#include <cling/Interpreter/Interpreter.h>
#include <cling/Interpreter/Value.h>
#include <cling/Utils/Casting.h>
#include <iostream>
#include <string>
#include <sstream>
#include <QCoreApplication>
#include <QFileInfo>
#include <QDebug>

#include <QUaServer>

#include "temperaturesensor.h"

#ifdef SQLITE_SERIALIZER
#include "quasqliteserializer.h"
#else
#include "quaxmlserializer.h"
#endif // SQLITE_SERIALIZER
int aGlobal = 42;
static float anotherGlobal = 3.141;
float getAnotherGlobal() { return anotherGlobal; }
void setAnotherGlobal(float val) { anotherGlobal = val; }
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

void setupDefaultAddressSpace(QUaServer &server)
{
	QUaFolderObject* objsFolder = server.objectsFolder();

	// create some instances of basic types
	QUaBaseDataVariable* varBaseData = objsFolder->addBaseDataVariable({ 1, "my_variable" });
	varBaseData->setWriteAccess(true);
	QUaNodeId someNodeId(1, "my_variable");
	varBaseData->setValue(someNodeId);
	QUaProperty* varProp = objsFolder->addProperty("my_property", "ns=1;s=my_prop");
	QUaLocalizedText someText("es", "hola");
	varProp->setValue(someText);
	varProp->setWriteAccess(true);
	QUaBaseObject*   objBase    = objsFolder->addBaseObject("my_object", "ns=1;s=my_obj");
	QUaFolderObject* objFolder  = objsFolder->addFolderObject("my_folder");
	QUaProperty*     varSubProp = objBase->addProperty("my_sub_property");
	varSubProp->setValue(666.7);
	QUaBaseObject*   objSubBase    = objBase->addBaseObject("my_sub_object");
	QUaFolderObject* objSubFolder  = objBase->addFolderObject("my_sub_folder");
	QUaBaseObject*   objSubSubBase = objSubFolder->addBaseObject("my_subsub_object", "ns=1;s=my_subsub_object");
	Q_UNUSED(objSubBase);

	// create some instances of custom type
	auto sensor1 = objSubSubBase->addChild<TemperatureSensor>("Sensor1", "ns=1;s=sensor1");
	auto sensor2 = objSubSubBase->addChild<TemperatureSensor>("Sensor2", "ns=1;s=sensor2");
	sensor2->turnOn();
	auto sensor3 = objSubSubBase->addChild<TemperatureSensor>("Sensor3", "ns=1;s=sensor3");
	sensor3->currentValue()->setValue(1.2345);
	// add some non-hierarchical references
	objBase->addReference({ "FriendOf", "FriendOf" }, sensor1);
	sensor2->addReference({ "FriendOf", "FriendOf" }, objFolder);
}

