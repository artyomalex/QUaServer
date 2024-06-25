#include <QCoreApplication>
#include <QDebug>

#include <QUaServer>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QUaServer server;

	// logging

	QObject::connect(&server, &QUaServer::logMessage,
    [](const QUaLog &log) {
        qDebug() << "[" << log.level << "] :" << log.message;
    });

	QObject::connect(&server, &QUaServer::clientConnected,
	[](const QUaSession * sessionData)
	{
		qDebug() << "Connected" << sessionData->address() << ":" << sessionData->port() << "|" << sessionData->applicationName();
	});

	QUaFolderObject * objsFolder = server.objectsFolder();

	// basics

	QUaBaseDataVariable * varBaseData = objsFolder->addBaseDataVariable("my_variable");
	varBaseData->setWriteAccess(true);
	varBaseData->setValue(1);
	Q_ASSERT(varBaseData->value<int>() == 1);
    QObject::connect(varBaseData, &QUaBaseDataVariable::valueChanged, [](const QVariant &value) {
		qDebug() << "New value :" << value;
	});
    emit varBaseData->valueChanged(QVariant(9.9999999), false);
	QUaProperty * varProp = objsFolder->addProperty("my_property", "ns=1;s=my_prop");
	varProp->setValue("hola");
	Q_ASSERT(varProp->value<QString>() == QString("hola"));

	objsFolder->addBaseObject("my_object");

	objsFolder->addFolderObject("my_folder");

	// nested nodes and browsing

	QUaBaseObject       * obj    = objsFolder->addBaseObject("obj");
	QUaBaseObject       * subobj = obj->addBaseObject("subobj");
	QUaBaseDataVariable * var    = subobj->addBaseDataVariable("var");
	QUaBaseDataVariable * subvar = var->addBaseDataVariable("subvar");
	QUaProperty         * prop   = subvar->addProperty("prop");

	// browse nested children by passing a list of browse names to the (relative) browsePath method
	Q_ASSERT(obj->browsePath(QUaBrowsePath() << "subobj") == subobj);
	Q_ASSERT(obj->browsePath(QUaBrowsePath() << "subobj" << "var") == var);
	Q_ASSERT(obj->browsePath(QUaBrowsePath() << "subobj" << "var" << "subvar") == subvar);
	Q_ASSERT(obj->browsePath(QUaBrowsePath() << "subobj" << "var" << "subvar" << "prop") == prop);
	// browse from server by passing the (absolute) browse of the node (starting at ObjectsFolder)
	Q_ASSERT(server.browsePath(subobj->nodeBrowsePath()) == subobj);
	Q_ASSERT(server.browsePath(var   ->nodeBrowsePath()) == var   );
	Q_ASSERT(server.browsePath(subvar->nodeBrowsePath()) == subvar);
	Q_ASSERT(server.browsePath(prop  ->nodeBrowsePath()) == prop  );

    // set and get qlist and qvector

    var->setValue(QList<int>() << 1 << 22 << 333);
    auto intlist = var->value<QList<int>>();
    qDebug() << "list contents:" << intlist.count();
    for(const auto& num : intlist) {
        qDebug() << num;
    }

    subvar->setValue(QVector<QString>() << "a" << "b" << "c");
    auto strvec = subvar->value<QVector<QString>>();
    qDebug() << "vector contents:" << strvec.count();
    for(const auto& str : strvec) {
        qDebug() << str;
    }

	// temperature sensor model

	QUaFolderObject * sensorsFolder = objsFolder->addFolderObject("Sensors");

	QUaBaseObject * objSensor1 = sensorsFolder->addBaseObject("TempSensor1");

	QUaProperty * modelProp = objSensor1->addProperty("Model");
	modelProp->setValue("LM35");
	QUaProperty * brandProp = objSensor1->addProperty("Brand");
	brandProp->setValue("Texas Instruments");
	QUaProperty * euProp = objSensor1->addProperty("Units");
	euProp->setValue("C");

	QUaBaseDataVariable * valueVar = objSensor1->addBaseDataVariable("Current Value");
	valueVar->setValue(36.7);
	Q_ASSERT(valueVar->value<double>() == 36.7);

	server.start();

	return a.exec(); 
}
