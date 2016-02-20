//Cracked by Roath
// /d/shenlong/sgjob/sgjob50000.c

// inherit SKILL;

inherit F_CLEAN_UP;

mapping *sgjobs = ({
        ([      "sgjob":          "Ì«¼«Ê®ÈýÊÆ",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "¾ÉÖñÆ¬",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "±¡¾î",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "Ê¯°å",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             50,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "×ÏÏ¼ÃØóÅ",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             200,
                "pot_bonus":             50,
                "score":                 2
        ]),

        ([      "sgjob":          "ÕÈ·¨Í¼½â",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             150,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "±ÌÁ×Õë",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             160,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "»¯Ê¬·Û",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             160,
                "pot_bonus":             40,
                "score":                 2
        ]),

        ([      "sgjob":          "Ïã",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             60,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "Á¶ÐÄµ¯",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             60,
                "pot_bonus":             10,
                "score":                 1
        ]),

        ([      "sgjob":          "ÃÉº¹Ò©",
                "sgjob_type":           "Ñ°",
                "exp_bonus":             30,
                "pot_bonus":             5,
                "score":                 1
        ]),

        ([      "sgjob":          "ÉßÕÈ",
                "sgjob_type":           "Ñ°",
                "exp_bonus":            120,
                "pot_bonus":             30,
                "score":                 2
        ]),

        ([      "sgjob":          "ÇåÐÄÉ¢",
                "sgjob_type":           "Ñ°",
                "exp_bonus":            100,
                "pot_bonus":             30,
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
});

void create() { seteuid(getuid()); }

mapping query_sgjob()
{
        return sgjobs[random(sizeof(sgjobs))];
}

