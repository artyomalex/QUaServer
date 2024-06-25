#include <cling/Interpreter/Interpreter.h>
#include <cling/Interpreter/Value.h>
#include <cling/Utils/Casting.h>
#include <iostream>
#include <string>
#include <sstream>
#include <QCoreApplication>
#include <QDebug>

#include <QUaServer>
int aGlobal = 42;
static QUaServer server;
static  QUaFolderObject * objsFolder;
static float anotherGlobal = 3.141;
float getAnotherGlobal() { return anotherGlobal; }
void setAnotherGlobal(float val) { anotherGlobal = val; }

QVariant getQVariant(QUaServer * server, QUaNodeId *node
                     // const QUaTypesConverter::ArrayType& arrType
                     /* = QUaTypesConverter::ArrayType::QList*/
                     )
{
    Q_CHECK_PTR(server->m_server);
    /*  Q_ASSERT(!UA_NodeId_isNull(node->toUaNodeId()));
    if (UA_NodeId_isNull(node->toUaNodeId()))
    {
        return QVariant();
    } */
    // get value
    UA_ReadValueId rv;
    UA_ReadValueId_init(&rv);
    rv.nodeId      = node->toUaNodeId();
    rv.attributeId = UA_ATTRIBUTEID_VALUE;
    UA_DataValue value = UA_Server_read(
        server->m_server,
        &rv,
        UA_TIMESTAMPSTORETURN_NEITHER
        );
    UA_Variant * s = &value.value;
    if(UA_Variant_isScalar(s))
    {
        // convert
        QVariant outVar = QUaTypesConverter::uaVariantToQVariant(value.value);
        // clenaup
        UA_DataValue_clear(&value);
        return outVar;
    }
    else
    {
        UA_DataValue_clear(&value);
        return QVariant();
    }
}


static void
setQVariant(QUaServer * server, QUaNodeId *node, QVariant value) {
    Q_CHECK_PTR(server->m_server);
    UA_NodeId myIntegerNodeId = node->toUaNodeId();

    /* Write a different integer value */
    UA_Double myInteger = value.toDouble();
    UA_Variant myVar = QUaTypesConverter::uaVariantFromQVariant(value);
    //UA_Variant_init(&myVar);
    //UA_Variant_setScalar(&myVar, &myInteger, &UA_TYPES[UA_TYPES_INT32]);
    UA_Server_writeValue(server->m_server, myIntegerNodeId, myVar);

    /* Set the status code of the value to an error code. The function
     * UA_Server_write provides access to the raw service. The above
     * UA_Server_writeValue is syntactic sugar for writing a specific node
     * attribute with the write service. */
    UA_WriteValue wv;
    UA_WriteValue_init(&wv);
    wv.nodeId = myIntegerNodeId;
    wv.attributeId = UA_ATTRIBUTEID_VALUE;
    wv.value.status = UA_STATUSCODE_BADNOTCONNECTED;
    wv.value.hasStatus = true;
    UA_Server_write(server->m_server, &wv);

    /* Reset the variable to a good statuscode with a value */
    wv.value.hasStatus = false;
    wv.value.value = myVar;
    wv.value.hasValue = true;
    UA_Server_write(server->m_server, &wv);
}


///\brief Call compiled functions from the interpreter.
void useHeader(cling::Interpreter& interp) {
    // We could use a header, too...
    interp.declare("int aGlobal;\n"
                   "float getAnotherGlobal();\n"
                   "void setAnotherGlobal(float val);\n");

    cling::Value res; // Will hold the result of the expression evaluation.
    interp.process("aGlobal;", &res);
    std::cout << "aGlobal is " << res.castAs<long long>() << '\n';
    interp.process("getAnotherGlobal();", &res);
    std::cout << "getAnotherGlobal() returned " << res.getFloat() << '\n';

    setAnotherGlobal(1.); // We modify the compiled value,
    interp.process("getAnotherGlobal();", &res); // does the interpreter see it?
    std::cout << "getAnotherGlobal() returned " << res.getFloat() << '\n';

    // We modify using the interpreter, now the binary sees the new value.
    interp.process("setAnotherGlobal(7.777); getAnotherGlobal();");
    std::cout << "getAnotherGlobal() returned " << getAnotherGlobal() << '\n';
}

