//Cracked by Roath
// group bwdh/gamble_room
// Apache 09/29/98

#include <ansi.h>

inherit ROOM;

string long_desc();
string look_paizi();

void create() {
    set("short", "赌场");
    set("long", (: long_desc :) );
    set("exits", ([
        "west"  : __DIR__"square",
    ]));
    set("item_desc", ([
        "paizi" : (: look_paizi :),
    ]));
    set("valid_startroom", 1);

    setup();
}

void init() {
    object ob = this_object();

    if ( !ob->query("status") ) ob->set("status", 0); // 1 for bet -1 for collect
    if ( !ob->query("round") ) ob->set("round", 0); // round number for current bet
    if ( !ob->query("east") ) ob->set("east", 0); // east bet ratio: n for n ~ 1, -n for 1 ~ n
    if ( !ob->query("west") ) ob->set("west", 0); // west bet ratio:
    if ( !ob->query("win") ) ob->set("win", "none"); // winning side

    add_action("do_bet", "bet");
    add_action("do_collect", "collect");
}

string look_paizi() {
    object ob = this_object();
    string msg;
    int i;

    if ( ob->query("status") == 1) {
        msg = HIY"\n" + sprintf("    第 %2d 局  压注中\n    －－－－－－－－", ob->query("round")) + "\n"NOR;
        i = to_int(ob->query("east"));
        if ( i > 0 )
            msg = msg + HIR"    东队  " + chinese_number(i) + "赔一\n"NOR;
        else if (i < 0)
            msg = msg + HIR"    东队  一赔" + chinese_number(-i) + "\n"NOR;
        i = to_int(ob->query("west"));
        if ( i > 0 )
            msg = msg + HIR"    西队  " + chinese_number(i) + "赔一\n"NOR;
        else if (i < 0)
            msg = msg + HIR"    西队  一赔" + chinese_number(-i) + "\n"NOR;
    }
    else if ( ob->query("status") == -1) {
        msg = HIY"\n" + sprintf("    第 %2d 局  赔付中\n    －－－－－－－－", ob->query("round")) + "\n"NOR;
        if ( ob->query("win") == "east" )
            msg = msg + HIR"        东队获胜\n"NOR;
        else if (ob->query("win") == "west" )
            msg = msg + HIR"        西队获胜\n"NOR;
        else
            msg = msg + HIW"      本局无赢家\n"NOR;
        return msg;
    }
    else
        msg = HIG"    暂无赌局\n"NOR;
    return msg;
}

string long_desc() {
    string msg;
    object ob = this_object();

    if (ob->query("status") == 1 )
        msg = "赌场内人山人海，乌烟瘴气。大家纷纷下注，有人口沫横飞地\n发表意见，有人两眼发直，喃喃自语。\n";
    else if (ob->query("status") == -1 )
        msg = "赌场现在是赔付时间，赢家喜气洋洋，得意地数着银子，输家\n早已急红了眼，面红耳赤。\n";
    else
        msg = "赌场现在没有营业，所以冷冷清清的。\n";

    msg = msg + "赌场正中挂者一个牌子(paizi)。\n";
    return msg;
}

int do_bet(string arg) {
    object ob = this_object();
    object me = this_player();
    object money;
    int i, balance;
    string side;

    if ( ob->query("status") != 1 )
        return notify_fail("现在不是压注时间。\n");

    if (sscanf(arg, "%s %d", side, i) != 2) 
        return notify_fail("什么？\n");

    if ( ((side != "east") && (side != "west")) )
        return notify_fail("什么？\n");

    if ( i < 0 )
        return notify_fail("限额在一到一百两白银。\n");

    money = present("silver_money", me);
    if( !money )
        return notify_fail("你身上没有这种货币。\n");
    if( (int)money->query_amount() < i)
        return notify_fail("你身上没有那么多白银。\n");
    money->set_amount((int)money->query_amount() - i);
    money->move(me);

    switch(side) {
    case "east" :   if ( me->query("bwdh_gamble/east_round") == ob->query("round") )
                        balance = me->query("bwdh_gamble/east_bet");
                    else
                        balance = 0;
                    me->set("bwdh_gamble/east_round", ob->query("round"));
                    if ( balance == 0 ) {
                        me->set("bwdh_gamble/east_bet", i);
                        write("你押了" + chinese_number(i) + "两白银在东队。\n");
                        return 1;
                    }
                    else {
                        me->set("bwdh_gamble/east_bet", i + balance);
                        write("你又押了" + chinese_number(i) + "两白银在东队。\n");
                        return 1;
                    }
                    break;
    case "west" :   if ( me->query("bwdh_gamble/west_round") == ob->query("round") )
                        balance = me->query("bwdh_gamble/west_bet");
                    else
                        balance = 0;
                    me->set("bwdh_gamble/west_round", ob->query("round"));
                    if ( balance == 0 ) {
                        me->set("bwdh_gamble/west_bet", i);
                        write("你押了" + chinese_number(i) + "两白银在东队。\n");
                        return 1;
                    }
                    else {
                        me->set("bwdh_gamble/west_bet", i + balance);
                        write("你又押了" + chinese_number(i) + "两白银在东队。\n");
                        return 1;
                    }
                    break;
    default : break;
    }

    return 1;
}

int do_collect() {
    object ob = this_object(), me = this_player(), money;
    int bet, ratio;
    string win_side;

    if ( ob->query("status") != -1 )
        return notify_fail("现在不是赔付时间。\n");

    win_side = ob->query("win");
    if ( win_side != "east" && win_side != "west" )
        return notify_fail("本局无赢家。\n");

    switch(win_side) {
    case "east" :   if ( me->query("bwdh_gamble/east_round") == ob->query("round") ) {
                        bet = me->query("bwdh_gamble/east_bet");
                        ratio = ob->query("east");
                    }
                    else {
                        write("赌场伙计对你“哼”的冷笑一声，一脚把你踢出门外。\n");
                        me->move(__DIR__"square");
                        return 1;
                    }
                    me->set("bwdh_gamble/east_round", 0);
                    break;
    case "west" :   if ( me->query("bwdh_gamble/west_round") == ob->query("round") ) {
                        bet = me->query("bwdh_gamble/west_bet");
                        ratio = ob->query("west");
                    }
                    else {
                        write("赌场伙计对你“哼”的冷笑一声，去招呼其他人了。\n");
                        return 1;
                    }
                    me->set("bwdh_gamble/west_round", 0);
                    break;
    default: break;
    }

    money = new("/clone/money/silver");
    if (ratio > 0)
        bet = bet + (int) (bet / ratio * 9 / 10);
    else
        bet = bet - bet * ratio * 9 / 10;
    money->set_amount(bet);
    money->move(me);
    me->set("bwdh_gamble/east_round", 0);
    write ("赌场付给你" + chinese_number(bet) + "两白银。\n");
    return 1;
}

int valid_leave(object player, string dir) {
    if (!wizardp(player) && dir == "up")
        return notify_fail("此间主人并没有邀请你去那里！\n");

    return ::valid_leave(player, dir);
}