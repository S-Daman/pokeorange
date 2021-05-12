Route103_MapScripts::
	.byte 0


Route51Sign::
	lock
	msgbox Route51Sign_Text_0, MSGBOX_SIGN
	release
	return


Route51Sign1::
	lock
	msgbox Route51Sign1_Text_0, MSGBOX_SIGN
	release
	return


Route51Sign2::
	lock
	msgbox Route51Sign2_Text_0, MSGBOX_SIGN
	release
	return


Route51TrainerTips::
	lock
	msgbox Route51TrainerTips_Text_0, MSGBOX_SIGN
	release
	return


Tracey51::
	goto_if_set FLAG_BADGE01_GET, Tracey51_2
	release
	end

Tracey51_2:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_ROUTE105_STATE, 7
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 47
	goto_if_eq Tracey51_5
	compare VAR_TEMP_1, 48
	goto_if_eq Tracey51_8
	compare VAR_TEMP_1, 49
	goto_if_eq Tracey51_11
	release
	end

Tracey51_5:
	applymovement 1, Route51_Tracey_Move_1_1
	applymovement EVENT_OBJ_ID_PLAYER, SurprisedToSeeTraceyRoute510
	waitmovement EVENT_OBJ_ID_PLAYER
	waitse
	playse SE_PIN
	waitse
	waitmovement 1
	delay 10
	msgbox Tracey51_Text_0, MSGBOX_DEFAULT
	giveitem_std ITEM_HM03, 1, 0
	msgbox Tracey51_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 4
	applymovement EVENT_OBJ_ID_PLAYER, SurprisedToSeeTraceyRoute51_1
	applymovement 1, Route51_Tracey_Move_2_1
	waitmovement 1
	removeobject 1
	release
	end

Tracey51_8:
	applymovement 1, Route51_Tracey_Move_1_2
	applymovement EVENT_OBJ_ID_PLAYER, SurprisedToSeeTraceyRoute51
	waitmovement EVENT_OBJ_ID_PLAYER
	waitse
	playse SE_PIN
	waitse
	waitmovement 1
	delay 10
	msgbox Tracey51_Text_0, MSGBOX_DEFAULT
	giveitem_std ITEM_HM03, 1, 0
	msgbox Tracey51_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 4
	applymovement EVENT_OBJ_ID_PLAYER, SurprisedToSeeTraceyRoute51_1
	applymovement 1, Route51_Tracey_Move_2_2
	waitmovement 1
	removeobject 1
	release
	end

Tracey51_11:
	applymovement 1, Route51_Tracey_Move_1_3
	applymovement EVENT_OBJ_ID_PLAYER, SurprisedToSeeTraceyRoute51
	waitmovement EVENT_OBJ_ID_PLAYER
	waitse
	playse SE_PIN
	waitse
	waitmovement 1
	delay 10
	msgbox Tracey51_Text_0, MSGBOX_DEFAULT
	giveitem_std ITEM_HM03, 1, 0
	msgbox Tracey51_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 4
	applymovement EVENT_OBJ_ID_PLAYER, SurprisedToSeeTraceyRoute51_2
	applymovement 1, Route51_Tracey_Move_2_3
	waitmovement 1
	removeobject 1
	release
	end


SurprisedToSeeTraceyRoute51:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	emote_exclamation_mark
	step_end

SurprisedToSeeTraceyRoute510:
	delay_16
	delay_16
	delay_16
	emote_exclamation_mark
	step_end

SurprisedToSeeTraceyRoute51_1:
	delay_8
	delay_8
	delay_8
	face_left
	step_end

SurprisedToSeeTraceyRoute51_2:
	delay_8
	delay_8
	delay_8
	face_left
	step_end

Route51_Tracey_Move_1_1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	step_end

Route51_Tracey_Move_1_2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

Route51_Tracey_Move_1_3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route51_Tracey_Move_2_1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route51_Tracey_Move_2_2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route51_Tracey_Move_2_3:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route51YoungsterDuncan::
	trainerbattle_single TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated, Route105_Luis_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route51YoungsterDuncan_2
Route51YoungsterDuncan_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route51YoungsterDuncan_5
Route51YoungsterDuncan_4:
	msgbox Route105_Text_LuisPostBattle, MSGBOX_DEFAULT
	release
	end

Route51YoungsterDuncan_2:
	goto Route105_Luis_Rematch
	goto Route51YoungsterDuncan_1

Route51YoungsterDuncan_5:
	goto Route105_Luis_CheckMatchCall2
	goto Route51YoungsterDuncan_4


