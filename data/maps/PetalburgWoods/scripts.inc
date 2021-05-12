PetalburgWoods_MapScripts::
	.byte 0


TangeloWoodsManiac::
	lock
	faceplayer
	msgbox TangeloWoodsManiac_Text_0, MSGBOX_AUTOCLOSE
	release
	return


TangeloWoodsSign1::
	lock
	msgbox TangeloWoodsSign1_Text_0, MSGBOX_SIGN
	release
	return


TangeloWoodsSign::
	lock
	msgbox TangeloWoodsSign_Text_0, MSGBOX_SIGN
	release
	return


TangeloWoodsHoneyTree::
	lock
	msgbox TangeloWoodsHoneyTree_Text_0, MSGBOX_SIGN
	release
	return


TangeloWoodsYoungsterCyril::
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat, Route104_Billy_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq TangeloWoodsYoungsterCyril_2
TangeloWoodsYoungsterCyril_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq TangeloWoodsYoungsterCyril_5
TangeloWoodsYoungsterCyril_4:
	msgbox Route104_Text_BillyPostBattle, MSGBOX_DEFAULT
	release
	end

TangeloWoodsYoungsterCyril_2:
	goto Route104_Billy_Rematch
	goto TangeloWoodsYoungsterCyril_1

TangeloWoodsYoungsterCyril_5:
	goto Route104_Billy_CheckMatchCall2
	goto TangeloWoodsYoungsterCyril_4


Route104_Billy_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Billy_CheckMatchCall_2
Route104_Billy_CheckMatchCall_1:
	release
	end

Route104_Billy_CheckMatchCall_2:
	goto Route104_Billy_RegisterShortMatchCall
	goto Route104_Billy_CheckMatchCall_1


Route104_Billy_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY
	release
	end


Route104_Billy_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Billy_CheckMatchCall2_2
Route104_Billy_CheckMatchCall2_1:
	msgbox Route104_Text_BillyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_Billy_CheckMatchCall2_2:
	goto Route104_Billy_RegisterMatchCall
	goto Route104_Billy_CheckMatchCall2_1


Route104_Billy_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_BILLY
	release
	end


Route104_Billy_Rematch::
	trainerbattle_rematch TRAINER_BILLY, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


TangeloWoodsRichBoySal::
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_Winston_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq TangeloWoodsRichBoySal_2
TangeloWoodsRichBoySal_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq TangeloWoodsRichBoySal_5
TangeloWoodsRichBoySal_4:
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

TangeloWoodsRichBoySal_2:
	goto Route104_Winston_Rematch
	goto TangeloWoodsRichBoySal_1

TangeloWoodsRichBoySal_5:
	goto Route104_Winston_CheckMatchCall2
	goto TangeloWoodsRichBoySal_4


Route104_Winston_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Winston_CheckMatchCall_2
Route104_Winston_CheckMatchCall_1:
	release
	end

Route104_Winston_CheckMatchCall_2:
	goto Route104_Winston_RegisterShortMatchCall
	goto Route104_Winston_CheckMatchCall_1


Route104_Winston_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end


Route104_Winston_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Winston_CheckMatchCall2_2
Route104_Winston_CheckMatchCall2_1:
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_Winston_CheckMatchCall2_2:
	goto Route104_Winston_RegisterMatchCall
	goto Route104_Winston_CheckMatchCall2_1


Route104_Winston_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end


Route104_Winston_Rematch::
	trainerbattle_rematch TRAINER_WINSTON_1, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


TangeloWoodsBugCatcherJason::
	trainerbattle_single TRAINER_LYLE, TangeloWoods_Text_LyleIntro, TangeloWoods_Text_LyleDefeat, Route104_Lyle_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq TangeloWoodsBugCatcherJason_2
TangeloWoodsBugCatcherJason_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq TangeloWoodsBugCatcherJason_5
TangeloWoodsBugCatcherJason_4:
	msgbox TangeloWoods_Text_LylePostBattle, MSGBOX_DEFAULT
	release
	end

TangeloWoodsBugCatcherJason_2:
	goto Route104_Lyle_Rematch
	goto TangeloWoodsBugCatcherJason_1

TangeloWoodsBugCatcherJason_5:
	goto Route104_Lyle_CheckMatchCall2
	goto TangeloWoodsBugCatcherJason_4


Route104_Lyle_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Lyle_CheckMatchCall_2
Route104_Lyle_CheckMatchCall_1:
	release
	end

Route104_Lyle_CheckMatchCall_2:
	goto Route104_Lyle_RegisterShortMatchCall
	goto Route104_Lyle_CheckMatchCall_1


Route104_Lyle_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_LYLE
	release
	end


Route104_Lyle_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Lyle_CheckMatchCall2_2
Route104_Lyle_CheckMatchCall2_1:
	msgbox TangeloWoods_Text_LylePostBattle, MSGBOX_DEFAULT
	release
	end

