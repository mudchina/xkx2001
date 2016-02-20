//Cracked by Roath
// Room: /d/death/noteroom.c
// mantian may/2001
// xQin 05/01

inherit ROOM;
#include <ansi.h>
void init();

void create()
{
        set("short", "玩家犯罪记录室");
        set("long", @LONG
这里是犯罪记录室，提供巫师记录玩家被抓的原因，以免其他巫师接手
后听信玩家片面之词而释放错人。
LONG );
	
        set("exits", ([
        "east" : "/d/wizard/wizard_room",
        "west" :   __DIR__"blkbot" ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();
	call_other("/clone/board/note1_b", "???");

}
void init()
{
	object me = this_player();
	if (wizhood(me) == "(player)")
	{
		write(HIW "\n这不是你该来的地方\n\n" NOR);
		me->set("startroom", "/d/death/death");
		me->move("/d/death/death.c");
		return 0;
	}
}