///\brief Call an interpreted function using its symbol address.
void useSymbolAddress(cling::Interpreter& interp) {
    // Declare a function to the interpreter. Make it extern "C" to remove
    // mangling from the game.
    interp.declare("extern \"C\" int plutification(int siss, int sat) "
                   "{ return siss * sat; }");
    void* addr = interp.getAddressOfGlobal("plutification");
    using func_t = int(int, int);
    func_t* pFunc = cling::utils::VoidToFunctionPtr<func_t*>(addr);
    std::cout << "7 * 8 = " << pFunc(7, 8) << '\n';
}

///\brief Pass a pointer into cling as a string.
auto usePointerLiteral_str(cling::Interpreter& interp, std::ostringstream *sstr) {
    //int res = 17; // The value that will be modified
    QRegExp test(".");
    //interp.unload(2);
    // Update the value of res by passing it to the interpreter.
    // on Windows, to prefix the hexadecimal value of a pointer with '0x',
    // one need to write: std::hex << std::showbase << (size_t)pointer
    //std::cout << types[0].toUtf8().constData() << "& types["<< "] = *(int*)" << std::hex << std::showbase << (size_t)&ls[i] << ';' << std::endl;
    //sstr << "int& ref = *(int*)" << std::hex << std::showbase << (size_t)&res << ';';
    //sstr << "int& bef = *(int*)" << std::hex << std::showbase << (size_t)&bes << ';';
    //sstr << "ref = ref * bef;";
    //qDebug() << "int& bef = *(int*)" << std::hex << std::showbase << (size_t)&bes << ';';
    //qDebug() << "ref = ref * bef;" << endl;
    auto str_prog= sstr->str();
    interp.process(str_prog);
    interp.unload(15);
    //auto res = values[0];
 //   auto nd =  QUaNodeId(ls[1]);
 //   setQVariant(&server,&nd, res);
   // qDebug() << "The square of 17 is " << res << '\n';



    //int x = QString::compare(ls[3], ls[5], Qt::CaseInsensitive);

    //QRegExp test(\"[^\`\]\g");
   // test.setMinimal(true);
    //QRegExp test("`(.*)`");
   /* if(test.exactMatch(inp))
    {
        qDebug() << "result:" << test.cap(0) << " " << test.cap(1)  << endl;
    } */

    return  0;
}