Route104_Lyle_CheckMatchCall2_2:
	goto Route104_Lyle_RegisterMatchCall
	goto Route104_Lyle_CheckMatchCall2_1


Route104_Lyle_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_LYLE
	release
	end


Route104_Lyle_Rematch::
	trainerbattle_rematch TRAINER_LYLE, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


TangeloWoodsBugCatcherWilliam::
	trainerbattle_single TRAINER_JAMES_1, TangeloWoods_Text_JamesIntro, TangeloWoods_Text_JamesDefeat, Route104_James_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq TangeloWoodsBugCatcherWilliam_2
TangeloWoodsBugCatcherWilliam_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq TangeloWoodsBugCatcherWilliam_5
TangeloWoodsBugCatcherWilliam_4:
	msgbox TangeloWoods_Text_JamesPostBattle, MSGBOX_DEFAULT
	release
	end

TangeloWoodsBugCatcherWilliam_2:
	goto Route104_James_Rematch
	goto TangeloWoodsBugCatcherWilliam_1

TangeloWoodsBugCatcherWilliam_5:
	goto Route104_James_CheckMatchCall2
	goto TangeloWoodsBugCatcherWilliam_4


Route104_James_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_James_CheckMatchCall_2
Route104_James_CheckMatchCall_1:
	release
	end

Route104_James_CheckMatchCall_2:
	goto Route104_James_RegisterShortMatchCall
	goto Route104_James_CheckMatchCall_1


Route104_James_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end


Route104_James_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_James_CheckMatchCall2_2
Route104_James_CheckMatchCall2_1:
	msgbox TangeloWoods_Text_JamesPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_James_CheckMatchCall2_2:
	goto Route104_James_RegisterMatchCall
	goto Route104_James_CheckMatchCall2_1


Route104_James_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end


Route104_James_Rematch::
	trainerbattle_rematch TRAINER_JAMES_1, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


TangeloWoodsBugCatcherNess::
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat, Route104_Jose_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq TangeloWoodsBugCatcherNess_2
TangeloWoodsBugCatcherNess_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq TangeloWoodsBugCatcherNess_5
TangeloWoodsBugCatcherNess_4:
	msgbox Route116_Text_JosePostBattle, MSGBOX_DEFAULT
	release
	end

TangeloWoodsBugCatcherNess_2:
	goto Route104_Jose_Rematch
	goto TangeloWoodsBugCatcherNess_1

TangeloWoodsBugCatcherNess_5:
	goto Route104_Jose_CheckMatchCall2
	goto TangeloWoodsBugCatcherNess_4


Route104_Jose_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Jose_CheckMatchCall_2
Route104_Jose_CheckMatchCall_1:
	release
	end

Route104_Jose_CheckMatchCall_2:
	goto Route104_Jose_RegisterShortMatchCall
	goto Route104_Jose_CheckMatchCall_1


Route104_Jose_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOSE
	release
	end


Route104_Jose_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Jose_CheckMatchCall2_2
Route104_Jose_CheckMatchCall2_1:
	msgbox Route116_Text_JosePostBattle, MSGBOX_DEFAULT
	release
	end

Route104_Jose_CheckMatchCall2_2:
	goto Route104_Jose_RegisterMatchCall
	goto Route104_Jose_CheckMatchCall2_1


Route104_Jose_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_JOSE
	release
	end


Route104_Jose_Rematch::
	trainerbattle_rematch TRAINER_JOSE, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


TangeloWoodsCora::
	lockall
	setflag FLAG_HIDE_TRACEY_103
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 7
	goto_if_eq TangeloWoodsCora_2
TangeloWoodsCora_1:
	compare VAR_TEMP_1, 8
	goto_if_eq TangeloWoodsCora_5
TangeloWoodsCora_4:
	releaseall
	end

TangeloWoodsCora_2:
	fadenewbgm 0
	setobjectxy 11, 30, 6
	waitse
	playse SE_KAIDAN
	waitse
	applymovement 11, TangeloWoodsCoraMove1
	waitmovement 0
	playbgm MUS_CORA_ENCOUNTER, 1
	msgbox TangeloWoodsCora_Text_0, MSGBOX_DEFAULT
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL, TangeloWoodsCora_8
TangeloWoodsCora_7:
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE, TangeloWoodsCora_14
TangeloWoodsCora_13:
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA, TangeloWoodsCora_19
	goto TangeloWoodsCora_1

TangeloWoodsCora_5:
	fadenewbgm 0
	setobjectxy 11, 30, 6
	waitse
	playse SE_KAIDAN
	waitse
	applymovement 11, TangeloWoodsCoraMove2
	waitmovement 0
	playbgm MUS_CORA_ENCOUNTER, 1
	msgbox TangeloWoodsCora_Text_0, MSGBOX_DEFAULT
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL, TangeloWoodsCora_11
TangeloWoodsCora_10:
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE, TangeloWoodsCora_17
TangeloWoodsCora_16:
	goto_if_set FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA, TangeloWoodsCora_21
	goto TangeloWoodsCora_4

