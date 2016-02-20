//Cracked by Roath
// /d/huanghe/bangjob/bangjob20000.c
// by aln 2 / 98

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *bangjobs = ({
        ([      "name"  :  "ÍõÎå",
                "file"  :  "/d/city/npc/guidao",
                "area"  :  "ÑïÖÝ×íÏÉÂ¥",
                "type"  :  "É±",
                "bonus" :  15,
                "score" :  4,
        ]),

        ([      "name"  :  "¿Õ¿Õ¶ù",
                "file"  :  "/d/city/npc/qigai.c",
                "area"  :  "ÑïÖÝ³Ç",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  20,
        ]),

        ([      "name"  :  "Ñ²²¶",
                "file"  :  "/d/city/npc/xunbu",
                "area"  :  "ÑïÖÝ³Ç",
                "type"  :  "É±",
                "bonus" :  50,
                "score" :  15,
        ]),

        ([      "name"  :  "¶ÎÚê",
                "file"  :  "/d/dali/npc/duanjin",
                "area"  :  "¶¨°²¸®",
                "type"  :  "É±",
                "bonus" :  50,
                "score" :  30,
        ]),

        ([      "name"  :  "³£³¤·ç",
                "file"  :  "/d/forest/npc/chang",
                "area"  :  "ÑïÖÝ½¼Íâ",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "»¨½£Ó°",
                "file"  :  "/d/forest/npc/hua",
                "area"  :  "ÑïÖÝ½¼Íâ",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "ÆÝ·¼",
                "file"  :  "/d/foshan/npc/qifang",
                "area"  :  "·ðÉ½Õò",
                "type"  :  "É±",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "·ïÒ»Ãù",
                "file"  :  "/d/foshan/npc/yiming",
                "area"  :  "·ðÉ½Õò",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "åÐÒ£×Ó",
                "file"  :  "/d/forest/npc/xiaoyaozi",
                "area"  :  "ÑïÖÝ½¼Íâ",
                "type"  :  "É±",
                "bonus" :  40,
                "score" :  12,
        ]),

        ([      "name"  :  "Áõºççø",
                "file"  :  "/d/quanzhou/npc/liuhongying",
                "area"  :  "ÈªÖÝÑïÍþÎä¹Ý",
                "type"  :  "É±",
                "bonus" :  20,
                "score" :  6,
        ]),

        ([      "name"  :  "Áúîý",
                "file"  :  "/d/quanzhou/npc/longquan",
                "area"  :  "ÈªÖÝÑïÍþÎä¹Ý",
                "type"  :  "É±",
                "bonus" :  20,
                "score" :  6,
        ]), 

        ([      "name"  :  "µ¶¿Í",
                "file"  :  "/d/taishan/npc/dao-ke",
                "area"  :  "Ì©É½",
                "type"  :  "É±",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "½£¿Í",
                "file"  :  "/d/taishan/npc/jian-ke",
                "area"  :  "Ì©É½",
                "type"  :  "É±",
                "bonus" :  12,
                "score" :  3,
        ]),

        ([      "name"  :  "ÍÁ·ËÍ·",
                "file"  :  "/d/wudang/npc/tufeitou",
                "area"  :  "Îäµ±É½",
                "type"  :  "É±",
                "bonus" :  50,
                "score" :  17,
        ]),

        ([      "name"  :  "³¤½£",
                "file"  :  "/clone/weapon/changjian",
                "type"  :  "Ñ°",
                "bonus" :  8,
                "score" :  1,
        ]),

        ([      "name"  :  "Ä¹±®",
                "file"  :  "/d/forest/npc/obj/mubei",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "name"  :  "ºÓÍ¼",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "ÂåÊé",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "¹ãÁêÉ¢",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "ÂÊÒâÌû",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "ÆåÆ×",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "ÐÐÂÃÍ¼",
                "file"  :  "  ",
                "type"  :  "Ñ°",
                "bonus" :  10,
                "score" :  3,
        ]),

        ([      "name"  :  "½ð½äÖ¸",
                "file"  :  "/d/city/npc/obj/goldring",
                "type"  :  "Ñ°",
                "bonus" :  15,
                "score" :  5,
        ]),

        ([      "name"  :  "×ÏÅÛ",
                "file"  :  "/d/dali/obj/zipao",
                "type"  :  "Ñ°",
                "bonus" :  25,
                "score" :  10,
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),

        ([      "type"  :  "½ØïÚ",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_job()
{
        return bangjobs[random(sizeof(bangjobs))];
}