static cling::Interpreter *intrp;


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
    }
    for(int i=0;i<values.length();i++)
    {
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


int main(int argc, char *argv[])
{
    char llvmdir [] = "";
    cling::Interpreter interp(argc, argv, llvmdir);
    intrp = &interp;
    useHeader(*intrp);
    useSymbolAddress(interp);
    //uusePointerLiteral(interp);


    QCoreApplication a(argc, argv);

	QUaServer server;
	server.registerType<TemperatureSensor>();

	QUaFolderObject* objsFolder = server.objectsFolder();

	QQueue<QUaLog> logOut;

#ifdef SQLITE_SERIALIZER
	const QString strFileName = "config.sqlite";
	QFileInfo fileInfoConf(strFileName);
	bool fileInfoExists = fileInfoConf.exists();
	QUaSqliteSerializer serializer;
	if (!serializer.setSqliteDbName(strFileName, logOut))
#else
	const QString strFileName = "config.xml";
	QFileInfo fileInfoConf(strFileName);
	bool fileInfoExists = fileInfoConf.exists();
	QUaXmlSerializer serializer;
	if (!serializer.setXmlFileName(strFileName, logOut))
#endif // SQLITE_SERIALIZER
	{
		for (auto log : logOut)
		{
			qCritical() << "[" << log.level << "] :" << log.message;
		}
		return 1;
	}
	// deserialize if config file exists, else serialize
	if (fileInfoExists)
	{
		// deserialize
		if (!objsFolder->deserialize(serializer, logOut))
		{
			// print log entries if any
			for (auto log : logOut)
			{
				qCritical() << "[" << log.level << "] :" << log.message;
			}
			return 1;
		}
        // display success
        qInfo() << "[INFO] Deserialized from" << strFileName;
        auto formulas = objsFolder->browseChild("Formulas");
        auto formula = formulas->browseChild("Formula");
        auto listformula =  formulas->findReferences<QUaBaseVariable>({"Organizes", "OrganizedBy" },true);
        for(int i=0; i< listformula.count(); i++)
        {
         auto calc = listformula.at(i)->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" },false);
        for(int j =0; j< calc.count(); j++)
         {
            auto calclat = calc.at(j);
           QObject::connect(calclat, &QUaBaseDataVariable::valueRankChanged, [calclat](const QVariant &valueRank) {
            qDebug() << "valueRankChanged :" << valueRank;
                auto listSensors1 = calclat->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });
            listSensors1<<calclat->findReferences<QUaBaseDataVariable>({ "Supplies1", "IsSupplied1By" });
                listSensors1<<calclat->findReferences<QUaBaseDataVariable>({ "Supplies2", "IsSupplied2By" });
            for (int k = 0; k < listSensors1.count(); k++)
            {
                qDebug() << listSensors1.at(k)->value();

            }
            listSensors1.end();
            listSensors1<<calclat;

            testNumbers(listSensors1);
            return;
            });
            auto listSensors1 = calclat->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });
            listSensors1<<calclat->findReferences<QUaBaseDataVariable>({ "Supplies1", "IsSupplied1By" });
            listSensors1<<calclat->findReferences<QUaBaseDataVariable>({ "Supplies2", "IsSupplied2By" });
            for (int i = 0; i < listSensors1.count(); i++)
            {
                QObject::connect(listSensors1.at(i), &QUaBaseDataVariable::valueChanged, [calclat](const QVariant &value) {
                    qDebug() << "New value :" << value;
                    emit calclat->valueRankChanged(0);
                    return;
                });
        }
        }
       // auto listformulas =  formula->findReferences<QUaBaseVariable>({ "Supplies", "IsSuppliedBy" },false);//findChildren<QObject>(QRegExp(".*"), Qt::FindChildrenRecursively); //
    }
    }
	else
	{
		// create some objects and variables to test
		setupDefaultAddressSpace(server);
        auto parent = objsFolder->parent();

        QUaFolderObject * objsFolder1 = objsFolder->addFolderObject("Folder");
        QUaFolderObject * objsFormula = objsFolder->addFolderObject("Formulas");
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

        QUaBaseDataVariable  * formulaVar = objsFormula->addBaseDataVariable("Formula");
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
        //auto objname = objSup2->objectName();
        //objSup2->setObjectName(objSup2->browseName() + "_copy");
        //objname = objSup2->objectName();
        objSup2->setParent(objsFolder1);
        //part = objSensor3->parent();
        //objSensor3->setDisplayName("Temp3");
        //objSensor3->setObjectName("ns=0;s=testName");

        objSup2->addReference({"Organizes", "OrganizedBy"}, objsFolder1, false);
        //auto listSuppliers1 = objsFolder->findReferences<QObject>({"Organizes", "OrganizedBy" }, true);
        //auto brn = objSensor3->browseName();;
        if (!objsFolder->serialize(serializer, logOut))
        {
            for (auto log : logOut)
            {
                qCritical() << "[" << log.level << "] :" << log.message;
            }
            return 1;
        }
        // display success
        qInfo() << "[INFO] Serialized to" << strFileName;
    }
	server.start();

	return a.exec(); 
}
