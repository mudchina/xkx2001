//Cracked by Roath
// Room: didao.c 地道入口
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "地道入口");
	set("long", @LONG
这里是厚土旗挖的地道入口，一座小土堆的后面，是一个黑漆漆的洞
穴通往地下。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down": __DIR__"didao1",
		"northeast" : "/d/kunlun/shanqiu",
]));
	set("no_clean_up", 1);
	set("cost", 1);

	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ((!me->query("family") || me->query("family/family_name")!="明教") &&
		dir == "down")
		return notify_fail("几名厚土旗壮汉挡住你，说道：外人不得进入地道！\n");
	
	return ::valid_leave(me,dir);
}