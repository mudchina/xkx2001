//Cracked by Roath
// Room: /d/xiangyang/kedian.c

inherit ROOM;

void create()
{
	set("short", "[1;36mÏå·®¿Íµê[2;37;0m");
	set("long", @LONG
ÓÉÓÚÃÉ¹Å´ó¾ü±øÁÙÏåÑô³ÇÏÂ£¬Òò´ËÍ¶ËŞ¿ÍÕ»µÄ¿ÍÈËÒ²¼õÉÙÁËĞí¶à£¬Î©¿ÖÊÜµ½
²¨¼°¡£ÉúÒâ²»ºÃ£¬ÓÖÓĞÕ½ÂÒµÄÍşĞ²£¬µêĞ¡¶şÒ²Ò»¸±³îÃ¼¿àÁ³µÄÄ£Ñù¡£µêøÎÓĞ¼¸¸ö
¹í¹íËîËîµÄ¼Ò»ï×øÁËÒ»×À£¬àÖàÖ¹¾¹¾µØ²»ÖªËµĞ©Ê²Ã´¡£Ç½ÉÏ¹Ò×ÅÒ»¸öÅÆ×Ó(paizi)
 £¬ÒÑ¾­ÓĞµãÆÆÀÃÁË¡£
LONG
	);
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("no_sleep_room", 1);
	set("coordinates", ([ "x" : 4, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"majiu",
  "up" : __DIR__"kedian2",
  "west" : __DIR__"jzjie1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "Â¥ÉÏÑÅ·¿£¬Ã¿Ò¹Ê®Á½....ºóÃæµÄ×ÖÒòÎªÅÆ×ÓÆÆËğ£¬¿´²»Çå³ş¡£
",
]));

	setup();
	replace_program(ROOM);
}
