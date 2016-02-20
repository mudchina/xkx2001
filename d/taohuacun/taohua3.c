// Room: /d/taohuacun/taohua3.c

inherit ROOM;

string look_shibei();
void create()
{
	set("short", "桃花谷");
	set("long", @LONG
顺溪流而上，两边山势渐高，流水渐急，桃林也愈见密集，层
层桃花拥攒成一片晚霞，留心处，时时可见悬泉飞瀑，倒挂崖间。
桃花溪水跳荡起伏，青鳞赤鲤隐隐相戏。这里就是桃花谷了。谷口
一个尺许高的小篆石碑(shibei)斜侧路旁。
LONG );
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("item_desc", ([
		"shibei" : (: look_shibei :),
	]));
	set("exits", ([
		"eastdown" : __DIR__"taohua2",
		"northup"  : __DIR__"taohua4",
	]));
	setup();
//	replace_program(ROOM);
}

string look_shibei()
{
        return
        "※※※※※※※※※※※※※※※\n"
        "※※                      ※※\n"
        "※※        桃花村        ※※\n"
        "※※                      ※※\n"
        "※※※※※※※※※※※※※※※\n";
}
