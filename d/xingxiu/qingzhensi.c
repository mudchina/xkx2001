//Cracked by Roath
// qingzhensi.c 艾提朵尔清真寺
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "艾提朵尔清真寺");
	set("long", @LONG
艾提朵尔清真寺是回疆最大的清真寺，寺院由门、庭园、经堂和礼
拜殿四大部分组成，建宏伟，富丽堂皇。浅蓝色的大门上方刻有可兰
经经文，周围衬托着维族风格的精美图案。每逢节日，尤其是古尔邦节
、肉孜节的清晨时分，做第一次礼拜时，全城乃至外地的穆斯林蜂拥入
内，大寺门前的广场也站满了教徒，阵容之大，令人吃惊。
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"shule",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/moslem" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
