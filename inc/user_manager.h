#ifndef __USER_MANAGER_H__
#define __USER_MANAGER_H__
#include "basic_head.h"

struct UserInfo {
    std::string name;
    std::string password;
    std::string ID;
};

class UserManager {
public:
    UserManager(void);
    ~UserManager(void);

    int load_user_info(void);

    int add_user(UserInfo info);
    int remove_user(std::string id);
    UserInfo& search(std::string id);

private:
    std::map<std::string, UserInfo> users_;
};

#endif