//Cracked by Roath
// Room: /d/heimuya/heimulin7.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "��ľ��");
        set("long", @LONG
����һ�����ص����֣���Χ����������Ĳ��������
�����Ｋ�����������������۾�Ҳ������������������
��·��һ����紵�����ң���Ҷ����ɳɳ������������
���������� 
LONG
        );

        set("exits", ([
                "north" : __DIR__"heimulin7",
                "east" : __DIR__"heimulin5",
                "south" : __DIR__"heimulin7",
                "west" : __DIR__"heimulin5",
        ]));

        set("objects", ([
                "/clone/beast/laohu" : 2,
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}
