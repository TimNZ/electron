#pragma once
#include "browser/notification.h"
#include "browser/win/notification_presenter_win7.h"

namespace brightray {

class Win32Notification : public brightray::Notification
{
public:
    Win32Notification(NotificationDelegate* delegate, NotificationPresenterWin7* presenter) : Notification(delegate, presenter) {}
    void Show(const base::string16& title, const base::string16& msg, const std::string& tag, const GURL& icon_url, const SkBitmap& icon, const bool silent) override;
    void Dismiss() override;

    const DesktopNotificationController::Notification& GetRef() const
    {
        return notificationRef;
    }

    const std::string& GetTag() const
    {
        return tag;
    }

private:
    DISALLOW_COPY_AND_ASSIGN(Win32Notification);
    DesktopNotificationController::Notification notificationRef;
    std::string tag;
};

}
