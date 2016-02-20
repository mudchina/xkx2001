//Change by Server
// Room: /adm/register/reg_room.c

inherit ROOM;

void create()
{
	set("short", "侠客行登记处");
	set("long", @LONG
为了更好地管理侠客行，我们要求你在进入侠客行之前先办好
登记手续，请用 register 指令在此登记，必须用完整及真实的 email
（可以是bbs email），千万不能有错，否则后果自负。最好在别处
先把指令写好，反复检查几遍后再copy & paste.

比如，如果你的email地址是tu@albert.uwinnpeg.ca
你就打以下指令：register tu@albert.uwinnipeg.ca

然后，我们会给你一个密码。

LONG
	);

	set("objects", ([
//		__DIR__"attr" : 1,
//		__DIR__"name" : 1,
		__DIR__"shaoye" : 1,
	]));
        set("exits", ([ /* sizeof() == 1 */
//              "north" : "/adm/guild/meetingroom"
        ]));

	set("invalid_startroom", 1);
	setup();
//	load_object("/daemon/board/wizard");
//	replace_program(ROOM);
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

