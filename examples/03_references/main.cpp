#include <QCoreApplication>
#include <QDebug>

#include <QUaServer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QUaServer server;

    QUaFolderObject * objsFolder = server.objectsFolder();
    auto parent = objsFolder->parent();

    QUaFolderObject * objsFolder1 = objsFolder->addFolderObject("Folder");

    auto  objsFolder2 = objsFolder->cloneNode();
   objsFolder2->setObjectName("ns=0;s=Objects1");
    objsFolder2->setParent(parent);
    // create objects

    QUaBaseDataVariable * objSensor1 = objsFolder->addBaseDataVariable("TempSensor1");
    QUaBaseDataVariable * objSensor2 = objsFolder->addBaseDataVariable("TempSensor2");
    objSensor1->setValue(1.0);
    objSensor1->setAccessLevel(UA_ACCESSLEVELEXTYPE_CURRENTREAD|UA_ACCESSLEVELEXTYPE_CURRENTWRITE);
    objSensor2->setValue(2.0);
    QUaBaseDataVariable * objSensor4 = objSensor1->addBaseDataVariable("TempSensor4");
    QUaBaseDataVariable  * objSupl1 = objsFolder->addBaseDataVariable("Mouser");

    objSupl1->setValue(5.0);
    objSensor4->setValue(1.1);
    // create references

    server.registerReferenceType({ "Supplies", "IsSuppliedBy" });
    objSensor2->addReference({ "Supplies", "IsSuppliedBy" }, objSupl1, false);


    server.registerReferenceType({ "Supplies", "IsSuppliedBy" });
    objSupl1->addReference({ "Supplies", "IsSuppliedBy" }, objSensor1);

  //  auto listSensors = objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });

    QObject::connect(objSupl1 , &QUaBaseDataVariable::valueRankChanged, [objSupl1](const QVariant &valueRank) {
        qDebug() << "valueRankChanged :" << valueRank;
       auto listSensors = objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });
       for (int i = 0; i < listSensors.count(); i++)
        {
         qDebug() << listSensors.at(i)->value();
        }
    });

    // browse references

    qDebug() << "Supplier" << objSupl1->displayName() << "supplies :";
    auto listSensors = objSupl1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" });
    for (int i = 0; i < listSensors.count(); i++)
    {
        QObject::connect(listSensors.at(i), &QUaBaseDataVariable::valueChanged, [objSupl1](const QVariant &value) {
            qDebug() << "New value :" << value;
            emit objSupl1->valueRankChanged(0);
        });
       listSensors.at(i)->setValue(55);
        qDebug() << listSensors.at(i)->nodeId();
    //   emit objSupl1->valueRankChanged(0);
    }
    objSensor1->setValue(1.0);
    qDebug() << objSensor1->displayName() << "supplier is: :";
    auto listSuppliers = objSensor1->findReferences<QUaBaseDataVariable>({ "Supplies", "IsSuppliedBy" }, false);
    qDebug() << listSuppliers.first()->displayName();
    //auto ttemp = objSupl1->browseChild("TempSensor1");
    auto objSensor3 =objSensor1->cloneNode();
    auto part = objSensor3->parent();
    objSensor3->setParent(objsFolder);
    part = objSensor3->parent();
    objSensor3->setDisplayName("Temp3");
    objSensor3->setObjectName("ns=0;s=testName");

    objSensor3->addReference({"Organizes", "OrganizedBy"}, objsFolder1, false);
    auto listSuppliers1 = objsFolder->findReferences<QObject>({"Organizes", "OrganizedBy" }, true);
    auto brn = objSensor3->browseName();
    server.start();

    return a.exec();
}
