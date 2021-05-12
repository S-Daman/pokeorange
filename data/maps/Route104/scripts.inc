Route104_MapScripts::
	.byte 0


Route52Sign::
	lock
	msgbox Route52Sign_Text_0, MSGBOX_SIGN
	release
	return


Whirlpool52::
	msgbox Whirlpool52_Text_0, MSGBOX_SIGN
	release
	return


Route52BlackBeltRyohei::
	trainerbattle_single TRAINER_KOJI_1, Route127_Text_KojiIntro, Route127_Text_KojiDefeat, Route127_Koji_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route52BlackBeltRyohei_2
Route52BlackBeltRyohei_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route52BlackBeltRyohei_5
Route52BlackBeltRyohei_4:
	msgbox Route127_Text_KojiPostBattle, MSGBOX_DEFAULT
	release
	end

Route52BlackBeltRyohei_2:
	goto Route127_Koji_Rematch
	goto Route52BlackBeltRyohei_1

Route52BlackBeltRyohei_5:
	goto Route127_Koji_CheckMatchCall2
	goto Route52BlackBeltRyohei_4


Route127_Koji_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route127_Koji_CheckMatchCall_2
Route127_Koji_CheckMatchCall_1:
	release
	end

Route127_Koji_CheckMatchCall_2:
	goto Route127_Koji_RegisterShortMatchCall
	goto Route127_Koji_CheckMatchCall_1


Route127_Koji_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_KOJI_1
	release
	end


Route127_Koji_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route127_Koji_CheckMatchCall2_2
Route127_Koji_CheckMatchCall2_1:
	msgbox Route127_Text_KojiPostBattle, MSGBOX_DEFAULT
	release
	end

Route127_Koji_CheckMatchCall2_2:
	goto Route127_Koji_RegisterMatchCall
	goto Route127_Koji_CheckMatchCall2_1


Route127_Koji_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_KOJI_1
	release
	end


Route127_Koji_Rematch::
	trainerbattle_rematch TRAINER_KOJI_1, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route52SwimmerEllie::
	trainerbattle_single TRAINER_CARLEE, Route128_Text_CarleeIntro, Route128_Text_CarleeDefeat, Route128_Carlee_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route52SwimmerEllie_2
Route52SwimmerEllie_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route52SwimmerEllie_5
Route52SwimmerEllie_4:
	msgbox Route128_Text_CarleePostBattle, MSGBOX_DEFAULT
	release
	end

Route52SwimmerEllie_2:
	goto Route128_Carlee_Rematch
	goto Route52SwimmerEllie_1

Route52SwimmerEllie_5:
	goto Route128_Carlee_CheckMatchCall2
	goto Route52SwimmerEllie_4


Route128_Carlee_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route128_Carlee_CheckMatchCall_2
Route128_Carlee_CheckMatchCall_1:
	release
	end

Route128_Carlee_CheckMatchCall_2:
	goto Route128_Carlee_RegisterShortMatchCall
	goto Route128_Carlee_CheckMatchCall_1


Route128_Carlee_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CARLEE
	release
	end


Route128_Carlee_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route128_Carlee_CheckMatchCall2_2
Route128_Carlee_CheckMatchCall2_1:
	msgbox Route128_Text_CarleePostBattle, MSGBOX_DEFAULT
	release
	end

Route128_Carlee_CheckMatchCall2_2:
	goto Route128_Carlee_RegisterMatchCall
	goto Route128_Carlee_CheckMatchCall2_1


Route128_Carlee_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CARLEE
	release
	end


Route128_Carlee_Rematch::
	trainerbattle_rematch TRAINER_CARLEE, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route52SwimmerJerry::
	trainerbattle_single TRAINER_RICHARD, Route131_Text_RichardIntro, Route131_Text_RichardDefeat, Route131_Richard_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route52SwimmerJerry_2
Route52SwimmerJerry_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route52SwimmerJerry_5
Route52SwimmerJerry_4:
	msgbox Route131_Text_RichardPostBattle, MSGBOX_DEFAULT
	release
	end

Route52SwimmerJerry_2:
	goto Route131_Richard_Rematch
	goto Route52SwimmerJerry_1

Route52SwimmerJerry_5:
	goto Route131_Richard_CheckMatchCall2
	goto Route52SwimmerJerry_4


Route131_Richard_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route131_Richard_CheckMatchCall_2
Route131_Richard_CheckMatchCall_1:
	release
	end

Route131_Richard_CheckMatchCall_2:
	goto Route131_Richard_RegisterShortMatchCall
	goto Route131_Richard_CheckMatchCall_1


Route131_Richard_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICHARD
	release
	end


Route131_Richard_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route131_Richard_CheckMatchCall2_2
Route131_Richard_CheckMatchCall2_1:
	msgbox Route131_Text_RichardPostBattle, MSGBOX_DEFAULT
	release
	end

Route131_Richard_CheckMatchCall2_2:
	goto Route131_Richard_RegisterMatchCall
	goto Route131_Richard_CheckMatchCall2_1


Route131_Richard_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICHARD
	release
	end


Route131_Richard_Rematch::
	trainerbattle_rematch TRAINER_RICHARD, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route52Sign_Text_0:
	.string "ROUTE 52\n{RIGHT_ARROW} PINKAN ISLAND$"

Whirlpool52_Text_0:
	.string "It's a ferocious whirlpool!\nA POKéMON may be able to pass it.$"
