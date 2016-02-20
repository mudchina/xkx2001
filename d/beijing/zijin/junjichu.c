//Cracked by Roath
// Room: /d/beijing/zijincheng/junjichu.c

inherit ROOM;

void create()
{
	set("short", "军机处");
	set("long", @LONG
清雍正七年(1729)雍正为加强中央集权,和即时调兵遣将,特设军机房.
乾隆即位后,改为总理处.三年命名军机处.
    军机处设军机大臣,军机章京等官职,他们在此值班,听候皇帝召见,共同密
商军政要事,协助皇帝处理军政事务.
/*这是一排小平房,按解绍应为东头是侍卫值宿室,西头是内务大臣办事处,中间
是军机处.但我不知怎样安排*/
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"xiaohuayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