auto usePointerLiteral(cling::Interpreter& interp) {
    //int res = 17; // The value that will be modified
    int bes = 7;
    QVariantList values={};
    QStringList types={};
    //QString inp = "`TheNewVariableNode`=`Number`+2;";
    QString inp = "`i=53949`=`i=53949`+2;";
    QRegExp test(".");
    QStringList ls = inp.split(QRegExp("`"));
    std::ostringstream sstr;
    for(int i=0;i<ls.length()/2;i++)
    {
      //  auto nnode = QUaNode(&server);
      //  nnode.writeMask();
        auto sbb = ls[2*i+1];
      //  auto sxx = (objsFolder-> browseChild<QUaBaseDataVariable>(sbb));
        auto sxx = QUaNodeId(sbb);
        if (!sxx.isNull()) {
            //auto syy = sxx->value();
            auto syy = getQVariant(&server, &sxx);
        values.append(syy);
        }
      //  values.append(QVariant((objsFolder-> browseChild<QUaBaseDataVariable>(ls[2*i+1]))->value()));
        types.append(QString(values[i].typeName())); // + QString("& ls[") + QString(i) + QString("]"));
        sstr << types[i].toUtf8().constData() << "& types_"<< std::dec << i << " = *(" << types[i].toUtf8().constData() << "*)" << std::hex << std::showbase << (values[i].data()) << ';';
        std::cout << types[i].toUtf8().constData() << "& types_"<< std::dec << i << " = *(" << types[i].toUtf8().constData() << "*)" << std::hex << std::showbase << (values[i].data()) << ';' << std::endl;
    }
    for(int i=0;i<ls.length();i++)
    {
        if(!(i%2))
        {
            sstr << ls[i].toUtf8().constData();
            std::cout << ls[i].toUtf8().constData();
        }
        else
        {
          sstr << "types_"<< std::dec << i/2;
          std::cout << "types_"<< std::dec << i/2;
        }
    }
    std::cout<<std::endl;
    //interp.unload(2);
    // Update the value of res by passing it to the interpreter.
    // on Windows, to prefix the hexadecimal value of a pointer with '0x',
    // one need to write: std::hex << std::showbase << (size_t)pointer
    //std::cout << types[0].toUtf8().constData() << "& types["<< "] = *(int*)" << std::hex << std::showbase << (size_t)&ls[i] << ';' << std::endl;
    //sstr << "int& ref = *(int*)" << std::hex << std::showbase << (size_t)&res << ';';
    //sstr << "int& bef = *(int*)" << std::hex << std::showbase << (size_t)&bes << ';';
   //sstr << "ref = ref * bef;";
    //qDebug() << "int& bef = *(int*)" << std::hex << std::showbase << (size_t)&bes << ';';
    //qDebug() << "ref = ref * bef;" << endl;
    interp.process(sstr.str());
    auto res = values[0];
    auto nd =  QUaNodeId(ls[1]);
    setQVariant(&server,&nd, res);
    qDebug() << "The square of 17 is " << res << '\n';



    //int x = QString::compare(ls[3], ls[5], Qt::CaseInsensitive);

    //QRegExp test(\"[^\`\]\g");
    test.setMinimal(true);
    //QRegExp test("`(.*)`");
    if(test.exactMatch(inp))
    {
        qDebug() << "result:" << test.cap(0) << " " << test.cap(1)  << endl;
    }
    interp.unload(1);
    return  res;
}
auto usePointerLiteral_br(cling::Interpreter& interp) {
    //int res = 17; // The value that will be modified
    int bes = 7;
    QVariantList values={};
    QStringList types={};
    QString inp = "`TheNewVariableNode`=`Number`+2;";
    QRegExp test(".");
    QStringList ls = inp.split(QRegExp("`"));
    std::ostringstream sstr;
    for(int i=0;i<ls.length()/2;i++)
    {
        //  auto nnode = QUaNode(&server);
        //  nnode.writeMask();
        auto sbb = ls[2*i+1];
        //  auto sxx = (objsFolder-> browseChild<QUaBaseDataVariable>(sbb));
        auto sxx = (objsFolder-> browseChild<QUaBaseDataVariable>(sbb));
        if (sxx) {
            auto syy = sxx->value();
            values.append(QVariant(syy));
        }
        //  values.append(QVariant((objsFolder-> browseChild<QUaBaseDataVariable>(ls[2*i+1]))->value()));
        types.append(QString(values[i].typeName())); // + QString("& ls[") + QString(i) + QString("]"));
        sstr << types[i].toUtf8().constData() << "& types_"<< std::dec << i << " = *(" << types[i].toUtf8().constData() << "*)" << std::hex << std::showbase << (values[i].data()) << ';';
        std::cout << types[i].toUtf8().constData() << "& types_"<< std::dec << i << " = *(" << types[i].toUtf8().constData() << "*)" << std::hex << std::showbase << (values[i].data()) << ';' << std::endl;
    }
    for(int i=0;i<ls.length();i++)
    {
        if(!(i%2))
        {
            sstr << ls[i].toUtf8().constData();
            std::cout << ls[i].toUtf8().constData();
        }
        else
        {
            sstr << "types_"<< std::dec << i/2;
            std::cout << "types_"<< std::dec << i/2;
        }
    }
    std::cout<<std::endl;
    //interp.unload(2);
    // Update the value of res by passing it to the interpreter.
    // on Windows, to prefix the hexadecimal value of a pointer with '0x',
    // one need to write: std::hex << std::showbase << (size_t)pointer
    //std::cout << types[0].toUtf8().constData() << "& types["<< "] = *(int*)" << std::hex << std::showbase << (size_t)&ls[i] << ';' << std::endl;
    //sstr << "int& ref = *(int*)" << std::hex << std::showbase << (size_t)&res << ';';
    //sstr << "int& bef = *(int*)" << std::hex << std::showbase << (size_t)&bes << ';';
    //sstr << "ref = ref * bef;";
    //qDebug() << "int& bef = *(int*)" << std::hex << std::showbase << (size_t)&bes << ';';
    //qDebug() << "ref = ref * bef;" << endl;
    interp.process(sstr.str());
    auto res = values[0];
    qDebug() << "The square of 17 is " << res << '\n';



    //int x = QString::compare(ls[3], ls[5], Qt::CaseInsensitive);

    //QRegExp test(\"[^\`\]\g");
    test.setMinimal(true);
    //QRegExp test("`(.*)`");
    if(test.exactMatch(inp))
    {
        qDebug() << "result:" << test.cap(0) << " " << test.cap(1)  << endl;
    }
    interp.unload(1);
    return  res;
}

