AbandonedShip_Rooms2_1F_MapScripts:: @ 82380A6
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan:: @ 82380A7
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons //, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan:: @ 82380D7
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch:: @ 82380F0
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira:: @ 823810B
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons //, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira:: @ 823813B
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch:: @ 8238154
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani:: @ 823816F
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison:: @ 8238186
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro: @ 823819D
	.string "SID: We were searching for crystals,\n"
	.string "but we found a TRAINER instead!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat: @ 82381DA
	.string "SID: We worked together, but we still\n"
	.string "didn't win…$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle: @ 823820F
	.string "SID: I'm looking for a small crystal,\n"
	.string "like something which will fit in a ring,\l"
	.string "but all I can find here are large ones…$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons: @ 8238257
	.string "SID: You won't stand a chance if you\n"
	.string "don't have even two POKéMON!$"

AbandonedShip_Rooms2_1F_Text_KiraIntro: @ 82382A4
	.string "MIRA: A TRAINER?\n"
	.string "My boyfriend and I were on a date,\l"
	.string "but you had to come and ruin it!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat: @ 82382F4
	.string "MIRA: Oh, no! We didn't stand a chance!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle: @ 823830A
	.string "MIRA: This place is so pretty!\p"
	.string "SID is the most romantic boyfriend\n"
	.string "any girl could ever ask for!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons: @ 823836F
	.string "MIRA: You don't even have two POKéMON?\n"
	.string "Come back some other time!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister: @ 82383BB
	.string "MIRA: Oh, you make me so angry!\n"
	.string "I'm going to register you for that!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro: @ 82383FF
	.string "SID: I just finished making the\n"
	.string "ring for MIRA!\p"
	.string "Let's battle to celebrate!$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat: @ 8238473
	.string "SID: I was distracted by the ring!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch: @ 8238491
	.string "DAN: We can't find any treasures,\n"
	.string "we lose at POKéMON…\p"
	.string "I want to go home… But if I say that,\n"
	.string "she gets all angry with me…$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons: @ 8238509
	.string "DAN: You don't even have two POKéMON.\n"
	.string "You can't expect to beat us like that.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro: @ 8238556
	.string "MIRA: Oh, you're back?,\p"
	.string "Why don't you let us enjoy our date?\p"
	.string "Leave us alone!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat: @ 82385F2
	.string "KIRA: Oh, we lost again…$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch: @ 823860B
	.string "KIRA: We're not leaving until we raise\n"
	.string "our POKéMON some more and we find\l"
	.string "the treasures here!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons: @ 8238668
	.string "KIRA: Oh, you don't have two POKéMON?\n"
	.string "We'll have to battle some other time!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro: @ 82386B4
	.string "I'm not good at swimming,\n"
	.string "but I am good at battles!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat: @ 82386E8
	.string "Oops.\n"
	.string "That didn't go very well.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle: @ 8238708
	.string "Walking around barefoot in this ship\n"
	.string "is kind of gross.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro: @ 823873F
	.string "Strength and compassion…\n"
	.string "Those are a TRAINER's treasures!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat: @ 8238779
	.string "Ah, there is something about you\n"
	.string "that sparkles.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle: @ 82387A9
	.string "In a cabin somewhere on board,\n"
	.string "I saw something sparkle.$"
