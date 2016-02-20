//Cracked by Roath
// Room: /adm/register/reg_room.c

inherit ROOM;

void create()
{
        set("short", "侠客岛挂名处");
        set("long", @LONG
这是一个大厅，厅的中央是一张大桌子，桌上摆着一个厚厚的本
子。桌子後面，靠墙立着一排书架，架子上排满了和桌上差不多的本
子。一个人正坐在桌子後翻看着那大本子，还不时拿起笔在上面修改
什麽。
LONG);

        set("objects", ([
                "/d/xiakedao/npc/mux" : 1,
        ]));

        set("invalid_startroom", 1);
        set("no_fight", "1");
        setup();
//      load_object("/daemon/board/wizard");
//      replace_program(ROOM);
}
void init()
{
        object ob = this_player();

        if (!wizardp(ob)) {
                add_action("block_cmd","",1);
//                ob->set("startroom", "/d/death/death");
                ob->set("block", 1);
        }
}

int block_cmd()
{
        string cmd;
        cmd = query_verb();
        if ( cmd == "quit" || cmd == "goto" || cmd == "suicide" || cmd == "register" || cmd == "tell" || cmd == "say" || cmd == "reply" || cmd == "look")
                return 0;
        return 1;
}