static cling::Interpreter *intrp;
auto testNumbers(QList<QUaBaseDataVariable*> a)
{
     QVariantList values={};
    QStringList types={};
    for(int i=0;i<a.count();i++)
    {
        qDebug() << a.at(i)->value();
    }
    QStringList ls = a.at(0)->value().toString().split(QRegExp("`"));
    std::ostringstream sstr;
    for(int i=0;i<ls.length()/2;i++)
    {
        //  auto nnode = QUaNode(&server);
        //  nnode.writeMask();
        auto sbb = ls[2*i+1].toInt();
        //  auto sxx = (objsFolder-> browseChild<QUaBaseDataVariable>(sbb));
        //auto sxx = QUaNodeId(sbb);
       // if (!sxx.isNull()) {
            //auto syy = sxx->value();
        auto syy = a.at(sbb)->value();
            values.append(syy);
        //}
        //  values.append(QVariant((objsFolder-> browseChild<QUaBaseDataVariable>(ls[2*i+1]))->value()));
        types.append(QString(values[i].typeName())); // + QString("& ls[") + QString(i) + QString("]"));
        sstr << types[i].toUtf8().constData() << "& types_"<< std::dec << i << " = *(" << types[i].toUtf8().constData() << "*)" << std::hex << std::showbase << (values[i].data()) << ';';
        std::cout << types[i].toUtf8().constData() << "& types_"<< std::dec << i << " = *(" << types[i].toUtf8().constData() << "*)" << std::hex << std::showbase << (values[i].data()) << ';' << std::endl;
    }
    for(int i=0;i<ls.length();i++)
    {
        if(!(i%2))
        {
            sstr << ls[i].toUtf8().constData();
            std::cout << ls[i].toUtf8().constData();
        }
        else
        {
            sstr << "types_"<< std::dec << i/2;
            std::cout << "types_"<< std::dec << i/2;
        }
    }
    std::cout<<std::endl;
      auto sstr_prog = sstr.str();
    usePointerLiteral_str(*intrp,&sstr);
      a.last()->setValue(values.first());
    return 0; //x + y;
}

auto addNumbers(QUaQualifiedName browseName, QUaQualifiedName y)
{
    return usePointerLiteral(*intrp); //x + y;
}

static void
addVariable(UA_Server *server) {
    /* Define the attribute of the myInteger variable node */
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    UA_Int32 myInteger = 42;
    UA_Variant_setScalar(&attr.value, &myInteger, &UA_TYPES[UA_TYPES_INT32]);
    attr.description = UA_LOCALIZEDTEXT("en-US","the answer");
    attr.displayName = UA_LOCALIZEDTEXT("en-US","the answer");
    attr.dataType = UA_TYPES[UA_TYPES_INT32].typeId;
    attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;

    /* Add the variable node to the information model */
    UA_NodeId myIntegerNodeId = UA_NODEID_STRING(1, "the.answer");
    UA_QualifiedName myIntegerName = UA_QUALIFIEDNAME(1, "the answer");
    UA_NodeId parentNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER);
    UA_NodeId parentReferenceNodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_ORGANIZES);
    UA_Server_addVariableNode(server, myIntegerNodeId, parentNodeId,
                              parentReferenceNodeId, myIntegerName,
                              UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE), attr, NULL, NULL);
}


