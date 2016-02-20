//Cracked by Roath
// jietuo.c 解脱坡
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "解脱坡");
	set("long", @LONG
这里是峨嵋胜地解脱坡。坡下一座小桥，叫解脱桥。行人至此，坐桥上听
泉声甚美。当此良辰美景，心无芥蒂，心即解脱。坡上一座庵堂，东下一片密
林。桥下山溪向东流淌到报国寺的西面。
LONG
	);
	set("exits", ([
		"eastdown" : __DIR__"fuhuroad2",
		"west" : __DIR__"guanyin",
	]));


        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 3);
	setup();
	replace_program(ROOM);
}

/*

偶过山间寻胜迹，忽从坡上发深思。
纵饶解脱虚空外，终是尘缘未了时。

*/
