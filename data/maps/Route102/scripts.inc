Route102_MapScripts::
	.byte 0


Route50OldaleSign::
	lock
	msgbox Route50OldaleSign_Text_0, MSGBOX_SIGN
	release
	return


Route50TangeloWoodsSign::
	lock
	msgbox Route50TangeloWoodsSign_Text_0, MSGBOX_SIGN
	release
	return


Route50TrainerTips::
	lock
	msgbox Route50TrainerTips_Text_0, MSGBOX_SIGN
	release
	return


Route50Lass::
	lock
	faceplayer
	msgbox Route50Lass_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Route50GreenBoy::
	lock
	faceplayer
	msgbox Route50GreenBoy_Text_0, MSGBOX_AUTOCLOSE
	release
	return


Route50YoungsterLuis::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_Calvin_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route50YoungsterLuis_2
Route50YoungsterLuis_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route50YoungsterLuis_5
Route50YoungsterLuis_4:
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route50YoungsterLuis_2:
	goto Route102_Calvin_Rematch
	goto Route50YoungsterLuis_1

Route50YoungsterLuis_5:
	goto Route102_Calvin_CheckMatchCall2
	goto Route50YoungsterLuis_4


Route102_Calvin_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_Calvin_CheckMatchCall_2
Route102_Calvin_CheckMatchCall_1:
	release
	end

Route102_Calvin_CheckMatchCall_2:
	goto Route102_Calvin_RegisterShortMatchCall
	goto Route102_Calvin_CheckMatchCall_1


Route102_Calvin_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end


Route102_Calvin_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_Calvin_CheckMatchCall2_2
Route102_Calvin_CheckMatchCall2_1:
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_Calvin_CheckMatchCall2_2:
	goto Route102_Calvin_RegisterMatchCall
	goto Route102_Calvin_CheckMatchCall2_1


Route102_Calvin_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end


Route102_Calvin_Rematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route50BugCatcherTony::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated, Route102_Rick_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route50BugCatcherTony_2
Route50BugCatcherTony_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route50BugCatcherTony_5
Route50BugCatcherTony_4:
	msgbox Route102_Text_RickPostBattle, MSGBOX_DEFAULT
	release
	end

Route50BugCatcherTony_2:
	goto Route102_Rick_Rematch
	goto Route50BugCatcherTony_1

Route50BugCatcherTony_5:
	goto Route102_Rick_CheckMatchCall2
	goto Route50BugCatcherTony_4


Route102_Rick_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_Rick_CheckMatchCall_2
Route102_Rick_CheckMatchCall_1:
	release
	end

Route102_Rick_CheckMatchCall_2:
	goto Route102_Rick_RegisterShortMatchCall
	goto Route102_Rick_CheckMatchCall_1


Route102_Rick_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end


Route102_Rick_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_Rick_CheckMatchCall2_2
Route102_Rick_CheckMatchCall2_1:
	msgbox Route102_Text_RickPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_Rick_CheckMatchCall2_2:
	goto Route102_Rick_RegisterMatchCall
	goto Route102_Rick_CheckMatchCall2_1


Route102_Rick_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICK
	release
	end


Route102_Rick_Rematch::
	trainerbattle_rematch TRAINER_RICK, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route50YoungsterJoey::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated, Route102_Allen_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route50YoungsterJoey_2
Route50YoungsterJoey_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route50YoungsterJoey_5
Route50YoungsterJoey_4:
	msgbox Route102_Text_AllenPostBattle, MSGBOX_DEFAULT
	release
	end

Route50YoungsterJoey_2:
	goto Route102_Allen_Rematch
	goto Route50YoungsterJoey_1

Route50YoungsterJoey_5:
	goto Route102_Allen_CheckMatchCall2
	goto Route50YoungsterJoey_4


Route102_Allen_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_Allen_CheckMatchCall_2
Route102_Allen_CheckMatchCall_1:
	release
	end

Route102_Allen_CheckMatchCall_2:
	goto Route102_Allen_RegisterShortMatchCall
	goto Route102_Allen_CheckMatchCall_1


Route102_Allen_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALLEN
	release
	end


Route102_Allen_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_Allen_CheckMatchCall2_2
Route102_Allen_CheckMatchCall2_1:
	msgbox Route102_Text_AllenPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_Allen_CheckMatchCall2_2:
	goto Route102_Allen_RegisteMatchCall
	goto Route102_Allen_CheckMatchCall2_1


Route102_Allen_RegisteMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALLEN
	release
	end


Route102_Allen_Rematch::
	trainerbattle_rematch TRAINER_ALLEN, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route50LassAmanda::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated, Route102_Tiana_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route50LassAmanda_2
Route50LassAmanda_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route50LassAmanda_5
Route50LassAmanda_4:
	msgbox Route102_Text_TianaPostBattle, MSGBOX_DEFAULT
	release
	end