Route105_Luis_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route105_Luis_CheckMatchCall_2
Route105_Luis_CheckMatchCall_1:
	release
	end

Route105_Luis_CheckMatchCall_2:
	goto Route105_Luis_RegisterShortMatchCall
	goto Route105_Luis_CheckMatchCall_1


Route105_Luis_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_LUIS
	release
	end


Route105_Luis_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route105_Luis_CheckMatchCall2_2
Route105_Luis_CheckMatchCall2_1:
	msgbox Route105_Text_LuisPostBattle, MSGBOX_DEFAULT
	release
	end

Route105_Luis_CheckMatchCall2_2:
	goto Route105_Luis_RegisterMatchCall
	goto Route105_Luis_CheckMatchCall2_1


Route105_Luis_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_LUIS
	release
	end


Route105_Luis_Rematch::
	trainerbattle_rematch TRAINER_LUIS, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route51YoungsterLola::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated, Route106_Kyla_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route51YoungsterLola_2
Route51YoungsterLola_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route51YoungsterLola_5
Route51YoungsterLola_4:
	msgbox Route106_Text_KylaPostBattle, MSGBOX_DEFAULT
	release
	end

Route51YoungsterLola_2:
	goto Route106_Kyla_Rematch
	goto Route51YoungsterLola_1

Route51YoungsterLola_5:
	goto Route106_Kyla_CheckMatchCall2
	goto Route51YoungsterLola_4


Route106_Kyla_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route106_Kyla_CheckMatchCall_2
Route106_Kyla_CheckMatchCall_1:
	release
	end

Route106_Kyla_CheckMatchCall_2:
	goto Route106_Kyla_RegisterShortMatchCall
	goto Route106_Kyla_CheckMatchCall_1


Route106_Kyla_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLA
	release
	end


Route106_Kyla_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route106_Kyla_CheckMatchCall2_2
Route106_Kyla_CheckMatchCall2_1:
	msgbox Route106_Text_KylaPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_Kyla_CheckMatchCall2_2:
	goto Route106_Kyla_RegisterMatchCall
	goto Route106_Kyla_CheckMatchCall2_1


Route106_Kyla_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_KYLA
	release
	end


Route106_Kyla_Rematch::
	trainerbattle_rematch TRAINER_KYLA, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route51YoungsterSally::
	trainerbattle_single TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated, Route105_Imani_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route51YoungsterSally_2
Route51YoungsterSally_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route51YoungsterSally_5
Route51YoungsterSally_4:
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_DEFAULT
	release
	end

Route51YoungsterSally_2:
	goto Route105_Imani_Rematch
	goto Route51YoungsterSally_1

Route51YoungsterSally_5:
	goto Route105_Imani_CheckMatchCall2
	goto Route51YoungsterSally_4


Route105_Imani_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route105_Imani_CheckMatchCall_2
Route105_Imani_CheckMatchCall_1:
	release
	end

Route105_Imani_CheckMatchCall_2:
	goto Route105_Imani_RegisterShortMatchCall
	goto Route105_Imani_CheckMatchCall_1


Route105_Imani_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_IMANI
	release
	end


Route105_Imani_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route105_Imani_CheckMatchCall2_2
Route105_Imani_CheckMatchCall2_1:
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_DEFAULT
	release
	end

Route105_Imani_CheckMatchCall2_2:
	goto Route105_Imani_RegisterMatchCall
	goto Route105_Imani_CheckMatchCall2_1


Route105_Imani_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_IMANI
	release
	end


Route105_Imani_Rematch::
	trainerbattle_rematch TRAINER_IMANI, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route51YoungsterFranklin::
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated, Route105_Dominik_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route51YoungsterFranklin_2
Route51YoungsterFranklin_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route51YoungsterFranklin_5
Route51YoungsterFranklin_4:
	msgbox Route105_Text_DominikPostBattle, MSGBOX_DEFAULT
	release
	end

Route51YoungsterFranklin_2:
	goto Route105_Dominik_Rematch
	goto Route51YoungsterFranklin_1

Route51YoungsterFranklin_5:
	goto Route105_Dominik_CheckMatchCall2
	goto Route51YoungsterFranklin_4


Route105_Dominik_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route105_Dominik_CheckMatchCall_2
Route105_Dominik_CheckMatchCall_1:
	release
	end

Route105_Dominik_CheckMatchCall_2:
	goto Route105_Dominik_RegisterShortMatchCall
	goto Route105_Dominik_CheckMatchCall_1


Route105_Dominik_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_DOMINIK
	release
	end


