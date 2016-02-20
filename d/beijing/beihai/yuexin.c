//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "悦心殿");
	set("long", @LONG
这里是永安寺西之悦心殿，殿内为五开间、西山灰瓦顶，是清帝引见、
理事之所。殿内非常安静，只依稀可闻有僧人扫着落叶的声音。殿前有宽
阔的月台，与庆宵楼相连殿内院中有一棵老树，枝叶茂密。殿内光线很暗，
看不清楚有些什么。
LONG
	);
	set("cost", 2);
	
    
	 
	set("exits", ([
                "east" : __DIR__"yongansi",
                "northup" : __DIR__"qingxiao",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
