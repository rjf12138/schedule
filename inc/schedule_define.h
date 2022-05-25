#ifndef __SCHEDULE_DEFINE_H__
#define __SCHEDULE_DEFINE_H__

// 事件当前状态
enum EEventStatus {
    EEventStatus_Dormancy, // 休眠状态，不会触发
    EEventStatus_ToBeExecuted, // 等待执行的
    EEventStatus_Executing, // 正在执行的
    EEventStatus_Overdue, // 过期的
    EEventStatus_Complete // 完成的
};

//////////////////////// 数据文件存储路径宏 ////////////////////////////////////
#define EVENT_INFO_DIR_PATH     "./config/event_info/"                     // 事件路径
#define EVENT_ID_LIST_PATH      "./config/user_info/event_id_list.txt"     // 事件id列表
#define USER_INFO_DIR_PATH      "./config/user_info/"                      // 用户信息路径
#define USERS_ID_LIST_PATH      "./config/user_info/user_id_list.txt"      // 用户id列表
#define NEXT_EVENT_ID_PATH      "./config/next_event_id"                   // 下一个可分配事件ID
#define NEXT_USER_ID_PATH       "./config/next_user_id"                    // 下一个可分配用户ID

/////////////////////// HTTP 请求URL ///////////////////////////////////////
/////////////////////// 用户登录/登出 ///////////////////////////////////////
#define MACRP_UserLogin "/UserLogin" // 用digest摘要认证方式
/*
成功返回一个Token，后续根据token来交互
*/
#define MACRP_UserLogout "/UserLogout"


/////////////////////// 操作事件 /////////////////////////////////
// 每个事件有一个独一无二的编号, 编号由系统生成
#define MACRP_AddEvent   "/AddEvent"        // 添加事件
/*
参数
{
    "ID" : "xber3456",
    "name":"xxxxxx",
    添加事件格式：
    "xber3456": {
        "status": 1,      // 事件状态
        "events":[
            {
                "number": 1, // 子事件的序号
                "status": 1, // 子事件状态
                "describe"："xxxxxx",   // 对事件的描述
                "start_time": "2022-05-20 08:07:30", // 开始时间
                "end_time": "2022-05-20 09:07:30", // 结束时间
                "reminder_type":  1, // 提醒类型
                "reminder_time": {
                    "day": true,    // 每天提醒
                    "week": false,  // 每周提醒
                    "month": false, // 每月提醒
                    "expire": false, // time指定的日期快要过期前提醒
                    "time": "2022-05-20 09:07:30" // 提醒的具体时间
                },
                "how_to": { // 如何完成这件事，这件事需要达到什么样的效果。
                    "describe": "xxxx",
                    ...
                }
            }，
            {...} // 事件列表
        ]
    }
}
*/

#define MACRP_ModifyEvent   "/ModifyEvent"
/*
参数
{
    "ID": "xber3456", // 需要修改事件的ID
    "number": 1, // 子事件的编号
    "modify": {
        "describe": "yyyyyyyyy", // 需要修改的值，这个只是其中的一个例子,参考上面添加的例子
        ...
    }
}
*/

#define MACRP_RequestEventList "/RequestEventList"   // 请求事件列表
/*
参数：无
返回：
{
    "EventName":[
        "xber3456",
        ...
    ]
}
*/

#define MACRP_RequestEventContent "/RequestEventContent" // 请求事件内容
/*
{
    "EventName": "xber3456"
}
*/

#endif