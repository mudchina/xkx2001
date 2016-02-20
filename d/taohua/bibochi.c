//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "碧波池");
	set("long", @LONG
绕过如同石屏风一般的涵碧峰，是一汪晶莹剔透，碧玉般的池水。池底有两眼活
泉，一为寒泉，一为温泉，所以池水冬暖夏凉，四季不涸，且水质特佳，不亚于天下
任何名泉。池养鱼鳖，大多是罕见异种，其中五色锦鲤嘻游嘬花，池中大鼋寿龄已达
五百余岁。更传说池中有可克百毒的“金娃娃”出现。北面隐隐约约有一座精舍，东
面靠近池中心处有一块奇形大石。
LONG
	);
	 set("exits", ([
                "southwest" : __DIR__"hanbi",
                "east" : __DIR__"tingyu",
                "north" : __DIR__"jingshe",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
