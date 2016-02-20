//Cracked by Roath
// casino tool for casino in sjsz
// Apache 10/98

inherit ITEM;

void create() {
    set_name("赌台", ({ "casino table" }));
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "张");
        set("long", "这张赌台是控制赌场的：\nCommands:\n  casino east n\n  casino west n \n
  casino bet \n  casino pay \n  casino stop \n");
        set("material", "steel");
        set("weight", 5000);
        set("value", 10000000);
        set("no_get", 1);
    }
    setup();
}

void init() {
    add_action("casino_cmds", "casino");
}

int casino_cmds(string arg) {
    object me = this_player();
    object room;
    string cmd, temp;
    int args, ratio, round;
    

    if (!wizardp(me))
        return 0;
    if (!arg)
        return notify_fail("指令错误！（无参数）\n");

    args = sscanf(arg, "%s %d", cmd, ratio);
    if (args != 2)
        args = sscanf(arg, "%s", cmd);
    room =  find_object("/d/bwdh/sjsz/gamble_room");
    if (!objectp(room)) {
        room = load_object("/d/bwdh/sjsz/gamble_room");
        if (!objectp(room))
            return notify_fail("找不到赌场。\n");
    }

    if (args == 1) {
        switch (cmd) {
        case "bet" :  if ( room->query("status") == 1)
                          return notify_fail("赌场现在正在接收压注。\n");
                      else {
                          round = room->query("round");
                          round++;
                          room->set("round", round);
                          temp = "第" + chinese_number(round) + "局";
                          room->set("status", 1);
                          message_vision("$N大喊一声：“" + temp + "，开赌！”\n", me);
                          return 1;
                      }
                      break;
        case "pay" :  if ( room->query("status") == -1)
                          return notify_fail("正赔着呢！\n");
                      else {
                          room->set("status", -1);
                          message_vision("$N哭丧着脸道：“完了，又要赔了。”\n", me);
                          return 1;
                      }
                      break;
        case "stop":  if (room->query("status") == 0)
                          return notify_fail("赌场已经关门啦。\n");
                      else {
                          room->set("status", 0);
                          message_vision("$N关闭了赌场。\n", me);
                          return 1;
                      }
                      break;
        default : return notify_fail("指令错误！（单参数）\n");
                  break;
        }
    }

    if (args == 2) {
         if (room->query("status") != 0)
             return notify_fail("请先关闭赌场。\n");
         if (ratio > 0)
             temp = chinese_number(ratio) + "赔一";
         else if (ratio < 0)
             temp = "一赔" + chinese_number(-ratio);

         switch (cmd) {
         case "east" : if (ratio != 0) {
                           room->set("east", ratio);
                           message_vision("$N设定东队赔率为" + temp +"。\n", me);
                           return 1;
                       }
                       else {
                           room->set("win", "east");
                           message_vision("$N判定东队胜！\n", me);
                           return 1;
                       }
                       return 1;
         case "west" : if (ratio != 0) {
                           room->set("west", ratio);
                           message_vision("$N设定西队赔率为" + temp +"。\n", me);
                           return 1;
                       }
                       else {
                           room->set("win", "east");
                           message_vision("$N判定西队胜！\n", me);
                           return 1;
                       }
                       return 1;
         default : return notify_fail("指令错误！（双参数）\n");
                   break;
         }
    }  

    return notify_fail("指令错误！\n");
}
