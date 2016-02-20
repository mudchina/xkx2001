//Cracked by Roath
// Room: /d/xixia/oldwall.c

inherit FERRY;

void create()
{
	set("short", "古长城");
	set("long", @LONG
这里是一段古长城。相传是当年秦始皇派他的心腹爱将蒙恬率三
十万大军所修。世事变迁、沧海桑田，如今这里已是一片废墟，唯一
依稀可见的是夯土制成的烽火台象个小土包一样矗立在那里。黄河从
西向东流去，河上有一叶小舟摆渡乘客，你可以叫(yell)一下船家。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"shimen",
  "southwest" : __DIR__"ypshui",
]));

	set("name", "江");
	set("boat", __DIR__"duchuan");
	set("opposite", __DIR__"xhbao");

	setup();
}
