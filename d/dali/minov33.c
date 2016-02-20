//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov33.c

inherit ROOM;

void create()
{
	set("short", "半山竹林");
	set("long", @LONG
一大片茂密的成年竹林生长在半山腰的缓坡上。竹子对大理地区各民族来说
是，既是重要的建筑材料，也是日常生活用品的原材料。山下的村庄里的摆夷人
经常上山来采伐竹子。北面山上有溪流下，到这里水流已经颇大，山民经常把砍
伐下的竹子丢在溪中，任其顺水飘流，到村子附近的溪水里再捞起来。
LONG);
	set("objects", ([
		__DIR__"npc/byshanren1.c" : 2,
		]));
	set("exits", ([
		"northup" : __DIR__"minov32",
		"eastdown" : __DIR__"minov34",
		]));
	set("area", "步雄部");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
