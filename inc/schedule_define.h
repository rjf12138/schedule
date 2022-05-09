#ifndef __SCHEDULE_DEFINE_H__
#define __SCHEDULE_DEFINE_H__

enum EEventType {
    EEventType_SingleEvent,         // 单个事件
    EEventType_ContinuousEvent,     // 持续事件：由多个相关联的单个事件组成一个统一的事件，比如学习微积分，可以拆分成学习微分和积分两个事件
    EEventType_EmergencyEvent,      // 紧急事件：具有最高优先级
};

enum EReminderType {
    EReminderType_RemindOnlyOnce,   // 只提醒一次
    EReminderType_RegularReminder,  // 定时提醒
};

// 每个事件有一个独一无二的编号, 编号由系统生成
#define  MACRP_AddEvent   "AddEvent"        // 添加事件
/*
{
    "number" : "xber3456",
    "name":"xxxxxx",
    添加事件格式：
    "xber3456": {
        "type": 1,      // 事件类型
        "events":[
            {
                "describe"："xxxxxx",   // 对事件的描述
                "start_time": "2022-05-20 08:07:30", // 开始时间
                "end_time": "2022-05-20 09:07:30", // 结束时间
                "reminder_type":  1, // 提醒类型
                "reminder_time": {
                    "day": true,    // 每天提醒
                    "week": false,  // 每周提醒
                    "month": false, // 每月提醒
                    "time": "2022-05-20 09:07:30" // 提醒的具体时间
                }
            }，
            {...} // 事件列表
        ]
    }
}
*/

#endif