TangeloWoodsCora_8:
	trainerbattle_no_intro TRAINER_BRENDAN_7, TangeloWoodsCoraDefeated
	goto TangeloWoodsCoraAfterBattle
	goto TangeloWoodsCora_7

TangeloWoodsCora_11:
	trainerbattle_no_intro TRAINER_BRENDAN_7, TangeloWoodsCoraDefeated
	goto TangeloWoodsCoraAfterBattle2
	goto TangeloWoodsCora_10

TangeloWoodsCora_14:
	trainerbattle_no_intro TRAINER_BRENDAN_1, TangeloWoodsCoraDefeated
	goto TangeloWoodsCoraAfterBattle
	goto TangeloWoodsCora_13

TangeloWoodsCora_17:
	trainerbattle_no_intro TRAINER_BRENDAN_1, TangeloWoodsCoraDefeated
	goto TangeloWoodsCoraAfterBattle2
	goto TangeloWoodsCora_16

TangeloWoodsCora_19:
	trainerbattle_no_intro TRAINER_BRENDAN_4, TangeloWoodsCoraDefeated
	goto TangeloWoodsCoraAfterBattle
	goto TangeloWoodsCora_1

TangeloWoodsCora_21:
	trainerbattle_no_intro TRAINER_BRENDAN_4, TangeloWoodsCoraDefeated
	goto TangeloWoodsCoraAfterBattle2
	goto TangeloWoodsCora_4


TangeloWoodsCoraAfterBattle::
	msgbox TangeloWoodsCoraAfterBattle_Text_0, MSGBOX_AUTOCLOSE
	release
	applymovement EVENT_OBJ_ID_PLAYER, TangeloWoodsPlayerMove1
	applymovement 11, TangeloWoodsCoraMove3
	waitmovement 11
	removeobject 11
	fadeoutbgm 1
	playbgm MUS_ORANGE_WOODS, 1
	setvar VAR_ROUTE105_STATE, 6
	setflag FLAG_TANGELO_LAPRAS
	releaseall
	end


TangeloWoodsCoraAfterBattle2::
	msgbox TangeloWoodsCoraAfterBattle_Text_0, MSGBOX_AUTOCLOSE
	release
	applymovement EVENT_OBJ_ID_PLAYER, TangeloWoodsPlayerMove2
	applymovement 11, TangeloWoodsCoraMove4
	waitmovement 11
	removeobject 11
	fadeoutbgm 1
	playbgm MUS_ORANGE_WOODS, 1
	setvar VAR_ROUTE105_STATE, 6
	setflag FLAG_TANGELO_LAPRAS
	releaseall
	end


TangeloWoodsCoraMove1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TangeloWoodsCoraMove2:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TangeloWoodsPlayerMove1:
	walk_down
	face_left
	step_end

TangeloWoodsCoraMove3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TangeloWoodsPlayerMove2:
	walk_up
	face_left
	step_end

TangeloWoodsCoraMove4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TangeloWoodsManiac_Text_0:
	.string "Oh, no! I got lost!\nIt's my fault, really…\pI was just trying to catch a SLAKOTH!$"

TangeloWoodsSign1_Text_0:
	.string "TANGELO WOODS\n{UP_ARROW} MIKAN ISLAND$"

TangeloWoodsSign_Text_0:
	.string "TRAINER TIPS\pEvery once in a while, there are\nthings on the ground even if you can't\lsee them.\pAlways check where you're walking by\npressing the A Button.$"

TangeloWoodsHoneyTree_Text_0:
	.string "This tree looks like it can be\nslathered with HONEY!$"

TangeloWoodsCora_Text_0:
	.string "Out of my way, I need to obtain\nsomething really important!\pI can stop at nothing, so I must\nbecome stronger.\p… … … … … … … …\n… … … … … … … …\pYou look like the perfect\npunching bag who might put up a\ldecent fight.\pAllow me to test my skills!$"

TangeloWoodsCoraAfterBattle_Text_0:
	.string "You win this time, but I'll get\nstronger.\pOtherwise, I'll never achieve my goals!$"

TangeloWoods_Text_LyleIntro::
	.string "This place is great!\n"
	.string "You can catch some rare finds!$"

TangeloWoods_Text_LyleDefeat::
	.string "I guess I should focus on strength\n"
	.string "rather than rarity.$"

TangeloWoods_Text_LylePostBattle::
	.string "Y'know, if you don't like BUG POKéMON,\n"
	.string "there are others here, too!$"

TangeloWoods_Text_JamesIntro::
	.string "Yo, yo, yo!\n"
	.string "Check out my BUG POKéMON collection!$"

TangeloWoods_Text_JamesDefeat::
	.string "I never said I could battle…$"

TangeloWoods_Text_JamesPostBattle::
	.string "I'm going to catch every single\n"
	.string "BUG POKéMON out there!$"

TangeloWoodsCoraDefeated::
	.string "That's far from enough…$"
