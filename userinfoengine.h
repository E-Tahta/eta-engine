#ifndef USERINFOENGINE_H
#define USERINFOENGINE_H

#include <Plasma/DataEngine>
#include <kuser.h>

#include <QtCore/QString>
#include <QApplication>
#include <QDesktopWidget>

class UserInfoEngine : public Plasma::DataEngine
{
    
    Q_OBJECT
 
    public:      
        UserInfoEngine(QObject* parent, const QVariantList& args);
	
    protected:       
        bool sourceRequestEvent(const QString& name);
        bool updateSourceEvent(const QString& source);
    
      
};

const QString getUsername(bool useShortName=false, const KUser& user = KUser());

#endif // USERINFOENGINE_H