int main(int argc, char *argv[])
{
    // Create the Interpreter. LLVMDIR is provided as -D during compilation.

    char llvmdir [] = "";
    cling::Interpreter interp(argc, argv, llvmdir);
    intrp = &interp;
    useHeader(*intrp);
    useSymbolAddress(interp);
    //uusePointerLiteral(interp);


    QCoreApplication a(argc, argv);

    //QUaServer server;
	server.registerEnum<QUaStatus>();

	// logging

	QObject::connect(&server, &QUaServer::logMessage,
	[](const QUaLog& log) {
		qDebug() << "[" << log.level << "] :" << log.message;
	});

   // QUaFolderObject *
    objsFolder = server.objectsFolder();

    addVariable(server.m_server);

	// add a method using callback function

   objsFolder->addMethod("addNumbers", &addNumbers);

  //  auto addmethod = objsFolder->browseChild<QUaBaseObject>("addNumbers");

   // add methods using lambdas

	auto varNumber = objsFolder->addBaseDataVariable("Number");
	varNumber->setValue(0.0);
	varNumber->setDataType(QMetaType::Double);
    varNumber = objsFolder->browseChild<QUaBaseDataVariable>("Number");
    auto varval = varNumber->value();
    auto nod = QUaNodeId("ns=0;i=53949");

    auto nd =nod.toUaNodeId();
    auto vat =getQVariant(&server, &nod);
    vat.setValue(1.0);
        setQVariant(&server, &nod, vat);
    auto varUNumber = objsFolder->addBaseDataVariable("UInteger");
    varUNumber->setValue(0);
    varUNumber->setDataType(QMetaType::UInt);

    auto varCalcNumber = varUNumber->addBaseDataVariable("CalcInteger");
    varCalcNumber->setValue(0);
    varCalcNumber->setDataType(QMetaType::Int);

    auto varFormula = varUNumber->addBaseDataVariable("Formula");
    varFormula->setValue("`i=53950'='i=53949`+2;");
    varFormula->setDataType(QMetaType::QString);

	objsFolder->addMethod("incrementNumberBy", 
	[&varNumber](double increment, QUaStatus status) {
		if (!varNumber)
		{
			return false;
		}
		double currentValue = varNumber->value().toDouble();
		double newValue = currentValue + increment;
		varNumber->setValue(
			newValue,
			status
		);
		return true;
	});

    QUaBaseDataVariable* varBaseData = objsFolder->addBaseDataVariable({ 1, "my_variable" });
    varBaseData->setWriteAccess(true);
    QUaNodeId someNodeId(1, "my_variable");
    varBaseData->setValue(someNodeId);

    objsFolder->addMethod("browseVariable",(
                          [](QUaQualifiedName qname) {
                              QUaBaseDataVariable * s= objsFolder-> browseChild<QUaBaseDataVariable>(qname);
                              if(s==NULL)
                              {
                                  return QVariant(0x8000000000000000LL);
                              }
                              return  QVariant((objsFolder-> browseChild<QUaBaseDataVariable>(qname))->value());
                          }));

    objsFolder->addMethod("browsesetVariable",(
                                              [](QUaQualifiedName qname1) {
                                                  QUaBaseDataVariable * s1= objsFolder-> browseChild<QUaBaseDataVariable>(qname1);
                                                  if(s1==NULL)
                                                  {
                                                      return QVariant(0x8000000000000000LL);

                                                  }
                                                  objsFolder-> browseChild<QUaBaseDataVariable>(qname1)->setValue(1);
                                                  return  QVariant((objsFolder-> browseChild<QUaBaseDataVariable>(qname1))->value());
                                              }));

	objsFolder->addMethod("deleteNumber", 
	[&varNumber]() {
		if (!varNumber)
		{
			return;
		}
		delete varNumber;
		varNumber = nullptr;
	});

	// use QList<T> or QVector<T> as arguments or return types
	// NOTE : only works with supported types T
	objsFolder->addMethod("addNumbersArray", 
	[](QList<int> listInts) {
		int total = 0;
		for (int i = 0; i < listInts.count(); i++)
		{
			total += listInts.at(i);
		}
		return total;
	});

	objsFolder->addMethod("getNames", 
	[]() {
		return QVector<QString>() << "arturo" << "juan" << "miguel";
	});

	// use methods to dynamically create object instances
	objsFolder->addMethod("addObject", 
    [](QString strName) {
		auto obj = objsFolder->browseChild<QUaBaseObject>(strName);
		if (obj)
		{
			return QObject::tr("Error : Object with name %1 already exists.").arg(strName);
		}
		obj = objsFolder->addBaseObject(strName, QString("ns=1;s=%1").arg(strName));
		// create delete method for each newly created object
		obj->addMethod("delete", 
		[obj]() {
			// delete instance
			delete obj;
		});
		return QObject::tr("Success.");
	});

	// temperature sensor model

	QUaFolderObject * sensorsFolder = objsFolder->addFolderObject("Sensors");

    QUaBaseObject * objSensor0 = sensorsFolder->addBaseObject("TempSensor1");

    QUaProperty * modelProp = objSensor0->addProperty("Model");
	modelProp->setValue("LM35");
    QUaProperty * brandProp = objSensor0->addProperty("Brand");
	brandProp->setValue("Texas Instruments");
    QUaProperty * euProp = objSensor0->addProperty("Units");
	euProp->setValue("C");

    QUaBaseDataVariable * valueVar = objSensor0->addBaseDataVariable("Current Value");
	valueVar->setValue(36.7);
    QUaBaseDataVariable * statusVar = objSensor0->addBaseDataVariable("Status");
	statusVar->setValue("On");

    objSensor0->addMethod("Turn On",
	[&statusVar]() {
		statusVar->setValue("On");
	});
    objSensor0->addMethod("Turn Off",
	[&statusVar]() {
		statusVar->setValue("Off");
	});
  //  auto code = usePointerLiteral(interp);
    auto parent = objsFolder->parent();

    QUaFolderObject * objsFolder1 = objsFolder->addFolderObject("Folder");

   // auto  objsFolder2 = objsFolder->cloneNode();
   // objsFolder2->setObjectName("ns=0;s=Objects1");
   // objsFolder2->setParent(parent);
    // create objects
    QUaBaseDataVariable  * objSupl1 = objsFolder->addBaseDataVariable("Mouser");
    QUaBaseDataVariable * objSensor1 = objSupl1->addBaseDataVariable("TempSensor1");
    QUaBaseDataVariable * objSensor2 = objSupl1->addBaseDataVariable("TempSensor2");
    objSensor1->setValue(1.0);
    objSensor1->setAccessLevel(UA_ACCESSLEVELEXTYPE_CURRENTREAD|UA_ACCESSLEVELEXTYPE_CURRENTWRITE);
    objSensor2->setValue(2.0);
    QUaBaseDataVariable * objSensor4 = objSensor1->addBaseDataVariable("TempSensor4");

    QUaBaseDataVariable  * formulaVar = objsFolder->addBaseDataVariable("Formula");
    objSupl1->setValue(5.0);
    objSensor4->setValue(1.1);
    formulaVar->setValue("`3`=`2`+`1`;");
    // create references


    server.registerReferenceType({ "Supplies2", "IsSupplied2By" });
    objSensor2->addReference({ "Supplies2", "IsSupplied2By" }, objSupl1, false);


    server.registerReferenceType({ "Supplies1", "IsSupplied1By" });
    objSupl1->addReference({ "Supplies1", "IsSupplied1By" }, objSensor1);

    server.registerReferenceType({ "Supplies", "IsSuppliedBy" });
    objSupl1->addReference({ "Supplies", "IsSuppliedBy" }, formulaVar);


    //  auto listSensors = objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });

    QObject::connect(objSupl1 , &QUaBaseDataVariable::valueRankChanged, [objSupl1](const QVariant &valueRank) {
        qDebug() << "valueRankChanged :" << valueRank;
        auto listSensors1 = objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });
        listSensors1<<objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies1", "IsSupplied1By" });
        listSensors1<<objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies2", "IsSupplied2By" });
        for (int i = 0; i < listSensors1.count(); i++)
        {
            qDebug() << listSensors1.at(i)->value();

        }
        listSensors1.end();
        listSensors1<<objSupl1;


          testNumbers(listSensors1);
        return;
    });

    // browse references

    qDebug() << "Supplier" << objSupl1->displayName() << "supplies :";
  //  auto listSensors = objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });
    auto listSensors = objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });
    listSensors<<objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies1", "IsSupplied1By" });
    listSensors<<objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies2", "IsSupplied2By" });
    for (int i = 0; i < listSensors.count(); i++)
    {
        QObject::connect(listSensors.at(i), &QUaBaseDataVariable::valueChanged, [objSupl1](const QVariant &value) {
            qDebug() << "New value :" << value;
            emit objSupl1->valueRankChanged(0);
            return;
        });
       // if(i!=0) listSensors.at(i)->setValue(55);
        qDebug() << listSensors.at(i)->nodeId();
        //   emit objSupl1->valueRankChanged(0);
    }
    objSensor1->setValue(1.0);
    qDebug() << objSensor1->displayName() << "supplier is: :";
  //  auto listSuppliers = objSensor1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" }, false);
  //  qDebug() << listSuppliers.first()->displayName();
    //auto ttemp = objSupl1->browseChild("TempSensor1");
    auto objSup2 =objSupl1->cloneNode();
    //auto part = objSensor3->parent();
    objSup2->setParent(objsFolder1);
    //part = objSensor3->parent();
    //objSensor3->setDisplayName("Temp3");
    //objSensor3->setObjectName("ns=0;s=testName");

    objSup2->addReference({"Organizes", "OrganizedBy"}, objsFolder1, false);
    //auto listSuppliers1 = objsFolder->findReferences<QObject>({"Organizes", "OrganizedBy" }, true);
    //auto brn = objSensor3->browseName();
	server.start();

	return a.exec(); 
}
