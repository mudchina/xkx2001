//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "头台");
	set("long", @LONG
离开仙人洞，南走十余里，就到了头台。这里山沟显得宽阔，山
势也见得低缳些。这里是从伊犁至内地的第一驿站，设有客店，筑有
炮台，置兵把守，过往的商人车马都在此过夜。
LONG
	);
	set("exits", ([
                "north" : __DIR__"",
                "south" : __DIR__"",
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
