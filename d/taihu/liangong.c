//Cracked by Roath
// Room: 
// Date: 

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是归云庄陆少庄主的练功房。由与陆少庄主乃少林旁支
仙霞派出身，所以房中布置尽是为习练外门硬功之用，竖立着不
少木桩和草靶。西边角上还有两个大沙坑，天花板上吊着一支大
沙袋。
LONG
	);

	set("exits", ([
		"west" : __DIR__"huayuan",
	]));


	set("objects",([
//		    __DIR__"npc/xiaoping" : 1,
//                __DIR__"npc/mu-ren" : 1
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

