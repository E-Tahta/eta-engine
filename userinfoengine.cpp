#include "userinfoengine.h"
#include <kuser.h>
#include <Plasma/DataContainer>


UserInfoEngine::UserInfoEngine(QObject* parent, const QVariantList& args)
    : Plasma::DataEngine(parent, args)
{
   
    Q_UNUSED(args)
    setMinimumPollingInterval(333);
    
}

bool UserInfoEngine::sourceRequestEvent(const QString &name)
{
    
    return updateSourceEvent(name);
}

bool UserInfoEngine::updateSourceEvent(const QString &name)
{
    

    QString fullname = getUsername(false);
    QString logname = getUsername(true);
    QDesktopWidget dw;
    int width = dw.screenGeometry(dw.primaryScreen()).width();
    int height = dw.screenGeometry(dw.primaryScreen()).height();
    if (name == I18N_NOOP("Local")) {
        setData(name, I18N_NOOP("fullname"),fullname);	
        setData(name, I18N_NOOP("loginname"),logname);
	setData(name,I18N_NOOP("width"),width);
	setData(name,I18N_NOOP("height"),height);
	/*
	 TASK : after changes
	 kbuildsycoca4
	 kquitapp plasma-desktop
	 plasma-desktop
	 */
    } else {
        setData(name, I18N_NOOP("fullname"),fullname);	
        setData(name, I18N_NOOP("loginname"),logname);
	setData(name,I18N_NOOP("width"),width);
	setData(name,I18N_NOOP("height"),height);
    }
    //dw.destroyed();
    return true;
}


const QString getUsername(bool useShortName, const KUser& user)
{
  if (useShortName)
    return user.loginName();
    

  QString username = user.property(KUser::FullName).toString();
  if (username.isEmpty())
    username = user.loginName();

  return username;
}


 


K_EXPORT_PLASMA_DATAENGINE(userinfo, UserInfoEngine)

#include "userinfoengine.moc"
