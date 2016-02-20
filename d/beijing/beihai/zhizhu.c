//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "智珠殿");
	set("long", @LONG
这是一座古色古香的大殿，是为供奉文殊佛像之所。殿前有一座大香炉，
香炉内烟雾缭绕，可见香火很盛。殿北有见春亭，亭北有琼岛春荫石幢，幢首、
石座、栏杆雕刻均精美。传为燕京八景之一。
LONG
	);
	set("cost", 2);
		 
	set("exits", ([
                "northdown" : __DIR__"shiqiao",
                "southwest" : __DIR__"yongansi",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