Route105_Dominik_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route105_Dominik_CheckMatchCall2_2
Route105_Dominik_CheckMatchCall2_1:
	msgbox Route105_Text_DominikPostBattle, MSGBOX_DEFAULT
	release
	end

Route105_Dominik_CheckMatchCall2_2:
	goto Route105_Dominik_RegisterMatchCall
	goto Route105_Dominik_CheckMatchCall2_1


Route105_Dominik_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_DOMINIK
	release
	end


Route105_Dominik_Rematch::
	trainerbattle_rematch TRAINER_DOMINIK, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route51YoungsterEmily::
	trainerbattle_single TRAINER_JANICE, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat, Route116_Janice_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route51YoungsterEmily_2
Route51YoungsterEmily_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route51YoungsterEmily_5
Route51YoungsterEmily_4:
	msgbox Route116_Text_JanicePostBattle, MSGBOX_DEFAULT
	release
	end

Route51YoungsterEmily_2:
	goto Route116_Janice_Rematch
	goto Route51YoungsterEmily_1

Route51YoungsterEmily_5:
	goto Route116_Janice_CheckMatchCall2
	goto Route51YoungsterEmily_4


Route116_Janice_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_Janice_CheckMatchCall_2
Route116_Janice_CheckMatchCall_1:
	release
	end

Route116_Janice_CheckMatchCall_2:
	goto Route116_Janice_RegisterShortMatchCall
	goto Route116_Janice_CheckMatchCall_1


Route116_Janice_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_JANICE
	release
	end


Route116_Janice_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_Janice_CheckMatchCall2_2
Route116_Janice_CheckMatchCall2_1:
	msgbox Route116_Text_JanicePostBattle, MSGBOX_DEFAULT
	release
	end

Route116_Janice_CheckMatchCall2_2:
	goto Route116_Janice_RegisterMatchCall
	goto Route116_Janice_CheckMatchCall2_1


Route116_Janice_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_JANICE
	release
	end


Route116_Janice_Rematch::
	trainerbattle_rematch TRAINER_JANICE, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route51YoungsterAndrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated, Route103_Andrew_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route51YoungsterAndrew_2
Route51YoungsterAndrew_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route51YoungsterAndrew_5
Route51YoungsterAndrew_4:
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_DEFAULT
	release
	end

Route51YoungsterAndrew_2:
	goto Route103_Andrew_Rematch
	goto Route51YoungsterAndrew_1

Route51YoungsterAndrew_5:
	goto Route103_Andrew_CheckMatchCall2
	goto Route51YoungsterAndrew_4


Route103_Andrew_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route103_Andrew_CheckMatchCall_2
Route103_Andrew_CheckMatchCall_1:
	release
	end

Route103_Andrew_CheckMatchCall_2:
	goto Route103_Andrew_RegisterShortMatchCall
	goto Route103_Andrew_CheckMatchCall_1


Route103_Andrew_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANDREW
	release
	end


Route103_Andrew_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route103_Andrew_CheckMatchCall2_2
Route103_Andrew_CheckMatchCall2_1:
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_DEFAULT
	release
	end

Route103_Andrew_CheckMatchCall2_2:
	goto Route103_Andrew_RegisterMatchCall
	goto Route103_Andrew_CheckMatchCall2_1


Route103_Andrew_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANDREW
	release
	end


Route103_Andrew_Rematch::
	trainerbattle_rematch TRAINER_ANDREW, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route51Sign_Text_0:
	.string "ROUTE 51\n{LEFT_ARROW} MIKAN ISLAND$"

Route51Sign1_Text_0:
	.string "ROUTE 51\n{UP_ARROW} MANDARIN ISLAND NORTH$"

Route51Sign2_Text_0:
	.string "ROUTE 51\n{DOWN_ARROW} SUNBURST ISLAND$"

Route51TrainerTips_Text_0:
	.string "TRAINER TIPS\pNo stealing other people's POKéMON!\pPOKé BALLS are meant to be thrown\nonly at wild POKéMON!$"

Tracey51_Text_0:
	.string "Oh, {PLAYER}!\pHave you been taking good care of\nthat LAPRAS?\pOh, the GYM BADGE you have there shows\nyou are doing a good job training it.\pI just remembered!\pI wanted you to have this.$"

Tracey51_Text_1:
	.string "It was stuck to LAPRAS' body, so\nI took it off since it was injured.\pIt looks like a HIDDEN MACHINE, but\nI am not sure which move it contains.\pHM moves are unique moves that can be\nused by POKéMON outside of battle.\pI hope it contains SURF because you\nreally need it to traverse around\lthese seas.\p… … … … … … … …\n… … … … … … … …\pSee you around, {PLAYER}!$"
