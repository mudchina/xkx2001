//Cracked by Roath
// /d/shenlong/sgjob/sgjob20000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *sgjobs = ({
        ([      "sgjob":          "µÀµÂ¾­",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             10,
                "pot_bonus":             3,
                "score":                 1
        ]),

        ([      "sgjob":          "¡ºÐÇËÞ¶¾¾­¡»",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "³ÖÊÀÍÓÂÞÄá¾­",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             40,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "Ìú°ËØÔ",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             120,
                "pot_bonus":             30,
                "score":                 2
        ]),

        ([      "sgjob":          "»ªÉ½½£Æ×",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "ÌÆÊ«Ñ¡¼­",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "ºú¼Òµ¶·¨²ÐÆª",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             250,
                "pot_bonus":             60,
                "score":                 2
        ]),

        ([      "sgjob":          "ÉÙÁÖÓ¢ÐÛÁî",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             120,
                "pot_bonus":             30,
                "score":                 1
        ]),

        ([      "sgjob":          "·£¶ñÁî",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             100,
                "pot_bonus":             25,
                "score":                 2
        ]),

        ([      "sgjob":          "ÉÍÉÆÁî",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             100,
                "pot_bonus":             25,
                "score":                 2
        ]),

        ([      "sgjob":          "ÕýÆø¾÷¾÷Æ×ÉÏ¾í",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "ÕýÆø¾÷¾÷Æ×ÏÂ¾í",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "×Ïë³Ò÷¾÷Æ×ÉÏ¾í",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "×Ïë³Ò÷¾÷Æ×ÏÂ¾í",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             30,
                "pot_bonus":             8,
                "score":                 1
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "FORCEJOIN",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),

        ([      "sgjob":          "PK",
        ]),
});

void create() { seteuid(getuid()); }

mapping query_sgjob()
{
        return sgjobs[random(sizeof(sgjobs))];
}


