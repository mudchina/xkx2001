//Cracked by Roath
// shijie1.c 石阶
// by Xiang

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
	你走在一条坚实的石阶上，不时地有进香客从你的身边走过。一边是峭
壁，一边是悬崖，抬头隐约可见笼罩在云雾中的天柱峰，听着流水淙淙，令人心
旷神怡。山上五里是一座宫宇。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"shanmen",
		"southup" : __DIR__"yuzhen",
	]));
	
	
    set("objects", ([
            __DIR__+"npc/guest" : 2 ]));
	            
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