Route50LassAmanda_2:
	goto Route102_Tiana_Rematch
	goto Route50LassAmanda_1

Route50LassAmanda_5:
	goto Route102_Tiana_CheckMatchCall2
	goto Route50LassAmanda_4


Route102_Tiana_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_Tiana_CheckMatchCall_2
Route102_Tiana_CheckMatchCall_1:
	release
	end

Route102_Tiana_CheckMatchCall_2:
	goto Route102_Tiana_RegisterShortMatchCall
	goto Route102_Tiana_CheckMatchCall_1


Route102_Tiana_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIANA
	release
	end


Route102_Tiana_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_Tiana_CheckMatchCall2_2
Route102_Tiana_CheckMatchCall2_1:
	msgbox Route102_Text_TianaPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_Tiana_CheckMatchCall2_2:
	goto Route102_Tiana_RegisteMatchCall
	goto Route102_Tiana_CheckMatchCall2_1


Route102_Tiana_RegisteMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIANA
	release
	end


Route102_Tiana_Rematch::
	trainerbattle_rematch TRAINER_TIANA, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route50LadyCindy::
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Route104_Cindy_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route50LadyCindy_2
Route50LadyCindy_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route50LadyCindy_5
Route50LadyCindy_4:
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
	release
	end

Route50LadyCindy_2:
	goto Route104_Cindy_Rematch
	goto Route50LadyCindy_1

Route50LadyCindy_5:
	goto Route104_Cindy_CheckMatchCall2
	goto Route50LadyCindy_4


Route104_Cindy_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Cindy_CheckMatchCall_2
Route104_Cindy_CheckMatchCall_1:
	release
	end

Route104_Cindy_CheckMatchCall_2:
	goto Route104_Cindy_RegisterShortMatchCall
	goto Route104_Cindy_CheckMatchCall_1


Route104_Cindy_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end


Route104_Cindy_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_Cindy_CheckMatchCall2_2
Route104_Cindy_CheckMatchCall2_1:
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_Cindy_CheckMatchCall2_2:
	goto Route104_Cindy_RegisteMatchCall
	goto Route104_Cindy_CheckMatchCall2_1


Route104_Cindy_RegisteMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end


Route104_Cindy_Rematch::
	trainerbattle_rematch TRAINER_CINDY_1, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route50SwimmerCarl::
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat, Route124_Declan_CheckMatchCall
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route50SwimmerCarl_2
Route50SwimmerCarl_1:
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route50SwimmerCarl_5
Route50SwimmerCarl_4:
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_DEFAULT
	release
	end

Route50SwimmerCarl_2:
	goto Route124_Declan_Rematch
	goto Route50SwimmerCarl_1

Route50SwimmerCarl_5:
	goto Route124_Declan_CheckMatchCall2
	goto Route50SwimmerCarl_4


Route124_Declan_CheckMatchCall::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route124_Declan_CheckMatchCall_2
Route124_Declan_CheckMatchCall_1:
	release
	end

Route124_Declan_CheckMatchCall_2:
	goto Route124_Declan_RegisterShortMatchCall
	goto Route124_Declan_CheckMatchCall_1


Route124_Declan_RegisterShortMatchCall::
	msgbox Text_RegisterShortFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_DECLAN
	release
	end


Route124_Declan_CheckMatchCall2::
	goto_if_set FLAG_HAS_MATCH_CALL, Route124_Declan_CheckMatchCall2_2
Route124_Declan_CheckMatchCall2_1:
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_Declan_CheckMatchCall2_2:
	goto Route124_Declan_RegisterMatchCall
	goto Route124_Declan_CheckMatchCall2_1


Route124_Declan_RegisterMatchCall::
	msgbox Text_RegisterFiller, MSGBOX_DEFAULT
	register_matchcall TRAINER_DECLAN
	release
	end


Route124_Declan_Rematch::
	trainerbattle_rematch TRAINER_DECLAN, Text_RematchIntroFiller, Text_RematchDefeatedFiller
	msgbox Text_RematchDefeatedFillerPostBattle, MSGBOX_AUTOCLOSE
	end


Route50OldaleSign_Text_0:
	.string "ROUTE 50\n{DOWN_ARROW} TANGELO ISLAND$"

Route50TangeloWoodsSign_Text_0:
	.string "ROUTE 50\n{UP_ARROW} TANGELO WOODS$"

Route50TrainerTips_Text_0:
	.string "TRAINER TIPS\pIn battle, apart from HP, POKéMON\nalso have Power Points (PP) that are\lused to carry out moves.\pWhen out of PP, a POKéMON will just\nstruggle and hurt itself, so keep\lit out of battle.$"

Route50Lass_Text_0:
	.string "Well, I'm not a TRAINER, but if a\nTRAINER's eyes meet with yours,\lprepare to battle.$"

Route50GreenBoy_Text_0:
	.string "TANGELO WOODS is pretty hard to\nget through.\pIt is full of strong TRAINERS and\npesky POKéMON.$"
