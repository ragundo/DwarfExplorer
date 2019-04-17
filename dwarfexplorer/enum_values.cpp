#include <cstdint>
#include <DataDefs.h>
#include <Core.h>
#include <Console.h>
#include <Export.h>
#include <PluginManager.h>
#include <RemoteServer.h>
#include <RemoteClient.h>
#include <VersionInfo.h>
#include "df_all.h"
#include "DF_Types.h"
#include "node.h"


using namespace rdf;


std::string get_ui_advmode_menu_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::ui_advmode_menu::ui_advmode_menu*>(p_address);
	switch (*m_value)
	{
		case 0: return "Default";
		case 1: return "Look";
		case 2: return "ConversationAddress";
		case 3: return "ConversationSelect";
		case 4: return "ConversationSpeak";
		case 5: return "Inventory";
		case 6: return "Drop";
		case 7: return "ThrowItem";
		case 8: return "Wear";
		case 9: return "Remove";
		case 10: return "Interact";
		case 11: return "Put";
		case 12: return "PutContainer";
		case 13: return "Eat";
		case 14: return "ThrowAim";
		case 15: return "Fire";
		case 16: return "Get";
		case 17: return "Unk17";
		case 18: return "CombatPrefs";
		case 19: return "Companions";
		case 20: return "MovementPrefs";
		case 21: return "SpeedPrefs";
		case 22: return "InteractAction";
		case 23: return "MoveCarefully";
		case 24: return "Announcements";
		case 25: return "UseBuilding";
		case 26: return "Travel";
		case 27: return "Unk27";
		case 28: return "Unk28";
		case 29: return "SleepConfirm";
		case 30: return "SelectInteractionTarget";
		case 31: return "Unk31";
		case 32: return "Unk32";
		case 33: return "FallAction";
		case 34: return "ViewTracks";
		case 35: return "Jump";
		case 36: return "Unk36";
		case 37: return "AttackConfirm";
		case 38: return "AttackType";
		case 39: return "AttackBodypart";
		case 40: return "AttackStrike";
		case 41: return "Unk41";
		case 42: return "Unk42";
		case 43: return "DodgeDirection";
		case 44: return "Unk44";
		case 45: return "Unk45";
		case 46: return "Build";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_talk_choice_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::talk_choice_type::talk_choice_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Greet";
		case 1: return "Nevermind";
		case 2: return "Trade";
		case 3: return "AskJoin";
		case 4: return "AskSurroundings";
		case 5: return "SayGoodbye";
		case 6: return "AskStructure";
		case 7: return "AskFamily";
		case 8: return "AskProfession";
		case 9: return "AskPermissionSleep";
		case 10: return "AccuseNightCreature";
		case 11: return "AskTroubles";
		case 12: return "BringUpEvent";
		case 13: return "SpreadRumor";
		case 14: return "ReplyGreeting";
		case 15: return "RefuseConversation";
		case 16: return "ReplyImpersonate";
		case 17: return "BringUpIncident";
		case 18: return "TellNothingChanged";
		case 19: return "Goodbye2";
		case 20: return "ReturnTopic";
		case 21: return "ChangeSubject";
		case 22: return "AskTargetAction";
		case 23: return "RequestSuggestAction";
		case 24: return "AskJoinInsurrection";
		case 25: return "AskJoinRescue";
		case 26: return "StateOpinion";
		case 27: return "RespondJoinInsurrection";
		case 28: return "anon_1";
		case 29: return "AllowPermissionSleep";
		case 30: return "DenyPermissionSleep";
		case 31: return "anon_2";
		case 32: return "AskJoinAdventure";
		case 33: return "AskGuideLocation";
		case 34: return "RespondJoin";
		case 35: return "RespondJoin2";
		case 36: return "OfferCondolences";
		case 37: return "StateNotAcquainted";
		case 38: return "SuggestTravel";
		case 39: return "SuggestTalk";
		case 40: return "RequestSelfRescue";
		case 41: return "AskWhatHappened";
		case 42: return "AskBeRescued";
		case 43: return "SayNotRemember";
		case 44: return "anon_3";
		case 45: return "SayNoFamily";
		case 46: return "StateUnitLocation";
		case 47: return "ReferToElder";
		case 48: return "AskComeCloser";
		case 49: return "DoBusiness";
		case 50: return "AskComeStoreLater";
		case 51: return "AskComeMarketLater";
		case 52: return "TellTryShopkeeper";
		case 53: return "DescribeSurroundings";
		case 54: return "AskWaitUntilHome";
		case 55: return "DescribeFamily";
		case 56: return "StateAge";
		case 57: return "DescribeProfession";
		case 58: return "AnnounceNightCreature";
		case 59: return "StateIncredulity";
		case 60: return "BypassGreeting";
		case 61: return "AskCeaseHostilities";
		case 62: return "DemandYield";
		case 63: return "HawkWares";
		case 64: return "YieldTerror";
		case 65: return "Yield";
		case 66: return "ExpressOverwhelmingEmotion";
		case 67: return "ExpressGreatEmotion";
		case 68: return "ExpressEmotion";
		case 69: return "ExpressMinorEmotion";
		case 70: return "ExpressLackEmotion";
		case 71: return "OutburstFleeConflict";
		case 72: return "StateFleeConflict";
		case 73: return "MentionJourney";
		case 74: return "SummarizeTroubles";
		case 75: return "AskAboutIncident";
		case 76: return "AskDirectionsPerson";
		case 77: return "AskDirectionsPlace";
		case 78: return "AskWhereabouts";
		case 79: return "RequestGuide";
		case 80: return "RequestGuide2";
		case 81: return "ProvideDirections";
		case 82: return "ProvideWhereabouts";
		case 83: return "TellTargetSelf";
		case 84: return "TellTargetDead";
		case 85: return "RecommendGuide";
		case 86: return "ProfessIgnorance";
		case 87: return "TellAboutPlace";
		case 88: return "AskFavorMenu";
		case 89: return "AskWait";
		case 90: return "AskFollow";
		case 91: return "ApologizeBusy";
		case 92: return "ComplyOrder";
		case 93: return "AgreeFollow";
		case 94: return "ExchangeItems";
		case 95: return "AskComeCloser2";
		case 96: return "InitiateBarter";
		case 97: return "AgreeCeaseHostile";
		case 98: return "RefuseCeaseHostile";
		case 99: return "RefuseCeaseHostile2";
		case 100: return "RefuseYield";
		case 101: return "RefuseYield2";
		case 102: return "Brag";
		case 103: return "DescribeRelation";
		case 104: return "ClaimSite";
		case 105: return "AnnounceLairHunt";
		case 106: return "RequestDuty";
		case 107: return "AskJoinService";
		case 108: return "AcceptService";
		case 109: return "TellRemainVigilant";
		case 110: return "GiveServiceOrder";
		case 111: return "WelcomeSelfHome";
		case 112: return "anon_4";
		case 113: return "AskTravelReason";
		case 114: return "TellTravelReason";
		case 115: return "AskLocalRuler";
		case 116: return "ComplainAgreement";
		case 117: return "CancelAgreement";
		case 118: return "SummarizeConflict";
		case 119: return "SummarizeViews";
		case 120: return "AskClaimStrength";
		case 121: return "AskArmyPosition";
		case 122: return "AskOtherClaims";
		case 123: return "AskDeserters";
		case 124: return "AskSiteNeighbors";
		case 125: return "DescribeSiteNeighbors";
		case 126: return "RaiseAlarm";
		case 127: return "DemandDropWeapon";
		case 128: return "AgreeComplyDemand";
		case 129: return "RefuseComplyDemand";
		case 130: return "AskLocationObject";
		case 131: return "DemandTribute";
		case 132: return "AgreeGiveTribute";
		case 133: return "RefuseGiveTribute";
		case 134: return "OfferGiveTribute";
		case 135: return "AgreeAcceptTribute";
		case 136: return "RefuseAcceptTribute";
		case 137: return "CancelTribute";
		case 138: return "OfferPeace";
		case 139: return "AgreePeace";
		case 140: return "RefusePeace";
		case 141: return "AskTradeDepotLater";
		case 142: return "ExpressAstonishment";
		case 143: return "CommentWeather";
		case 144: return "CommentNature";
		case 145: return "SummarizeTerritory";
		case 146: return "SummarizePatrols";
		case 147: return "SummarizeOpposition";
		case 148: return "DescribeRefugees";
		case 149: return "AccuseTroublemaker";
		case 150: return "AskAdopt";
		case 151: return "AgreeAdopt";
		case 152: return "RefuseAdopt";
		case 153: return "RevokeService";
		case 154: return "InviteService";
		case 155: return "AcceptInviteService";
		case 156: return "RefuseShareInformation";
		case 157: return "RefuseInviteService";
		case 158: return "RefuseRequestService";
		case 159: return "OfferService";
		case 160: return "AcceptPositionService";
		case 161: return "RefusePositionService";
		case 162: return "InvokeNameBanish";
		case 163: return "InvokeNameService";
		case 164: return "GrovelMaster";
		case 165: return "DemandItem";
		case 166: return "GiveServiceReport";
		case 167: return "OfferEncouragement";
		case 168: return "PraiseTaskCompleter";
		case 169: return "AskAboutPersonMenu";
		case 170: return "AskAboutPerson";
		case 171: return "TellAboutPerson";
		case 172: return "AskFeelings";
		case 173: return "TellThoughts";
		case 174: return "AskServices";
		case 175: return "TellServices";
		case 176: return "OrderDrink";
		case 177: return "RentRoom";
		case 178: return "ExtendRoomRental";
		case 179: return "ConfirmServiceOrder";
		case 180: return "AskJoinEntertain";
		case 181: return "RespondJoinEntertain";
		case 182: return "AskJoinTroupe";
		case 183: return "anon_5";
		case 184: return "RefuseTroupeApplication";
		case 185: return "InviteJoinTroupe";
		case 186: return "AcceptTroupeInvitation";
		case 187: return "RefuseTroupeInvitation";
		case 188: return "KickOutOfTroupe";
		case 189: return "CreateTroupe";
		case 190: return "LeaveTroupe";
		case 191: return "YellServiceOrder";
		case 192: return "TellBePatientForService";
		case 193: return "TellNoServices";
		case 194: return "AskWaitUntilThere";
		case 195: return "DenyWorkingHere";
		case 196: return "ExpressEmotionMenu";
		case 197: return "StateValueMenu";
		case 198: return "StateValue";
		case 199: return "SayNoOrderYet";
		case 200: return "ProvideDirectionsBuilding";
		case 201: return "Argue";
		case 202: return "Flatter";
		case 203: return "DismissArgument";
		case 204: return "RespondPassively";
		case 205: return "Acquiesce";
		case 206: return "DerideFlattery";
		case 207: return "ExpressOutrageAtDismissal";
		case 208: return "PressArgument";
		case 209: return "DropArgument";
		case 210: return "AskWork";
		case 211: return "AskWorkGroup";
		case 212: return "GrantWork";
		case 213: return "RefuseWork";
		case 214: return "GrantWorkGroup";
		case 215: return "RefuseWorkGroup";
		case 216: return "GiveSquadOrder";
		case 217: return "Artifact";
		case 218: return "PraiseReturn";
		case 219: return "ProvideLocation";
		case 220: return "Prophesize";
		case 221: return "TalkAboutAncestor";
		case 222: return "SuggestTrade";
		case 223: return "AcceptNotTrade";
		case 224: return "DemandIdentity";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_announcement_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::announcement_type::announcement_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "REACHED_PEAK";
		case 1: return "ERA_CHANGE";
		case 2: return "FEATURE_DISCOVERY";
		case 3: return "STRUCK_DEEP_METAL";
		case 4: return "STRUCK_MINERAL";
		case 5: return "STRUCK_ECONOMIC_MINERAL";
		case 6: return "COMBAT_TWIST_WEAPON";
		case 7: return "COMBAT_LET_ITEM_DROP";
		case 8: return "COMBAT_START_CHARGE";
		case 9: return "COMBAT_SURPRISE_CHARGE";
		case 10: return "COMBAT_JUMP_DODGE_PROJ";
		case 11: return "COMBAT_JUMP_DODGE_STRIKE";
		case 12: return "COMBAT_DODGE";
		case 13: return "COMBAT_COUNTERSTRIKE";
		case 14: return "COMBAT_BLOCK";
		case 15: return "COMBAT_PARRY";
		case 16: return "COMBAT_CHARGE_COLLISION";
		case 17: return "COMBAT_CHARGE_DEFENDER_TUMBLES";
		case 18: return "COMBAT_CHARGE_DEFENDER_KNOCKED_OVER";
		case 19: return "COMBAT_CHARGE_ATTACKER_TUMBLES";
		case 20: return "COMBAT_CHARGE_ATTACKER_BOUNCE_BACK";
		case 21: return "COMBAT_CHARGE_TANGLE_TOGETHER";
		case 22: return "COMBAT_CHARGE_TANGLE_TUMBLE";
		case 23: return "COMBAT_CHARGE_RUSH_BY";
		case 24: return "COMBAT_CHARGE_MANAGE_STOP";
		case 25: return "COMBAT_CHARGE_OBSTACLE_SLAM";
		case 26: return "COMBAT_WRESTLE_LOCK";
		case 27: return "COMBAT_WRESTLE_CHOKEHOLD";
		case 28: return "COMBAT_WRESTLE_TAKEDOWN";
		case 29: return "COMBAT_WRESTLE_THROW";
		case 30: return "COMBAT_WRESTLE_RELEASE_LOCK";
		case 31: return "COMBAT_WRESTLE_RELEASE_CHOKE";
		case 32: return "COMBAT_WRESTLE_RELEASE_GRIP";
		case 33: return "COMBAT_WRESTLE_STRUGGLE";
		case 34: return "COMBAT_WRESTLE_RELEASE_LATCH";
		case 35: return "COMBAT_WRESTLE_STRANGLE_KO";
		case 36: return "COMBAT_WRESTLE_ADJUST_GRIP";
		case 37: return "COMBAT_GRAB_TEAR";
		case 38: return "COMBAT_STRIKE_DETAILS";
		case 39: return "COMBAT_STRIKE_DETAILS_2";
		case 40: return "COMBAT_EVENT_ENRAGED";
		case 41: return "COMBAT_EVENT_STUCKIN";
		case 42: return "COMBAT_EVENT_LATCH_BP";
		case 43: return "COMBAT_EVENT_LATCH_GENERAL";
		case 44: return "COMBAT_EVENT_PROPELLED_AWAY";
		case 45: return "COMBAT_EVENT_KNOCKED_OUT";
		case 46: return "COMBAT_EVENT_STUNNED";
		case 47: return "COMBAT_EVENT_WINDED";
		case 48: return "COMBAT_EVENT_NAUSEATED";
		case 49: return "MIGRANT_ARRIVAL_NAMED";
		case 50: return "MIGRANT_ARRIVAL";
		case 51: return "DIG_CANCEL_WARM";
		case 52: return "DIG_CANCEL_DAMP";
		case 53: return "AMBUSH_DEFENDER";
		case 54: return "AMBUSH_RESIDENT";
		case 55: return "AMBUSH_THIEF";
		case 56: return "AMBUSH_THIEF_SUPPORT_SKULKING";
		case 57: return "AMBUSH_THIEF_SUPPORT_NATURE";
		case 58: return "AMBUSH_THIEF_SUPPORT";
		case 59: return "AMBUSH_MISCHIEVOUS";
		case 60: return "AMBUSH_SNATCHER";
		case 61: return "AMBUSH_SNATCHER_SUPPORT";
		case 62: return "AMBUSH_AMBUSHER_NATURE";
		case 63: return "AMBUSH_AMBUSHER";
		case 64: return "AMBUSH_INJURED";
		case 65: return "AMBUSH_OTHER";
		case 66: return "AMBUSH_INCAPACITATED";
		case 67: return "CARAVAN_ARRIVAL";
		case 68: return "NOBLE_ARRIVAL";
		case 69: return "D_MIGRANTS_ARRIVAL";
		case 70: return "D_MIGRANT_ARRIVAL";
		case 71: return "D_MIGRANT_ARRIVAL_DISCOURAGED";
		case 72: return "D_NO_MIGRANT_ARRIVAL";
		case 73: return "ANIMAL_TRAP_CATCH";
		case 74: return "ANIMAL_TRAP_ROBBED";
		case 75: return "MISCHIEF_LEVER";
		case 76: return "MISCHIEF_PLATE";
		case 77: return "MISCHIEF_CAGE";
		case 78: return "MISCHIEF_CHAIN";
		case 79: return "DIPLOMAT_ARRIVAL";
		case 80: return "LIAISON_ARRIVAL";
		case 81: return "TRADE_DIPLOMAT_ARRIVAL";
		case 82: return "CAVE_COLLAPSE";
		case 83: return "BIRTH_CITIZEN";
		case 84: return "BIRTH_ANIMAL";
		case 85: return "STRANGE_MOOD";
		case 86: return "MADE_ARTIFACT";
		case 87: return "NAMED_ARTIFACT";
		case 88: return "ITEM_ATTACHMENT";
		case 89: return "VERMIN_CAGE_ESCAPE";
		case 90: return "TRIGGER_WEB";
		case 91: return "MOOD_BUILDING_CLAIMED";
		case 92: return "ARTIFACT_BEGUN";
		case 93: return "MEGABEAST_ARRIVAL";
		case 94: return "BERSERK_CITIZEN";
		case 95: return "MAGMA_DEFACES_ENGRAVING";
		case 96: return "ENGRAVING_MELTS";
		case 97: return "MASTERPIECE_ARCHITECTURE";
		case 98: return "MASTERPIECE_CONSTRUCTION";
		case 99: return "MASTER_ARCHITECTURE_LOST";
		case 100: return "MASTER_CONSTRUCTION_LOST";
		case 101: return "ADV_AWAKEN";
		case 102: return "ADV_SLEEP_INTERRUPTED";
		case 103: return "CANCEL_JOB";
		case 104: return "ADV_CREATURE_DEATH";
		case 105: return "CITIZEN_DEATH";
		case 106: return "PET_DEATH";
		case 107: return "ENDGAME_EVENT_1";
		case 108: return "ENDGAME_EVENT_2";
		case 109: return "FALL_OVER";
		case 110: return "CAUGHT_IN_FLAMES";
		case 111: return "CAUGHT_IN_WEB";
		case 112: return "UNIT_PROJECTILE_SLAM_BLOW_APART";
		case 113: return "UNIT_PROJECTILE_SLAM";
		case 114: return "UNIT_PROJECTILE_SLAM_INTO_UNIT";
		case 115: return "VOMIT";
		case 116: return "LOSE_HOLD_OF_ITEM";
		case 117: return "REGAIN_CONSCIOUSNESS";
		case 118: return "FREE_FROM_WEB";
		case 119: return "PARALYZED";
		case 120: return "OVERCOME_PARALYSIS";
		case 121: return "NOT_STUNNED";
		case 122: return "EXHAUSTION";
		case 123: return "PAIN_KO";
		case 124: return "BREAK_GRIP";
		case 125: return "NO_BREAK_GRIP";
		case 126: return "BLOCK_FIRE";
		case 127: return "BREATHE_FIRE";
		case 128: return "SHOOT_WEB";
		case 129: return "PULL_OUT_DROP";
		case 130: return "STAND_UP";
		case 131: return "MARTIAL_TRANCE";
		case 132: return "MAT_BREATH";
		case 133: return "ADV_REACTION_PRODUCTS";
		case 134: return "NIGHT_ATTACK_STARTS";
		case 135: return "NIGHT_ATTACK_ENDS";
		case 136: return "NIGHT_ATTACK_TRAVEL";
		case 137: return "GHOST_ATTACK";
		case 138: return "FLAME_HIT";
		case 139: return "TRAVEL_SITE_DISCOVERY";
		case 140: return "TRAVEL_SITE_BUMP";
		case 141: return "ADVENTURE_INTRO";
		case 142: return "CREATURE_SOUND";
		case 143: return "CREATURE_STEALS_OBJECT";
		case 144: return "FOUND_TRAP";
		case 145: return "BODY_TRANSFORMATION";
		case 146: return "INTERACTION_ACTOR";
		case 147: return "INTERACTION_TARGET";
		case 148: return "UNDEAD_ATTACK";
		case 149: return "CITIZEN_MISSING";
		case 150: return "PET_MISSING";
		case 151: return "EMBRACE";
		case 152: return "STRANGE_RAIN_SNOW";
		case 153: return "STRANGE_CLOUD";
		case 154: return "SIMPLE_ANIMAL_ACTION";
		case 155: return "FLOUNDER_IN_LIQUID";
		case 156: return "TRAINING_DOWN_TO_SEMI_WILD";
		case 157: return "TRAINING_FULL_REVERSION";
		case 158: return "ANIMAL_TRAINING_KNOWLEDGE";
		case 159: return "SKIP_ON_LIQUID";
		case 160: return "DODGE_FLYING_OBJECT";
		case 161: return "REGULAR_CONVERSATION";
		case 162: return "BANDIT_EMPTY_CONTAINER";
		case 163: return "BANDIT_GRAB_ITEM";
		case 164: return "COMBAT_EVENT_ATTACK_INTERRUPTED";
		case 165: return "COMBAT_WRESTLE_CATCH_ATTACK";
		case 166: return "FAIL_TO_GRAB_SURFACE";
		case 167: return "LOSE_HOLD_OF_SURFACE";
		case 168: return "TRAVEL_COMPLAINT";
		case 169: return "LOSE_EMOTION";
		case 170: return "REORGANIZE_POSSESSIONS";
		case 171: return "PUSH_ITEM";
		case 172: return "DRAW_ITEM";
		case 173: return "STRAP_ITEM";
		case 174: return "GAIN_SITE_CONTROL";
		case 175: return "CONFLICT_CONVERSATION";
		case 176: return "FORT_POSITION_SUCCESSION";
		case 177: return "MECHANISM_SOUND";
		case 178: return "BIRTH_WILD_ANIMAL";
		case 179: return "STRESSED_CITIZEN";
		case 180: return "CITIZEN_LOST_TO_STRESS";
		case 181: return "CITIZEN_TANTRUM";
		case 182: return "MOVED_OUT_OF_RANGE";
		case 183: return "CANNOT_JUMP";
		case 184: return "NO_TRACKS";
		case 185: return "ALREADY_SEARCHED_AREA";
		case 186: return "SEARCH_FOUND_SOMETHING";
		case 187: return "SEARCH_FOUND_NOTHING";
		case 188: return "NOTHING_TO_INTERACT";
		case 189: return "NOTHING_TO_EXAMINE";
		case 190: return "YOU_YIELDED";
		case 191: return "YOU_UNYIELDED";
		case 192: return "YOU_STRAP_ITEM";
		case 193: return "YOU_DRAW_ITEM";
		case 194: return "NO_GRASP_TO_DRAW_ITEM";
		case 195: return "NO_ITEM_TO_STRAP";
		case 196: return "NO_INV_TO_REMOVE";
		case 197: return "NO_INV_TO_WEAR";
		case 198: return "NO_INV_TO_EAT";
		case 199: return "NO_INV_TO_CONTAIN";
		case 200: return "NO_INV_TO_DROP";
		case 201: return "NOTHING_TO_PICK_UP";
		case 202: return "NO_INV_TO_THROW";
		case 203: return "NO_INV_TO_FIRE";
		case 204: return "CURRENT_SMELL";
		case 205: return "CURRENT_WEATHER";
		case 206: return "CURRENT_TEMPERATURE";
		case 207: return "CURRENT_DATE";
		case 208: return "NO_GRASP_FOR_PICKUP";
		case 209: return "TRAVEL_ADVISORY";
		case 210: return "CANNOT_CLIMB";
		case 211: return "CANNOT_STAND";
		case 212: return "MUST_UNRETRACT_FIRST";
		case 213: return "CANNOT_REST";
		case 214: return "CANNOT_MAKE_CAMPFIRE";
		case 215: return "MADE_CAMPFIRE";
		case 216: return "CANNOT_SET_FIRE";
		case 217: return "SET_FIRE";
		case 218: return "DAWN_BREAKS";
		case 219: return "NOON";
		case 220: return "NIGHTFALL";
		case 221: return "NO_INV_INTERACTION";
		case 222: return "EMPTY_CONTAINER";
		case 223: return "TAKE_OUT_OF_CONTAINER";
		case 224: return "NO_CONTAINER_FOR_ITEM";
		case 225: return "PUT_INTO_CONTAINER";
		case 226: return "EAT_ITEM";
		case 227: return "DRINK_ITEM";
		case 228: return "CONSUME_FAILURE";
		case 229: return "DROP_ITEM";
		case 230: return "PICK_UP_ITEM";
		case 231: return "YOU_BUILDING_INTERACTION";
		case 232: return "YOU_ITEM_INTERACTION";
		case 233: return "YOU_TEMPERATURE_EFFECTS";
		case 234: return "PROFESSION_CHANGES";
		case 235: return "RECRUIT_PROMOTED";
		case 236: return "SOLDIER_BECOMES_MASTER";
		case 237: return "RESOLVE_SHARED_ITEMS";
		case 238: return "COUGH_BLOOD";
		case 239: return "VOMIT_BLOOD";
		case 240: return "MERCHANTS_UNLOADING";
		case 241: return "MERCHANTS_NEED_DEPOT";
		case 242: return "MERCHANT_WAGONS_BYPASSED";
		case 243: return "MERCHANTS_LEAVING_SOON";
		case 244: return "MERCHANTS_EMBARKED";
		case 245: return "PET_LOSES_DEAD_OWNER";
		case 246: return "PET_ADOPTS_OWNER";
		case 247: return "VERMIN_BITE";
		case 248: return "UNABLE_TO_COMPLETE_BUILDING";
		case 249: return "JOBS_REMOVED_FROM_UNPOWERED_BUILDING";
		case 250: return "CITIZEN_SNATCHED";
		case 251: return "VERMIN_DISTURBED";
		case 252: return "LAND_GAINS_STATUS";
		case 253: return "LAND_ELEVATED_STATUS";
		case 254: return "MASTERPIECE_CRAFTED";
		case 255: return "ARTWORK_DEFACED";
		case 256: return "POWER_LEARNED";
		case 257: return "YOU_FEED_ON_SUCKEE";
		case 258: return "ANIMAL_TRAINED";
		case 259: return "DYED_MASTERPIECE";
		case 260: return "COOKED_MASTERPIECE";
		case 261: return "MANDATE_ENDS";
		case 262: return "SLOWDOWN_ENDS";
		case 263: return "FAREWELL_HELPER";
		case 264: return "ELECTION_RESULTS";
		case 265: return "SITE_PRESENT";
		case 266: return "CONSTRUCTION_SUSPENDED";
		case 267: return "LINKAGE_SUSPENDED";
		case 268: return "QUOTA_FILLED";
		case 269: return "JOB_OVERWRITTEN";
		case 270: return "NOTHING_TO_CATCH_IN_WATER";
		case 271: return "DEMAND_FORGOTTEN";
		case 272: return "NEW_DEMAND";
		case 273: return "NEW_MANDATE";
		case 274: return "PRICES_ALTERED";
		case 275: return "NAMED_RESIDENT_CREATURE";
		case 276: return "SOMEBODY_GROWS_UP";
		case 277: return "GUILD_REQUEST_TAKEN";
		case 278: return "GUILD_WAGES_CHANGED";
		case 279: return "NEW_WORK_MANDATE";
		case 280: return "CITIZEN_BECOMES_SOLDIER";
		case 281: return "CITIZEN_BECOMES_NONSOLDIER";
		case 282: return "PARTY_ORGANIZED";
		case 283: return "POSSESSED_TANTRUM";
		case 284: return "BUILDING_TOPPLED_BY_GHOST";
		case 285: return "MASTERFUL_IMPROVEMENT";
		case 286: return "MASTERPIECE_ENGRAVING";
		case 287: return "MARRIAGE";
		case 288: return "NO_MARRIAGE_CELEBRATION";
		case 289: return "CURIOUS_GUZZLER";
		case 290: return "WEATHER_BECOMES_CLEAR";
		case 291: return "WEATHER_BECOMES_SNOW";
		case 292: return "WEATHER_BECOMES_RAIN";
		case 293: return "SEASON_WET";
		case 294: return "SEASON_DRY";
		case 295: return "SEASON_SPRING";
		case 296: return "SEASON_SUMMER";
		case 297: return "SEASON_AUTUMN";
		case 298: return "SEASON_WINTER";
		case 299: return "GUEST_ARRIVAL";
		case 300: return "CANNOT_SPEAK";
		case 301: return "RESEARCH_BREAKTHROUGH";
		case 302: return "SERVICE_ORDER_DELIVERY";
		case 303: return "PERFORMANCE_START_FAILURE";
		case 304: return "BEGIN_ACTIVITY";
		case 305: return "MIDDLE_OF_ACTIVITY";
		case 306: return "ACTIVITY_SECTION_CHANGE";
		case 307: return "CONCLUDE_ACTIVITY";
		case 308: return "LEARNED_WRITTEN_CONTENT";
		case 309: return "LEARNED_ART_FORM";
		case 310: return "PERFORMER_UPDATE";
		case 311: return "BUILDING_DESTROYED_OR_TOPPLED";
		case 312: return "DEITY_CURSE";
		case 313: return "COMPOSITION_COMPLETE";
		case 314: return "COMPOSITION_FAILED";
		case 315: return "NEW_APPRENTICESHIP";
		case 316: return "PETITION_IGNORED";
		case 317: return "CHOP_TREE";
		case 318: return "CANNOT_CONSTRUCT";
		case 319: return "RUMOR_SPREAD";
		case 320: return "AMBUSH_HERO";
		case 321: return "SERVICE_ORDER_RUMOR_RECEIVED";
		case 322: return "RETURNING_RUMOR_RECEIVED";
		case 323: return "NEW_HOLDING";
		case 324: return "NEW_MARKET_LINK";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_art_image_element_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::art_image_element_type::art_image_element_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "CREATURE";
		case 1: return "PLANT";
		case 2: return "TREE";
		case 3: return "SHAPE";
		case 4: return "ITEM";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_art_image_property_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::art_image_property_type::art_image_property_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "transitive_verb";
		case 1: return "intransitive_verb";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_art_image_property_verb_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::art_image_property_verb::art_image_property_verb*>(p_address);
	switch (*m_value)
	{
		case 0: return "Withering";
		case 1: return "SurroundedBy";
		case 2: return "Massacring";
		case 3: return "Fighting";
		case 4: return "Laboring";
		case 5: return "Greeting";
		case 6: return "Refusing";
		case 7: return "Speaking";
		case 8: return "Embracing";
		case 9: return "StrikingDown";
		case 10: return "MenacingPose";
		case 11: return "Traveling";
		case 12: return "Raising";
		case 13: return "Hiding";
		case 14: return "LookingConfused";
		case 15: return "LookingTerrified";
		case 16: return "Devouring";
		case 17: return "Admiring";
		case 18: return "Burning";
		case 19: return "Weeping";
		case 20: return "LookingDejected";
		case 21: return "Cringing";
		case 22: return "Screaming";
		case 23: return "SubmissiveGesture";
		case 24: return "FetalPosition";
		case 25: return "SmearedIntoSpiral";
		case 26: return "Falling";
		case 27: return "Dead";
		case 28: return "Laughing";
		case 29: return "LookingOffended";
		case 30: return "BeingShot";
		case 31: return "PlaintiveGesture";
		case 32: return "Melting";
		case 33: return "Shooting";
		case 34: return "Torturing";
		case 35: return "CommittingDepravedAct";
		case 36: return "Praying";
		case 37: return "Contemplating";
		case 38: return "Cooking";
		case 39: return "Engraving";
		case 40: return "Prostrating";
		case 41: return "Suffering";
		case 42: return "BeingImpaled";
		case 43: return "BeingContorted";
		case 44: return "BeingFlayed";
		case 45: return "HangingFrom";
		case 46: return "BeingMutilated";
		case 47: return "TriumphantPose";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_art_facet_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::art_facet_type::art_facet_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "OWN_RACE";
		case 1: return "FANCIFUL";
		case 2: return "GOOD";
		case 3: return "EVIL";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_poetic_form_action_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::poetic_form_action::poetic_form_action*>(p_address);
	switch (*m_value)
	{
		case 0: return "Describe";
		case 1: return "Satirize";
		case 2: return "AmuseAudience";
		case 3: return "Complain";
		case 4: return "Renounce";
		case 5: return "MakeApology";
		case 6: return "ExpressPleasure";
		case 7: return "ExpressGrief";
		case 8: return "Praise";
		case 9: return "TeachMoralLesson";
		case 10: return "MakeAssertion";
		case 11: return "MakeCounterAssertion";
		case 12: return "MakeConsession";
		case 13: return "SynthesizePreviousIdeas";
		case 14: return "DevelopPreviousIdea";
		case 15: return "InvertTheAssertion";
		case 16: return "UndercutAssertion";
		case 17: return "MoveAwayFromPreviousIdeas";
		case 18: return "ReflectPreviousIdeas";
		case 19: return "ConsoleAudience";
		case 20: return "RefuseConsolation";
		case 21: return "OfferDifferentPerspective";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_poetic_form_pattern_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::poetic_form_pattern::poetic_form_pattern*>(p_address);
	switch (*m_value)
	{
		case 0: return "AA";
		case 1: return "AB";
		case 2: return "BA";
		case 3: return "BB";
		case 4: return "AAA";
		case 5: return "BAA";
		case 6: return "ABA";
		case 7: return "AAB";
		case 8: return "ABB";
		case 9: return "BBA";
		case 10: return "BAB";
		case 11: return "BBB";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_poetic_form_caesura_position_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::poetic_form_caesura_position::poetic_form_caesura_position*>(p_address);
	switch (*m_value)
	{
		case 0: return "Initial";
		case 1: return "Medial";
		case 2: return "Terminal";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_poetic_form_mood_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::poetic_form_mood::poetic_form_mood*>(p_address);
	switch (*m_value)
	{
		case 0: return "Narrative";
		case 1: return "Dramatic";
		case 2: return "Reflective";
		case 3: return "Riddle";
		case 4: return "Ribald";
		case 5: return "Light";
		case 6: return "Solemn";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_poetic_form_subject_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::poetic_form_subject::poetic_form_subject*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Past";
		case 1: return "CurrentEvents";
		case 2: return "Future";
		case 3: return "SomeoneRecentlyDeceased";
		case 4: return "SomeoneRecentlyRetired";
		case 5: return "Religion";
		case 6: return "SpecificPlace";
		case 7: return "SpecificWildernessRegion";
		case 8: return "Nature";
		case 9: return "Lover";
		case 10: return "Family";
		case 11: return "AlcoholicBeverages";
		case 12: return "Journey";
		case 13: return "War";
		case 14: return "Hunt";
		case 15: return "Mining";
		case 16: return "Death";
		case 17: return "Immortality";
		case 18: return "SomeonesCharacter";
		case 19: return "Histfig";
		case 20: return "Concept";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_poetic_form_additional_feature_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::poetic_form_additional_feature::poetic_form_additional_feature*>(p_address);
	switch (*m_value)
	{
		case 0: return "SharesUnderlyingMeaning";
		case 1: return "ContrastsUnderlyingMeaning";
		case 2: return "RequiredToMaintainPhrasing";
		case 3: return "SameGrammaticalStructure";
		case 4: return "SamePlacementOfAllusions";
		case 5: return "ReverseWordOrder";
		case 6: return "ReverseGrammaticalStructure";
		case 7: return "PresentsDifferentView";
		case 8: return "MustExpandIdea";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_poetic_form_perspective__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::poetic_form_perspective::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Author";
		case 1: return "Soldier";
		case 2: return "Traveller";
		case 3: return "RelativeOfAuthor";
		case 4: return "PartyOfDebate";
		case 5: return "FictionalPoet";
		case 6: return "Histfig";
		case 7: return "Animal";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_occupation_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::occupation_type::occupation_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "TAVERN_KEEPER";
		case 1: return "PERFORMER";
		case 2: return "SCHOLAR";
		case 3: return "MERCENARY";
		case 4: return "MONSTER_SLAYER";
		case 5: return "SCRIBE";
		case 6: return "MESSENGER";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_buildings_other_id_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::buildings_other_id::buildings_other_id*>(p_address);
	switch (*m_value)
	{
		case -1: return "ANY";
		case 0: return "IN_PLAY";
		case 1: return "LOCATION_ASSIGNED";
		case 2: return "STOCKPILE";
		case 3: return "ANY_ZONE";
		case 4: return "ACTIVITY_ZONE";
		case 5: return "ANY_ACTUAL";
		case 6: return "ANY_MACHINE";
		case 7: return "ANY_HOSPITAL_STORAGE";
		case 8: return "ANY_STORAGE";
		case 9: return "ANY_BARRACKS";
		case 10: return "ANY_NOBLE_ROOM";
		case 11: return "ANY_HOSPITAL";
		case 12: return "BOX";
		case 13: return "CABINET";
		case 14: return "TRAP";
		case 15: return "DOOR";
		case 16: return "FLOODGATE";
		case 17: return "HATCH";
		case 18: return "GRATE_WALL";
		case 19: return "GRATE_FLOOR";
		case 20: return "BARS_VERTICAL";
		case 21: return "BARS_FLOOR";
		case 22: return "WINDOW_ANY";
		case 23: return "WELL";
		case 24: return "TABLE";
		case 25: return "BRIDGE";
		case 26: return "CHAIR";
		case 27: return "TRADE_DEPOT";
		case 28: return "NEST";
		case 29: return "NEST_BOX";
		case 30: return "BOOKCASE";
		case 31: return "DISPLAY_CASE";
		case 32: return "HIVE";
		case 33: return "WAGON";
		case 34: return "SHOP";
		case 35: return "BED";
		case 36: return "TRACTION_BENCH";
		case 37: return "ANY_ROAD";
		case 38: return "FARM_PLOT";
		case 39: return "GEAR_ASSEMBLY";
		case 40: return "ROLLERS";
		case 41: return "AXLE_HORIZONTAL";
		case 42: return "AXLE_VERTICAL";
		case 43: return "SUPPORT";
		case 44: return "ARCHERY_TARGET";
		case 45: return "SCREW_PUMP";
		case 46: return "WATER_WHEEL";
		case 47: return "WINDMILL";
		case 48: return "CHAIN";
		case 49: return "CAGE";
		case 50: return "STATUE";
		case 51: return "SLAB";
		case 52: return "COFFIN";
		case 53: return "WEAPON_RACK";
		case 54: return "ARMOR_STAND";
		case 55: return "FURNACE_ANY";
		case 56: return "FURNACE_WOOD";
		case 57: return "FURNACE_SMELTER_ANY";
		case 58: return "FURNACE_SMELTER_MAGMA";
		case 59: return "FURNACE_KILN_ANY";
		case 60: return "FURNACE_GLASS_ANY";
		case 61: return "FURNACE_CUSTOM";
		case 62: return "WORKSHOP_ANY";
		case 63: return "WORKSHOP_BUTCHER";
		case 64: return "WORKSHOP_MASON";
		case 65: return "WORKSHOP_KENNEL";
		case 66: return "WORKSHOP_FISHERY";
		case 67: return "WORKSHOP_JEWELER";
		case 68: return "WORKSHOP_LOOM";
		case 69: return "WORKSHOP_TANNER";
		case 70: return "WORKSHOP_DYER";
		case 71: return "WORKSHOP_MILL_ANY";
		case 72: return "WORKSHOP_QUERN";
		case 73: return "WORKSHOP_TOOL";
		case 74: return "WORKSHOP_MILLSTONE";
		case 75: return "WORKSHOP_KITCHEN";
		case 76: return "WORKSHOP_STILL";
		case 77: return "WORKSHOP_FARMER";
		case 78: return "WORKSHOP_ASHERY";
		case 79: return "WORKSHOP_CARPENTER";
		case 80: return "WORKSHOP_CRAFTSDWARF";
		case 81: return "WORKSHOP_MECHANIC";
		case 82: return "WORKSHOP_SIEGE";
		case 83: return "WORKSHOP_CLOTHIER";
		case 84: return "WORKSHOP_LEATHER";
		case 85: return "WORKSHOP_BOWYER";
		case 86: return "WORKSHOP_MAGMA_FORGE";
		case 87: return "WORKSHOP_FORGE_ANY";
		case 88: return "WORKSHOP_CUSTOM";
		case 89: return "WEAPON_UPRIGHT";
		case 90: return "INSTRUMENT_STATIONARY";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_building_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::building_type::building_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "Chair";
		case 1: return "Bed";
		case 2: return "Table";
		case 3: return "Coffin";
		case 4: return "FarmPlot";
		case 5: return "Furnace";
		case 6: return "TradeDepot";
		case 7: return "Shop";
		case 8: return "Door";
		case 9: return "Floodgate";
		case 10: return "Box";
		case 11: return "Weaponrack";
		case 12: return "Armorstand";
		case 13: return "Workshop";
		case 14: return "Cabinet";
		case 15: return "Statue";
		case 16: return "WindowGlass";
		case 17: return "WindowGem";
		case 18: return "Well";
		case 19: return "Bridge";
		case 20: return "RoadDirt";
		case 21: return "RoadPaved";
		case 22: return "SiegeEngine";
		case 23: return "Trap";
		case 24: return "AnimalTrap";
		case 25: return "Support";
		case 26: return "ArcheryTarget";
		case 27: return "Chain";
		case 28: return "Cage";
		case 29: return "Stockpile";
		case 30: return "Civzone";
		case 31: return "Weapon";
		case 32: return "Wagon";
		case 33: return "ScrewPump";
		case 34: return "Construction";
		case 35: return "Hatch";
		case 36: return "GrateWall";
		case 37: return "GrateFloor";
		case 38: return "BarsVertical";
		case 39: return "BarsFloor";
		case 40: return "GearAssembly";
		case 41: return "AxleHorizontal";
		case 42: return "AxleVertical";
		case 43: return "WaterWheel";
		case 44: return "Windmill";
		case 45: return "TractionBench";
		case 46: return "Slab";
		case 47: return "Nest";
		case 48: return "NestBox";
		case 49: return "Hive";
		case 50: return "Rollers";
		case 51: return "Instrument";
		case 52: return "Bookcase";
		case 53: return "DisplayFurniture";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_civzone_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::civzone_type::civzone_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Home";
		case 1: return "Depot";
		case 2: return "Stockpile";
		case 3: return "NobleQuarters";
		case 4: return "anon_1";
		case 5: return "anon_2";
		case 6: return "anon_3";
		case 7: return "MeadHall";
		case 8: return "ThroneRoom";
		case 9: return "ActivityZone";
		case 10: return "Temple";
		case 11: return "Kitchen";
		case 12: return "CaptiveRoom";
		case 13: return "TowerTop";
		case 14: return "Courtyard";
		case 15: return "Treasury";
		case 16: return "GuardPost";
		case 17: return "Entrance";
		case 18: return "SecretLibrary";
		case 19: return "Library";
		case 20: return "Plot";
		case 21: return "MarketStall";
		case 22: return "anon_4";
		case 23: return "Campground";
		case 24: return "CommandTent";
		case 25: return "Tent";
		case 26: return "CommandTentBld";
		case 27: return "TentBld";
		case 28: return "MechanismRoom";
		case 29: return "DungeonCell";
		case 30: return "AnimalPit";
		case 31: return "ClothPit";
		case 32: return "TanningPit";
		case 33: return "ClothClothingPit";
		case 34: return "LeatherClothingPit";
		case 35: return "BoneCarvingPit";
		case 36: return "GemCuttingPit";
		case 37: return "WeaponsmithingPit";
		case 38: return "BowmakingPit";
		case 39: return "BlacksmithingPit";
		case 40: return "ArmorsmithingPit";
		case 41: return "MetalCraftingPit";
		case 42: return "LeatherworkingPit";
		case 43: return "CarpentryPit";
		case 44: return "StoneworkingPit";
		case 45: return "ForgingPit";
		case 46: return "FightingPit";
		case 47: return "anon_5";
		case 48: return "anon_6";
		case 49: return "anon_7";
		case 50: return "anon_8";
		case 51: return "anon_9";
		case 52: return "anon_10";
		case 53: return "AnimalWorkshop";
		case 54: return "ClothWorkshop";
		case 55: return "TanningWorkshop";
		case 56: return "ClothClothingWorkshop";
		case 57: return "LeatherClothingWorkshop";
		case 58: return "BoneCarvingWorkshop";
		case 59: return "GemCuttingWorkshop";
		case 60: return "WeaponsmithingWorkshop";
		case 61: return "BowmakingWorkshop";
		case 62: return "BlacksmithingWorkshop";
		case 63: return "ArmorsmithingWorkshop";
		case 64: return "MetalCraftingWorkshop";
		case 65: return "LeatherworkingShop";
		case 66: return "CarpentryWorkshop";
		case 67: return "StoneworkingWorkshop";
		case 68: return "ForgingWorkshop";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_furnace_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::furnace_type::furnace_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "WoodFurnace";
		case 1: return "Smelter";
		case 2: return "GlassFurnace";
		case 3: return "Kiln";
		case 4: return "MagmaSmelter";
		case 5: return "MagmaGlassFurnace";
		case 6: return "MagmaKiln";
		case 7: return "Custom";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_workshop_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::workshop_type::workshop_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Carpenters";
		case 1: return "Farmers";
		case 2: return "Masons";
		case 3: return "Craftsdwarfs";
		case 4: return "Jewelers";
		case 5: return "MetalsmithsForge";
		case 6: return "MagmaForge";
		case 7: return "Bowyers";
		case 8: return "Mechanics";
		case 9: return "Siege";
		case 10: return "Butchers";
		case 11: return "Leatherworks";
		case 12: return "Tanners";
		case 13: return "Clothiers";
		case 14: return "Fishery";
		case 15: return "Still";
		case 16: return "Loom";
		case 17: return "Quern";
		case 18: return "Kennels";
		case 19: return "Kitchen";
		case 20: return "Ashery";
		case 21: return "Dyers";
		case 22: return "Millstone";
		case 23: return "Custom";
		case 24: return "Tool";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_construction_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::construction_type::construction_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "Fortification";
		case 1: return "Wall";
		case 2: return "Floor";
		case 3: return "UpStair";
		case 4: return "DownStair";
		case 5: return "UpDownStair";
		case 6: return "Ramp";
		case 7: return "TrackN";
		case 8: return "TrackS";
		case 9: return "TrackE";
		case 10: return "TrackW";
		case 11: return "TrackNS";
		case 12: return "TrackNE";
		case 13: return "TrackNW";
		case 14: return "TrackSE";
		case 15: return "TrackSW";
		case 16: return "TrackEW";
		case 17: return "TrackNSE";
		case 18: return "TrackNSW";
		case 19: return "TrackNEW";
		case 20: return "TrackSEW";
		case 21: return "TrackNSEW";
		case 22: return "TrackRampN";
		case 23: return "TrackRampS";
		case 24: return "TrackRampE";
		case 25: return "TrackRampW";
		case 26: return "TrackRampNS";
		case 27: return "TrackRampNE";
		case 28: return "TrackRampNW";
		case 29: return "TrackRampSE";
		case 30: return "TrackRampSW";
		case 31: return "TrackRampEW";
		case 32: return "TrackRampNSE";
		case 33: return "TrackRampNSW";
		case 34: return "TrackRampNEW";
		case 35: return "TrackRampSEW";
		case 36: return "TrackRampNSEW";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_shop_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::shop_type::shop_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "GeneralStore";
		case 1: return "CraftsMarket";
		case 2: return "ClothingShop";
		case 3: return "ExoticClothingShop";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_siegeengine_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::siegeengine_type::siegeengine_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Catapult";
		case 1: return "Ballista";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_trap_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::trap_type::trap_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Lever";
		case 1: return "PressurePlate";
		case 2: return "CageTrap";
		case 3: return "StoneFallTrap";
		case 4: return "WeaponTrap";
		case 5: return "TrackStop";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_dfhack_room_quality_level_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::dfhack_room_quality_level::dfhack_room_quality_level*>(p_address);
	switch (*m_value)
	{
		case 0: return "Meager";
		case 1: return "Modest";
		case 2: return "Normal";
		case 3: return "Decent";
		case 4: return "Fine";
		case 5: return "Great";
		case 6: return "Grand";
		case 7: return "Royal";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_creature_raw_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::creature_raw_flags::creature_raw_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "unk_wagon";
		case 1: return "EQUIPMENT_WAGON";
		case 2: return "MUNDANE";
		case 3: return "VERMIN_EATER";
		case 4: return "VERMIN_GROUNDER";
		case 5: return "VERMIN_ROTTER";
		case 6: return "VERMIN_SOIL";
		case 7: return "VERMIN_SOIL_COLONY";
		case 8: return "LARGE_ROAMING";
		case 9: return "VERMIN_FISH";
		case 10: return "LOOSE_CLUSTERS";
		case 11: return "FANCIFUL";
		case 12: return "BIOME_MOUNTAIN";
		case 13: return "BIOME_GLACIER";
		case 14: return "BIOME_TUNDRA";
		case 15: return "BIOME_SWAMP_TEMPERATE_FRESHWATER";
		case 16: return "BIOME_SWAMP_TEMPERATE_SALTWATER";
		case 17: return "BIOME_MARSH_TEMPERATE_FRESHWATER";
		case 18: return "BIOME_MARSH_TEMPERATE_SALTWATER";
		case 19: return "BIOME_SWAMP_TROPICAL_FRESHWATER";
		case 20: return "BIOME_SWAMP_TROPICAL_SALTWATER";
		case 21: return "BIOME_SWAMP_MANGROVE";
		case 22: return "BIOME_MARSH_TROPICAL_FRESHWATER";
		case 23: return "BIOME_MARSH_TROPICAL_SALTWATER";
		case 24: return "BIOME_FOREST_TAIGA";
		case 25: return "BIOME_FOREST_TEMPERATE_CONIFER";
		case 26: return "BIOME_FOREST_TEMPERATE_BROADLEAF";
		case 27: return "BIOME_FOREST_TROPICAL_CONIFER";
		case 28: return "BIOME_FOREST_TROPICAL_DRY_BROADLEAF";
		case 29: return "BIOME_FOREST_TROPICAL_MOIST_BROADLEAF";
		case 30: return "BIOME_GRASSLAND_TEMPERATE";
		case 31: return "BIOME_SAVANNA_TEMPERATE";
		case 32: return "BIOME_SHRUBLAND_TEMPERATE";
		case 33: return "BIOME_GRASSLAND_TROPICAL";
		case 34: return "BIOME_SAVANNA_TROPICAL";
		case 35: return "BIOME_SHRUBLAND_TROPICAL";
		case 36: return "BIOME_DESERT_BADLAND";
		case 37: return "BIOME_DESERT_ROCK";
		case 38: return "BIOME_DESERT_SAND";
		case 39: return "BIOME_OCEAN_TROPICAL";
		case 40: return "BIOME_OCEAN_TEMPERATE";
		case 41: return "BIOME_OCEAN_ARCTIC";
		case 42: return "BIOME_SUBTERRANEAN_WATER";
		case 43: return "BIOME_SUBTERRANEAN_CHASM";
		case 44: return "BIOME_SUBTERRANEAN_LAVA";
		case 45: return "BIOME_POOL_TEMPERATE_FRESHWATER";
		case 46: return "BIOME_POOL_TEMPERATE_BRACKISHWATER";
		case 47: return "BIOME_POOL_TEMPERATE_SALTWATER";
		case 48: return "BIOME_POOL_TROPICAL_FRESHWATER";
		case 49: return "BIOME_POOL_TROPICAL_BRACKISHWATER";
		case 50: return "BIOME_POOL_TROPICAL_SALTWATER";
		case 51: return "BIOME_LAKE_TEMPERATE_FRESHWATER";
		case 52: return "BIOME_LAKE_TEMPERATE_BRACKISHWATER";
		case 53: return "BIOME_LAKE_TEMPERATE_SALTWATER";
		case 54: return "BIOME_LAKE_TROPICAL_FRESHWATER";
		case 55: return "BIOME_LAKE_TROPICAL_BRACKISHWATER";
		case 56: return "BIOME_LAKE_TROPICAL_SALTWATER";
		case 57: return "BIOME_RIVER_TEMPERATE_FRESHWATER";
		case 58: return "BIOME_RIVER_TEMPERATE_BRACKISHWATER";
		case 59: return "BIOME_RIVER_TEMPERATE_SALTWATER";
		case 60: return "BIOME_RIVER_TROPICAL_FRESHWATER";
		case 61: return "BIOME_RIVER_TROPICAL_BRACKISHWATER";
		case 62: return "BIOME_RIVER_TROPICAL_SALTWATER";
		case 63: return "GOOD";
		case 64: return "EVIL";
		case 65: return "SAVAGE";
		case 66: return "NOT_ASEXUAL";
		case 67: return "unk_43";
		case 68: return "unk_44";
		case 69: return "unk_45";
		case 70: return "any_vermin";
		case 71: return "CASTE_CAN_LEARN";
		case 72: return "CASTE_VERMIN_HATEABLE";
		case 73: return "unk_49";
		case 74: return "CASTE_LARGE_PREDATOR";
		case 75: return "CASTE_CURIOUSBEAST";
		case 76: return "CASTE_BENIGN";
		case 77: return "CASTE_NATURAL";
		case 78: return "CASTE_MEGABEAST";
		case 79: return "CASTE_SEMIMEGABEAST";
		case 80: return "CASTE_POWER";
		case 81: return "CASTE_VERMIN_MICRO";
		case 82: return "CASTE_NOT_FIREIMMUNE";
		case 83: return "CASTE_MUST_BREATHE_AIR";
		case 84: return "CASTE_MUST_BREATHE_WATER";
		case 85: return "unk_55";
		case 86: return "CASTE_SWIMS_LEARNED";
		case 87: return "CASTE_COMMON_DOMESTIC";
		case 88: return "CASTE_UTTERANCES";
		case 89: return "CASTE_CAN_SPEAK";
		case 90: return "CASTE_FEATURE_BEAST";
		case 91: return "GENERATED";
		case 92: return "CASTE_TITAN";
		case 93: return "CASTE_UNIQUE_DEMON";
		case 94: return "DOES_NOT_EXIST";
		case 95: return "CASTE_NOT_LIVING";
		case 96: return "CASTE_MISCHIEVOUS";
		case 97: return "CASTE_FLIER";
		case 98: return "CASTE_DEMON";
		case 99: return "CASTE_NIGHT_CREATURE_ANY";
		case 100: return "CASTE_NIGHT_CREATURE_HUNTER";
		case 101: return "CASTE_NIGHT_CREATURE_BOGEYMAN";
		case 102: return "CASTE_CARNIVORE";
		case 103: return "ARTIFICIAL_HIVEABLE";
		case 104: return "UBIQUITOUS";
		case 105: return "unk_69";
		case 106: return "CASTE_SUPERNATURAL";
		case 107: return "CASTE_BLOOD";
		case 108: return "CASTE_GRAZER";
		case 109: return "CASTE_unk_31";
		case 110: return "unk_6e";
		case 111: return "unk_6f";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_caste_raw_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::caste_raw_flags::caste_raw_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "AMPHIBIOUS";
		case 1: return "AQUATIC";
		case 2: return "LOCKPICKER";
		case 3: return "MISCHIEVOUS";
		case 4: return "PATTERNFLIER";
		case 5: return "CURIOUSBEAST_ANY";
		case 6: return "CURIOUSBEAST_ITEM";
		case 7: return "CURIOUSBEAST_GUZZLER";
		case 8: return "FLEEQUICK";
		case 9: return "AT_PEACE_WITH_WILDLIFE";
		case 10: return "SWIMS_LEARNED";
		case 11: return "OPPOSED_TO_LIFE";
		case 12: return "CURIOUSBEAST_EATER";
		case 13: return "NO_EAT";
		case 14: return "NO_DRINK";
		case 15: return "NO_SLEEP";
		case 16: return "COMMON_DOMESTIC";
		case 17: return "WAGON_PULLER";
		case 18: return "PACK_ANIMAL";
		case 19: return "FLIER";
		case 20: return "LARGE_PREDATOR";
		case 21: return "MAGMA_VISION";
		case 22: return "FIREIMMUNE";
		case 23: return "FIREIMMUNE_SUPER";
		case 24: return "WEBBER";
		case 25: return "WEBIMMUNE";
		case 26: return "FISHITEM";
		case 27: return "IMMOBILE_LAND";
		case 28: return "IMMOLATE";
		case 29: return "MILKABLE";
		case 30: return "NO_SPRING";
		case 31: return "NO_SUMMER";
		case 32: return "NO_AUTUMN";
		case 33: return "NO_WINTER";
		case 34: return "BENIGN";
		case 35: return "VERMIN_NOROAM";
		case 36: return "VERMIN_NOTRAP";
		case 37: return "VERMIN_NOFISH";
		case 38: return "HAS_NERVES";
		case 39: return "NO_DIZZINESS";
		case 40: return "NO_FEVERS";
		case 41: return "NO_UNIT_TYPE_COLOR";
		case 42: return "NO_CONNECTIONS_FOR_MOVEMENT";
		case 43: return "SUPERNATURAL";
		case 44: return "AMBUSHPREDATOR";
		case 45: return "GNAWER";
		case 46: return "NOT_BUTCHERABLE";
		case 47: return "COOKABLE_LIVE";
		case 48: return "SECRETION";
		case 49: return "IMMOBILE";
		case 50: return "MULTIPART_FULL_VISION";
		case 51: return "MEANDERER";
		case 52: return "THICKWEB";
		case 53: return "TRAINABLE_HUNTING";
		case 54: return "PET";
		case 55: return "PET_EXOTIC";
		case 56: return "unk_38";
		case 57: return "CAN_SPEAK";
		case 58: return "CAN_LEARN";
		case 59: return "UTTERANCES";
		case 60: return "BONECARN";
		case 61: return "CARNIVORE";
		case 62: return "UNDERSWIM";
		case 63: return "NOEXERT";
		case 64: return "NOPAIN";
		case 65: return "EXTRAVISION";
		case 66: return "NOBREATHE";
		case 67: return "NOSTUN";
		case 68: return "NONAUSEA";
		case 69: return "BLOOD";
		case 70: return "TRANCES";
		case 71: return "NOEMOTION";
		case 72: return "SLOW_LEARNER";
		case 73: return "NOSTUCKINS";
		case 74: return "PUS";
		case 75: return "NOSKULL";
		case 76: return "NOSKIN";
		case 77: return "NOBONES";
		case 78: return "NOMEAT";
		case 79: return "PARALYZEIMMUNE";
		case 80: return "NOFEAR";
		case 81: return "CANOPENDOORS";
		case 82: return "ITEMCORPSE";
		case 83: return "GETS_WOUND_INFECTIONS";
		case 84: return "NOSMELLYROT";
		case 85: return "REMAINS_UNDETERMINED";
		case 86: return "HASSHELL";
		case 87: return "PEARL";
		case 88: return "TRAINABLE_WAR";
		case 89: return "NO_THOUGHT_CENTER_FOR_MOVEMENT";
		case 90: return "ARENA_RESTRICTED";
		case 91: return "LAIR_HUNTER";
		case 92: return "LIKES_FIGHTING";
		case 93: return "VERMIN_HATEABLE";
		case 94: return "VEGETATION";
		case 95: return "MAGICAL";
		case 96: return "NATURAL";
		case 97: return "BABY";
		case 98: return "CHILD";
		case 99: return "MULTIPLE_LITTER_RARE";
		case 100: return "MOUNT";
		case 101: return "MOUNT_EXOTIC";
		case 102: return "FEATURE_ATTACK_GROUP";
		case 103: return "VERMIN_MICRO";
		case 104: return "EQUIPS";
		case 105: return "LAYS_EGGS";
		case 106: return "GRAZER";
		case 107: return "NOTHOUGHT";
		case 108: return "TRAPAVOID";
		case 109: return "CAVE_ADAPT";
		case 110: return "MEGABEAST";
		case 111: return "SEMIMEGABEAST";
		case 112: return "ALL_ACTIVE";
		case 113: return "DIURNAL";
		case 114: return "NOCTURNAL";
		case 115: return "CREPUSCULAR";
		case 116: return "MATUTINAL";
		case 117: return "VESPERTINE";
		case 118: return "LIGHT_GEN";
		case 119: return "LISP";
		case 120: return "GETS_INFECTIONS_FROM_ROT";
		case 121: return "CASTE_SOLDIER_TILE";
		case 122: return "ALCOHOL_DEPENDENT";
		case 123: return "SWIMS_INNATE";
		case 124: return "POWER";
		case 125: return "TENDONS";
		case 126: return "LIGAMENTS";
		case 127: return "CASTE_TILE";
		case 128: return "CASTE_COLOR";
		case 129: return "CASTE_GLOWTILE";
		case 130: return "CASTE_GLOWCOLOR";
		case 131: return "FEATURE_BEAST";
		case 132: return "TITAN";
		case 133: return "UNIQUE_DEMON";
		case 134: return "DEMON";
		case 135: return "MANNERISM_LAUGH";
		case 136: return "MANNERISM_SMILE";
		case 137: return "MANNERISM_WALK";
		case 138: return "MANNERISM_SIT";
		case 139: return "MANNERISM_BREATH";
		case 140: return "MANNERISM_POSTURE";
		case 141: return "MANNERISM_STRETCH";
		case 142: return "MANNERISM_EYELIDS";
		case 143: return "NIGHT_CREATURE_ANY";
		case 144: return "NIGHT_CREATURE_HUNTER";
		case 145: return "NIGHT_CREATURE_BOGEYMAN";
		case 146: return "CONVERTED_SPOUSE";
		case 147: return "SPOUSE_CONVERTER";
		case 148: return "SPOUSE_CONVERSION_TARGET";
		case 149: return "DIE_WHEN_VERMIN_BITE";
		case 150: return "REMAINS_ON_VERMIN_BITE_DEATH";
		case 151: return "COLONY_EXTERNAL";
		case 152: return "LAYS_UNUSUAL_EGGS";
		case 153: return "RETURNS_VERMIN_KILLS_TO_OWNER";
		case 154: return "HUNTS_VERMIN";
		case 155: return "ADOPTS_OWNER";
		case 156: return "SOUND_ALERT";
		case 157: return "SOUND_PEACEFUL_INTERMITTENT";
		case 158: return "NOT_LIVING";
		case 159: return "NO_PHYS_ATT_GAIN";
		case 160: return "NO_PHYS_ATT_RUST";
		case 161: return "CRAZED";
		case 162: return "BLOODSUCKER";
		case 163: return "NO_VEGETATION_PERTURB";
		case 164: return "DIVE_HUNTS_VERMIN";
		case 165: return "GOBBLE_VERMIN";
		case 166: return "CANNOT_JUMP";
		case 167: return "STANCE_CLIMBER";
		case 168: return "CANNOT_CLIMB";
		case 169: return "LOCAL_POPS_CONTROLLABLE";
		case 170: return "OUTSIDER_CONTROLLABLE";
		case 171: return "LOCAL_POPS_PRODUCE_HEROES";
		case 172: return "STRANGE_MOODS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_body_part_raw_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::body_part_raw_flags::body_part_raw_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "HEAD";
		case 1: return "UPPERBODY";
		case 2: return "LOWERBODY";
		case 3: return "SIGHT";
		case 4: return "EMBEDDED";
		case 5: return "INTERNAL";
		case 6: return "CIRCULATION";
		case 7: return "SKELETON";
		case 8: return "LIMB";
		case 9: return "GRASP";
		case 10: return "STANCE";
		case 11: return "GUTS";
		case 12: return "BREATHE";
		case 13: return "SMALL";
		case 14: return "THROAT";
		case 15: return "JOINT";
		case 16: return "THOUGHT";
		case 17: return "NERVOUS";
		case 18: return "RIGHT";
		case 19: return "LEFT";
		case 20: return "HEAR";
		case 21: return "SMELL";
		case 22: return "FLIER";
		case 23: return "DIGIT";
		case 24: return "MOUTH";
		case 25: return "APERTURE";
		case 26: return "SOCKET";
		case 27: return "TOTEMABLE";
		case 28: return "anon_1";
		case 29: return "anon_2";
		case 30: return "UNDER_PRESSURE";
		case 31: return "anon_3";
		case 32: return "VERMIN_BUTCHER_ITEM";
		case 33: return "CONNECTOR";
		case 34: return "anon_4";
		case 35: return "anon_5";
		case 36: return "anon_6";
		case 37: return "anon_7";
		case 38: return "GELDABLE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_appearance_modifier_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::appearance_modifier_type::appearance_modifier_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "HEIGHT";
		case 1: return "BROADNESS";
		case 2: return "LENGTH";
		case 3: return "CLOSE_SET";
		case 4: return "DEEP_SET";
		case 5: return "HIGH_POSITION";
		case 6: return "LARGE_IRIS";
		case 7: return "WRINKLY";
		case 8: return "CURLY";
		case 9: return "CONVEX";
		case 10: return "DENSE";
		case 11: return "THICKNESS";
		case 12: return "UPTURNED";
		case 13: return "SPLAYED_OUT";
		case 14: return "HANGING_LOBES";
		case 15: return "GAPS";
		case 16: return "HIGH_CHEEKBONES";
		case 17: return "BROAD_CHIN";
		case 18: return "JUTTING_CHIN";
		case 19: return "SQUARE_CHIN";
		case 20: return "ROUND_VS_NARROW";
		case 21: return "GREASY";
		case 22: return "DEEP_VOICE";
		case 23: return "RASPY_VOICE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_body_part_layer_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::body_part_layer_flags::body_part_layer_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "CONNECTS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_appearance_modifier_growth_interval_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::appearance_modifier_growth_interval::appearance_modifier_growth_interval*>(p_address);
	switch (*m_value)
	{
		case 0: return "DAILY";
		case 1: return "WEEKLY";
		case 2: return "MONTHLY";
		case 3: return "YEARLY";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_gait_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::gait_type::gait_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "WALK";
		case 1: return "FLY";
		case 2: return "SWIM";
		case 3: return "CRAWL";
		case 4: return "CLIMB";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_creature_graphics_role_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::creature_graphics_role::creature_graphics_role*>(p_address);
	switch (*m_value)
	{
		case 0: return "DEFAULT";
		case 1: return "ADVENTURER";
		case 2: return "GUARD";
		case 3: return "ROYALGUARD";
		case 4: return "ANIMATED";
		case 5: return "GHOST";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tissue_style_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tissue_style_type::tissue_style_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "NEATLY_COMBED";
		case 1: return "BRAIDED";
		case 2: return "DOUBLE_BRAIDS";
		case 3: return "PONY_TAILS";
		case 4: return "CLEAN_SHAVEN";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_body_part_template_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::body_part_template_flags::body_part_template_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "HEAD";
		case 1: return "UPPERBODY";
		case 2: return "LOWERBODY";
		case 3: return "SIGHT";
		case 4: return "EMBEDDED";
		case 5: return "INTERNAL";
		case 6: return "CIRCULATION";
		case 7: return "SKELETON";
		case 8: return "LIMB";
		case 9: return "GRASP";
		case 10: return "STANCE";
		case 11: return "GUTS";
		case 12: return "BREATHE";
		case 13: return "SMALL";
		case 14: return "THROAT";
		case 15: return "JOINT";
		case 16: return "THOUGHT";
		case 17: return "NERVOUS";
		case 18: return "RIGHT";
		case 19: return "LEFT";
		case 20: return "HEAR";
		case 21: return "SMELL";
		case 22: return "FLIER";
		case 23: return "DIGIT";
		case 24: return "MOUTH";
		case 25: return "APERTURE";
		case 26: return "SOCKET";
		case 27: return "TOTEMABLE";
		case 28: return "UNDER_PRESSURE";
		case 29: return "VERMIN_BUTCHER_ITEM";
		case 30: return "CONNECTOR";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_body_part_template_contype_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::body_part_template_contype::body_part_template_contype*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "UPPERBODY";
		case 1: return "LOWERBODY";
		case 2: return "HEAD";
		case 3: return "GRASP";
		case 4: return "STANCE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tissue_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tissue_flags::tissue_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "THICKENS_ON_STRENGTH";
		case 1: return "THICKENS_ON_ENERGY_STORAGE";
		case 2: return "ARTERIES";
		case 3: return "SCARS";
		case 4: return "STRUCTURAL";
		case 5: return "NERVOUS";
		case 6: return "THOUGHT";
		case 7: return "MUSCULAR";
		case 8: return "SMELL";
		case 9: return "HEAR";
		case 10: return "FLIGHT";
		case 11: return "BREATHE";
		case 12: return "SIGHT";
		case 13: return "COSMETIC";
		case 14: return "CONNECTS";
		case 15: return "FUNCTIONAL";
		case 16: return "MAJOR_ARTERIES";
		case 17: return "TISSUE_LEAKS";
		case 18: return "STYLEABLE";
		case 19: return "CONNECTIVE_TISSUE_ANCHOR";
		case 20: return "SETTABLE";
		case 21: return "SPLINTABLE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_nickname_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_nickname::d_init_nickname*>(p_address);
	switch (*m_value)
	{
		case 0: return "REPLACE_FIRST";
		case 1: return "CENTRALIZE";
		case 2: return "REPLACE_ALL";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_z_view_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_z_view::d_init_z_view*>(p_address);
	switch (*m_value)
	{
		case 0: return "OFF";
		case 1: return "UNHIDDEN";
		case 2: return "CREATURE";
		case 3: return "ON";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_embark_confirm_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_embark_confirm::d_init_embark_confirm*>(p_address);
	switch (*m_value)
	{
		case 0: return "ALWAYS";
		case 1: return "IF_POINTS_REMAIN";
		case 2: return "NO";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_idlers_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_idlers::d_init_idlers*>(p_address);
	switch (*m_value)
	{
		case -1: return "OFF";
		case 0: return "TOP";
		case 1: return "BOTTOM";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_tunnel_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_tunnel::d_init_tunnel*>(p_address);
	switch (*m_value)
	{
		case 0: return "NO";
		case 1: return "FINDER";
		case 2: return "ALWAYS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_flags1_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_flags1::d_init_flags1*>(p_address);
	switch (*m_value)
	{
		case 0: return "VARIED_GROUND_TILES";
		case 1: return "ENGRAVINGS_START_OBSCURED";
		case 2: return "SHOW_IMP_QUALITY";
		case 3: return "SHOW_FLOW_AMOUNTS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_flags2_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_flags2::d_init_flags2*>(p_address);
	switch (*m_value)
	{
		case 0: return "MORE";
		case 1: return "ADVENTURER_TRAPS";
		case 2: return "ADVENTURER_ALWAYS_CENTER";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_flags3_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_flags3::d_init_flags3*>(p_address);
	switch (*m_value)
	{
		case 0: return "COFFIN_NO_PETS_DEFAULT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_d_init_flags4_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::d_init_flags4::d_init_flags4*>(p_address);
	switch (*m_value)
	{
		case 0: return "TEMPERATURE";
		case 1: return "WEATHER";
		case 2: return "ECONOMY";
		case 3: return "ZERO_RENT";
		case 4: return "AUTOSAVE_SEASONAL";
		case 5: return "AUTOSAVE_YEARLY";
		case 6: return "AUTOSAVE_PAUSE";
		case 7: return "AUTOBACKUP";
		case 8: return "INITIAL_SAVE";
		case 9: return "INVADERS";
		case 10: return "CAVEINS";
		case 11: return "ARTIFACTS";
		case 12: return "LOG_MAP_REJECTS";
		case 13: return "PAUSE_ON_LOAD";
		case 14: return "EMBARK_WARNING_ALWAYS";
		case 15: return "SHOW_ALL_HISTORY_IN_DWARF_MODE";
		case 16: return "TESTING_ARENA";
		case 17: return "WALKING_SPREADS_SPATTER_DWF";
		case 18: return "WALKING_SPREADS_SPATTER_ADV";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_pattern_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::pattern_type::pattern_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MONOTONE";
		case 1: return "STRIPES";
		case 2: return "IRIS_EYE";
		case 3: return "SPOTS";
		case 4: return "PUPIL_EYE";
		case 5: return "MOTTLED";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_occasion_schedule_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::occasion_schedule_type::occasion_schedule_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "DANCE_PERFORMANCE";
		case 1: return "MUSICAL_PERFORMANCE";
		case 2: return "POETRY_RECITAL";
		case 3: return "STORYTELLING";
		case 4: return "DANCE_COMPETITION";
		case 5: return "MUSICAL_COMPETITION";
		case 6: return "POETRY_COMPETITION";
		case 7: return "FOOT_RACE";
		case 8: return "anon_1";
		case 9: return "anon_2";
		case 10: return "WRESTLING_COMPETITION";
		case 11: return "THROWING_COMPETITION";
		case 12: return "GLADIATORY_COMPETITION";
		case 13: return "PROCESSION";
		case 14: return "CEREMONY";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_occasion_schedule_feature_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::occasion_schedule_feature::occasion_schedule_feature*>(p_address);
	switch (*m_value)
	{
		case 0: return "anon_1";
		case 1: return "anon_2";
		case 2: return "STORYTELLING";
		case 3: return "POETRY_RECITAL";
		case 4: return "MUSICAL_PERFORMANCE";
		case 5: return "DANCE_PERFORMANCE";
		case 6: return "anon_3";
		case 7: return "CRIERS_IN_FRONT";
		case 8: return "ORDER_OF_PRECEDENCE";
		case 9: return "BANNERS";
		case 10: return "IMAGES";
		case 11: return "anon_4";
		case 12: return "anon_5";
		case 13: return "ACROBATS";
		case 14: return "INCENSE_BURNING";
		case 15: return "COSTUMES";
		case 16: return "CANDLES";
		case 17: return "THE_GIVING_OF_ITEMS";
		case 18: return "THE_SACRIFICE_OF_ITEMS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_sell_category_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_sell_category::entity_sell_category*>(p_address);
	switch (*m_value)
	{
		case 0: return "Leather";
		case 1: return "ClothPlant";
		case 2: return "ClothSilk";
		case 3: return "Crafts";
		case 4: return "Wood";
		case 5: return "MetalBars";
		case 6: return "SmallCutGems";
		case 7: return "LargeCutGems";
		case 8: return "StoneBlocks";
		case 9: return "Seeds";
		case 10: return "Anvils";
		case 11: return "Weapons";
		case 12: return "TrainingWeapons";
		case 13: return "Ammo";
		case 14: return "TrapComponents";
		case 15: return "DiggingImplements";
		case 16: return "Bodywear";
		case 17: return "Headwear";
		case 18: return "Handwear";
		case 19: return "Footwear";
		case 20: return "Legwear";
		case 21: return "Shields";
		case 22: return "Toys";
		case 23: return "Instruments";
		case 24: return "Pets";
		case 25: return "Drinks";
		case 26: return "Cheese";
		case 27: return "Powders";
		case 28: return "Extracts";
		case 29: return "Meat";
		case 30: return "Fish";
		case 31: return "Plants";
		case 32: return "FruitsNuts";
		case 33: return "GardenVegetables";
		case 34: return "MeatFishRecipes";
		case 35: return "OtherRecipes";
		case 36: return "Stone";
		case 37: return "Cages";
		case 38: return "BagsLeather";
		case 39: return "BagsPlant";
		case 40: return "BagsSilk";
		case 41: return "ThreadPlant";
		case 42: return "ThreadSilk";
		case 43: return "RopesPlant";
		case 44: return "RopesSilk";
		case 45: return "Barrels";
		case 46: return "FlasksWaterskins";
		case 47: return "Quivers";
		case 48: return "Backpacks";
		case 49: return "Sand";
		case 50: return "Glass";
		case 51: return "Miscellaneous";
		case 52: return "Buckets";
		case 53: return "Splints";
		case 54: return "Crutches";
		case 55: return "Eggs";
		case 56: return "BagsYarn";
		case 57: return "RopesYarn";
		case 58: return "ClothYarn";
		case 59: return "ThreadYarn";
		case 60: return "Tools";
		case 61: return "Clay";
		case 62: return "Parchment";
		case 63: return "CupsMugsGoblets";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_historical_entity_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::historical_entity_type::historical_entity_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Civilization";
		case 1: return "SiteGovernment";
		case 2: return "VesselCrew";
		case 3: return "MigratingGroup";
		case 4: return "NomadicGroup";
		case 5: return "Religion";
		case 6: return "MilitaryUnit";
		case 7: return "Outcast";
		case 8: return "PerformanceTroupe";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_training_knowledge_level_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::training_knowledge_level::training_knowledge_level*>(p_address);
	switch (*m_value)
	{
		case 0: return "None";
		case 1: return "FewFacts";
		case 2: return "GeneralFamiliarity";
		case 3: return "Knowledgeable";
		case 4: return "Expert";
		case 5: return "Domesticated";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_position_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_position_flags::entity_position_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "IS_LAW_MAKER";
		case 1: return "ELECTED";
		case 2: return "DUTY_BOUND";
		case 3: return "MILITARY_SCREEN_ONLY";
		case 4: return "GENDER_MALE";
		case 5: return "GENDER_FEMALE";
		case 6: return "SUCCESSION_BY_HEIR";
		case 7: return "HAS_RESPONSIBILITIES";
		case 8: return "FLASHES";
		case 9: return "BRAG_ON_KILL";
		case 10: return "CHAT_WORTHY";
		case 11: return "DO_NOT_CULL";
		case 12: return "KILL_QUEST";
		case 13: return "IS_LEADER";
		case 14: return "IS_DIPLOMAT";
		case 15: return "EXPORTED_IN_LEGENDS";
		case 16: return "DETERMINES_COIN_DESIGN";
		case 17: return "ACCOUNT_EXEMPT";
		case 18: return "unk_12";
		case 19: return "unk_13";
		case 20: return "COLOR";
		case 21: return "RULES_FROM_LOCATION";
		case 22: return "MENIAL_WORK_EXEMPTION";
		case 23: return "MENIAL_WORK_EXEMPTION_SPOUSE";
		case 24: return "SLEEP_PRETENSION";
		case 25: return "PUNISHMENT_EXEMPTION";
		case 26: return "unk_1a";
		case 27: return "unk_1b";
		case 28: return "QUEST_GIVER";
		case 29: return "SPECIAL_BURIAL";
		case 30: return "REQUIRES_MARKET";
		case 31: return "unk_1f";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_material_category_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_material_category::entity_material_category*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Clothing";
		case 1: return "Leather";
		case 2: return "Cloth";
		case 3: return "Wood";
		case 4: return "Crafts";
		case 5: return "Stone";
		case 6: return "Improvement";
		case 7: return "Glass";
		case 8: return "Wood2";
		case 9: return "Bag";
		case 10: return "Cage";
		case 11: return "WeaponMelee";
		case 12: return "WeaponRanged";
		case 13: return "Ammo";
		case 14: return "Ammo2";
		case 15: return "Pick";
		case 16: return "Armor";
		case 17: return "Gem";
		case 18: return "Bone";
		case 19: return "Shell";
		case 20: return "Pearl";
		case 21: return "Ivory";
		case 22: return "Horn";
		case 23: return "Other";
		case 24: return "Anvil";
		case 25: return "Booze";
		case 26: return "Metal";
		case 27: return "PlantFiber";
		case 28: return "Silk";
		case 29: return "Wool";
		case 30: return "Furniture";
		case 31: return "MiscWood2";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_event_type::entity_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "invasion";
		case 1: return "abduction";
		case 2: return "incident";
		case 3: return "occupation";
		case 4: return "beast";
		case 5: return "group";
		case 6: return "harass";
		case 7: return "flee";
		case 8: return "abandon";
		case 9: return "reclaimed";
		case 10: return "founded";
		case 11: return "reclaiming";
		case 12: return "founding";
		case 13: return "leave";
		case 14: return "insurrection";
		case 15: return "insurrection_end";
		case 16: return "succession";
		case 17: return "claim";
		case 18: return "accept_tribute_offer";
		case 19: return "refuse_tribute_offer";
		case 20: return "accept_tribute_demand";
		case 21: return "refuse_tribute_demand";
		case 22: return "accept_peace_offer";
		case 23: return "refuse_peace_offer";
		case 24: return "cease_tribute_offer";
		case 25: return "artifact_in_site";
		case 26: return "artifact_in_subregion";
		case 27: return "artifact_in_feature_layer";
		case 28: return "artifact_in_inventory";
		case 29: return "artifact_not_in_site";
		case 30: return "artifact_not_in_subregion";
		case 31: return "artifact_not_in_feature_layer";
		case 32: return "artifact_not_in_inventory";
		case 33: return "artifact_was_destroyed";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_raw_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_raw_flags::entity_raw_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "CIV_CONTROLLABLE";
		case 1: return "INDIV_CONTROLLABLE";
		case 2: return "LAYER_LINKED";
		case 3: return "INDOOR_WOOD";
		case 4: return "WOOD_ARMOR";
		case 5: return "SIEGER";
		case 6: return "AMBUSHER";
		case 7: return "BABYSNATCHER";
		case 8: return "ITEM_THIEF";
		case 9: return "CLOTHING";
		case 10: return "CURRENCY_BY_YEAR";
		case 11: return "METAL_PREF";
		case 12: return "GEM_PREF";
		case 13: return "STONE_PREF";
		case 14: return "WOOD_WEAPONS";
		case 15: return "BUILDS_OUTDOOR_FORTIFICATIONS";
		case 16: return "RIVER_PRODUCTS";
		case 17: return "OCEAN_PRODUCTS";
		case 18: return "INDOOR_FARMING";
		case 19: return "OUTDOOR_FARMING";
		case 20: return "USE_CAVE_ANIMALS";
		case 21: return "USE_EVIL_ANIMALS";
		case 22: return "USE_ANIMAL_PRODUCTS";
		case 23: return "COMMON_DOMESTIC_PACK";
		case 24: return "COMMON_DOMESTIC_PULL";
		case 25: return "COMMON_DOMESTIC_MOUNT";
		case 26: return "COMMON_DOMESTIC_PET";
		case 27: return "SUBTERRANEAN_CLOTHING";
		case 28: return "USE_EVIL_WOOD";
		case 29: return "USE_GOOD_WOOD";
		case 30: return "USE_EVIL_PLANTS";
		case 31: return "USE_GOOD_PLANTS";
		case 32: return "USE_GOOD_ANIMALS";
		case 33: return "USE_ANY_PET_RACE";
		case 34: return "USE_MISC_PROCESSED_WOOD_PRODUCTS";
		case 35: return "IMPROVED_BOWS";
		case 36: return "OUTDOOR_WOOD";
		case 37: return "LOCAL_BANDITRY";
		case 38: return "BUILDS_OUTDOOR_TOMBS";
		case 39: return "INVADERS_IGNORE_NEUTRALS";
		case 40: return "AT_PEACE_WITH_WILDLIFE";
		case 41: return "EQUIPMENT_IMPROVEMENTS";
		case 42: return "ABUSE_BODIES";
		case 43: return "UNDEAD_CANDIDATE";
		case 44: return "GENERATED";
		case 45: return "SKULKING";
		case 46: return "anon_1";
		case 47: return "MERCHANT_NOBILITY";
		case 48: return "TREE_CAP_DIPLOMACY";
		case 49: return "DIPLOMAT_BODYGUARDS";
		case 50: return "MERCHANT_BODYGUARDS";
		case 51: return "INDOOR_ORCHARDS";
		case 52: return "OUTDOOR_ORCHARDS";
		case 53: return "WANDERER";
		case 54: return "BEAST_HUNTER";
		case 55: return "SCOUT";
		case 56: return "WILL_ACCEPT_TRIBUTE";
		case 57: return "INDOOR_GARDENS";
		case 58: return "OUTDOOR_GARDENS";
		case 59: return "MERCENARY";
		case 60: return "SITE_GUARDIAN";
		case 61: return "DIVINE_MAT_WEAPONS";
		case 62: return "DIVINE_MAT_ARMOR";
		case 63: return "DIVINE_MAT_CRAFTS";
		case 64: return "DIVINE_MAT_CLOTHING";
		case 65: return "GENERATE_KEYBOARD_INSTRUMENTS";
		case 66: return "GENERATE_STRINGED_INSTRUMENTS";
		case 67: return "GENERATE_WIND_INSTRUMENTS";
		case 68: return "GENERATE_PERCUSSION_INSTRUMENTS";
		case 69: return "GENERATE_POETIC_FORMS";
		case 70: return "GENERATE_MUSICAL_FORMS";
		case 71: return "GENERATE_DANCE_FORMS";
		case 72: return "SET_SCHOLARS_ON_VALUES_AND_JOBS";
		case 73: return "NO_ARTIFACT_CLAIMS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_site_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::site_type::site_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "PLAYER_FORTRESS";
		case 1: return "DARK_FORTRESS";
		case 2: return "CAVE";
		case 3: return "CAVE_DETAILED";
		case 4: return "TREE_CITY";
		case 5: return "CITY";
		case 6: return "anon_1";
		case 7: return "anon_2";
		case 8: return "FORTRESS";
		case 9: return "anon_3";
		case 10: return "MONUMENT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ethic_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::ethic_type::ethic_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "KILL_ENTITY_MEMBER";
		case 1: return "KILL_NEUTRAL";
		case 2: return "KILL_ENEMY";
		case 3: return "KILL_ANIMAL";
		case 4: return "KILL_PLANT";
		case 5: return "TORTURE_AS_EXAMPLE";
		case 6: return "TORTURE_FOR_INFORMATION";
		case 7: return "TORTURE_FOR_FUN";
		case 8: return "TORTURE_ANIMALS";
		case 9: return "TREASON";
		case 10: return "OATH_BREAKING";
		case 11: return "LYING";
		case 12: return "VANDALISM";
		case 13: return "TRESPASSING";
		case 14: return "THEFT";
		case 15: return "ASSAULT";
		case 16: return "SLAVERY";
		case 17: return "EAT_SAPIENT_OTHER";
		case 18: return "EAT_SAPIENT_KILL";
		case 19: return "MAKE_TROPHY_SAME_RACE";
		case 20: return "MAKE_TROPHY_SAPIENT";
		case 21: return "MAKE_TROPHY_ANIMAL";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ethic_response_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::ethic_response::ethic_response*>(p_address);
	switch (*m_value)
	{
		case 0: return "NOT_APPLICABLE";
		case 1: return "ACCEPTABLE";
		case 2: return "PERSONAL_MATTER";
		case 3: return "JUSTIFIED_IF_NO_REPERCUSSIONS";
		case 4: return "JUSTIFIED_IF_GOOD_REASON";
		case 5: return "JUSTIFIED_IF_EXTREME_REASON";
		case 6: return "JUSTIFIED_IF_SELF_DEFENSE";
		case 7: return "ONLY_IF_SANCTIONED";
		case 8: return "MISGUIDED";
		case 9: return "SHUN";
		case 10: return "APPALLING";
		case 11: return "PUNISH_REPRIMAND";
		case 12: return "PUNISH_SERIOUS";
		case 13: return "PUNISH_EXILE";
		case 14: return "PUNISH_CAPITAL";
		case 15: return "UNTHINKABLE";
		case 16: return "REQUIRED";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_name_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_name_type::entity_name_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "OTHER";
		case 1: return "CIV";
		case 2: return "SITE";
		case 3: return "VESSEL";
		case 4: return "MILITARY_UNIT";
		case 5: return "RELIGION";
		case 6: return "TEMPLE";
		case 7: return "WAR";
		case 8: return "BATTLE";
		case 9: return "SIEGE";
		case 10: return "ROAD";
		case 11: return "BRIDGE";
		case 12: return "TUNNEL";
		case 13: return "WALL";
		case 14: return "LIBRARY";
		case 15: return "FESTIVAL";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_position_raw_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_position_raw_flags::entity_position_raw_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "SITE";
		case 1: return "ELECTED";
		case 2: return "CONQUERED_SITE";
		case 3: return "MILITARY_SCREEN_ONLY";
		case 4: return "GENDER_MALE";
		case 5: return "GENDER_FEMALE";
		case 6: return "SUCCESSION_BY_HEIR";
		case 7: return "EXPORTED_IN_LEGENDS";
		case 8: return "FLASHES";
		case 9: return "BRAG_ON_KILL";
		case 10: return "CHAT_WORTHY";
		case 11: return "DO_NOT_CULL";
		case 12: return "KILL_QUEST";
		case 13: return "DETERMINES_COIN_DESIGN";
		case 14: return "ACCOUNT_EXEMPT";
		case 15: return "DUTY_BOUND";
		case 16: return "COLOR";
		case 17: return "RULES_FROM_LOCATION";
		case 18: return "MENIAL_WORK_EXEMPTION";
		case 19: return "MENIAL_WORK_EXEMPTION_SPOUSE";
		case 20: return "SLEEP_PRETENSION";
		case 21: return "PUNISHMENT_EXEMPTION";
		case 22: return "QUEST_GIVER";
		case 23: return "SPECIAL_BURIAL";
		case 24: return "REQUIRES_MARKET";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_position_responsibility_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_position_responsibility::entity_position_responsibility*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "LAW_MAKING";
		case 1: return "LAW_ENFORCEMENT";
		case 2: return "RECEIVE_DIPLOMATS";
		case 3: return "MEET_WORKERS";
		case 4: return "MANAGE_PRODUCTION";
		case 5: return "TRADE";
		case 6: return "ACCOUNTING";
		case 7: return "ESTABLISH_COLONY_TRADE_AGREEMENTS";
		case 8: return "MAKE_INTRODUCTIONS";
		case 9: return "MAKE_PEACE_AGREEMENTS";
		case 10: return "MAKE_TOPIC_AGREEMENTS";
		case 11: return "COLLECT_TAXES";
		case 12: return "ESCORT_TAX_COLLECTOR";
		case 13: return "EXECUTIONS";
		case 14: return "TAME_EXOTICS";
		case 15: return "RELIGION";
		case 16: return "ATTACK_ENEMIES";
		case 17: return "PATROL_TERRITORY";
		case 18: return "MILITARY_GOALS";
		case 19: return "MILITARY_STRATEGY";
		case 20: return "UPGRADE_SQUAD_EQUIPMENT";
		case 21: return "EQUIPMENT_MANIFESTS";
		case 22: return "SORT_AMMUNITION";
		case 23: return "BUILD_MORALE";
		case 24: return "HEALTH_MANAGEMENT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_weather_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::weather_type::weather_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "None";
		case 1: return "Rain";
		case 2: return "Snow";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_game_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::game_mode::game_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "DWARF";
		case 1: return "ADVENTURE";
		case 2: return "num";
		case 3: return "NONE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_game_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::game_type::game_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "DWARF_MAIN";
		case 1: return "ADVENTURE_MAIN";
		case 2: return "VIEW_LEGENDS";
		case 3: return "DWARF_RECLAIM";
		case 4: return "DWARF_ARENA";
		case 5: return "ADVENTURE_ARENA";
		case 6: return "ADVENTURE_DUNGEON";
		case 7: return "DWARF_TUTORIAL";
		case 8: return "DWARF_UNRETIRE";
		case 9: return "ADVENTURE_WORLD_DEBUG";
		case 10: return "num";
		case 11: return "NONE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_lever_target_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::lever_target_type::lever_target_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 66: return "BarsVertical";
		case 70: return "BarsFloor";
		case 83: return "SpearsSpikes";
		case 84: return "TrackStop";
		case 97: return "GearAssembly";
		case 98: return "Bridge";
		case 99: return "Chain";
		case 100: return "Door";
		case 101: return "EncrustGems";
		case 102: return "Floodgate";
		case 103: return "GrateFloor";
		case 104: return "Hatch";
		case 106: return "Cage";
		case 115: return "Support";
		case 119: return "GrateWall";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_zoom_commands_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::zoom_commands::zoom_commands*>(p_address);
	switch (*m_value)
	{
		case 0: return "zoom_in";
		case 1: return "zoom_out";
		case 2: return "zoom_reset";
		case 3: return "zoom_fullscreen";
		case 4: return "zoom_resetgrid";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_reputation_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::reputation_type::reputation_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Hero";
		case 1: return "Buddy";
		case 2: return "Grudge";
		case 3: return "AnimalPartner";
		case 4: return "Brawler";
		case 5: return "Psycho";
		case 6: return "TradePartner";
		case 7: return "Friendly";
		case 8: return "Killer";
		case 9: return "Murderer";
		case 10: return "Comrade";
		case 11: return "RespectedGroup";
		case 12: return "HatedGroup";
		case 13: return "EnemyFighter";
		case 14: return "FriendlyFighter";
		case 15: return "Bully";
		case 16: return "Brigand";
		case 17: return "LoyalSoldier";
		case 18: return "Monster";
		case 19: return "Storyteller";
		case 20: return "Poet";
		case 21: return "Bard";
		case 22: return "Dancer";
		case 23: return "Quarreler";
		case 24: return "Flatterer";
		case 25: return "Hunter";
		case 26: return "ProtectorOfWeak";
		case 27: return "TreasureHunter";
		case 28: return "Thief";
		case 29: return "InformationSource";
		case 30: return "PreserverOfKnowledge";
		case 31: return "Intruder";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_histfig_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::histfig_flags::histfig_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "reveal_artwork";
		case 1: return "equipment_created";
		case 2: return "deity";
		case 3: return "force";
		case 4: return "skeletal_deity";
		case 5: return "rotting_deity";
		case 6: return "worldgen_acted";
		case 7: return "ghost";
		case 8: return "skin_destroyed";
		case 9: return "meat_destroyed";
		case 10: return "bones_destroyed";
		case 11: return "brag_on_kill";
		case 12: return "kill_quest";
		case 13: return "chatworthy";
		case 14: return "flashes";
		case 15: return "never_cull";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_histfig_relationship_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::histfig_relationship_type::histfig_relationship_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Mother";
		case 1: return "Father";
		case 2: return "Parent";
		case 3: return "Husband";
		case 4: return "Wife";
		case 5: return "Spouse";
		case 6: return "SonEldest";
		case 7: return "SonEldest2";
		case 8: return "SonEldest3";
		case 9: return "SonEldest4";
		case 10: return "SonEldest5";
		case 11: return "SonEldest6";
		case 12: return "SonEldest7";
		case 13: return "SonEldest8";
		case 14: return "SonEldest9";
		case 15: return "SonEldest10";
		case 16: return "Son";
		case 17: return "SonYoungest";
		case 18: return "SonOnly";
		case 19: return "DaughterEldest";
		case 20: return "DaughterEldest2";
		case 21: return "DaughterEldest3";
		case 22: return "DaughterEldest4";
		case 23: return "DaughterEldest5";
		case 24: return "DaughterEldest6";
		case 25: return "DaughterEldest7";
		case 26: return "DaughterEldest8";
		case 27: return "DaughterEldest9";
		case 28: return "DaughterEldest10";
		case 29: return "Daughter";
		case 30: return "DaughterOnly";
		case 31: return "DaughterYoungest";
		case 32: return "ChildEldest";
		case 33: return "ChildEldest2";
		case 34: return "ChildEldest3";
		case 35: return "ChildEldest4";
		case 36: return "ChildEldest5";
		case 37: return "ChildEldest6";
		case 38: return "ChildEldest7";
		case 39: return "ChildEldest8";
		case 40: return "ChildEldest9";
		case 41: return "ChildEldest10";
		case 42: return "Child";
		case 43: return "ChildYoungest";
		case 44: return "ChildOnly";
		case 45: return "PaternalGrandmother";
		case 46: return "PaternalGrandfather";
		case 47: return "MaternalGrandmother";
		case 48: return "MaternalGrandfather";
		case 49: return "Grandmother";
		case 50: return "Grandfather";
		case 51: return "Grandparent";
		case 52: return "OlderBrother";
		case 53: return "OlderSister";
		case 54: return "OlderSibling";
		case 55: return "YoungerBrother";
		case 56: return "YoungerSister";
		case 57: return "YoungerSibling";
		case 58: return "Cousin";
		case 59: return "Aunt";
		case 60: return "Uncle";
		case 61: return "Niece";
		case 62: return "Nephew";
		case 63: return "Sibling";
		case 64: return "Grandchild";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_mental_picture_property_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::mental_picture_property_type::mental_picture_property_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "DATE";
		case 1: return "ACTION";
		case 2: return "TOOL";
		case 3: return "EMOTION";
		case 4: return "COLOR_PATTERN";
		case 5: return "SHAPE";
		case 6: return "ADJECTIVE";
		case 7: return "POSITION";
		case 8: return "TIME";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_mental_picture_element_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::mental_picture_element_type::mental_picture_element_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "HF";
		case 1: return "SITE";
		case 2: return "REGION";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::history_event_type::history_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "WAR_ATTACKED_SITE";
		case 1: return "WAR_DESTROYED_SITE";
		case 2: return "CREATED_SITE";
		case 3: return "HIST_FIGURE_DIED";
		case 4: return "ADD_HF_ENTITY_LINK";
		case 5: return "REMOVE_HF_ENTITY_LINK";
		case 6: return "FIRST_CONTACT";
		case 7: return "FIRST_CONTACT_FAILED";
		case 8: return "TOPICAGREEMENT_CONCLUDED";
		case 9: return "TOPICAGREEMENT_REJECTED";
		case 10: return "TOPICAGREEMENT_MADE";
		case 11: return "WAR_PEACE_ACCEPTED";
		case 12: return "WAR_PEACE_REJECTED";
		case 13: return "DIPLOMAT_LOST";
		case 14: return "AGREEMENTS_VOIDED";
		case 15: return "MERCHANT";
		case 16: return "ARTIFACT_HIDDEN";
		case 17: return "ARTIFACT_POSSESSED";
		case 18: return "ARTIFACT_CREATED";
		case 19: return "ARTIFACT_LOST";
		case 20: return "ARTIFACT_FOUND";
		case 21: return "ARTIFACT_RECOVERED";
		case 22: return "ARTIFACT_DROPPED";
		case 23: return "RECLAIM_SITE";
		case 24: return "HF_DESTROYED_SITE";
		case 25: return "SITE_DIED";
		case 26: return "SITE_RETIRED";
		case 27: return "ENTITY_CREATED";
		case 28: return "ENTITY_ACTION";
		case 29: return "ENTITY_INCORPORATED";
		case 30: return "CREATED_BUILDING";
		case 31: return "REPLACED_BUILDING";
		case 32: return "ADD_HF_SITE_LINK";
		case 33: return "REMOVE_HF_SITE_LINK";
		case 34: return "ADD_HF_HF_LINK";
		case 35: return "REMOVE_HF_HF_LINK";
		case 36: return "ENTITY_RAZED_BUILDING";
		case 37: return "MASTERPIECE_CREATED_ARCH_DESIGN";
		case 38: return "MASTERPIECE_CREATED_ARCH_CONSTRUCT";
		case 39: return "MASTERPIECE_CREATED_ITEM";
		case 40: return "MASTERPIECE_CREATED_DYE_ITEM";
		case 41: return "MASTERPIECE_CREATED_ITEM_IMPROVEMENT";
		case 42: return "MASTERPIECE_CREATED_FOOD";
		case 43: return "MASTERPIECE_CREATED_ENGRAVING";
		case 44: return "MASTERPIECE_LOST";
		case 45: return "CHANGE_HF_STATE";
		case 46: return "CHANGE_HF_JOB";
		case 47: return "WAR_FIELD_BATTLE";
		case 48: return "WAR_PLUNDERED_SITE";
		case 49: return "WAR_SITE_NEW_LEADER";
		case 50: return "WAR_SITE_TRIBUTE_FORCED";
		case 51: return "WAR_SITE_TAKEN_OVER";
		case 52: return "BODY_ABUSED";
		case 53: return "HIST_FIGURE_ABDUCTED";
		case 54: return "ITEM_STOLEN";
		case 55: return "HF_RAZED_BUILDING";
		case 56: return "CREATURE_DEVOURED";
		case 57: return "HIST_FIGURE_WOUNDED";
		case 58: return "HIST_FIGURE_SIMPLE_BATTLE_EVENT";
		case 59: return "CREATED_WORLD_CONSTRUCTION";
		case 60: return "HIST_FIGURE_REUNION";
		case 61: return "HIST_FIGURE_REACH_SUMMIT";
		case 62: return "HIST_FIGURE_TRAVEL";
		case 63: return "HIST_FIGURE_NEW_PET";
		case 64: return "ASSUME_IDENTITY";
		case 65: return "CREATE_ENTITY_POSITION";
		case 66: return "CHANGE_CREATURE_TYPE";
		case 67: return "HIST_FIGURE_REVIVED";
		case 68: return "HF_LEARNS_SECRET";
		case 69: return "CHANGE_HF_BODY_STATE";
		case 70: return "HF_ACT_ON_BUILDING";
		case 71: return "HF_DOES_INTERACTION";
		case 72: return "HF_CONFRONTED";
		case 73: return "ENTITY_LAW";
		case 74: return "HF_GAINS_SECRET_GOAL";
		case 75: return "ARTIFACT_STORED";
		case 76: return "AGREEMENT_FORMED";
		case 77: return "SITE_DISPUTE";
		case 78: return "AGREEMENT_CONCLUDED";
		case 79: return "INSURRECTION_STARTED";
		case 80: return "INSURRECTION_ENDED";
		case 81: return "HF_ATTACKED_SITE";
		case 82: return "PERFORMANCE";
		case 83: return "COMPETITION";
		case 84: return "PROCESSION";
		case 85: return "CEREMONY";
		case 86: return "KNOWLEDGE_DISCOVERED";
		case 87: return "ARTIFACT_TRANSFORMED";
		case 88: return "ARTIFACT_DESTROYED";
		case 89: return "HF_RELATIONSHIP_DENIED";
		case 90: return "REGIONPOP_INCORPORATED_INTO_ENTITY";
		case 91: return "POETIC_FORM_CREATED";
		case 92: return "MUSICAL_FORM_CREATED";
		case 93: return "DANCE_FORM_CREATED";
		case 94: return "WRITTEN_CONTENT_COMPOSED";
		case 95: return "CHANGE_HF_MOOD";
		case 96: return "ARTIFACT_CLAIM_FORMED";
		case 97: return "ARTIFACT_GIVEN";
		case 98: return "HF_ACT_ON_ARTIFACT";
		case 99: return "HF_RECRUITED_UNIT_TYPE_FOR_ENTITY";
		case 100: return "HFS_FORMED_REPUTATION_RELATIONSHIP";
		case 101: return "ARTIFACT_COPIED";
		case 102: return "SNEAK_INTO_SITE";
		case 103: return "SPOTTED_LEAVING_SITE";
		case 104: return "ENTITY_SEARCHED_SITE";
		case 105: return "HF_FREED";
		case 106: return "HIST_FIGURE_SIMPLE_ACTION";
		case 107: return "ENTITY_RAMPAGED_IN_SITE";
		case 108: return "ENTITY_FLED_SITE";
		case 109: return "TACTICAL_SITUATION";
		case 110: return "SQUAD_VS_SQUAD";
		case 111: return "SITE_SURRENDERED";
		case 112: return "ENTITY_EXPELS_HF";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_reason_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::history_event_reason::history_event_reason*>(p_address);
	switch (*m_value)
	{
		case -1: return "none";
		case 0: return "insurrection";
		case 1: return "adventure";
		case 2: return "guide";
		case 3: return "rescued";
		case 4: return "sphere_alignment";
		case 5: return "maintain_balance_in_universe";
		case 6: return "highlight_boundaries_between_worlds";
		case 7: return "sow_the_seeds_of_chaos_in_the_world";
		case 8: return "provide_opportunities_for_courage";
		case 9: return "bring_death_to_the_world";
		case 10: return "liked_appearance";
		case 11: return "because_it_was_destined";
		case 12: return "great_fortresses_built_and_tested";
		case 13: return "whim";
		case 14: return "bring_misery_to_the_world";
		case 15: return "bring_murder_to_the_world";
		case 16: return "bring_nightmares_into_reality";
		case 17: return "bring_thralldom_to_the_world";
		case 18: return "bring_torture_to_the_world";
		case 19: return "provide_opportunities_for_acts_of_valor";
		case 20: return "bring_war_to_the_world";
		case 21: return "find_relative";
		case 22: return "offer_condolences";
		case 23: return "be_brought_to_safety";
		case 24: return "help_with_rescue";
		case 25: return "insufficient_work";
		case 26: return "work_request";
		case 27: return "make_weapon";
		case 28: return "vent_at_boss";
		case 29: return "cry_on_boss";
		case 30: return "should_have_reached_goal";
		case 31: return "insufficient_progress_toward_goal";
		case 32: return "going_wrong_direction";
		case 33: return "arrived_at_location";
		case 34: return "entity_no_longer_rules";
		case 35: return "left_site";
		case 36: return "reunited_with_loved_one";
		case 37: return "violent_disagreement";
		case 38: return "adopted";
		case 39: return "true_name_invocation";
		case 40: return "arrived_at_person";
		case 41: return "eradicate_beasts";
		case 42: return "entertain_people";
		case 43: return "make_a_living_as_a_warrior";
		case 44: return "study";
		case 45: return "flight";
		case 46: return "scholarship";
		case 47: return "be_with_master";
		case 48: return "become_citizen";
		case 49: return "prefers_working_alone";
		case 50: return "jealousy";
		case 51: return "glorify_hf";
		case 52: return "have_not_performed";
		case 53: return "prevented_from_leaving";
		case 54: return "curiosity";
		case 55: return "hire_on_as_mercenary";
		case 56: return "hire_on_as_performer";
		case 57: return "hire_on_as_scholar";
		case 58: return "drink";
		case 59: return "admire_architecture";
		case 60: return "pray";
		case 61: return "relax";
		case 62: return "danger";
		case 63: return "cannot_find_artifact";
		case 64: return "failed_mood";
		case 65: return "lack_of_sleep";
		case 66: return "trapped_in_cage";
		case 67: return "great_deal_of_stress";
		case 68: return "unable_to_leave_location";
		case 69: return "sanctify_hf";
		case 70: return "artifact_is_heirloom_of_family_hfid";
		case 71: return "cement_bonds_of_friendship";
		case 72: return "as_a_symbol_of_everlasting_peace";
		case 73: return "on_a_pilgrimage";
		case 74: return "gather_information";
		case 75: return "seek_sanctuary";
		case 76: return "part_of_trade_negotiation";
		case 77: return "artifact_is_symbol_of_entity_position";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_death_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::death_type::death_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "OLD_AGE";
		case 1: return "HUNGER";
		case 2: return "THIRST";
		case 3: return "SHOT";
		case 4: return "BLEED";
		case 5: return "DROWN";
		case 6: return "SUFFOCATE";
		case 7: return "STRUCK_DOWN";
		case 8: return "SCUTTLE";
		case 9: return "COLLISION";
		case 10: return "MAGMA";
		case 11: return "MAGMA_MIST";
		case 12: return "DRAGONFIRE";
		case 13: return "FIRE";
		case 14: return "SCALD";
		case 15: return "CAVEIN";
		case 16: return "DRAWBRIDGE";
		case 17: return "FALLING_ROCKS";
		case 18: return "CHASM";
		case 19: return "CAGE";
		case 20: return "MURDER";
		case 21: return "TRAP";
		case 22: return "VANISH";
		case 23: return "QUIT";
		case 24: return "ABANDON";
		case 25: return "HEAT";
		case 26: return "COLD";
		case 27: return "SPIKE";
		case 28: return "ENCASE_LAVA";
		case 29: return "ENCASE_MAGMA";
		case 30: return "ENCASE_ICE";
		case 31: return "BEHEAD";
		case 32: return "CRUCIFY";
		case 33: return "BURY_ALIVE";
		case 34: return "DROWN_ALT";
		case 35: return "BURN_ALIVE";
		case 36: return "FEED_TO_BEASTS";
		case 37: return "HACK_TO_PIECES";
		case 38: return "LEAVE_OUT_IN_AIR";
		case 39: return "BOIL";
		case 40: return "MELT";
		case 41: return "CONDENSE";
		case 42: return "SOLIDIFY";
		case 43: return "INFECTION";
		case 44: return "MEMORIALIZE";
		case 45: return "SCARE";
		case 46: return "DARKNESS";
		case 47: return "COLLAPSE";
		case 48: return "DRAIN_BLOOD";
		case 49: return "SLAUGHTER";
		case 50: return "VEHICLE";
		case 51: return "FALLING_OBJECT";
		case 52: return "LEAPT_FROM_HEIGHT";
		case 53: return "DROWN_ALT2";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_action_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_action_type::entity_action_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "entity_primary_criminals";
		case 1: return "entity_relocate";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_masterpiece_loss_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::masterpiece_loss_type::masterpiece_loss_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MELT";
		case 1: return "MAGMA";
		case 2: return "FORTIFICATION";
		case 3: return "MINING";
		case 4: return "CAVEIN";
		case 5: return "VEGETATION";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_hist_figure_woundedst__T_injury_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::history_event_hist_figure_woundedst::T_injury_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Smash";
		case 1: return "Slash";
		case 2: return "Stab";
		case 3: return "Rip";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_simple_battle_subtype_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::history_event_simple_battle_subtype::history_event_simple_battle_subtype*>(p_address);
	switch (*m_value)
	{
		case 0: return "SCUFFLE";
		case 1: return "ATTACK";
		case 2: return "SURPRISE";
		case 3: return "AMBUSH";
		case 4: return "HAPPEN_UPON";
		case 5: return "CORNER";
		case 6: return "CONFRONT";
		case 7: return "LOSE_AFTER_RECEIVE_WOUND";
		case 8: return "LOSE_AFTER_INFLICT_WOUND";
		case 9: return "LOSE_AFTER_EXCHANGE_WOUND";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_histfig_body_state_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::histfig_body_state::histfig_body_state*>(p_address);
	switch (*m_value)
	{
		case 0: return "Active";
		case 1: return "BuriedAtSite";
		case 2: return "UnburiedAtBattlefield";
		case 3: return "UnburiedAtSubregion";
		case 4: return "UnburiedAtFeatureLayer";
		case 5: return "EntombedAtSite";
		case 6: return "UnburiedAtSite";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_hf_act_on_buildingst__T_action_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::history_event_hf_act_on_buildingst::T_action*>(p_address);
	switch (*m_value)
	{
		case 0: return "Profane";
		case 1: return "Disturb";
		case 2: return "PrayedInside";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_site_dispute_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::site_dispute_type::site_dispute_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Territory";
		case 1: return "WaterRights";
		case 2: return "GrazingRights";
		case 3: return "FishingRights";
		case 4: return "RightsOfWay";
		case 5: return "LivestockOwnership";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_insurrection_outcome_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::insurrection_outcome::insurrection_outcome*>(p_address);
	switch (*m_value)
	{
		case 0: return "LeadershipOverthrown";
		case 1: return "PopulationGone";
		case 2: return "Crushed";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_hf_act_on_artifactst__T_action_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::history_event_hf_act_on_artifactst::T_action*>(p_address);
	switch (*m_value)
	{
		case 0: return "View";
		case 1: return "AskAbout";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tactical_situation_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tactical_situation::tactical_situation*>(p_address);
	switch (*m_value)
	{
		case 0: return "attacker_strongly_favored";
		case 1: return "attacker_favored";
		case 2: return "attacker_slightly_favored";
		case 3: return "defender_strongly_favored";
		case 4: return "defender_favored";
		case 5: return "defender_slightly_favored";
		case 6: return "neither_favored";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_collection_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::history_event_collection_type::history_event_collection_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "WAR";
		case 1: return "BATTLE";
		case 2: return "DUEL";
		case 3: return "SITE_CONQUERED";
		case 4: return "ABDUCTION";
		case 5: return "THEFT";
		case 6: return "BEAST_ATTACK";
		case 7: return "JOURNEY";
		case 8: return "INSURRECTION";
		case 9: return "OCCASION";
		case 10: return "PERFORMANCE";
		case 11: return "COMPETITION";
		case 12: return "PROCESSION";
		case 13: return "CEREMONY";
		case 14: return "PURGE";
		case 15: return "RAID";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_era_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::era_type::era_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "ThreePowers";
		case 1: return "TwoPowers";
		case 2: return "OnePower";
		case 3: return "Myth";
		case 4: return "Legends";
		case 5: return "Twilight";
		case 6: return "FairyTales";
		case 7: return "Race";
		case 8: return "Heroes";
		case 9: return "Golden";
		case 10: return "Death";
		case 11: return "Civilization";
		case 12: return "Emptiness";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_init_display_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::init_display_flags::init_display_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "USE_GRAPHICS";
		case 1: return "BLACK_SPACE";
		case 2: return "PARTIAL_PRINT";
		case 3: return "FRAME_BUFFER";
		case 4: return "SINGLE_BUFFER";
		case 5: return "ACCUM_BUFFER";
		case 6: return "VBO";
		case 7: return "RENDER_2D";
		case 8: return "RENDER_2DHW";
		case 9: return "RENDER_2DASYNC";
		case 10: return "UNUSED_01_08";
		case 11: return "TEXT";
		case 12: return "SHADER";
		case 13: return "NOT_RESIZABLE";
		case 14: return "ARB_SYNC";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_init_media_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::init_media_flags::init_media_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "SOUND_OFF";
		case 1: return "INTRO_OFF";
		case 2: return "COMPRESS_SAVES";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_init_input_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::init_input_flags::init_input_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "MOUSE_OFF";
		case 1: return "MOUSE_PICTURE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_init_window_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::init_window_flags::init_window_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "TOPMOST";
		case 1: return "VSYNC_ON";
		case 2: return "VSYNC_OFF";
		case 3: return "TEXTURE_LINEAR";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interaction_effect_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::interaction_effect_type::interaction_effect_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "ANIMATE";
		case 1: return "ADD_SYNDROME";
		case 2: return "RESURRECT";
		case 3: return "CLEAN";
		case 4: return "CONTACT";
		case 5: return "MATERIAL_EMISSION";
		case 6: return "HIDE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interaction_effect_location_hint_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::interaction_effect_location_hint::interaction_effect_location_hint*>(p_address);
	switch (*m_value)
	{
		case 0: return "IN_WATER";
		case 1: return "IN_MAGMA";
		case 2: return "NO_WATER";
		case 3: return "NO_MAGMA";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interaction_source_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::interaction_source_type::interaction_source_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "REGION";
		case 1: return "SECRET";
		case 2: return "DISTURBANCE";
		case 3: return "DEITY";
		case 4: return "ATTACK";
		case 5: return "INGESTION";
		case 6: return "CREATURE_ACTION";
		case 7: return "UNDERGROUND_SPECIAL";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interaction_source_usage_hint_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::interaction_source_usage_hint::interaction_source_usage_hint*>(p_address);
	switch (*m_value)
	{
		case 0: return "MAJOR_CURSE";
		case 1: return "GREETING";
		case 2: return "CLEAN_SELF";
		case 3: return "CLEAN_FRIEND";
		case 4: return "ATTACK";
		case 5: return "FLEEING";
		case 6: return "NEGATIVE_SOCIAL_RESPONSE";
		case 7: return "TORMENT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interaction_target_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::interaction_target_type::interaction_target_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "CORPSE";
		case 1: return "CREATURE";
		case 2: return "MATERIAL";
		case 3: return "LOCATION";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interaction_target_location_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::interaction_target_location_type::interaction_target_location_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "CONTEXT_NONE";
		case 0: return "CONTEXT_REGION";
		case 1: return "CONTEXT_CREATURE";
		case 2: return "CONTEXT_ITEM";
		case 3: return "CONTEXT_BP";
		case 4: return "CONTEXT_LOCATION";
		case 5: return "CONTEXT_CREATURE_OR_LOCATION";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_breath_attack_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::breath_attack_type::breath_attack_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "TRAILING_DUST_FLOW";
		case 1: return "TRAILING_VAPOR_FLOW";
		case 2: return "TRAILING_GAS_FLOW";
		case 3: return "SOLID_GLOB";
		case 4: return "LIQUID_GLOB";
		case 5: return "UNDIRECTED_GAS";
		case 6: return "UNDIRECTED_VAPOR";
		case 7: return "UNDIRECTED_DUST";
		case 8: return "WEB_SPRAY";
		case 9: return "DRAGONFIRE";
		case 10: return "FIREJET";
		case 11: return "FIREBALL";
		case 12: return "WEATHER_CREEPING_GAS";
		case 13: return "WEATHER_CREEPING_VAPOR";
		case 14: return "WEATHER_CREEPING_DUST";
		case 15: return "WEATHER_FALLING_MATERIAL";
		case 16: return "SPATTER_POWDER";
		case 17: return "SPATTER_LIQUID";
		case 18: return "UNDIRECTED_ITEM_CLOUD";
		case 19: return "TRAILING_ITEM_FLOW";
		case 20: return "OTHER";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_item_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::item_type::item_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "BAR";
		case 1: return "SMALLGEM";
		case 2: return "BLOCKS";
		case 3: return "ROUGH";
		case 4: return "BOULDER";
		case 5: return "WOOD";
		case 6: return "DOOR";
		case 7: return "FLOODGATE";
		case 8: return "BED";
		case 9: return "CHAIR";
		case 10: return "CHAIN";
		case 11: return "FLASK";
		case 12: return "GOBLET";
		case 13: return "INSTRUMENT";
		case 14: return "TOY";
		case 15: return "WINDOW";
		case 16: return "CAGE";
		case 17: return "BARREL";
		case 18: return "BUCKET";
		case 19: return "ANIMALTRAP";
		case 20: return "TABLE";
		case 21: return "COFFIN";
		case 22: return "STATUE";
		case 23: return "CORPSE";
		case 24: return "WEAPON";
		case 25: return "ARMOR";
		case 26: return "SHOES";
		case 27: return "SHIELD";
		case 28: return "HELM";
		case 29: return "GLOVES";
		case 30: return "BOX";
		case 31: return "BIN";
		case 32: return "ARMORSTAND";
		case 33: return "WEAPONRACK";
		case 34: return "CABINET";
		case 35: return "FIGURINE";
		case 36: return "AMULET";
		case 37: return "SCEPTER";
		case 38: return "AMMO";
		case 39: return "CROWN";
		case 40: return "RING";
		case 41: return "EARRING";
		case 42: return "BRACELET";
		case 43: return "GEM";
		case 44: return "ANVIL";
		case 45: return "CORPSEPIECE";
		case 46: return "REMAINS";
		case 47: return "MEAT";
		case 48: return "FISH";
		case 49: return "FISH_RAW";
		case 50: return "VERMIN";
		case 51: return "PET";
		case 52: return "SEEDS";
		case 53: return "PLANT";
		case 54: return "SKIN_TANNED";
		case 55: return "PLANT_GROWTH";
		case 56: return "THREAD";
		case 57: return "CLOTH";
		case 58: return "TOTEM";
		case 59: return "PANTS";
		case 60: return "BACKPACK";
		case 61: return "QUIVER";
		case 62: return "CATAPULTPARTS";
		case 63: return "BALLISTAPARTS";
		case 64: return "SIEGEAMMO";
		case 65: return "BALLISTAARROWHEAD";
		case 66: return "TRAPPARTS";
		case 67: return "TRAPCOMP";
		case 68: return "DRINK";
		case 69: return "POWDER_MISC";
		case 70: return "CHEESE";
		case 71: return "FOOD";
		case 72: return "LIQUID_MISC";
		case 73: return "COIN";
		case 74: return "GLOB";
		case 75: return "ROCK";
		case 76: return "PIPE_SECTION";
		case 77: return "HATCH_COVER";
		case 78: return "GRATE";
		case 79: return "QUERN";
		case 80: return "MILLSTONE";
		case 81: return "SPLINT";
		case 82: return "CRUTCH";
		case 83: return "TRACTION_BENCH";
		case 84: return "ORTHOPEDIC_CAST";
		case 85: return "TOOL";
		case 86: return "SLAB";
		case 87: return "EGG";
		case 88: return "BOOK";
		case 89: return "SHEET";
		case 90: return "BRANCH";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ammo_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::ammo_flags::ammo_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "HAS_EDGE_ATTACK";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_armor_general_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::armor_general_flags::armor_general_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "SOFT";
		case 1: return "HARD";
		case 2: return "METAL";
		case 3: return "BARRED";
		case 4: return "SCALED";
		case 5: return "LEATHER";
		case 6: return "SHAPED";
		case 7: return "CHAIN_METAL_TEXT";
		case 8: return "STRUCTURAL_ELASTICITY_WOVEN_THREAD";
		case 9: return "STRUCTURAL_ELASTICITY_CHAIN_METAL";
		case 10: return "STRUCTURAL_ELASTICITY_CHAIN_ALL";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_armor_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::armor_flags::armor_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "METAL_ARMOR_LEVELS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_gloves_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::gloves_flags::gloves_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "METAL_ARMOR_LEVELS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_helm_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::helm_flags::helm_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "METAL_ARMOR_LEVELS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_instrument_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::instrument_flags::instrument_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "INDEFINITE_PITCH";
		case 1: return "PLACED_AS_BUILDING";
		case 2: return "METAL_MAT";
		case 3: return "STONE_MAT";
		case 4: return "WOOD_MAT";
		case 5: return "GLASS_MAT";
		case 6: return "CERAMIC_MAT";
		case 7: return "SHELL_MAT";
		case 8: return "BONE_MAT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_sound_production_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::sound_production_type::sound_production_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "PLUCKED_BY_BP";
		case 1: return "PLUCKED";
		case 2: return "BOWED";
		case 3: return "STRUCK_BY_BP";
		case 4: return "STRUCK";
		case 5: return "VIBRATE_BP_AGAINST_OPENING";
		case 6: return "BLOW_AGAINST_FIPPLE";
		case 7: return "BLOW_OVER_OPENING_SIDE";
		case 8: return "BLOW_OVER_OPENING_END";
		case 9: return "BLOW_OVER_SINGLE_REED";
		case 10: return "BLOW_OVER_DOUBLE_REED";
		case 11: return "BLOW_OVER_FREE_REED";
		case 12: return "STRUCK_TOGETHER";
		case 13: return "SHAKEN";
		case 14: return "SCRAPED";
		case 15: return "FRICTION";
		case 16: return "RESONATOR";
		case 17: return "BAG_OVER_REED";
		case 18: return "AIR_OVER_REED";
		case 19: return "AIR_OVER_FREE_REED";
		case 20: return "AIR_AGAINST_FIPPLE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_pitch_choice_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::pitch_choice_type::pitch_choice_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MEMBRANE_POSITION";
		case 1: return "SUBPART_CHOICE";
		case 2: return "KEYBOARD";
		case 3: return "STOPPING_FRET";
		case 4: return "STOPPING_AGAINST_BODY";
		case 5: return "STOPPING_HOLE";
		case 6: return "STOPPING_HOLE_KEY";
		case 7: return "SLIDE";
		case 8: return "HARMONIC_SERIES";
		case 9: return "VALVE_ROUTES_AIR";
		case 10: return "BP_IN_BELL";
		case 11: return "FOOT_PEDALS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tuning_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tuning_type::tuning_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "PEGS";
		case 1: return "ADJUSTABLE_BRIDGES";
		case 2: return "CROOKS";
		case 3: return "TIGHTENING";
		case 4: return "LEVERS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_timbre_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::timbre_type::timbre_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "CLEAR";
		case 1: return "NOISY";
		case 2: return "FULL";
		case 3: return "THIN";
		case 4: return "ROUND";
		case 5: return "SHARP";
		case 6: return "SMOOTH";
		case 7: return "CHOPPY";
		case 8: return "STEADY";
		case 9: return "EVOLVING";
		case 10: return "STRONG";
		case 11: return "DELICATE";
		case 12: return "BRIGHT";
		case 13: return "GRACEFUL";
		case 14: return "SPARSE";
		case 15: return "BREATHY";
		case 16: return "STRAINED";
		case 17: return "BROAD";
		case 18: return "LIGHT";
		case 19: return "MELLOW";
		case 20: return "WOBBLING";
		case 21: return "FOCUSED";
		case 22: return "EVEN";
		case 23: return "FLUID";
		case 24: return "VIBRATING";
		case 25: return "QUAVERING";
		case 26: return "EERIE";
		case 27: return "FRAGILE";
		case 28: return "BRITTLE";
		case 29: return "PURE_";
		case 30: return "PIERCING";
		case 31: return "STRIDENT";
		case 32: return "WAVERING";
		case 33: return "HARSH";
		case 34: return "REEDY";
		case 35: return "NASAL";
		case 36: return "BUZZY";
		case 37: return "ROUGH";
		case 38: return "WARM";
		case 39: return "RUGGED";
		case 40: return "HEAVY";
		case 41: return "FLAT";
		case 42: return "DARK";
		case 43: return "CRISP";
		case 44: return "SONOROUS";
		case 45: return "WATERY";
		case 46: return "GENTLE";
		case 47: return "SLICING";
		case 48: return "LIQUID";
		case 49: return "RAUCOUS";
		case 50: return "BREEZY";
		case 51: return "RASPY";
		case 52: return "WISPY";
		case 53: return "SHRILL";
		case 54: return "MUDDY";
		case 55: return "RICH";
		case 56: return "DULL";
		case 57: return "FLOATING";
		case 58: return "RINGING";
		case 59: return "RESONANT";
		case 60: return "SWEET";
		case 61: return "RIPPLING";
		case 62: return "SPARKLING";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_pants_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::pants_flags::pants_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "METAL_ARMOR_LEVELS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_shoes_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::shoes_flags::shoes_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "METAL_ARMOR_LEVELS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tool_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tool_flags::tool_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "HARD_MAT";
		case 1: return "METAL_MAT";
		case 2: return "HAS_EDGE_ATTACK";
		case 3: return "METAL_WEAPON_MAT";
		case 4: return "UNIMPROVABLE";
		case 5: return "SOFT_MAT";
		case 6: return "WOOD_MAT";
		case 7: return "INVERTED_TILE";
		case 8: return "FURNITURE";
		case 9: return "LEATHER_MAT";
		case 10: return "SILK_MAT";
		case 11: return "THREAD_PLANT_MAT";
		case 12: return "GLASS_MAT";
		case 13: return "CERAMIC_MAT";
		case 14: return "STONE_MAT";
		case 15: return "SHELL_MAT";
		case 16: return "BONE_MAT";
		case 17: return "NO_DEFAULT_JOB";
		case 18: return "INCOMPLETE_ITEM";
		case 19: return "SHEET_MAT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tool_uses_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tool_uses::tool_uses*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "LIQUID_COOKING";
		case 1: return "LIQUID_SCOOP";
		case 2: return "GRIND_POWDER_RECEPTACLE";
		case 3: return "GRIND_POWDER_GRINDER";
		case 4: return "MEAT_CARVING";
		case 5: return "MEAT_BONING";
		case 6: return "MEAT_SLICING";
		case 7: return "MEAT_CLEAVING";
		case 8: return "HOLD_MEAT_FOR_CARVING";
		case 9: return "MEAL_CONTAINER";
		case 10: return "LIQUID_CONTAINER";
		case 11: return "FOOD_STORAGE";
		case 12: return "HIVE";
		case 13: return "NEST_BOX";
		case 14: return "SMALL_OBJECT_STORAGE";
		case 15: return "TRACK_CART";
		case 16: return "HEAVY_OBJECT_HAULING";
		case 17: return "STAND_AND_WORK_ABOVE";
		case 18: return "ROLL_UP_SHEET";
		case 19: return "PROTECT_FOLDED_SHEETS";
		case 20: return "CONTAIN_WRITING";
		case 21: return "BOOKCASE";
		case 22: return "DISPLAY_OBJECT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_toy_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::toy_flags::toy_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "HARD_MAT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_trapcomp_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::trapcomp_flags::trapcomp_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "IS_SCREW";
		case 1: return "IS_SPIKE";
		case 2: return "WOOD";
		case 3: return "METAL";
		case 4: return "HAS_EDGE_ATTACK";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_weapon_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::weapon_flags::weapon_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "CAN_STONE";
		case 1: return "HAS_EDGE_ATTACK";
		case 2: return "TRAINING";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_items_other_id_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::items_other_id::items_other_id*>(p_address);
	switch (*m_value)
	{
		case -1: return "ANY";
		case 0: return "IN_PLAY";
		case 1: return "ANY_ARTIFACT";
		case 2: return "WEAPON";
		case 3: return "ANY_WEAPON";
		case 4: return "ANY_SPIKE";
		case 5: return "ANY_TRUE_ARMOR";
		case 6: return "ANY_ARMOR_HELM";
		case 7: return "ANY_ARMOR_SHOES";
		case 8: return "SHIELD";
		case 9: return "ANY_ARMOR_GLOVES";
		case 10: return "ANY_ARMOR_PANTS";
		case 11: return "QUIVER";
		case 12: return "SPLINT";
		case 13: return "ORTHOPEDIC_CAST";
		case 14: return "CRUTCH";
		case 15: return "BACKPACK";
		case 16: return "AMMO";
		case 17: return "WOOD";
		case 18: return "BRANCH";
		case 19: return "BOULDER";
		case 20: return "ROCK";
		case 21: return "ANY_REFUSE";
		case 22: return "ANY_GOOD_FOOD";
		case 23: return "ANY_AUTO_CLEAN";
		case 24: return "ANY_GENERIC24";
		case 25: return "ANY_GENERIC25";
		case 26: return "ANY_FURNITURE";
		case 27: return "ANY_CAGE_OR_TRAP";
		case 28: return "ANY_EDIBLE_RAW";
		case 29: return "ANY_EDIBLE_CARNIVORE";
		case 30: return "ANY_EDIBLE_BONECARN";
		case 31: return "ANY_EDIBLE_VERMIN";
		case 32: return "ANY_EDIBLE_VERMIN_BOX";
		case 33: return "ANY_CAN_ROT";
		case 34: return "ANY_MURDERED";
		case 35: return "ANY_DEAD_DWARF";
		case 36: return "ANY_GENERIC36";
		case 37: return "ANY_GENERIC37";
		case 38: return "ANY_GENERIC38";
		case 39: return "ANY_GENERIC39";
		case 40: return "DOOR";
		case 41: return "FLOODGATE";
		case 42: return "HATCH_COVER";
		case 43: return "GRATE";
		case 44: return "CAGE";
		case 45: return "FLASK";
		case 46: return "WINDOW";
		case 47: return "GOBLET";
		case 48: return "INSTRUMENT";
		case 49: return "INSTRUMENT_STATIONARY";
		case 50: return "TOY";
		case 51: return "TOOL";
		case 52: return "BUCKET";
		case 53: return "BARREL";
		case 54: return "CHAIN";
		case 55: return "ANIMALTRAP";
		case 56: return "BED";
		case 57: return "TRACTION_BENCH";
		case 58: return "CHAIR";
		case 59: return "COFFIN";
		case 60: return "TABLE";
		case 61: return "STATUE";
		case 62: return "SLAB";
		case 63: return "QUERN";
		case 64: return "MILLSTONE";
		case 65: return "BOX";
		case 66: return "BIN";
		case 67: return "ARMORSTAND";
		case 68: return "WEAPONRACK";
		case 69: return "CABINET";
		case 70: return "ANVIL";
		case 71: return "CATAPULTPARTS";
		case 72: return "BALLISTAPARTS";
		case 73: return "SIEGEAMMO";
		case 74: return "TRAPPARTS";
		case 75: return "ANY_WEBS";
		case 76: return "PIPE_SECTION";
		case 77: return "ANY_ENCASED";
		case 78: return "ANY_IN_CONSTRUCTION";
		case 79: return "DRINK";
		case 80: return "ANY_DRINK";
		case 81: return "LIQUID_MISC";
		case 82: return "POWDER_MISC";
		case 83: return "ANY_COOKABLE";
		case 84: return "ANY_GENERIC84";
		case 85: return "VERMIN";
		case 86: return "PET";
		case 87: return "ANY_CRITTER";
		case 88: return "COIN";
		case 89: return "GLOB";
		case 90: return "TRAPCOMP";
		case 91: return "BAR";
		case 92: return "SMALLGEM";
		case 93: return "BLOCKS";
		case 94: return "ROUGH";
		case 95: return "ANY_CORPSE";
		case 96: return "CORPSE";
		case 97: return "BOOK";
		case 98: return "FIGURINE";
		case 99: return "AMULET";
		case 100: return "SCEPTER";
		case 101: return "CROWN";
		case 102: return "RING";
		case 103: return "EARRING";
		case 104: return "BRACELET";
		case 105: return "GEM";
		case 106: return "CORPSEPIECE";
		case 107: return "REMAINS";
		case 108: return "MEAT";
		case 109: return "FISH";
		case 110: return "FISH_RAW";
		case 111: return "EGG";
		case 112: return "SEEDS";
		case 113: return "PLANT";
		case 114: return "SKIN_TANNED";
		case 115: return "PLANT_GROWTH";
		case 116: return "THREAD";
		case 117: return "CLOTH";
		case 118: return "SHEET";
		case 119: return "TOTEM";
		case 120: return "PANTS";
		case 121: return "CHEESE";
		case 122: return "FOOD";
		case 123: return "BALLISTAARROWHEAD";
		case 124: return "ARMOR";
		case 125: return "SHOES";
		case 126: return "HELM";
		case 127: return "GLOVES";
		case 128: return "ANY_GENERIC128";
		case 129: return "FOOD_STORAGE";
		case 130: return "ANY_RECENTLY_DROPPED";
		case 131: return "ANY_MELT_DESIGNATED";
		case 132: return "BAD";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_job_item_vector_id_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::job_item_vector_id::job_item_vector_id*>(p_address);
	switch (*m_value)
	{
		case 0: return "ANY";
		case 1: return "IN_PLAY";
		case 2: return "ANY_ARTIFACT";
		case 3: return "WEAPON";
		case 4: return "ANY_WEAPON";
		case 5: return "ANY_SPIKE";
		case 6: return "ANY_TRUE_ARMOR";
		case 7: return "ANY_ARMOR_HELM";
		case 8: return "ANY_ARMOR_SHOES";
		case 9: return "SHIELD";
		case 10: return "ANY_ARMOR_GLOVES";
		case 11: return "ANY_ARMOR_PANTS";
		case 12: return "QUIVER";
		case 13: return "SPLINT";
		case 14: return "ANY_14";
		case 15: return "CRUTCH";
		case 16: return "BACKPACK";
		case 17: return "AMMO";
		case 18: return "WOOD";
		case 19: return "BOULDER";
		case 20: return "ROCK";
		case 21: return "ANY_REFUSE";
		case 22: return "ANY_GOOD_FOOD";
		case 23: return "ANY_AUTO_CLEAN";
		case 24: return "ANY_GENERIC24";
		case 25: return "ANY_GENERIC25";
		case 26: return "ANY_FURNITURE";
		case 27: return "ANY_CAGE_OR_TRAP";
		case 28: return "ANY_EDIBLE_RAW";
		case 29: return "ANY_EDIBLE_CARNIVORE";
		case 30: return "ANY_EDIBLE_BONECARN";
		case 31: return "ANY_EDIBLE_VERMIN";
		case 32: return "ANY_EDIBLE_VERMIN_BOX";
		case 33: return "ANY_CAN_ROT";
		case 34: return "ANY_MURDERED";
		case 35: return "ANY_DEAD_DWARF";
		case 36: return "ANY_GENERIC36";
		case 37: return "ANY_GENERIC37";
		case 38: return "ANY_GENERIC38";
		case 39: return "ANY_GENERIC39";
		case 40: return "DOOR";
		case 41: return "FLOODGATE";
		case 42: return "HATCH_COVER";
		case 43: return "GRATE";
		case 44: return "CAGE";
		case 45: return "FLASK";
		case 46: return "WINDOW";
		case 47: return "GOBLET";
		case 48: return "INSTRUMENT";
		case 49: return "TOY";
		case 50: return "BUCKET";
		case 51: return "BARREL";
		case 52: return "CHAIN";
		case 53: return "ANIMALTRAP";
		case 54: return "BED";
		case 55: return "TRACTION_BENCH";
		case 56: return "CHAIR";
		case 57: return "COFFIN";
		case 58: return "TABLE";
		case 59: return "STATUE";
		case 60: return "QUERN";
		case 61: return "MILLSTONE";
		case 62: return "BOX";
		case 63: return "BIN";
		case 64: return "ARMORSTAND";
		case 65: return "WEAPONRACK";
		case 66: return "CABINET";
		case 67: return "ANVIL";
		case 68: return "CATAPULTPARTS";
		case 69: return "BALLISTAPARTS";
		case 70: return "SIEGEAMMO";
		case 71: return "TRAPPARTS";
		case 72: return "ANY_WEBS";
		case 73: return "PIPE_SECTION";
		case 74: return "ANY_ENCASED";
		case 75: return "ANY_IN_CONSTRUCTION";
		case 76: return "DRINK";
		case 77: return "ANY_DRINK";
		case 78: return "LIQUID_MISC";
		case 79: return "POWDER_MISC";
		case 80: return "ANY_COOKABLE";
		case 81: return "ANY_GENERIC84";
		case 82: return "VERMIN";
		case 83: return "PET";
		case 84: return "ANY_CRITTER";
		case 85: return "COIN";
		case 86: return "GLOB";
		case 87: return "ANY_RECENTLY_DROPPED";
		case 88: return "ANY_MELT_DESIGNATED";
		case 89: return "BAD";
		case 90: return "TRAPCOMP";
		case 91: return "BAR";
		case 92: return "SMALLGEM";
		case 93: return "BLOCKS";
		case 94: return "ROUGH";
		case 95: return "CORPSE";
		case 96: return "FIGURINE";
		case 97: return "AMULET";
		case 98: return "SCEPTER";
		case 99: return "CROWN";
		case 100: return "RING";
		case 101: return "EARRING";
		case 102: return "BRACELET";
		case 103: return "GEM";
		case 104: return "CORPSEPIECE";
		case 105: return "REMAINS";
		case 106: return "MEAT";
		case 107: return "FISH";
		case 108: return "FISH_RAW";
		case 109: return "SEEDS";
		case 110: return "PLANT";
		case 111: return "SKIN_TANNED";
		case 112: return "PLANT_GROWTH";
		case 113: return "THREAD";
		case 114: return "CLOTH";
		case 115: return "TOTEM";
		case 116: return "PANTS";
		case 117: return "CHEESE";
		case 118: return "FOOD";
		case 119: return "BALLISTAARROWHEAD";
		case 120: return "ARMOR";
		case 121: return "SHOES";
		case 122: return "HELM";
		case 123: return "GLOVES";
		case 124: return "ANY_124";
		case 125: return "ANY_125";
		case 126: return "EGG";
		case 127: return "ANY_127";
		case 128: return "ANY_CORPSE";
		case 129: return "BOOK";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_improvement_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::improvement_type::improvement_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "ART_IMAGE";
		case 1: return "COVERED";
		case 2: return "RINGS_HANGING";
		case 3: return "BANDS";
		case 4: return "SPIKES";
		case 5: return "ITEMSPECIFIC";
		case 6: return "THREAD";
		case 7: return "CLOTH";
		case 8: return "SEWN_IMAGE";
		case 9: return "PAGES";
		case 10: return "ILLUSTRATION";
		case 11: return "INSTRUMENT_PIECE";
		case 12: return "WRITING";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_itemimprovement_specific_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::itemimprovement_specific_type::itemimprovement_specific_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "HANDLE";
		case 1: return "ROLLERS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_written_content_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::written_content_type::written_content_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Manual";
		case 1: return "Guide";
		case 2: return "Chronicle";
		case 3: return "ShortStory";
		case 4: return "Novel";
		case 5: return "Biography";
		case 6: return "Autobiography";
		case 7: return "Poem";
		case 8: return "Play";
		case 9: return "Letter";
		case 10: return "Essay";
		case 11: return "Dialog";
		case 12: return "MusicalComposition";
		case 13: return "Choreography";
		case 14: return "ComparativeBiography";
		case 15: return "BiographicalDictionary";
		case 16: return "Genealogy";
		case 17: return "Encyclopedia";
		case 18: return "CulturalHistory";
		case 19: return "CulturalComparison";
		case 20: return "AlternateHistory";
		case 21: return "TreatiseOnTechnologicalEvolution";
		case 22: return "Dictionary";
		case 23: return "StarChart";
		case 24: return "StarCatalogue";
		case 25: return "Atlas";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_written_content_style_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::written_content_style::written_content_style*>(p_address);
	switch (*m_value)
	{
		case 0: return "Meandering";
		case 1: return "Cheerful";
		case 2: return "Depressing";
		case 3: return "Rigid";
		case 4: return "Serious";
		case 5: return "Disjointed";
		case 6: return "Ornate";
		case 7: return "Forceful";
		case 8: return "Humorous";
		case 9: return "Immature";
		case 10: return "SelfIndulgent";
		case 11: return "Touching";
		case 12: return "Compassionate";
		case 13: return "Vicious";
		case 14: return "Concise";
		case 15: return "Scornful";
		case 16: return "Witty";
		case 17: return "Ranting";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_item_magicness_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::item_magicness_type::item_magicness_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Sparkle";
		case 1: return "AirWarped";
		case 2: return "Whistle";
		case 3: return "OddlySquare";
		case 4: return "SmallBumps";
		case 5: return "EarthSmell";
		case 6: return "Lightning";
		case 7: return "GrayHairs";
		case 8: return "RustlingLeaves";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_item_quality_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::item_quality::item_quality*>(p_address);
	switch (*m_value)
	{
		case 0: return "Ordinary";
		case 1: return "WellCrafted";
		case 2: return "FinelyCrafted";
		case 3: return "Superior";
		case 4: return "Exceptional";
		case 5: return "Masterful";
		case 6: return "Artifact";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_slab_engraving_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::slab_engraving_type::slab_engraving_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "Slab";
		case 0: return "Memorial";
		case 1: return "CraftShopSign";
		case 2: return "WeaponsmithShopSign";
		case 3: return "ArmorsmithShopSign";
		case 4: return "GeneralStoreSign";
		case 5: return "FoodShopSign";
		case 6: return "Secrets";
		case 7: return "FoodImportsSign";
		case 8: return "ClothingImportsSign";
		case 9: return "GeneralImportsSign";
		case 10: return "ClothShopSign";
		case 11: return "LeatherShopSign";
		case 12: return "WovenClothingShopSign";
		case 13: return "LeatherClothingShopSign";
		case 14: return "BoneCarverShopSign";
		case 15: return "GemCutterShopSign";
		case 16: return "WeaponsmithShopSign2";
		case 17: return "BowyerShopSign";
		case 18: return "BlacksmithShopSign";
		case 19: return "ArmorsmithShopSign2";
		case 20: return "MetalCraftShopSign";
		case 21: return "LeatherGoodsShopSign";
		case 22: return "CarpenterShopSign";
		case 23: return "StoneFurnitureShopSign";
		case 24: return "MetalFurnitureShopSign";
		case 25: return "DemonIdentity";
		case 26: return "TavernSign";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_corpse_material_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::corpse_material_type::corpse_material_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Plant";
		case 1: return "Silk";
		case 2: return "Leather";
		case 3: return "Bone";
		case 4: return "Shell";
		case 5: return "anon_1";
		case 6: return "Soap";
		case 7: return "Tooth";
		case 8: return "Horn";
		case 9: return "Pearl";
		case 10: return "HairWool";
		case 11: return "Yarn";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_job_type_class_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::job_type_class::job_type_class*>(p_address);
	switch (*m_value)
	{
		case 0: return "Misc";
		case 1: return "Digging";
		case 2: return "Building";
		case 3: return "Hauling";
		case 4: return "LifeSupport";
		case 5: return "TidyUp";
		case 6: return "Leisure";
		case 7: return "Gathering";
		case 8: return "Manufacture";
		case 9: return "Improvement";
		case 10: return "Crime";
		case 11: return "LawEnforcement";
		case 12: return "StrangeMood";
		case 13: return "UnitHandling";
		case 14: return "SiegeWeapon";
		case 15: return "Medicine";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_job_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::job_type::job_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "CarveFortification";
		case 1: return "DetailWall";
		case 2: return "DetailFloor";
		case 3: return "Dig";
		case 4: return "CarveUpwardStaircase";
		case 5: return "CarveDownwardStaircase";
		case 6: return "CarveUpDownStaircase";
		case 7: return "CarveRamp";
		case 8: return "DigChannel";
		case 9: return "FellTree";
		case 10: return "GatherPlants";
		case 11: return "RemoveConstruction";
		case 12: return "CollectWebs";
		case 13: return "BringItemToDepot";
		case 14: return "BringItemToShop";
		case 15: return "Eat";
		case 16: return "GetProvisions";
		case 17: return "Drink";
		case 18: return "Drink2";
		case 19: return "FillWaterskin";
		case 20: return "FillWaterskin2";
		case 21: return "Sleep";
		case 22: return "CollectSand";
		case 23: return "Fish";
		case 24: return "Hunt";
		case 25: return "HuntVermin";
		case 26: return "Kidnap";
		case 27: return "BeatCriminal";
		case 28: return "StartingFistFight";
		case 29: return "CollectTaxes";
		case 30: return "GuardTaxCollector";
		case 31: return "CatchLiveLandAnimal";
		case 32: return "CatchLiveFish";
		case 33: return "ReturnKill";
		case 34: return "CheckChest";
		case 35: return "StoreOwnedItem";
		case 36: return "PlaceItemInTomb";
		case 37: return "StoreItemInStockpile";
		case 38: return "StoreItemInBag";
		case 39: return "StoreItemInHospital";
		case 40: return "StoreItemInLocation";
		case 41: return "anon_1";
		case 42: return "StoreWeapon";
		case 43: return "StoreArmor";
		case 44: return "StoreItemInBarrel";
		case 45: return "StoreItemInBin";
		case 46: return "SeekArtifact";
		case 47: return "SeekInfant";
		case 48: return "AttendParty";
		case 49: return "GoShopping";
		case 50: return "GoShopping2";
		case 51: return "Clean";
		case 52: return "Rest";
		case 53: return "PickupEquipment";
		case 54: return "DumpItem";
		case 55: return "StrangeMoodCrafter";
		case 56: return "StrangeMoodJeweller";
		case 57: return "StrangeMoodForge";
		case 58: return "StrangeMoodMagmaForge";
		case 59: return "StrangeMoodBrooding";
		case 60: return "StrangeMoodFell";
		case 61: return "StrangeMoodCarpenter";
		case 62: return "StrangeMoodMason";
		case 63: return "StrangeMoodBowyer";
		case 64: return "StrangeMoodTanner";
		case 65: return "StrangeMoodWeaver";
		case 66: return "StrangeMoodGlassmaker";
		case 67: return "StrangeMoodMechanics";
		case 68: return "ConstructBuilding";
		case 69: return "ConstructDoor";
		case 70: return "ConstructFloodgate";
		case 71: return "ConstructBed";
		case 72: return "ConstructThrone";
		case 73: return "ConstructCoffin";
		case 74: return "ConstructTable";
		case 75: return "ConstructChest";
		case 76: return "ConstructBin";
		case 77: return "ConstructArmorStand";
		case 78: return "ConstructWeaponRack";
		case 79: return "ConstructCabinet";
		case 80: return "ConstructStatue";
		case 81: return "ConstructBlocks";
		case 82: return "MakeRawGlass";
		case 83: return "MakeCrafts";
		case 84: return "MintCoins";
		case 85: return "CutGems";
		case 86: return "CutGlass";
		case 87: return "EncrustWithGems";
		case 88: return "EncrustWithGlass";
		case 89: return "DestroyBuilding";
		case 90: return "SmeltOre";
		case 91: return "MeltMetalObject";
		case 92: return "ExtractMetalStrands";
		case 93: return "PlantSeeds";
		case 94: return "HarvestPlants";
		case 95: return "TrainHuntingAnimal";
		case 96: return "TrainWarAnimal";
		case 97: return "MakeWeapon";
		case 98: return "ForgeAnvil";
		case 99: return "ConstructCatapultParts";
		case 100: return "ConstructBallistaParts";
		case 101: return "MakeArmor";
		case 102: return "MakeHelm";
		case 103: return "MakePants";
		case 104: return "StudWith";
		case 105: return "ButcherAnimal";
		case 106: return "PrepareRawFish";
		case 107: return "MillPlants";
		case 108: return "BaitTrap";
		case 109: return "MilkCreature";
		case 110: return "MakeCheese";
		case 111: return "ProcessPlants";
		case 112: return "anon_2";
		case 113: return "ProcessPlantsVial";
		case 114: return "ProcessPlantsBarrel";
		case 115: return "PrepareMeal";
		case 116: return "WeaveCloth";
		case 117: return "MakeGloves";
		case 118: return "MakeShoes";
		case 119: return "MakeShield";
		case 120: return "MakeCage";
		case 121: return "MakeChain";
		case 122: return "MakeFlask";
		case 123: return "MakeGoblet";
		case 124: return "anon_3";
		case 125: return "MakeToy";
		case 126: return "MakeAnimalTrap";
		case 127: return "MakeBarrel";
		case 128: return "MakeBucket";
		case 129: return "MakeWindow";
		case 130: return "MakeTotem";
		case 131: return "MakeAmmo";
		case 132: return "DecorateWith";
		case 133: return "MakeBackpack";
		case 134: return "MakeQuiver";
		case 135: return "MakeBallistaArrowHead";
		case 136: return "AssembleSiegeAmmo";
		case 137: return "LoadCatapult";
		case 138: return "LoadBallista";
		case 139: return "FireCatapult";
		case 140: return "FireBallista";
		case 141: return "ConstructMechanisms";
		case 142: return "MakeTrapComponent";
		case 143: return "LoadCageTrap";
		case 144: return "LoadStoneTrap";
		case 145: return "LoadWeaponTrap";
		case 146: return "CleanTrap";
		case 147: return "CastSpell";
		case 148: return "LinkBuildingToTrigger";
		case 149: return "PullLever";
		case 150: return "anon_4";
		case 151: return "ExtractFromPlants";
		case 152: return "ExtractFromRawFish";
		case 153: return "ExtractFromLandAnimal";
		case 154: return "TameVermin";
		case 155: return "TameAnimal";
		case 156: return "ChainAnimal";
		case 157: return "UnchainAnimal";
		case 158: return "UnchainPet";
		case 159: return "ReleaseLargeCreature";
		case 160: return "ReleasePet";
		case 161: return "ReleaseSmallCreature";
		case 162: return "HandleSmallCreature";
		case 163: return "HandleLargeCreature";
		case 164: return "CageLargeCreature";
		case 165: return "CageSmallCreature";
		case 166: return "RecoverWounded";
		case 167: return "DiagnosePatient";
		case 168: return "ImmobilizeBreak";
		case 169: return "DressWound";
		case 170: return "CleanPatient";
		case 171: return "Surgery";
		case 172: return "Suture";
		case 173: return "SetBone";
		case 174: return "PlaceInTraction";
		case 175: return "DrainAquarium";
		case 176: return "FillAquarium";
		case 177: return "FillPond";
		case 178: return "GiveWater";
		case 179: return "GiveFood";
		case 180: return "GiveWater2";
		case 181: return "GiveFood2";
		case 182: return "RecoverPet";
		case 183: return "PitLargeAnimal";
		case 184: return "PitSmallAnimal";
		case 185: return "SlaughterAnimal";
		case 186: return "MakeCharcoal";
		case 187: return "MakeAsh";
		case 188: return "MakeLye";
		case 189: return "MakePotashFromLye";
		case 190: return "FertilizeField";
		case 191: return "MakePotashFromAsh";
		case 192: return "DyeThread";
		case 193: return "DyeCloth";
		case 194: return "SewImage";
		case 195: return "MakePipeSection";
		case 196: return "OperatePump";
		case 197: return "ManageWorkOrders";
		case 198: return "UpdateStockpileRecords";
		case 199: return "TradeAtDepot";
		case 200: return "ConstructHatchCover";
		case 201: return "ConstructGrate";
		case 202: return "RemoveStairs";
		case 203: return "ConstructQuern";
		case 204: return "ConstructMillstone";
		case 205: return "ConstructSplint";
		case 206: return "ConstructCrutch";
		case 207: return "ConstructTractionBench";
		case 208: return "CleanSelf";
		case 209: return "BringCrutch";
		case 210: return "ApplyCast";
		case 211: return "CustomReaction";
		case 212: return "ConstructSlab";
		case 213: return "EngraveSlab";
		case 214: return "ShearCreature";
		case 215: return "SpinThread";
		case 216: return "PenLargeAnimal";
		case 217: return "PenSmallAnimal";
		case 218: return "MakeTool";
		case 219: return "CollectClay";
		case 220: return "InstallColonyInHive";
		case 221: return "CollectHiveProducts";
		case 222: return "CauseTrouble";
		case 223: return "DrinkBlood";
		case 224: return "ReportCrime";
		case 225: return "ExecuteCriminal";
		case 226: return "TrainAnimal";
		case 227: return "CarveTrack";
		case 228: return "PushTrackVehicle";
		case 229: return "PlaceTrackVehicle";
		case 230: return "StoreItemInVehicle";
		case 231: return "GeldAnimal";
		case 232: return "MakeFigurine";
		case 233: return "MakeAmulet";
		case 234: return "MakeScepter";
		case 235: return "MakeCrown";
		case 236: return "MakeRing";
		case 237: return "MakeEarring";
		case 238: return "MakeBracelet";
		case 239: return "MakeGem";
		case 240: return "PutItemOnDisplay";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_job_subtype_surgery_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::job_subtype_surgery::job_subtype_surgery*>(p_address);
	switch (*m_value)
	{
		case 0: return "Surgery";
		case 1: return "StopBleeding";
		case 2: return "RepairCompoundFracture";
		case 3: return "RemoveRottenTissue";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_job_art_specification__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::job_art_specification::T_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "HistoricalFigure";
		case 1: return "Site";
		case 2: return "Entity";
		case 3: return "ArtImage";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_manager_order_condition_order__T_condition_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::manager_order_condition_order::T_condition*>(p_address);
	switch (*m_value)
	{
		case 0: return "Activated";
		case 1: return "Completed";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_guild_id_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::guild_id::guild_id*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Miners";
		case 1: return "Carpenters";
		case 2: return "Masons";
		case 3: return "Metalsmiths";
		case 4: return "Jewelers";
		case 5: return "Craftsmen";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interface_key_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::interface_key::interface_key*>(p_address);
	switch (*m_value)
	{
		case 0: return "NONE";
		case 1: return "SELECT";
		case 2: return "SEC_SELECT";
		case 3: return "DESELECT";
		case 4: return "SELECT_ALL";
		case 5: return "DESELECT_ALL";
		case 6: return "LEAVESCREEN";
		case 7: return "LEAVESCREEN_ALL";
		case 8: return "CLOSE_MEGA_ANNOUNCEMENT";
		case 9: return "OPTIONS";
		case 10: return "OPTION_EXPORT";
		case 11: return "HELP";
		case 12: return "TOGGLE_FULLSCREEN";
		case 13: return "MOVIES";
		case 14: return "ZOOM_IN";
		case 15: return "ZOOM_OUT";
		case 16: return "ZOOM_TOGGLE";
		case 17: return "ZOOM_RESET";
		case 18: return "MOVIE_RECORD";
		case 19: return "MOVIE_PLAY";
		case 20: return "MOVIE_SAVE";
		case 21: return "MOVIE_LOAD";
		case 22: return "TOGGLE_TTF";
		case 23: return "FPS_UP";
		case 24: return "FPS_DOWN";
		case 25: return "CHANGETAB";
		case 26: return "SEC_CHANGETAB";
		case 27: return "STANDARDSCROLL_UP";
		case 28: return "STANDARDSCROLL_DOWN";
		case 29: return "STANDARDSCROLL_LEFT";
		case 30: return "STANDARDSCROLL_RIGHT";
		case 31: return "STANDARDSCROLL_PAGEUP";
		case 32: return "STANDARDSCROLL_PAGEDOWN";
		case 33: return "SECONDSCROLL_UP";
		case 34: return "SECONDSCROLL_DOWN";
		case 35: return "SECONDSCROLL_PAGEUP";
		case 36: return "SECONDSCROLL_PAGEDOWN";
		case 37: return "CURSOR_UP";
		case 38: return "CURSOR_DOWN";
		case 39: return "CURSOR_LEFT";
		case 40: return "CURSOR_RIGHT";
		case 41: return "CURSOR_UPLEFT";
		case 42: return "CURSOR_UPRIGHT";
		case 43: return "CURSOR_DOWNLEFT";
		case 44: return "CURSOR_DOWNRIGHT";
		case 45: return "CURSOR_UP_FAST";
		case 46: return "CURSOR_DOWN_FAST";
		case 47: return "CURSOR_LEFT_FAST";
		case 48: return "CURSOR_RIGHT_FAST";
		case 49: return "CURSOR_UPLEFT_FAST";
		case 50: return "CURSOR_UPRIGHT_FAST";
		case 51: return "CURSOR_DOWNLEFT_FAST";
		case 52: return "CURSOR_DOWNRIGHT_FAST";
		case 53: return "CURSOR_UP_Z";
		case 54: return "CURSOR_DOWN_Z";
		case 55: return "CURSOR_UP_Z_AUX";
		case 56: return "CURSOR_DOWN_Z_AUX";
		case 57: return "MENU_CONFIRM";
		case 58: return "SAVE_BINDINGS";
		case 59: return "LOAD_BINDINGS";
		case 60: return "MACRO_BREAK";
		case 61: return "RECORD_MACRO";
		case 62: return "PLAY_MACRO";
		case 63: return "SAVE_MACRO";
		case 64: return "LOAD_MACRO";
		case 65: return "PREFIX";
		case 66: return "OPTION1";
		case 67: return "OPTION2";
		case 68: return "OPTION3";
		case 69: return "OPTION4";
		case 70: return "OPTION5";
		case 71: return "OPTION6";
		case 72: return "OPTION7";
		case 73: return "OPTION8";
		case 74: return "OPTION9";
		case 75: return "OPTION10";
		case 76: return "OPTION11";
		case 77: return "OPTION12";
		case 78: return "OPTION13";
		case 79: return "OPTION14";
		case 80: return "OPTION15";
		case 81: return "OPTION16";
		case 82: return "OPTION17";
		case 83: return "OPTION18";
		case 84: return "OPTION19";
		case 85: return "OPTION20";
		case 86: return "SEC_OPTION1";
		case 87: return "SEC_OPTION2";
		case 88: return "SEC_OPTION3";
		case 89: return "SEC_OPTION4";
		case 90: return "SEC_OPTION5";
		case 91: return "SEC_OPTION6";
		case 92: return "SEC_OPTION7";
		case 93: return "SEC_OPTION8";
		case 94: return "SEC_OPTION9";
		case 95: return "SEC_OPTION10";
		case 96: return "SEC_OPTION11";
		case 97: return "SEC_OPTION12";
		case 98: return "SEC_OPTION13";
		case 99: return "SEC_OPTION14";
		case 100: return "SEC_OPTION15";
		case 101: return "SEC_OPTION16";
		case 102: return "SEC_OPTION17";
		case 103: return "SEC_OPTION18";
		case 104: return "SEC_OPTION19";
		case 105: return "SEC_OPTION20";
		case 106: return "CUSTOM_A";
		case 107: return "CUSTOM_B";
		case 108: return "CUSTOM_C";
		case 109: return "CUSTOM_D";
		case 110: return "CUSTOM_E";
		case 111: return "CUSTOM_F";
		case 112: return "CUSTOM_G";
		case 113: return "CUSTOM_H";
		case 114: return "CUSTOM_I";
		case 115: return "CUSTOM_J";
		case 116: return "CUSTOM_K";
		case 117: return "CUSTOM_L";
		case 118: return "CUSTOM_M";
		case 119: return "CUSTOM_N";
		case 120: return "CUSTOM_O";
		case 121: return "CUSTOM_P";
		case 122: return "CUSTOM_Q";
		case 123: return "CUSTOM_R";
		case 124: return "CUSTOM_S";
		case 125: return "CUSTOM_T";
		case 126: return "CUSTOM_U";
		case 127: return "CUSTOM_V";
		case 128: return "CUSTOM_W";
		case 129: return "CUSTOM_X";
		case 130: return "CUSTOM_Y";
		case 131: return "CUSTOM_Z";
		case 132: return "CUSTOM_SHIFT_A";
		case 133: return "CUSTOM_SHIFT_B";
		case 134: return "CUSTOM_SHIFT_C";
		case 135: return "CUSTOM_SHIFT_D";
		case 136: return "CUSTOM_SHIFT_E";
		case 137: return "CUSTOM_SHIFT_F";
		case 138: return "CUSTOM_SHIFT_G";
		case 139: return "CUSTOM_SHIFT_H";
		case 140: return "CUSTOM_SHIFT_I";
		case 141: return "CUSTOM_SHIFT_J";
		case 142: return "CUSTOM_SHIFT_K";
		case 143: return "CUSTOM_SHIFT_L";
		case 144: return "CUSTOM_SHIFT_M";
		case 145: return "CUSTOM_SHIFT_N";
		case 146: return "CUSTOM_SHIFT_O";
		case 147: return "CUSTOM_SHIFT_P";
		case 148: return "CUSTOM_SHIFT_Q";
		case 149: return "CUSTOM_SHIFT_R";
		case 150: return "CUSTOM_SHIFT_S";
		case 151: return "CUSTOM_SHIFT_T";
		case 152: return "CUSTOM_SHIFT_U";
		case 153: return "CUSTOM_SHIFT_V";
		case 154: return "CUSTOM_SHIFT_W";
		case 155: return "CUSTOM_SHIFT_X";
		case 156: return "CUSTOM_SHIFT_Y";
		case 157: return "CUSTOM_SHIFT_Z";
		case 158: return "CUSTOM_CTRL_A";
		case 159: return "CUSTOM_CTRL_B";
		case 160: return "CUSTOM_CTRL_C";
		case 161: return "CUSTOM_CTRL_D";
		case 162: return "CUSTOM_CTRL_E";
		case 163: return "CUSTOM_CTRL_F";
		case 164: return "CUSTOM_CTRL_G";
		case 165: return "CUSTOM_CTRL_H";
		case 166: return "CUSTOM_CTRL_I";
		case 167: return "CUSTOM_CTRL_J";
		case 168: return "CUSTOM_CTRL_K";
		case 169: return "CUSTOM_CTRL_L";
		case 170: return "CUSTOM_CTRL_M";
		case 171: return "CUSTOM_CTRL_N";
		case 172: return "CUSTOM_CTRL_O";
		case 173: return "CUSTOM_CTRL_P";
		case 174: return "CUSTOM_CTRL_Q";
		case 175: return "CUSTOM_CTRL_R";
		case 176: return "CUSTOM_CTRL_S";
		case 177: return "CUSTOM_CTRL_T";
		case 178: return "CUSTOM_CTRL_U";
		case 179: return "CUSTOM_CTRL_V";
		case 180: return "CUSTOM_CTRL_W";
		case 181: return "CUSTOM_CTRL_X";
		case 182: return "CUSTOM_CTRL_Y";
		case 183: return "CUSTOM_CTRL_Z";
		case 184: return "CUSTOM_ALT_A";
		case 185: return "CUSTOM_ALT_B";
		case 186: return "CUSTOM_ALT_C";
		case 187: return "CUSTOM_ALT_D";
		case 188: return "CUSTOM_ALT_E";
		case 189: return "CUSTOM_ALT_F";
		case 190: return "CUSTOM_ALT_G";
		case 191: return "CUSTOM_ALT_H";
		case 192: return "CUSTOM_ALT_I";
		case 193: return "CUSTOM_ALT_J";
		case 194: return "CUSTOM_ALT_K";
		case 195: return "CUSTOM_ALT_L";
		case 196: return "CUSTOM_ALT_M";
		case 197: return "CUSTOM_ALT_N";
		case 198: return "CUSTOM_ALT_O";
		case 199: return "CUSTOM_ALT_P";
		case 200: return "CUSTOM_ALT_Q";
		case 201: return "CUSTOM_ALT_R";
		case 202: return "CUSTOM_ALT_S";
		case 203: return "CUSTOM_ALT_T";
		case 204: return "CUSTOM_ALT_U";
		case 205: return "CUSTOM_ALT_V";
		case 206: return "CUSTOM_ALT_W";
		case 207: return "CUSTOM_ALT_X";
		case 208: return "CUSTOM_ALT_Y";
		case 209: return "CUSTOM_ALT_Z";
		case 210: return "WORLD_PARAM_TITLE";
		case 211: return "WORLD_PARAM_ADD";
		case 212: return "WORLD_PARAM_COPY";
		case 213: return "WORLD_PARAM_DELETE";
		case 214: return "WORLD_PARAM_NAME_RANDOM";
		case 215: return "WORLD_PARAM_NAME_ENTER";
		case 216: return "WORLD_PARAM_SEED_RANDOM";
		case 217: return "WORLD_PARAM_SEED_ENTER";
		case 218: return "WORLD_PARAM_LOAD";
		case 219: return "WORLD_PARAM_SAVE";
		case 220: return "WORLD_PARAM_DIM_X_UP";
		case 221: return "WORLD_PARAM_DIM_X_DOWN";
		case 222: return "WORLD_PARAM_DIM_Y_UP";
		case 223: return "WORLD_PARAM_DIM_Y_DOWN";
		case 224: return "WORLD_PARAM_SET";
		case 225: return "WORLD_PARAM_INCREASE";
		case 226: return "WORLD_PARAM_DECREASE";
		case 227: return "WORLD_PARAM_ENTER_VALUE";
		case 228: return "WORLD_PARAM_NULLIFY";
		case 229: return "WORLD_PARAM_PRESET";
		case 230: return "WORLD_PARAM_REJECT_CONTINUE";
		case 231: return "WORLD_PARAM_REJECT_ABORT";
		case 232: return "WORLD_PARAM_REJECT_ALLOW_THIS";
		case 233: return "WORLD_PARAM_REJECT_ALLOW_ALL";
		case 234: return "WORLD_GEN_CONTINUE";
		case 235: return "WORLD_GEN_USE";
		case 236: return "WORLD_GEN_ABORT";
		case 237: return "WORLDGEN_EXPORT_MAP";
		case 238: return "LEGENDS_EXPORT_MAP";
		case 239: return "LEGENDS_EXPORT_XML";
		case 240: return "LEGENDS_EXPORT_DETAILED_MAP";
		case 241: return "LEGENDS_TOGGLE_CIVSITE";
		case 242: return "LEGENDS_STRING_FILTER";
		case 243: return "A_RETURN_TO_ARENA";
		case 244: return "A_MOVE_N";
		case 245: return "A_MOVE_S";
		case 246: return "A_MOVE_E";
		case 247: return "A_MOVE_W";
		case 248: return "A_MOVE_NW";
		case 249: return "A_MOVE_NE";
		case 250: return "A_MOVE_SW";
		case 251: return "A_MOVE_SE";
		case 252: return "A_MOVE_SAME_SQUARE";
		case 253: return "A_CARE_MOVE_N";
		case 254: return "A_CARE_MOVE_S";
		case 255: return "A_CARE_MOVE_E";
		case 256: return "A_CARE_MOVE_W";
		case 257: return "A_CARE_MOVE_NW";
		case 258: return "A_CARE_MOVE_NE";
		case 259: return "A_CARE_MOVE_SW";
		case 260: return "A_CARE_MOVE_SE";
		case 261: return "A_CARE_MOVE_UPDOWN";
		case 262: return "A_MOVE_N_UP";
		case 263: return "A_MOVE_S_UP";
		case 264: return "A_MOVE_E_UP";
		case 265: return "A_MOVE_W_UP";
		case 266: return "A_MOVE_NW_UP";
		case 267: return "A_MOVE_NE_UP";
		case 268: return "A_MOVE_SW_UP";
		case 269: return "A_MOVE_SE_UP";
		case 270: return "A_MOVE_UP";
		case 271: return "A_MOVE_N_DOWN";
		case 272: return "A_MOVE_S_DOWN";
		case 273: return "A_MOVE_E_DOWN";
		case 274: return "A_MOVE_W_DOWN";
		case 275: return "A_MOVE_NW_DOWN";
		case 276: return "A_MOVE_NE_DOWN";
		case 277: return "A_MOVE_SW_DOWN";
		case 278: return "A_MOVE_SE_DOWN";
		case 279: return "A_MOVE_DOWN";
		case 280: return "A_MOVE_UP_AUX";
		case 281: return "A_MOVE_DOWN_AUX";
		case 282: return "A_COMBAT_ATTACK";
		case 283: return "A_COMBAT_DODGE";
		case 284: return "A_COMBAT_CHARGEDEF";
		case 285: return "A_STATUS";
		case 286: return "A_STATUS_WRESTLE";
		case 287: return "A_STATUS_CUSTOMIZE";
		case 288: return "A_STATUS_KILLS";
		case 289: return "A_STATUS_HEALTH";
		case 290: return "A_STATUS_ATT_SKILL";
		case 291: return "A_STATUS_DESC";
		case 292: return "A_CLEAR_ANNOUNCEMENTS";
		case 293: return "A_SLEEP";
		case 294: return "A_SLEEP_SLEEP";
		case 295: return "A_SLEEP_WAIT";
		case 296: return "A_SLEEP_DAWN";
		case 297: return "A_WAIT";
		case 298: return "A_SHORT_WAIT";
		case 299: return "A_ATTACK";
		case 300: return "A_ATTACK_CONFIRM";
		case 301: return "QUICK_ATTACK";
		case 302: return "HEAVY_ATTACK";
		case 303: return "WILD_ATTACK";
		case 304: return "PRECISE_ATTACK";
		case 305: return "CHARGE_ATTACK";
		case 306: return "MULTI_ATTACK";
		case 307: return "A_LOOK";
		case 308: return "A_SEARCH";
		case 309: return "A_ODOR";
		case 310: return "A_DISPLAY_ODOR";
		case 311: return "A_YIELD";
		case 312: return "A_DISPLAY_TRACKS";
		case 313: return "A_FRESHEST_TRACK";
		case 314: return "A_INV_DRAW_WEAPON";
		case 315: return "A_JUMP";
		case 316: return "A_HOLD";
		case 317: return "A_TALK";
		case 318: return "A_ASSUME_IDENTITY_NEW";
		case 319: return "A_ASSUME_IDENTITY_NONE";
		case 320: return "A_ASSUME_IDENTITY_NAME";
		case 321: return "A_ASSUME_IDENTITY_ORIGIN";
		case 322: return "A_ASSUME_IDENTITY_PROFESSION";
		case 323: return "A_ASSUME_IDENTITY_WORSHIP";
		case 324: return "A_INTERACT";
		case 325: return "A_ACTION";
		case 326: return "A_ACTION_CREATE";
		case 327: return "A_ACTION_BUTCHER";
		case 328: return "A_ACTION_ABILITY";
		case 329: return "A_ACTION_POWER";
		case 330: return "A_ACTION_COMPOSE";
		case 331: return "A_ACTION_WRITE";
		case 332: return "A_CONSTRUCTION";
		case 333: return "ADV_CONSTRUCTION_ZONE_NEW";
		case 334: return "ADV_CONSTRUCTION_ZONE_EDIT";
		case 335: return "ADV_CONSTRUCTION_ZONE_ASSIGN";
		case 336: return "ADV_CONSTRUCTION_ZONE_DELETE";
		case 337: return "ADV_CONSTRUCTION_ZONE_RECT";
		case 338: return "ADV_CONSTRUCTION_ZONE_FLOW";
		case 339: return "ADV_CONSTRUCTION_ZONE_REMOVE_RECT";
		case 340: return "ADV_CONSTRUCTION_STAIR_UPDOWN";
		case 341: return "ADV_CONSTRUCTION_REMOVE_PLANS";
		case 342: return "ADV_CONSTRUCTION_REMOVE_EXISTING";
		case 343: return "ADV_CONSTRUCTION_MATERIAL";
		case 344: return "ADV_CONSTRUCTION_CONSTRUCTION";
		case 345: return "ADV_CONSTRUCTION_BUILDING";
		case 346: return "ADV_CONSTRUCTION_ZONE";
		case 347: return "ADV_CONSTRUCTION_WORK_MENU";
		case 348: return "ADV_CONSTRUCTION_NAME_SITE";
		case 349: return "ADV_CONSTRUCTION_YOU_WORK";
		case 350: return "ADV_CONSTRUCTION_START";
		case 351: return "A_COMPOSE_FILTER";
		case 352: return "A_INV_LOOK";
		case 353: return "A_INV_REMOVE";
		case 354: return "A_INV_WEAR";
		case 355: return "A_INV_EATDRINK";
		case 356: return "A_INV_PUTIN";
		case 357: return "A_INV_DROP";
		case 358: return "A_GROUND";
		case 359: return "A_THROW";
		case 360: return "A_SHOOT";
		case 361: return "A_ANNOUNCEMENTS";
		case 362: return "A_COMBAT";
		case 363: return "A_MOVEMENT";
		case 364: return "A_MOVEMENT_SWIM";
		case 365: return "A_SNEAK";
		case 366: return "A_SPEED_SNEAK";
		case 367: return "A_CENTER";
		case 368: return "A_COMPANIONS";
		case 369: return "A_BUILDING";
		case 370: return "A_TRAVEL";
		case 371: return "A_TRAVEL_SLEEP";
		case 372: return "A_TRAVEL_MAP";
		case 373: return "A_TRAVEL_HIDE_INSTRUCTIONS";
		case 374: return "A_DATE";
		case 375: return "A_WEATHER";
		case 376: return "A_TEMPERATURE";
		case 377: return "A_STANCE";
		case 378: return "A_ENTER_NAME";
		case 379: return "A_CUST_NAME";
		case 380: return "A_RANDOM_NAME";
		case 381: return "A_RANDOM_APPEARANCE";
		case 382: return "A_RANDOM_APPEARANCE_FULL";
		case 383: return "A_RANDOM_PERSONALITY";
		case 384: return "A_CUSTOM_PERSONALITY";
		case 385: return "A_CHANGE_DREAM";
		case 386: return "A_CHANGE_GENDER";
		case 387: return "A_END_TRAVEL";
		case 388: return "A_TRAVEL_CLOUDS";
		case 389: return "A_LOG";
		case 390: return "A_TRAVEL_LOG";
		case 391: return "A_LOG_SORT";
		case 392: return "A_LOG_PIN";
		case 393: return "A_LOG_ENTITIES";
		case 394: return "A_LOG_SITES";
		case 395: return "A_LOG_SUBREGIONS";
		case 396: return "A_LOG_FEATURE_LAYERS";
		case 397: return "A_LOG_PEOPLE";
		case 398: return "A_LOG_AGREEMENTS";
		case 399: return "A_LOG_EVENTS";
		case 400: return "A_LOG_BESTIARY";
		case 401: return "A_LOG_ARTIFACTS";
		case 402: return "A_LOG_FILTER";
		case 403: return "A_LOG_ZOOM_CURRENT_LOCATION";
		case 404: return "A_LOG_ZOOM_SELECTED";
		case 405: return "A_LOG_LINE";
		case 406: return "A_LOG_MAP";
		case 407: return "A_BARTER_VIEW";
		case 408: return "A_BARTER_CURRENCY_1";
		case 409: return "A_BARTER_CURRENCY_2";
		case 410: return "A_BARTER_TRADE";
		case 411: return "A_BARTER_SHOW";
		case 412: return "SETUP_EMBARK";
		case 413: return "SETUP_NAME_FORT";
		case 414: return "SETUP_NAME_GROUP";
		case 415: return "SETUP_SYMBOL";
		case 416: return "SETUP_RECLAIM";
		case 417: return "SETUP_FIND";
		case 418: return "SETUP_NOTES";
		case 419: return "SETUP_NOTES_TAKE_NOTES";
		case 420: return "SETUP_NOTES_DELETE_NOTE";
		case 421: return "SETUP_NOTES_CHANGE_SYMBOL_SELECTION";
		case 422: return "SETUP_NOTES_ADOPT_SYMBOL";
		case 423: return "SETUP_LOCAL_Y_UP";
		case 424: return "SETUP_LOCAL_Y_DOWN";
		case 425: return "SETUP_LOCAL_X_UP";
		case 426: return "SETUP_LOCAL_X_DOWN";
		case 427: return "SETUP_LOCAL_Y_MUP";
		case 428: return "SETUP_LOCAL_Y_MDOWN";
		case 429: return "SETUP_LOCAL_X_MUP";
		case 430: return "SETUP_LOCAL_X_MDOWN";
		case 431: return "SETUP_BIOME_1";
		case 432: return "SETUP_BIOME_2";
		case 433: return "SETUP_BIOME_3";
		case 434: return "SETUP_BIOME_4";
		case 435: return "SETUP_BIOME_5";
		case 436: return "SETUP_BIOME_6";
		case 437: return "SETUP_BIOME_7";
		case 438: return "SETUP_BIOME_8";
		case 439: return "SETUP_BIOME_9";
		case 440: return "CHOOSE_NAME_RANDOM";
		case 441: return "CHOOSE_NAME_CLEAR";
		case 442: return "CHOOSE_NAME_TYPE";
		case 443: return "CHOOSE_NAME_FIRST";
		case 444: return "SETUPGAME_NEW";
		case 445: return "SETUPGAME_VIEW";
		case 446: return "SETUPGAME_CUSTOMIZE_UNIT";
		case 447: return "SETUPGAME_SAVE_PROFILE";
		case 448: return "SETUPGAME_SAVE_PROFILE_ABORT";
		case 449: return "SETUPGAME_SAVE_PROFILE_GO";
		case 450: return "SETUPGAME_VIEW_PROFILE_PROBLEMS";
		case 451: return "BUILDJOB_ADD";
		case 452: return "BUILDJOB_CANCEL";
		case 453: return "BUILDJOB_NAME";
		case 454: return "BUILDJOB_PROMOTE";
		case 455: return "BUILDJOB_NOW";
		case 456: return "BUILDJOB_REPEAT";
		case 457: return "BUILDJOB_SUSPEND";
		case 458: return "BUILDJOB_WORKSHOP_PROFILE";
		case 459: return "BUILDJOB_DETAILS";
		case 460: return "BUILDJOB_DETAILS_FILTER";
		case 461: return "BUILDJOB_WELL_FREE";
		case 462: return "BUILDJOB_WELL_SIZE";
		case 463: return "BUILDJOB_TARGET_FREE";
		case 464: return "BUILDJOB_TARGET_SIZE";
		case 465: return "BUILDJOB_TARGET_DOWN";
		case 466: return "BUILDJOB_TARGET_UP";
		case 467: return "BUILDJOB_TARGET_RIGHT";
		case 468: return "BUILDJOB_TARGET_LEFT";
		case 469: return "BUILDJOB_STATUE_ASSIGN";
		case 470: return "BUILDJOB_STATUE_FREE";
		case 471: return "BUILDJOB_STATUE_SIZE";
		case 472: return "BUILDJOB_CAGE_JUSTICE";
		case 473: return "BUILDJOB_CAGE_FREE";
		case 474: return "BUILDJOB_CAGE_SIZE";
		case 475: return "BUILDJOB_CAGE_ASSIGN_OCC";
		case 476: return "BUILDJOB_CAGE_WATER";
		case 477: return "BUILDJOB_CAGE_ASSIGN";
		case 478: return "BUILDJOB_CHAIN_ASSIGN_OCC";
		case 479: return "BUILDJOB_CHAIN_JUSTICE";
		case 480: return "BUILDJOB_CHAIN_ASSIGN";
		case 481: return "BUILDJOB_CHAIN_FREE";
		case 482: return "BUILDJOB_CHAIN_SIZE";
		case 483: return "BUILDJOB_SIEGE_FIRING";
		case 484: return "BUILDJOB_SIEGE_ORIENT";
		case 485: return "BUILDJOB_DOOR_INTERNAL";
		case 486: return "BUILDJOB_DOOR_LOCK";
		case 487: return "BUILDJOB_DOOR_AJAR";
		case 488: return "BUILDJOB_COFFIN_ASSIGN";
		case 489: return "BUILDJOB_COFFIN_FREE";
		case 490: return "BUILDJOB_COFFIN_SIZE";
		case 491: return "BUILDJOB_COFFIN_BURIAL";
		case 492: return "BUILDJOB_COFFIN_CIV";
		case 493: return "BUILDJOB_COFFIN_PET";
		case 494: return "BUILDJOB_CHAIR_ASSIGN";
		case 495: return "BUILDJOB_CHAIR_FREE";
		case 496: return "BUILDJOB_CHAIR_SIZE";
		case 497: return "BUILDJOB_TABLE_ASSIGN";
		case 498: return "BUILDJOB_TABLE_HALL";
		case 499: return "BUILDJOB_TABLE_FREE";
		case 500: return "BUILDJOB_TABLE_SIZE";
		case 501: return "BUILDJOB_BED_ASSIGN";
		case 502: return "BUILDJOB_BED_FREE";
		case 503: return "BUILDJOB_BED_BARRACKS";
		case 504: return "BUILDJOB_BED_DORMITORY";
		case 505: return "BUILDJOB_BED_RENT";
		case 506: return "BUILDJOB_BED_SIZE";
		case 507: return "BUILDJOB_BED_SLEEP";
		case 508: return "BUILDJOB_BED_TRAIN";
		case 509: return "BUILDJOB_BED_INDIV_EQ";
		case 510: return "BUILDJOB_BED_SQUAD_EQ";
		case 511: return "BUILDJOB_BED_POSITION";
		case 512: return "BUILDJOB_DEPOT_BRING";
		case 513: return "BUILDJOB_DEPOT_TRADE";
		case 514: return "BUILDJOB_DEPOT_REQUEST_TRADER";
		case 515: return "BUILDJOB_DEPOT_BROKER_ONLY";
		case 516: return "BUILDJOB_ANIMALTRAP_BAIT_NONE";
		case 517: return "BUILDJOB_ANIMALTRAP_BAIT_MEAT";
		case 518: return "BUILDJOB_ANIMALTRAP_BAIT_FISH";
		case 519: return "BUILDJOB_ANIMALTRAP_BAIT_GEM";
		case 520: return "BUILDJOB_FARM_FALLOW";
		case 521: return "BUILDJOB_FARM_FERTILIZE";
		case 522: return "BUILDJOB_FARM_SEASFERT";
		case 523: return "BUILDJOB_FARM_SPRING";
		case 524: return "BUILDJOB_FARM_SUMMER";
		case 525: return "BUILDJOB_FARM_AUTUMN";
		case 526: return "BUILDJOB_FARM_WINTER";
		case 527: return "BUILDJOB_RACK_MAT_BONE";
		case 528: return "BUILDJOB_RACK_MAT_BRONZE";
		case 529: return "BUILDJOB_RACK_MAT_COPPER";
		case 530: return "BUILDJOB_RACK_MAT_IRON";
		case 531: return "BUILDJOB_RACK_MAT_STEEL";
		case 532: return "BUILDJOB_RACK_MAT_WOOD";
		case 533: return "BUILDJOB_RACK_MAT_METAL";
		case 534: return "BUILDJOB_STAND_MAT_BONE";
		case 535: return "BUILDJOB_STAND_MAT_LEATHER";
		case 536: return "BUILDJOB_STAND_MAT_COPPER";
		case 537: return "BUILDJOB_STAND_MAT_BRONZE";
		case 538: return "BUILDJOB_STAND_MAT_STEEL";
		case 539: return "BUILDJOB_STAND_MAT_IRON";
		case 540: return "BUILDJOB_STAND_MAT_WOOD";
		case 541: return "BUILDJOB_STAND_MAT_METAL";
		case 542: return "BUILDJOB_RACKSTAND_ASSIGN";
		case 543: return "BUILDJOB_RACKSTAND_FREE";
		case 544: return "BUILDJOB_RACKSTAND_SIZE";
		case 545: return "BUILDJOB_RACKSTAND_ITEM";
		case 546: return "BUILDJOB_RACKSTAND_MAT";
		case 547: return "BUILDJOB_RACKSTAND_DEFAULTS1";
		case 548: return "BUILDJOB_RACKSTAND_KILL1";
		case 549: return "BUILDJOB_RACKSTAND_DEFAULTS2";
		case 550: return "BUILDJOB_RACKSTAND_KILL2";
		case 551: return "BUILDJOB_DISPLAY_FURNITURE_SET";
		case 552: return "BUILDJOB_DISPLAY_FURNITURE_CANCEL";
		case 553: return "HOTKEY_BUILDING_ARMORSTAND";
		case 554: return "HOTKEY_BUILDING_BED";
		case 555: return "HOTKEY_BUILDING_CHAIR";
		case 556: return "HOTKEY_BUILDING_COFFIN";
		case 557: return "HOTKEY_BUILDING_DOOR";
		case 558: return "HOTKEY_BUILDING_FLOODGATE";
		case 559: return "HOTKEY_BUILDING_HATCH";
		case 560: return "HOTKEY_BUILDING_GRATE_WALL";
		case 561: return "HOTKEY_BUILDING_GRATE_FLOOR";
		case 562: return "HOTKEY_BUILDING_BARS_VERTICAL";
		case 563: return "HOTKEY_BUILDING_BARS_FLOOR";
		case 564: return "HOTKEY_BUILDING_CABINET";
		case 565: return "HOTKEY_BUILDING_BOX";
		case 566: return "HOTKEY_BUILDING_KENNEL";
		case 567: return "HOTKEY_BUILDING_FARMPLOT";
		case 568: return "HOTKEY_BUILDING_WEAPONRACK";
		case 569: return "HOTKEY_BUILDING_STATUE";
		case 570: return "HOTKEY_BUILDING_TABLE";
		case 571: return "HOTKEY_BUILDING_ROAD_DIRT";
		case 572: return "HOTKEY_BUILDING_ROAD_PAVED";
		case 573: return "HOTKEY_BUILDING_BRIDGE";
		case 574: return "HOTKEY_BUILDING_WELL";
		case 575: return "HOTKEY_BUILDING_SIEGEENGINE";
		case 576: return "HOTKEY_BUILDING_WORKSHOP";
		case 577: return "HOTKEY_BUILDING_FURNACE";
		case 578: return "HOTKEY_BUILDING_WINDOW_GLASS";
		case 579: return "HOTKEY_BUILDING_WINDOW_GEM";
		case 580: return "HOTKEY_BUILDING_SHOP";
		case 581: return "HOTKEY_BUILDING_ANIMALTRAP";
		case 582: return "HOTKEY_BUILDING_CHAIN";
		case 583: return "HOTKEY_BUILDING_CAGE";
		case 584: return "HOTKEY_BUILDING_TRADEDEPOT";
		case 585: return "HOTKEY_BUILDING_TRAP";
		case 586: return "HOTKEY_BUILDING_MACHINE";
		case 587: return "HOTKEY_BUILDING_INSTRUMENT";
		case 588: return "HOTKEY_BUILDING_SUPPORT";
		case 589: return "HOTKEY_BUILDING_ARCHERYTARGET";
		case 590: return "HOTKEY_BUILDING_TRACTION_BENCH";
		case 591: return "HOTKEY_BUILDING_SLAB";
		case 592: return "HOTKEY_BUILDING_NEST_BOX";
		case 593: return "HOTKEY_BUILDING_BOOKCASE";
		case 594: return "HOTKEY_BUILDING_HIVE";
		case 595: return "HOTKEY_BUILDING_DISPLAY_FURNITURE";
		case 596: return "HOTKEY_BUILDING_MACHINE_SCREW_PUMP";
		case 597: return "HOTKEY_BUILDING_MACHINE_WATER_WHEEL";
		case 598: return "HOTKEY_BUILDING_MACHINE_WINDMILL";
		case 599: return "HOTKEY_BUILDING_MACHINE_GEAR_ASSEMBLY";
		case 600: return "HOTKEY_BUILDING_MACHINE_AXLE_VERTICAL";
		case 601: return "HOTKEY_BUILDING_MACHINE_AXLE_HORIZONTAL";
		case 602: return "HOTKEY_BUILDING_MACHINE_ROLLERS";
		case 603: return "HOTKEY_BUILDING_SIEGEENGINE_BALLISTA";
		case 604: return "HOTKEY_BUILDING_SIEGEENGINE_CATAPULT";
		case 605: return "HOTKEY_BUILDING_TRAP_STONE";
		case 606: return "HOTKEY_BUILDING_TRAP_WEAPON";
		case 607: return "HOTKEY_BUILDING_TRAP_LEVER";
		case 608: return "HOTKEY_BUILDING_TRAP_TRIGGER";
		case 609: return "HOTKEY_BUILDING_TRAP_CAGE";
		case 610: return "HOTKEY_BUILDING_TRAP_SPIKE";
		case 611: return "HOTKEY_BUILDING_CONSTRUCTION";
		case 612: return "HOTKEY_BUILDING_CONSTRUCTION_WALL";
		case 613: return "HOTKEY_BUILDING_CONSTRUCTION_FLOOR";
		case 614: return "HOTKEY_BUILDING_CONSTRUCTION_RAMP";
		case 615: return "HOTKEY_BUILDING_CONSTRUCTION_STAIR_UP";
		case 616: return "HOTKEY_BUILDING_CONSTRUCTION_STAIR_DOWN";
		case 617: return "HOTKEY_BUILDING_CONSTRUCTION_STAIR_UPDOWN";
		case 618: return "HOTKEY_BUILDING_CONSTRUCTION_FORTIFICATION";
		case 619: return "HOTKEY_BUILDING_CONSTRUCTION_TRACK";
		case 620: return "HOTKEY_BUILDING_CONSTRUCTION_TRACK_STOP";
		case 621: return "HOTKEY_BUILDING_WORKSHOP_LEATHER";
		case 622: return "HOTKEY_BUILDING_WORKSHOP_QUERN";
		case 623: return "HOTKEY_BUILDING_WORKSHOP_MILLSTONE";
		case 624: return "HOTKEY_BUILDING_WORKSHOP_LOOM";
		case 625: return "HOTKEY_BUILDING_WORKSHOP_CLOTHES";
		case 626: return "HOTKEY_BUILDING_WORKSHOP_BOWYER";
		case 627: return "HOTKEY_BUILDING_WORKSHOP_CARPENTER";
		case 628: return "HOTKEY_BUILDING_WORKSHOP_METALSMITH";
		case 629: return "HOTKEY_BUILDING_WORKSHOP_LAVAMILL";
		case 630: return "HOTKEY_BUILDING_WORKSHOP_JEWELER";
		case 631: return "HOTKEY_BUILDING_WORKSHOP_MASON";
		case 632: return "HOTKEY_BUILDING_WORKSHOP_BUTCHER";
		case 633: return "HOTKEY_BUILDING_WORKSHOP_TANNER";
		case 634: return "HOTKEY_BUILDING_WORKSHOP_DYER";
		case 635: return "HOTKEY_BUILDING_WORKSHOP_CRAFTSMAN";
		case 636: return "HOTKEY_BUILDING_WORKSHOP_SIEGE";
		case 637: return "HOTKEY_BUILDING_WORKSHOP_MECHANIC";
		case 638: return "HOTKEY_BUILDING_WORKSHOP_STILL";
		case 639: return "HOTKEY_BUILDING_WORKSHOP_FARMER";
		case 640: return "HOTKEY_BUILDING_WORKSHOP_KITCHEN";
		case 641: return "HOTKEY_BUILDING_WORKSHOP_FISHERY";
		case 642: return "HOTKEY_BUILDING_WORKSHOP_ASHERY";
		case 643: return "HOTKEY_BUILDING_FURNACE_WOOD";
		case 644: return "HOTKEY_BUILDING_FURNACE_SMELTER";
		case 645: return "HOTKEY_BUILDING_FURNACE_GLASS";
		case 646: return "HOTKEY_BUILDING_FURNACE_KILN";
		case 647: return "HOTKEY_BUILDING_FURNACE_SMELTER_LAVA";
		case 648: return "HOTKEY_BUILDING_FURNACE_GLASS_LAVA";
		case 649: return "HOTKEY_BUILDING_FURNACE_KILN_LAVA";
		case 650: return "HIVE_INSTALL_COLONY";
		case 651: return "HIVE_GATHER_PRODUCTS";
		case 652: return "BUILDING_DIM_Y_UP";
		case 653: return "BUILDING_DIM_Y_DOWN";
		case 654: return "BUILDING_DIM_X_UP";
		case 655: return "BUILDING_DIM_X_DOWN";
		case 656: return "BUILDING_ORIENT_UP";
		case 657: return "BUILDING_ORIENT_LEFT";
		case 658: return "BUILDING_ORIENT_RIGHT";
		case 659: return "BUILDING_ORIENT_DOWN";
		case 660: return "BUILDING_ORIENT_NONE";
		case 661: return "BUILDING_VIEW_ITEM";
		case 662: return "BUILDING_ADVANCE_STAGE";
		case 663: return "BUILDING_EXPAND_CONTRACT";
		case 664: return "BUILDING_TRIGGER_ENABLE_WATER";
		case 665: return "BUILDING_TRIGGER_MIN_WATER_UP";
		case 666: return "BUILDING_TRIGGER_MIN_WATER_DOWN";
		case 667: return "BUILDING_TRIGGER_MAX_WATER_UP";
		case 668: return "BUILDING_TRIGGER_MAX_WATER_DOWN";
		case 669: return "BUILDING_TRIGGER_ENABLE_MAGMA";
		case 670: return "BUILDING_TRIGGER_MIN_MAGMA_UP";
		case 671: return "BUILDING_TRIGGER_MIN_MAGMA_DOWN";
		case 672: return "BUILDING_TRIGGER_MAX_MAGMA_UP";
		case 673: return "BUILDING_TRIGGER_MAX_MAGMA_DOWN";
		case 674: return "BUILDING_TRIGGER_ENABLE_TRACK_CART";
		case 675: return "BUILDING_TRIGGER_MIN_TRACK_CART_DOWN";
		case 676: return "BUILDING_TRIGGER_MIN_TRACK_CART_UP";
		case 677: return "BUILDING_TRIGGER_MAX_TRACK_CART_DOWN";
		case 678: return "BUILDING_TRIGGER_MAX_TRACK_CART_UP";
		case 679: return "BUILDING_TRIGGER_ENABLE_CREATURE";
		case 680: return "BUILDING_TRIGGER_ENABLE_LOCALS";
		case 681: return "BUILDING_TRIGGER_RESETS";
		case 682: return "BUILDING_TRIGGER_MIN_SIZE_UP";
		case 683: return "BUILDING_TRIGGER_MIN_SIZE_DOWN";
		case 684: return "BUILDING_TRIGGER_MAX_SIZE_UP";
		case 685: return "BUILDING_TRIGGER_MAX_SIZE_DOWN";
		case 686: return "BUILDING_TRIGGER_MIN_SIZE_UP_PLUS";
		case 687: return "BUILDING_TRIGGER_MIN_SIZE_DOWN_PLUS";
		case 688: return "BUILDING_TRIGGER_MAX_SIZE_UP_PLUS";
		case 689: return "BUILDING_TRIGGER_MAX_SIZE_DOWN_PLUS";
		case 690: return "BUILDING_ROLLERS_SPEED_UP";
		case 691: return "BUILDING_ROLLERS_SPEED_DOWN";
		case 692: return "BUILDING_TRACK_STOP_FRICTION_UP";
		case 693: return "BUILDING_TRACK_STOP_FRICTION_DOWN";
		case 694: return "BUILDING_TRACK_STOP_DUMP";
		case 695: return "DESTROYBUILDING";
		case 696: return "SUSPENDBUILDING";
		case 697: return "BUILDINGLIST_ZOOM_T";
		case 698: return "BUILDINGLIST_ZOOM_Q";
		case 699: return "RECENTER_ON_LEVER";
		case 700: return "ASSIGN_LOCATION";
		case 701: return "LOCATION_NEW";
		case 702: return "LOCATION_RETIRE";
		case 703: return "LOCATION_INN_TAVERN";
		case 704: return "LOCATION_TEMPLE";
		case 705: return "LOCATION_LIBRARY";
		case 706: return "LOCATION_MAIN_HALL";
		case 707: return "LOCATION_RENAME";
		case 708: return "LOCATION_DETAILS";
		case 709: return "LOCATION_RESTRICTION";
		case 710: return "LOCATION_SET_NUMBER_1";
		case 711: return "LOCATION_SET_NUMBER_2";
		case 712: return "HOTKEY_MAKE_ASH";
		case 713: return "HOTKEY_MAKE_CHARCOAL";
		case 714: return "HOTKEY_MELT_OBJECT";
		case 715: return "HOTKEY_GLASS_GREEN";
		case 716: return "HOTKEY_GLASS_CLEAR";
		case 717: return "HOTKEY_GLASS_CRYSTAL";
		case 718: return "HOTKEY_COLLECT_SAND";
		case 719: return "HOTKEY_COLLECT_CLAY";
		case 720: return "HOTKEY_GLASS_ROUGH";
		case 721: return "HOTKEY_GLASS_ARMORSTAND";
		case 722: return "HOTKEY_GLASS_BOX";
		case 723: return "HOTKEY_GLASS_CABINET";
		case 724: return "HOTKEY_GLASS_COFFIN";
		case 725: return "HOTKEY_GLASS_FLOODGATE";
		case 726: return "HOTKEY_GLASS_HATCH_COVER";
		case 727: return "HOTKEY_GLASS_GRATE";
		case 728: return "HOTKEY_GLASS_GOBLET";
		case 729: return "HOTKEY_GLASS_TOY";
		case 730: return "HOTKEY_GLASS_DOOR";
		case 731: return "HOTKEY_GLASS_STATUE";
		case 732: return "HOTKEY_GLASS_TABLE";
		case 733: return "HOTKEY_GLASS_CAGE";
		case 734: return "HOTKEY_GLASS_CHAIR";
		case 735: return "HOTKEY_GLASS_BLOCKS";
		case 736: return "HOTKEY_GLASS_FLASK";
		case 737: return "HOTKEY_GLASS_WEAPONRACK";
		case 738: return "HOTKEY_GLASS_WINDOW";
		case 739: return "HOTKEY_ASHERY_LYE";
		case 740: return "HOTKEY_ASHERY_POTASH";
		case 741: return "HOTKEY_ASHERY_POTASH_DIRECT";
		case 742: return "HOTKEY_CARPENTER_BARREL";
		case 743: return "HOTKEY_CARPENTER_BLOCKS";
		case 744: return "HOTKEY_CARPENTER_BUCKET";
		case 745: return "HOTKEY_CARPENTER_TRAP_ANIMAL";
		case 746: return "HOTKEY_CARPENTER_CAGE";
		case 747: return "HOTKEY_CARPENTER_ARMORSTAND";
		case 748: return "HOTKEY_CARPENTER_BED";
		case 749: return "HOTKEY_CARPENTER_CHAIR";
		case 750: return "HOTKEY_CARPENTER_COFFIN";
		case 751: return "HOTKEY_CARPENTER_DOOR";
		case 752: return "HOTKEY_CARPENTER_FLOODGATE";
		case 753: return "HOTKEY_CARPENTER_HATCH_COVER";
		case 754: return "HOTKEY_CARPENTER_GRATE";
		case 755: return "HOTKEY_CARPENTER_CABINET";
		case 756: return "HOTKEY_CARPENTER_BIN";
		case 757: return "HOTKEY_CARPENTER_BOX";
		case 758: return "HOTKEY_CARPENTER_WEAPONRACK";
		case 759: return "HOTKEY_CARPENTER_TABLE";
		case 760: return "HOTKEY_SIEGE_BALLISTA";
		case 761: return "HOTKEY_SIEGE_CATAPULT";
		case 762: return "HOTKEY_LEATHER_BOX";
		case 763: return "HOTKEY_LEATHER_FLASK";
		case 764: return "HOTKEY_LEATHER_SHIRT";
		case 765: return "HOTKEY_LEATHER_CLOAK";
		case 766: return "HOTKEY_LEATHER_BACKPACK";
		case 767: return "HOTKEY_LEATHER_QUIVER";
		case 768: return "HOTKEY_LEATHER_IMAGE";
		case 769: return "HOTKEY_CLOTHES_MAT_PLANT";
		case 770: return "HOTKEY_CLOTHES_MAT_SILK";
		case 771: return "HOTKEY_CLOTHES_MAT_YARN";
		case 772: return "HOTKEY_CLOTHES_SHIRT";
		case 773: return "HOTKEY_CLOTHES_CLOAK";
		case 774: return "HOTKEY_CLOTHES_BOX";
		case 775: return "HOTKEY_CLOTHES_CHAIN";
		case 776: return "HOTKEY_CLOTHES_IMAGE";
		case 777: return "HOTKEY_CRAFTS_MAT_STONE";
		case 778: return "HOTKEY_CRAFTS_MAT_WOOD";
		case 779: return "HOTKEY_CRAFTS_DEC_BONE";
		case 780: return "HOTKEY_CRAFTS_DEC_SHELL";
		case 781: return "HOTKEY_CRAFTS_DEC_TOOTH";
		case 782: return "HOTKEY_CRAFTS_DEC_HORN";
		case 783: return "HOTKEY_CRAFTS_DEC_PEARL";
		case 784: return "HOTKEY_CRAFTS_TOTEM";
		case 785: return "HOTKEY_CRAFTS_CLOTH";
		case 786: return "HOTKEY_CRAFTS_SILK";
		case 787: return "HOTKEY_CRAFTS_YARN";
		case 788: return "HOTKEY_CRAFTS_SEL_WOOD";
		case 789: return "HOTKEY_CRAFTS_SEL_BONE";
		case 790: return "HOTKEY_CRAFTS_SEL_SHELL";
		case 791: return "HOTKEY_CRAFTS_SHELL";
		case 792: return "HOTKEY_CRAFTS_TOOTH";
		case 793: return "HOTKEY_CRAFTS_HORN";
		case 794: return "HOTKEY_CRAFTS_PEARL";
		case 795: return "HOTKEY_CRAFTS_BONE";
		case 796: return "HOTKEY_CRAFTS_LEATHER";
		case 797: return "HOTKEY_CRAFTS_SLAB";
		case 798: return "HOTKEY_CRAFTS_MAT_CRAFTS";
		case 799: return "HOTKEY_CRAFTS_MAT_GOBLET";
		case 800: return "HOTKEY_CRAFTS_MAT_TOY";
		case 801: return "HOTKEY_SMITH_WEAPON";
		case 802: return "HOTKEY_SMITH_ARMOR";
		case 803: return "HOTKEY_SMITH_FURNITURE";
		case 804: return "HOTKEY_SMITH_SIEGE";
		case 805: return "HOTKEY_SMITH_TRAP";
		case 806: return "HOTKEY_SMITH_OTHER";
		case 807: return "HOTKEY_SMITH_METAL";
		case 808: return "HOTKEY_ALCHEMIST_SOAP";
		case 809: return "HOTKEY_STILL_BREW";
		case 810: return "HOTKEY_STILL_EXTRACT";
		case 811: return "HOTKEY_LOOM_COLLECT_SILK";
		case 812: return "HOTKEY_LOOM_WEAVE_CLOTH";
		case 813: return "HOTKEY_LOOM_WEAVE_SILK";
		case 814: return "HOTKEY_LOOM_WEAVE_YARN";
		case 815: return "HOTKEY_LOOM_WEAVE_METAL";
		case 816: return "HOTKEY_KITCHEN_COOK_2";
		case 817: return "HOTKEY_KITCHEN_COOK_3";
		case 818: return "HOTKEY_KITCHEN_COOK_4";
		case 819: return "HOTKEY_KITCHEN_RENDER_FAT";
		case 820: return "HOTKEY_FARMER_PROCESS";
		case 821: return "HOTKEY_FARMER_PROCESS_VIAL";
		case 822: return "HOTKEY_FARMER_PROCESS_BAG";
		case 823: return "HOTKEY_FARMER_PROCESS_BARREL";
		case 824: return "HOTKEY_FARMER_CHEESE";
		case 825: return "HOTKEY_FARMER_MILK";
		case 826: return "HOTKEY_FARMER_SHEAR_CREATURE";
		case 827: return "HOTKEY_FARMER_SPIN_THREAD";
		case 828: return "HOTKEY_MILL_MILL";
		case 829: return "HOTKEY_KENNEL_CATCH_VERMIN";
		case 830: return "HOTKEY_KENNEL_TAME_VERMIN";
		case 831: return "HOTKEY_FISHERY_PROCESS";
		case 832: return "HOTKEY_FISHERY_EXTRACT";
		case 833: return "HOTKEY_FISHERY_CATCH";
		case 834: return "HOTKEY_BUTCHER_BUTCHER";
		case 835: return "HOTKEY_BUTCHER_EXTRACT";
		case 836: return "HOTKEY_BUTCHER_CATCH";
		case 837: return "HOTKEY_TANNER_TAN";
		case 838: return "HOTKEY_DYER_THREAD";
		case 839: return "HOTKEY_DYER_CLOTH";
		case 840: return "HOTKEY_JEWELER_FURNITURE";
		case 841: return "HOTKEY_JEWELER_FINISHED";
		case 842: return "HOTKEY_JEWELER_AMMO";
		case 843: return "HOTKEY_JEWELER_CUT";
		case 844: return "HOTKEY_JEWELER_ENCRUST";
		case 845: return "HOTKEY_MECHANIC_PARTS";
		case 846: return "HOTKEY_MECHANIC_TRACTION_BENCH";
		case 847: return "HOTKEY_MASON_ARMORSTAND";
		case 848: return "HOTKEY_MASON_BLOCKS";
		case 849: return "HOTKEY_MASON_CHAIR";
		case 850: return "HOTKEY_MASON_COFFIN";
		case 851: return "HOTKEY_MASON_DOOR";
		case 852: return "HOTKEY_MASON_FLOODGATE";
		case 853: return "HOTKEY_MASON_HATCH_COVER";
		case 854: return "HOTKEY_MASON_GRATE";
		case 855: return "HOTKEY_MASON_CABINET";
		case 856: return "HOTKEY_MASON_BOX";
		case 857: return "HOTKEY_MASON_STATUE";
		case 858: return "HOTKEY_MASON_TABLE";
		case 859: return "HOTKEY_MASON_WEAPONRACK";
		case 860: return "HOTKEY_MASON_QUERN";
		case 861: return "HOTKEY_MASON_MILLSTONE";
		case 862: return "HOTKEY_MASON_SLAB";
		case 863: return "HOTKEY_TRAP_BRIDGE";
		case 864: return "HOTKEY_TRAP_DOOR";
		case 865: return "HOTKEY_TRAP_FLOODGATE";
		case 866: return "HOTKEY_TRAP_SPIKE";
		case 867: return "HOTKEY_TRAP_HATCH";
		case 868: return "HOTKEY_TRAP_GRATE_WALL";
		case 869: return "HOTKEY_TRAP_GRATE_FLOOR";
		case 870: return "HOTKEY_TRAP_BARS_VERTICAL";
		case 871: return "HOTKEY_TRAP_BARS_FLOOR";
		case 872: return "HOTKEY_TRAP_SUPPORT";
		case 873: return "HOTKEY_TRAP_CHAIN";
		case 874: return "HOTKEY_TRAP_CAGE";
		case 875: return "HOTKEY_TRAP_GEAR_ASSEMBLY";
		case 876: return "HOTKEY_TRAP_TRACK_STOP";
		case 877: return "HOTKEY_TRAP_PULL_LEVER";
		case 878: return "BUILDJOB_STOCKPILE_MASTER";
		case 879: return "BUILDJOB_STOCKPILE_LINK_ANYWHERE";
		case 880: return "BUILDJOB_STOCKPILE_GIVE_TO";
		case 881: return "BUILDJOB_STOCKPILE_DELETE_CHILD";
		case 882: return "BUILDJOB_STOCKPILE_SETTINGS";
		case 883: return "BUILDJOB_STOCKPILE_BARREL_UP";
		case 884: return "BUILDJOB_STOCKPILE_BARREL_DOWN";
		case 885: return "BUILDJOB_STOCKPILE_BARREL_ZERO";
		case 886: return "BUILDJOB_STOCKPILE_BARREL_MAX";
		case 887: return "BUILDJOB_STOCKPILE_BIN_UP";
		case 888: return "BUILDJOB_STOCKPILE_BIN_DOWN";
		case 889: return "BUILDJOB_STOCKPILE_BIN_ZERO";
		case 890: return "BUILDJOB_STOCKPILE_BIN_MAX";
		case 891: return "BUILDJOB_STOCKPILE_WHEELBARROW";
		case 892: return "STOCKPILE_ANIMAL";
		case 893: return "STOCKPILE_FOOD";
		case 894: return "STOCKPILE_WEAPON";
		case 895: return "STOCKPILE_ARMOR";
		case 896: return "STOCKPILE_CUSTOM";
		case 897: return "STOCKPILE_CUSTOM_SETTINGS";
		case 898: return "STOCKPILE_FURNITURE";
		case 899: return "STOCKPILE_GRAVEYARD";
		case 900: return "STOCKPILE_REFUSE";
		case 901: return "STOCKPILE_WOOD";
		case 902: return "STOCKPILE_STONE";
		case 903: return "STOCKPILE_GEM";
		case 904: return "STOCKPILE_BARBLOCK";
		case 905: return "STOCKPILE_CLOTH";
		case 906: return "STOCKPILE_LEATHER";
		case 907: return "STOCKPILE_AMMO";
		case 908: return "STOCKPILE_COINS";
		case 909: return "STOCKPILE_FINISHED";
		case 910: return "STOCKPILE_SHEET";
		case 911: return "STOCKPILE_NONE";
		case 912: return "STOCKPILE_SETTINGS_ENABLE";
		case 913: return "STOCKPILE_SETTINGS_DISABLE";
		case 914: return "STOCKPILE_SETTINGS_PERMIT_ALL";
		case 915: return "STOCKPILE_SETTINGS_FORBID_ALL";
		case 916: return "STOCKPILE_SETTINGS_PERMIT_SUB";
		case 917: return "STOCKPILE_SETTINGS_FORBID_SUB";
		case 918: return "STOCKPILE_SETTINGS_SPECIFIC1";
		case 919: return "STOCKPILE_SETTINGS_SPECIFIC2";
		case 920: return "CIVZONE_NAME";
		case 921: return "CIVZONE_REMOVE";
		case 922: return "CIVZONE_REMOVE_ZONE";
		case 923: return "CIVZONE_SHAPE";
		case 924: return "CIVZONE_NEXT";
		case 925: return "CIVZONE_WATER_SOURCE";
		case 926: return "CIVZONE_FISH";
		case 927: return "CIVZONE_GATHER";
		case 928: return "CIVZONE_DUMP";
		case 929: return "CIVZONE_POND";
		case 930: return "CIVZONE_HOSPITAL";
		case 931: return "CIVZONE_SAND_COLLECT";
		case 932: return "CIVZONE_CLAY_COLLECT";
		case 933: return "CIVZONE_ACTIVE";
		case 934: return "CIVZONE_MEETING";
		case 935: return "CIVZONE_ANIMAL_TRAINING";
		case 936: return "CIVZONE_PEN";
		case 937: return "CIVZONE_PEN_OPTIONS";
		case 938: return "CIVZONE_POND_OPTIONS";
		case 939: return "CIVZONE_POND_WATER";
		case 940: return "CIVZONE_HOSPITAL_OPTIONS";
		case 941: return "CIVZONE_GATHER_OPTIONS";
		case 942: return "CIVZONE_GATHER_OPTIONS_PICK_TREES";
		case 943: return "CIVZONE_GATHER_OPTIONS_PICK_SHRUBS";
		case 944: return "CIVZONE_GATHER_OPTIONS_GATHER_FALLEN";
		case 945: return "STORES_VIEW";
		case 946: return "STORES_ZOOM";
		case 947: return "STORES_FORBID";
		case 948: return "STORES_MELT";
		case 949: return "STORES_DUMP";
		case 950: return "STORES_HIDE";
		case 951: return "PET_BUTCHER";
		case 952: return "PET_GELD";
		case 953: return "ANIMAL_SELECT_TRAINER";
		case 954: return "ANIMAL_WAR_TRAINING";
		case 955: return "ANIMAL_HUNTING_TRAINING";
		case 956: return "KITCHEN_COOK";
		case 957: return "KITCHEN_BREW";
		case 958: return "ORDERS_AUTOFORBID";
		case 959: return "ORDERS_FORBID_PROJECTILE";
		case 960: return "ORDERS_FORBID_YOUR_CORPSE";
		case 961: return "ORDERS_FORBID_YOUR_ITEMS";
		case 962: return "ORDERS_FORBID_OTHER_CORPSE";
		case 963: return "ORDERS_FORBID_OTHER_ITEMS";
		case 964: return "ORDERS_REFUSE_GATHER";
		case 965: return "ORDERS_REFUSE_OUTSIDE";
		case 966: return "ORDERS_REFUSE_OUTSIDE_VERMIN";
		case 967: return "ORDERS_REFUSE_DUMP_CORPSE";
		case 968: return "ORDERS_REFUSE_DUMP_SKULL";
		case 969: return "ORDERS_REFUSE_DUMP_BONE";
		case 970: return "ORDERS_REFUSE_DUMP_SHELL";
		case 971: return "ORDERS_REFUSE_DUMP_SKIN";
		case 972: return "ORDERS_REFUSE_DUMP_OTHER";
		case 973: return "ORDERS_REFUSE_DUMP_STRAND_TISSUE";
		case 974: return "ORDERS_GATHER_FURNITURE";
		case 975: return "ORDERS_GATHER_ANIMALS";
		case 976: return "ORDERS_GATHER_FOOD";
		case 977: return "ORDERS_GATHER_BODIES";
		case 978: return "ORDERS_REFUSE";
		case 979: return "ORDERS_GATHER_STONE";
		case 980: return "ORDERS_GATHER_WOOD";
		case 981: return "ORDERS_ALL_HARVEST";
		case 982: return "ORDERS_SAMEPILE";
		case 983: return "ORDERS_MIXFOODS";
		case 984: return "ORDERS_LOOM";
		case 985: return "ORDERS_DYED_CLOTH";
		case 986: return "ORDERS_EXCEPTIONS";
		case 987: return "ORDERS_WORKSHOP";
		case 988: return "ORDERS_COLLECT_WEB";
		case 989: return "ORDERS_SLAUGHTER";
		case 990: return "ORDERS_BUTCHER";
		case 991: return "ORDERS_TAN";
		case 992: return "ORDERS_AUTO_FISHERY";
		case 993: return "ORDERS_AUTO_KITCHEN";
		case 994: return "ORDERS_AUTO_KILN";
		case 995: return "ORDERS_AUTO_SMELTER";
		case 996: return "ORDERS_AUTO_OTHER";
		case 997: return "ORDERS_ZONE";
		case 998: return "ORDERS_ZONE_DRINKING";
		case 999: return "ORDERS_ZONE_FISHING";
		case 1000: return "D_ONESTEP";
		case 1001: return "D_PAUSE";
		case 1002: return "D_DEPOT";
		case 1003: return "D_HOT_KEYS";
		case 1004: return "D_HOTKEY1";
		case 1005: return "D_HOTKEY2";
		case 1006: return "D_HOTKEY3";
		case 1007: return "D_HOTKEY4";
		case 1008: return "D_HOTKEY5";
		case 1009: return "D_HOTKEY6";
		case 1010: return "D_HOTKEY7";
		case 1011: return "D_HOTKEY8";
		case 1012: return "D_HOTKEY9";
		case 1013: return "D_HOTKEY10";
		case 1014: return "D_HOTKEY11";
		case 1015: return "D_HOTKEY12";
		case 1016: return "D_HOTKEY13";
		case 1017: return "D_HOTKEY14";
		case 1018: return "D_HOTKEY15";
		case 1019: return "D_HOTKEY16";
		case 1020: return "D_HOTKEY_CHANGE_NAME";
		case 1021: return "D_HOTKEY_ZOOM";
		case 1022: return "D_ANNOUNCE";
		case 1023: return "D_REPORTS";
		case 1024: return "D_BUILDING";
		case 1025: return "D_CIVLIST";
		case 1026: return "D_DESIGNATE";
		case 1027: return "D_ARTLIST";
		case 1028: return "D_NOBLES";
		case 1029: return "D_ORDERS";
		case 1030: return "D_PETITIONS";
		case 1031: return "D_LOCATIONS";
		case 1032: return "D_MILITARY";
		case 1033: return "D_ROOMS";
		case 1034: return "D_SQUADS";
		case 1035: return "D_STOCKPILES";
		case 1036: return "D_CIVZONE";
		case 1037: return "D_VIEWUNIT";
		case 1038: return "D_JOBLIST";
		case 1039: return "D_UNITLIST";
		case 1040: return "D_LOOK";
		case 1041: return "D_HAULING";
		case 1042: return "D_HAULING_NEW_ROUTE";
		case 1043: return "D_HAULING_NEW_STOP";
		case 1044: return "D_HAULING_REMOVE";
		case 1045: return "D_HAULING_PROMOTE";
		case 1046: return "D_HAULING_VEHICLE";
		case 1047: return "D_HAULING_NICKNAME";
		case 1048: return "D_HAULING_STOP_NEW_DEPART";
		case 1049: return "D_HAULING_STOP_NEW_LINK";
		case 1050: return "D_HAULING_STOP_REMOVE";
		case 1051: return "D_HAULING_STOP_SL_SELECT_PILE";
		case 1052: return "D_HAULING_STOP_SL_TAKE_GIVE";
		case 1053: return "D_HAULING_STOP_LC_DIR";
		case 1054: return "D_HAULING_STOP_LC_MODE";
		case 1055: return "D_HAULING_STOP_LC_TIMER_UP";
		case 1056: return "D_HAULING_STOP_LC_TIMER_DOWN";
		case 1057: return "D_HAULING_STOP_LC_FULLNESS_UP";
		case 1058: return "D_HAULING_STOP_LC_FULLNESS_DOWN";
		case 1059: return "D_HAULING_STOP_LC_MORE_LESS";
		case 1060: return "D_HAULING_STOP_LC_DESIRED_TOTAL";
		case 1061: return "D_HAULING_STOP_LC_CHANGE";
		case 1062: return "D_HAULING_STOP_LC_ADVANCED";
		case 1063: return "D_BURROWS";
		case 1064: return "D_BURROWS_ADD";
		case 1065: return "D_BURROWS_DELETE";
		case 1066: return "D_BURROWS_DEFINE";
		case 1067: return "D_BURROWS_ADD_UNIT";
		case 1068: return "D_BURROWS_WORKSHOP_LIMIT";
		case 1069: return "D_BURROWS_CENTER";
		case 1070: return "D_BURROWS_NAME";
		case 1071: return "D_BURROWS_CHANGE_SELECTION";
		case 1072: return "D_BURROWS_BRUSH";
		case 1073: return "D_BURROWS_REMOVE";
		case 1074: return "D_NOTE";
		case 1075: return "D_NOTE_PLACE";
		case 1076: return "D_NOTE_DELETE";
		case 1077: return "D_NOTE_NAME";
		case 1078: return "D_NOTE_ENTER";
		case 1079: return "D_NOTE_ADOPT_SYMBOL";
		case 1080: return "D_NOTE_CHANGE_SELECTION";
		case 1081: return "D_NOTE_POINTS";
		case 1082: return "D_NOTE_ROUTE";
		case 1083: return "D_NOTE_ROUTE_ADD";
		case 1084: return "D_NOTE_ROUTE_EDIT";
		case 1085: return "D_NOTE_ROUTE_DELETE";
		case 1086: return "D_NOTE_ROUTE_CENTER";
		case 1087: return "D_NOTE_ROUTE_NAME";
		case 1088: return "D_BUILDJOB";
		case 1089: return "D_STATUS";
		case 1090: return "D_STATUS_OVERALL_HEALTH_RECENTER";
		case 1091: return "D_BUILDITEM";
		case 1092: return "D_BITEM_FORBID";
		case 1093: return "D_BITEM_DUMP";
		case 1094: return "D_BITEM_MELT";
		case 1095: return "D_BITEM_HIDE";
		case 1096: return "D_BITEM_NAME";
		case 1097: return "D_LOOK_FORBID";
		case 1098: return "D_LOOK_DUMP";
		case 1099: return "D_LOOK_MELT";
		case 1100: return "D_LOOK_HIDE";
		case 1101: return "D_LOOK_FOLLOW";
		case 1102: return "D_LOOK_ARENA_CREATURE";
		case 1103: return "D_LOOK_ARENA_ADV_MODE";
		case 1104: return "D_LOOK_ARENA_WATER";
		case 1105: return "D_LOOK_ARENA_MAGMA";
		case 1106: return "ARENA_CREATURE_SIDE_DOWN";
		case 1107: return "ARENA_CREATURE_SIDE_UP";
		case 1108: return "ARENA_CREATURE_NEW_ITEM";
		case 1109: return "ARENA_CREATURE_BLANK_LIST";
		case 1110: return "ARENA_CREATURE_REMOVE_ITEM";
		case 1111: return "ARENA_CREATURE_UNDEAD";
		case 1112: return "ARENA_CREATURE_STRING";
		case 1113: return "ARENA_CONFLICT_STATE_1";
		case 1114: return "ARENA_CONFLICT_STATE_2";
		case 1115: return "ARENA_MORALE";
		case 1116: return "ARENA_WEATHER";
		case 1117: return "ARENA_WEATHER_SNOW";
		case 1118: return "ARENA_WEATHER_MUD";
		case 1119: return "ARENA_WEATHER_CLEAR_SPATTER";
		case 1120: return "D_LOOK_ARENA_TREE";
		case 1121: return "ARENA_TREE_FILTER";
		case 1122: return "ARENA_TREE_AGE";
		case 1123: return "D_LOOK_ARENA_MOUNT";
		case 1124: return "ASSIGNTRADE_VIEW";
		case 1125: return "ASSIGNTRADE_STRING";
		case 1126: return "ASSIGNTRADE_EXCLUDE_PROHIBITED";
		case 1127: return "ASSIGNTRADE_PENDING";
		case 1128: return "ASSIGNTRADE_SORT";
		case 1129: return "NOBLELIST_REPLACE";
		case 1130: return "NOBLELIST_SETTINGS";
		case 1131: return "NOBLELIST_CAPITAL";
		case 1132: return "NOBLELIST_VIEW_CANDIDATE";
		case 1133: return "TRADE_VIEW";
		case 1134: return "TRADE_TRADE";
		case 1135: return "TRADE_OFFER";
		case 1136: return "TRADE_SEIZE";
		case 1137: return "MILITARY_ACTIVATE";
		case 1138: return "MILITARY_VIEW";
		case 1139: return "MILITARY_WEAPON";
		case 1140: return "MILITARY_ZOOM";
		case 1141: return "ANNOUNCE_ZOOM";
		case 1142: return "ANNOUNCE_ZOOM_2";
		case 1143: return "UNITJOB_REMOVE_CRE";
		case 1144: return "UNITJOB_ZOOM_CRE";
		case 1145: return "UNITJOB_ZOOM_BUILD";
		case 1146: return "UNITJOB_VIEW_UNIT";
		case 1147: return "UNITJOB_VIEW_JOB";
		case 1148: return "UNITJOB_MANAGER";
		case 1149: return "MANAGER_NEW_ORDER";
		case 1150: return "MANAGER_REMOVE";
		case 1151: return "MANAGER_PROMOTE";
		case 1152: return "MANAGER_MAX";
		case 1153: return "MANAGER_WAGES";
		case 1154: return "MANAGER_CONDITIONS";
		case 1155: return "MANAGER_DETAILS";
		case 1156: return "WORK_ORDER_CONDITION_ADD_ITEM";
		case 1157: return "WORK_ORDER_CONDITION_ADD_ORDER";
		case 1158: return "WORK_ORDER_CONDITION_ITEM_TYPE";
		case 1159: return "WORK_ORDER_CONDITION_ITEM_MATERIAL";
		case 1160: return "WORK_ORDER_CONDITION_ITEM_TRAITS";
		case 1161: return "WORK_ORDER_CONDITION_ITEM_INEQUALITY";
		case 1162: return "WORK_ORDER_CONDITION_ITEM_NUMBER";
		case 1163: return "WORK_ORDER_CONDITION_DELETE";
		case 1164: return "WORK_ORDER_CONDITION_ORDER_ACTIVATION";
		case 1165: return "WORK_ORDER_CONDITION_REAGENTS";
		case 1166: return "WORK_ORDER_CONDITION_PRODUCTS";
		case 1167: return "DESIGNATE_BITEM";
		case 1168: return "DESIGNATE_CLAIM";
		case 1169: return "DESIGNATE_UNCLAIM";
		case 1170: return "DESIGNATE_MELT";
		case 1171: return "DESIGNATE_NO_MELT";
		case 1172: return "DESIGNATE_DUMP";
		case 1173: return "DESIGNATE_NO_DUMP";
		case 1174: return "DESIGNATE_HIDE";
		case 1175: return "DESIGNATE_NO_HIDE";
		case 1176: return "DESIGNATE_DIG";
		case 1177: return "DESIGNATE_DIG_REMOVE_STAIRS_RAMPS";
		case 1178: return "DESIGNATE_TRAFFIC";
		case 1179: return "DESIGNATE_TRAFFIC_HIGH";
		case 1180: return "DESIGNATE_TRAFFIC_NORMAL";
		case 1181: return "DESIGNATE_TRAFFIC_LOW";
		case 1182: return "DESIGNATE_TRAFFIC_RESTRICTED";
		case 1183: return "DESIGNATE_TRAFFIC_INCREASE_WEIGHT";
		case 1184: return "DESIGNATE_TRAFFIC_DECREASE_WEIGHT";
		case 1185: return "DESIGNATE_TRAFFIC_INCREASE_WEIGHT_MORE";
		case 1186: return "DESIGNATE_TRAFFIC_DECREASE_WEIGHT_MORE";
		case 1187: return "DESIGNATE_STAIR_UP";
		case 1188: return "DESIGNATE_STAIR_DOWN";
		case 1189: return "DESIGNATE_STAIR_UPDOWN";
		case 1190: return "DESIGNATE_RAMP";
		case 1191: return "DESIGNATE_CHANNEL";
		case 1192: return "DESIGNATE_CHOP";
		case 1193: return "DESIGNATE_PLANTS";
		case 1194: return "DESIGNATE_SMOOTH";
		case 1195: return "DESIGNATE_ENGRAVE";
		case 1196: return "DESIGNATE_DETAILS";
		case 1197: return "DESIGNATE_FORTIFY";
		case 1198: return "DESIGNATE_TRACK";
		case 1199: return "DESIGNATE_TOGGLE_ENGRAVING";
		case 1200: return "DESIGNATE_STANDARD_MARKER";
		case 1201: return "DESIGNATE_MINE_MODE";
		case 1202: return "DESIGNATE_TOGGLE_MARKER";
		case 1203: return "DESIGNATE_UNDO";
		case 1204: return "DESIGNATE_REMOVE_CONSTRUCTION";
		case 1205: return "ITEM_DESCRIPTION";
		case 1206: return "ITEM_FORBID";
		case 1207: return "ITEM_MELT";
		case 1208: return "ITEM_DUMP";
		case 1209: return "ITEM_HIDE";
		case 1210: return "UNITVIEW_CUSTOMIZE";
		case 1211: return "UNITVIEW_HEALTH";
		case 1212: return "UNITVIEW_RELATIONSHIPS";
		case 1213: return "UNITVIEW_RELATIONSHIPS_ZOOM";
		case 1214: return "UNITVIEW_RELATIONSHIPS_VIEW";
		case 1215: return "UNITVIEW_KILLS";
		case 1216: return "UNITVIEW_GEN";
		case 1217: return "UNITVIEW_INV";
		case 1218: return "UNITVIEW_PRF";
		case 1219: return "UNITVIEW_WND";
		case 1220: return "UNITVIEW_FOLLOW";
		case 1221: return "UNITVIEW_NEXT";
		case 1222: return "UNITVIEW_SLAUGHTER";
		case 1223: return "UNITVIEW_GELD";
		case 1224: return "UNITVIEW_GEN_COMBAT";
		case 1225: return "UNITVIEW_GEN_LABOR";
		case 1226: return "UNITVIEW_GEN_MISC";
		case 1227: return "UNITVIEW_PRF_PROF";
		case 1228: return "UNITVIEW_PRF_PET";
		case 1229: return "UNITVIEW_PRF_EXPEL";
		case 1230: return "UNITVIEW_PRF_VIEW";
		case 1231: return "UNITVIEW_PRF_NEW_SQUAD";
		case 1232: return "UNITVIEW_PRF_REMOVE_FROM_SQUAD";
		case 1233: return "UNITVIEW_PRF_NAME_CURRENT_SQUAD";
		case 1234: return "UNITVIEW_PRF_NAME_SELECTED_SQUAD";
		case 1235: return "UNITVIEW_PRF_OCCUPATION";
		case 1236: return "CUSTOMIZE_UNIT_NICKNAME";
		case 1237: return "CUSTOMIZE_UNIT_PROFNAME";
		case 1238: return "IMAGE_CREATOR_FILTER";
		case 1239: return "IMAGE_CREATOR_NAME";
		case 1240: return "IMAGE_CREATOR_DONE";
		case 1241: return "CIV_RAID";
		case 1242: return "CIV_CENTER_ON_FORT";
		case 1243: return "CIV_HOLDINGS";
		case 1244: return "CIV_MAP_LEGEND";
		case 1245: return "CIV_REMOVE_MISSION";
		case 1246: return "CIV_RESCUE";
		case 1247: return "CIV_RECOVER";
		case 1248: return "CIV_WORLD";
		case 1249: return "CIV_MISSIONS";
		case 1250: return "CIV_MISSION_DETAILS";
		case 1251: return "CIV_MISSION_FREE_CAPTIVES";
		case 1252: return "CIV_MISSION_RELEASE_OTHERS";
		case 1253: return "CIV_MISSION_TAKE_ARTIFACTS";
		case 1254: return "CIV_MISSION_TAKE_ITEMS";
		case 1255: return "CIV_MISSION_TAKE_LIVESTOCK";
		case 1256: return "CIV_MISSION_RAID";
		case 1257: return "CIV_MISSION_PILLAGE";
		case 1258: return "CIV_MISSION_RAZE";
		case 1259: return "CIV_MISSION_TRIBUTE_ONE_TIME";
		case 1260: return "CIV_MISSION_TRIBUTE_ONGOING";
		case 1261: return "CIV_MISSION_CONQUER";
		case 1262: return "CIV_MISSION_DEMAND_SURRENDER";
		case 1263: return "CIV_NEWS";
		case 1264: return "CIV_PEOPLE";
		case 1265: return "CIV_ARTIFACTS";
		case 1266: return "CIV_CIVS";
		case 1267: return "D_MILITARY_CREATE_SQUAD";
		case 1268: return "D_MILITARY_DISBAND_SQUAD";
		case 1269: return "D_MILITARY_CREATE_SUB_SQUAD";
		case 1270: return "D_MILITARY_CANCEL_ORDERS";
		case 1271: return "D_MILITARY_POSITIONS";
		case 1272: return "D_MILITARY_ALERTS";
		case 1273: return "D_MILITARY_ALERTS_ADD";
		case 1274: return "D_MILITARY_ALERTS_DELETE";
		case 1275: return "D_MILITARY_ALERTS_SET";
		case 1276: return "D_MILITARY_ALERTS_NAME";
		case 1277: return "D_MILITARY_ALERTS_SET_RETAIN";
		case 1278: return "D_MILITARY_EQUIP";
		case 1279: return "D_MILITARY_EQUIP_CUSTOMIZE";
		case 1280: return "D_MILITARY_EQUIP_UNIFORM";
		case 1281: return "D_MILITARY_EQUIP_PRIORITY";
		case 1282: return "D_MILITARY_UNIFORMS";
		case 1283: return "D_MILITARY_SUPPLIES";
		case 1284: return "D_MILITARY_SUPPLIES_WATER_DOWN";
		case 1285: return "D_MILITARY_SUPPLIES_WATER_UP";
		case 1286: return "D_MILITARY_SUPPLIES_FOOD_DOWN";
		case 1287: return "D_MILITARY_SUPPLIES_FOOD_UP";
		case 1288: return "D_MILITARY_AMMUNITION";
		case 1289: return "D_MILITARY_AMMUNITION_ADD_ITEM";
		case 1290: return "D_MILITARY_AMMUNITION_REMOVE_ITEM";
		case 1291: return "D_MILITARY_AMMUNITION_LOWER_AMOUNT";
		case 1292: return "D_MILITARY_AMMUNITION_RAISE_AMOUNT";
		case 1293: return "D_MILITARY_AMMUNITION_LOWER_AMOUNT_LOTS";
		case 1294: return "D_MILITARY_AMMUNITION_RAISE_AMOUNT_LOTS";
		case 1295: return "D_MILITARY_AMMUNITION_MATERIAL";
		case 1296: return "D_MILITARY_AMMUNITION_COMBAT";
		case 1297: return "D_MILITARY_AMMUNITION_TRAINING";
		case 1298: return "D_MILITARY_TRAINING";
		case 1299: return "D_MILITARY_SCHEDULE";
		case 1300: return "D_MILITARY_ADD_UNIFORM";
		case 1301: return "D_MILITARY_DELETE_UNIFORM";
		case 1302: return "D_MILITARY_NAME_UNIFORM";
		case 1303: return "D_MILITARY_NAME_SQUAD";
		case 1304: return "D_MILITARY_ADD_ARMOR";
		case 1305: return "D_MILITARY_ADD_PANTS";
		case 1306: return "D_MILITARY_ADD_HELM";
		case 1307: return "D_MILITARY_ADD_GLOVES";
		case 1308: return "D_MILITARY_ADD_BOOTS";
		case 1309: return "D_MILITARY_ADD_SHIELD";
		case 1310: return "D_MILITARY_ADD_WEAPON";
		case 1311: return "D_MILITARY_ADD_MATERIAL";
		case 1312: return "D_MILITARY_ADD_COLOR";
		case 1313: return "D_MILITARY_REPLACE_CLOTHING";
		case 1314: return "D_MILITARY_EXACT_MATCH";
		case 1315: return "D_SQUADS_MOVE";
		case 1316: return "D_SQUADS_KILL";
		case 1317: return "D_SQUADS_KILL_LIST";
		case 1318: return "D_SQUADS_KILL_RECT";
		case 1319: return "D_SQUADS_SCHEDULE";
		case 1320: return "D_SQUADS_CANCEL_ORDER";
		case 1321: return "D_SQUADS_ALERT";
		case 1322: return "D_SQUADS_SELECT_INDIVIDUALS";
		case 1323: return "D_SQUADS_CENTER";
		case 1324: return "D_SQUAD_SCH_SLEEP";
		case 1325: return "D_SQUAD_SCH_CIVILIAN_UNIFORM";
		case 1326: return "D_SQUAD_SCH_GIVE_ORDER";
		case 1327: return "D_SQUAD_SCH_EDIT_ORDER";
		case 1328: return "D_SQUAD_SCH_CANCEL_ORDER";
		case 1329: return "D_SQUAD_SCH_COPY_ORDERS";
		case 1330: return "D_SQUAD_SCH_PASTE_ORDERS";
		case 1331: return "D_SQUAD_SCH_MS_NAME";
		case 1332: return "STRING_A000";
		case 1333: return "STRING_A001";
		case 1334: return "STRING_A002";
		case 1335: return "STRING_A003";
		case 1336: return "STRING_A004";
		case 1337: return "STRING_A005";
		case 1338: return "STRING_A006";
		case 1339: return "STRING_A007";
		case 1340: return "STRING_A008";
		case 1341: return "STRING_A009";
		case 1342: return "STRING_A010";
		case 1343: return "STRING_A011";
		case 1344: return "STRING_A012";
		case 1345: return "STRING_A013";
		case 1346: return "STRING_A014";
		case 1347: return "STRING_A015";
		case 1348: return "STRING_A016";
		case 1349: return "STRING_A017";
		case 1350: return "STRING_A018";
		case 1351: return "STRING_A019";
		case 1352: return "STRING_A020";
		case 1353: return "STRING_A021";
		case 1354: return "STRING_A022";
		case 1355: return "STRING_A023";
		case 1356: return "STRING_A024";
		case 1357: return "STRING_A025";
		case 1358: return "STRING_A026";
		case 1359: return "STRING_A027";
		case 1360: return "STRING_A028";
		case 1361: return "STRING_A029";
		case 1362: return "STRING_A030";
		case 1363: return "STRING_A031";
		case 1364: return "STRING_A032";
		case 1365: return "STRING_A033";
		case 1366: return "STRING_A034";
		case 1367: return "STRING_A035";
		case 1368: return "STRING_A036";
		case 1369: return "STRING_A037";
		case 1370: return "STRING_A038";
		case 1371: return "STRING_A039";
		case 1372: return "STRING_A040";
		case 1373: return "STRING_A041";
		case 1374: return "STRING_A042";
		case 1375: return "STRING_A043";
		case 1376: return "STRING_A044";
		case 1377: return "STRING_A045";
		case 1378: return "STRING_A046";
		case 1379: return "STRING_A047";
		case 1380: return "STRING_A048";
		case 1381: return "STRING_A049";
		case 1382: return "STRING_A050";
		case 1383: return "STRING_A051";
		case 1384: return "STRING_A052";
		case 1385: return "STRING_A053";
		case 1386: return "STRING_A054";
		case 1387: return "STRING_A055";
		case 1388: return "STRING_A056";
		case 1389: return "STRING_A057";
		case 1390: return "STRING_A058";
		case 1391: return "STRING_A059";
		case 1392: return "STRING_A060";
		case 1393: return "STRING_A061";
		case 1394: return "STRING_A062";
		case 1395: return "STRING_A063";
		case 1396: return "STRING_A064";
		case 1397: return "STRING_A065";
		case 1398: return "STRING_A066";
		case 1399: return "STRING_A067";
		case 1400: return "STRING_A068";
		case 1401: return "STRING_A069";
		case 1402: return "STRING_A070";
		case 1403: return "STRING_A071";
		case 1404: return "STRING_A072";
		case 1405: return "STRING_A073";
		case 1406: return "STRING_A074";
		case 1407: return "STRING_A075";
		case 1408: return "STRING_A076";
		case 1409: return "STRING_A077";
		case 1410: return "STRING_A078";
		case 1411: return "STRING_A079";
		case 1412: return "STRING_A080";
		case 1413: return "STRING_A081";
		case 1414: return "STRING_A082";
		case 1415: return "STRING_A083";
		case 1416: return "STRING_A084";
		case 1417: return "STRING_A085";
		case 1418: return "STRING_A086";
		case 1419: return "STRING_A087";
		case 1420: return "STRING_A088";
		case 1421: return "STRING_A089";
		case 1422: return "STRING_A090";
		case 1423: return "STRING_A091";
		case 1424: return "STRING_A092";
		case 1425: return "STRING_A093";
		case 1426: return "STRING_A094";
		case 1427: return "STRING_A095";
		case 1428: return "STRING_A096";
		case 1429: return "STRING_A097";
		case 1430: return "STRING_A098";
		case 1431: return "STRING_A099";
		case 1432: return "STRING_A100";
		case 1433: return "STRING_A101";
		case 1434: return "STRING_A102";
		case 1435: return "STRING_A103";
		case 1436: return "STRING_A104";
		case 1437: return "STRING_A105";
		case 1438: return "STRING_A106";
		case 1439: return "STRING_A107";
		case 1440: return "STRING_A108";
		case 1441: return "STRING_A109";
		case 1442: return "STRING_A110";
		case 1443: return "STRING_A111";
		case 1444: return "STRING_A112";
		case 1445: return "STRING_A113";
		case 1446: return "STRING_A114";
		case 1447: return "STRING_A115";
		case 1448: return "STRING_A116";
		case 1449: return "STRING_A117";
		case 1450: return "STRING_A118";
		case 1451: return "STRING_A119";
		case 1452: return "STRING_A120";
		case 1453: return "STRING_A121";
		case 1454: return "STRING_A122";
		case 1455: return "STRING_A123";
		case 1456: return "STRING_A124";
		case 1457: return "STRING_A125";
		case 1458: return "STRING_A126";
		case 1459: return "STRING_A128";
		case 1460: return "STRING_A129";
		case 1461: return "STRING_A130";
		case 1462: return "STRING_A131";
		case 1463: return "STRING_A132";
		case 1464: return "STRING_A133";
		case 1465: return "STRING_A134";
		case 1466: return "STRING_A135";
		case 1467: return "STRING_A136";
		case 1468: return "STRING_A137";
		case 1469: return "STRING_A138";
		case 1470: return "STRING_A139";
		case 1471: return "STRING_A140";
		case 1472: return "STRING_A141";
		case 1473: return "STRING_A142";
		case 1474: return "STRING_A143";
		case 1475: return "STRING_A144";
		case 1476: return "STRING_A145";
		case 1477: return "STRING_A146";
		case 1478: return "STRING_A147";
		case 1479: return "STRING_A148";
		case 1480: return "STRING_A149";
		case 1481: return "STRING_A150";
		case 1482: return "STRING_A151";
		case 1483: return "STRING_A152";
		case 1484: return "STRING_A153";
		case 1485: return "STRING_A154";
		case 1486: return "STRING_A155";
		case 1487: return "STRING_A156";
		case 1488: return "STRING_A157";
		case 1489: return "STRING_A158";
		case 1490: return "STRING_A159";
		case 1491: return "STRING_A160";
		case 1492: return "STRING_A161";
		case 1493: return "STRING_A162";
		case 1494: return "STRING_A163";
		case 1495: return "STRING_A164";
		case 1496: return "STRING_A165";
		case 1497: return "STRING_A166";
		case 1498: return "STRING_A167";
		case 1499: return "STRING_A168";
		case 1500: return "STRING_A169";
		case 1501: return "STRING_A170";
		case 1502: return "STRING_A171";
		case 1503: return "STRING_A172";
		case 1504: return "STRING_A173";
		case 1505: return "STRING_A174";
		case 1506: return "STRING_A175";
		case 1507: return "STRING_A176";
		case 1508: return "STRING_A177";
		case 1509: return "STRING_A178";
		case 1510: return "STRING_A179";
		case 1511: return "STRING_A180";
		case 1512: return "STRING_A181";
		case 1513: return "STRING_A182";
		case 1514: return "STRING_A183";
		case 1515: return "STRING_A184";
		case 1516: return "STRING_A185";
		case 1517: return "STRING_A186";
		case 1518: return "STRING_A187";
		case 1519: return "STRING_A188";
		case 1520: return "STRING_A189";
		case 1521: return "STRING_A190";
		case 1522: return "STRING_A191";
		case 1523: return "STRING_A192";
		case 1524: return "STRING_A193";
		case 1525: return "STRING_A194";
		case 1526: return "STRING_A195";
		case 1527: return "STRING_A196";
		case 1528: return "STRING_A197";
		case 1529: return "STRING_A198";
		case 1530: return "STRING_A199";
		case 1531: return "STRING_A200";
		case 1532: return "STRING_A201";
		case 1533: return "STRING_A202";
		case 1534: return "STRING_A203";
		case 1535: return "STRING_A204";
		case 1536: return "STRING_A205";
		case 1537: return "STRING_A206";
		case 1538: return "STRING_A207";
		case 1539: return "STRING_A208";
		case 1540: return "STRING_A209";
		case 1541: return "STRING_A210";
		case 1542: return "STRING_A211";
		case 1543: return "STRING_A212";
		case 1544: return "STRING_A213";
		case 1545: return "STRING_A214";
		case 1546: return "STRING_A215";
		case 1547: return "STRING_A216";
		case 1548: return "STRING_A217";
		case 1549: return "STRING_A218";
		case 1550: return "STRING_A219";
		case 1551: return "STRING_A220";
		case 1552: return "STRING_A221";
		case 1553: return "STRING_A222";
		case 1554: return "STRING_A223";
		case 1555: return "STRING_A224";
		case 1556: return "STRING_A225";
		case 1557: return "STRING_A226";
		case 1558: return "STRING_A227";
		case 1559: return "STRING_A228";
		case 1560: return "STRING_A229";
		case 1561: return "STRING_A230";
		case 1562: return "STRING_A231";
		case 1563: return "STRING_A232";
		case 1564: return "STRING_A233";
		case 1565: return "STRING_A234";
		case 1566: return "STRING_A235";
		case 1567: return "STRING_A236";
		case 1568: return "STRING_A237";
		case 1569: return "STRING_A238";
		case 1570: return "STRING_A239";
		case 1571: return "STRING_A240";
		case 1572: return "STRING_A241";
		case 1573: return "STRING_A242";
		case 1574: return "STRING_A243";
		case 1575: return "STRING_A244";
		case 1576: return "STRING_A245";
		case 1577: return "STRING_A246";
		case 1578: return "STRING_A247";
		case 1579: return "STRING_A248";
		case 1580: return "STRING_A249";
		case 1581: return "STRING_A250";
		case 1582: return "STRING_A251";
		case 1583: return "STRING_A252";
		case 1584: return "STRING_A253";
		case 1585: return "STRING_A254";
		case 1586: return "STRING_A255";
		case 1587: return "KEYBINDING_COMPLETE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_dfhack_knowledge_scholar_flag_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::dfhack_knowledge_scholar_flag::dfhack_knowledge_scholar_flag*>(p_address);
	switch (*m_value)
	{
		case 0: return "philosophy_logic_formal_reasoning";
		case 1: return "philosophy_logic_deductive_reasoning";
		case 2: return "philosophy_logic_syllogistic_logic";
		case 3: return "philosophy_logic_hypothetical_syllogisms";
		case 4: return "philosophy_logic_propositional_logic";
		case 5: return "philosophy_logic_dialectic_reasoning";
		case 6: return "philosophy_logic_analogical_inference";
		case 7: return "philosophy_ethics_applied_medical";
		case 8: return "philosophy_ethics_individual_value";
		case 9: return "philosophy_ethics_state_consequentialism";
		case 10: return "philosophy_epistemology_truth";
		case 11: return "philosophy_epistemology_perception";
		case 12: return "philosophy_epistemology_justification";
		case 13: return "philosophy_epistemology_belief";
		case 14: return "philosophy_metaphysics_existence";
		case 15: return "philosophy_metaphysics_time";
		case 16: return "philosophy_metaphysics_mind_body";
		case 17: return "philosophy_metaphysics_objects_and_properties";
		case 18: return "philosophy_metaphysics_wholes_and_parts";
		case 19: return "philosophy_metaphysics_events";
		case 20: return "philosophy_metaphysics_processes";
		case 21: return "philosophy_metaphysics_causation";
		case 22: return "philosophy_ethics_applied_military";
		case 23: return "philosophy_ethics_applied_interpersonal_conduct";
		case 24: return "philosophy_specialized_law";
		case 25: return "philosophy_specialized_education";
		case 26: return "philosophy_specialized_language_grammar";
		case 27: return "philosophy_specialized_language_etymology";
		case 28: return "philosophy_specialized_politics_diplomacy";
		case 29: return "philosophy_specialized_politics_government_forms";
		case 30: return "philosophy_specialized_politics_economic_policy";
		case 31: return "philosophy_specialized_politics_social_welfare";
		case 32: return "philosophy_logic_inductive_reasoning";
		case 33: return "philosophy_logic_direct_inference";
		case 34: return "philosophy_aesthetics_nature_of_beauty";
		case 35: return "philosophy_aesthetics_value_of_art";
		case 36: return "philosophy_specialized_language_dictionary";
		case 64: return "mathematics_method_proof_by_contradiction";
		case 65: return "mathematics_notation_zero";
		case 66: return "mathematics_notation_negative_numbers";
		case 67: return "mathematics_notation_large_numbers";
		case 68: return "mathematics_notation_positional";
		case 69: return "mathematics_geometry_basic_objects";
		case 70: return "mathematics_method_exhaustion";
		case 71: return "mathematics_geometry_similar_and_congruent_triangles";
		case 72: return "mathematics_geometry_geometric_mean_theorem";
		case 73: return "mathematics_geometry_isosceles_base_angles_equal";
		case 74: return "mathematics_geometry_inscribed_triangle_on_diameter_is_right";
		case 75: return "mathematics_geometry_pythagorean_theorem";
		case 76: return "mathematics_geometry_pythagorean_triples_small";
		case 77: return "mathematics_geometry_pythagorean_triples_3_digit";
		case 78: return "mathematics_geometry_pythagorean_triples_4_digit";
		case 79: return "mathematics_geometry_existence_of_incommensurable_ratios";
		case 80: return "mathematics_method_axiomatic_reasoning";
		case 81: return "mathematics_numbers_unique_prime_factorization";
		case 82: return "mathematics_numbers_algorithm_for_computing_gcd";
		case 83: return "mathematics_geometry_volume_of_pyramid";
		case 84: return "mathematics_geometry_volume_of_cone";
		case 85: return "mathematics_geometry_volume_of_sphere";
		case 86: return "mathematics_geometry_pi_to_4_digits";
		case 87: return "mathematics_numbers_division_algorithm";
		case 88: return "mathematics_geometry_table_of_chord_values";
		case 89: return "mathematics_geometry_area_of_triangle_from_side_lengths";
		case 90: return "mathematics_geometry_area_of_circle";
		case 91: return "mathematics_geometry_pi_to_6_digits";
		case 92: return "mathematics_geometry_definitions_and_basic_properties_of_conic_sections";
		case 93: return "mathematics_numbers_chinese_remainder_algorithm";
		case 94: return "mathematics_geometry_area_enclosed_by_line_and_parabola";
		case 95: return "mathematics_numbers_sieve_algorithm_for_primes";
		case 96: return "mathematics_numbers_root_2_to_5_digits";
		case 97: return "mathematics_numbers_infinite_primes";
		case 98: return "mathematics_numbers_root_2_irrational";
		case 99: return "mathematics_geometry_surface_area_of_sphere";
		case 100: return "mathematics_algebra_finite_summation_formulas";
		case 101: return "mathematics_algebra_solving_linear_systems";
		case 102: return "mathematics_algebra_balancing_and_completion";
		case 103: return "mathematics_algebra_quadratic_by_completing_square";
		case 104: return "mathematics_algebra_quadratic_formula";
		case 105: return "mathematics_notation_syncopated_algebra";
		case 106: return "mathematics_geometry_law_of_sines";
		case 107: return "mathematics_geometry_angle_sum_difference_trig_identities";
		case 108: return "mathematics_algebra_pascals_triangle";
		case 109: return "mathematics_algebra_solving_higher_order_polynomials";
		case 110: return "mathematics_notation_early_symbols_for_operations";
		case 111: return "mathematics_algebra_divergence_of_harmonic_series";
		case 112: return "mathematics_geometry_properties_of_chords";
		case 128: return "history_sourcing_basic_reliability";
		case 129: return "history_sourcing_role_of_systemic_bias";
		case 130: return "history_sourcing_role_of_state_bias_and_propaganda";
		case 131: return "history_sourcing_personal_interviews";
		case 132: return "history_theory_historical_causation";
		case 133: return "history_theory_historical_cycles";
		case 134: return "history_theory_social_cohesion";
		case 135: return "history_theory_social_conflict";
		case 136: return "history_form_biography";
		case 137: return "history_form_comparative_biography";
		case 138: return "history_form_biographical_dictionaries";
		case 139: return "history_form_autobiographical_adventure";
		case 140: return "history_form_genealogy";
		case 141: return "history_form_encyclopedia";
		case 142: return "history_form_cultural_history";
		case 143: return "history_form_cultural_comparison";
		case 144: return "history_sourcing_role_of_cultural_differences";
		case 145: return "history_form_alternate_history";
		case 146: return "history_sourcing_basic_archaeology";
		case 147: return "history_form_treatise_on_tech_evolution";
		case 160: return "astronomy_phases_of_the_moon";
		case 161: return "astronomy_summer_winter_moon";
		case 162: return "astronomy_path_of_the_moon";
		case 163: return "astronomy_tides_and_the_moon";
		case 164: return "astronomy_height_of_tides_vs_moon_and_sun";
		case 165: return "astronomy_summer_winter_sun";
		case 166: return "astronomy_relationship_between_lunar_solar_year";
		case 167: return "astronomy_daylight_variation_with_solar_year";
		case 168: return "astronomy_geocentric_model";
		case 169: return "astronomy_heliocentric_model";
		case 170: return "astronomy_dates_of_lunar_and_solar_eclipses";
		case 171: return "astronomy_star_charts";
		case 172: return "astronomy_star_catalogues_100";
		case 173: return "astronomy_star_catalogues_1000";
		case 174: return "astronomy_star_color_classification";
		case 175: return "astronomy_star_magnitude_classification";
		case 176: return "astronomy_shape_of_the_world";
		case 177: return "astronomy_precession_of_equinoxes";
		case 178: return "astronomy_method_empirical_observation";
		case 179: return "astronomy_method_path_models";
		case 192: return "naturalist_method_dissection";
		case 193: return "naturalist_observation_anatomy";
		case 194: return "naturalist_theory_comparative_anatomy";
		case 195: return "naturalist_theory_classification_by_physical_features";
		case 196: return "naturalist_observation_migration_patterns";
		case 197: return "naturalist_observation_reproductive_behavior";
		case 198: return "naturalist_observation_foraging_behavior_and_diet";
		case 199: return "naturalist_theory_food_chain";
		case 200: return "naturalist_observation_social_behavior";
		case 201: return "naturalist_observation_diseases";
		case 202: return "naturalist_theory_climactic_adaptation";
		case 203: return "naturalist_observation_embriological_development";
		case 204: return "naturalist_theory_struggle_for_existence";
		case 224: return "chemistry_classification_combustibles";
		case 225: return "chemistry_classification_ores";
		case 226: return "chemistry_metallurgy_alloys";
		case 227: return "chemistry_classification_scratch_test";
		case 228: return "chemistry_classification_elemental_theory";
		case 229: return "chemistry_chemicals_adhesives";
		case 230: return "chemistry_laboratory_blast_furnace";
		case 231: return "chemistry_laboratory_alembic";
		case 232: return "chemistry_laboratory_theory_of_liquid_liquid_extraction";
		case 233: return "chemistry_laboratory_theory_of_distillation";
		case 234: return "chemistry_laboratory_theory_of_evaporation";
		case 235: return "chemistry_classification_alkali_and_acids";
		case 236: return "chemistry_laboratory_systematic_experiments";
		case 237: return "chemistry_laboratory_glass_flask";
		case 238: return "chemistry_laboratory_glass_beaker";
		case 239: return "chemistry_laboratory_glass_vial";
		case 240: return "chemistry_laboratory_glass_funnel";
		case 241: return "chemistry_laboratory_crucible";
		case 242: return "chemistry_chemicals_nitric_acid";
		case 243: return "chemistry_chemicals_sulfuric_acid";
		case 244: return "chemistry_chemicals_aqua_regia";
		case 245: return "chemistry_laboratory_glass_ampoule";
		case 246: return "chemistry_laboratory_glass_retort";
		case 247: return "chemistry_laboratory_lab_ovens";
		case 256: return "geography_surveying_basic";
		case 257: return "geography_surveying_staff";
		case 258: return "geography_cartography_basic";
		case 259: return "geography_surveying_triangulation";
		case 260: return "geography_surveying_cartographical";
		case 261: return "geography_surveying_land";
		case 262: return "geography_surveying_military";
		case 263: return "geography_surveying_engineering";
		case 264: return "geography_cartography_geological";
		case 265: return "geography_cartography_grid_system";
		case 266: return "geography_cartography_distance_scale";
		case 267: return "geography_cartography_height_measurements";
		case 268: return "geography_method_economic_data_collection";
		case 269: return "geography_cartography_economic";
		case 270: return "geography_form_atlas";
		case 271: return "geography_theory_delta_formation";
		case 272: return "geography_theory_wind_patterns";
		case 273: return "geography_theory_origin_of_rainfall_from_evap_condense";
		case 274: return "geography_theory_water_cycle";
		case 275: return "geography_theory_latitude_climate_zones";
		case 276: return "geography_cartography_accurate_maps";
		case 277: return "geography_cartography_map_projections";
		case 288: return "medicine_theory_disease_and_fouled_water";
		case 289: return "medicine_method_physical_examination";
		case 290: return "medicine_method_autopsy";
		case 291: return "medicine_theory_prognosis";
		case 292: return "medicine_tool_herbal_remedies";
		case 293: return "medicine_tool_animal_remedies";
		case 294: return "medicine_tool_mineral_remedies";
		case 295: return "medicine_tool_bandages";
		case 296: return "medicine_theory_disease_classification";
		case 297: return "medicine_theory_toxicology";
		case 298: return "medicine_theory_acute_and_chronic_conditions";
		case 299: return "medicine_theory_endemic_disease";
		case 300: return "medicine_theory_epidemic_disease";
		case 301: return "medicine_theory_exacerbation";
		case 302: return "medicine_theory_paroxysm";
		case 303: return "medicine_theory_relapse";
		case 304: return "medicine_theory_convalescence";
		case 305: return "medicine_method_treatment_of_traumatic_injuries";
		case 306: return "medicine_method_fracture_treatment";
		case 307: return "medicine_theory_fracture_classification";
		case 308: return "medicine_tool_traction_bench";
		case 309: return "medicine_method_fracture_immobilization";
		case 310: return "medicine_tool_orthopedic_cast";
		case 311: return "medicine_method_surgery_excision";
		case 312: return "medicine_method_surgery_incision";
		case 313: return "medicine_method_hernia_surgery";
		case 314: return "medicine_method_tracheotomy_surgery";
		case 315: return "medicine_method_lithotomy_surgery";
		case 316: return "medicine_method_surgery_scraping";
		case 317: return "medicine_method_surgery_draining";
		case 318: return "medicine_method_surgery_probing";
		case 319: return "medicine_method_surgery_suturing";
		case 320: return "medicine_method_surgery_ligature";
		case 321: return "medicine_theory_surgical_models";
		case 322: return "medicine_tool_mud_bags_as_surgical_models";
		case 323: return "medicine_tool_plants_as_surgical_models";
		case 324: return "medicine_tool_animals_as_surgical_models";
		case 325: return "medicine_theory_specialized_surgical_instruments";
		case 326: return "medicine_tool_forceps";
		case 327: return "medicine_tool_scalpel";
		case 328: return "medicine_tool_surgical_scissors";
		case 329: return "medicine_tool_surgical_needles";
		case 330: return "medicine_method_cataract_surgery";
		case 331: return "medicine_method_cauterization";
		case 332: return "medicine_method_anesthesia";
		case 333: return "medicine_theory_pulmonary_medicine";
		case 334: return "medicine_theory_anatomical_studies";
		case 335: return "medicine_theory_classification_of_bodily_fluids";
		case 336: return "medicine_theory_eye_anatomy";
		case 337: return "medicine_theory_motor_vs_sensory_nerves";
		case 338: return "medicine_theory_nervous_system_function";
		case 339: return "medicine_theory_reaction_time";
		case 340: return "medicine_theory_blood_vessels";
		case 341: return "medicine_theory_pulmonary_circulation";
		case 342: return "medicine_theory_comparative_anatomy";
		case 343: return "medicine_theory_the_voice";
		case 344: return "medicine_theory_classification_of_muscles";
		case 345: return "medicine_theory_classification_of_mental_illnesses";
		case 346: return "medicine_theory_treatment_of_mental_illnesses";
		case 347: return "medicine_tool_dedicated_hospitals";
		case 348: return "medicine_method_professional_hospital_staff";
		case 349: return "medicine_method_specialized_wards";
		case 350: return "medicine_method_hospital_lab";
		case 351: return "medicine_method_medical_school";
		case 352: return "medicine_method_asylum_for_mentally_ill";
		case 384: return "engineering_horology_shadow_clock";
		case 385: return "engineering_horology_water_clock";
		case 386: return "engineering_horology_conical_water_clock";
		case 387: return "engineering_horology_water_clock_reservoir";
		case 388: return "engineering_horology_astrarium";
		case 389: return "engineering_horology_hourglass";
		case 390: return "engineering_horology_mechanical_clock";
		case 391: return "engineering_machine_theory_of_pulley";
		case 392: return "engineering_machine_pulley";
		case 393: return "engineering_machine_theory_of_screw";
		case 394: return "engineering_machine_screw";
		case 395: return "engineering_machine_theory_of_wheel_and_axle";
		case 396: return "engineering_machine_windlass";
		case 397: return "engineering_machine_theory_of_wedge";
		case 398: return "engineering_machine_theory_of_lever";
		case 399: return "engineering_machine_lever";
		case 400: return "engineering_machine_straight_beam_balance";
		case 401: return "engineering_machine_theory_of_gears";
		case 402: return "engineering_machine_warded_lock";
		case 403: return "engineering_machine_tumbler_lock";
		case 404: return "engineering_machine_padlock";
		case 405: return "engineering_machine_camshaft";
		case 406: return "engineering_machine_crankshaft";
		case 407: return "engineering_machine_water_powered_sawmill";
		case 408: return "engineering_machine_chariot_odometer";
		case 409: return "engineering_machine_chain_drive";
		case 410: return "engineering_machine_mechanical_compass";
		case 411: return "engineering_machine_differential_gear";
		case 412: return "engineering_machine_combination_lock";
		case 413: return "engineering_machine_verge_escapement";
		case 414: return "engineering_machine_balance_wheel";
		case 415: return "engineering_fluid_theory_of_siphon";
		case 416: return "engineering_fluid_valves";
		case 417: return "engineering_fluid_force_pump";
		case 418: return "engineering_optics_crystal_lens";
		case 419: return "engineering_optics_water_filled_spheres";
		case 420: return "engineering_optics_glass_lens";
		case 421: return "engineering_optics_camera_obscura";
		case 422: return "engineering_optics_parabolic_mirror";
		case 423: return "engineering_optics_theory_of_color";
		case 424: return "engineering_optics_theory_of_rainbows";
		case 425: return "engineering_optics_law_of_refraction";
		case 426: return "engineering_design_models_and_templates";
		case 427: return "engineering_construction_wood_lamination";
		case 428: return "engineering_astronomy_dioptra";
		case 429: return "engineering_astronomy_astrolabe";
		case 430: return "engineering_astronomy_armillary_sphere";
		case 431: return "engineering_astronomy_spherical_astrolabe";
		case 432: return "engineering_astronomy_mural_instrument";
		case 433: return "engineering_astronomy_orrery";
		case 434: return "engineering_machine_water_powered_trip_hammer";
		case 435: return "engineering_machine_double_acting_piston_bellows";
		case 436: return "engineering_fluid_archimedes_principle";
		case 437: return "engineering_optics_atmospheric_refraction";
		case 438: return "engineering_optics_cause_of_twilight";
		case 439: return "engineering_optics_height_of_atmosphere";
		case 440: return "engineering_machine_piston";
		case 441: return "engineering_machine_crank";
		case 442: return "engineering_machine_bellows";
		case 443: return "engineering_machine_water_powered_piston_bellows";
		case 444: return "engineering_machine_water_wheel";
		case 445: return "engineering_machine_trip_hammer";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_part_of_speech_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::part_of_speech::part_of_speech*>(p_address);
	switch (*m_value)
	{
		case 0: return "Noun";
		case 1: return "NounPlural";
		case 2: return "Adjective";
		case 3: return "Prefix";
		case 4: return "Verb";
		case 5: return "Verb3rdPerson";
		case 6: return "VerbPast";
		case 7: return "VerbPassive";
		case 8: return "VerbGerund";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_sphere_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::sphere_type::sphere_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "AGRICULTURE";
		case 1: return "ANIMALS";
		case 2: return "ART";
		case 3: return "BALANCE";
		case 4: return "BEAUTY";
		case 5: return "BIRTH";
		case 6: return "BLIGHT";
		case 7: return "BOUNDARIES";
		case 8: return "CAVERNS";
		case 9: return "CHAOS";
		case 10: return "CHARITY";
		case 11: return "CHILDREN";
		case 12: return "COASTS";
		case 13: return "CONSOLATION";
		case 14: return "COURAGE";
		case 15: return "CRAFTS";
		case 16: return "CREATION";
		case 17: return "DANCE";
		case 18: return "DARKNESS";
		case 19: return "DAWN";
		case 20: return "DAY";
		case 21: return "DEATH";
		case 22: return "DEFORMITY";
		case 23: return "DEPRAVITY";
		case 24: return "DISCIPLINE";
		case 25: return "DISEASE";
		case 26: return "DREAMS";
		case 27: return "DUSK";
		case 28: return "DUTY";
		case 29: return "EARTH";
		case 30: return "FAMILY";
		case 31: return "FAME";
		case 32: return "FATE";
		case 33: return "FERTILITY";
		case 34: return "FESTIVALS";
		case 35: return "FIRE";
		case 36: return "FISH";
		case 37: return "FISHING";
		case 38: return "FOOD";
		case 39: return "FORGIVENESS";
		case 40: return "FORTRESSES";
		case 41: return "FREEDOM";
		case 42: return "GAMBLING";
		case 43: return "GAMES";
		case 44: return "GENEROSITY";
		case 45: return "HAPPINESS";
		case 46: return "HEALING";
		case 47: return "HOSPITALITY";
		case 48: return "HUNTING";
		case 49: return "INSPIRATION";
		case 50: return "JEALOUSY";
		case 51: return "JEWELS";
		case 52: return "JUSTICE";
		case 53: return "LABOR";
		case 54: return "LAKES";
		case 55: return "LAWS";
		case 56: return "LIES";
		case 57: return "LIGHT";
		case 58: return "LIGHTNING";
		case 59: return "LONGEVITY";
		case 60: return "LOVE";
		case 61: return "LOYALTY";
		case 62: return "LUCK";
		case 63: return "LUST";
		case 64: return "MARRIAGE";
		case 65: return "MERCY";
		case 66: return "METALS";
		case 67: return "MINERALS";
		case 68: return "MISERY";
		case 69: return "MIST";
		case 70: return "MOON";
		case 71: return "MOUNTAINS";
		case 72: return "MUCK";
		case 73: return "MURDER";
		case 74: return "MUSIC";
		case 75: return "NATURE";
		case 76: return "NIGHT";
		case 77: return "NIGHTMARES";
		case 78: return "OATHS";
		case 79: return "OCEANS";
		case 80: return "ORDER";
		case 81: return "PAINTING";
		case 82: return "PEACE";
		case 83: return "PERSUASION";
		case 84: return "PLANTS";
		case 85: return "POETRY";
		case 86: return "PREGNANCY";
		case 87: return "RAIN";
		case 88: return "RAINBOWS";
		case 89: return "REBIRTH";
		case 90: return "REVELRY";
		case 91: return "REVENGE";
		case 92: return "RIVERS";
		case 93: return "RULERSHIP";
		case 94: return "RUMORS";
		case 95: return "SACRIFICE";
		case 96: return "SALT";
		case 97: return "SCHOLARSHIP";
		case 98: return "SEASONS";
		case 99: return "SILENCE";
		case 100: return "SKY";
		case 101: return "SONG";
		case 102: return "SPEECH";
		case 103: return "STARS";
		case 104: return "STORMS";
		case 105: return "STRENGTH";
		case 106: return "SUICIDE";
		case 107: return "SUN";
		case 108: return "THEFT";
		case 109: return "THRALLDOM";
		case 110: return "THUNDER";
		case 111: return "TORTURE";
		case 112: return "TRADE";
		case 113: return "TRAVELERS";
		case 114: return "TREACHERY";
		case 115: return "TREES";
		case 116: return "TRICKERY";
		case 117: return "TRUTH";
		case 118: return "TWILIGHT";
		case 119: return "VALOR";
		case 120: return "VICTORY";
		case 121: return "VOLCANOS";
		case 122: return "WAR";
		case 123: return "WATER";
		case 124: return "WEALTH";
		case 125: return "WEATHER";
		case 126: return "WIND";
		case 127: return "WISDOM";
		case 128: return "WRITING";
		case 129: return "YOUTH";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_language_name_category_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::language_name_category::language_name_category*>(p_address);
	switch (*m_value)
	{
		case 0: return "Unit";
		case 1: return "Artifact";
		case 2: return "ArtifactEvil";
		case 3: return "Swamp";
		case 4: return "Desert";
		case 5: return "Forest";
		case 6: return "Mountains";
		case 7: return "Lake";
		case 8: return "Ocean";
		case 9: return "Glacier";
		case 10: return "Tundra";
		case 11: return "Grassland";
		case 12: return "Hills";
		case 13: return "Region";
		case 14: return "Cave";
		case 15: return "SwampEvil";
		case 16: return "DesertEvil";
		case 17: return "ForestEvil";
		case 18: return "MountainsEvil";
		case 19: return "LakeEvil";
		case 20: return "OceanEvil";
		case 21: return "GlacierEvil";
		case 22: return "TundraEvil";
		case 23: return "GrasslandEvil";
		case 24: return "HillsEvil";
		case 25: return "SwampGood";
		case 26: return "DesertGood";
		case 27: return "ForestGood";
		case 28: return "MountainsGood";
		case 29: return "LakeGood";
		case 30: return "OceanGood";
		case 31: return "GlacierGood";
		case 32: return "TundraGood";
		case 33: return "GrasslandGood";
		case 34: return "HillsGood";
		case 35: return "ArtImage";
		case 36: return "MountainPeak";
		case 37: return "Unknown1";
		case 38: return "Volcano";
		case 39: return "SmallIsland";
		case 40: return "Island";
		case 41: return "Continent";
		case 42: return "CommonReligion";
		case 43: return "Temple";
		case 44: return "Keep";
		case 45: return "Unknown2";
		case 46: return "SymbolArtifice";
		case 47: return "SymbolViolent";
		case 48: return "SymbolProtect";
		case 49: return "SymbolDomestic";
		case 50: return "SymbolFood";
		case 51: return "War";
		case 52: return "Battle";
		case 53: return "Siege";
		case 54: return "Road";
		case 55: return "Wall";
		case 56: return "Bridge";
		case 57: return "Tunnel";
		case 58: return "Tomb";
		case 59: return "SymbolProtect2";
		case 60: return "Library";
		case 61: return "Festival";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_nemesis_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::nemesis_flags::nemesis_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "ACTIVE_ADVENTURER";
		case 1: return "RETIRED_ADVENTURER";
		case 2: return "ADVENTURER";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_machine_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::machine_type::machine_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "standard";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_screw_pump_direction_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::screw_pump_direction::screw_pump_direction*>(p_address);
	switch (*m_value)
	{
		case 0: return "FromNorth";
		case 1: return "FromEast";
		case 2: return "FromSouth";
		case 3: return "FromWest";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tile_traffic_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tile_traffic::tile_traffic*>(p_address);
	switch (*m_value)
	{
		case 0: return "Normal";
		case 1: return "Low";
		case 2: return "High";
		case 3: return "Restricted";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tile_dig_designation_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tile_dig_designation::tile_dig_designation*>(p_address);
	switch (*m_value)
	{
		case 0: return "No";
		case 1: return "Default";
		case 2: return "UpDownStair";
		case 3: return "Channel";
		case 4: return "Ramp";
		case 5: return "DownStair";
		case 6: return "UpStair";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tile_liquid_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tile_liquid::tile_liquid*>(p_address);
	switch (*m_value)
	{
		case 0: return "Water";
		case 1: return "Magma";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tile_building_occ_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tile_building_occ::tile_building_occ*>(p_address);
	switch (*m_value)
	{
		case 0: return "None";
		case 1: return "Planned";
		case 2: return "Passable";
		case 3: return "Obstacle";
		case 4: return "Well";
		case 5: return "Floored";
		case 6: return "Impassable";
		case 7: return "Dynamic";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tile_liquid_flow_dir_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tile_liquid_flow_dir::tile_liquid_flow_dir*>(p_address);
	switch (*m_value)
	{
		case 0: return "none";
		case 1: return "south";
		case 2: return "east";
		case 3: return "northeast";
		case 4: return "west";
		case 5: return "northwest";
		case 6: return "southeast";
		case 7: return "southwest";
		case 8: return "inv_8";
		case 9: return "inv_9";
		case 10: return "north";
		case 11: return "inv_b";
		case 12: return "inv_c";
		case 13: return "inv_d";
		case 14: return "inv_e";
		case 15: return "inv_f";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_block_square_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::block_square_event_type::block_square_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "mineral";
		case 1: return "frozen_liquid";
		case 2: return "world_construction";
		case 3: return "material_spatter";
		case 4: return "grass";
		case 5: return "spoor";
		case 6: return "item_spatter";
		case 7: return "designation_priority";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_feature_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::feature_type::feature_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "outdoor_river";
		case 1: return "cave";
		case 2: return "pit";
		case 3: return "magma_pool";
		case 4: return "volcano";
		case 5: return "deep_special_tube";
		case 6: return "deep_surface_portal";
		case 7: return "subterranean_from_layer";
		case 8: return "magma_core_from_layer";
		case 9: return "underworld_from_layer";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_feature_init_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::feature_init_flags::feature_init_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "anon_1";
		case 1: return "anon_2";
		case 2: return "anon_3";
		case 3: return "Discovered";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_feature_alteration_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::feature_alteration_type::feature_alteration_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "new_pop_max";
		case 1: return "new_lava_fill_z";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_world_construction_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::world_construction_type::world_construction_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "ROAD";
		case 1: return "TUNNEL";
		case 2: return "BRIDGE";
		case 3: return "WALL";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_biome_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::biome_type::biome_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MOUNTAIN";
		case 1: return "GLACIER";
		case 2: return "TUNDRA";
		case 3: return "SWAMP_TEMPERATE_FRESHWATER";
		case 4: return "SWAMP_TEMPERATE_SALTWATER";
		case 5: return "MARSH_TEMPERATE_FRESHWATER";
		case 6: return "MARSH_TEMPERATE_SALTWATER";
		case 7: return "SWAMP_TROPICAL_FRESHWATER";
		case 8: return "SWAMP_TROPICAL_SALTWATER";
		case 9: return "SWAMP_MANGROVE";
		case 10: return "MARSH_TROPICAL_FRESHWATER";
		case 11: return "MARSH_TROPICAL_SALTWATER";
		case 12: return "FOREST_TAIGA";
		case 13: return "FOREST_TEMPERATE_CONIFER";
		case 14: return "FOREST_TEMPERATE_BROADLEAF";
		case 15: return "FOREST_TROPICAL_CONIFER";
		case 16: return "FOREST_TROPICAL_DRY_BROADLEAF";
		case 17: return "FOREST_TROPICAL_MOIST_BROADLEAF";
		case 18: return "GRASSLAND_TEMPERATE";
		case 19: return "SAVANNA_TEMPERATE";
		case 20: return "SHRUBLAND_TEMPERATE";
		case 21: return "GRASSLAND_TROPICAL";
		case 22: return "SAVANNA_TROPICAL";
		case 23: return "SHRUBLAND_TROPICAL";
		case 24: return "DESERT_BADLAND";
		case 25: return "DESERT_ROCK";
		case 26: return "DESERT_SAND";
		case 27: return "OCEAN_TROPICAL";
		case 28: return "OCEAN_TEMPERATE";
		case 29: return "OCEAN_ARCTIC";
		case 30: return "POOL_TEMPERATE_FRESHWATER";
		case 31: return "POOL_TEMPERATE_BRACKISHWATER";
		case 32: return "POOL_TEMPERATE_SALTWATER";
		case 33: return "POOL_TROPICAL_FRESHWATER";
		case 34: return "POOL_TROPICAL_BRACKISHWATER";
		case 35: return "POOL_TROPICAL_SALTWATER";
		case 36: return "LAKE_TEMPERATE_FRESHWATER";
		case 37: return "LAKE_TEMPERATE_BRACKISHWATER";
		case 38: return "LAKE_TEMPERATE_SALTWATER";
		case 39: return "LAKE_TROPICAL_FRESHWATER";
		case 40: return "LAKE_TROPICAL_BRACKISHWATER";
		case 41: return "LAKE_TROPICAL_SALTWATER";
		case 42: return "RIVER_TEMPERATE_FRESHWATER";
		case 43: return "RIVER_TEMPERATE_BRACKISHWATER";
		case 44: return "RIVER_TEMPERATE_SALTWATER";
		case 45: return "RIVER_TROPICAL_FRESHWATER";
		case 46: return "RIVER_TROPICAL_BRACKISHWATER";
		case 47: return "RIVER_TROPICAL_SALTWATER";
		case 48: return "SUBTERRANEAN_WATER";
		case 49: return "SUBTERRANEAN_CHASM";
		case 50: return "SUBTERRANEAN_LAVA";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_flow_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::flow_type::flow_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Miasma";
		case 1: return "Steam";
		case 2: return "Mist";
		case 3: return "MaterialDust";
		case 4: return "MagmaMist";
		case 5: return "Smoke";
		case 6: return "Dragonfire";
		case 7: return "Fire";
		case 8: return "Web";
		case 9: return "MaterialGas";
		case 10: return "MaterialVapor";
		case 11: return "OceanWave";
		case 12: return "SeaFoam";
		case 13: return "ItemCloud";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_flow_guide_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::flow_guide_type::flow_guide_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "TrailingFlow";
		case 1: return "ItemCloud";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_region_block_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::region_block_event_type::region_block_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "SphereField";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_craft_material_class_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::craft_material_class::craft_material_class*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Metal";
		case 1: return "Wood";
		case 2: return "Gem";
		case 3: return "Glass";
		case 4: return "Stone";
		case 5: return "Bone";
		case 6: return "Ivory";
		case 7: return "Horn";
		case 8: return "Pearl";
		case 9: return "Shell";
		case 10: return "Leather";
		case 11: return "Cloth";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_builtin_mats_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::builtin_mats::builtin_mats*>(p_address);
	switch (*m_value)
	{
		case 0: return "INORGANIC";
		case 1: return "AMBER";
		case 2: return "CORAL";
		case 3: return "GLASS_GREEN";
		case 4: return "GLASS_CLEAR";
		case 5: return "GLASS_CRYSTAL";
		case 6: return "WATER";
		case 7: return "COAL";
		case 8: return "POTASH";
		case 9: return "ASH";
		case 10: return "PEARLASH";
		case 11: return "LYE";
		case 12: return "MUD";
		case 13: return "VOMIT";
		case 14: return "SALT";
		case 15: return "FILTH_B";
		case 16: return "FILTH_Y";
		case 17: return "UNKNOWN_SUBSTANCE";
		case 18: return "GRIME";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_material_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::material_flags::material_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "BONE";
		case 1: return "MEAT";
		case 2: return "EDIBLE_VERMIN";
		case 3: return "EDIBLE_RAW";
		case 4: return "EDIBLE_COOKED";
		case 5: return "ALCOHOL";
		case 6: return "ITEMS_METAL";
		case 7: return "ITEMS_BARRED";
		case 8: return "ITEMS_SCALED";
		case 9: return "ITEMS_LEATHER";
		case 10: return "ITEMS_SOFT";
		case 11: return "ITEMS_HARD";
		case 12: return "IMPLIES_ANIMAL_KILL";
		case 13: return "ALCOHOL_PLANT";
		case 14: return "ALCOHOL_CREATURE";
		case 15: return "CHEESE_PLANT";
		case 16: return "CHEESE_CREATURE";
		case 17: return "POWDER_MISC_PLANT";
		case 18: return "POWDER_MISC_CREATURE";
		case 19: return "STOCKPILE_GLOB";
		case 20: return "LIQUID_MISC_PLANT";
		case 21: return "LIQUID_MISC_CREATURE";
		case 22: return "LIQUID_MISC_OTHER";
		case 23: return "WOOD";
		case 24: return "THREAD_PLANT";
		case 25: return "TOOTH";
		case 26: return "HORN";
		case 27: return "PEARL";
		case 28: return "SHELL";
		case 29: return "LEATHER";
		case 30: return "SILK";
		case 31: return "SOAP";
		case 32: return "ROTS";
		case 33: return "IS_DYE";
		case 34: return "POWDER_MISC";
		case 35: return "LIQUID_MISC";
		case 36: return "STRUCTURAL_PLANT_MAT";
		case 37: return "SEED_MAT";
		case 38: return "LEAF_MAT";
		case 39: return "CHEESE";
		case 40: return "ENTERS_BLOOD";
		case 41: return "BLOOD_MAP_DESCRIPTOR";
		case 42: return "ICHOR_MAP_DESCRIPTOR";
		case 43: return "GOO_MAP_DESCRIPTOR";
		case 44: return "SLIME_MAP_DESCRIPTOR";
		case 45: return "PUS_MAP_DESCRIPTOR";
		case 46: return "GENERATES_MIASMA";
		case 47: return "IS_METAL";
		case 48: return "IS_GEM";
		case 49: return "IS_GLASS";
		case 50: return "CRYSTAL_GLASSABLE";
		case 51: return "ITEMS_WEAPON";
		case 52: return "ITEMS_WEAPON_RANGED";
		case 53: return "ITEMS_ANVIL";
		case 54: return "ITEMS_AMMO";
		case 55: return "ITEMS_DIGGER";
		case 56: return "ITEMS_ARMOR";
		case 57: return "ITEMS_DELICATE";
		case 58: return "ITEMS_SIEGE_ENGINE";
		case 59: return "ITEMS_QUERN";
		case 60: return "IS_STONE";
		case 61: return "UNDIGGABLE";
		case 62: return "YARN";
		case 63: return "STOCKPILE_GLOB_PASTE";
		case 64: return "STOCKPILE_GLOB_PRESSED";
		case 65: return "DISPLAY_UNGLAZED";
		case 66: return "DO_NOT_CLEAN_GLOB";
		case 67: return "NO_STONE_STOCKPILE";
		case 68: return "STOCKPILE_THREAD_METAL";
		case 69: return "SWEAT_MAP_DESCRIPTOR";
		case 70: return "TEARS_MAP_DESCRIPTOR";
		case 71: return "SPIT_MAP_DESCRIPTOR";
		case 72: return "EVAPORATES";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_matter_state_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::matter_state::matter_state*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Solid";
		case 1: return "Liquid";
		case 2: return "Gas";
		case 3: return "Powder";
		case 4: return "Paste";
		case 5: return "Pressed";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_strain_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::strain_type::strain_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "BENDING";
		case 1: return "SHEAR";
		case 2: return "TORSION";
		case 3: return "IMPACT";
		case 4: return "TENSILE";
		case 5: return "COMPRESSIVE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_inorganic_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::inorganic_flags::inorganic_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "LAVA";
		case 1: return "GENERATED";
		case 2: return "ENVIRONMENT_NON_SOIL_OCEAN";
		case 3: return "SEDIMENTARY";
		case 4: return "SEDIMENTARY_OCEAN_SHALLOW";
		case 5: return "IGNEOUS_INTRUSIVE";
		case 6: return "IGNEOUS_EXTRUSIVE";
		case 7: return "METAMORPHIC";
		case 8: return "DEEP_SURFACE";
		case 9: return "METAL_ORE";
		case 10: return "AQUIFER";
		case 11: return "SOIL_ANY";
		case 12: return "SOIL_OCEAN";
		case 13: return "SOIL_SAND";
		case 14: return "SEDIMENTARY_OCEAN_DEEP";
		case 15: return "THREAD_METAL";
		case 16: return "SPECIAL";
		case 17: return "SOIL";
		case 18: return "DEEP_SPECIAL";
		case 19: return "DIVINE";
		case 20: return "anon_1";
		case 21: return "anon_2";
		case 22: return "anon_3";
		case 23: return "anon_4";
		case 24: return "anon_5";
		case 25: return "WAFERS";
		case 26: return "anon_6";
		case 27: return "anon_7";
		case 28: return "anon_8";
		case 29: return "anon_9";
		case 30: return "anon_10";
		case 31: return "anon_11";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_environment_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::environment_type::environment_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "SOIL";
		case 1: return "SOIL_OCEAN";
		case 2: return "SOIL_SAND";
		case 3: return "METAMORPHIC";
		case 4: return "SEDIMENTARY";
		case 5: return "IGNEOUS_INTRUSIVE";
		case 6: return "IGNEOUS_EXTRUSIVE";
		case 7: return "ALLUVIAL";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_inclusion_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::inclusion_type::inclusion_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "anon_1";
		case 1: return "VEIN";
		case 2: return "CLUSTER";
		case 3: return "CLUSTER_SMALL";
		case 4: return "CLUSTER_ONE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_organic_mat_category_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::organic_mat_category::organic_mat_category*>(p_address);
	switch (*m_value)
	{
		case 0: return "Meat";
		case 1: return "Fish";
		case 2: return "UnpreparedFish";
		case 3: return "Eggs";
		case 4: return "Plants";
		case 5: return "PlantDrink";
		case 6: return "CreatureDrink";
		case 7: return "PlantCheese";
		case 8: return "CreatureCheese";
		case 9: return "Seed";
		case 10: return "Leaf";
		case 11: return "PlantPowder";
		case 12: return "CreaturePowder";
		case 13: return "Glob";
		case 14: return "PlantLiquid";
		case 15: return "CreatureLiquid";
		case 16: return "MiscLiquid";
		case 17: return "Leather";
		case 18: return "Silk";
		case 19: return "PlantFiber";
		case 20: return "Bone";
		case 21: return "Shell";
		case 22: return "Wood";
		case 23: return "Horn";
		case 24: return "Pearl";
		case 25: return "Tooth";
		case 26: return "EdibleCheese";
		case 27: return "AnyDrink";
		case 28: return "EdiblePlant";
		case 29: return "CookableLiquid";
		case 30: return "CookablePowder";
		case 31: return "CookableSeed";
		case 32: return "CookableLeaf";
		case 33: return "Paste";
		case 34: return "Pressed";
		case 35: return "Yarn";
		case 36: return "MetalThread";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_meeting_topic_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::meeting_topic::meeting_topic*>(p_address);
	switch (*m_value)
	{
		case 0: return "DiscussCurrent";
		case 1: return "RequestPeace";
		case 2: return "TreeQuota";
		case 3: return "BecomeLandHolder";
		case 4: return "PromoteLandHolder";
		case 5: return "ExportAgreement";
		case 6: return "ImportAgreement";
		case 7: return "PleasantPlace";
		case 8: return "WorldStatus";
		case 9: return "TributeAgreement";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_meeting_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::meeting_event_type::meeting_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "AcceptAgreement";
		case 1: return "RejectAgreement";
		case 2: return "AcceptPeace";
		case 3: return "RejectPeace";
		case 4: return "ExportAgreement";
		case 5: return "ImportAgreement";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_activity_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::activity_event_type::activity_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "TrainingSession";
		case 1: return "CombatTraining";
		case 2: return "SkillDemonstration";
		case 3: return "IndividualSkillDrill";
		case 4: return "Sparring";
		case 5: return "RangedPractice";
		case 6: return "Harassment";
		case 7: return "Conversation";
		case 8: return "Conflict";
		case 9: return "Guard";
		case 10: return "Reunion";
		case 11: return "Prayer";
		case 12: return "Socialize";
		case 13: return "Worship";
		case 14: return "Performance";
		case 15: return "Research";
		case 16: return "PonderTopic";
		case 17: return "DiscussTopic";
		case 18: return "Read";
		case 19: return "FillServiceOrder";
		case 20: return "Write";
		case 21: return "CopyWrittenContent";
		case 22: return "TeachTopic";
		case 23: return "Play";
		case 24: return "MakeBelieve";
		case 25: return "PlayWithToy";
		case 26: return "Encounter";
		case 27: return "StoreObject";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_conversation_menu_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::conversation_menu::conversation_menu*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "RespondGreeting";
		case 1: return "MainMenu";
		case 2: return "anon_1";
		case 3: return "anon_2";
		case 4: return "anon_3";
		case 5: return "anon_4";
		case 6: return "anon_5";
		case 7: return "RespondGoodbye";
		case 8: return "anon_6";
		case 9: return "DenyPermissionSleep";
		case 10: return "AskJoin";
		case 11: return "RespondJoin";
		case 12: return "DiscussRescue";
		case 13: return "DiscussAgreement";
		case 14: return "DiscussTrade";
		case 15: return "DiscussSurroundingArea";
		case 16: return "RespondAccusation";
		case 17: return "DiscussFamily";
		case 18: return "RespondArmistice";
		case 19: return "RespondDemandYield";
		case 20: return "anon_7";
		case 21: return "anon_8";
		case 22: return "anon_9";
		case 23: return "AskDirections";
		case 24: return "anon_10";
		case 25: return "anon_11";
		case 26: return "anon_12";
		case 27: return "anon_13";
		case 28: return "anon_14";
		case 29: return "anon_15";
		case 30: return "Demand";
		case 31: return "anon_16";
		case 32: return "anon_17";
		case 33: return "anon_18";
		case 34: return "Barter";
		case 35: return "DiscussHearthpersonDuties";
		case 36: return "anon_19";
		case 37: return "DiscussJourney";
		case 38: return "DiscussGroup";
		case 39: return "DiscussConflict";
		case 40: return "DiscussSite";
		case 41: return "RespondDemand";
		case 42: return "anon_20";
		case 43: return "RespondTributeDemand";
		case 44: return "RespondTributeOffer";
		case 45: return "DiscussTradeCancellation";
		case 46: return "RespondPeaceOffer";
		case 47: return "DiscussAgreementConclusion";
		case 48: return "RespondAdoptionRequest";
		case 49: return "anon_21";
		case 50: return "anon_22";
		case 51: return "RespondPositionOffer";
		case 52: return "RespondInvocation";
		case 53: return "anon_23";
		case 54: return "AskAboutPerson";
		case 55: return "anon_24";
		case 56: return "DiscussFeelings";
		case 57: return "anon_25";
		case 58: return "anon_26";
		case 59: return "anon_27";
		case 60: return "anon_28";
		case 61: return "anon_29";
		case 62: return "anon_30";
		case 63: return "anon_31";
		case 64: return "anon_32";
		case 65: return "StateGeneralThoughts";
		case 66: return "DiscussValues";
		case 67: return "RespondValues";
		case 68: return "RespondPassiveReply";
		case 69: return "RespondFlattery";
		case 70: return "RespondDismissal";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_performance_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::performance_event_type::performance_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "STORY";
		case 1: return "POETRY";
		case 2: return "MUSIC";
		case 3: return "DANCE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_performance_participant_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::performance_participant_type::performance_participant_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "TELL_STORY";
		case 1: return "RECITE_POETRY";
		case 2: return "MAKE_MUSIC";
		case 3: return "PERFORM_DANCE";
		case 4: return "LISTEN";
		case 5: return "HEAR";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_uniform_category_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::uniform_category::uniform_category*>(p_address);
	switch (*m_value)
	{
		case 0: return "body";
		case 1: return "head";
		case 2: return "pants";
		case 3: return "gloves";
		case 4: return "shoes";
		case 5: return "shield";
		case 6: return "weapon";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_barrack_preference_category_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::barrack_preference_category::barrack_preference_category*>(p_address);
	switch (*m_value)
	{
		case 0: return "Bed";
		case 1: return "Armorstand";
		case 2: return "Box";
		case 3: return "Cabinet";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_squad_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::squad_event_type::squad_event_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Unk0";
		case 1: return "Unk1";
		case 2: return "Unk2";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_squad_order_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::squad_order_type::squad_order_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MOVE";
		case 1: return "KILL_LIST";
		case 2: return "DEFEND_BURROWS";
		case 3: return "PATROL_ROUTE";
		case 4: return "TRAIN";
		case 5: return "DRIVE_ENTITY_OFF_SITE";
		case 6: return "CAUSE_TROUBLE_FOR_ENTITY";
		case 7: return "KILL_HF";
		case 8: return "DRIVE_ARMIES_FROM_SITE";
		case 9: return "RETRIEVE_ARTIFACT";
		case 10: return "RAID_SITE";
		case 11: return "RESCUE_HF";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_squad_order_cannot_reason_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::squad_order_cannot_reason::squad_order_cannot_reason*>(p_address);
	switch (*m_value)
	{
		case 0: return "not_following_order";
		case 1: return "activity_cancelled";
		case 2: return "no_barracks";
		case 3: return "improper_barracks";
		case 4: return "no_activity";
		case 5: return "cannot_individually_drill";
		case 6: return "does_not_exist";
		case 7: return "no_archery_target";
		case 8: return "improper_building";
		case 9: return "unreachable_location";
		case 10: return "invalid_location";
		case 11: return "no_reachable_valid_target";
		case 12: return "no_burrow";
		case 13: return "not_in_squad";
		case 14: return "no_patrol_route";
		case 15: return "no_reachable_point_on_route";
		case 16: return "invalid_order";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_army_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::army_flags::army_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "player";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_path_goal_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::unit_path_goal::unit_path_goal*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "ComeToJobBuilding";
		case 1: return "ValidPondDumpUnit";
		case 2: return "ValidPondDump";
		case 3: return "ConflictDefense";
		case 4: return "AdventureMove";
		case 5: return "MarauderMill";
		case 6: return "WildernessCuriousStealTarget";
		case 7: return "WildernessRoamer";
		case 8: return "ThiefTarget";
		case 9: return "Owner";
		case 10: return "CheckChest";
		case 11: return "SleepBed";
		case 12: return "SleepBarracks";
		case 13: return "SleepGround";
		case 14: return "LeaveWall";
		case 15: return "FleeTerrain";
		case 16: return "TaxRoom";
		case 17: return "GuardTaxes";
		case 18: return "RansackTaxes";
		case 19: return "GetEmptySandBag";
		case 20: return "SandZone";
		case 21: return "GrabCage";
		case 22: return "UncageAnimal";
		case 23: return "CaptureSmallPet";
		case 24: return "GrabCageUnit";
		case 25: return "GoToCage";
		case 26: return "GrabAnimalTrap";
		case 27: return "CageVermin";
		case 28: return "GrabUnfillBucket";
		case 29: return "SeekFillBucket";
		case 30: return "SeekPatientForCarry";
		case 31: return "SeekPatientForDiagnosis";
		case 32: return "SeekPatientForImmobilizeBreak";
		case 33: return "SeekPatientForCrutch";
		case 34: return "SeekPatientForSuturing";
		case 35: return "SeekSurgerySite";
		case 36: return "CarryPatientToBed";
		case 37: return "SeekGiveWaterBucket";
		case 38: return "SeekJobItem";
		case 39: return "SeekUnitForItemDrop";
		case 40: return "SeekUnitForJob";
		case 41: return "SeekSplint";
		case 42: return "SeekCrutch";
		case 43: return "SeekSutureThread";
		case 44: return "SeekDressingCloth";
		case 45: return "GoToGiveWaterTarget";
		case 46: return "SeekFoodForTarget";
		case 47: return "SeekTargetForFood";
		case 48: return "SeekAnimalForSlaughter";
		case 49: return "SeekSlaughterBuilding";
		case 50: return "SeekAnimalForChain";
		case 51: return "SeekChainForAnimal";
		case 52: return "SeekCageForUnchain";
		case 53: return "SeekAnimalForUnchain";
		case 54: return "GrabFoodForTaming";
		case 55: return "SeekAnimalForTaming";
		case 56: return "SeekDrinkItem";
		case 57: return "SeekFoodItem";
		case 58: return "SeekEatingChair";
		case 59: return "SeekEatingChair2";
		case 60: return "SeekBadMoodBuilding";
		case 61: return "SetGlassMoodBuilding";
		case 62: return "SetMoodBuilding";
		case 63: return "SeekFellVictim";
		case 64: return "CleanBuildingSite";
		case 65: return "ResetPriorityGoal";
		case 66: return "MainJobBuilding";
		case 67: return "DropOffJobItems";
		case 68: return "GrabJobResources";
		case 69: return "WorkAtBuilding";
		case 70: return "GrabUniform";
		case 71: return "GrabClothing";
		case 72: return "GrabWeapon";
		case 73: return "GrabAmmunition";
		case 74: return "GrabShield";
		case 75: return "GrabArmor";
		case 76: return "GrabHelm";
		case 77: return "GrabBoots";
		case 78: return "GrabGloves";
		case 79: return "GrabPants";
		case 80: return "GrabQuiver";
		case 81: return "GrabBackpack";
		case 82: return "GrabWaterskin";
		case 83: return "StartHunt";
		case 84: return "StartFish";
		case 85: return "Clean";
		case 86: return "HuntVermin";
		case 87: return "Patrol";
		case 88: return "SquadStation";
		case 89: return "SeekInfant";
		case 90: return "ShopSpecific";
		case 91: return "MillInShop";
		case 92: return "GoToShop";
		case 93: return "SeekTrainingAmmunition";
		case 94: return "ArcheryTrainingSite";
		case 95: return "SparringPartner";
		case 96: return "SparringSite";
		case 97: return "AttendParty";
		case 98: return "SeekArtifact";
		case 99: return "GrabAmmunitionForBuilding";
		case 100: return "SeekBuildingForAmmunition";
		case 101: return "SeekItemForStorage";
		case 102: return "StoreItem";
		case 103: return "GrabKill";
		case 104: return "DropKillAtButcher";
		case 105: return "DropKillOutFront";
		case 106: return "GoToBeatingTarget";
		case 107: return "SeekKidnapVictim";
		case 108: return "SeekHuntingTarget";
		case 109: return "SeekTargetMechanism";
		case 110: return "SeekTargetForMechanism";
		case 111: return "SeekMechanismForTrigger";
		case 112: return "SeekTriggerForMechanism";
		case 113: return "SeekTrapForVerminCatch";
		case 114: return "SeekVerminForCatching";
		case 115: return "SeekVerminCatchLocation";
		case 116: return "WanderVerminCatchLocation";
		case 117: return "SeekVerminForHunting";
		case 118: return "SeekVerminHuntingSpot";
		case 119: return "WanderVerminHuntingSpot";
		case 120: return "SeekFishTrap";
		case 121: return "SeekFishCatchLocation";
		case 122: return "SeekWellForWater";
		case 123: return "SeekDrinkAreaForWater";
		case 124: return "UpgradeSquadEquipment";
		case 125: return "PrepareEquipmentManifests";
		case 126: return "WanderDepot";
		case 127: return "SeekUpdateOffice";
		case 128: return "SeekManageOffice";
		case 129: return "AssignedBuildingJob";
		case 130: return "ChaseOpponent";
		case 131: return "FleeFromOpponent";
		case 132: return "AttackBuilding";
		case 133: return "StartBedCarry";
		case 134: return "StartGiveFoodWater";
		case 135: return "StartMedicalAid";
		case 136: return "SeekStationFlood";
		case 137: return "SeekStation";
		case 138: return "StartWaterJobWell";
		case 139: return "StartWaterJobDrinkArea";
		case 140: return "StartEatJob";
		case 141: return "ScheduledMeal";
		case 142: return "ScheduledSleepBed";
		case 143: return "ScheduledSleepGround";
		case 144: return "Rest";
		case 145: return "RemoveConstruction";
		case 146: return "Chop";
		case 147: return "Detail";
		case 148: return "GatherPlant";
		case 149: return "Dig";
		case 150: return "Mischief";
		case 151: return "ChaseOpponentSameSquare";
		case 152: return "RestRecovered";
		case 153: return "RestReset";
		case 154: return "CombatTraining";
		case 155: return "SkillDemonstration";
		case 156: return "IndividualSkillDrill";
		case 157: return "SeekBuildingForItemDrop";
		case 158: return "SeekBuildingForJob";
		case 159: return "GrabMilkUnit";
		case 160: return "GoToMilkStation";
		case 161: return "SeekPatientForDressWound";
		case 162: return "UndeadHunt";
		case 163: return "GrabShearUnit";
		case 164: return "GoToShearStation";
		case 165: return "LayEggNestBox";
		case 166: return "ClayZone";
		case 167: return "ColonyToInstall";
		case 168: return "ReturnColonyToInstall";
		case 169: return "Nonsense";
		case 170: return "SeekBloodSuckVictim";
		case 171: return "SeekSheriff";
		case 172: return "GrabExecutionWeapon";
		case 173: return "TrainAnimal";
		case 174: return "GuardPath";
		case 175: return "Harass";
		case 176: return "SiteWalk";
		case 177: return "SiteWalkToBuilding";
		case 178: return "Reunion";
		case 179: return "ArmyWalk";
		case 180: return "ChaseOpponentFlood";
		case 181: return "ChargeAttack";
		case 182: return "FleeFromOpponentClimb";
		case 183: return "SeekLadderToClimb";
		case 184: return "SeekLadderToMove";
		case 185: return "PlaceLadder";
		case 186: return "SeekAnimalForGelding";
		case 187: return "SeekGeldingBuilding";
		case 188: return "Prayer";
		case 189: return "Socialize";
		case 190: return "Performance";
		case 191: return "Research";
		case 192: return "PonderTopic";
		case 193: return "FillServiceOrder";
		case 194: return "GetWrittenContent";
		case 195: return "GoToReadingPlace";
		case 196: return "GetWritingMaterials";
		case 197: return "GoToWritingPlace";
		case 198: return "Worship";
		case 199: return "GrabInstrument";
		case 200: return "Play";
		case 201: return "MakeBelieve";
		case 202: return "PlayWithToy";
		case 203: return "GrabToy";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_station_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::unit_station_type::unit_station_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Nonsense";
		case 1: return "DungeonCommander";
		case 2: return "InsaneMood";
		case 3: return "UndeadHunt";
		case 4: return "SiegerPatrol";
		case 5: return "MaraudeTarget";
		case 6: return "SiegerBasepoint";
		case 7: return "SiegerMill";
		case 8: return "AmbushPatrol";
		case 9: return "MarauderMill";
		case 10: return "WildernessCuriousWander";
		case 11: return "WildernessCuriousStealTarget";
		case 12: return "WildernessRoamer";
		case 13: return "PatternPatrol";
		case 14: return "InactiveMarauder";
		case 15: return "Owner";
		case 16: return "Commander";
		case 17: return "ChainedAnimal";
		case 18: return "MeetingLocation";
		case 19: return "MeetingLocationBuilding";
		case 20: return "Depot";
		case 21: return "VerminHunting";
		case 22: return "SeekCommander";
		case 23: return "ReturnToBase";
		case 24: return "MillAnywhere";
		case 25: return "Wagon";
		case 26: return "MillBuilding";
		case 27: return "HeadForEdge";
		case 28: return "MillingFlood";
		case 29: return "MillingBurrow";
		case 30: return "SquadMove";
		case 31: return "SquadKillList";
		case 32: return "SquadPatrol";
		case 33: return "SquadDefendBurrow";
		case 34: return "SquadDefendBurrowFromTarget";
		case 35: return "LairHunter";
		case 36: return "Graze";
		case 37: return "Guard";
		case 38: return "Alarm";
		case 39: return "MoveToSite";
		case 40: return "ClaimSite";
		case 41: return "WaitOrder";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_plant_raw_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::plant_raw_flags::plant_raw_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "SPRING";
		case 1: return "SUMMER";
		case 2: return "AUTUMN";
		case 3: return "WINTER";
		case 4: return "anon_1";
		case 5: return "SEED";
		case 6: return "TREE_HAS_MUSHROOM_CAP";
		case 7: return "DRINK";
		case 8: return "EXTRACT_BARREL";
		case 9: return "EXTRACT_VIAL";
		case 10: return "EXTRACT_STILL_VIAL";
		case 11: return "GENERATED";
		case 12: return "THREAD";
		case 13: return "MILL";
		case 14: return "anon_2";
		case 15: return "anon_3";
		case 16: return "anon_4";
		case 17: return "anon_5";
		case 18: return "anon_6";
		case 19: return "anon_7";
		case 20: return "WET";
		case 21: return "DRY";
		case 22: return "BIOME_MOUNTAIN";
		case 23: return "BIOME_GLACIER";
		case 24: return "BIOME_TUNDRA";
		case 25: return "BIOME_SWAMP_TEMPERATE_FRESHWATER";
		case 26: return "BIOME_SWAMP_TEMPERATE_SALTWATER";
		case 27: return "BIOME_MARSH_TEMPERATE_FRESHWATER";
		case 28: return "BIOME_MARSH_TEMPERATE_SALTWATER";
		case 29: return "BIOME_SWAMP_TROPICAL_FRESHWATER";
		case 30: return "BIOME_SWAMP_TROPICAL_SALTWATER";
		case 31: return "BIOME_SWAMP_MANGROVE";
		case 32: return "BIOME_MARSH_TROPICAL_FRESHWATER";
		case 33: return "BIOME_MARSH_TROPICAL_SALTWATER";
		case 34: return "BIOME_FOREST_TAIGA";
		case 35: return "BIOME_FOREST_TEMPERATE_CONIFER";
		case 36: return "BIOME_FOREST_TEMPERATE_BROADLEAF";
		case 37: return "BIOME_FOREST_TROPICAL_CONIFER";
		case 38: return "BIOME_FOREST_TROPICAL_DRY_BROADLEAF";
		case 39: return "BIOME_FOREST_TROPICAL_MOIST_BROADLEAF";
		case 40: return "BIOME_GRASSLAND_TEMPERATE";
		case 41: return "BIOME_SAVANNA_TEMPERATE";
		case 42: return "BIOME_SHRUBLAND_TEMPERATE";
		case 43: return "BIOME_GRASSLAND_TROPICAL";
		case 44: return "BIOME_SAVANNA_TROPICAL";
		case 45: return "BIOME_SHRUBLAND_TROPICAL";
		case 46: return "BIOME_DESERT_BADLAND";
		case 47: return "BIOME_DESERT_ROCK";
		case 48: return "BIOME_DESERT_SAND";
		case 49: return "BIOME_OCEAN_TROPICAL";
		case 50: return "BIOME_OCEAN_TEMPERATE";
		case 51: return "BIOME_OCEAN_ARCTIC";
		case 52: return "BIOME_POOL_TEMPERATE_FRESHWATER";
		case 53: return "BIOME_SUBTERRANEAN_WATER";
		case 54: return "BIOME_SUBTERRANEAN_CHASM";
		case 55: return "BIOME_SUBTERRANEAN_LAVA";
		case 56: return "GOOD";
		case 57: return "EVIL";
		case 58: return "SAVAGE";
		case 59: return "BIOME_POOL_TEMPERATE_BRACKISHWATER";
		case 60: return "BIOME_POOL_TEMPERATE_SALTWATER";
		case 61: return "BIOME_POOL_TROPICAL_FRESHWATER";
		case 62: return "BIOME_POOL_TROPICAL_BRACKISHWATER";
		case 63: return "BIOME_POOL_TROPICAL_SALTWATER";
		case 64: return "BIOME_LAKE_TEMPERATE_FRESHWATER";
		case 65: return "BIOME_LAKE_TEMPERATE_BRACKISHWATER";
		case 66: return "BIOME_LAKE_TEMPERATE_SALTWATER";
		case 67: return "BIOME_LAKE_TROPICAL_FRESHWATER";
		case 68: return "BIOME_LAKE_TROPICAL_BRACKISHWATER";
		case 69: return "BIOME_LAKE_TROPICAL_SALTWATER";
		case 70: return "BIOME_RIVER_TEMPERATE_FRESHWATER";
		case 71: return "BIOME_RIVER_TEMPERATE_BRACKISHWATER";
		case 72: return "BIOME_RIVER_TEMPERATE_SALTWATER";
		case 73: return "BIOME_RIVER_TROPICAL_FRESHWATER";
		case 74: return "BIOME_RIVER_TROPICAL_BRACKISHWATER";
		case 75: return "BIOME_RIVER_TROPICAL_SALTWATER";
		case 76: return "TWIGS_SIDE_BRANCHES";
		case 77: return "SAPLING";
		case 78: return "TREE";
		case 79: return "GRASS";
		case 80: return "TWIGS_ABOVE_BRANCHES";
		case 81: return "TWIGS_BELOW_BRANCHES";
		case 82: return "TWIGS_SIDE_HEAVY_BRANCHES";
		case 83: return "TWIGS_ABOVE_HEAVY_BRANCHES";
		case 84: return "TWIGS_BELOW_HEAVY_BRANCHES";
		case 85: return "TWIGS_SIDE_TRUNK";
		case 86: return "TWIGS_ABOVE_TRUNK";
		case 87: return "TWIGS_BELOW_TRUNK";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_projectile_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::projectile_type::projectile_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Item";
		case 1: return "Unit";
		case 2: return "Magic";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_reaction_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::reaction_flags::reaction_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "FUEL";
		case 1: return "AUTOMATIC";
		case 2: return "ADVENTURE_MODE_ENABLED";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_reaction_reagent_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::reaction_reagent_type::reaction_reagent_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "item";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_reaction_product_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::reaction_product_type::reaction_product_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "item";
		case 1: return "improvement";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_reaction_product_item_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::reaction_product_item_flags::reaction_product_item_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "GET_MATERIAL_SAME";
		case 1: return "GET_MATERIAL_PRODUCT";
		case 2: return "FORCE_EDGE";
		case 3: return "PASTE";
		case 4: return "PRESSED";
		case 5: return "CRAFTS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_reaction_product_improvement_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::reaction_product_improvement_flags::reaction_product_improvement_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "GET_MATERIAL_SAME";
		case 1: return "GET_MATERIAL_PRODUCT";
		case 2: return "GLAZED";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_general_ref_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::general_ref_type::general_ref_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "ARTIFACT";
		case 1: return "IS_ARTIFACT";
		case 2: return "NEMESIS";
		case 3: return "IS_NEMESIS";
		case 4: return "ITEM";
		case 5: return "ITEM_TYPE";
		case 6: return "COINBATCH";
		case 7: return "MAPSQUARE";
		case 8: return "ENTITY_ART_IMAGE";
		case 9: return "CONTAINS_UNIT";
		case 10: return "CONTAINS_ITEM";
		case 11: return "CONTAINED_IN_ITEM";
		case 12: return "PROJECTILE";
		case 13: return "UNIT";
		case 14: return "UNIT_MILKEE";
		case 15: return "UNIT_TRAINEE";
		case 16: return "UNIT_ITEMOWNER";
		case 17: return "UNIT_TRADEBRINGER";
		case 18: return "UNIT_HOLDER";
		case 19: return "UNIT_WORKER";
		case 20: return "UNIT_CAGEE";
		case 21: return "UNIT_BEATEE";
		case 22: return "UNIT_FOODRECEIVER";
		case 23: return "UNIT_KIDNAPEE";
		case 24: return "UNIT_PATIENT";
		case 25: return "UNIT_INFANT";
		case 26: return "UNIT_SLAUGHTEREE";
		case 27: return "UNIT_SHEAREE";
		case 28: return "UNIT_SUCKEE";
		case 29: return "UNIT_REPORTEE";
		case 30: return "BUILDING";
		case 31: return "BUILDING_CIVZONE_ASSIGNED";
		case 32: return "BUILDING_TRIGGER";
		case 33: return "BUILDING_TRIGGERTARGET";
		case 34: return "BUILDING_CHAIN";
		case 35: return "BUILDING_CAGED";
		case 36: return "BUILDING_HOLDER";
		case 37: return "BUILDING_WELL_TAG";
		case 38: return "BUILDING_USE_TARGET_1";
		case 39: return "BUILDING_USE_TARGET_2";
		case 40: return "BUILDING_DESTINATION";
		case 41: return "BUILDING_NEST_BOX";
		case 42: return "ENTITY";
		case 43: return "ENTITY_STOLEN";
		case 44: return "ENTITY_OFFERED";
		case 45: return "ENTITY_ITEMOWNER";
		case 46: return "LOCATION";
		case 47: return "INTERACTION";
		case 48: return "ABSTRACT_BUILDING";
		case 49: return "HISTORICAL_EVENT";
		case 50: return "SPHERE";
		case 51: return "SITE";
		case 52: return "SUBREGION";
		case 53: return "FEATURE_LAYER";
		case 54: return "HISTORICAL_FIGURE";
		case 55: return "ENTITY_POP";
		case 56: return "CREATURE";
		case 57: return "UNIT_RIDER";
		case 58: return "UNIT_CLIMBER";
		case 59: return "UNIT_GELDEE";
		case 60: return "KNOWLEDGE_SCHOLAR_FLAG";
		case 61: return "ACTIVITY_EVENT";
		case 62: return "VALUE_LEVEL";
		case 63: return "LANGUAGE";
		case 64: return "WRITTEN_CONTENT";
		case 65: return "POETIC_FORM";
		case 66: return "MUSICAL_FORM";
		case 67: return "DANCE_FORM";
		case 68: return "BUILDING_DISPLAY_FURNITURE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_specific_ref_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::specific_ref_type::specific_ref_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "anon_1";
		case 1: return "UNIT_INVENTORY";
		case 2: return "JOB";
		case 3: return "BUILDING_PARTY";
		case 4: return "ACTIVITY";
		case 5: return "ITEM_GENERAL";
		case 6: return "EFFECT";
		case 7: return "PETINFO_PET";
		case 8: return "PETINFO_OWNER";
		case 9: return "VERMIN_EVENT";
		case 10: return "VERMIN_ESCAPED_PET";
		case 11: return "ENTITY";
		case 12: return "PLOT_INFO";
		case 13: return "VIEWSCREEN";
		case 14: return "UNIT_ITEM_WRESTLE";
		case 15: return "NULL_REF";
		case 16: return "HIST_FIG";
		case 17: return "SITE";
		case 18: return "ARTIFACT";
		case 19: return "ITEM_IMPROVEMENT";
		case 20: return "COIN_FRONT";
		case 21: return "COIN_BACK";
		case 22: return "DETAIL_EVENT";
		case 23: return "SUBREGION";
		case 24: return "FEATURE_LAYER";
		case 25: return "ART_IMAGE";
		case 26: return "CREATURE_DEF";
		case 27: return "anon_2";
		case 28: return "anon_3";
		case 29: return "ENTITY_POPULATION";
		case 30: return "BREED";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_histfig_entity_link_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::histfig_entity_link_type::histfig_entity_link_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MEMBER";
		case 1: return "FORMER_MEMBER";
		case 2: return "MERCENARY";
		case 3: return "FORMER_MERCENARY";
		case 4: return "SLAVE";
		case 5: return "FORMER_SLAVE";
		case 6: return "PRISONER";
		case 7: return "FORMER_PRISONER";
		case 8: return "ENEMY";
		case 9: return "CRIMINAL";
		case 10: return "POSITION";
		case 11: return "FORMER_POSITION";
		case 12: return "POSITION_CLAIM";
		case 13: return "SQUAD";
		case 14: return "FORMER_SQUAD";
		case 15: return "OCCUPATION";
		case 16: return "FORMER_OCCUPATION";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_histfig_site_link_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::histfig_site_link_type::histfig_site_link_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "OCCUPATION";
		case 1: return "SEAT_OF_POWER";
		case 2: return "HANGOUT";
		case 3: return "HOME_SITE_ABSTRACT_BUILDING";
		case 4: return "HOME_SITE_REALIZATION_BUILDING";
		case 5: return "LAIR";
		case 6: return "HOME_SITE_REALIZATION_SUL";
		case 7: return "HOME_SITE_SAVED_CIVZONE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_histfig_hf_link_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::histfig_hf_link_type::histfig_hf_link_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MOTHER";
		case 1: return "FATHER";
		case 2: return "SPOUSE";
		case 3: return "CHILD";
		case 4: return "DEITY";
		case 5: return "LOVER";
		case 6: return "PRISONER";
		case 7: return "IMPRISONER";
		case 8: return "MASTER";
		case 9: return "APPRENTICE";
		case 10: return "COMPANION";
		case 11: return "FORMER_MASTER";
		case 12: return "FORMER_APPRENTICE";
		case 13: return "PET_OWNER";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_entity_link_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::entity_entity_link_type::entity_entity_link_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "PARENT";
		case 1: return "CHILD";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_resource_allotment_specifier_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::resource_allotment_specifier_type::resource_allotment_specifier_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "CROP";
		case 1: return "STONE";
		case 2: return "METAL";
		case 3: return "WOOD";
		case 4: return "ARMOR_BODY";
		case 5: return "ARMOR_PANTS";
		case 6: return "ARMOR_GLOVES";
		case 7: return "ARMOR_BOOTS";
		case 8: return "ARMOR_HELM";
		case 9: return "CLOTHING_BODY";
		case 10: return "CLOTHING_PANTS";
		case 11: return "CLOTHING_GLOVES";
		case 12: return "CLOTHING_BOOTS";
		case 13: return "CLOTHING_HELM";
		case 14: return "WEAPON_MELEE";
		case 15: return "WEAPON_RANGED";
		case 16: return "ANVIL";
		case 17: return "GEMS";
		case 18: return "THREAD";
		case 19: return "CLOTH";
		case 20: return "LEATHER";
		case 21: return "QUIVER";
		case 22: return "BACKPACK";
		case 23: return "FLASK";
		case 24: return "BAG";
		case 25: return "TABLE";
		case 26: return "CABINET";
		case 27: return "CHAIR";
		case 28: return "BOX";
		case 29: return "BED";
		case 30: return "CRAFTS";
		case 31: return "MEAT";
		case 32: return "BONE";
		case 33: return "HORN";
		case 34: return "SHELL";
		case 35: return "TALLOW";
		case 36: return "TOOTH";
		case 37: return "PEARL";
		case 38: return "SOAP";
		case 39: return "EXTRACT";
		case 40: return "CHEESE";
		case 41: return "SKIN";
		case 42: return "POWDER";
		case 43: return "AMMO";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_profession_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::profession::profession*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "MINER";
		case 1: return "WOODWORKER";
		case 2: return "CARPENTER";
		case 3: return "BOWYER";
		case 4: return "WOODCUTTER";
		case 5: return "STONEWORKER";
		case 6: return "ENGRAVER";
		case 7: return "MASON";
		case 8: return "RANGER";
		case 9: return "ANIMAL_CARETAKER";
		case 10: return "ANIMAL_TRAINER";
		case 11: return "HUNTER";
		case 12: return "TRAPPER";
		case 13: return "ANIMAL_DISSECTOR";
		case 14: return "METALSMITH";
		case 15: return "FURNACE_OPERATOR";
		case 16: return "WEAPONSMITH";
		case 17: return "ARMORER";
		case 18: return "BLACKSMITH";
		case 19: return "METALCRAFTER";
		case 20: return "JEWELER";
		case 21: return "GEM_CUTTER";
		case 22: return "GEM_SETTER";
		case 23: return "CRAFTSMAN";
		case 24: return "WOODCRAFTER";
		case 25: return "STONECRAFTER";
		case 26: return "LEATHERWORKER";
		case 27: return "BONE_CARVER";
		case 28: return "WEAVER";
		case 29: return "CLOTHIER";
		case 30: return "GLASSMAKER";
		case 31: return "POTTER";
		case 32: return "GLAZER";
		case 33: return "WAX_WORKER";
		case 34: return "STRAND_EXTRACTOR";
		case 35: return "FISHERY_WORKER";
		case 36: return "FISHERMAN";
		case 37: return "FISH_DISSECTOR";
		case 38: return "FISH_CLEANER";
		case 39: return "FARMER";
		case 40: return "CHEESE_MAKER";
		case 41: return "MILKER";
		case 42: return "COOK";
		case 43: return "THRESHER";
		case 44: return "MILLER";
		case 45: return "BUTCHER";
		case 46: return "TANNER";
		case 47: return "DYER";
		case 48: return "PLANTER";
		case 49: return "HERBALIST";
		case 50: return "BREWER";
		case 51: return "SOAP_MAKER";
		case 52: return "POTASH_MAKER";
		case 53: return "LYE_MAKER";
		case 54: return "WOOD_BURNER";
		case 55: return "SHEARER";
		case 56: return "SPINNER";
		case 57: return "PRESSER";
		case 58: return "BEEKEEPER";
		case 59: return "ENGINEER";
		case 60: return "MECHANIC";
		case 61: return "SIEGE_ENGINEER";
		case 62: return "SIEGE_OPERATOR";
		case 63: return "PUMP_OPERATOR";
		case 64: return "CLERK";
		case 65: return "ADMINISTRATOR";
		case 66: return "TRADER";
		case 67: return "ARCHITECT";
		case 68: return "ALCHEMIST";
		case 69: return "DOCTOR";
		case 70: return "DIAGNOSER";
		case 71: return "BONE_SETTER";
		case 72: return "SUTURER";
		case 73: return "SURGEON";
		case 74: return "MERCHANT";
		case 75: return "HAMMERMAN";
		case 76: return "MASTER_HAMMERMAN";
		case 77: return "SPEARMAN";
		case 78: return "MASTER_SPEARMAN";
		case 79: return "CROSSBOWMAN";
		case 80: return "MASTER_CROSSBOWMAN";
		case 81: return "WRESTLER";
		case 82: return "MASTER_WRESTLER";
		case 83: return "AXEMAN";
		case 84: return "MASTER_AXEMAN";
		case 85: return "SWORDSMAN";
		case 86: return "MASTER_SWORDSMAN";
		case 87: return "MACEMAN";
		case 88: return "MASTER_MACEMAN";
		case 89: return "PIKEMAN";
		case 90: return "MASTER_PIKEMAN";
		case 91: return "BOWMAN";
		case 92: return "MASTER_BOWMAN";
		case 93: return "BLOWGUNMAN";
		case 94: return "MASTER_BLOWGUNMAN";
		case 95: return "LASHER";
		case 96: return "MASTER_LASHER";
		case 97: return "RECRUIT";
		case 98: return "TRAINED_HUNTER";
		case 99: return "TRAINED_WAR";
		case 100: return "MASTER_THIEF";
		case 101: return "THIEF";
		case 102: return "STANDARD";
		case 103: return "CHILD";
		case 104: return "BABY";
		case 105: return "DRUNK";
		case 106: return "MONSTER_SLAYER";
		case 107: return "SCOUT";
		case 108: return "BEAST_HUNTER";
		case 109: return "SNATCHER";
		case 110: return "MERCENARY";
		case 111: return "GELDER";
		case 112: return "PERFORMER";
		case 113: return "POET";
		case 114: return "BARD";
		case 115: return "DANCER";
		case 116: return "SAGE";
		case 117: return "SCHOLAR";
		case 118: return "PHILOSOPHER";
		case 119: return "MATHEMATICIAN";
		case 120: return "HISTORIAN";
		case 121: return "ASTRONOMER";
		case 122: return "NATURALIST";
		case 123: return "CHEMIST";
		case 124: return "GEOGRAPHER";
		case 125: return "SCRIBE";
		case 126: return "PAPERMAKER";
		case 127: return "BOOKBINDER";
		case 128: return "TAVERN_KEEPER";
		case 129: return "CRIMINAL";
		case 130: return "PEDDLER";
		case 131: return "PROPHET";
		case 132: return "PILGRIM";
		case 133: return "MONK";
		case 134: return "MESSENGER";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_labor_category_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::unit_labor_category::unit_labor_category*>(p_address);
	switch (*m_value)
	{
		case -13: return "Other";
		case -12: return "Hauling";
		case -11: return "Engineering";
		case -10: return "Crafts";
		case -9: return "Jewelry";
		case -8: return "Metalsmithing";
		case -7: return "Fishing";
		case -6: return "Farming";
		case -5: return "Healthcare";
		case -4: return "Hunting";
		case -3: return "Stoneworking";
		case -2: return "Woodworking";
		case -1: return "None";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_labor_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::unit_labor::unit_labor*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "MINE";
		case 1: return "HAUL_STONE";
		case 2: return "HAUL_WOOD";
		case 3: return "HAUL_BODY";
		case 4: return "HAUL_FOOD";
		case 5: return "HAUL_REFUSE";
		case 6: return "HAUL_ITEM";
		case 7: return "HAUL_FURNITURE";
		case 8: return "HAUL_ANIMALS";
		case 9: return "CLEAN";
		case 10: return "CUTWOOD";
		case 11: return "CARPENTER";
		case 12: return "DETAIL";
		case 13: return "MASON";
		case 14: return "ARCHITECT";
		case 15: return "ANIMALTRAIN";
		case 16: return "ANIMALCARE";
		case 17: return "DIAGNOSE";
		case 18: return "SURGERY";
		case 19: return "BONE_SETTING";
		case 20: return "SUTURING";
		case 21: return "DRESSING_WOUNDS";
		case 22: return "FEED_WATER_CIVILIANS";
		case 23: return "RECOVER_WOUNDED";
		case 24: return "BUTCHER";
		case 25: return "TRAPPER";
		case 26: return "DISSECT_VERMIN";
		case 27: return "LEATHER";
		case 28: return "TANNER";
		case 29: return "BREWER";
		case 30: return "ALCHEMIST";
		case 31: return "SOAP_MAKER";
		case 32: return "WEAVER";
		case 33: return "CLOTHESMAKER";
		case 34: return "MILLER";
		case 35: return "PROCESS_PLANT";
		case 36: return "MAKE_CHEESE";
		case 37: return "MILK";
		case 38: return "COOK";
		case 39: return "PLANT";
		case 40: return "HERBALIST";
		case 41: return "FISH";
		case 42: return "CLEAN_FISH";
		case 43: return "DISSECT_FISH";
		case 44: return "HUNT";
		case 45: return "SMELT";
		case 46: return "FORGE_WEAPON";
		case 47: return "FORGE_ARMOR";
		case 48: return "FORGE_FURNITURE";
		case 49: return "METAL_CRAFT";
		case 50: return "CUT_GEM";
		case 51: return "ENCRUST_GEM";
		case 52: return "WOOD_CRAFT";
		case 53: return "STONE_CRAFT";
		case 54: return "BONE_CARVE";
		case 55: return "GLASSMAKER";
		case 56: return "EXTRACT_STRAND";
		case 57: return "SIEGECRAFT";
		case 58: return "SIEGEOPERATE";
		case 59: return "BOWYER";
		case 60: return "MECHANIC";
		case 61: return "POTASH_MAKING";
		case 62: return "LYE_MAKING";
		case 63: return "DYER";
		case 64: return "BURN_WOOD";
		case 65: return "OPERATE_PUMP";
		case 66: return "SHEARER";
		case 67: return "SPINNER";
		case 68: return "POTTERY";
		case 69: return "GLAZING";
		case 70: return "PRESSING";
		case 71: return "BEEKEEPING";
		case 72: return "WAX_WORKING";
		case 73: return "HANDLE_VEHICLES";
		case 74: return "HAUL_TRADE";
		case 75: return "PULL_LEVER";
		case 76: return "REMOVE_CONSTRUCTION";
		case 77: return "HAUL_WATER";
		case 78: return "GELD";
		case 79: return "BUILD_ROAD";
		case 80: return "BUILD_CONSTRUCTION";
		case 81: return "PAPERMAKING";
		case 82: return "BOOKBINDING";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_job_skill_class_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::job_skill_class::job_skill_class*>(p_address);
	switch (*m_value)
	{
		case 0: return "Normal";
		case 1: return "Medical";
		case 2: return "Personal";
		case 3: return "Social";
		case 4: return "Cultural";
		case 5: return "MilitaryWeapon";
		case 6: return "MilitaryUnarmed";
		case 7: return "MilitaryAttack";
		case 8: return "MilitaryDefense";
		case 9: return "MilitaryMisc";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_job_skill_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::job_skill::job_skill*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "MINING";
		case 1: return "WOODCUTTING";
		case 2: return "CARPENTRY";
		case 3: return "DETAILSTONE";
		case 4: return "MASONRY";
		case 5: return "ANIMALTRAIN";
		case 6: return "ANIMALCARE";
		case 7: return "DISSECT_FISH";
		case 8: return "DISSECT_VERMIN";
		case 9: return "PROCESSFISH";
		case 10: return "BUTCHER";
		case 11: return "TRAPPING";
		case 12: return "TANNER";
		case 13: return "WEAVING";
		case 14: return "BREWING";
		case 15: return "ALCHEMY";
		case 16: return "CLOTHESMAKING";
		case 17: return "MILLING";
		case 18: return "PROCESSPLANTS";
		case 19: return "CHEESEMAKING";
		case 20: return "MILK";
		case 21: return "COOK";
		case 22: return "PLANT";
		case 23: return "HERBALISM";
		case 24: return "FISH";
		case 25: return "SMELT";
		case 26: return "EXTRACT_STRAND";
		case 27: return "FORGE_WEAPON";
		case 28: return "FORGE_ARMOR";
		case 29: return "FORGE_FURNITURE";
		case 30: return "CUTGEM";
		case 31: return "ENCRUSTGEM";
		case 32: return "WOODCRAFT";
		case 33: return "STONECRAFT";
		case 34: return "METALCRAFT";
		case 35: return "GLASSMAKER";
		case 36: return "LEATHERWORK";
		case 37: return "BONECARVE";
		case 38: return "AXE";
		case 39: return "SWORD";
		case 40: return "DAGGER";
		case 41: return "MACE";
		case 42: return "HAMMER";
		case 43: return "SPEAR";
		case 44: return "CROSSBOW";
		case 45: return "SHIELD";
		case 46: return "ARMOR";
		case 47: return "SIEGECRAFT";
		case 48: return "SIEGEOPERATE";
		case 49: return "BOWYER";
		case 50: return "PIKE";
		case 51: return "WHIP";
		case 52: return "BOW";
		case 53: return "BLOWGUN";
		case 54: return "THROW";
		case 55: return "MECHANICS";
		case 56: return "MAGIC_NATURE";
		case 57: return "SNEAK";
		case 58: return "DESIGNBUILDING";
		case 59: return "DRESS_WOUNDS";
		case 60: return "DIAGNOSE";
		case 61: return "SURGERY";
		case 62: return "SET_BONE";
		case 63: return "SUTURE";
		case 64: return "CRUTCH_WALK";
		case 65: return "WOOD_BURNING";
		case 66: return "LYE_MAKING";
		case 67: return "SOAP_MAKING";
		case 68: return "POTASH_MAKING";
		case 69: return "DYER";
		case 70: return "OPERATE_PUMP";
		case 71: return "SWIMMING";
		case 72: return "PERSUASION";
		case 73: return "NEGOTIATION";
		case 74: return "JUDGING_INTENT";
		case 75: return "APPRAISAL";
		case 76: return "ORGANIZATION";
		case 77: return "RECORD_KEEPING";
		case 78: return "LYING";
		case 79: return "INTIMIDATION";
		case 80: return "CONVERSATION";
		case 81: return "COMEDY";
		case 82: return "FLATTERY";
		case 83: return "CONSOLE";
		case 84: return "PACIFY";
		case 85: return "TRACKING";
		case 86: return "KNOWLEDGE_ACQUISITION";
		case 87: return "CONCENTRATION";
		case 88: return "DISCIPLINE";
		case 89: return "SITUATIONAL_AWARENESS";
		case 90: return "WRITING";
		case 91: return "PROSE";
		case 92: return "POETRY";
		case 93: return "READING";
		case 94: return "SPEAKING";
		case 95: return "COORDINATION";
		case 96: return "BALANCE";
		case 97: return "LEADERSHIP";
		case 98: return "TEACHING";
		case 99: return "MELEE_COMBAT";
		case 100: return "RANGED_COMBAT";
		case 101: return "WRESTLING";
		case 102: return "BITE";
		case 103: return "GRASP_STRIKE";
		case 104: return "STANCE_STRIKE";
		case 105: return "DODGING";
		case 106: return "MISC_WEAPON";
		case 107: return "KNAPPING";
		case 108: return "MILITARY_TACTICS";
		case 109: return "SHEARING";
		case 110: return "SPINNING";
		case 111: return "POTTERY";
		case 112: return "GLAZING";
		case 113: return "PRESSING";
		case 114: return "BEEKEEPING";
		case 115: return "WAX_WORKING";
		case 116: return "CLIMBING";
		case 117: return "GELD";
		case 118: return "DANCE";
		case 119: return "MAKE_MUSIC";
		case 120: return "SING_MUSIC";
		case 121: return "PLAY_KEYBOARD_INSTRUMENT";
		case 122: return "PLAY_STRINGED_INSTRUMENT";
		case 123: return "PLAY_WIND_INSTRUMENT";
		case 124: return "PLAY_PERCUSSION_INSTRUMENT";
		case 125: return "CRITICAL_THINKING";
		case 126: return "LOGIC";
		case 127: return "MATHEMATICS";
		case 128: return "ASTRONOMY";
		case 129: return "CHEMISTRY";
		case 130: return "GEOGRAPHY";
		case 131: return "OPTICS_ENGINEER";
		case 132: return "FLUID_ENGINEER";
		case 133: return "PAPERMAKING";
		case 134: return "BOOKBINDING";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_hauler_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::hauler_type::hauler_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Any";
		case 1: return "Stone";
		case 2: return "Wood";
		case 3: return "Item";
		case 4: return "Bin";
		case 5: return "Body";
		case 6: return "Food";
		case 7: return "Refuse";
		case 8: return "Furniture";
		case 9: return "Animal";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_furniture_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::furniture_type::furniture_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "FLOODGATE";
		case 1: return "HATCH_COVER";
		case 2: return "GRATE";
		case 3: return "DOOR";
		case 4: return "CATAPULTPARTS";
		case 5: return "BALLISTAPARTS";
		case 6: return "TRAPPARTS";
		case 7: return "BED";
		case 8: return "TRACTION_BENCH";
		case 9: return "WINDOW";
		case 10: return "CHAIR";
		case 11: return "TABLE";
		case 12: return "COFFIN";
		case 13: return "STATUE";
		case 14: return "SLAB";
		case 15: return "QUERN";
		case 16: return "MILLSTONE";
		case 17: return "ARMORSTAND";
		case 18: return "WEAPONRACK";
		case 19: return "CABINET";
		case 20: return "ANVIL";
		case 21: return "BUCKET";
		case 22: return "BIN";
		case 23: return "BOX";
		case 24: return "SIEGEAMMO";
		case 25: return "BARREL";
		case 26: return "BALLISTAARROWHEAD";
		case 27: return "PIPE_SECTION";
		case 28: return "FOOD_STORAGE";
		case 29: return "MINECART";
		case 30: return "WHEELBARROW";
		case 31: return "OTHER_LARGE_TOOLS";
		case 32: return "SAND_BAG";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_stockpile_category_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::stockpile_category::stockpile_category*>(p_address);
	switch (*m_value)
	{
		case -1: return "Remove";
		case 0: return "Animals";
		case 1: return "Food";
		case 2: return "Furniture";
		case 3: return "Corpses";
		case 4: return "Refuse";
		case 5: return "Stone";
		case 6: return "Ore";
		case 7: return "Ammo";
		case 8: return "Coins";
		case 9: return "Bars";
		case 10: return "Gems";
		case 11: return "Goods";
		case 12: return "Leather";
		case 13: return "Cloth";
		case 14: return "Wood";
		case 15: return "Weapons";
		case 16: return "Armor";
		case 17: return "Sheets";
		case 18: return "Custom";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_stockpile_list_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::stockpile_list::stockpile_list*>(p_address);
	switch (*m_value)
	{
		case 0: return "Animals";
		case 1: return "Food";
		case 2: return "FoodMeat";
		case 3: return "FoodFish";
		case 4: return "FoodUnpreparedFish";
		case 5: return "FoodEgg";
		case 6: return "FoodPlants";
		case 7: return "FoodDrinkPlant";
		case 8: return "FoodDrinkAnimal";
		case 9: return "FoodCheesePlant";
		case 10: return "FoodCheeseAnimal";
		case 11: return "FoodSeeds";
		case 12: return "FoodLeaves";
		case 13: return "FoodMilledPlant";
		case 14: return "FoodBoneMeal";
		case 15: return "FoodFat";
		case 16: return "FoodPaste";
		case 17: return "FoodPressedMaterial";
		case 18: return "FoodExtractPlant";
		case 19: return "FoodExtractAnimal";
		case 20: return "FoodMiscLiquid";
		case 21: return "Furniture";
		case 22: return "FurnitureType";
		case 23: return "FurnitureStoneClay";
		case 24: return "FurnitureMetal";
		case 25: return "FurnitureOtherMaterials";
		case 26: return "FurnitureCoreQuality";
		case 27: return "FurnitureTotalQuality";
		case 28: return "Corpses";
		case 29: return "Refuse";
		case 30: return "RefuseItems";
		case 31: return "RefuseCorpses";
		case 32: return "RefuseParts";
		case 33: return "RefuseSkulls";
		case 34: return "RefuseBones";
		case 35: return "RefuseShells";
		case 36: return "RefuseTeeth";
		case 37: return "RefuseHorns";
		case 38: return "RefuseHair";
		case 39: return "Stone";
		case 40: return "StoneOres";
		case 41: return "StoneEconomic";
		case 42: return "StoneOther";
		case 43: return "StoneClay";
		case 44: return "Ammo";
		case 45: return "AmmoType";
		case 46: return "AmmoMetal";
		case 47: return "AmmoOther";
		case 48: return "AmmoCoreQuality";
		case 49: return "AmmoTotalQuality";
		case 50: return "Coins";
		case 51: return "BarsBlocks";
		case 52: return "BarsMetal";
		case 53: return "BarsOther";
		case 54: return "BlocksStone";
		case 55: return "BlocksMetal";
		case 56: return "BlocksOther";
		case 57: return "Gems";
		case 58: return "RoughGem";
		case 59: return "RoughGlass";
		case 60: return "CutGem";
		case 61: return "CutGlass";
		case 62: return "CutStone";
		case 63: return "Goods";
		case 64: return "GoodsType";
		case 65: return "GoodsStone";
		case 66: return "GoodsMetal";
		case 67: return "GoodsGem";
		case 68: return "GoodsOther";
		case 69: return "GoodsCoreQuality";
		case 70: return "GoodsTotalQuality";
		case 71: return "Leather";
		case 72: return "Cloth";
		case 73: return "ThreadSilk";
		case 74: return "ThreadPlant";
		case 75: return "ThreadYarn";
		case 76: return "ThreadMetal";
		case 77: return "ClothSilk";
		case 78: return "ClothPlant";
		case 79: return "ClothYarn";
		case 80: return "ClothMetal";
		case 81: return "Wood";
		case 82: return "Weapons";
		case 83: return "WeaponsType";
		case 84: return "WeaponsTrapcomp";
		case 85: return "WeaponsMetal";
		case 86: return "WeaponsStone";
		case 87: return "WeaponsOther";
		case 88: return "WeaponsCoreQuality";
		case 89: return "WeaponsTotalQuality";
		case 90: return "Armor";
		case 91: return "ArmorBody";
		case 92: return "ArmorHead";
		case 93: return "ArmorFeet";
		case 94: return "ArmorHands";
		case 95: return "ArmorLegs";
		case 96: return "ArmorShield";
		case 97: return "ArmorMetal";
		case 98: return "ArmorOther";
		case 99: return "ArmorCoreQuality";
		case 100: return "ArmorTotalQuality";
		case 101: return "Sheet";
		case 102: return "SheetPaper";
		case 103: return "SheetParchment";
		case 104: return "AdditionalOptions";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_creature_interaction_effect_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::creature_interaction_effect_type::creature_interaction_effect_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "PAIN";
		case 1: return "SWELLING";
		case 2: return "OOZING";
		case 3: return "BRUISING";
		case 4: return "BLISTERS";
		case 5: return "NUMBNESS";
		case 6: return "PARALYSIS";
		case 7: return "FEVER";
		case 8: return "BLEEDING";
		case 9: return "COUGH_BLOOD";
		case 10: return "VOMIT_BLOOD";
		case 11: return "NAUSEA";
		case 12: return "UNCONSCIOUSNESS";
		case 13: return "NECROSIS";
		case 14: return "IMPAIR_FUNCTION";
		case 15: return "DROWSINESS";
		case 16: return "DIZZINESS";
		case 17: return "ADD_TAG";
		case 18: return "REMOVE_TAG";
		case 19: return "DISPLAY_TILE";
		case 20: return "FLASH_TILE";
		case 21: return "SPEED_CHANGE";
		case 22: return "CAN_DO_INTERACTION";
		case 23: return "SKILL_ROLL_ADJUST";
		case 24: return "BODY_TRANSFORMATION";
		case 25: return "PHYS_ATT_CHANGE";
		case 26: return "MENT_ATT_CHANGE";
		case 27: return "MATERIAL_FORCE_MULTIPLIER";
		case 28: return "BODY_MAT_INTERACTION";
		case 29: return "BODY_APPEARANCE_MODIFIER";
		case 30: return "BP_APPEARANCE_MODIFIER";
		case 31: return "DISPLAY_NAME";
		case 32: return "SENSE_CREATURE_CLASS";
		case 33: return "FEEL_EMOTION";
		case 34: return "CHANGE_PERSONALITY";
		case 35: return "ERRATIC_BEHAVIOR";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_creature_interaction_effect_target_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::creature_interaction_effect_target_mode::creature_interaction_effect_target_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "BY_TYPE";
		case 1: return "BY_TOKEN";
		case 2: return "BY_CATEGORY";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tiletype_shape_basic_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tiletype_shape_basic::tiletype_shape_basic*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Open";
		case 1: return "Floor";
		case 2: return "Ramp";
		case 3: return "Wall";
		case 4: return "Stair";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tiletype_shape_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tiletype_shape::tiletype_shape*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "EMPTY";
		case 1: return "FLOOR";
		case 2: return "BOULDER";
		case 3: return "PEBBLES";
		case 4: return "WALL";
		case 5: return "FORTIFICATION";
		case 6: return "STAIR_UP";
		case 7: return "STAIR_DOWN";
		case 8: return "STAIR_UPDOWN";
		case 9: return "RAMP";
		case 10: return "RAMP_TOP";
		case 11: return "BROOK_BED";
		case 12: return "BROOK_TOP";
		case 13: return "BRANCH";
		case 14: return "TRUNK_BRANCH";
		case 15: return "TWIG";
		case 16: return "SAPLING";
		case 17: return "SHRUB";
		case 18: return "ENDLESS_PIT";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tiletype_material_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tiletype_material::tiletype_material*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "AIR";
		case 1: return "SOIL";
		case 2: return "STONE";
		case 3: return "FEATURE";
		case 4: return "LAVA_STONE";
		case 5: return "MINERAL";
		case 6: return "FROZEN_LIQUID";
		case 7: return "CONSTRUCTION";
		case 8: return "GRASS_LIGHT";
		case 9: return "GRASS_DARK";
		case 10: return "GRASS_DRY";
		case 11: return "GRASS_DEAD";
		case 12: return "PLANT";
		case 13: return "HFS";
		case 14: return "CAMPFIRE";
		case 15: return "FIRE";
		case 16: return "ASHES";
		case 17: return "MAGMA";
		case 18: return "DRIFTWOOD";
		case 19: return "POOL";
		case 20: return "BROOK";
		case 21: return "RIVER";
		case 22: return "ROOT";
		case 23: return "TREE";
		case 24: return "MUSHROOM";
		case 25: return "UNDERWORLD_GATE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tiletype_variant_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tiletype_variant::tiletype_variant*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "VAR_1";
		case 1: return "VAR_2";
		case 2: return "VAR_3";
		case 3: return "VAR_4";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tiletype_special_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tiletype_special::tiletype_special*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "NORMAL";
		case 1: return "RIVER_SOURCE";
		case 2: return "WATERFALL";
		case 3: return "SMOOTH";
		case 4: return "FURROWED";
		case 5: return "WET";
		case 6: return "DEAD";
		case 7: return "WORN_1";
		case 8: return "WORN_2";
		case 9: return "WORN_3";
		case 10: return "TRACK";
		case 11: return "SMOOTH_DEAD";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tiletype_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tiletype::tiletype*>(p_address);
	switch (*m_value)
	{
		case 0: return "Void";
		case 1: return "RampTop";
		case 2: return "MurkyPool";
		case 3: return "MurkyPoolRamp";
		case 4: return "UnderworldGateStairU";
		case 5: return "UnderworldGateStairD";
		case 6: return "UnderworldGateStairUD";
		case 7: return "anon_1";
		case 8: return "anon_2";
		case 9: return "anon_3";
		case 10: return "anon_4";
		case 11: return "anon_5";
		case 12: return "anon_6";
		case 13: return "anon_7";
		case 14: return "anon_8";
		case 15: return "anon_9";
		case 16: return "anon_10";
		case 17: return "anon_11";
		case 18: return "anon_12";
		case 19: return "Driftwood";
		case 20: return "anon_13";
		case 21: return "anon_14";
		case 22: return "anon_15";
		case 23: return "anon_16";
		case 24: return "anon_17";
		case 25: return "FrozenStairUD";
		case 26: return "FrozenStairD";
		case 27: return "FrozenStairU";
		case 28: return "anon_18";
		case 29: return "anon_19";
		case 30: return "anon_20";
		case 31: return "anon_21";
		case 32: return "OpenSpace";
		case 33: return "anon_22";
		case 34: return "Shrub";
		case 35: return "Chasm";
		case 36: return "LavaStairUD";
		case 37: return "LavaStairD";
		case 38: return "LavaStairU";
		case 39: return "SoilStairUD";
		case 40: return "SoilStairD";
		case 41: return "SoilStairU";
		case 42: return "EeriePit";
		case 43: return "StoneFloorSmooth";
		case 44: return "LavaFloorSmooth";
		case 45: return "FeatureFloorSmooth";
		case 46: return "MineralFloorSmooth";
		case 47: return "FrozenFloorSmooth";
		case 48: return "anon_23";
		case 49: return "Grass1StairUD";
		case 50: return "Grass1StairD";
		case 51: return "Grass1StairU";
		case 52: return "Grass2StairUD";
		case 53: return "Grass2StairD";
		case 54: return "Grass2StairU";
		case 55: return "StoneStairUD";
		case 56: return "StoneStairD";
		case 57: return "StoneStairU";
		case 58: return "MineralStairUD";
		case 59: return "MineralStairD";
		case 60: return "MineralStairU";
		case 61: return "FeatureStairUD";
		case 62: return "FeatureStairD";
		case 63: return "FeatureStairU";
		case 64: return "anon_24";
		case 65: return "StoneFortification";
		case 66: return "anon_25";
		case 67: return "Campfire";
		case 68: return "anon_26";
		case 69: return "anon_27";
		case 70: return "Fire";
		case 71: return "BurningTreeTrunk";
		case 72: return "BurningTreeBranches";
		case 73: return "BurningTreeTwigs";
		case 74: return "BurningTreeCapWall";
		case 75: return "BurningTreeCapRamp";
		case 76: return "BurningTreeCapFloor";
		case 77: return "anon_28";
		case 78: return "anon_29";
		case 79: return "StonePillar";
		case 80: return "LavaPillar";
		case 81: return "FeaturePillar";
		case 82: return "MineralPillar";
		case 83: return "FrozenPillar";
		case 84: return "anon_30";
		case 85: return "anon_31";
		case 86: return "anon_32";
		case 87: return "anon_33";
		case 88: return "anon_34";
		case 89: return "Waterfall";
		case 90: return "RiverSource";
		case 91: return "TreeRootSloping";
		case 92: return "TreeRoots";
		case 93: return "TreeTrunkPillar";
		case 94: return "TreeTrunkSloping";
		case 95: return "TreeTrunkN";
		case 96: return "TreeTrunkS";
		case 97: return "TreeTrunkE";
		case 98: return "TreeTrunkW";
		case 99: return "TreeTrunkNW";
		case 100: return "TreeTrunkNE";
		case 101: return "TreeTrunkSW";
		case 102: return "TreeTrunkSE";
		case 103: return "TreeTrunkBranchN";
		case 104: return "TreeTrunkBranchS";
		case 105: return "TreeTrunkBranchE";
		case 106: return "TreeTrunkBranchW";
		case 107: return "TreeBranchNS";
		case 108: return "TreeBranchEW";
		case 109: return "TreeBranchesSmooth";
		case 110: return "TreeDeadBranchesSmooth";
		case 111: return "TreeBranchNW";
		case 112: return "TreeBranchNE";
		case 113: return "TreeBranchSW";
		case 114: return "TreeBranchSE";
		case 115: return "TreeBranches";
		case 116: return "TreeTwigs";
		case 117: return "TreeCapRamp";
		case 118: return "TreeCapPillar";
		case 119: return "TreeCapWallN";
		case 120: return "TreeCapWallS";
		case 121: return "TreeCapWallE";
		case 122: return "TreeCapWallW";
		case 123: return "TreeCapWallNW";
		case 124: return "TreeCapWallNE";
		case 125: return "TreeCapWallSW";
		case 126: return "TreeCapWallSE";
		case 127: return "TreeCapFloor1";
		case 128: return "TreeCapFloor2";
		case 129: return "TreeCapFloor3";
		case 130: return "TreeCapFloor4";
		case 131: return "TreeDeadRootSloping";
		case 132: return "TreeDeadRoots";
		case 133: return "TreeDeadTrunkPillar";
		case 134: return "TreeDeadTrunkSloping";
		case 135: return "TreeDeadTrunkN";
		case 136: return "TreeDeadTrunkS";
		case 137: return "TreeDeadTrunkE";
		case 138: return "TreeDeadTrunkW";
		case 139: return "TreeDeadTrunkNW";
		case 140: return "TreeDeadTrunkNE";
		case 141: return "TreeDeadTrunkSW";
		case 142: return "TreeDeadTrunkSE";
		case 143: return "TreeDeadTrunkBranchN";
		case 144: return "TreeDeadTrunkBranchS";
		case 145: return "TreeDeadTrunkBranchE";
		case 146: return "TreeDeadTrunkBranchW";
		case 147: return "TreeDeadBranchNS";
		case 148: return "TreeDeadBranchEW";
		case 149: return "anon_35";
		case 150: return "anon_36";
		case 151: return "TreeDeadBranchNW";
		case 152: return "TreeDeadBranchNE";
		case 153: return "TreeDeadBranchSW";
		case 154: return "TreeDeadBranchSE";
		case 155: return "TreeDeadBranches";
		case 156: return "TreeDeadTwigs";
		case 157: return "TreeDeadCapRamp";
		case 158: return "TreeDeadCapPillar";
		case 159: return "TreeDeadCapWallN";
		case 160: return "TreeDeadCapWallS";
		case 161: return "TreeDeadCapWallE";
		case 162: return "TreeDeadCapWallW";
		case 163: return "TreeDeadCapWallNW";
		case 164: return "TreeDeadCapWallNE";
		case 165: return "TreeDeadCapWallSW";
		case 166: return "TreeDeadCapWallSE";
		case 167: return "TreeDeadCapFloor1";
		case 168: return "TreeDeadCapFloor2";
		case 169: return "TreeDeadCapFloor3";
		case 170: return "TreeDeadCapFloor4";
		case 171: return "anon_37";
		case 172: return "StoneWallWorn1";
		case 173: return "StoneWallWorn2";
		case 174: return "StoneWallWorn3";
		case 175: return "TreeBranchNSE";
		case 176: return "TreeBranchNSW";
		case 177: return "TreeBranchNEW";
		case 178: return "TreeBranchSEW";
		case 179: return "TreeBranchNSEW";
		case 180: return "TreeDeadBranchNSE";
		case 181: return "TreeDeadBranchNSW";
		case 182: return "TreeDeadBranchNEW";
		case 183: return "TreeDeadBranchSEW";
		case 184: return "TreeDeadBranchNSEW";
		case 185: return "TreeTrunkNSE";
		case 186: return "TreeTrunkNSW";
		case 187: return "TreeTrunkNEW";
		case 188: return "TreeTrunkSEW";
		case 189: return "TreeTrunkNS";
		case 190: return "TreeTrunkEW";
		case 191: return "TreeTrunkNSEW";
		case 192: return "TreeTrunkInterior";
		case 193: return "TreeDeadTrunkNSE";
		case 194: return "TreeDeadTrunkNSW";
		case 195: return "TreeDeadTrunkNEW";
		case 196: return "TreeDeadTrunkSEW";
		case 197: return "TreeDeadTrunkNS";
		case 198: return "TreeDeadTrunkEW";
		case 199: return "TreeDeadTrunkNSEW";
		case 200: return "TreeDeadTrunkInterior";
		case 201: return "anon_38";
		case 202: return "anon_39";
		case 203: return "anon_40";
		case 204: return "anon_41";
		case 205: return "anon_42";
		case 206: return "anon_43";
		case 207: return "anon_44";
		case 208: return "anon_45";
		case 209: return "anon_46";
		case 210: return "anon_47";
		case 211: return "anon_48";
		case 212: return "anon_49";
		case 213: return "anon_50";
		case 214: return "anon_51";
		case 215: return "StoneWall";
		case 216: return "anon_52";
		case 217: return "anon_53";
		case 218: return "anon_54";
		case 219: return "anon_55";
		case 220: return "anon_56";
		case 221: return "anon_57";
		case 222: return "anon_58";
		case 223: return "anon_59";
		case 224: return "anon_60";
		case 225: return "anon_61";
		case 226: return "anon_62";
		case 227: return "Sapling";
		case 228: return "anon_63";
		case 229: return "GrassDryRamp";
		case 230: return "GrassDeadRamp";
		case 231: return "GrassLightRamp";
		case 232: return "GrassDarkRamp";
		case 233: return "StoneRamp";
		case 234: return "LavaRamp";
		case 235: return "FeatureRamp";
		case 236: return "MineralRamp";
		case 237: return "SoilRamp";
		case 238: return "Ashes1";
		case 239: return "Ashes2";
		case 240: return "Ashes3";
		case 241: return "FrozenRamp";
		case 242: return "anon_64";
		case 243: return "anon_65";
		case 244: return "anon_66";
		case 245: return "anon_67";
		case 246: return "anon_68";
		case 247: return "anon_69";
		case 248: return "anon_70";
		case 249: return "anon_71";
		case 250: return "anon_72";
		case 251: return "anon_73";
		case 252: return "anon_74";
		case 253: return "anon_75";
		case 254: return "FrozenFloor2";
		case 255: return "FrozenFloor3";
		case 256: return "FrozenFloor4";
		case 257: return "FurrowedSoil";
		case 258: return "FrozenFloor1";
		case 259: return "SemiMoltenRock";
		case 260: return "MagmaFlow";
		case 261: return "SoilWall";
		case 262: return "GlowingBarrier";
		case 263: return "GlowingFloor";
		case 264: return "anon_76";
		case 265: return "LavaWallSmoothRD2";
		case 266: return "LavaWallSmoothR2D";
		case 267: return "LavaWallSmoothR2U";
		case 268: return "LavaWallSmoothRU2";
		case 269: return "LavaWallSmoothL2U";
		case 270: return "LavaWallSmoothLU2";
		case 271: return "LavaWallSmoothL2D";
		case 272: return "LavaWallSmoothLD2";
		case 273: return "LavaWallSmoothLRUD";
		case 274: return "LavaWallSmoothRUD";
		case 275: return "LavaWallSmoothLRD";
		case 276: return "LavaWallSmoothLRU";
		case 277: return "LavaWallSmoothLUD";
		case 278: return "LavaWallSmoothRD";
		case 279: return "LavaWallSmoothRU";
		case 280: return "LavaWallSmoothLU";
		case 281: return "LavaWallSmoothLD";
		case 282: return "LavaWallSmoothUD";
		case 283: return "LavaWallSmoothLR";
		case 284: return "FeatureWallSmoothRD2";
		case 285: return "FeatureWallSmoothR2D";
		case 286: return "FeatureWallSmoothR2U";
		case 287: return "FeatureWallSmoothRU2";
		case 288: return "FeatureWallSmoothL2U";
		case 289: return "FeatureWallSmoothLU2";
		case 290: return "FeatureWallSmoothL2D";
		case 291: return "FeatureWallSmoothLD2";
		case 292: return "FeatureWallSmoothLRUD";
		case 293: return "FeatureWallSmoothRUD";
		case 294: return "FeatureWallSmoothLRD";
		case 295: return "FeatureWallSmoothLRU";
		case 296: return "FeatureWallSmoothLUD";
		case 297: return "FeatureWallSmoothRD";
		case 298: return "FeatureWallSmoothRU";
		case 299: return "FeatureWallSmoothLU";
		case 300: return "FeatureWallSmoothLD";
		case 301: return "FeatureWallSmoothUD";
		case 302: return "FeatureWallSmoothLR";
		case 303: return "StoneWallSmoothRD2";
		case 304: return "StoneWallSmoothR2D";
		case 305: return "StoneWallSmoothR2U";
		case 306: return "StoneWallSmoothRU2";
		case 307: return "StoneWallSmoothL2U";
		case 308: return "StoneWallSmoothLU2";
		case 309: return "StoneWallSmoothL2D";
		case 310: return "StoneWallSmoothLD2";
		case 311: return "StoneWallSmoothLRUD";
		case 312: return "StoneWallSmoothRUD";
		case 313: return "StoneWallSmoothLRD";
		case 314: return "StoneWallSmoothLRU";
		case 315: return "StoneWallSmoothLUD";
		case 316: return "StoneWallSmoothRD";
		case 317: return "StoneWallSmoothRU";
		case 318: return "StoneWallSmoothLU";
		case 319: return "StoneWallSmoothLD";
		case 320: return "StoneWallSmoothUD";
		case 321: return "StoneWallSmoothLR";
		case 322: return "LavaFortification";
		case 323: return "FeatureFortification";
		case 324: return "LavaWallWorn1";
		case 325: return "LavaWallWorn2";
		case 326: return "LavaWallWorn3";
		case 327: return "LavaWall";
		case 328: return "FeatureWallWorn1";
		case 329: return "FeatureWallWorn2";
		case 330: return "FeatureWallWorn3";
		case 331: return "FeatureWall";
		case 332: return "StoneFloor1";
		case 333: return "StoneFloor2";
		case 334: return "StoneFloor3";
		case 335: return "StoneFloor4";
		case 336: return "LavaFloor1";
		case 337: return "LavaFloor2";
		case 338: return "LavaFloor3";
		case 339: return "LavaFloor4";
		case 340: return "FeatureFloor1";
		case 341: return "FeatureFloor2";
		case 342: return "FeatureFloor3";
		case 343: return "FeatureFloor4";
		case 344: return "GrassDarkFloor1";
		case 345: return "GrassDarkFloor2";
		case 346: return "GrassDarkFloor3";
		case 347: return "GrassDarkFloor4";
		case 348: return "SoilFloor1";
		case 349: return "SoilFloor2";
		case 350: return "SoilFloor3";
		case 351: return "SoilFloor4";
		case 352: return "SoilWetFloor1";
		case 353: return "SoilWetFloor2";
		case 354: return "SoilWetFloor3";
		case 355: return "SoilWetFloor4";
		case 356: return "FrozenFortification";
		case 357: return "FrozenWallWorn1";
		case 358: return "FrozenWallWorn2";
		case 359: return "FrozenWallWorn3";
		case 360: return "FrozenWall";
		case 361: return "RiverN";
		case 362: return "RiverS";
		case 363: return "RiverE";
		case 364: return "RiverW";
		case 365: return "RiverNW";
		case 366: return "RiverNE";
		case 367: return "RiverSW";
		case 368: return "RiverSE";
		case 369: return "BrookN";
		case 370: return "BrookS";
		case 371: return "BrookE";
		case 372: return "BrookW";
		case 373: return "BrookNW";
		case 374: return "BrookNE";
		case 375: return "BrookSW";
		case 376: return "BrookSE";
		case 377: return "BrookTop";
		case 378: return "anon_77";
		case 379: return "anon_78";
		case 380: return "anon_79";
		case 381: return "anon_80";
		case 382: return "anon_81";
		case 383: return "GrassDryFloor1";
		case 384: return "GrassDryFloor2";
		case 385: return "GrassDryFloor3";
		case 386: return "GrassDryFloor4";
		case 387: return "anon_82";
		case 388: return "SaplingDead";
		case 389: return "ShrubDead";
		case 390: return "GrassDeadFloor1";
		case 391: return "GrassDeadFloor2";
		case 392: return "GrassDeadFloor3";
		case 393: return "GrassDeadFloor4";
		case 394: return "GrassLightFloor1";
		case 395: return "GrassLightFloor2";
		case 396: return "GrassLightFloor3";
		case 397: return "GrassLightFloor4";
		case 398: return "StoneBoulder";
		case 399: return "LavaBoulder";
		case 400: return "FeatureBoulder";
		case 401: return "StonePebbles1";
		case 402: return "StonePebbles2";
		case 403: return "StonePebbles3";
		case 404: return "StonePebbles4";
		case 405: return "LavaPebbles1";
		case 406: return "LavaPebbles2";
		case 407: return "LavaPebbles3";
		case 408: return "LavaPebbles4";
		case 409: return "FeaturePebbles1";
		case 410: return "FeaturePebbles2";
		case 411: return "FeaturePebbles3";
		case 412: return "FeaturePebbles4";
		case 413: return "MineralWallSmoothRD2";
		case 414: return "MineralWallSmoothR2D";
		case 415: return "MineralWallSmoothR2U";
		case 416: return "MineralWallSmoothRU2";
		case 417: return "MineralWallSmoothL2U";
		case 418: return "MineralWallSmoothLU2";
		case 419: return "MineralWallSmoothL2D";
		case 420: return "MineralWallSmoothLD2";
		case 421: return "MineralWallSmoothLRUD";
		case 422: return "MineralWallSmoothRUD";
		case 423: return "MineralWallSmoothLRD";
		case 424: return "MineralWallSmoothLRU";
		case 425: return "MineralWallSmoothLUD";
		case 426: return "MineralWallSmoothRD";
		case 427: return "MineralWallSmoothRU";
		case 428: return "MineralWallSmoothLU";
		case 429: return "MineralWallSmoothLD";
		case 430: return "MineralWallSmoothUD";
		case 431: return "MineralWallSmoothLR";
		case 432: return "MineralFortification";
		case 433: return "MineralWallWorn1";
		case 434: return "MineralWallWorn2";
		case 435: return "MineralWallWorn3";
		case 436: return "MineralWall";
		case 437: return "MineralFloor1";
		case 438: return "MineralFloor2";
		case 439: return "MineralFloor3";
		case 440: return "MineralFloor4";
		case 441: return "MineralBoulder";
		case 442: return "MineralPebbles1";
		case 443: return "MineralPebbles2";
		case 444: return "MineralPebbles3";
		case 445: return "MineralPebbles4";
		case 446: return "FrozenWallSmoothRD2";
		case 447: return "FrozenWallSmoothR2D";
		case 448: return "FrozenWallSmoothR2U";
		case 449: return "FrozenWallSmoothRU2";
		case 450: return "FrozenWallSmoothL2U";
		case 451: return "FrozenWallSmoothLU2";
		case 452: return "FrozenWallSmoothL2D";
		case 453: return "FrozenWallSmoothLD2";
		case 454: return "FrozenWallSmoothLRUD";
		case 455: return "FrozenWallSmoothRUD";
		case 456: return "FrozenWallSmoothLRD";
		case 457: return "FrozenWallSmoothLRU";
		case 458: return "FrozenWallSmoothLUD";
		case 459: return "FrozenWallSmoothRD";
		case 460: return "FrozenWallSmoothRU";
		case 461: return "FrozenWallSmoothLU";
		case 462: return "FrozenWallSmoothLD";
		case 463: return "FrozenWallSmoothUD";
		case 464: return "FrozenWallSmoothLR";
		case 465: return "RiverRampN";
		case 466: return "RiverRampS";
		case 467: return "RiverRampE";
		case 468: return "RiverRampW";
		case 469: return "RiverRampNW";
		case 470: return "RiverRampNE";
		case 471: return "RiverRampSW";
		case 472: return "RiverRampSE";
		case 473: return "anon_83";
		case 474: return "anon_84";
		case 475: return "anon_85";
		case 476: return "anon_86";
		case 477: return "anon_87";
		case 478: return "anon_88";
		case 479: return "anon_89";
		case 480: return "anon_90";
		case 481: return "anon_91";
		case 482: return "anon_92";
		case 483: return "anon_93";
		case 484: return "anon_94";
		case 485: return "anon_95";
		case 486: return "anon_96";
		case 487: return "anon_97";
		case 488: return "anon_98";
		case 489: return "ConstructedFloor";
		case 490: return "ConstructedFortification";
		case 491: return "ConstructedPillar";
		case 492: return "ConstructedWallRD2";
		case 493: return "ConstructedWallR2D";
		case 494: return "ConstructedWallR2U";
		case 495: return "ConstructedWallRU2";
		case 496: return "ConstructedWallL2U";
		case 497: return "ConstructedWallLU2";
		case 498: return "ConstructedWallL2D";
		case 499: return "ConstructedWallLD2";
		case 500: return "ConstructedWallLRUD";
		case 501: return "ConstructedWallRUD";
		case 502: return "ConstructedWallLRD";
		case 503: return "ConstructedWallLRU";
		case 504: return "ConstructedWallLUD";
		case 505: return "ConstructedWallRD";
		case 506: return "ConstructedWallRU";
		case 507: return "ConstructedWallLU";
		case 508: return "ConstructedWallLD";
		case 509: return "ConstructedWallUD";
		case 510: return "ConstructedWallLR";
		case 511: return "ConstructedStairUD";
		case 512: return "ConstructedStairD";
		case 513: return "ConstructedStairU";
		case 514: return "ConstructedRamp";
		case 515: return "StoneFloorTrackN";
		case 516: return "StoneFloorTrackS";
		case 517: return "StoneFloorTrackE";
		case 518: return "StoneFloorTrackW";
		case 519: return "StoneFloorTrackNS";
		case 520: return "StoneFloorTrackNE";
		case 521: return "StoneFloorTrackNW";
		case 522: return "StoneFloorTrackSE";
		case 523: return "StoneFloorTrackSW";
		case 524: return "StoneFloorTrackEW";
		case 525: return "StoneFloorTrackNSE";
		case 526: return "StoneFloorTrackNSW";
		case 527: return "StoneFloorTrackNEW";
		case 528: return "StoneFloorTrackSEW";
		case 529: return "StoneFloorTrackNSEW";
		case 530: return "LavaFloorTrackN";
		case 531: return "LavaFloorTrackS";
		case 532: return "LavaFloorTrackE";
		case 533: return "LavaFloorTrackW";
		case 534: return "LavaFloorTrackNS";
		case 535: return "LavaFloorTrackNE";
		case 536: return "LavaFloorTrackNW";
		case 537: return "LavaFloorTrackSE";
		case 538: return "LavaFloorTrackSW";
		case 539: return "LavaFloorTrackEW";
		case 540: return "LavaFloorTrackNSE";
		case 541: return "LavaFloorTrackNSW";
		case 542: return "LavaFloorTrackNEW";
		case 543: return "LavaFloorTrackSEW";
		case 544: return "LavaFloorTrackNSEW";
		case 545: return "FeatureFloorTrackN";
		case 546: return "FeatureFloorTrackS";
		case 547: return "FeatureFloorTrackE";
		case 548: return "FeatureFloorTrackW";
		case 549: return "FeatureFloorTrackNS";
		case 550: return "FeatureFloorTrackNE";
		case 551: return "FeatureFloorTrackNW";
		case 552: return "FeatureFloorTrackSE";
		case 553: return "FeatureFloorTrackSW";
		case 554: return "FeatureFloorTrackEW";
		case 555: return "FeatureFloorTrackNSE";
		case 556: return "FeatureFloorTrackNSW";
		case 557: return "FeatureFloorTrackNEW";
		case 558: return "FeatureFloorTrackSEW";
		case 559: return "FeatureFloorTrackNSEW";
		case 560: return "MineralFloorTrackN";
		case 561: return "MineralFloorTrackS";
		case 562: return "MineralFloorTrackE";
		case 563: return "MineralFloorTrackW";
		case 564: return "MineralFloorTrackNS";
		case 565: return "MineralFloorTrackNE";
		case 566: return "MineralFloorTrackNW";
		case 567: return "MineralFloorTrackSE";
		case 568: return "MineralFloorTrackSW";
		case 569: return "MineralFloorTrackEW";
		case 570: return "MineralFloorTrackNSE";
		case 571: return "MineralFloorTrackNSW";
		case 572: return "MineralFloorTrackNEW";
		case 573: return "MineralFloorTrackSEW";
		case 574: return "MineralFloorTrackNSEW";
		case 575: return "FrozenFloorTrackN";
		case 576: return "FrozenFloorTrackS";
		case 577: return "FrozenFloorTrackE";
		case 578: return "FrozenFloorTrackW";
		case 579: return "FrozenFloorTrackNS";
		case 580: return "FrozenFloorTrackNE";
		case 581: return "FrozenFloorTrackNW";
		case 582: return "FrozenFloorTrackSE";
		case 583: return "FrozenFloorTrackSW";
		case 584: return "FrozenFloorTrackEW";
		case 585: return "FrozenFloorTrackNSE";
		case 586: return "FrozenFloorTrackNSW";
		case 587: return "FrozenFloorTrackNEW";
		case 588: return "FrozenFloorTrackSEW";
		case 589: return "FrozenFloorTrackNSEW";
		case 590: return "ConstructedFloorTrackN";
		case 591: return "ConstructedFloorTrackS";
		case 592: return "ConstructedFloorTrackE";
		case 593: return "ConstructedFloorTrackW";
		case 594: return "ConstructedFloorTrackNS";
		case 595: return "ConstructedFloorTrackNE";
		case 596: return "ConstructedFloorTrackNW";
		case 597: return "ConstructedFloorTrackSE";
		case 598: return "ConstructedFloorTrackSW";
		case 599: return "ConstructedFloorTrackEW";
		case 600: return "ConstructedFloorTrackNSE";
		case 601: return "ConstructedFloorTrackNSW";
		case 602: return "ConstructedFloorTrackNEW";
		case 603: return "ConstructedFloorTrackSEW";
		case 604: return "ConstructedFloorTrackNSEW";
		case 605: return "StoneRampTrackN";
		case 606: return "StoneRampTrackS";
		case 607: return "StoneRampTrackE";
		case 608: return "StoneRampTrackW";
		case 609: return "StoneRampTrackNS";
		case 610: return "StoneRampTrackNE";
		case 611: return "StoneRampTrackNW";
		case 612: return "StoneRampTrackSE";
		case 613: return "StoneRampTrackSW";
		case 614: return "StoneRampTrackEW";
		case 615: return "StoneRampTrackNSE";
		case 616: return "StoneRampTrackNSW";
		case 617: return "StoneRampTrackNEW";
		case 618: return "StoneRampTrackSEW";
		case 619: return "StoneRampTrackNSEW";
		case 620: return "LavaRampTrackN";
		case 621: return "LavaRampTrackS";
		case 622: return "LavaRampTrackE";
		case 623: return "LavaRampTrackW";
		case 624: return "LavaRampTrackNS";
		case 625: return "LavaRampTrackNE";
		case 626: return "LavaRampTrackNW";
		case 627: return "LavaRampTrackSE";
		case 628: return "LavaRampTrackSW";
		case 629: return "LavaRampTrackEW";
		case 630: return "LavaRampTrackNSE";
		case 631: return "LavaRampTrackNSW";
		case 632: return "LavaRampTrackNEW";
		case 633: return "LavaRampTrackSEW";
		case 634: return "LavaRampTrackNSEW";
		case 635: return "FeatureRampTrackN";
		case 636: return "FeatureRampTrackS";
		case 637: return "FeatureRampTrackE";
		case 638: return "FeatureRampTrackW";
		case 639: return "FeatureRampTrackNS";
		case 640: return "FeatureRampTrackNE";
		case 641: return "FeatureRampTrackNW";
		case 642: return "FeatureRampTrackSE";
		case 643: return "FeatureRampTrackSW";
		case 644: return "FeatureRampTrackEW";
		case 645: return "FeatureRampTrackNSE";
		case 646: return "FeatureRampTrackNSW";
		case 647: return "FeatureRampTrackNEW";
		case 648: return "FeatureRampTrackSEW";
		case 649: return "FeatureRampTrackNSEW";
		case 650: return "MineralRampTrackN";
		case 651: return "MineralRampTrackS";
		case 652: return "MineralRampTrackE";
		case 653: return "MineralRampTrackW";
		case 654: return "MineralRampTrackNS";
		case 655: return "MineralRampTrackNE";
		case 656: return "MineralRampTrackNW";
		case 657: return "MineralRampTrackSE";
		case 658: return "MineralRampTrackSW";
		case 659: return "MineralRampTrackEW";
		case 660: return "MineralRampTrackNSE";
		case 661: return "MineralRampTrackNSW";
		case 662: return "MineralRampTrackNEW";
		case 663: return "MineralRampTrackSEW";
		case 664: return "MineralRampTrackNSEW";
		case 665: return "FrozenRampTrackN";
		case 666: return "FrozenRampTrackS";
		case 667: return "FrozenRampTrackE";
		case 668: return "FrozenRampTrackW";
		case 669: return "FrozenRampTrackNS";
		case 670: return "FrozenRampTrackNE";
		case 671: return "FrozenRampTrackNW";
		case 672: return "FrozenRampTrackSE";
		case 673: return "FrozenRampTrackSW";
		case 674: return "FrozenRampTrackEW";
		case 675: return "FrozenRampTrackNSE";
		case 676: return "FrozenRampTrackNSW";
		case 677: return "FrozenRampTrackNEW";
		case 678: return "FrozenRampTrackSEW";
		case 679: return "FrozenRampTrackNSEW";
		case 680: return "ConstructedRampTrackN";
		case 681: return "ConstructedRampTrackS";
		case 682: return "ConstructedRampTrackE";
		case 683: return "ConstructedRampTrackW";
		case 684: return "ConstructedRampTrackNS";
		case 685: return "ConstructedRampTrackNE";
		case 686: return "ConstructedRampTrackNW";
		case 687: return "ConstructedRampTrackSE";
		case 688: return "ConstructedRampTrackSW";
		case 689: return "ConstructedRampTrackEW";
		case 690: return "ConstructedRampTrackNSE";
		case 691: return "ConstructedRampTrackNSW";
		case 692: return "ConstructedRampTrackNEW";
		case 693: return "ConstructedRampTrackSEW";
		case 694: return "ConstructedRampTrackNSEW";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_build_req_choice_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::build_req_choice_type::build_req_choice_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "General";
		case 1: return "Specific";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_hotkey__T_cmd_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_hotkey::T_cmd*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Zoom";
		case 1: return "FollowUnit";
		case 2: return "FollowItem";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_sidebar_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::ui_sidebar_mode::ui_sidebar_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Default";
		case 1: return "Squads";
		case 2: return "DesignateMine";
		case 3: return "DesignateRemoveRamps";
		case 4: return "DesignateUpStair";
		case 5: return "DesignateDownStair";
		case 6: return "DesignateUpDownStair";
		case 7: return "DesignateUpRamp";
		case 8: return "DesignateChannel";
		case 9: return "DesignateGatherPlants";
		case 10: return "DesignateRemoveDesignation";
		case 11: return "DesignateSmooth";
		case 12: return "DesignateCarveTrack";
		case 13: return "DesignateEngrave";
		case 14: return "DesignateCarveFortification";
		case 15: return "Stockpiles";
		case 16: return "Build";
		case 17: return "QueryBuilding";
		case 18: return "Orders";
		case 19: return "OrdersForbid";
		case 20: return "OrdersRefuse";
		case 21: return "OrdersWorkshop";
		case 22: return "OrdersZone";
		case 23: return "BuildingItems";
		case 24: return "ViewUnits";
		case 25: return "LookAround";
		case 26: return "DesignateItemsClaim";
		case 27: return "DesignateItemsForbid";
		case 28: return "DesignateItemsMelt";
		case 29: return "DesignateItemsUnmelt";
		case 30: return "DesignateItemsDump";
		case 31: return "DesignateItemsUndump";
		case 32: return "DesignateItemsHide";
		case 33: return "DesignateItemsUnhide";
		case 34: return "DesignateChopTrees";
		case 35: return "DesignateToggleEngravings";
		case 36: return "DesignateToggleMarker";
		case 37: return "Hotkeys";
		case 38: return "DesignateTrafficHigh";
		case 39: return "DesignateTrafficNormal";
		case 40: return "DesignateTrafficLow";
		case 41: return "DesignateTrafficRestricted";
		case 42: return "Zones";
		case 43: return "ZonesPenInfo";
		case 44: return "ZonesPitInfo";
		case 45: return "ZonesHospitalInfo";
		case 46: return "ZonesGatherInfo";
		case 47: return "DesignateRemoveConstruction";
		case 48: return "DepotAccess";
		case 49: return "NotesPoints";
		case 50: return "NotesRoutes";
		case 51: return "Burrows";
		case 52: return "Hauling";
		case 53: return "ArenaWeather";
		case 54: return "ArenaTrees";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_kitchen_exc_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::kitchen_exc_type::kitchen_exc_type*>(p_address);
	switch (*m_value)
	{
		case 1: return "Cook";
		case 2: return "Brew";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_timed_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::timed_event_type::timed_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Caravan";
		case 1: return "Migrants";
		case 2: return "Diplomat";
		case 3: return "FeatureAttack";
		case 4: return "Megabeast";
		case 5: return "WildlifeCurious";
		case 6: return "WildlifeMischievous";
		case 7: return "WildlifeFlier";
		case 8: return "NightCreature";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_emotion_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::emotion_type::emotion_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "ANYTHING";
		case 0: return "ACCEPTANCE";
		case 1: return "ADORATION";
		case 2: return "AFFECTION";
		case 3: return "AGITATION";
		case 4: return "AGGRAVATION";
		case 5: return "AGONY";
		case 6: return "ALARM";
		case 7: return "ALIENATION";
		case 8: return "AMAZEMENT";
		case 9: return "AMBIVALENCE";
		case 10: return "AMUSEMENT";
		case 11: return "ANGER";
		case 12: return "ANGST";
		case 13: return "ANGUISH";
		case 14: return "ANNOYANCE";
		case 15: return "anon_1";
		case 16: return "ANXIETY";
		case 17: return "APATHY";
		case 18: return "anon_2";
		case 19: return "AROUSAL";
		case 20: return "ASTONISHMENT";
		case 21: return "anon_3";
		case 22: return "AVERSION";
		case 23: return "AWE";
		case 24: return "BITTERNESS";
		case 25: return "BLISS";
		case 26: return "BOREDOM";
		case 27: return "CARING";
		case 28: return "anon_4";
		case 29: return "CONFUSION";
		case 30: return "CONTEMPT";
		case 31: return "CONTENTMENT";
		case 32: return "anon_5";
		case 33: return "anon_6";
		case 34: return "DEFEAT";
		case 35: return "DEJECTION";
		case 36: return "DELIGHT";
		case 37: return "anon_7";
		case 38: return "anon_8";
		case 39: return "DESPAIR";
		case 40: return "DISAPPOINTMENT";
		case 41: return "DISGUST";
		case 42: return "DISILLUSIONMENT";
		case 43: return "DISLIKE";
		case 44: return "DISMAY";
		case 45: return "DISPLEASURE";
		case 46: return "DISTRESS";
		case 47: return "DOUBT";
		case 48: return "anon_9";
		case 49: return "EAGERNESS";
		case 50: return "anon_10";
		case 51: return "ELATION";
		case 52: return "EMBARRASSMENT";
		case 53: return "EMPATHY";
		case 54: return "EMPTINESS";
		case 55: return "ENJOYMENT";
		case 56: return "anon_11";
		case 57: return "ENTHUSIASM";
		case 58: return "anon_12";
		case 59: return "EUPHORIA";
		case 60: return "EXASPERATION";
		case 61: return "EXCITEMENT";
		case 62: return "EXHILARATION";
		case 63: return "EXPECTANCY";
		case 64: return "FEAR";
		case 65: return "FEROCITY";
		case 66: return "FONDNESS";
		case 67: return "FREEDOM";
		case 68: return "FRIGHT";
		case 69: return "FRUSTRATION";
		case 70: return "anon_13";
		case 71: return "GAIETY";
		case 72: return "anon_14";
		case 73: return "GLEE";
		case 74: return "GLOOM";
		case 75: return "GLUMNESS";
		case 76: return "GRATITUDE";
		case 77: return "anon_15";
		case 78: return "GRIEF";
		case 79: return "GRIM_SATISFACTION";
		case 80: return "GROUCHINESS";
		case 81: return "GRUMPINESS";
		case 82: return "GUILT";
		case 83: return "HAPPINESS";
		case 84: return "HATRED";
		case 85: return "anon_16";
		case 86: return "HOPE";
		case 87: return "HOPELESSNESS";
		case 88: return "HORROR";
		case 89: return "anon_17";
		case 90: return "HUMILIATION";
		case 91: return "anon_18";
		case 92: return "anon_19";
		case 93: return "anon_20";
		case 94: return "anon_21";
		case 95: return "INSULT";
		case 96: return "INTEREST";
		case 97: return "IRRITATION";
		case 98: return "ISOLATION";
		case 99: return "anon_22";
		case 100: return "JOLLINESS";
		case 101: return "JOVIALITY";
		case 102: return "JOY";
		case 103: return "JUBILATION";
		case 104: return "anon_23";
		case 105: return "LOATHING";
		case 106: return "LONELINESS";
		case 107: return "anon_24";
		case 108: return "LOVE";
		case 109: return "anon_25";
		case 110: return "LUST";
		case 111: return "anon_26";
		case 112: return "MISERY";
		case 113: return "MORTIFICATION";
		case 114: return "anon_27";
		case 115: return "NERVOUSNESS";
		case 116: return "NOSTALGIA";
		case 117: return "OPTIMISM";
		case 118: return "OUTRAGE";
		case 119: return "PANIC";
		case 120: return "PATIENCE";
		case 121: return "PASSION";
		case 122: return "PESSIMISM";
		case 123: return "anon_28";
		case 124: return "PLEASURE";
		case 125: return "PRIDE";
		case 126: return "RAGE";
		case 127: return "RAPTURE";
		case 128: return "REJECTION";
		case 129: return "RELIEF";
		case 130: return "REGRET";
		case 131: return "REMORSE";
		case 132: return "REPENTANCE";
		case 133: return "RESENTMENT";
		case 134: return "anon_29";
		case 135: return "RIGHTEOUS_INDIGNATION";
		case 136: return "SADNESS";
		case 137: return "SATISFACTION";
		case 138: return "anon_30";
		case 139: return "SELF_PITY";
		case 140: return "anon_31";
		case 141: return "SERVILE";
		case 142: return "SHAKEN";
		case 143: return "SHAME";
		case 144: return "SHOCK";
		case 145: return "anon_32";
		case 146: return "anon_33";
		case 147: return "anon_34";
		case 148: return "anon_35";
		case 149: return "SUSPICION";
		case 150: return "SYMPATHY";
		case 151: return "TENDERNESS";
		case 152: return "anon_36";
		case 153: return "TERROR";
		case 154: return "THRILL";
		case 155: return "anon_37";
		case 156: return "TRIUMPH";
		case 157: return "UNEASINESS";
		case 158: return "UNHAPPINESS";
		case 159: return "VENGEFULNESS";
		case 160: return "anon_38";
		case 161: return "WONDER";
		case 162: return "WORRY";
		case 163: return "WRATH";
		case 164: return "ZEAL";
		case 165: return "anon_39";
		case 166: return "anon_40";
		case 167: return "anon_41";
		case 168: return "RESTLESS";
		case 169: return "ADMIRATION";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_thought_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::unit_thought_type::unit_thought_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Conflict";
		case 1: return "Trauma";
		case 2: return "WitnessDeath";
		case 3: return "UnexpectedDeath";
		case 4: return "Death";
		case 5: return "Kill";
		case 6: return "LoveSeparated";
		case 7: return "LoveReunited";
		case 8: return "JoinConflict";
		case 9: return "MakeMasterwork";
		case 10: return "MadeArtifact";
		case 11: return "MasterSkill";
		case 12: return "NewRomance";
		case 13: return "BecomeParent";
		case 14: return "NearConflict";
		case 15: return "CancelAgreement";
		case 16: return "JoinTravel";
		case 17: return "SiteControlled";
		case 18: return "TributeCancel";
		case 19: return "Incident";
		case 20: return "HearRumor";
		case 21: return "MilitaryRemoved";
		case 22: return "StrangerWeapon";
		case 23: return "StrangerSneaking";
		case 24: return "SawDrinkBlood";
		case 25: return "Complained";
		case 26: return "ReceivedComplaint";
		case 27: return "AdmireBuilding";
		case 28: return "AdmireOwnBuilding";
		case 29: return "AdmireArrangedBuilding";
		case 30: return "AdmireOwnArrangedBuilding";
		case 31: return "LostPet";
		case 32: return "ThrownStuff";
		case 33: return "JailReleased";
		case 34: return "Miscarriage";
		case 35: return "SpouseMiscarriage";
		case 36: return "OldClothing";
		case 37: return "TatteredClothing";
		case 38: return "RottedClothing";
		case 39: return "GhostNightmare";
		case 40: return "GhostHaunt";
		case 41: return "Spar";
		case 42: return "UnableComplain";
		case 43: return "LongPatrol";
		case 44: return "SunNausea";
		case 45: return "SunIrritated";
		case 46: return "Drowsy";
		case 47: return "VeryDrowsy";
		case 48: return "Thirsty";
		case 49: return "Dehydrated";
		case 50: return "Hungry";
		case 51: return "Starving";
		case 52: return "MajorInjuries";
		case 53: return "MinorInjuries";
		case 54: return "SleepNoise";
		case 55: return "Rest";
		case 56: return "FreakishWeather";
		case 57: return "Rain";
		case 58: return "SnowStorm";
		case 59: return "Miasma";
		case 60: return "Smoke";
		case 61: return "Waterfall";
		case 62: return "Dust";
		case 63: return "Demands";
		case 64: return "ImproperPunishment";
		case 65: return "PunishmentReduced";
		case 66: return "Elected";
		case 67: return "Reelected";
		case 68: return "RequestApproved";
		case 69: return "RequestIgnored";
		case 70: return "NoPunishment";
		case 71: return "PunishmentDelayed";
		case 72: return "DelayedPunishment";
		case 73: return "ScarceCageChain";
		case 74: return "MandateIgnored";
		case 75: return "MandateDeadlineMissed";
		case 76: return "LackWork";
		case 77: return "SmashedBuilding";
		case 78: return "ToppledStuff";
		case 79: return "NoblePromotion";
		case 80: return "BecomeNoble";
		case 81: return "Cavein";
		case 82: return "MandateDeadlineMet";
		case 83: return "Uncovered";
		case 84: return "NoShirt";
		case 85: return "NoShoes";
		case 86: return "EatPet";
		case 87: return "EatLikedCreature";
		case 88: return "EatVermin";
		case 89: return "FistFight";
		case 90: return "GaveBeating";
		case 91: return "GotBeaten";
		case 92: return "GaveHammering";
		case 93: return "GotHammered";
		case 94: return "NoHammer";
		case 95: return "SameFood";
		case 96: return "AteRotten";
		case 97: return "GoodMeal";
		case 98: return "GoodDrink";
		case 99: return "MoreChests";
		case 100: return "MoreCabinets";
		case 101: return "MoreWeaponRacks";
		case 102: return "MoreArmorStands";
		case 103: return "RoomPretension";
		case 104: return "LackTables";
		case 105: return "CrowdedTables";
		case 106: return "DiningQuality";
		case 107: return "NoDining";
		case 108: return "LackChairs";
		case 109: return "TrainingBond";
		case 110: return "Rescued";
		case 111: return "RescuedOther";
		case 112: return "SatisfiedAtWork";
		case 113: return "TaxedLostProperty";
		case 114: return "Taxed";
		case 115: return "LackProtection";
		case 116: return "TaxRoomUnreachable";
		case 117: return "TaxRoomMisinformed";
		case 118: return "PleasedNoble";
		case 119: return "TaxCollectionSmooth";
		case 120: return "DisappointedNoble";
		case 121: return "TaxCollectionRough";
		case 122: return "MadeFriend";
		case 123: return "FormedGrudge";
		case 124: return "AnnoyedVermin";
		case 125: return "NearVermin";
		case 126: return "PesteredVermin";
		case 127: return "AcquiredItem";
		case 128: return "AdoptedPet";
		case 129: return "Jailed";
		case 130: return "Bath";
		case 131: return "SoapyBath";
		case 132: return "SparringAccident";
		case 133: return "Attacked";
		case 134: return "AttackedByDead";
		case 135: return "SameBooze";
		case 136: return "DrinkBlood";
		case 137: return "DrinkSlime";
		case 138: return "DrinkVomit";
		case 139: return "DrinkGoo";
		case 140: return "DrinkIchor";
		case 141: return "DrinkPus";
		case 142: return "NastyWater";
		case 143: return "DrankSpoiled";
		case 144: return "LackWell";
		case 145: return "NearCaged";
		case 146: return "NearCagedHated";
		case 147: return "LackBedroom";
		case 148: return "BedroomQuality";
		case 149: return "SleptFloor";
		case 150: return "SleptMud";
		case 151: return "SleptGrass";
		case 152: return "SleptRoughFloor";
		case 153: return "SleptRocks";
		case 154: return "SleptIce";
		case 155: return "SleptDirt";
		case 156: return "SleptDriftwood";
		case 157: return "ArtDefacement";
		case 158: return "Evicted";
		case 159: return "GaveBirth";
		case 160: return "SpouseGaveBirth";
		case 161: return "ReceivedWater";
		case 162: return "GaveWater";
		case 163: return "ReceivedFood";
		case 164: return "GaveFood";
		case 165: return "Talked";
		case 166: return "OfficeQuality";
		case 167: return "MeetingInBedroom";
		case 168: return "MeetingInDiningRoom";
		case 169: return "NoRooms";
		case 170: return "TombQuality";
		case 171: return "TombLack";
		case 172: return "TalkToNoble";
		case 173: return "InteractPet";
		case 174: return "ConvictionCorpse";
		case 175: return "ConvictionAnimal";
		case 176: return "ConvictionVictim";
		case 177: return "ConvictionJusticeSelf";
		case 178: return "ConvictionJusticeFamily";
		case 179: return "Decay";
		case 180: return "NeedsUnfulfilled";
		case 181: return "Prayer";
		case 182: return "DrinkWithoutCup";
		case 183: return "ResearchBreakthrough";
		case 184: return "ResearchStalled";
		case 185: return "PonderTopic";
		case 186: return "DiscussTopic";
		case 187: return "Syndrome";
		case 188: return "Perform";
		case 189: return "WatchPerform";
		case 190: return "RemoveTroupe";
		case 191: return "LearnTopic";
		case 192: return "LearnSkill";
		case 193: return "LearnBook";
		case 194: return "LearnInteraction";
		case 195: return "LearnPoetry";
		case 196: return "LearnMusic";
		case 197: return "LearnDance";
		case 198: return "TeachTopic";
		case 199: return "TeachSkill";
		case 200: return "ReadBook";
		case 201: return "WriteBook";
		case 202: return "BecomeResident";
		case 203: return "BecomeCitizen";
		case 204: return "DenyResident";
		case 205: return "DenyCitizen";
		case 206: return "LeaveTroupe";
		case 207: return "MakeBelieve";
		case 208: return "PlayToy";
		case 209: return "DreamAbout";
		case 210: return "Dream";
		case 211: return "Nightmare";
		case 212: return "Argument";
		case 213: return "CombatDrills";
		case 214: return "ArcheryPractice";
		case 215: return "ImproveSkill";
		case 216: return "WearItem";
		case 217: return "RealizeValue";
		case 218: return "OpinionStoryteller";
		case 219: return "OpinionRecitation";
		case 220: return "OpinionInstrumentSimulation";
		case 221: return "OpinionInstrumentPlayer";
		case 222: return "OpinionSinger";
		case 223: return "OpinionChanter";
		case 224: return "OpinionDancer";
		case 225: return "OpinionStory";
		case 226: return "OpinionPoetry";
		case 227: return "OpinionMusic";
		case 228: return "OpinionDance";
		case 229: return "Defeated";
		case 230: return "FavoritePossession";
		case 231: return "PreserveBody";
		case 232: return "Murdered";
		case 233: return "HistEventCollection";
		case 234: return "ViewOwnDisplay";
		case 235: return "ViewDisplay";
		case 236: return "AcquireArtifact";
		case 237: return "DenySanctuary";
		case 238: return "CaughtSneaking";
		case 239: return "GaveArtifact";
		case 240: return "SawDeadBody";
		case 241: return "Expelled";
		case 242: return "RelativeExpelled";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_value_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::value_type::value_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "LAW";
		case 1: return "LOYALTY";
		case 2: return "FAMILY";
		case 3: return "FRIENDSHIP";
		case 4: return "POWER";
		case 5: return "TRUTH";
		case 6: return "CUNNING";
		case 7: return "ELOQUENCE";
		case 8: return "FAIRNESS";
		case 9: return "DECORUM";
		case 10: return "TRADITION";
		case 11: return "ARTWORK";
		case 12: return "COOPERATION";
		case 13: return "INDEPENDENCE";
		case 14: return "STOICISM";
		case 15: return "INTROSPECTION";
		case 16: return "SELF_CONTROL";
		case 17: return "TRANQUILITY";
		case 18: return "HARMONY";
		case 19: return "MERRIMENT";
		case 20: return "CRAFTSMANSHIP";
		case 21: return "MARTIAL_PROWESS";
		case 22: return "SKILL";
		case 23: return "HARD_WORK";
		case 24: return "SACRIFICE";
		case 25: return "COMPETITION";
		case 26: return "PERSEVERENCE";
		case 27: return "LEISURE_TIME";
		case 28: return "COMMERCE";
		case 29: return "ROMANCE";
		case 30: return "NATURE";
		case 31: return "PEACE";
		case 32: return "KNOWLEDGE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_goal_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::goal_type::goal_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "STAY_ALIVE";
		case 1: return "MAINTAIN_ENTITY_STATUS";
		case 2: return "START_A_FAMILY";
		case 3: return "RULE_THE_WORLD";
		case 4: return "CREATE_A_GREAT_WORK_OF_ART";
		case 5: return "CRAFT_A_MASTERWORK";
		case 6: return "BRING_PEACE_TO_THE_WORLD";
		case 7: return "BECOME_A_LEGENDARY_WARRIOR";
		case 8: return "MASTER_A_SKILL";
		case 9: return "FALL_IN_LOVE";
		case 10: return "SEE_THE_GREAT_NATURAL_SITES";
		case 11: return "IMMORTALITY";
		case 12: return "MAKE_A_GREAT_DISCOVERY";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_personality_facet_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::personality_facet_type::personality_facet_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "LOVE_PROPENSITY";
		case 1: return "HATE_PROPENSITY";
		case 2: return "ENVY_PROPENSITY";
		case 3: return "CHEER_PROPENSITY";
		case 4: return "DEPRESSION_PROPENSITY";
		case 5: return "ANGER_PROPENSITY";
		case 6: return "ANXIETY_PROPENSITY";
		case 7: return "LUST_PROPENSITY";
		case 8: return "STRESS_VULNERABILITY";
		case 9: return "GREED";
		case 10: return "IMMODERATION";
		case 11: return "VIOLENT";
		case 12: return "PERSEVERENCE";
		case 13: return "WASTEFULNESS";
		case 14: return "DISCORD";
		case 15: return "FRIENDLINESS";
		case 16: return "POLITENESS";
		case 17: return "DISDAIN_ADVICE";
		case 18: return "BRAVERY";
		case 19: return "CONFIDENCE";
		case 20: return "VANITY";
		case 21: return "AMBITION";
		case 22: return "GRATITUDE";
		case 23: return "IMMODESTY";
		case 24: return "HUMOR";
		case 25: return "VENGEFUL";
		case 26: return "PRIDE";
		case 27: return "CRUELTY";
		case 28: return "SINGLEMINDED";
		case 29: return "HOPEFUL";
		case 30: return "CURIOUS";
		case 31: return "BASHFUL";
		case 32: return "PRIVACY";
		case 33: return "PERFECTIONIST";
		case 34: return "CLOSEMINDED";
		case 35: return "TOLERANT";
		case 36: return "EMOTIONALLY_OBSESSIVE";
		case 37: return "SWAYED_BY_EMOTIONS";
		case 38: return "ALTRUISM";
		case 39: return "DUTIFULNESS";
		case 40: return "THOUGHTLESSNESS";
		case 41: return "ORDERLINESS";
		case 42: return "TRUST";
		case 43: return "GREGARIOUSNESS";
		case 44: return "ASSERTIVENESS";
		case 45: return "ACTIVITY_LEVEL";
		case 46: return "EXCITEMENT_SEEKING";
		case 47: return "IMAGINATION";
		case 48: return "ABSTRACT_INCLINED";
		case 49: return "ART_INCLINED";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_physical_attribute_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::physical_attribute_type::physical_attribute_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "STRENGTH";
		case 1: return "AGILITY";
		case 2: return "TOUGHNESS";
		case 3: return "ENDURANCE";
		case 4: return "RECUPERATION";
		case 5: return "DISEASE_RESISTANCE";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_mental_attribute_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::mental_attribute_type::mental_attribute_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "ANALYTICAL_ABILITY";
		case 1: return "FOCUS";
		case 2: return "WILLPOWER";
		case 3: return "CREATIVITY";
		case 4: return "INTUITION";
		case 5: return "PATIENCE";
		case 6: return "MEMORY";
		case 7: return "LINGUISTIC_ABILITY";
		case 8: return "SPATIAL_SENSE";
		case 9: return "MUSICALITY";
		case 10: return "KINESTHETIC_SENSE";
		case 11: return "EMPATHY";
		case 12: return "SOCIAL_AWARENESS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_mood_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::mood_type::mood_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Fey";
		case 1: return "Secretive";
		case 2: return "Possessed";
		case 3: return "Macabre";
		case 4: return "Fell";
		case 5: return "Melancholy";
		case 6: return "Raving";
		case 7: return "Berserk";
		case 8: return "Baby";
		case 9: return "Traumatized";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ghost_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::ghost_type::ghost_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MurderousGhost";
		case 1: return "SadisticGhost";
		case 2: return "SecretivePoltergeist";
		case 3: return "EnergeticPoltergeist";
		case 4: return "AngryGhost";
		case 5: return "ViolentGhost";
		case 6: return "MoaningSpirit";
		case 7: return "HowlingSpirit";
		case 8: return "TroublesomePoltergeist";
		case 9: return "RestlessHaunt";
		case 10: return "ForlornHaunt";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_animal_training_level_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::animal_training_level::animal_training_level*>(p_address);
	switch (*m_value)
	{
		case 0: return "SemiWild";
		case 1: return "Trained";
		case 2: return "WellTrained";
		case 3: return "SkilfullyTrained";
		case 4: return "ExpertlyTrained";
		case 5: return "ExceptionallyTrained";
		case 6: return "MasterfullyTrained";
		case 7: return "Domesticated";
		case 8: return "Unk8";
		case 9: return "WildUntamed";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_report_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::unit_report_type::unit_report_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Combat";
		case 1: return "Sparring";
		case 2: return "Hunting";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_skill_rating_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::skill_rating::skill_rating*>(p_address);
	switch (*m_value)
	{
		case 0: return "Dabbling";
		case 1: return "Novice";
		case 2: return "Adequate";
		case 3: return "Competent";
		case 4: return "Skilled";
		case 5: return "Proficient";
		case 6: return "Talented";
		case 7: return "Adept";
		case 8: return "Expert";
		case 9: return "Professional";
		case 10: return "Accomplished";
		case 11: return "Great";
		case 12: return "Master";
		case 13: return "HighMaster";
		case 14: return "GrandMaster";
		case 15: return "Legendary";
		case 16: return "Legendary1";
		case 17: return "Legendary2";
		case 18: return "Legendary3";
		case 19: return "Legendary4";
		case 20: return "Legendary5";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_relationship_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::unit_relationship_type::unit_relationship_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Pet";
		case 1: return "Spouse";
		case 2: return "Mother";
		case 3: return "Father";
		case 4: return "LastAttacker";
		case 5: return "GroupLeader";
		case 6: return "Draggee";
		case 7: return "Dragger";
		case 8: return "RiderMount";
		case 9: return "Lover";
		case 10: return "unk10";
		case 11: return "Sibling";
		case 12: return "Child";
		case 13: return "Friend";
		case 14: return "Grudge";
		case 15: return "Worship";
		case 16: return "AcquaintanceLong";
		case 17: return "AcquaintancePassing";
		case 18: return "Bonded";
		case 19: return "Hero";
		case 20: return "ConsidersViolent";
		case 21: return "ConsidersPsychotic";
		case 22: return "GoodForBusiness";
		case 23: return "FriendlyTerms";
		case 24: return "ConsidersKiller";
		case 25: return "ConsidersMurderer";
		case 26: return "Comrade";
		case 27: return "MemberOfRespectedGroup";
		case 28: return "MemberOfHatedGroup";
		case 29: return "EnemyFighter";
		case 30: return "FriendlyFighter";
		case 31: return "ConsidersBully";
		case 32: return "ConsidersBrigand";
		case 33: return "LoyalSoldier";
		case 34: return "ConsidersMonster";
		case 35: return "ConsidersStoryteller";
		case 36: return "ConsidersPoet";
		case 37: return "ConsidersBard";
		case 38: return "ConsidersDancer";
		case 39: return "Master";
		case 40: return "Apprentice";
		case 41: return "Companion";
		case 42: return "FormerMaster";
		case 43: return "FormerApprentice";
		case 44: return "ConsidersQuarreler";
		case 45: return "ConsidersFlatterer";
		case 46: return "Hunter";
		case 47: return "ProtectorOfTheWeak";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_need_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::need_type::need_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Socialize";
		case 1: return "DrinkAlcohol";
		case 2: return "PrayOrMedidate";
		case 3: return "StayOccupied";
		case 4: return "BeCreative";
		case 5: return "Excitement";
		case 6: return "LearnSomething";
		case 7: return "BeWithFamily";
		case 8: return "BeWithFriends";
		case 9: return "HearEloquence";
		case 10: return "UpholdTradition";
		case 11: return "SelfExamination";
		case 12: return "MakeMerry";
		case 13: return "CraftObject";
		case 14: return "MartialTraining";
		case 15: return "PracticeSkill";
		case 16: return "TakeItEasy";
		case 17: return "MakeRomance";
		case 18: return "SeeAnimal";
		case 19: return "SeeGreatBeast";
		case 20: return "AcquireObject";
		case 21: return "EatGoodMeal";
		case 22: return "Fight";
		case 23: return "CauseTrouble";
		case 24: return "Argue";
		case 25: return "BeExtravagant";
		case 26: return "Wander";
		case 27: return "HelpSomebody";
		case 28: return "ThinkAbstractly";
		case 29: return "AdmireArt";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ghost_goal_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::ghost_goal::ghost_goal*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "ScareToDeath";
		case 1: return "Stun";
		case 2: return "Batter";
		case 3: return "Possess";
		case 4: return "MisplaceItem";
		case 5: return "Haunt";
		case 6: return "Torment";
		case 7: return "ToppleBuilding";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_wound_effect_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::wound_effect_type::wound_effect_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Bruise";
		case 1: return "Burn";
		case 2: return "Frostbite";
		case 3: return "Burn2";
		case 4: return "Melting";
		case 5: return "Boiling";
		case 6: return "Freezing";
		case 7: return "Condensation";
		case 8: return "Necrosis";
		case 9: return "Blister";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_misc_trait_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::misc_trait_type::misc_trait_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "RequestWaterCooldown";
		case 1: return "RequestFoodCooldown";
		case 2: return "RequestRescueCooldown";
		case 3: return "RequestHealthcareCooldown";
		case 4: return "GetDrinkCooldown";
		case 5: return "GetFoodCooldown";
		case 6: return "CleanSelfCooldown";
		case 7: return "Migrant";
		case 8: return "RoomComplaint";
		case 9: return "UnnamedResident";
		case 10: return "RentBedroomCooldown";
		case 11: return "ClaimTrinketCooldown";
		case 12: return "ClaimClothingCooldown";
		case 13: return "WantsDrink";
		case 14: return "anon_1";
		case 15: return "anon_2";
		case 16: return "anon_3";
		case 17: return "anon_4";
		case 18: return "PrepareToDie";
		case 19: return "CaveAdapt";
		case 20: return "anon_5";
		case 21: return "anon_6";
		case 22: return "anon_7";
		case 23: return "anon_8";
		case 24: return "FollowUnitCooldown";
		case 25: return "anon_9";
		case 26: return "anon_10";
		case 27: return "anon_11";
		case 28: return "DangerousTerrainCooldown";
		case 29: return "Beaching";
		case 30: return "IdleAreaCooldown";
		case 31: return "anon_12";
		case 32: return "PartiedOut";
		case 33: return "DiagnosePatientCooldown";
		case 34: return "DressWoundCooldown";
		case 35: return "CleanPatientCooldown";
		case 36: return "SurgeryCooldown";
		case 37: return "SutureCooldown";
		case 38: return "SetBoneCooldown";
		case 39: return "PlaceInTractionCooldown";
		case 40: return "ApplyCastCooldown";
		case 41: return "ImmobilizeBreakCooldown";
		case 42: return "BringCrutchCooldown";
		case 43: return "anon_13";
		case 44: return "MilkCounter";
		case 45: return "HadDrill";
		case 46: return "CompletedDrill";
		case 47: return "EggSpent";
		case 48: return "GroundedAnimalAnger";
		case 49: return "anon_14";
		case 50: return "TimeSinceSuckedBlood";
		case 51: return "DrinkingBlood";
		case 52: return "anon_15";
		case 53: return "anon_16";
		case 54: return "RevertWildTimer";
		case 55: return "anon_17";
		case 56: return "NoPantsAnger";
		case 57: return "NoShirtAnger";
		case 58: return "NoShoesAnger";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_action_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::unit_action_type::unit_action_type*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Move";
		case 1: return "Attack";
		case 2: return "Jump";
		case 3: return "HoldTerrain";
		case 4: return "ReleaseTerrain";
		case 5: return "Climb";
		case 6: return "Job";
		case 7: return "Talk";
		case 8: return "Unsteady";
		case 9: return "Parry";
		case 10: return "Block";
		case 11: return "Dodge";
		case 12: return "Recover";
		case 13: return "StandUp";
		case 14: return "LieDown";
		case 15: return "Job2";
		case 16: return "PushObject";
		case 17: return "SuckBlood";
		case 18: return "HoldItem";
		case 19: return "ReleaseItem";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interface_breakdown_types_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::interface_breakdown_types::interface_breakdown_types*>(p_address);
	switch (*m_value)
	{
		case 0: return "NONE";
		case 1: return "QUIT";
		case 2: return "STOPSCREEN";
		case 3: return "TOFIRST";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_embark_finder_option_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::embark_finder_option::embark_finder_option*>(p_address);
	switch (*m_value)
	{
		case 0: return "DimensionX";
		case 1: return "DimensionY";
		case 2: return "Savagery";
		case 3: return "Evil";
		case 4: return "Elevation";
		case 5: return "Temperature";
		case 6: return "Rain";
		case 7: return "Drainage";
		case 8: return "FluxStone";
		case 9: return "Aquifer";
		case 10: return "River";
		case 11: return "UndergroundRiver";
		case 12: return "UndergroundPool";
		case 13: return "MagmaPool";
		case 14: return "MagmaPipe";
		case 15: return "Chasm";
		case 16: return "BottomlessPit";
		case 17: return "OtherFeatures";
		case 18: return "ShallowMetal";
		case 19: return "DeepMetal";
		case 20: return "Soil";
		case 21: return "Clay";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_image_creator_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::viewscreen_image_creator_mode::viewscreen_image_creator_mode*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "ArtistToChoose";
		case 1: return "Histfig";
		case 2: return "Site";
		case 3: return "Entity";
		case 4: return "HistoryEvent";
		case 5: return "ExistingImage";
		case 6: return "NewImage";
		case 7: return "AddCreature";
		case 8: return "AddHistfig";
		case 9: return "AddPlant";
		case 10: return "AddTree";
		case 11: return "AddShape";
		case 12: return "AddObject";
		case 13: return "AddArtifact";
		case 14: return "AddRelationship";
		case 15: return "ChooseRelationshipX";
		case 16: return "ChooseRelationshipY";
		case 17: return "EnterNumber";
		case 18: return "DeleteElement";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_kitchenpref_page_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::viewscreen_kitchenpref_page::viewscreen_kitchenpref_page*>(p_address);
	switch (*m_value)
	{
		case 0: return "VegetablesFruitLeaves";
		case 1: return "Seeds";
		case 2: return "Drinks";
		case 3: return "MeatFishOther";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_adventurer_attribute_level_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::adventurer_attribute_level::adventurer_attribute_level*>(p_address);
	switch (*m_value)
	{
		case 0: return "VeryLow";
		case 1: return "Low";
		case 2: return "BelowAverage";
		case 3: return "Average";
		case 4: return "AboveAverage";
		case 5: return "High";
		case 6: return "Superior";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_unitlist_page_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::viewscreen_unitlist_page::viewscreen_unitlist_page*>(p_address);
	switch (*m_value)
	{
		case 0: return "Citizens";
		case 1: return "Livestock";
		case 2: return "Others";
		case 3: return "Dead";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_world_population_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::world_population_type::world_population_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Animal";
		case 1: return "Vermin";
		case 2: return "Unk2";
		case 3: return "VerminInnumerable";
		case 4: return "ColonyInsect";
		case 5: return "Tree";
		case 6: return "Grass";
		case 7: return "Bush";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_world_region_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::world_region_type::world_region_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Swamp";
		case 1: return "Desert";
		case 2: return "Jungle";
		case 3: return "Mountains";
		case 4: return "Ocean";
		case 5: return "Lake";
		case 6: return "Glacier";
		case 7: return "Tundra";
		case 8: return "Steppe";
		case 9: return "Hills";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_geo_layer_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::geo_layer_type::geo_layer_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "SOIL";
		case 1: return "SEDIMENTARY";
		case 2: return "METAMORPHIC";
		case 3: return "IGNEOUS_EXTRUSIVE";
		case 4: return "IGNEOUS_INTRUSIVE";
		case 5: return "SOIL_OCEAN";
		case 6: return "SOIL_SAND";
		case 7: return "SEDIMENTARY_OCEAN_SHALLOW";
		case 8: return "SEDIMENTARY_OCEAN_DEEP";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_region_map_entry_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::region_map_entry_flags::region_map_entry_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "has_river";
		case 1: return "tile_variant";
		case 2: return "anon_1";
		case 3: return "has_site";
		case 4: return "anon_2";
		case 5: return "river_up";
		case 6: return "river_down";
		case 7: return "river_right";
		case 8: return "river_left";
		case 9: return "discovered";
		case 10: return "anon_3";
		case 11: return "anon_4";
		case 12: return "anon_5";
		case 13: return "is_peak";
		case 14: return "is_lake";
		case 15: return "is_brook";
		case 16: return "has_road";
		case 17: return "anon_6";
		case 18: return "anon_7";
		case 19: return "anon_8";
		case 20: return "anon_9";
		case 21: return "anon_10";
		case 22: return "anon_11";
		case 23: return "anon_12";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_front_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::front_type::front_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "front_none";
		case 1: return "front_warm";
		case 2: return "front_cold";
		case 3: return "front_occluded";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_cumulus_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::cumulus_type::cumulus_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "cumulus_none";
		case 1: return "cumulus_medium";
		case 2: return "cumulus_multi";
		case 3: return "cumulus_nimbus";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_stratus_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::stratus_type::stratus_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "stratus_none";
		case 1: return "stratus_alto";
		case 2: return "stratus_proper";
		case 3: return "stratus_nimbus";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_fog_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::fog_type::fog_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "fog_none";
		case 1: return "fog_mist";
		case 2: return "fog_normal";
		case 3: return "fog_thick";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_mountain_peak_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::mountain_peak_flags::mountain_peak_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "is_volcano";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_abstract_building_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::abstract_building_type::abstract_building_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "MEAD_HALL";
		case 1: return "KEEP";
		case 2: return "TEMPLE";
		case 3: return "DARK_TOWER";
		case 4: return "MARKET";
		case 5: return "TOMB";
		case 6: return "DUNGEON";
		case 7: return "UNDERWORLD_SPIRE";
		case 8: return "INN_TAVERN";
		case 9: return "LIBRARY";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_abstract_building_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::abstract_building_flags::abstract_building_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "Unk0";
		case 1: return "Unk1";
		case 2: return "Unk2";
		case 3: return "Unk3";
		case 4: return "AllowVisitors";
		case 5: return "AllowResidents";
		case 6: return "Unk6";
		case 7: return "Unk7";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_world_site_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::world_site_type::world_site_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "PlayerFortress";
		case 1: return "DarkFortress";
		case 2: return "Cave";
		case 3: return "MountainHalls";
		case 4: return "ForestRetreat";
		case 5: return "Town";
		case 6: return "ImportantLocation";
		case 7: return "LairShrine";
		case 8: return "Fortress";
		case 9: return "Camp";
		case 10: return "Monument";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_world_site_flags_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::world_site_flags::world_site_flags*>(p_address);
	switch (*m_value)
	{
		case 0: return "Undiscovered";
		case 1: return "anon_1";
		case 2: return "anon_2";
		case 3: return "Town";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_site_realization_building_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::site_realization_building_type::site_realization_building_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "cottage_plot";
		case 1: return "castle_wall";
		case 2: return "castle_tower";
		case 3: return "castle_courtyard";
		case 4: return "house";
		case 5: return "temple";
		case 6: return "tomb";
		case 7: return "shop_house";
		case 8: return "warehouse";
		case 9: return "market_square";
		case 10: return "pasture";
		case 11: return "waste";
		case 12: return "courtyard";
		case 13: return "well";
		case 14: return "vault";
		case 15: return "great_tower";
		case 16: return "trenches";
		case 17: return "tree_house";
		case 18: return "hillock_house";
		case 19: return "mead_hall";
		case 20: return "fortress_entrance";
		case 21: return "library";
		case 22: return "tavern";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_site_shop_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::site_shop_type::site_shop_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "GeneralImports";
		case 1: return "FoodImports";
		case 2: return "ClothingImports";
		case 3: return "Cloth";
		case 4: return "Leather";
		case 5: return "WovenClothing";
		case 6: return "LeatherClothing";
		case 7: return "BoneCarver";
		case 8: return "GemCutter";
		case 9: return "Weaponsmith";
		case 10: return "Bowyer";
		case 11: return "Blacksmith";
		case 12: return "Armorsmith";
		case 13: return "MetalCraft";
		case 14: return "LeatherGoods";
		case 15: return "Carpenter";
		case 16: return "StoneFurniture";
		case 17: return "MetalFurniture";
		case 18: return "ImportedGoodsMarket";
		case 19: return "ImportedFoodMarket";
		case 20: return "ImportedClothingMarket";
		case 21: return "MeatMarket";
		case 22: return "FruitAndVegetableMarket";
		case 23: return "CheeseMarket";
		case 24: return "ProcessedGoodsMarket";
		case 25: return "Tavern";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_tree_house_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::tree_house_type::tree_house_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "TreeHouse";
		case 1: return "HomeTree";
		case 2: return "ShapingTree";
		case 3: return "MarketTree";
		case 4: return "Unknown1";
		case 5: return "Unknown2";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_hillock_house_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::hillock_house_type::hillock_house_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "anon_1";
		case 1: return "CivicMound";
		case 2: return "CastleMound";
		case 3: return "DrinkingMound";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_creation_zone_pwg_alteration_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::creation_zone_pwg_alteration_type::creation_zone_pwg_alteration_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "location_death";
		case 1: return "camp";
		case 2: return "srb_ruined";
		case 3: return "srp_ruined";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_worldgen_region_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::worldgen_region_type::worldgen_region_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "SWAMP";
		case 1: return "DESERT";
		case 2: return "FOREST";
		case 3: return "MOUNTAINS";
		case 4: return "OCEAN";
		case 5: return "LAKE";
		case 6: return "GLACIER";
		case 7: return "TUNDRA";
		case 8: return "GRASSLAND";
		case 9: return "HILLS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_worldgen_range_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::worldgen_range_type::worldgen_range_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "ELEVATION";
		case 1: return "RAINFALL";
		case 2: return "anon_1";
		case 3: return "TEMPERATURE";
		case 4: return "anon_2";
		case 5: return "DRAINAGE";
		case 6: return "VOLCANISM";
		case 7: return "SAVAGERY";
		case 8: return "anon_3";
		case 9: return "anon_4";
		case 10: return "anon_5";
		case 11: return "anon_6";
		case 12: return "anon_7";
		case 13: return "anon_8";
		case 14: return "anon_9";
		case 15: return "anon_10";
		case 16: return "anon_11";
		case 17: return "anon_12";
		case 18: return "anon_13";
		case 19: return "anon_14";
		case 20: return "anon_15";
		case 21: return "anon_16";
		case 22: return "anon_17";
		case 23: return "anon_18";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_units_other_id_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::units_other_id::units_other_id*>(p_address);
	switch (*m_value)
	{
		case 0: return "ANY_RIDER";
		case 1: return "ANY_BABY2";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_conflict_level_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::conflict_level::conflict_level*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "Encounter";
		case 1: return "Horseplay";
		case 2: return "Training";
		case 3: return "Brawl";
		case 4: return "Nonlethal";
		case 5: return "Lethal";
		case 6: return "NoQuarter";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_combat_report_event_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::enums::combat_report_event_type::combat_report_event_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "anon_1";
		case 1: return "Deflected";
		case 2: return "anon_2";
		case 3: return "anon_3";
		case 4: return "anon_4";
		case 5: return "anon_5";
		case 6: return "Unconscious";
		case 7: return "Stunned";
		case 8: return "MoreStunned";
		case 9: return "Winded";
		case 10: return "MoreWinded";
		case 11: return "Nausea";
		case 12: return "MoreNausea";
		case 13: return "anon_6";
		case 14: return "anon_7";
		case 15: return "ExtractInjected";
		case 16: return "ExtractSprayed";
		case 17: return "BloodSucked";
		case 18: return "SeveredPart";
		case 19: return "anon_8";
		case 20: return "KnockedBack";
		case 21: return "StuckIn";
		case 22: return "LatchOnPart";
		case 23: return "LatchOn";
		case 24: return "Enraged";
		case 25: return "PassThrough";
		case 26: return "GlancesAway";
		case 27: return "anon_9";
		case 28: return "anon_10";
		case 29: return "MajorArtery";
		case 30: return "Artery";
		case 31: return "MotorNerve";
		case 32: return "SensoryNerve";
		case 33: return "NoForce";
		case 34: return "Interrupted";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_conversation__T_state_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::conversation::T_state*>(p_address);
	switch (*m_value)
	{
		case 0: return "started";
		case 1: return "active";
		case 2: return "finished";
		case 3: return "quit";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_building_archerytargetst__T_archery_direction_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::building_archerytargetst::T_archery_direction*>(p_address);
	switch (*m_value)
	{
		case 0: return "TopToBottom";
		case 1: return "BottomToTop";
		case 2: return "LeftToRight";
		case 3: return "RightToLeft";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_building_bridgest__T_direction_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::building_bridgest::T_direction*>(p_address);
	switch (*m_value)
	{
		case -1: return "Retracting";
		case 0: return "Left";
		case 1: return "Right";
		case 2: return "Up";
		case 3: return "Down";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_building_siegeenginest__T_facing_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::building_siegeenginest::T_facing*>(p_address);
	switch (*m_value)
	{
		case 0: return "Left";
		case 1: return "Up";
		case 2: return "Right";
		case 3: return "Down";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_building_siegeenginest__T_action_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::building_siegeenginest::T_action*>(p_address);
	switch (*m_value)
	{
		case 0: return "NotInUse";
		case 1: return "PrepareToFire";
		case 2: return "FireAtWill";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_caste_body_info__T_interactions__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::caste_body_info::T_interactions::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "RETRACT_INTO_BP";
		case 1: return "CAN_DO_INTERACTION";
		case 2: return "ROOT_AROUND";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_caravan_state__T_trade_state_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::caravan_state::T_trade_state*>(p_address);
	switch (*m_value)
	{
		case 0: return "None";
		case 1: return "Approaching";
		case 2: return "AtDepot";
		case 3: return "Leaving";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_entity_event__T_data__T_insurrection_end__T_result_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::entity_event::T_data::T_insurrection_end::T_result*>(p_address);
	switch (*m_value)
	{
		case 0: return "Overthrow";
		case 1: return "Failure";
		case 2: return "Crushing";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_change_hf_statest__T_state_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::history_event_change_hf_statest::T_state*>(p_address);
	switch (*m_value)
	{
		case 0: return "Wandering";
		case 1: return "Settled";
		case 2: return "Refugee";
		case 3: return "anon_1";
		case 4: return "anon_2";
		case 5: return "Visiting";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_body_abusedst__T_props__T_pile_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::history_event_body_abusedst::T_props::T_pile_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "GrislyMound";
		case 1: return "GrotesquePillar";
		case 2: return "GruesomeSculpture";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_body_abusedst__T_abuse_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::history_event_body_abusedst::T_abuse_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Impaled";
		case 1: return "Piled";
		case 2: return "Flayed";
		case 3: return "Hung";
		case 4: return "Mutilated";
		case 5: return "Animated";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_hist_figure_travelst__T_reason_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::history_event_hist_figure_travelst::T_reason*>(p_address);
	switch (*m_value)
	{
		case 0: return "Journey";
		case 1: return "Return";
		case 2: return "Escape";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_history_event_artifact_claim_formedst__T_claim_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::history_event_artifact_claim_formedst::T_claim_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Symbol";
		case 1: return "Heirloom";
		case 2: return "Treasure";
		case 3: return "HolyRelic";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_init_display__T_windowed_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::init_display::T_windowed*>(p_address);
	switch (*m_value)
	{
		case 0: return "True";
		case 1: return "False";
		case 2: return "Prompt";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_init_font__T_use_ttf_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::init_font::T_use_ttf*>(p_address);
	switch (*m_value)
	{
		case 0: return "TTF_OFF";
		case 1: return "TTF_ON";
		case 2: return "TTF_AUTO";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_job_item_ref__T_role_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::job_item_ref::T_role*>(p_address);
	switch (*m_value)
	{
		case 0: return "anon_1";
		case 1: return "Reagent";
		case 2: return "Hauled";
		case 3: return "LinkToTarget";
		case 4: return "LinkToTrigger";
		case 5: return "anon_2";
		case 6: return "TargetContainer";
		case 7: return "QueuedContainer";
		case 8: return "PushHaulVehicle";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_manager_order__T_frequency_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::manager_order::T_frequency*>(p_address);
	switch (*m_value)
	{
		case 0: return "OneTime";
		case 1: return "Daily";
		case 2: return "Monthly";
		case 3: return "Seasonally";
		case 4: return "Yearly";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_manager_order_condition_item__T_compare_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::manager_order_condition_item::T_compare_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "AtLeast";
		case 1: return "AtMost";
		case 2: return "GreaterThan";
		case 3: return "LessThan";
		case 4: return "Exactly";
		case 5: return "Not";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_mandate__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::mandate::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Export";
		case 1: return "Make";
		case 2: return "Guild";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_demand__T_place_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::unit_demand::T_place*>(p_address);
	switch (*m_value)
	{
		case 0: return "Office";
		case 1: return "Bedroom";
		case 2: return "DiningRoom";
		case 3: return "Tomb";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_advmode__T_conversation__T_targets__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_advmode::T_conversation::T_targets::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Talk";
		case 1: return "anon_1";
		case 2: return "anon_2";
		case 3: return "Shout";
		case 4: return "Perform";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_advmode__T_travel_right_map_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_advmode::T_travel_right_map*>(p_address);
	switch (*m_value)
	{
		case 0: return "MapNone";
		case 1: return "MapSite";
		case 2: return "MapWorld";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_advmode__T_show_menu_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_advmode::T_show_menu*>(p_address);
	switch (*m_value)
	{
		case -1: return "TwoBlankRows";
		case 0: return "Hidden";
		case 1: return "TwoRowsWithKeybindingHints";
		case 2: return "TwoRows";
		case 3: return "OneRow";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_stop_depart_condition__T_direction_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::stop_depart_condition::T_direction*>(p_address);
	switch (*m_value)
	{
		case 0: return "North";
		case 1: return "South";
		case 2: return "East";
		case 3: return "West";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_stop_depart_condition__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::stop_depart_condition::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Push";
		case 1: return "Ride";
		case 2: return "Guide";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_interface_button_construction_category_selectorst__T_category_id_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::interface_button_construction_category_selectorst::T_category_id*>(p_address);
	switch (*m_value)
	{
		case 1: return "SiegeEngines";
		case 2: return "Traps";
		case 3: return "Workshops";
		case 4: return "Furnaces";
		case 5: return "Constructions";
		case 6: return "MachineComponents";
		case 7: return "Track";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_sidebar_menus__T_designation__T_mine_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_sidebar_menus::T_designation::T_mine_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "All";
		case 1: return "AutoMine";
		case 2: return "Economic";
		case 3: return "Gems";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_sidebar_menus__T_zone__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_sidebar_menus::T_zone::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Rectangle";
		case 1: return "Flow";
		case 2: return "FloorFlow";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_sidebar_menus__T_unit__T_expel_error_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_sidebar_menus::T_unit::T_expel_error*>(p_address);
	switch (*m_value)
	{
		case -1: return "NONE";
		case 0: return "NOBILITY";
		case 1: return "HOLDS_OFFICE";
		case 2: return "DOES_EXPELLING";
		case 3: return "SPOUSE_IS_NOT_PRESENT";
		case 4: return "SPOUSE_IS_NOBILITY";
		case 5: return "SPOUSE_IS_ELECTED";
		case 6: return "SPOUSE_DOES_EXPELLING";
		case 7: return "CHILD_IS_NOT_PRESENT";
		case 8: return "CHILD_IS_NOBILITY";
		case 9: return "CHILD_IS_ELECTED";
		case 10: return "CHILD_DOES_EXPELLING";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_look_list__T_items__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_look_list::T_items::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Item";
		case 1: return "Floor";
		case 2: return "Unit";
		case 3: return "Building";
		case 4: return "Vermin";
		case 5: return "Flow";
		case 6: return "Campfire";
		case 7: return "Spatter";
		case 8: return "BuildingItem";
		case 9: return "Fire";
		case 10: return "Water";
		case 11: return "Magma";
		case 12: return "Spoor";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_ui_unit_view_mode__T_value_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::ui_unit_view_mode::T_value*>(p_address);
	switch (*m_value)
	{
		case 0: return "General";
		case 1: return "Inventory";
		case 2: return "Preferences";
		case 3: return "Wounds";
		case 4: return "PrefLabor";
		case 5: return "PrefDogs";
		case 6: return "PrefOccupation";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit__T_meeting__T_state_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::unit::T_meeting::T_state*>(p_address);
	switch (*m_value)
	{
		case 0: return "SelectNoble";
		case 1: return "FollowNoble";
		case 2: return "DoMeeting";
		case 3: return "LeaveMap";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit__T_counters__T_soldier_mood_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::unit::T_counters::T_soldier_mood*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "MartialTrance";
		case 1: return "Enraged";
		case 2: return "Tantrum";
		case 3: return "Depressed";
		case 4: return "Oblivious";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_inventory_item__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::unit_inventory_item::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Hauled";
		case 1: return "Weapon";
		case 2: return "Worn";
		case 3: return "Piercing";
		case 4: return "Flask";
		case 5: return "WrappedAround";
		case 6: return "StuckIn";
		case 7: return "InMouth";
		case 8: return "Pet";
		case 9: return "SewnInto";
		case 10: return "Strapped";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_preference__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::unit_preference::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "LikeMaterial";
		case 1: return "LikeCreature";
		case 2: return "LikeFood";
		case 3: return "HateCreature";
		case 4: return "LikeItem";
		case 5: return "LikePlant";
		case 6: return "LikeTree";
		case 7: return "LikeColor";
		case 8: return "LikeShape";
		case 9: return "LikePoeticForm";
		case 10: return "LikeMusicalForm";
		case 11: return "LikeDanceForm";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_complaint__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::unit_complaint::T_type*>(p_address);
	switch (*m_value)
	{
		case 25: return "SelfUnemployed";
		case 26: return "GuildUnemployed";
		case 27: return "NeedWeapons";
		case 28: return "IsAngry";
		case 29: return "IsSad";
		case 30: return "anon_1";
		case 31: return "anon_2";
		case 32: return "anon_3";
		case 33: return "anon_4";
		case 34: return "anon_5";
		case 35: return "anon_6";
		case 36: return "anon_7";
		case 37: return "anon_8";
		case 38: return "anon_9";
		case 39: return "anon_10";
		case 40: return "anon_11";
		case 41: return "anon_12";
		case 42: return "anon_13";
		case 43: return "anon_14";
		case 44: return "anon_15";
		case 45: return "anon_16";
		case 46: return "anon_17";
		case 47: return "anon_18";
		case 48: return "Petition";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_unit_request__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::unit_request::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "DoGuildJobs";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_KeybindingScreen__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::KeybindingScreen::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Main";
		case 1: return "KeyL";
		case 2: return "KeyR";
		case 3: return "Macro";
		case 4: return "Register";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_adventure_logst__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_adventure_logst::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Info";
		case 1: return "Map";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_adventure_logst__T_info_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_adventure_logst::T_info_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Events";
		case 1: return "Agreements";
		case 2: return "People";
		case 3: return "Sites";
		case 4: return "Groups";
		case 5: return "Regions";
		case 6: return "Bestiary";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_assign_display_itemst__T_sel_column_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_assign_display_itemst::T_sel_column*>(p_address);
	switch (*m_value)
	{
		case 0: return "ItemTypes";
		case 1: return "Items";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_choose_start_sitest__T_page_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_choose_start_sitest::T_page*>(p_address);
	switch (*m_value)
	{
		case 0: return "Biome";
		case 1: return "Neighbors";
		case 2: return "Civilization";
		case 3: return "Elevation";
		case 4: return "Cliffs";
		case 5: return "Reclaim";
		case 6: return "Reclaim2";
		case 7: return "Find";
		case 8: return "Notes";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_mission__T_details__T_raid__T_raid_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::mission::T_details::T_raid::T_raid_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Raze";
		case 1: return "TakeOver";
		case 2: return "Occupy";
		case 3: return "DemandTribute";
		case 4: return "Raid";
		case 5: return "Explore";
		case 6: return "Pillage";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_mission__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::mission::T_type*>(p_address);
	switch (*m_value)
	{
		case 2: return "Raid";
		case 17: return "RecoverArtifact";
		case 18: return "RescuePerson";
		case 19: return "RequestWorkers";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_civlistst__T_rumors__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_civlistst::T_rumors::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "ArmyMarched";
		case 1: return "Kidnapped";
		case 3: return "Unknown3";
		case 7: return "RefugeesFled";
		case 8: return "MovedOn";
		case 9: return "Reclaimed";
		case 10: return "Founded";
		case 13: return "GaveUpOccupation";
		case 16: return "BecameRuler";
		case 17: return "Claimed";
		case 25: return "ArtifactLocation";
		case 28: return "Unknown28";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_civlistst__T_page_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_civlistst::T_page*>(p_address);
	switch (*m_value)
	{
		case 0: return "Civilizations";
		case 1: return "News";
		case 2: return "World";
		case 3: return "Missions";
		case 4: return "MissionSquads";
		case 5: return "MissionMessengers";
		case 6: return "MissionDetails";
		case 7: return "People";
		case 8: return "Artifacts";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_game_cleanerst__T_state_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_game_cleanerst::T_state*>(p_address);
	switch (*m_value)
	{
		case 0: return "CleaningGameObjects";
		case 1: return "CleaningStrandedObjects";
		case 2: return "CleaningPlayObjects";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_justicest__T_cur_column_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_justicest::T_cur_column*>(p_address);
	switch (*m_value)
	{
		case 0: return "Crimes";
		case 1: return "Suspects";
		case 2: return "ConvictChoices";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_assign_trade_status__T_status_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::assign_trade_status::T_status*>(p_address);
	switch (*m_value)
	{
		case -2: return "RemoveTrading";
		case -1: return "RemovePending";
		case 0: return "None";
		case 1: return "AddPending";
		case 2: return "Pending";
		case 3: return "Trading";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_layer_choose_language_namest__T_current_component_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_layer_choose_language_namest::T_current_component*>(p_address);
	switch (*m_value)
	{
		case 0: return "FrontCompound";
		case 1: return "RearCompound";
		case 2: return "FirstAdjective";
		case 3: return "SecondAdjective";
		case 4: return "HyphenCompound";
		case 5: return "TheX";
		case 6: return "OfX";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_layer_militaryst__T_equip__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_layer_militaryst::T_equip::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Customize";
		case 1: return "Uniform";
		case 2: return "Priority";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_layer_militaryst__T_equip__T_edit_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_layer_militaryst::T_equip::T_edit_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Armor";
		case 1: return "Helm";
		case 2: return "Legs";
		case 3: return "Gloves";
		case 4: return "Boots";
		case 5: return "Shield";
		case 6: return "Weapon";
		case 7: return "Material";
		case 8: return "Color";
		case 9: return "SpecificArmor";
		case 10: return "SpecificHelm";
		case 11: return "SpecificLegs";
		case 12: return "SpecificGloves";
		case 13: return "SpecificBoots";
		case 14: return "SpecificShield";
		case 15: return "SpecificWeapon";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_layer_militaryst__T_page_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_layer_militaryst::T_page*>(p_address);
	switch (*m_value)
	{
		case 0: return "Positions";
		case 1: return "Alerts";
		case 2: return "Equip";
		case 3: return "Uniforms";
		case 4: return "Supplies";
		case 5: return "Ammunition";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_layer_noblelistst__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_layer_noblelistst::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "List";
		case 1: return "Appoint";
		case 2: return "Settings";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_legendsst__T_cur_page_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_legendsst::T_cur_page*>(p_address);
	switch (*m_value)
	{
		case 0: return "Main";
		case 1: return "HistoricalFigures";
		case 2: return "Sites";
		case 3: return "Artifacts";
		case 4: return "Regions";
		case 5: return "Civilizations";
		case 6: return "Art";
		case 7: return "Structures";
		case 8: return "Age";
		case 9: return "HistoricalMaps";
		case 10: return "UndergroundRegions";
		case 11: return "Populations";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_locationsst__T_in_edit_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_locationsst::T_in_edit*>(p_address);
	switch (*m_value)
	{
		case 0: return "None";
		case 1: return "Goblets";
		case 2: return "Instruments";
		case 3: return "WritingCopies";
		case 4: return "WritingMaterial";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_locationsst__T_menu_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_locationsst::T_menu*>(p_address);
	switch (*m_value)
	{
		case 0: return "Locations";
		case 1: return "Occupations";
		case 2: return "AssignOccupation";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_petst__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_petst::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "List";
		case 1: return "TrainingKnowledge";
		case 2: return "SelectTrainer";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_setup_character_info__T_status_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::setup_character_info::T_status*>(p_address);
	switch (*m_value)
	{
		case 0: return "Peasant";
		case 1: return "Hero";
		case 2: return "Demigod";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_setupadventurest__T_page_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_setupadventurest::T_page*>(p_address);
	switch (*m_value)
	{
		case 0: return "ChooseRace";
		case 1: return "ChooseAnimalRace";
		case 2: return "ChooseHistfig";
		case 3: return "ChooseCiv";
		case 4: return "Skills";
		case 5: return "PhysicalTraits";
		case 6: return "MentalTraits";
		case 7: return "Background";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_setupadventurest__T_sel_trait_column_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_setupadventurest::T_sel_trait_column*>(p_address);
	switch (*m_value)
	{
		case 0: return "SkillsColumn";
		case 1: return "AttributesColumn";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_setupdwarfgamest__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_setupdwarfgamest::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "Dwarves";
		case 1: return "Items";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_titlest__T_sel_subpage_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_titlest::T_sel_subpage*>(p_address);
	switch (*m_value)
	{
		case 0: return "None";
		case 1: return "StartSelectWorld";
		case 2: return "StartSelectMode";
		case 3: return "Arena";
		case 4: return "About";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_workquota_conditionst__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_workquota_conditionst::T_mode*>(p_address);
	switch (*m_value)
	{
		case -1: return "List";
		case 0: return "ItemType";
		case 1: return "Material";
		case 2: return "Traits";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_viewscreen_workshop_profilest__T_tab_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::viewscreen_workshop_profilest::T_tab*>(p_address);
	switch (*m_value)
	{
		case 0: return "Workers";
		case 1: return "Orders";
		case 2: return "Restrictions";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_world_underground_region__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::world_underground_region::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Cavern";
		case 1: return "MagmaSea";
		case 2: return "Underworld";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_world_data__T_flip_latitude_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::world_data::T_flip_latitude*>(p_address);
	switch (*m_value)
	{
		case -1: return "None";
		case 0: return "North";
		case 1: return "South";
		case 2: return "Both";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_abstract_building_dungeonst__T_dungeon_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::abstract_building_dungeonst::T_dungeon_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "DUNGEON";
		case 1: return "SEWERS";
		case 2: return "CATACOMBS";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_cultural_identity__T_group_log__T_join_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::cultural_identity::T_group_log::T_join_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Peaceful";
		case 1: return "CompleteTakeOver";
		case 2: return "TakeOver";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_world_site_realization__T_areas__T_type_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::world_site_realization::T_areas::T_type*>(p_address);
	switch (*m_value)
	{
		case 0: return "Crops1";
		case 1: return "Crops2";
		case 2: return "Crops3";
		case 3: return "Meadow";
		case 4: return "Pasture";
		case 5: return "Orchard";
		case 6: return "Woodland";
		case 7: return "Waste";
		case 8: return "Unknown1";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_crime__T_mode_string_value(uint64_t p_address)
{
	auto m_value = reinterpret_cast<df::crime::T_mode*>(p_address);
	switch (*m_value)
	{
		case 0: return "ProductionOrderViolation";
		case 1: return "ExportViolation";
		case 2: return "JobOrderViolation";
		case 3: return "ConspiracyToSlowLabor";
		case 4: return "Murder";
		case 5: return "DisorderlyBehavior";
		case 6: return "BuildingDestruction";
		case 7: return "Vandalism";
		case 8: return "Theft";
		case 9: return "Robbery";
		case 10: return "BloodDrinking";
		default: break;
	}
	return "UNKNOWN-VALUE";
}

std::string get_enum_value_as_string(DF_Type p_df_type, uint64_t p_address)
{
	switch(p_df_type)
	{
		case DF_Type::ui_advmode_menu: return get_ui_advmode_menu_string_value(p_address);
		case DF_Type::talk_choice_type: return get_talk_choice_type_string_value(p_address);
		case DF_Type::announcement_type: return get_announcement_type_string_value(p_address);
		case DF_Type::art_image_element_type: return get_art_image_element_type_string_value(p_address);
		case DF_Type::art_image_property_type: return get_art_image_property_type_string_value(p_address);
		case DF_Type::art_image_property_verb: return get_art_image_property_verb_string_value(p_address);
		case DF_Type::art_facet_type: return get_art_facet_type_string_value(p_address);
		case DF_Type::poetic_form_action: return get_poetic_form_action_string_value(p_address);
		case DF_Type::poetic_form_pattern: return get_poetic_form_pattern_string_value(p_address);
		case DF_Type::poetic_form_caesura_position: return get_poetic_form_caesura_position_string_value(p_address);
		case DF_Type::poetic_form_mood: return get_poetic_form_mood_string_value(p_address);
		case DF_Type::poetic_form_subject: return get_poetic_form_subject_string_value(p_address);
		case DF_Type::poetic_form_additional_feature: return get_poetic_form_additional_feature_string_value(p_address);
		case DF_Type::poetic_form_perspective__T_type: return get_poetic_form_perspective__T_type_string_value(p_address);
		case DF_Type::occupation_type: return get_occupation_type_string_value(p_address);
		case DF_Type::buildings_other_id: return get_buildings_other_id_string_value(p_address);
		case DF_Type::building_type: return get_building_type_string_value(p_address);
		case DF_Type::civzone_type: return get_civzone_type_string_value(p_address);
		case DF_Type::furnace_type: return get_furnace_type_string_value(p_address);
		case DF_Type::workshop_type: return get_workshop_type_string_value(p_address);
		case DF_Type::construction_type: return get_construction_type_string_value(p_address);
		case DF_Type::shop_type: return get_shop_type_string_value(p_address);
		case DF_Type::siegeengine_type: return get_siegeengine_type_string_value(p_address);
		case DF_Type::trap_type: return get_trap_type_string_value(p_address);
		case DF_Type::dfhack_room_quality_level: return get_dfhack_room_quality_level_string_value(p_address);
		case DF_Type::creature_raw_flags: return get_creature_raw_flags_string_value(p_address);
		case DF_Type::caste_raw_flags: return get_caste_raw_flags_string_value(p_address);
		case DF_Type::body_part_raw_flags: return get_body_part_raw_flags_string_value(p_address);
		case DF_Type::appearance_modifier_type: return get_appearance_modifier_type_string_value(p_address);
		case DF_Type::body_part_layer_flags: return get_body_part_layer_flags_string_value(p_address);
		case DF_Type::appearance_modifier_growth_interval: return get_appearance_modifier_growth_interval_string_value(p_address);
		case DF_Type::gait_type: return get_gait_type_string_value(p_address);
		case DF_Type::creature_graphics_role: return get_creature_graphics_role_string_value(p_address);
		case DF_Type::tissue_style_type: return get_tissue_style_type_string_value(p_address);
		case DF_Type::body_part_template_flags: return get_body_part_template_flags_string_value(p_address);
		case DF_Type::body_part_template_contype: return get_body_part_template_contype_string_value(p_address);
		case DF_Type::tissue_flags: return get_tissue_flags_string_value(p_address);
		case DF_Type::d_init_nickname: return get_d_init_nickname_string_value(p_address);
		case DF_Type::d_init_z_view: return get_d_init_z_view_string_value(p_address);
		case DF_Type::d_init_embark_confirm: return get_d_init_embark_confirm_string_value(p_address);
		case DF_Type::d_init_idlers: return get_d_init_idlers_string_value(p_address);
		case DF_Type::d_init_tunnel: return get_d_init_tunnel_string_value(p_address);
		case DF_Type::d_init_flags1: return get_d_init_flags1_string_value(p_address);
		case DF_Type::d_init_flags2: return get_d_init_flags2_string_value(p_address);
		case DF_Type::d_init_flags3: return get_d_init_flags3_string_value(p_address);
		case DF_Type::d_init_flags4: return get_d_init_flags4_string_value(p_address);
		case DF_Type::pattern_type: return get_pattern_type_string_value(p_address);
		case DF_Type::occasion_schedule_type: return get_occasion_schedule_type_string_value(p_address);
		case DF_Type::occasion_schedule_feature: return get_occasion_schedule_feature_string_value(p_address);
		case DF_Type::entity_sell_category: return get_entity_sell_category_string_value(p_address);
		case DF_Type::historical_entity_type: return get_historical_entity_type_string_value(p_address);
		case DF_Type::training_knowledge_level: return get_training_knowledge_level_string_value(p_address);
		case DF_Type::entity_position_flags: return get_entity_position_flags_string_value(p_address);
		case DF_Type::entity_material_category: return get_entity_material_category_string_value(p_address);
		case DF_Type::entity_event_type: return get_entity_event_type_string_value(p_address);
		case DF_Type::entity_raw_flags: return get_entity_raw_flags_string_value(p_address);
		case DF_Type::site_type: return get_site_type_string_value(p_address);
		case DF_Type::ethic_type: return get_ethic_type_string_value(p_address);
		case DF_Type::ethic_response: return get_ethic_response_string_value(p_address);
		case DF_Type::entity_name_type: return get_entity_name_type_string_value(p_address);
		case DF_Type::entity_position_raw_flags: return get_entity_position_raw_flags_string_value(p_address);
		case DF_Type::entity_position_responsibility: return get_entity_position_responsibility_string_value(p_address);
		case DF_Type::weather_type: return get_weather_type_string_value(p_address);
		case DF_Type::game_mode: return get_game_mode_string_value(p_address);
		case DF_Type::game_type: return get_game_type_string_value(p_address);
		case DF_Type::lever_target_type: return get_lever_target_type_string_value(p_address);
		case DF_Type::zoom_commands: return get_zoom_commands_string_value(p_address);
		case DF_Type::reputation_type: return get_reputation_type_string_value(p_address);
		case DF_Type::histfig_flags: return get_histfig_flags_string_value(p_address);
		case DF_Type::histfig_relationship_type: return get_histfig_relationship_type_string_value(p_address);
		case DF_Type::mental_picture_property_type: return get_mental_picture_property_type_string_value(p_address);
		case DF_Type::mental_picture_element_type: return get_mental_picture_element_type_string_value(p_address);
		case DF_Type::history_event_type: return get_history_event_type_string_value(p_address);
		case DF_Type::history_event_reason: return get_history_event_reason_string_value(p_address);
		case DF_Type::death_type: return get_death_type_string_value(p_address);
		case DF_Type::entity_action_type: return get_entity_action_type_string_value(p_address);
		case DF_Type::masterpiece_loss_type: return get_masterpiece_loss_type_string_value(p_address);
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return get_history_event_hist_figure_woundedst__T_injury_type_string_value(p_address);
		case DF_Type::history_event_simple_battle_subtype: return get_history_event_simple_battle_subtype_string_value(p_address);
		case DF_Type::histfig_body_state: return get_histfig_body_state_string_value(p_address);
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return get_history_event_hf_act_on_buildingst__T_action_string_value(p_address);
		case DF_Type::site_dispute_type: return get_site_dispute_type_string_value(p_address);
		case DF_Type::insurrection_outcome: return get_insurrection_outcome_string_value(p_address);
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return get_history_event_hf_act_on_artifactst__T_action_string_value(p_address);
		case DF_Type::tactical_situation: return get_tactical_situation_string_value(p_address);
		case DF_Type::history_event_collection_type: return get_history_event_collection_type_string_value(p_address);
		case DF_Type::era_type: return get_era_type_string_value(p_address);
		case DF_Type::init_display_flags: return get_init_display_flags_string_value(p_address);
		case DF_Type::init_media_flags: return get_init_media_flags_string_value(p_address);
		case DF_Type::init_input_flags: return get_init_input_flags_string_value(p_address);
		case DF_Type::init_window_flags: return get_init_window_flags_string_value(p_address);
		case DF_Type::interaction_effect_type: return get_interaction_effect_type_string_value(p_address);
		case DF_Type::interaction_effect_location_hint: return get_interaction_effect_location_hint_string_value(p_address);
		case DF_Type::interaction_source_type: return get_interaction_source_type_string_value(p_address);
		case DF_Type::interaction_source_usage_hint: return get_interaction_source_usage_hint_string_value(p_address);
		case DF_Type::interaction_target_type: return get_interaction_target_type_string_value(p_address);
		case DF_Type::interaction_target_location_type: return get_interaction_target_location_type_string_value(p_address);
		case DF_Type::breath_attack_type: return get_breath_attack_type_string_value(p_address);
		case DF_Type::item_type: return get_item_type_string_value(p_address);
		case DF_Type::ammo_flags: return get_ammo_flags_string_value(p_address);
		case DF_Type::armor_general_flags: return get_armor_general_flags_string_value(p_address);
		case DF_Type::armor_flags: return get_armor_flags_string_value(p_address);
		case DF_Type::gloves_flags: return get_gloves_flags_string_value(p_address);
		case DF_Type::helm_flags: return get_helm_flags_string_value(p_address);
		case DF_Type::instrument_flags: return get_instrument_flags_string_value(p_address);
		case DF_Type::sound_production_type: return get_sound_production_type_string_value(p_address);
		case DF_Type::pitch_choice_type: return get_pitch_choice_type_string_value(p_address);
		case DF_Type::tuning_type: return get_tuning_type_string_value(p_address);
		case DF_Type::timbre_type: return get_timbre_type_string_value(p_address);
		case DF_Type::pants_flags: return get_pants_flags_string_value(p_address);
		case DF_Type::shoes_flags: return get_shoes_flags_string_value(p_address);
		case DF_Type::tool_flags: return get_tool_flags_string_value(p_address);
		case DF_Type::tool_uses: return get_tool_uses_string_value(p_address);
		case DF_Type::toy_flags: return get_toy_flags_string_value(p_address);
		case DF_Type::trapcomp_flags: return get_trapcomp_flags_string_value(p_address);
		case DF_Type::weapon_flags: return get_weapon_flags_string_value(p_address);
		case DF_Type::items_other_id: return get_items_other_id_string_value(p_address);
		case DF_Type::job_item_vector_id: return get_job_item_vector_id_string_value(p_address);
		case DF_Type::improvement_type: return get_improvement_type_string_value(p_address);
		case DF_Type::itemimprovement_specific_type: return get_itemimprovement_specific_type_string_value(p_address);
		case DF_Type::written_content_type: return get_written_content_type_string_value(p_address);
		case DF_Type::written_content_style: return get_written_content_style_string_value(p_address);
		case DF_Type::item_magicness_type: return get_item_magicness_type_string_value(p_address);
		case DF_Type::item_quality: return get_item_quality_string_value(p_address);
		case DF_Type::slab_engraving_type: return get_slab_engraving_type_string_value(p_address);
		case DF_Type::corpse_material_type: return get_corpse_material_type_string_value(p_address);
		case DF_Type::job_type_class: return get_job_type_class_string_value(p_address);
		case DF_Type::job_type: return get_job_type_string_value(p_address);
		case DF_Type::job_subtype_surgery: return get_job_subtype_surgery_string_value(p_address);
		case DF_Type::job_art_specification__T_type: return get_job_art_specification__T_type_string_value(p_address);
		case DF_Type::manager_order_condition_order__T_condition: return get_manager_order_condition_order__T_condition_string_value(p_address);
		case DF_Type::guild_id: return get_guild_id_string_value(p_address);
		case DF_Type::interface_key: return get_interface_key_string_value(p_address);
		case DF_Type::dfhack_knowledge_scholar_flag: return get_dfhack_knowledge_scholar_flag_string_value(p_address);
		case DF_Type::part_of_speech: return get_part_of_speech_string_value(p_address);
		case DF_Type::sphere_type: return get_sphere_type_string_value(p_address);
		case DF_Type::language_name_category: return get_language_name_category_string_value(p_address);
		case DF_Type::nemesis_flags: return get_nemesis_flags_string_value(p_address);
		case DF_Type::machine_type: return get_machine_type_string_value(p_address);
		case DF_Type::screw_pump_direction: return get_screw_pump_direction_string_value(p_address);
		case DF_Type::tile_traffic: return get_tile_traffic_string_value(p_address);
		case DF_Type::tile_dig_designation: return get_tile_dig_designation_string_value(p_address);
		case DF_Type::tile_liquid: return get_tile_liquid_string_value(p_address);
		case DF_Type::tile_building_occ: return get_tile_building_occ_string_value(p_address);
		case DF_Type::tile_liquid_flow_dir: return get_tile_liquid_flow_dir_string_value(p_address);
		case DF_Type::block_square_event_type: return get_block_square_event_type_string_value(p_address);
		case DF_Type::feature_type: return get_feature_type_string_value(p_address);
		case DF_Type::feature_init_flags: return get_feature_init_flags_string_value(p_address);
		case DF_Type::feature_alteration_type: return get_feature_alteration_type_string_value(p_address);
		case DF_Type::world_construction_type: return get_world_construction_type_string_value(p_address);
		case DF_Type::biome_type: return get_biome_type_string_value(p_address);
		case DF_Type::flow_type: return get_flow_type_string_value(p_address);
		case DF_Type::flow_guide_type: return get_flow_guide_type_string_value(p_address);
		case DF_Type::region_block_event_type: return get_region_block_event_type_string_value(p_address);
		case DF_Type::craft_material_class: return get_craft_material_class_string_value(p_address);
		case DF_Type::builtin_mats: return get_builtin_mats_string_value(p_address);
		case DF_Type::material_flags: return get_material_flags_string_value(p_address);
		case DF_Type::matter_state: return get_matter_state_string_value(p_address);
		case DF_Type::strain_type: return get_strain_type_string_value(p_address);
		case DF_Type::inorganic_flags: return get_inorganic_flags_string_value(p_address);
		case DF_Type::environment_type: return get_environment_type_string_value(p_address);
		case DF_Type::inclusion_type: return get_inclusion_type_string_value(p_address);
		case DF_Type::organic_mat_category: return get_organic_mat_category_string_value(p_address);
		case DF_Type::meeting_topic: return get_meeting_topic_string_value(p_address);
		case DF_Type::meeting_event_type: return get_meeting_event_type_string_value(p_address);
		case DF_Type::activity_event_type: return get_activity_event_type_string_value(p_address);
		case DF_Type::conversation_menu: return get_conversation_menu_string_value(p_address);
		case DF_Type::performance_event_type: return get_performance_event_type_string_value(p_address);
		case DF_Type::performance_participant_type: return get_performance_participant_type_string_value(p_address);
		case DF_Type::uniform_category: return get_uniform_category_string_value(p_address);
		case DF_Type::barrack_preference_category: return get_barrack_preference_category_string_value(p_address);
		case DF_Type::squad_event_type: return get_squad_event_type_string_value(p_address);
		case DF_Type::squad_order_type: return get_squad_order_type_string_value(p_address);
		case DF_Type::squad_order_cannot_reason: return get_squad_order_cannot_reason_string_value(p_address);
		case DF_Type::army_flags: return get_army_flags_string_value(p_address);
		case DF_Type::unit_path_goal: return get_unit_path_goal_string_value(p_address);
		case DF_Type::unit_station_type: return get_unit_station_type_string_value(p_address);
		case DF_Type::plant_raw_flags: return get_plant_raw_flags_string_value(p_address);
		case DF_Type::projectile_type: return get_projectile_type_string_value(p_address);
		case DF_Type::reaction_flags: return get_reaction_flags_string_value(p_address);
		case DF_Type::reaction_reagent_type: return get_reaction_reagent_type_string_value(p_address);
		case DF_Type::reaction_product_type: return get_reaction_product_type_string_value(p_address);
		case DF_Type::reaction_product_item_flags: return get_reaction_product_item_flags_string_value(p_address);
		case DF_Type::reaction_product_improvement_flags: return get_reaction_product_improvement_flags_string_value(p_address);
		case DF_Type::general_ref_type: return get_general_ref_type_string_value(p_address);
		case DF_Type::specific_ref_type: return get_specific_ref_type_string_value(p_address);
		case DF_Type::histfig_entity_link_type: return get_histfig_entity_link_type_string_value(p_address);
		case DF_Type::histfig_site_link_type: return get_histfig_site_link_type_string_value(p_address);
		case DF_Type::histfig_hf_link_type: return get_histfig_hf_link_type_string_value(p_address);
		case DF_Type::entity_entity_link_type: return get_entity_entity_link_type_string_value(p_address);
		case DF_Type::resource_allotment_specifier_type: return get_resource_allotment_specifier_type_string_value(p_address);
		case DF_Type::profession: return get_profession_string_value(p_address);
		case DF_Type::unit_labor_category: return get_unit_labor_category_string_value(p_address);
		case DF_Type::unit_labor: return get_unit_labor_string_value(p_address);
		case DF_Type::job_skill_class: return get_job_skill_class_string_value(p_address);
		case DF_Type::job_skill: return get_job_skill_string_value(p_address);
		case DF_Type::hauler_type: return get_hauler_type_string_value(p_address);
		case DF_Type::furniture_type: return get_furniture_type_string_value(p_address);
		case DF_Type::stockpile_category: return get_stockpile_category_string_value(p_address);
		case DF_Type::stockpile_list: return get_stockpile_list_string_value(p_address);
		case DF_Type::creature_interaction_effect_type: return get_creature_interaction_effect_type_string_value(p_address);
		case DF_Type::creature_interaction_effect_target_mode: return get_creature_interaction_effect_target_mode_string_value(p_address);
		case DF_Type::tiletype_shape_basic: return get_tiletype_shape_basic_string_value(p_address);
		case DF_Type::tiletype_shape: return get_tiletype_shape_string_value(p_address);
		case DF_Type::tiletype_material: return get_tiletype_material_string_value(p_address);
		case DF_Type::tiletype_variant: return get_tiletype_variant_string_value(p_address);
		case DF_Type::tiletype_special: return get_tiletype_special_string_value(p_address);
		case DF_Type::tiletype: return get_tiletype_string_value(p_address);
		case DF_Type::build_req_choice_type: return get_build_req_choice_type_string_value(p_address);
		case DF_Type::ui_hotkey__T_cmd: return get_ui_hotkey__T_cmd_string_value(p_address);
		case DF_Type::ui_sidebar_mode: return get_ui_sidebar_mode_string_value(p_address);
		case DF_Type::kitchen_exc_type: return get_kitchen_exc_type_string_value(p_address);
		case DF_Type::timed_event_type: return get_timed_event_type_string_value(p_address);
		case DF_Type::emotion_type: return get_emotion_type_string_value(p_address);
		case DF_Type::unit_thought_type: return get_unit_thought_type_string_value(p_address);
		case DF_Type::value_type: return get_value_type_string_value(p_address);
		case DF_Type::goal_type: return get_goal_type_string_value(p_address);
		case DF_Type::personality_facet_type: return get_personality_facet_type_string_value(p_address);
		case DF_Type::physical_attribute_type: return get_physical_attribute_type_string_value(p_address);
		case DF_Type::mental_attribute_type: return get_mental_attribute_type_string_value(p_address);
		case DF_Type::mood_type: return get_mood_type_string_value(p_address);
		case DF_Type::ghost_type: return get_ghost_type_string_value(p_address);
		case DF_Type::animal_training_level: return get_animal_training_level_string_value(p_address);
		case DF_Type::unit_report_type: return get_unit_report_type_string_value(p_address);
		case DF_Type::skill_rating: return get_skill_rating_string_value(p_address);
		case DF_Type::unit_relationship_type: return get_unit_relationship_type_string_value(p_address);
		case DF_Type::need_type: return get_need_type_string_value(p_address);
		case DF_Type::ghost_goal: return get_ghost_goal_string_value(p_address);
		case DF_Type::wound_effect_type: return get_wound_effect_type_string_value(p_address);
		case DF_Type::misc_trait_type: return get_misc_trait_type_string_value(p_address);
		case DF_Type::unit_action_type: return get_unit_action_type_string_value(p_address);
		case DF_Type::interface_breakdown_types: return get_interface_breakdown_types_string_value(p_address);
		case DF_Type::embark_finder_option: return get_embark_finder_option_string_value(p_address);
		case DF_Type::viewscreen_image_creator_mode: return get_viewscreen_image_creator_mode_string_value(p_address);
		case DF_Type::viewscreen_kitchenpref_page: return get_viewscreen_kitchenpref_page_string_value(p_address);
		case DF_Type::adventurer_attribute_level: return get_adventurer_attribute_level_string_value(p_address);
		case DF_Type::viewscreen_unitlist_page: return get_viewscreen_unitlist_page_string_value(p_address);
		case DF_Type::world_population_type: return get_world_population_type_string_value(p_address);
		case DF_Type::world_region_type: return get_world_region_type_string_value(p_address);
		case DF_Type::geo_layer_type: return get_geo_layer_type_string_value(p_address);
		case DF_Type::region_map_entry_flags: return get_region_map_entry_flags_string_value(p_address);
		case DF_Type::front_type: return get_front_type_string_value(p_address);
		case DF_Type::cumulus_type: return get_cumulus_type_string_value(p_address);
		case DF_Type::stratus_type: return get_stratus_type_string_value(p_address);
		case DF_Type::fog_type: return get_fog_type_string_value(p_address);
		case DF_Type::mountain_peak_flags: return get_mountain_peak_flags_string_value(p_address);
		case DF_Type::abstract_building_type: return get_abstract_building_type_string_value(p_address);
		case DF_Type::abstract_building_flags: return get_abstract_building_flags_string_value(p_address);
		case DF_Type::world_site_type: return get_world_site_type_string_value(p_address);
		case DF_Type::world_site_flags: return get_world_site_flags_string_value(p_address);
		case DF_Type::site_realization_building_type: return get_site_realization_building_type_string_value(p_address);
		case DF_Type::site_shop_type: return get_site_shop_type_string_value(p_address);
		case DF_Type::tree_house_type: return get_tree_house_type_string_value(p_address);
		case DF_Type::hillock_house_type: return get_hillock_house_type_string_value(p_address);
		case DF_Type::creation_zone_pwg_alteration_type: return get_creation_zone_pwg_alteration_type_string_value(p_address);
		case DF_Type::worldgen_region_type: return get_worldgen_region_type_string_value(p_address);
		case DF_Type::worldgen_range_type: return get_worldgen_range_type_string_value(p_address);
		case DF_Type::units_other_id: return get_units_other_id_string_value(p_address);
		case DF_Type::conflict_level: return get_conflict_level_string_value(p_address);
		case DF_Type::combat_report_event_type: return get_combat_report_event_type_string_value(p_address);
		case DF_Type::conversation__T_state: return get_conversation__T_state_string_value(p_address);
		case DF_Type::building_archerytargetst__T_archery_direction: return get_building_archerytargetst__T_archery_direction_string_value(p_address);
		case DF_Type::building_bridgest__T_direction: return get_building_bridgest__T_direction_string_value(p_address);
		case DF_Type::building_siegeenginest__T_facing: return get_building_siegeenginest__T_facing_string_value(p_address);
		case DF_Type::building_siegeenginest__T_action: return get_building_siegeenginest__T_action_string_value(p_address);
		case DF_Type::caste_body_info__T_interactions__T_type: return get_caste_body_info__T_interactions__T_type_string_value(p_address);
		case DF_Type::caravan_state__T_trade_state: return get_caravan_state__T_trade_state_string_value(p_address);
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return get_entity_event__T_data__T_insurrection_end__T_result_string_value(p_address);
		case DF_Type::history_event_change_hf_statest__T_state: return get_history_event_change_hf_statest__T_state_string_value(p_address);
		case DF_Type::history_event_body_abusedst__T_props__T_pile_type: return get_history_event_body_abusedst__T_props__T_pile_type_string_value(p_address);
		case DF_Type::history_event_body_abusedst__T_abuse_type: return get_history_event_body_abusedst__T_abuse_type_string_value(p_address);
		case DF_Type::history_event_hist_figure_travelst__T_reason: return get_history_event_hist_figure_travelst__T_reason_string_value(p_address);
		case DF_Type::history_event_artifact_claim_formedst__T_claim_type: return get_history_event_artifact_claim_formedst__T_claim_type_string_value(p_address);
		case DF_Type::init_display__T_windowed: return get_init_display__T_windowed_string_value(p_address);
		case DF_Type::init_font__T_use_ttf: return get_init_font__T_use_ttf_string_value(p_address);
		case DF_Type::job_item_ref__T_role: return get_job_item_ref__T_role_string_value(p_address);
		case DF_Type::manager_order__T_frequency: return get_manager_order__T_frequency_string_value(p_address);
		case DF_Type::manager_order_condition_item__T_compare_type: return get_manager_order_condition_item__T_compare_type_string_value(p_address);
		case DF_Type::mandate__T_mode: return get_mandate__T_mode_string_value(p_address);
		case DF_Type::unit_demand__T_place: return get_unit_demand__T_place_string_value(p_address);
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return get_ui_advmode__T_conversation__T_targets__T_type_string_value(p_address);
		case DF_Type::ui_advmode__T_travel_right_map: return get_ui_advmode__T_travel_right_map_string_value(p_address);
		case DF_Type::ui_advmode__T_show_menu: return get_ui_advmode__T_show_menu_string_value(p_address);
		case DF_Type::stop_depart_condition__T_direction: return get_stop_depart_condition__T_direction_string_value(p_address);
		case DF_Type::stop_depart_condition__T_mode: return get_stop_depart_condition__T_mode_string_value(p_address);
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return get_interface_button_construction_category_selectorst__T_category_id_string_value(p_address);
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return get_ui_sidebar_menus__T_designation__T_mine_mode_string_value(p_address);
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return get_ui_sidebar_menus__T_zone__T_mode_string_value(p_address);
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return get_ui_sidebar_menus__T_unit__T_expel_error_string_value(p_address);
		case DF_Type::ui_look_list__T_items__T_type: return get_ui_look_list__T_items__T_type_string_value(p_address);
		case DF_Type::ui_unit_view_mode__T_value: return get_ui_unit_view_mode__T_value_string_value(p_address);
		case DF_Type::unit__T_meeting__T_state: return get_unit__T_meeting__T_state_string_value(p_address);
		case DF_Type::unit__T_counters__T_soldier_mood: return get_unit__T_counters__T_soldier_mood_string_value(p_address);
		case DF_Type::unit_inventory_item__T_mode: return get_unit_inventory_item__T_mode_string_value(p_address);
		case DF_Type::unit_preference__T_type: return get_unit_preference__T_type_string_value(p_address);
		case DF_Type::unit_complaint__T_type: return get_unit_complaint__T_type_string_value(p_address);
		case DF_Type::unit_request__T_type: return get_unit_request__T_type_string_value(p_address);
		case DF_Type::KeybindingScreen__T_mode: return get_KeybindingScreen__T_mode_string_value(p_address);
		case DF_Type::viewscreen_adventure_logst__T_mode: return get_viewscreen_adventure_logst__T_mode_string_value(p_address);
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return get_viewscreen_adventure_logst__T_info_mode_string_value(p_address);
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return get_viewscreen_assign_display_itemst__T_sel_column_string_value(p_address);
		case DF_Type::viewscreen_choose_start_sitest__T_page: return get_viewscreen_choose_start_sitest__T_page_string_value(p_address);
		case DF_Type::mission__T_details__T_raid__T_raid_type: return get_mission__T_details__T_raid__T_raid_type_string_value(p_address);
		case DF_Type::mission__T_type: return get_mission__T_type_string_value(p_address);
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return get_viewscreen_civlistst__T_rumors__T_type_string_value(p_address);
		case DF_Type::viewscreen_civlistst__T_page: return get_viewscreen_civlistst__T_page_string_value(p_address);
		case DF_Type::viewscreen_game_cleanerst__T_state: return get_viewscreen_game_cleanerst__T_state_string_value(p_address);
		case DF_Type::viewscreen_justicest__T_cur_column: return get_viewscreen_justicest__T_cur_column_string_value(p_address);
		case DF_Type::assign_trade_status__T_status: return get_assign_trade_status__T_status_string_value(p_address);
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return get_viewscreen_layer_choose_language_namest__T_current_component_string_value(p_address);
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return get_viewscreen_layer_militaryst__T_equip__T_mode_string_value(p_address);
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return get_viewscreen_layer_militaryst__T_equip__T_edit_mode_string_value(p_address);
		case DF_Type::viewscreen_layer_militaryst__T_page: return get_viewscreen_layer_militaryst__T_page_string_value(p_address);
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return get_viewscreen_layer_noblelistst__T_mode_string_value(p_address);
		case DF_Type::viewscreen_legendsst__T_cur_page: return get_viewscreen_legendsst__T_cur_page_string_value(p_address);
		case DF_Type::viewscreen_locationsst__T_in_edit: return get_viewscreen_locationsst__T_in_edit_string_value(p_address);
		case DF_Type::viewscreen_locationsst__T_menu: return get_viewscreen_locationsst__T_menu_string_value(p_address);
		case DF_Type::viewscreen_petst__T_mode: return get_viewscreen_petst__T_mode_string_value(p_address);
		case DF_Type::setup_character_info__T_status: return get_setup_character_info__T_status_string_value(p_address);
		case DF_Type::viewscreen_setupadventurest__T_page: return get_viewscreen_setupadventurest__T_page_string_value(p_address);
		case DF_Type::viewscreen_setupadventurest__T_sel_trait_column: return get_viewscreen_setupadventurest__T_sel_trait_column_string_value(p_address);
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return get_viewscreen_setupdwarfgamest__T_mode_string_value(p_address);
		case DF_Type::viewscreen_titlest__T_sel_subpage: return get_viewscreen_titlest__T_sel_subpage_string_value(p_address);
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return get_viewscreen_workquota_conditionst__T_mode_string_value(p_address);
		case DF_Type::viewscreen_workshop_profilest__T_tab: return get_viewscreen_workshop_profilest__T_tab_string_value(p_address);
		case DF_Type::world_underground_region__T_type: return get_world_underground_region__T_type_string_value(p_address);
		case DF_Type::world_data__T_flip_latitude: return get_world_data__T_flip_latitude_string_value(p_address);
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return get_abstract_building_dungeonst__T_dungeon_type_string_value(p_address);
		case DF_Type::cultural_identity__T_group_log__T_join_type: return get_cultural_identity__T_group_log__T_join_type_string_value(p_address);
		case DF_Type::world_site_realization__T_areas__T_type: return get_world_site_realization__T_areas__T_type_string_value(p_address);
		case DF_Type::crime__T_mode: return get_crime__T_mode_string_value(p_address);
		default: break;
	}
	return "UNKNOWN DF_TYPE";
}

