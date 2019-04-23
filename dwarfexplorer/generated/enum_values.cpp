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


int64_t cast(DF_Type p_base_type, uint64_t p_address)
{
	switch (p_base_type)
	{
		case DF_Type::int8_t:   return *(reinterpret_cast<int8_t*>(p_address));
		case DF_Type::int16_t:  return *(reinterpret_cast<int16_t*>(p_address));
		case DF_Type::int32_t:  return *(reinterpret_cast<int32_t*>(p_address));
		case DF_Type::int64_t:  return *(reinterpret_cast<int64_t*>(p_address));
		case DF_Type::uint8_t:  return *(reinterpret_cast<uint8_t*>(p_address));
		case DF_Type::uint16_t: return *(reinterpret_cast<uint16_t*>(p_address));
		case DF_Type::uint32_t: return *(reinterpret_cast<uint32_t*>(p_address));
		default: break;
	}
	return -1111;
}

std::pair<int64_t, std::string> get_ui_advmode_menu_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Default"; break;
		case 1: result.second = "Look"; break;
		case 2: result.second = "ConversationAddress"; break;
		case 3: result.second = "ConversationSelect"; break;
		case 4: result.second = "ConversationSpeak"; break;
		case 5: result.second = "Inventory"; break;
		case 6: result.second = "Drop"; break;
		case 7: result.second = "ThrowItem"; break;
		case 8: result.second = "Wear"; break;
		case 9: result.second = "Remove"; break;
		case 10: result.second = "Interact"; break;
		case 11: result.second = "Put"; break;
		case 12: result.second = "PutContainer"; break;
		case 13: result.second = "Eat"; break;
		case 14: result.second = "ThrowAim"; break;
		case 15: result.second = "Fire"; break;
		case 16: result.second = "Get"; break;
		case 17: result.second = "Unk17"; break;
		case 18: result.second = "CombatPrefs"; break;
		case 19: result.second = "Companions"; break;
		case 20: result.second = "MovementPrefs"; break;
		case 21: result.second = "SpeedPrefs"; break;
		case 22: result.second = "InteractAction"; break;
		case 23: result.second = "MoveCarefully"; break;
		case 24: result.second = "Announcements"; break;
		case 25: result.second = "UseBuilding"; break;
		case 26: result.second = "Travel"; break;
		case 27: result.second = "Unk27"; break;
		case 28: result.second = "Unk28"; break;
		case 29: result.second = "SleepConfirm"; break;
		case 30: result.second = "SelectInteractionTarget"; break;
		case 31: result.second = "Unk31"; break;
		case 32: result.second = "Unk32"; break;
		case 33: result.second = "FallAction"; break;
		case 34: result.second = "ViewTracks"; break;
		case 35: result.second = "Jump"; break;
		case 36: result.second = "Unk36"; break;
		case 37: result.second = "AttackConfirm"; break;
		case 38: result.second = "AttackType"; break;
		case 39: result.second = "AttackBodypart"; break;
		case 40: result.second = "AttackStrike"; break;
		case 41: result.second = "Unk41"; break;
		case 42: result.second = "Unk42"; break;
		case 43: result.second = "DodgeDirection"; break;
		case 44: result.second = "Unk44"; break;
		case 45: result.second = "Unk45"; break;
		case 46: result.second = "Build"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_talk_choice_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Greet"; break;
		case 1: result.second = "Nevermind"; break;
		case 2: result.second = "Trade"; break;
		case 3: result.second = "AskJoin"; break;
		case 4: result.second = "AskSurroundings"; break;
		case 5: result.second = "SayGoodbye"; break;
		case 6: result.second = "AskStructure"; break;
		case 7: result.second = "AskFamily"; break;
		case 8: result.second = "AskProfession"; break;
		case 9: result.second = "AskPermissionSleep"; break;
		case 10: result.second = "AccuseNightCreature"; break;
		case 11: result.second = "AskTroubles"; break;
		case 12: result.second = "BringUpEvent"; break;
		case 13: result.second = "SpreadRumor"; break;
		case 14: result.second = "ReplyGreeting"; break;
		case 15: result.second = "RefuseConversation"; break;
		case 16: result.second = "ReplyImpersonate"; break;
		case 17: result.second = "BringUpIncident"; break;
		case 18: result.second = "TellNothingChanged"; break;
		case 19: result.second = "Goodbye2"; break;
		case 20: result.second = "ReturnTopic"; break;
		case 21: result.second = "ChangeSubject"; break;
		case 22: result.second = "AskTargetAction"; break;
		case 23: result.second = "RequestSuggestAction"; break;
		case 24: result.second = "AskJoinInsurrection"; break;
		case 25: result.second = "AskJoinRescue"; break;
		case 26: result.second = "StateOpinion"; break;
		case 27: result.second = "RespondJoinInsurrection"; break;
		case 28: result.second = "anon_1"; break;
		case 29: result.second = "AllowPermissionSleep"; break;
		case 30: result.second = "DenyPermissionSleep"; break;
		case 31: result.second = "anon_2"; break;
		case 32: result.second = "AskJoinAdventure"; break;
		case 33: result.second = "AskGuideLocation"; break;
		case 34: result.second = "RespondJoin"; break;
		case 35: result.second = "RespondJoin2"; break;
		case 36: result.second = "OfferCondolences"; break;
		case 37: result.second = "StateNotAcquainted"; break;
		case 38: result.second = "SuggestTravel"; break;
		case 39: result.second = "SuggestTalk"; break;
		case 40: result.second = "RequestSelfRescue"; break;
		case 41: result.second = "AskWhatHappened"; break;
		case 42: result.second = "AskBeRescued"; break;
		case 43: result.second = "SayNotRemember"; break;
		case 44: result.second = "anon_3"; break;
		case 45: result.second = "SayNoFamily"; break;
		case 46: result.second = "StateUnitLocation"; break;
		case 47: result.second = "ReferToElder"; break;
		case 48: result.second = "AskComeCloser"; break;
		case 49: result.second = "DoBusiness"; break;
		case 50: result.second = "AskComeStoreLater"; break;
		case 51: result.second = "AskComeMarketLater"; break;
		case 52: result.second = "TellTryShopkeeper"; break;
		case 53: result.second = "DescribeSurroundings"; break;
		case 54: result.second = "AskWaitUntilHome"; break;
		case 55: result.second = "DescribeFamily"; break;
		case 56: result.second = "StateAge"; break;
		case 57: result.second = "DescribeProfession"; break;
		case 58: result.second = "AnnounceNightCreature"; break;
		case 59: result.second = "StateIncredulity"; break;
		case 60: result.second = "BypassGreeting"; break;
		case 61: result.second = "AskCeaseHostilities"; break;
		case 62: result.second = "DemandYield"; break;
		case 63: result.second = "HawkWares"; break;
		case 64: result.second = "YieldTerror"; break;
		case 65: result.second = "Yield"; break;
		case 66: result.second = "ExpressOverwhelmingEmotion"; break;
		case 67: result.second = "ExpressGreatEmotion"; break;
		case 68: result.second = "ExpressEmotion"; break;
		case 69: result.second = "ExpressMinorEmotion"; break;
		case 70: result.second = "ExpressLackEmotion"; break;
		case 71: result.second = "OutburstFleeConflict"; break;
		case 72: result.second = "StateFleeConflict"; break;
		case 73: result.second = "MentionJourney"; break;
		case 74: result.second = "SummarizeTroubles"; break;
		case 75: result.second = "AskAboutIncident"; break;
		case 76: result.second = "AskDirectionsPerson"; break;
		case 77: result.second = "AskDirectionsPlace"; break;
		case 78: result.second = "AskWhereabouts"; break;
		case 79: result.second = "RequestGuide"; break;
		case 80: result.second = "RequestGuide2"; break;
		case 81: result.second = "ProvideDirections"; break;
		case 82: result.second = "ProvideWhereabouts"; break;
		case 83: result.second = "TellTargetSelf"; break;
		case 84: result.second = "TellTargetDead"; break;
		case 85: result.second = "RecommendGuide"; break;
		case 86: result.second = "ProfessIgnorance"; break;
		case 87: result.second = "TellAboutPlace"; break;
		case 88: result.second = "AskFavorMenu"; break;
		case 89: result.second = "AskWait"; break;
		case 90: result.second = "AskFollow"; break;
		case 91: result.second = "ApologizeBusy"; break;
		case 92: result.second = "ComplyOrder"; break;
		case 93: result.second = "AgreeFollow"; break;
		case 94: result.second = "ExchangeItems"; break;
		case 95: result.second = "AskComeCloser2"; break;
		case 96: result.second = "InitiateBarter"; break;
		case 97: result.second = "AgreeCeaseHostile"; break;
		case 98: result.second = "RefuseCeaseHostile"; break;
		case 99: result.second = "RefuseCeaseHostile2"; break;
		case 100: result.second = "RefuseYield"; break;
		case 101: result.second = "RefuseYield2"; break;
		case 102: result.second = "Brag"; break;
		case 103: result.second = "DescribeRelation"; break;
		case 104: result.second = "ClaimSite"; break;
		case 105: result.second = "AnnounceLairHunt"; break;
		case 106: result.second = "RequestDuty"; break;
		case 107: result.second = "AskJoinService"; break;
		case 108: result.second = "AcceptService"; break;
		case 109: result.second = "TellRemainVigilant"; break;
		case 110: result.second = "GiveServiceOrder"; break;
		case 111: result.second = "WelcomeSelfHome"; break;
		case 112: result.second = "anon_4"; break;
		case 113: result.second = "AskTravelReason"; break;
		case 114: result.second = "TellTravelReason"; break;
		case 115: result.second = "AskLocalRuler"; break;
		case 116: result.second = "ComplainAgreement"; break;
		case 117: result.second = "CancelAgreement"; break;
		case 118: result.second = "SummarizeConflict"; break;
		case 119: result.second = "SummarizeViews"; break;
		case 120: result.second = "AskClaimStrength"; break;
		case 121: result.second = "AskArmyPosition"; break;
		case 122: result.second = "AskOtherClaims"; break;
		case 123: result.second = "AskDeserters"; break;
		case 124: result.second = "AskSiteNeighbors"; break;
		case 125: result.second = "DescribeSiteNeighbors"; break;
		case 126: result.second = "RaiseAlarm"; break;
		case 127: result.second = "DemandDropWeapon"; break;
		case 128: result.second = "AgreeComplyDemand"; break;
		case 129: result.second = "RefuseComplyDemand"; break;
		case 130: result.second = "AskLocationObject"; break;
		case 131: result.second = "DemandTribute"; break;
		case 132: result.second = "AgreeGiveTribute"; break;
		case 133: result.second = "RefuseGiveTribute"; break;
		case 134: result.second = "OfferGiveTribute"; break;
		case 135: result.second = "AgreeAcceptTribute"; break;
		case 136: result.second = "RefuseAcceptTribute"; break;
		case 137: result.second = "CancelTribute"; break;
		case 138: result.second = "OfferPeace"; break;
		case 139: result.second = "AgreePeace"; break;
		case 140: result.second = "RefusePeace"; break;
		case 141: result.second = "AskTradeDepotLater"; break;
		case 142: result.second = "ExpressAstonishment"; break;
		case 143: result.second = "CommentWeather"; break;
		case 144: result.second = "CommentNature"; break;
		case 145: result.second = "SummarizeTerritory"; break;
		case 146: result.second = "SummarizePatrols"; break;
		case 147: result.second = "SummarizeOpposition"; break;
		case 148: result.second = "DescribeRefugees"; break;
		case 149: result.second = "AccuseTroublemaker"; break;
		case 150: result.second = "AskAdopt"; break;
		case 151: result.second = "AgreeAdopt"; break;
		case 152: result.second = "RefuseAdopt"; break;
		case 153: result.second = "RevokeService"; break;
		case 154: result.second = "InviteService"; break;
		case 155: result.second = "AcceptInviteService"; break;
		case 156: result.second = "RefuseShareInformation"; break;
		case 157: result.second = "RefuseInviteService"; break;
		case 158: result.second = "RefuseRequestService"; break;
		case 159: result.second = "OfferService"; break;
		case 160: result.second = "AcceptPositionService"; break;
		case 161: result.second = "RefusePositionService"; break;
		case 162: result.second = "InvokeNameBanish"; break;
		case 163: result.second = "InvokeNameService"; break;
		case 164: result.second = "GrovelMaster"; break;
		case 165: result.second = "DemandItem"; break;
		case 166: result.second = "GiveServiceReport"; break;
		case 167: result.second = "OfferEncouragement"; break;
		case 168: result.second = "PraiseTaskCompleter"; break;
		case 169: result.second = "AskAboutPersonMenu"; break;
		case 170: result.second = "AskAboutPerson"; break;
		case 171: result.second = "TellAboutPerson"; break;
		case 172: result.second = "AskFeelings"; break;
		case 173: result.second = "TellThoughts"; break;
		case 174: result.second = "AskServices"; break;
		case 175: result.second = "TellServices"; break;
		case 176: result.second = "OrderDrink"; break;
		case 177: result.second = "RentRoom"; break;
		case 178: result.second = "ExtendRoomRental"; break;
		case 179: result.second = "ConfirmServiceOrder"; break;
		case 180: result.second = "AskJoinEntertain"; break;
		case 181: result.second = "RespondJoinEntertain"; break;
		case 182: result.second = "AskJoinTroupe"; break;
		case 183: result.second = "anon_5"; break;
		case 184: result.second = "RefuseTroupeApplication"; break;
		case 185: result.second = "InviteJoinTroupe"; break;
		case 186: result.second = "AcceptTroupeInvitation"; break;
		case 187: result.second = "RefuseTroupeInvitation"; break;
		case 188: result.second = "KickOutOfTroupe"; break;
		case 189: result.second = "CreateTroupe"; break;
		case 190: result.second = "LeaveTroupe"; break;
		case 191: result.second = "YellServiceOrder"; break;
		case 192: result.second = "TellBePatientForService"; break;
		case 193: result.second = "TellNoServices"; break;
		case 194: result.second = "AskWaitUntilThere"; break;
		case 195: result.second = "DenyWorkingHere"; break;
		case 196: result.second = "ExpressEmotionMenu"; break;
		case 197: result.second = "StateValueMenu"; break;
		case 198: result.second = "StateValue"; break;
		case 199: result.second = "SayNoOrderYet"; break;
		case 200: result.second = "ProvideDirectionsBuilding"; break;
		case 201: result.second = "Argue"; break;
		case 202: result.second = "Flatter"; break;
		case 203: result.second = "DismissArgument"; break;
		case 204: result.second = "RespondPassively"; break;
		case 205: result.second = "Acquiesce"; break;
		case 206: result.second = "DerideFlattery"; break;
		case 207: result.second = "ExpressOutrageAtDismissal"; break;
		case 208: result.second = "PressArgument"; break;
		case 209: result.second = "DropArgument"; break;
		case 210: result.second = "AskWork"; break;
		case 211: result.second = "AskWorkGroup"; break;
		case 212: result.second = "GrantWork"; break;
		case 213: result.second = "RefuseWork"; break;
		case 214: result.second = "GrantWorkGroup"; break;
		case 215: result.second = "RefuseWorkGroup"; break;
		case 216: result.second = "GiveSquadOrder"; break;
		case 217: result.second = "Artifact"; break;
		case 218: result.second = "PraiseReturn"; break;
		case 219: result.second = "ProvideLocation"; break;
		case 220: result.second = "Prophesize"; break;
		case 221: result.second = "TalkAboutAncestor"; break;
		case 222: result.second = "SuggestTrade"; break;
		case 223: result.second = "AcceptNotTrade"; break;
		case 224: result.second = "DemandIdentity"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_announcement_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "REACHED_PEAK"; break;
		case 1: result.second = "ERA_CHANGE"; break;
		case 2: result.second = "FEATURE_DISCOVERY"; break;
		case 3: result.second = "STRUCK_DEEP_METAL"; break;
		case 4: result.second = "STRUCK_MINERAL"; break;
		case 5: result.second = "STRUCK_ECONOMIC_MINERAL"; break;
		case 6: result.second = "COMBAT_TWIST_WEAPON"; break;
		case 7: result.second = "COMBAT_LET_ITEM_DROP"; break;
		case 8: result.second = "COMBAT_START_CHARGE"; break;
		case 9: result.second = "COMBAT_SURPRISE_CHARGE"; break;
		case 10: result.second = "COMBAT_JUMP_DODGE_PROJ"; break;
		case 11: result.second = "COMBAT_JUMP_DODGE_STRIKE"; break;
		case 12: result.second = "COMBAT_DODGE"; break;
		case 13: result.second = "COMBAT_COUNTERSTRIKE"; break;
		case 14: result.second = "COMBAT_BLOCK"; break;
		case 15: result.second = "COMBAT_PARRY"; break;
		case 16: result.second = "COMBAT_CHARGE_COLLISION"; break;
		case 17: result.second = "COMBAT_CHARGE_DEFENDER_TUMBLES"; break;
		case 18: result.second = "COMBAT_CHARGE_DEFENDER_KNOCKED_OVER"; break;
		case 19: result.second = "COMBAT_CHARGE_ATTACKER_TUMBLES"; break;
		case 20: result.second = "COMBAT_CHARGE_ATTACKER_BOUNCE_BACK"; break;
		case 21: result.second = "COMBAT_CHARGE_TANGLE_TOGETHER"; break;
		case 22: result.second = "COMBAT_CHARGE_TANGLE_TUMBLE"; break;
		case 23: result.second = "COMBAT_CHARGE_RUSH_BY"; break;
		case 24: result.second = "COMBAT_CHARGE_MANAGE_STOP"; break;
		case 25: result.second = "COMBAT_CHARGE_OBSTACLE_SLAM"; break;
		case 26: result.second = "COMBAT_WRESTLE_LOCK"; break;
		case 27: result.second = "COMBAT_WRESTLE_CHOKEHOLD"; break;
		case 28: result.second = "COMBAT_WRESTLE_TAKEDOWN"; break;
		case 29: result.second = "COMBAT_WRESTLE_THROW"; break;
		case 30: result.second = "COMBAT_WRESTLE_RELEASE_LOCK"; break;
		case 31: result.second = "COMBAT_WRESTLE_RELEASE_CHOKE"; break;
		case 32: result.second = "COMBAT_WRESTLE_RELEASE_GRIP"; break;
		case 33: result.second = "COMBAT_WRESTLE_STRUGGLE"; break;
		case 34: result.second = "COMBAT_WRESTLE_RELEASE_LATCH"; break;
		case 35: result.second = "COMBAT_WRESTLE_STRANGLE_KO"; break;
		case 36: result.second = "COMBAT_WRESTLE_ADJUST_GRIP"; break;
		case 37: result.second = "COMBAT_GRAB_TEAR"; break;
		case 38: result.second = "COMBAT_STRIKE_DETAILS"; break;
		case 39: result.second = "COMBAT_STRIKE_DETAILS_2"; break;
		case 40: result.second = "COMBAT_EVENT_ENRAGED"; break;
		case 41: result.second = "COMBAT_EVENT_STUCKIN"; break;
		case 42: result.second = "COMBAT_EVENT_LATCH_BP"; break;
		case 43: result.second = "COMBAT_EVENT_LATCH_GENERAL"; break;
		case 44: result.second = "COMBAT_EVENT_PROPELLED_AWAY"; break;
		case 45: result.second = "COMBAT_EVENT_KNOCKED_OUT"; break;
		case 46: result.second = "COMBAT_EVENT_STUNNED"; break;
		case 47: result.second = "COMBAT_EVENT_WINDED"; break;
		case 48: result.second = "COMBAT_EVENT_NAUSEATED"; break;
		case 49: result.second = "MIGRANT_ARRIVAL_NAMED"; break;
		case 50: result.second = "MIGRANT_ARRIVAL"; break;
		case 51: result.second = "DIG_CANCEL_WARM"; break;
		case 52: result.second = "DIG_CANCEL_DAMP"; break;
		case 53: result.second = "AMBUSH_DEFENDER"; break;
		case 54: result.second = "AMBUSH_RESIDENT"; break;
		case 55: result.second = "AMBUSH_THIEF"; break;
		case 56: result.second = "AMBUSH_THIEF_SUPPORT_SKULKING"; break;
		case 57: result.second = "AMBUSH_THIEF_SUPPORT_NATURE"; break;
		case 58: result.second = "AMBUSH_THIEF_SUPPORT"; break;
		case 59: result.second = "AMBUSH_MISCHIEVOUS"; break;
		case 60: result.second = "AMBUSH_SNATCHER"; break;
		case 61: result.second = "AMBUSH_SNATCHER_SUPPORT"; break;
		case 62: result.second = "AMBUSH_AMBUSHER_NATURE"; break;
		case 63: result.second = "AMBUSH_AMBUSHER"; break;
		case 64: result.second = "AMBUSH_INJURED"; break;
		case 65: result.second = "AMBUSH_OTHER"; break;
		case 66: result.second = "AMBUSH_INCAPACITATED"; break;
		case 67: result.second = "CARAVAN_ARRIVAL"; break;
		case 68: result.second = "NOBLE_ARRIVAL"; break;
		case 69: result.second = "D_MIGRANTS_ARRIVAL"; break;
		case 70: result.second = "D_MIGRANT_ARRIVAL"; break;
		case 71: result.second = "D_MIGRANT_ARRIVAL_DISCOURAGED"; break;
		case 72: result.second = "D_NO_MIGRANT_ARRIVAL"; break;
		case 73: result.second = "ANIMAL_TRAP_CATCH"; break;
		case 74: result.second = "ANIMAL_TRAP_ROBBED"; break;
		case 75: result.second = "MISCHIEF_LEVER"; break;
		case 76: result.second = "MISCHIEF_PLATE"; break;
		case 77: result.second = "MISCHIEF_CAGE"; break;
		case 78: result.second = "MISCHIEF_CHAIN"; break;
		case 79: result.second = "DIPLOMAT_ARRIVAL"; break;
		case 80: result.second = "LIAISON_ARRIVAL"; break;
		case 81: result.second = "TRADE_DIPLOMAT_ARRIVAL"; break;
		case 82: result.second = "CAVE_COLLAPSE"; break;
		case 83: result.second = "BIRTH_CITIZEN"; break;
		case 84: result.second = "BIRTH_ANIMAL"; break;
		case 85: result.second = "STRANGE_MOOD"; break;
		case 86: result.second = "MADE_ARTIFACT"; break;
		case 87: result.second = "NAMED_ARTIFACT"; break;
		case 88: result.second = "ITEM_ATTACHMENT"; break;
		case 89: result.second = "VERMIN_CAGE_ESCAPE"; break;
		case 90: result.second = "TRIGGER_WEB"; break;
		case 91: result.second = "MOOD_BUILDING_CLAIMED"; break;
		case 92: result.second = "ARTIFACT_BEGUN"; break;
		case 93: result.second = "MEGABEAST_ARRIVAL"; break;
		case 94: result.second = "BERSERK_CITIZEN"; break;
		case 95: result.second = "MAGMA_DEFACES_ENGRAVING"; break;
		case 96: result.second = "ENGRAVING_MELTS"; break;
		case 97: result.second = "MASTERPIECE_ARCHITECTURE"; break;
		case 98: result.second = "MASTERPIECE_CONSTRUCTION"; break;
		case 99: result.second = "MASTER_ARCHITECTURE_LOST"; break;
		case 100: result.second = "MASTER_CONSTRUCTION_LOST"; break;
		case 101: result.second = "ADV_AWAKEN"; break;
		case 102: result.second = "ADV_SLEEP_INTERRUPTED"; break;
		case 103: result.second = "CANCEL_JOB"; break;
		case 104: result.second = "ADV_CREATURE_DEATH"; break;
		case 105: result.second = "CITIZEN_DEATH"; break;
		case 106: result.second = "PET_DEATH"; break;
		case 107: result.second = "ENDGAME_EVENT_1"; break;
		case 108: result.second = "ENDGAME_EVENT_2"; break;
		case 109: result.second = "FALL_OVER"; break;
		case 110: result.second = "CAUGHT_IN_FLAMES"; break;
		case 111: result.second = "CAUGHT_IN_WEB"; break;
		case 112: result.second = "UNIT_PROJECTILE_SLAM_BLOW_APART"; break;
		case 113: result.second = "UNIT_PROJECTILE_SLAM"; break;
		case 114: result.second = "UNIT_PROJECTILE_SLAM_INTO_UNIT"; break;
		case 115: result.second = "VOMIT"; break;
		case 116: result.second = "LOSE_HOLD_OF_ITEM"; break;
		case 117: result.second = "REGAIN_CONSCIOUSNESS"; break;
		case 118: result.second = "FREE_FROM_WEB"; break;
		case 119: result.second = "PARALYZED"; break;
		case 120: result.second = "OVERCOME_PARALYSIS"; break;
		case 121: result.second = "NOT_STUNNED"; break;
		case 122: result.second = "EXHAUSTION"; break;
		case 123: result.second = "PAIN_KO"; break;
		case 124: result.second = "BREAK_GRIP"; break;
		case 125: result.second = "NO_BREAK_GRIP"; break;
		case 126: result.second = "BLOCK_FIRE"; break;
		case 127: result.second = "BREATHE_FIRE"; break;
		case 128: result.second = "SHOOT_WEB"; break;
		case 129: result.second = "PULL_OUT_DROP"; break;
		case 130: result.second = "STAND_UP"; break;
		case 131: result.second = "MARTIAL_TRANCE"; break;
		case 132: result.second = "MAT_BREATH"; break;
		case 133: result.second = "ADV_REACTION_PRODUCTS"; break;
		case 134: result.second = "NIGHT_ATTACK_STARTS"; break;
		case 135: result.second = "NIGHT_ATTACK_ENDS"; break;
		case 136: result.second = "NIGHT_ATTACK_TRAVEL"; break;
		case 137: result.second = "GHOST_ATTACK"; break;
		case 138: result.second = "FLAME_HIT"; break;
		case 139: result.second = "TRAVEL_SITE_DISCOVERY"; break;
		case 140: result.second = "TRAVEL_SITE_BUMP"; break;
		case 141: result.second = "ADVENTURE_INTRO"; break;
		case 142: result.second = "CREATURE_SOUND"; break;
		case 143: result.second = "CREATURE_STEALS_OBJECT"; break;
		case 144: result.second = "FOUND_TRAP"; break;
		case 145: result.second = "BODY_TRANSFORMATION"; break;
		case 146: result.second = "INTERACTION_ACTOR"; break;
		case 147: result.second = "INTERACTION_TARGET"; break;
		case 148: result.second = "UNDEAD_ATTACK"; break;
		case 149: result.second = "CITIZEN_MISSING"; break;
		case 150: result.second = "PET_MISSING"; break;
		case 151: result.second = "EMBRACE"; break;
		case 152: result.second = "STRANGE_RAIN_SNOW"; break;
		case 153: result.second = "STRANGE_CLOUD"; break;
		case 154: result.second = "SIMPLE_ANIMAL_ACTION"; break;
		case 155: result.second = "FLOUNDER_IN_LIQUID"; break;
		case 156: result.second = "TRAINING_DOWN_TO_SEMI_WILD"; break;
		case 157: result.second = "TRAINING_FULL_REVERSION"; break;
		case 158: result.second = "ANIMAL_TRAINING_KNOWLEDGE"; break;
		case 159: result.second = "SKIP_ON_LIQUID"; break;
		case 160: result.second = "DODGE_FLYING_OBJECT"; break;
		case 161: result.second = "REGULAR_CONVERSATION"; break;
		case 162: result.second = "BANDIT_EMPTY_CONTAINER"; break;
		case 163: result.second = "BANDIT_GRAB_ITEM"; break;
		case 164: result.second = "COMBAT_EVENT_ATTACK_INTERRUPTED"; break;
		case 165: result.second = "COMBAT_WRESTLE_CATCH_ATTACK"; break;
		case 166: result.second = "FAIL_TO_GRAB_SURFACE"; break;
		case 167: result.second = "LOSE_HOLD_OF_SURFACE"; break;
		case 168: result.second = "TRAVEL_COMPLAINT"; break;
		case 169: result.second = "LOSE_EMOTION"; break;
		case 170: result.second = "REORGANIZE_POSSESSIONS"; break;
		case 171: result.second = "PUSH_ITEM"; break;
		case 172: result.second = "DRAW_ITEM"; break;
		case 173: result.second = "STRAP_ITEM"; break;
		case 174: result.second = "GAIN_SITE_CONTROL"; break;
		case 175: result.second = "CONFLICT_CONVERSATION"; break;
		case 176: result.second = "FORT_POSITION_SUCCESSION"; break;
		case 177: result.second = "MECHANISM_SOUND"; break;
		case 178: result.second = "BIRTH_WILD_ANIMAL"; break;
		case 179: result.second = "STRESSED_CITIZEN"; break;
		case 180: result.second = "CITIZEN_LOST_TO_STRESS"; break;
		case 181: result.second = "CITIZEN_TANTRUM"; break;
		case 182: result.second = "MOVED_OUT_OF_RANGE"; break;
		case 183: result.second = "CANNOT_JUMP"; break;
		case 184: result.second = "NO_TRACKS"; break;
		case 185: result.second = "ALREADY_SEARCHED_AREA"; break;
		case 186: result.second = "SEARCH_FOUND_SOMETHING"; break;
		case 187: result.second = "SEARCH_FOUND_NOTHING"; break;
		case 188: result.second = "NOTHING_TO_INTERACT"; break;
		case 189: result.second = "NOTHING_TO_EXAMINE"; break;
		case 190: result.second = "YOU_YIELDED"; break;
		case 191: result.second = "YOU_UNYIELDED"; break;
		case 192: result.second = "YOU_STRAP_ITEM"; break;
		case 193: result.second = "YOU_DRAW_ITEM"; break;
		case 194: result.second = "NO_GRASP_TO_DRAW_ITEM"; break;
		case 195: result.second = "NO_ITEM_TO_STRAP"; break;
		case 196: result.second = "NO_INV_TO_REMOVE"; break;
		case 197: result.second = "NO_INV_TO_WEAR"; break;
		case 198: result.second = "NO_INV_TO_EAT"; break;
		case 199: result.second = "NO_INV_TO_CONTAIN"; break;
		case 200: result.second = "NO_INV_TO_DROP"; break;
		case 201: result.second = "NOTHING_TO_PICK_UP"; break;
		case 202: result.second = "NO_INV_TO_THROW"; break;
		case 203: result.second = "NO_INV_TO_FIRE"; break;
		case 204: result.second = "CURRENT_SMELL"; break;
		case 205: result.second = "CURRENT_WEATHER"; break;
		case 206: result.second = "CURRENT_TEMPERATURE"; break;
		case 207: result.second = "CURRENT_DATE"; break;
		case 208: result.second = "NO_GRASP_FOR_PICKUP"; break;
		case 209: result.second = "TRAVEL_ADVISORY"; break;
		case 210: result.second = "CANNOT_CLIMB"; break;
		case 211: result.second = "CANNOT_STAND"; break;
		case 212: result.second = "MUST_UNRETRACT_FIRST"; break;
		case 213: result.second = "CANNOT_REST"; break;
		case 214: result.second = "CANNOT_MAKE_CAMPFIRE"; break;
		case 215: result.second = "MADE_CAMPFIRE"; break;
		case 216: result.second = "CANNOT_SET_FIRE"; break;
		case 217: result.second = "SET_FIRE"; break;
		case 218: result.second = "DAWN_BREAKS"; break;
		case 219: result.second = "NOON"; break;
		case 220: result.second = "NIGHTFALL"; break;
		case 221: result.second = "NO_INV_INTERACTION"; break;
		case 222: result.second = "EMPTY_CONTAINER"; break;
		case 223: result.second = "TAKE_OUT_OF_CONTAINER"; break;
		case 224: result.second = "NO_CONTAINER_FOR_ITEM"; break;
		case 225: result.second = "PUT_INTO_CONTAINER"; break;
		case 226: result.second = "EAT_ITEM"; break;
		case 227: result.second = "DRINK_ITEM"; break;
		case 228: result.second = "CONSUME_FAILURE"; break;
		case 229: result.second = "DROP_ITEM"; break;
		case 230: result.second = "PICK_UP_ITEM"; break;
		case 231: result.second = "YOU_BUILDING_INTERACTION"; break;
		case 232: result.second = "YOU_ITEM_INTERACTION"; break;
		case 233: result.second = "YOU_TEMPERATURE_EFFECTS"; break;
		case 234: result.second = "PROFESSION_CHANGES"; break;
		case 235: result.second = "RECRUIT_PROMOTED"; break;
		case 236: result.second = "SOLDIER_BECOMES_MASTER"; break;
		case 237: result.second = "RESOLVE_SHARED_ITEMS"; break;
		case 238: result.second = "COUGH_BLOOD"; break;
		case 239: result.second = "VOMIT_BLOOD"; break;
		case 240: result.second = "MERCHANTS_UNLOADING"; break;
		case 241: result.second = "MERCHANTS_NEED_DEPOT"; break;
		case 242: result.second = "MERCHANT_WAGONS_BYPASSED"; break;
		case 243: result.second = "MERCHANTS_LEAVING_SOON"; break;
		case 244: result.second = "MERCHANTS_EMBARKED"; break;
		case 245: result.second = "PET_LOSES_DEAD_OWNER"; break;
		case 246: result.second = "PET_ADOPTS_OWNER"; break;
		case 247: result.second = "VERMIN_BITE"; break;
		case 248: result.second = "UNABLE_TO_COMPLETE_BUILDING"; break;
		case 249: result.second = "JOBS_REMOVED_FROM_UNPOWERED_BUILDING"; break;
		case 250: result.second = "CITIZEN_SNATCHED"; break;
		case 251: result.second = "VERMIN_DISTURBED"; break;
		case 252: result.second = "LAND_GAINS_STATUS"; break;
		case 253: result.second = "LAND_ELEVATED_STATUS"; break;
		case 254: result.second = "MASTERPIECE_CRAFTED"; break;
		case 255: result.second = "ARTWORK_DEFACED"; break;
		case 256: result.second = "POWER_LEARNED"; break;
		case 257: result.second = "YOU_FEED_ON_SUCKEE"; break;
		case 258: result.second = "ANIMAL_TRAINED"; break;
		case 259: result.second = "DYED_MASTERPIECE"; break;
		case 260: result.second = "COOKED_MASTERPIECE"; break;
		case 261: result.second = "MANDATE_ENDS"; break;
		case 262: result.second = "SLOWDOWN_ENDS"; break;
		case 263: result.second = "FAREWELL_HELPER"; break;
		case 264: result.second = "ELECTION_RESULTS"; break;
		case 265: result.second = "SITE_PRESENT"; break;
		case 266: result.second = "CONSTRUCTION_SUSPENDED"; break;
		case 267: result.second = "LINKAGE_SUSPENDED"; break;
		case 268: result.second = "QUOTA_FILLED"; break;
		case 269: result.second = "JOB_OVERWRITTEN"; break;
		case 270: result.second = "NOTHING_TO_CATCH_IN_WATER"; break;
		case 271: result.second = "DEMAND_FORGOTTEN"; break;
		case 272: result.second = "NEW_DEMAND"; break;
		case 273: result.second = "NEW_MANDATE"; break;
		case 274: result.second = "PRICES_ALTERED"; break;
		case 275: result.second = "NAMED_RESIDENT_CREATURE"; break;
		case 276: result.second = "SOMEBODY_GROWS_UP"; break;
		case 277: result.second = "GUILD_REQUEST_TAKEN"; break;
		case 278: result.second = "GUILD_WAGES_CHANGED"; break;
		case 279: result.second = "NEW_WORK_MANDATE"; break;
		case 280: result.second = "CITIZEN_BECOMES_SOLDIER"; break;
		case 281: result.second = "CITIZEN_BECOMES_NONSOLDIER"; break;
		case 282: result.second = "PARTY_ORGANIZED"; break;
		case 283: result.second = "POSSESSED_TANTRUM"; break;
		case 284: result.second = "BUILDING_TOPPLED_BY_GHOST"; break;
		case 285: result.second = "MASTERFUL_IMPROVEMENT"; break;
		case 286: result.second = "MASTERPIECE_ENGRAVING"; break;
		case 287: result.second = "MARRIAGE"; break;
		case 288: result.second = "NO_MARRIAGE_CELEBRATION"; break;
		case 289: result.second = "CURIOUS_GUZZLER"; break;
		case 290: result.second = "WEATHER_BECOMES_CLEAR"; break;
		case 291: result.second = "WEATHER_BECOMES_SNOW"; break;
		case 292: result.second = "WEATHER_BECOMES_RAIN"; break;
		case 293: result.second = "SEASON_WET"; break;
		case 294: result.second = "SEASON_DRY"; break;
		case 295: result.second = "SEASON_SPRING"; break;
		case 296: result.second = "SEASON_SUMMER"; break;
		case 297: result.second = "SEASON_AUTUMN"; break;
		case 298: result.second = "SEASON_WINTER"; break;
		case 299: result.second = "GUEST_ARRIVAL"; break;
		case 300: result.second = "CANNOT_SPEAK"; break;
		case 301: result.second = "RESEARCH_BREAKTHROUGH"; break;
		case 302: result.second = "SERVICE_ORDER_DELIVERY"; break;
		case 303: result.second = "PERFORMANCE_START_FAILURE"; break;
		case 304: result.second = "BEGIN_ACTIVITY"; break;
		case 305: result.second = "MIDDLE_OF_ACTIVITY"; break;
		case 306: result.second = "ACTIVITY_SECTION_CHANGE"; break;
		case 307: result.second = "CONCLUDE_ACTIVITY"; break;
		case 308: result.second = "LEARNED_WRITTEN_CONTENT"; break;
		case 309: result.second = "LEARNED_ART_FORM"; break;
		case 310: result.second = "PERFORMER_UPDATE"; break;
		case 311: result.second = "BUILDING_DESTROYED_OR_TOPPLED"; break;
		case 312: result.second = "DEITY_CURSE"; break;
		case 313: result.second = "COMPOSITION_COMPLETE"; break;
		case 314: result.second = "COMPOSITION_FAILED"; break;
		case 315: result.second = "NEW_APPRENTICESHIP"; break;
		case 316: result.second = "PETITION_IGNORED"; break;
		case 317: result.second = "CHOP_TREE"; break;
		case 318: result.second = "CANNOT_CONSTRUCT"; break;
		case 319: result.second = "RUMOR_SPREAD"; break;
		case 320: result.second = "AMBUSH_HERO"; break;
		case 321: result.second = "SERVICE_ORDER_RUMOR_RECEIVED"; break;
		case 322: result.second = "RETURNING_RUMOR_RECEIVED"; break;
		case 323: result.second = "NEW_HOLDING"; break;
		case 324: result.second = "NEW_MARKET_LINK"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_art_image_element_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "CREATURE"; break;
		case 1: result.second = "PLANT"; break;
		case 2: result.second = "TREE"; break;
		case 3: result.second = "SHAPE"; break;
		case 4: result.second = "ITEM"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_art_image_property_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "transitive_verb"; break;
		case 1: result.second = "intransitive_verb"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_art_image_property_verb_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Withering"; break;
		case 1: result.second = "SurroundedBy"; break;
		case 2: result.second = "Massacring"; break;
		case 3: result.second = "Fighting"; break;
		case 4: result.second = "Laboring"; break;
		case 5: result.second = "Greeting"; break;
		case 6: result.second = "Refusing"; break;
		case 7: result.second = "Speaking"; break;
		case 8: result.second = "Embracing"; break;
		case 9: result.second = "StrikingDown"; break;
		case 10: result.second = "MenacingPose"; break;
		case 11: result.second = "Traveling"; break;
		case 12: result.second = "Raising"; break;
		case 13: result.second = "Hiding"; break;
		case 14: result.second = "LookingConfused"; break;
		case 15: result.second = "LookingTerrified"; break;
		case 16: result.second = "Devouring"; break;
		case 17: result.second = "Admiring"; break;
		case 18: result.second = "Burning"; break;
		case 19: result.second = "Weeping"; break;
		case 20: result.second = "LookingDejected"; break;
		case 21: result.second = "Cringing"; break;
		case 22: result.second = "Screaming"; break;
		case 23: result.second = "SubmissiveGesture"; break;
		case 24: result.second = "FetalPosition"; break;
		case 25: result.second = "SmearedIntoSpiral"; break;
		case 26: result.second = "Falling"; break;
		case 27: result.second = "Dead"; break;
		case 28: result.second = "Laughing"; break;
		case 29: result.second = "LookingOffended"; break;
		case 30: result.second = "BeingShot"; break;
		case 31: result.second = "PlaintiveGesture"; break;
		case 32: result.second = "Melting"; break;
		case 33: result.second = "Shooting"; break;
		case 34: result.second = "Torturing"; break;
		case 35: result.second = "CommittingDepravedAct"; break;
		case 36: result.second = "Praying"; break;
		case 37: result.second = "Contemplating"; break;
		case 38: result.second = "Cooking"; break;
		case 39: result.second = "Engraving"; break;
		case 40: result.second = "Prostrating"; break;
		case 41: result.second = "Suffering"; break;
		case 42: result.second = "BeingImpaled"; break;
		case 43: result.second = "BeingContorted"; break;
		case 44: result.second = "BeingFlayed"; break;
		case 45: result.second = "HangingFrom"; break;
		case 46: result.second = "BeingMutilated"; break;
		case 47: result.second = "TriumphantPose"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_art_facet_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "OWN_RACE"; break;
		case 1: result.second = "FANCIFUL"; break;
		case 2: result.second = "GOOD"; break;
		case 3: result.second = "EVIL"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_poetic_form_action_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Describe"; break;
		case 1: result.second = "Satirize"; break;
		case 2: result.second = "AmuseAudience"; break;
		case 3: result.second = "Complain"; break;
		case 4: result.second = "Renounce"; break;
		case 5: result.second = "MakeApology"; break;
		case 6: result.second = "ExpressPleasure"; break;
		case 7: result.second = "ExpressGrief"; break;
		case 8: result.second = "Praise"; break;
		case 9: result.second = "TeachMoralLesson"; break;
		case 10: result.second = "MakeAssertion"; break;
		case 11: result.second = "MakeCounterAssertion"; break;
		case 12: result.second = "MakeConsession"; break;
		case 13: result.second = "SynthesizePreviousIdeas"; break;
		case 14: result.second = "DevelopPreviousIdea"; break;
		case 15: result.second = "InvertTheAssertion"; break;
		case 16: result.second = "UndercutAssertion"; break;
		case 17: result.second = "MoveAwayFromPreviousIdeas"; break;
		case 18: result.second = "ReflectPreviousIdeas"; break;
		case 19: result.second = "ConsoleAudience"; break;
		case 20: result.second = "RefuseConsolation"; break;
		case 21: result.second = "OfferDifferentPerspective"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_poetic_form_pattern_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "AA"; break;
		case 1: result.second = "AB"; break;
		case 2: result.second = "BA"; break;
		case 3: result.second = "BB"; break;
		case 4: result.second = "AAA"; break;
		case 5: result.second = "BAA"; break;
		case 6: result.second = "ABA"; break;
		case 7: result.second = "AAB"; break;
		case 8: result.second = "ABB"; break;
		case 9: result.second = "BBA"; break;
		case 10: result.second = "BAB"; break;
		case 11: result.second = "BBB"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_poetic_form_caesura_position_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Initial"; break;
		case 1: result.second = "Medial"; break;
		case 2: result.second = "Terminal"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_poetic_form_mood_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Narrative"; break;
		case 1: result.second = "Dramatic"; break;
		case 2: result.second = "Reflective"; break;
		case 3: result.second = "Riddle"; break;
		case 4: result.second = "Ribald"; break;
		case 5: result.second = "Light"; break;
		case 6: result.second = "Solemn"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_poetic_form_subject_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Past"; break;
		case 1: result.second = "CurrentEvents"; break;
		case 2: result.second = "Future"; break;
		case 3: result.second = "SomeoneRecentlyDeceased"; break;
		case 4: result.second = "SomeoneRecentlyRetired"; break;
		case 5: result.second = "Religion"; break;
		case 6: result.second = "SpecificPlace"; break;
		case 7: result.second = "SpecificWildernessRegion"; break;
		case 8: result.second = "Nature"; break;
		case 9: result.second = "Lover"; break;
		case 10: result.second = "Family"; break;
		case 11: result.second = "AlcoholicBeverages"; break;
		case 12: result.second = "Journey"; break;
		case 13: result.second = "War"; break;
		case 14: result.second = "Hunt"; break;
		case 15: result.second = "Mining"; break;
		case 16: result.second = "Death"; break;
		case 17: result.second = "Immortality"; break;
		case 18: result.second = "SomeonesCharacter"; break;
		case 19: result.second = "Histfig"; break;
		case 20: result.second = "Concept"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_poetic_form_additional_feature_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SharesUnderlyingMeaning"; break;
		case 1: result.second = "ContrastsUnderlyingMeaning"; break;
		case 2: result.second = "RequiredToMaintainPhrasing"; break;
		case 3: result.second = "SameGrammaticalStructure"; break;
		case 4: result.second = "SamePlacementOfAllusions"; break;
		case 5: result.second = "ReverseWordOrder"; break;
		case 6: result.second = "ReverseGrammaticalStructure"; break;
		case 7: result.second = "PresentsDifferentView"; break;
		case 8: result.second = "MustExpandIdea"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_poetic_form_perspective__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Author"; break;
		case 1: result.second = "Soldier"; break;
		case 2: result.second = "Traveller"; break;
		case 3: result.second = "RelativeOfAuthor"; break;
		case 4: result.second = "PartyOfDebate"; break;
		case 5: result.second = "FictionalPoet"; break;
		case 6: result.second = "Histfig"; break;
		case 7: result.second = "Animal"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_occupation_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TAVERN_KEEPER"; break;
		case 1: result.second = "PERFORMER"; break;
		case 2: result.second = "SCHOLAR"; break;
		case 3: result.second = "MERCENARY"; break;
		case 4: result.second = "MONSTER_SLAYER"; break;
		case 5: result.second = "SCRIBE"; break;
		case 6: result.second = "MESSENGER"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_buildings_other_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "ANY"; break;
		case 0: result.second = "IN_PLAY"; break;
		case 1: result.second = "LOCATION_ASSIGNED"; break;
		case 2: result.second = "STOCKPILE"; break;
		case 3: result.second = "ANY_ZONE"; break;
		case 4: result.second = "ACTIVITY_ZONE"; break;
		case 5: result.second = "ANY_ACTUAL"; break;
		case 6: result.second = "ANY_MACHINE"; break;
		case 7: result.second = "ANY_HOSPITAL_STORAGE"; break;
		case 8: result.second = "ANY_STORAGE"; break;
		case 9: result.second = "ANY_BARRACKS"; break;
		case 10: result.second = "ANY_NOBLE_ROOM"; break;
		case 11: result.second = "ANY_HOSPITAL"; break;
		case 12: result.second = "BOX"; break;
		case 13: result.second = "CABINET"; break;
		case 14: result.second = "TRAP"; break;
		case 15: result.second = "DOOR"; break;
		case 16: result.second = "FLOODGATE"; break;
		case 17: result.second = "HATCH"; break;
		case 18: result.second = "GRATE_WALL"; break;
		case 19: result.second = "GRATE_FLOOR"; break;
		case 20: result.second = "BARS_VERTICAL"; break;
		case 21: result.second = "BARS_FLOOR"; break;
		case 22: result.second = "WINDOW_ANY"; break;
		case 23: result.second = "WELL"; break;
		case 24: result.second = "TABLE"; break;
		case 25: result.second = "BRIDGE"; break;
		case 26: result.second = "CHAIR"; break;
		case 27: result.second = "TRADE_DEPOT"; break;
		case 28: result.second = "NEST"; break;
		case 29: result.second = "NEST_BOX"; break;
		case 30: result.second = "BOOKCASE"; break;
		case 31: result.second = "DISPLAY_CASE"; break;
		case 32: result.second = "HIVE"; break;
		case 33: result.second = "WAGON"; break;
		case 34: result.second = "SHOP"; break;
		case 35: result.second = "BED"; break;
		case 36: result.second = "TRACTION_BENCH"; break;
		case 37: result.second = "ANY_ROAD"; break;
		case 38: result.second = "FARM_PLOT"; break;
		case 39: result.second = "GEAR_ASSEMBLY"; break;
		case 40: result.second = "ROLLERS"; break;
		case 41: result.second = "AXLE_HORIZONTAL"; break;
		case 42: result.second = "AXLE_VERTICAL"; break;
		case 43: result.second = "SUPPORT"; break;
		case 44: result.second = "ARCHERY_TARGET"; break;
		case 45: result.second = "SCREW_PUMP"; break;
		case 46: result.second = "WATER_WHEEL"; break;
		case 47: result.second = "WINDMILL"; break;
		case 48: result.second = "CHAIN"; break;
		case 49: result.second = "CAGE"; break;
		case 50: result.second = "STATUE"; break;
		case 51: result.second = "SLAB"; break;
		case 52: result.second = "COFFIN"; break;
		case 53: result.second = "WEAPON_RACK"; break;
		case 54: result.second = "ARMOR_STAND"; break;
		case 55: result.second = "FURNACE_ANY"; break;
		case 56: result.second = "FURNACE_WOOD"; break;
		case 57: result.second = "FURNACE_SMELTER_ANY"; break;
		case 58: result.second = "FURNACE_SMELTER_MAGMA"; break;
		case 59: result.second = "FURNACE_KILN_ANY"; break;
		case 60: result.second = "FURNACE_GLASS_ANY"; break;
		case 61: result.second = "FURNACE_CUSTOM"; break;
		case 62: result.second = "WORKSHOP_ANY"; break;
		case 63: result.second = "WORKSHOP_BUTCHER"; break;
		case 64: result.second = "WORKSHOP_MASON"; break;
		case 65: result.second = "WORKSHOP_KENNEL"; break;
		case 66: result.second = "WORKSHOP_FISHERY"; break;
		case 67: result.second = "WORKSHOP_JEWELER"; break;
		case 68: result.second = "WORKSHOP_LOOM"; break;
		case 69: result.second = "WORKSHOP_TANNER"; break;
		case 70: result.second = "WORKSHOP_DYER"; break;
		case 71: result.second = "WORKSHOP_MILL_ANY"; break;
		case 72: result.second = "WORKSHOP_QUERN"; break;
		case 73: result.second = "WORKSHOP_TOOL"; break;
		case 74: result.second = "WORKSHOP_MILLSTONE"; break;
		case 75: result.second = "WORKSHOP_KITCHEN"; break;
		case 76: result.second = "WORKSHOP_STILL"; break;
		case 77: result.second = "WORKSHOP_FARMER"; break;
		case 78: result.second = "WORKSHOP_ASHERY"; break;
		case 79: result.second = "WORKSHOP_CARPENTER"; break;
		case 80: result.second = "WORKSHOP_CRAFTSDWARF"; break;
		case 81: result.second = "WORKSHOP_MECHANIC"; break;
		case 82: result.second = "WORKSHOP_SIEGE"; break;
		case 83: result.second = "WORKSHOP_CLOTHIER"; break;
		case 84: result.second = "WORKSHOP_LEATHER"; break;
		case 85: result.second = "WORKSHOP_BOWYER"; break;
		case 86: result.second = "WORKSHOP_MAGMA_FORGE"; break;
		case 87: result.second = "WORKSHOP_FORGE_ANY"; break;
		case 88: result.second = "WORKSHOP_CUSTOM"; break;
		case 89: result.second = "WEAPON_UPRIGHT"; break;
		case 90: result.second = "INSTRUMENT_STATIONARY"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_building_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "Chair"; break;
		case 1: result.second = "Bed"; break;
		case 2: result.second = "Table"; break;
		case 3: result.second = "Coffin"; break;
		case 4: result.second = "FarmPlot"; break;
		case 5: result.second = "Furnace"; break;
		case 6: result.second = "TradeDepot"; break;
		case 7: result.second = "Shop"; break;
		case 8: result.second = "Door"; break;
		case 9: result.second = "Floodgate"; break;
		case 10: result.second = "Box"; break;
		case 11: result.second = "Weaponrack"; break;
		case 12: result.second = "Armorstand"; break;
		case 13: result.second = "Workshop"; break;
		case 14: result.second = "Cabinet"; break;
		case 15: result.second = "Statue"; break;
		case 16: result.second = "WindowGlass"; break;
		case 17: result.second = "WindowGem"; break;
		case 18: result.second = "Well"; break;
		case 19: result.second = "Bridge"; break;
		case 20: result.second = "RoadDirt"; break;
		case 21: result.second = "RoadPaved"; break;
		case 22: result.second = "SiegeEngine"; break;
		case 23: result.second = "Trap"; break;
		case 24: result.second = "AnimalTrap"; break;
		case 25: result.second = "Support"; break;
		case 26: result.second = "ArcheryTarget"; break;
		case 27: result.second = "Chain"; break;
		case 28: result.second = "Cage"; break;
		case 29: result.second = "Stockpile"; break;
		case 30: result.second = "Civzone"; break;
		case 31: result.second = "Weapon"; break;
		case 32: result.second = "Wagon"; break;
		case 33: result.second = "ScrewPump"; break;
		case 34: result.second = "Construction"; break;
		case 35: result.second = "Hatch"; break;
		case 36: result.second = "GrateWall"; break;
		case 37: result.second = "GrateFloor"; break;
		case 38: result.second = "BarsVertical"; break;
		case 39: result.second = "BarsFloor"; break;
		case 40: result.second = "GearAssembly"; break;
		case 41: result.second = "AxleHorizontal"; break;
		case 42: result.second = "AxleVertical"; break;
		case 43: result.second = "WaterWheel"; break;
		case 44: result.second = "Windmill"; break;
		case 45: result.second = "TractionBench"; break;
		case 46: result.second = "Slab"; break;
		case 47: result.second = "Nest"; break;
		case 48: result.second = "NestBox"; break;
		case 49: result.second = "Hive"; break;
		case 50: result.second = "Rollers"; break;
		case 51: result.second = "Instrument"; break;
		case 52: result.second = "Bookcase"; break;
		case 53: result.second = "DisplayFurniture"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_civzone_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Home"; break;
		case 1: result.second = "Depot"; break;
		case 2: result.second = "Stockpile"; break;
		case 3: result.second = "NobleQuarters"; break;
		case 4: result.second = "anon_1"; break;
		case 5: result.second = "anon_2"; break;
		case 6: result.second = "anon_3"; break;
		case 7: result.second = "MeadHall"; break;
		case 8: result.second = "ThroneRoom"; break;
		case 9: result.second = "ActivityZone"; break;
		case 10: result.second = "Temple"; break;
		case 11: result.second = "Kitchen"; break;
		case 12: result.second = "CaptiveRoom"; break;
		case 13: result.second = "TowerTop"; break;
		case 14: result.second = "Courtyard"; break;
		case 15: result.second = "Treasury"; break;
		case 16: result.second = "GuardPost"; break;
		case 17: result.second = "Entrance"; break;
		case 18: result.second = "SecretLibrary"; break;
		case 19: result.second = "Library"; break;
		case 20: result.second = "Plot"; break;
		case 21: result.second = "MarketStall"; break;
		case 22: result.second = "anon_4"; break;
		case 23: result.second = "Campground"; break;
		case 24: result.second = "CommandTent"; break;
		case 25: result.second = "Tent"; break;
		case 26: result.second = "CommandTentBld"; break;
		case 27: result.second = "TentBld"; break;
		case 28: result.second = "MechanismRoom"; break;
		case 29: result.second = "DungeonCell"; break;
		case 30: result.second = "AnimalPit"; break;
		case 31: result.second = "ClothPit"; break;
		case 32: result.second = "TanningPit"; break;
		case 33: result.second = "ClothClothingPit"; break;
		case 34: result.second = "LeatherClothingPit"; break;
		case 35: result.second = "BoneCarvingPit"; break;
		case 36: result.second = "GemCuttingPit"; break;
		case 37: result.second = "WeaponsmithingPit"; break;
		case 38: result.second = "BowmakingPit"; break;
		case 39: result.second = "BlacksmithingPit"; break;
		case 40: result.second = "ArmorsmithingPit"; break;
		case 41: result.second = "MetalCraftingPit"; break;
		case 42: result.second = "LeatherworkingPit"; break;
		case 43: result.second = "CarpentryPit"; break;
		case 44: result.second = "StoneworkingPit"; break;
		case 45: result.second = "ForgingPit"; break;
		case 46: result.second = "FightingPit"; break;
		case 47: result.second = "anon_5"; break;
		case 48: result.second = "anon_6"; break;
		case 49: result.second = "anon_7"; break;
		case 50: result.second = "anon_8"; break;
		case 51: result.second = "anon_9"; break;
		case 52: result.second = "anon_10"; break;
		case 53: result.second = "AnimalWorkshop"; break;
		case 54: result.second = "ClothWorkshop"; break;
		case 55: result.second = "TanningWorkshop"; break;
		case 56: result.second = "ClothClothingWorkshop"; break;
		case 57: result.second = "LeatherClothingWorkshop"; break;
		case 58: result.second = "BoneCarvingWorkshop"; break;
		case 59: result.second = "GemCuttingWorkshop"; break;
		case 60: result.second = "WeaponsmithingWorkshop"; break;
		case 61: result.second = "BowmakingWorkshop"; break;
		case 62: result.second = "BlacksmithingWorkshop"; break;
		case 63: result.second = "ArmorsmithingWorkshop"; break;
		case 64: result.second = "MetalCraftingWorkshop"; break;
		case 65: result.second = "LeatherworkingShop"; break;
		case 66: result.second = "CarpentryWorkshop"; break;
		case 67: result.second = "StoneworkingWorkshop"; break;
		case 68: result.second = "ForgingWorkshop"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_furnace_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "WoodFurnace"; break;
		case 1: result.second = "Smelter"; break;
		case 2: result.second = "GlassFurnace"; break;
		case 3: result.second = "Kiln"; break;
		case 4: result.second = "MagmaSmelter"; break;
		case 5: result.second = "MagmaGlassFurnace"; break;
		case 6: result.second = "MagmaKiln"; break;
		case 7: result.second = "Custom"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_workshop_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Carpenters"; break;
		case 1: result.second = "Farmers"; break;
		case 2: result.second = "Masons"; break;
		case 3: result.second = "Craftsdwarfs"; break;
		case 4: result.second = "Jewelers"; break;
		case 5: result.second = "MetalsmithsForge"; break;
		case 6: result.second = "MagmaForge"; break;
		case 7: result.second = "Bowyers"; break;
		case 8: result.second = "Mechanics"; break;
		case 9: result.second = "Siege"; break;
		case 10: result.second = "Butchers"; break;
		case 11: result.second = "Leatherworks"; break;
		case 12: result.second = "Tanners"; break;
		case 13: result.second = "Clothiers"; break;
		case 14: result.second = "Fishery"; break;
		case 15: result.second = "Still"; break;
		case 16: result.second = "Loom"; break;
		case 17: result.second = "Quern"; break;
		case 18: result.second = "Kennels"; break;
		case 19: result.second = "Kitchen"; break;
		case 20: result.second = "Ashery"; break;
		case 21: result.second = "Dyers"; break;
		case 22: result.second = "Millstone"; break;
		case 23: result.second = "Custom"; break;
		case 24: result.second = "Tool"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_construction_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "Fortification"; break;
		case 1: result.second = "Wall"; break;
		case 2: result.second = "Floor"; break;
		case 3: result.second = "UpStair"; break;
		case 4: result.second = "DownStair"; break;
		case 5: result.second = "UpDownStair"; break;
		case 6: result.second = "Ramp"; break;
		case 7: result.second = "TrackN"; break;
		case 8: result.second = "TrackS"; break;
		case 9: result.second = "TrackE"; break;
		case 10: result.second = "TrackW"; break;
		case 11: result.second = "TrackNS"; break;
		case 12: result.second = "TrackNE"; break;
		case 13: result.second = "TrackNW"; break;
		case 14: result.second = "TrackSE"; break;
		case 15: result.second = "TrackSW"; break;
		case 16: result.second = "TrackEW"; break;
		case 17: result.second = "TrackNSE"; break;
		case 18: result.second = "TrackNSW"; break;
		case 19: result.second = "TrackNEW"; break;
		case 20: result.second = "TrackSEW"; break;
		case 21: result.second = "TrackNSEW"; break;
		case 22: result.second = "TrackRampN"; break;
		case 23: result.second = "TrackRampS"; break;
		case 24: result.second = "TrackRampE"; break;
		case 25: result.second = "TrackRampW"; break;
		case 26: result.second = "TrackRampNS"; break;
		case 27: result.second = "TrackRampNE"; break;
		case 28: result.second = "TrackRampNW"; break;
		case 29: result.second = "TrackRampSE"; break;
		case 30: result.second = "TrackRampSW"; break;
		case 31: result.second = "TrackRampEW"; break;
		case 32: result.second = "TrackRampNSE"; break;
		case 33: result.second = "TrackRampNSW"; break;
		case 34: result.second = "TrackRampNEW"; break;
		case 35: result.second = "TrackRampSEW"; break;
		case 36: result.second = "TrackRampNSEW"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_shop_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "GeneralStore"; break;
		case 1: result.second = "CraftsMarket"; break;
		case 2: result.second = "ClothingShop"; break;
		case 3: result.second = "ExoticClothingShop"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_siegeengine_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Catapult"; break;
		case 1: result.second = "Ballista"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_trap_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Lever"; break;
		case 1: result.second = "PressurePlate"; break;
		case 2: result.second = "CageTrap"; break;
		case 3: result.second = "StoneFallTrap"; break;
		case 4: result.second = "WeaponTrap"; break;
		case 5: result.second = "TrackStop"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_dfhack_room_quality_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Meager"; break;
		case 1: result.second = "Modest"; break;
		case 2: result.second = "Normal"; break;
		case 3: result.second = "Decent"; break;
		case 4: result.second = "Fine"; break;
		case 5: result.second = "Great"; break;
		case 6: result.second = "Grand"; break;
		case 7: result.second = "Royal"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_creature_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "unk_wagon"; break;
		case 1: result.second = "EQUIPMENT_WAGON"; break;
		case 2: result.second = "MUNDANE"; break;
		case 3: result.second = "VERMIN_EATER"; break;
		case 4: result.second = "VERMIN_GROUNDER"; break;
		case 5: result.second = "VERMIN_ROTTER"; break;
		case 6: result.second = "VERMIN_SOIL"; break;
		case 7: result.second = "VERMIN_SOIL_COLONY"; break;
		case 8: result.second = "LARGE_ROAMING"; break;
		case 9: result.second = "VERMIN_FISH"; break;
		case 10: result.second = "LOOSE_CLUSTERS"; break;
		case 11: result.second = "FANCIFUL"; break;
		case 12: result.second = "BIOME_MOUNTAIN"; break;
		case 13: result.second = "BIOME_GLACIER"; break;
		case 14: result.second = "BIOME_TUNDRA"; break;
		case 15: result.second = "BIOME_SWAMP_TEMPERATE_FRESHWATER"; break;
		case 16: result.second = "BIOME_SWAMP_TEMPERATE_SALTWATER"; break;
		case 17: result.second = "BIOME_MARSH_TEMPERATE_FRESHWATER"; break;
		case 18: result.second = "BIOME_MARSH_TEMPERATE_SALTWATER"; break;
		case 19: result.second = "BIOME_SWAMP_TROPICAL_FRESHWATER"; break;
		case 20: result.second = "BIOME_SWAMP_TROPICAL_SALTWATER"; break;
		case 21: result.second = "BIOME_SWAMP_MANGROVE"; break;
		case 22: result.second = "BIOME_MARSH_TROPICAL_FRESHWATER"; break;
		case 23: result.second = "BIOME_MARSH_TROPICAL_SALTWATER"; break;
		case 24: result.second = "BIOME_FOREST_TAIGA"; break;
		case 25: result.second = "BIOME_FOREST_TEMPERATE_CONIFER"; break;
		case 26: result.second = "BIOME_FOREST_TEMPERATE_BROADLEAF"; break;
		case 27: result.second = "BIOME_FOREST_TROPICAL_CONIFER"; break;
		case 28: result.second = "BIOME_FOREST_TROPICAL_DRY_BROADLEAF"; break;
		case 29: result.second = "BIOME_FOREST_TROPICAL_MOIST_BROADLEAF"; break;
		case 30: result.second = "BIOME_GRASSLAND_TEMPERATE"; break;
		case 31: result.second = "BIOME_SAVANNA_TEMPERATE"; break;
		case 32: result.second = "BIOME_SHRUBLAND_TEMPERATE"; break;
		case 33: result.second = "BIOME_GRASSLAND_TROPICAL"; break;
		case 34: result.second = "BIOME_SAVANNA_TROPICAL"; break;
		case 35: result.second = "BIOME_SHRUBLAND_TROPICAL"; break;
		case 36: result.second = "BIOME_DESERT_BADLAND"; break;
		case 37: result.second = "BIOME_DESERT_ROCK"; break;
		case 38: result.second = "BIOME_DESERT_SAND"; break;
		case 39: result.second = "BIOME_OCEAN_TROPICAL"; break;
		case 40: result.second = "BIOME_OCEAN_TEMPERATE"; break;
		case 41: result.second = "BIOME_OCEAN_ARCTIC"; break;
		case 42: result.second = "BIOME_SUBTERRANEAN_WATER"; break;
		case 43: result.second = "BIOME_SUBTERRANEAN_CHASM"; break;
		case 44: result.second = "BIOME_SUBTERRANEAN_LAVA"; break;
		case 45: result.second = "BIOME_POOL_TEMPERATE_FRESHWATER"; break;
		case 46: result.second = "BIOME_POOL_TEMPERATE_BRACKISHWATER"; break;
		case 47: result.second = "BIOME_POOL_TEMPERATE_SALTWATER"; break;
		case 48: result.second = "BIOME_POOL_TROPICAL_FRESHWATER"; break;
		case 49: result.second = "BIOME_POOL_TROPICAL_BRACKISHWATER"; break;
		case 50: result.second = "BIOME_POOL_TROPICAL_SALTWATER"; break;
		case 51: result.second = "BIOME_LAKE_TEMPERATE_FRESHWATER"; break;
		case 52: result.second = "BIOME_LAKE_TEMPERATE_BRACKISHWATER"; break;
		case 53: result.second = "BIOME_LAKE_TEMPERATE_SALTWATER"; break;
		case 54: result.second = "BIOME_LAKE_TROPICAL_FRESHWATER"; break;
		case 55: result.second = "BIOME_LAKE_TROPICAL_BRACKISHWATER"; break;
		case 56: result.second = "BIOME_LAKE_TROPICAL_SALTWATER"; break;
		case 57: result.second = "BIOME_RIVER_TEMPERATE_FRESHWATER"; break;
		case 58: result.second = "BIOME_RIVER_TEMPERATE_BRACKISHWATER"; break;
		case 59: result.second = "BIOME_RIVER_TEMPERATE_SALTWATER"; break;
		case 60: result.second = "BIOME_RIVER_TROPICAL_FRESHWATER"; break;
		case 61: result.second = "BIOME_RIVER_TROPICAL_BRACKISHWATER"; break;
		case 62: result.second = "BIOME_RIVER_TROPICAL_SALTWATER"; break;
		case 63: result.second = "GOOD"; break;
		case 64: result.second = "EVIL"; break;
		case 65: result.second = "SAVAGE"; break;
		case 66: result.second = "NOT_ASEXUAL"; break;
		case 67: result.second = "unk_43"; break;
		case 68: result.second = "unk_44"; break;
		case 69: result.second = "unk_45"; break;
		case 70: result.second = "any_vermin"; break;
		case 71: result.second = "CASTE_CAN_LEARN"; break;
		case 72: result.second = "CASTE_VERMIN_HATEABLE"; break;
		case 73: result.second = "unk_49"; break;
		case 74: result.second = "CASTE_LARGE_PREDATOR"; break;
		case 75: result.second = "CASTE_CURIOUSBEAST"; break;
		case 76: result.second = "CASTE_BENIGN"; break;
		case 77: result.second = "CASTE_NATURAL"; break;
		case 78: result.second = "CASTE_MEGABEAST"; break;
		case 79: result.second = "CASTE_SEMIMEGABEAST"; break;
		case 80: result.second = "CASTE_POWER"; break;
		case 81: result.second = "CASTE_VERMIN_MICRO"; break;
		case 82: result.second = "CASTE_NOT_FIREIMMUNE"; break;
		case 83: result.second = "CASTE_MUST_BREATHE_AIR"; break;
		case 84: result.second = "CASTE_MUST_BREATHE_WATER"; break;
		case 85: result.second = "unk_55"; break;
		case 86: result.second = "CASTE_SWIMS_LEARNED"; break;
		case 87: result.second = "CASTE_COMMON_DOMESTIC"; break;
		case 88: result.second = "CASTE_UTTERANCES"; break;
		case 89: result.second = "CASTE_CAN_SPEAK"; break;
		case 90: result.second = "CASTE_FEATURE_BEAST"; break;
		case 91: result.second = "GENERATED"; break;
		case 92: result.second = "CASTE_TITAN"; break;
		case 93: result.second = "CASTE_UNIQUE_DEMON"; break;
		case 94: result.second = "DOES_NOT_EXIST"; break;
		case 95: result.second = "CASTE_NOT_LIVING"; break;
		case 96: result.second = "CASTE_MISCHIEVOUS"; break;
		case 97: result.second = "CASTE_FLIER"; break;
		case 98: result.second = "CASTE_DEMON"; break;
		case 99: result.second = "CASTE_NIGHT_CREATURE_ANY"; break;
		case 100: result.second = "CASTE_NIGHT_CREATURE_HUNTER"; break;
		case 101: result.second = "CASTE_NIGHT_CREATURE_BOGEYMAN"; break;
		case 102: result.second = "CASTE_CARNIVORE"; break;
		case 103: result.second = "ARTIFICIAL_HIVEABLE"; break;
		case 104: result.second = "UBIQUITOUS"; break;
		case 105: result.second = "unk_69"; break;
		case 106: result.second = "CASTE_SUPERNATURAL"; break;
		case 107: result.second = "CASTE_BLOOD"; break;
		case 108: result.second = "CASTE_GRAZER"; break;
		case 109: result.second = "CASTE_unk_31"; break;
		case 110: result.second = "unk_6e"; break;
		case 111: result.second = "unk_6f"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_caste_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "AMPHIBIOUS"; break;
		case 1: result.second = "AQUATIC"; break;
		case 2: result.second = "LOCKPICKER"; break;
		case 3: result.second = "MISCHIEVOUS"; break;
		case 4: result.second = "PATTERNFLIER"; break;
		case 5: result.second = "CURIOUSBEAST_ANY"; break;
		case 6: result.second = "CURIOUSBEAST_ITEM"; break;
		case 7: result.second = "CURIOUSBEAST_GUZZLER"; break;
		case 8: result.second = "FLEEQUICK"; break;
		case 9: result.second = "AT_PEACE_WITH_WILDLIFE"; break;
		case 10: result.second = "SWIMS_LEARNED"; break;
		case 11: result.second = "OPPOSED_TO_LIFE"; break;
		case 12: result.second = "CURIOUSBEAST_EATER"; break;
		case 13: result.second = "NO_EAT"; break;
		case 14: result.second = "NO_DRINK"; break;
		case 15: result.second = "NO_SLEEP"; break;
		case 16: result.second = "COMMON_DOMESTIC"; break;
		case 17: result.second = "WAGON_PULLER"; break;
		case 18: result.second = "PACK_ANIMAL"; break;
		case 19: result.second = "FLIER"; break;
		case 20: result.second = "LARGE_PREDATOR"; break;
		case 21: result.second = "MAGMA_VISION"; break;
		case 22: result.second = "FIREIMMUNE"; break;
		case 23: result.second = "FIREIMMUNE_SUPER"; break;
		case 24: result.second = "WEBBER"; break;
		case 25: result.second = "WEBIMMUNE"; break;
		case 26: result.second = "FISHITEM"; break;
		case 27: result.second = "IMMOBILE_LAND"; break;
		case 28: result.second = "IMMOLATE"; break;
		case 29: result.second = "MILKABLE"; break;
		case 30: result.second = "NO_SPRING"; break;
		case 31: result.second = "NO_SUMMER"; break;
		case 32: result.second = "NO_AUTUMN"; break;
		case 33: result.second = "NO_WINTER"; break;
		case 34: result.second = "BENIGN"; break;
		case 35: result.second = "VERMIN_NOROAM"; break;
		case 36: result.second = "VERMIN_NOTRAP"; break;
		case 37: result.second = "VERMIN_NOFISH"; break;
		case 38: result.second = "HAS_NERVES"; break;
		case 39: result.second = "NO_DIZZINESS"; break;
		case 40: result.second = "NO_FEVERS"; break;
		case 41: result.second = "NO_UNIT_TYPE_COLOR"; break;
		case 42: result.second = "NO_CONNECTIONS_FOR_MOVEMENT"; break;
		case 43: result.second = "SUPERNATURAL"; break;
		case 44: result.second = "AMBUSHPREDATOR"; break;
		case 45: result.second = "GNAWER"; break;
		case 46: result.second = "NOT_BUTCHERABLE"; break;
		case 47: result.second = "COOKABLE_LIVE"; break;
		case 48: result.second = "SECRETION"; break;
		case 49: result.second = "IMMOBILE"; break;
		case 50: result.second = "MULTIPART_FULL_VISION"; break;
		case 51: result.second = "MEANDERER"; break;
		case 52: result.second = "THICKWEB"; break;
		case 53: result.second = "TRAINABLE_HUNTING"; break;
		case 54: result.second = "PET"; break;
		case 55: result.second = "PET_EXOTIC"; break;
		case 56: result.second = "unk_38"; break;
		case 57: result.second = "CAN_SPEAK"; break;
		case 58: result.second = "CAN_LEARN"; break;
		case 59: result.second = "UTTERANCES"; break;
		case 60: result.second = "BONECARN"; break;
		case 61: result.second = "CARNIVORE"; break;
		case 62: result.second = "UNDERSWIM"; break;
		case 63: result.second = "NOEXERT"; break;
		case 64: result.second = "NOPAIN"; break;
		case 65: result.second = "EXTRAVISION"; break;
		case 66: result.second = "NOBREATHE"; break;
		case 67: result.second = "NOSTUN"; break;
		case 68: result.second = "NONAUSEA"; break;
		case 69: result.second = "BLOOD"; break;
		case 70: result.second = "TRANCES"; break;
		case 71: result.second = "NOEMOTION"; break;
		case 72: result.second = "SLOW_LEARNER"; break;
		case 73: result.second = "NOSTUCKINS"; break;
		case 74: result.second = "PUS"; break;
		case 75: result.second = "NOSKULL"; break;
		case 76: result.second = "NOSKIN"; break;
		case 77: result.second = "NOBONES"; break;
		case 78: result.second = "NOMEAT"; break;
		case 79: result.second = "PARALYZEIMMUNE"; break;
		case 80: result.second = "NOFEAR"; break;
		case 81: result.second = "CANOPENDOORS"; break;
		case 82: result.second = "ITEMCORPSE"; break;
		case 83: result.second = "GETS_WOUND_INFECTIONS"; break;
		case 84: result.second = "NOSMELLYROT"; break;
		case 85: result.second = "REMAINS_UNDETERMINED"; break;
		case 86: result.second = "HASSHELL"; break;
		case 87: result.second = "PEARL"; break;
		case 88: result.second = "TRAINABLE_WAR"; break;
		case 89: result.second = "NO_THOUGHT_CENTER_FOR_MOVEMENT"; break;
		case 90: result.second = "ARENA_RESTRICTED"; break;
		case 91: result.second = "LAIR_HUNTER"; break;
		case 92: result.second = "LIKES_FIGHTING"; break;
		case 93: result.second = "VERMIN_HATEABLE"; break;
		case 94: result.second = "VEGETATION"; break;
		case 95: result.second = "MAGICAL"; break;
		case 96: result.second = "NATURAL"; break;
		case 97: result.second = "BABY"; break;
		case 98: result.second = "CHILD"; break;
		case 99: result.second = "MULTIPLE_LITTER_RARE"; break;
		case 100: result.second = "MOUNT"; break;
		case 101: result.second = "MOUNT_EXOTIC"; break;
		case 102: result.second = "FEATURE_ATTACK_GROUP"; break;
		case 103: result.second = "VERMIN_MICRO"; break;
		case 104: result.second = "EQUIPS"; break;
		case 105: result.second = "LAYS_EGGS"; break;
		case 106: result.second = "GRAZER"; break;
		case 107: result.second = "NOTHOUGHT"; break;
		case 108: result.second = "TRAPAVOID"; break;
		case 109: result.second = "CAVE_ADAPT"; break;
		case 110: result.second = "MEGABEAST"; break;
		case 111: result.second = "SEMIMEGABEAST"; break;
		case 112: result.second = "ALL_ACTIVE"; break;
		case 113: result.second = "DIURNAL"; break;
		case 114: result.second = "NOCTURNAL"; break;
		case 115: result.second = "CREPUSCULAR"; break;
		case 116: result.second = "MATUTINAL"; break;
		case 117: result.second = "VESPERTINE"; break;
		case 118: result.second = "LIGHT_GEN"; break;
		case 119: result.second = "LISP"; break;
		case 120: result.second = "GETS_INFECTIONS_FROM_ROT"; break;
		case 121: result.second = "CASTE_SOLDIER_TILE"; break;
		case 122: result.second = "ALCOHOL_DEPENDENT"; break;
		case 123: result.second = "SWIMS_INNATE"; break;
		case 124: result.second = "POWER"; break;
		case 125: result.second = "TENDONS"; break;
		case 126: result.second = "LIGAMENTS"; break;
		case 127: result.second = "CASTE_TILE"; break;
		case 128: result.second = "CASTE_COLOR"; break;
		case 129: result.second = "CASTE_GLOWTILE"; break;
		case 130: result.second = "CASTE_GLOWCOLOR"; break;
		case 131: result.second = "FEATURE_BEAST"; break;
		case 132: result.second = "TITAN"; break;
		case 133: result.second = "UNIQUE_DEMON"; break;
		case 134: result.second = "DEMON"; break;
		case 135: result.second = "MANNERISM_LAUGH"; break;
		case 136: result.second = "MANNERISM_SMILE"; break;
		case 137: result.second = "MANNERISM_WALK"; break;
		case 138: result.second = "MANNERISM_SIT"; break;
		case 139: result.second = "MANNERISM_BREATH"; break;
		case 140: result.second = "MANNERISM_POSTURE"; break;
		case 141: result.second = "MANNERISM_STRETCH"; break;
		case 142: result.second = "MANNERISM_EYELIDS"; break;
		case 143: result.second = "NIGHT_CREATURE_ANY"; break;
		case 144: result.second = "NIGHT_CREATURE_HUNTER"; break;
		case 145: result.second = "NIGHT_CREATURE_BOGEYMAN"; break;
		case 146: result.second = "CONVERTED_SPOUSE"; break;
		case 147: result.second = "SPOUSE_CONVERTER"; break;
		case 148: result.second = "SPOUSE_CONVERSION_TARGET"; break;
		case 149: result.second = "DIE_WHEN_VERMIN_BITE"; break;
		case 150: result.second = "REMAINS_ON_VERMIN_BITE_DEATH"; break;
		case 151: result.second = "COLONY_EXTERNAL"; break;
		case 152: result.second = "LAYS_UNUSUAL_EGGS"; break;
		case 153: result.second = "RETURNS_VERMIN_KILLS_TO_OWNER"; break;
		case 154: result.second = "HUNTS_VERMIN"; break;
		case 155: result.second = "ADOPTS_OWNER"; break;
		case 156: result.second = "SOUND_ALERT"; break;
		case 157: result.second = "SOUND_PEACEFUL_INTERMITTENT"; break;
		case 158: result.second = "NOT_LIVING"; break;
		case 159: result.second = "NO_PHYS_ATT_GAIN"; break;
		case 160: result.second = "NO_PHYS_ATT_RUST"; break;
		case 161: result.second = "CRAZED"; break;
		case 162: result.second = "BLOODSUCKER"; break;
		case 163: result.second = "NO_VEGETATION_PERTURB"; break;
		case 164: result.second = "DIVE_HUNTS_VERMIN"; break;
		case 165: result.second = "GOBBLE_VERMIN"; break;
		case 166: result.second = "CANNOT_JUMP"; break;
		case 167: result.second = "STANCE_CLIMBER"; break;
		case 168: result.second = "CANNOT_CLIMB"; break;
		case 169: result.second = "LOCAL_POPS_CONTROLLABLE"; break;
		case 170: result.second = "OUTSIDER_CONTROLLABLE"; break;
		case 171: result.second = "LOCAL_POPS_PRODUCE_HEROES"; break;
		case 172: result.second = "STRANGE_MOODS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_body_part_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "HEAD"; break;
		case 1: result.second = "UPPERBODY"; break;
		case 2: result.second = "LOWERBODY"; break;
		case 3: result.second = "SIGHT"; break;
		case 4: result.second = "EMBEDDED"; break;
		case 5: result.second = "INTERNAL"; break;
		case 6: result.second = "CIRCULATION"; break;
		case 7: result.second = "SKELETON"; break;
		case 8: result.second = "LIMB"; break;
		case 9: result.second = "GRASP"; break;
		case 10: result.second = "STANCE"; break;
		case 11: result.second = "GUTS"; break;
		case 12: result.second = "BREATHE"; break;
		case 13: result.second = "SMALL"; break;
		case 14: result.second = "THROAT"; break;
		case 15: result.second = "JOINT"; break;
		case 16: result.second = "THOUGHT"; break;
		case 17: result.second = "NERVOUS"; break;
		case 18: result.second = "RIGHT"; break;
		case 19: result.second = "LEFT"; break;
		case 20: result.second = "HEAR"; break;
		case 21: result.second = "SMELL"; break;
		case 22: result.second = "FLIER"; break;
		case 23: result.second = "DIGIT"; break;
		case 24: result.second = "MOUTH"; break;
		case 25: result.second = "APERTURE"; break;
		case 26: result.second = "SOCKET"; break;
		case 27: result.second = "TOTEMABLE"; break;
		case 28: result.second = "anon_1"; break;
		case 29: result.second = "anon_2"; break;
		case 30: result.second = "UNDER_PRESSURE"; break;
		case 31: result.second = "anon_3"; break;
		case 32: result.second = "VERMIN_BUTCHER_ITEM"; break;
		case 33: result.second = "CONNECTOR"; break;
		case 34: result.second = "anon_4"; break;
		case 35: result.second = "anon_5"; break;
		case 36: result.second = "anon_6"; break;
		case 37: result.second = "anon_7"; break;
		case 38: result.second = "GELDABLE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_appearance_modifier_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "HEIGHT"; break;
		case 1: result.second = "BROADNESS"; break;
		case 2: result.second = "LENGTH"; break;
		case 3: result.second = "CLOSE_SET"; break;
		case 4: result.second = "DEEP_SET"; break;
		case 5: result.second = "HIGH_POSITION"; break;
		case 6: result.second = "LARGE_IRIS"; break;
		case 7: result.second = "WRINKLY"; break;
		case 8: result.second = "CURLY"; break;
		case 9: result.second = "CONVEX"; break;
		case 10: result.second = "DENSE"; break;
		case 11: result.second = "THICKNESS"; break;
		case 12: result.second = "UPTURNED"; break;
		case 13: result.second = "SPLAYED_OUT"; break;
		case 14: result.second = "HANGING_LOBES"; break;
		case 15: result.second = "GAPS"; break;
		case 16: result.second = "HIGH_CHEEKBONES"; break;
		case 17: result.second = "BROAD_CHIN"; break;
		case 18: result.second = "JUTTING_CHIN"; break;
		case 19: result.second = "SQUARE_CHIN"; break;
		case 20: result.second = "ROUND_VS_NARROW"; break;
		case 21: result.second = "GREASY"; break;
		case 22: result.second = "DEEP_VOICE"; break;
		case 23: result.second = "RASPY_VOICE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_body_part_layer_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "CONNECTS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_appearance_modifier_growth_interval_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DAILY"; break;
		case 1: result.second = "WEEKLY"; break;
		case 2: result.second = "MONTHLY"; break;
		case 3: result.second = "YEARLY"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_gait_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "WALK"; break;
		case 1: result.second = "FLY"; break;
		case 2: result.second = "SWIM"; break;
		case 3: result.second = "CRAWL"; break;
		case 4: result.second = "CLIMB"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_creature_graphics_role_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DEFAULT"; break;
		case 1: result.second = "ADVENTURER"; break;
		case 2: result.second = "GUARD"; break;
		case 3: result.second = "ROYALGUARD"; break;
		case 4: result.second = "ANIMATED"; break;
		case 5: result.second = "GHOST"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tissue_style_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "NEATLY_COMBED"; break;
		case 1: result.second = "BRAIDED"; break;
		case 2: result.second = "DOUBLE_BRAIDS"; break;
		case 3: result.second = "PONY_TAILS"; break;
		case 4: result.second = "CLEAN_SHAVEN"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_body_part_template_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "HEAD"; break;
		case 1: result.second = "UPPERBODY"; break;
		case 2: result.second = "LOWERBODY"; break;
		case 3: result.second = "SIGHT"; break;
		case 4: result.second = "EMBEDDED"; break;
		case 5: result.second = "INTERNAL"; break;
		case 6: result.second = "CIRCULATION"; break;
		case 7: result.second = "SKELETON"; break;
		case 8: result.second = "LIMB"; break;
		case 9: result.second = "GRASP"; break;
		case 10: result.second = "STANCE"; break;
		case 11: result.second = "GUTS"; break;
		case 12: result.second = "BREATHE"; break;
		case 13: result.second = "SMALL"; break;
		case 14: result.second = "THROAT"; break;
		case 15: result.second = "JOINT"; break;
		case 16: result.second = "THOUGHT"; break;
		case 17: result.second = "NERVOUS"; break;
		case 18: result.second = "RIGHT"; break;
		case 19: result.second = "LEFT"; break;
		case 20: result.second = "HEAR"; break;
		case 21: result.second = "SMELL"; break;
		case 22: result.second = "FLIER"; break;
		case 23: result.second = "DIGIT"; break;
		case 24: result.second = "MOUTH"; break;
		case 25: result.second = "APERTURE"; break;
		case 26: result.second = "SOCKET"; break;
		case 27: result.second = "TOTEMABLE"; break;
		case 28: result.second = "UNDER_PRESSURE"; break;
		case 29: result.second = "VERMIN_BUTCHER_ITEM"; break;
		case 30: result.second = "CONNECTOR"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_body_part_template_contype_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "UPPERBODY"; break;
		case 1: result.second = "LOWERBODY"; break;
		case 2: result.second = "HEAD"; break;
		case 3: result.second = "GRASP"; break;
		case 4: result.second = "STANCE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tissue_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "THICKENS_ON_STRENGTH"; break;
		case 1: result.second = "THICKENS_ON_ENERGY_STORAGE"; break;
		case 2: result.second = "ARTERIES"; break;
		case 3: result.second = "SCARS"; break;
		case 4: result.second = "STRUCTURAL"; break;
		case 5: result.second = "NERVOUS"; break;
		case 6: result.second = "THOUGHT"; break;
		case 7: result.second = "MUSCULAR"; break;
		case 8: result.second = "SMELL"; break;
		case 9: result.second = "HEAR"; break;
		case 10: result.second = "FLIGHT"; break;
		case 11: result.second = "BREATHE"; break;
		case 12: result.second = "SIGHT"; break;
		case 13: result.second = "COSMETIC"; break;
		case 14: result.second = "CONNECTS"; break;
		case 15: result.second = "FUNCTIONAL"; break;
		case 16: result.second = "MAJOR_ARTERIES"; break;
		case 17: result.second = "TISSUE_LEAKS"; break;
		case 18: result.second = "STYLEABLE"; break;
		case 19: result.second = "CONNECTIVE_TISSUE_ANCHOR"; break;
		case 20: result.second = "SETTABLE"; break;
		case 21: result.second = "SPLINTABLE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_nickname_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "REPLACE_FIRST"; break;
		case 1: result.second = "CENTRALIZE"; break;
		case 2: result.second = "REPLACE_ALL"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_z_view_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "OFF"; break;
		case 1: result.second = "UNHIDDEN"; break;
		case 2: result.second = "CREATURE"; break;
		case 3: result.second = "ON"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_embark_confirm_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ALWAYS"; break;
		case 1: result.second = "IF_POINTS_REMAIN"; break;
		case 2: result.second = "NO"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_idlers_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "OFF"; break;
		case 0: result.second = "TOP"; break;
		case 1: result.second = "BOTTOM"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_tunnel_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "NO"; break;
		case 1: result.second = "FINDER"; break;
		case 2: result.second = "ALWAYS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_flags1_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "VARIED_GROUND_TILES"; break;
		case 1: result.second = "ENGRAVINGS_START_OBSCURED"; break;
		case 2: result.second = "SHOW_IMP_QUALITY"; break;
		case 3: result.second = "SHOW_FLOW_AMOUNTS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_flags2_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MORE"; break;
		case 1: result.second = "ADVENTURER_TRAPS"; break;
		case 2: result.second = "ADVENTURER_ALWAYS_CENTER"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_flags3_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "COFFIN_NO_PETS_DEFAULT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_d_init_flags4_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TEMPERATURE"; break;
		case 1: result.second = "WEATHER"; break;
		case 2: result.second = "ECONOMY"; break;
		case 3: result.second = "ZERO_RENT"; break;
		case 4: result.second = "AUTOSAVE_SEASONAL"; break;
		case 5: result.second = "AUTOSAVE_YEARLY"; break;
		case 6: result.second = "AUTOSAVE_PAUSE"; break;
		case 7: result.second = "AUTOBACKUP"; break;
		case 8: result.second = "INITIAL_SAVE"; break;
		case 9: result.second = "INVADERS"; break;
		case 10: result.second = "CAVEINS"; break;
		case 11: result.second = "ARTIFACTS"; break;
		case 12: result.second = "LOG_MAP_REJECTS"; break;
		case 13: result.second = "PAUSE_ON_LOAD"; break;
		case 14: result.second = "EMBARK_WARNING_ALWAYS"; break;
		case 15: result.second = "SHOW_ALL_HISTORY_IN_DWARF_MODE"; break;
		case 16: result.second = "TESTING_ARENA"; break;
		case 17: result.second = "WALKING_SPREADS_SPATTER_DWF"; break;
		case 18: result.second = "WALKING_SPREADS_SPATTER_ADV"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_pattern_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MONOTONE"; break;
		case 1: result.second = "STRIPES"; break;
		case 2: result.second = "IRIS_EYE"; break;
		case 3: result.second = "SPOTS"; break;
		case 4: result.second = "PUPIL_EYE"; break;
		case 5: result.second = "MOTTLED"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_occasion_schedule_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DANCE_PERFORMANCE"; break;
		case 1: result.second = "MUSICAL_PERFORMANCE"; break;
		case 2: result.second = "POETRY_RECITAL"; break;
		case 3: result.second = "STORYTELLING"; break;
		case 4: result.second = "DANCE_COMPETITION"; break;
		case 5: result.second = "MUSICAL_COMPETITION"; break;
		case 6: result.second = "POETRY_COMPETITION"; break;
		case 7: result.second = "FOOT_RACE"; break;
		case 8: result.second = "anon_1"; break;
		case 9: result.second = "anon_2"; break;
		case 10: result.second = "WRESTLING_COMPETITION"; break;
		case 11: result.second = "THROWING_COMPETITION"; break;
		case 12: result.second = "GLADIATORY_COMPETITION"; break;
		case 13: result.second = "PROCESSION"; break;
		case 14: result.second = "CEREMONY"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_occasion_schedule_feature_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "anon_1"; break;
		case 1: result.second = "anon_2"; break;
		case 2: result.second = "STORYTELLING"; break;
		case 3: result.second = "POETRY_RECITAL"; break;
		case 4: result.second = "MUSICAL_PERFORMANCE"; break;
		case 5: result.second = "DANCE_PERFORMANCE"; break;
		case 6: result.second = "anon_3"; break;
		case 7: result.second = "CRIERS_IN_FRONT"; break;
		case 8: result.second = "ORDER_OF_PRECEDENCE"; break;
		case 9: result.second = "BANNERS"; break;
		case 10: result.second = "IMAGES"; break;
		case 11: result.second = "anon_4"; break;
		case 12: result.second = "anon_5"; break;
		case 13: result.second = "ACROBATS"; break;
		case 14: result.second = "INCENSE_BURNING"; break;
		case 15: result.second = "COSTUMES"; break;
		case 16: result.second = "CANDLES"; break;
		case 17: result.second = "THE_GIVING_OF_ITEMS"; break;
		case 18: result.second = "THE_SACRIFICE_OF_ITEMS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_sell_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Leather"; break;
		case 1: result.second = "ClothPlant"; break;
		case 2: result.second = "ClothSilk"; break;
		case 3: result.second = "Crafts"; break;
		case 4: result.second = "Wood"; break;
		case 5: result.second = "MetalBars"; break;
		case 6: result.second = "SmallCutGems"; break;
		case 7: result.second = "LargeCutGems"; break;
		case 8: result.second = "StoneBlocks"; break;
		case 9: result.second = "Seeds"; break;
		case 10: result.second = "Anvils"; break;
		case 11: result.second = "Weapons"; break;
		case 12: result.second = "TrainingWeapons"; break;
		case 13: result.second = "Ammo"; break;
		case 14: result.second = "TrapComponents"; break;
		case 15: result.second = "DiggingImplements"; break;
		case 16: result.second = "Bodywear"; break;
		case 17: result.second = "Headwear"; break;
		case 18: result.second = "Handwear"; break;
		case 19: result.second = "Footwear"; break;
		case 20: result.second = "Legwear"; break;
		case 21: result.second = "Shields"; break;
		case 22: result.second = "Toys"; break;
		case 23: result.second = "Instruments"; break;
		case 24: result.second = "Pets"; break;
		case 25: result.second = "Drinks"; break;
		case 26: result.second = "Cheese"; break;
		case 27: result.second = "Powders"; break;
		case 28: result.second = "Extracts"; break;
		case 29: result.second = "Meat"; break;
		case 30: result.second = "Fish"; break;
		case 31: result.second = "Plants"; break;
		case 32: result.second = "FruitsNuts"; break;
		case 33: result.second = "GardenVegetables"; break;
		case 34: result.second = "MeatFishRecipes"; break;
		case 35: result.second = "OtherRecipes"; break;
		case 36: result.second = "Stone"; break;
		case 37: result.second = "Cages"; break;
		case 38: result.second = "BagsLeather"; break;
		case 39: result.second = "BagsPlant"; break;
		case 40: result.second = "BagsSilk"; break;
		case 41: result.second = "ThreadPlant"; break;
		case 42: result.second = "ThreadSilk"; break;
		case 43: result.second = "RopesPlant"; break;
		case 44: result.second = "RopesSilk"; break;
		case 45: result.second = "Barrels"; break;
		case 46: result.second = "FlasksWaterskins"; break;
		case 47: result.second = "Quivers"; break;
		case 48: result.second = "Backpacks"; break;
		case 49: result.second = "Sand"; break;
		case 50: result.second = "Glass"; break;
		case 51: result.second = "Miscellaneous"; break;
		case 52: result.second = "Buckets"; break;
		case 53: result.second = "Splints"; break;
		case 54: result.second = "Crutches"; break;
		case 55: result.second = "Eggs"; break;
		case 56: result.second = "BagsYarn"; break;
		case 57: result.second = "RopesYarn"; break;
		case 58: result.second = "ClothYarn"; break;
		case 59: result.second = "ThreadYarn"; break;
		case 60: result.second = "Tools"; break;
		case 61: result.second = "Clay"; break;
		case 62: result.second = "Parchment"; break;
		case 63: result.second = "CupsMugsGoblets"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_historical_entity_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Civilization"; break;
		case 1: result.second = "SiteGovernment"; break;
		case 2: result.second = "VesselCrew"; break;
		case 3: result.second = "MigratingGroup"; break;
		case 4: result.second = "NomadicGroup"; break;
		case 5: result.second = "Religion"; break;
		case 6: result.second = "MilitaryUnit"; break;
		case 7: result.second = "Outcast"; break;
		case 8: result.second = "PerformanceTroupe"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_training_knowledge_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "None"; break;
		case 1: result.second = "FewFacts"; break;
		case 2: result.second = "GeneralFamiliarity"; break;
		case 3: result.second = "Knowledgeable"; break;
		case 4: result.second = "Expert"; break;
		case 5: result.second = "Domesticated"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_position_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "IS_LAW_MAKER"; break;
		case 1: result.second = "ELECTED"; break;
		case 2: result.second = "DUTY_BOUND"; break;
		case 3: result.second = "MILITARY_SCREEN_ONLY"; break;
		case 4: result.second = "GENDER_MALE"; break;
		case 5: result.second = "GENDER_FEMALE"; break;
		case 6: result.second = "SUCCESSION_BY_HEIR"; break;
		case 7: result.second = "HAS_RESPONSIBILITIES"; break;
		case 8: result.second = "FLASHES"; break;
		case 9: result.second = "BRAG_ON_KILL"; break;
		case 10: result.second = "CHAT_WORTHY"; break;
		case 11: result.second = "DO_NOT_CULL"; break;
		case 12: result.second = "KILL_QUEST"; break;
		case 13: result.second = "IS_LEADER"; break;
		case 14: result.second = "IS_DIPLOMAT"; break;
		case 15: result.second = "EXPORTED_IN_LEGENDS"; break;
		case 16: result.second = "DETERMINES_COIN_DESIGN"; break;
		case 17: result.second = "ACCOUNT_EXEMPT"; break;
		case 18: result.second = "unk_12"; break;
		case 19: result.second = "unk_13"; break;
		case 20: result.second = "COLOR"; break;
		case 21: result.second = "RULES_FROM_LOCATION"; break;
		case 22: result.second = "MENIAL_WORK_EXEMPTION"; break;
		case 23: result.second = "MENIAL_WORK_EXEMPTION_SPOUSE"; break;
		case 24: result.second = "SLEEP_PRETENSION"; break;
		case 25: result.second = "PUNISHMENT_EXEMPTION"; break;
		case 26: result.second = "unk_1a"; break;
		case 27: result.second = "unk_1b"; break;
		case 28: result.second = "QUEST_GIVER"; break;
		case 29: result.second = "SPECIAL_BURIAL"; break;
		case 30: result.second = "REQUIRES_MARKET"; break;
		case 31: result.second = "unk_1f"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_material_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Clothing"; break;
		case 1: result.second = "Leather"; break;
		case 2: result.second = "Cloth"; break;
		case 3: result.second = "Wood"; break;
		case 4: result.second = "Crafts"; break;
		case 5: result.second = "Stone"; break;
		case 6: result.second = "Improvement"; break;
		case 7: result.second = "Glass"; break;
		case 8: result.second = "Wood2"; break;
		case 9: result.second = "Bag"; break;
		case 10: result.second = "Cage"; break;
		case 11: result.second = "WeaponMelee"; break;
		case 12: result.second = "WeaponRanged"; break;
		case 13: result.second = "Ammo"; break;
		case 14: result.second = "Ammo2"; break;
		case 15: result.second = "Pick"; break;
		case 16: result.second = "Armor"; break;
		case 17: result.second = "Gem"; break;
		case 18: result.second = "Bone"; break;
		case 19: result.second = "Shell"; break;
		case 20: result.second = "Pearl"; break;
		case 21: result.second = "Ivory"; break;
		case 22: result.second = "Horn"; break;
		case 23: result.second = "Other"; break;
		case 24: result.second = "Anvil"; break;
		case 25: result.second = "Booze"; break;
		case 26: result.second = "Metal"; break;
		case 27: result.second = "PlantFiber"; break;
		case 28: result.second = "Silk"; break;
		case 29: result.second = "Wool"; break;
		case 30: result.second = "Furniture"; break;
		case 31: result.second = "MiscWood2"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "invasion"; break;
		case 1: result.second = "abduction"; break;
		case 2: result.second = "incident"; break;
		case 3: result.second = "occupation"; break;
		case 4: result.second = "beast"; break;
		case 5: result.second = "group"; break;
		case 6: result.second = "harass"; break;
		case 7: result.second = "flee"; break;
		case 8: result.second = "abandon"; break;
		case 9: result.second = "reclaimed"; break;
		case 10: result.second = "founded"; break;
		case 11: result.second = "reclaiming"; break;
		case 12: result.second = "founding"; break;
		case 13: result.second = "leave"; break;
		case 14: result.second = "insurrection"; break;
		case 15: result.second = "insurrection_end"; break;
		case 16: result.second = "succession"; break;
		case 17: result.second = "claim"; break;
		case 18: result.second = "accept_tribute_offer"; break;
		case 19: result.second = "refuse_tribute_offer"; break;
		case 20: result.second = "accept_tribute_demand"; break;
		case 21: result.second = "refuse_tribute_demand"; break;
		case 22: result.second = "accept_peace_offer"; break;
		case 23: result.second = "refuse_peace_offer"; break;
		case 24: result.second = "cease_tribute_offer"; break;
		case 25: result.second = "artifact_in_site"; break;
		case 26: result.second = "artifact_in_subregion"; break;
		case 27: result.second = "artifact_in_feature_layer"; break;
		case 28: result.second = "artifact_in_inventory"; break;
		case 29: result.second = "artifact_not_in_site"; break;
		case 30: result.second = "artifact_not_in_subregion"; break;
		case 31: result.second = "artifact_not_in_feature_layer"; break;
		case 32: result.second = "artifact_not_in_inventory"; break;
		case 33: result.second = "artifact_was_destroyed"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "CIV_CONTROLLABLE"; break;
		case 1: result.second = "INDIV_CONTROLLABLE"; break;
		case 2: result.second = "LAYER_LINKED"; break;
		case 3: result.second = "INDOOR_WOOD"; break;
		case 4: result.second = "WOOD_ARMOR"; break;
		case 5: result.second = "SIEGER"; break;
		case 6: result.second = "AMBUSHER"; break;
		case 7: result.second = "BABYSNATCHER"; break;
		case 8: result.second = "ITEM_THIEF"; break;
		case 9: result.second = "CLOTHING"; break;
		case 10: result.second = "CURRENCY_BY_YEAR"; break;
		case 11: result.second = "METAL_PREF"; break;
		case 12: result.second = "GEM_PREF"; break;
		case 13: result.second = "STONE_PREF"; break;
		case 14: result.second = "WOOD_WEAPONS"; break;
		case 15: result.second = "BUILDS_OUTDOOR_FORTIFICATIONS"; break;
		case 16: result.second = "RIVER_PRODUCTS"; break;
		case 17: result.second = "OCEAN_PRODUCTS"; break;
		case 18: result.second = "INDOOR_FARMING"; break;
		case 19: result.second = "OUTDOOR_FARMING"; break;
		case 20: result.second = "USE_CAVE_ANIMALS"; break;
		case 21: result.second = "USE_EVIL_ANIMALS"; break;
		case 22: result.second = "USE_ANIMAL_PRODUCTS"; break;
		case 23: result.second = "COMMON_DOMESTIC_PACK"; break;
		case 24: result.second = "COMMON_DOMESTIC_PULL"; break;
		case 25: result.second = "COMMON_DOMESTIC_MOUNT"; break;
		case 26: result.second = "COMMON_DOMESTIC_PET"; break;
		case 27: result.second = "SUBTERRANEAN_CLOTHING"; break;
		case 28: result.second = "USE_EVIL_WOOD"; break;
		case 29: result.second = "USE_GOOD_WOOD"; break;
		case 30: result.second = "USE_EVIL_PLANTS"; break;
		case 31: result.second = "USE_GOOD_PLANTS"; break;
		case 32: result.second = "USE_GOOD_ANIMALS"; break;
		case 33: result.second = "USE_ANY_PET_RACE"; break;
		case 34: result.second = "USE_MISC_PROCESSED_WOOD_PRODUCTS"; break;
		case 35: result.second = "IMPROVED_BOWS"; break;
		case 36: result.second = "OUTDOOR_WOOD"; break;
		case 37: result.second = "LOCAL_BANDITRY"; break;
		case 38: result.second = "BUILDS_OUTDOOR_TOMBS"; break;
		case 39: result.second = "INVADERS_IGNORE_NEUTRALS"; break;
		case 40: result.second = "AT_PEACE_WITH_WILDLIFE"; break;
		case 41: result.second = "EQUIPMENT_IMPROVEMENTS"; break;
		case 42: result.second = "ABUSE_BODIES"; break;
		case 43: result.second = "UNDEAD_CANDIDATE"; break;
		case 44: result.second = "GENERATED"; break;
		case 45: result.second = "SKULKING"; break;
		case 46: result.second = "anon_1"; break;
		case 47: result.second = "MERCHANT_NOBILITY"; break;
		case 48: result.second = "TREE_CAP_DIPLOMACY"; break;
		case 49: result.second = "DIPLOMAT_BODYGUARDS"; break;
		case 50: result.second = "MERCHANT_BODYGUARDS"; break;
		case 51: result.second = "INDOOR_ORCHARDS"; break;
		case 52: result.second = "OUTDOOR_ORCHARDS"; break;
		case 53: result.second = "WANDERER"; break;
		case 54: result.second = "BEAST_HUNTER"; break;
		case 55: result.second = "SCOUT"; break;
		case 56: result.second = "WILL_ACCEPT_TRIBUTE"; break;
		case 57: result.second = "INDOOR_GARDENS"; break;
		case 58: result.second = "OUTDOOR_GARDENS"; break;
		case 59: result.second = "MERCENARY"; break;
		case 60: result.second = "SITE_GUARDIAN"; break;
		case 61: result.second = "DIVINE_MAT_WEAPONS"; break;
		case 62: result.second = "DIVINE_MAT_ARMOR"; break;
		case 63: result.second = "DIVINE_MAT_CRAFTS"; break;
		case 64: result.second = "DIVINE_MAT_CLOTHING"; break;
		case 65: result.second = "GENERATE_KEYBOARD_INSTRUMENTS"; break;
		case 66: result.second = "GENERATE_STRINGED_INSTRUMENTS"; break;
		case 67: result.second = "GENERATE_WIND_INSTRUMENTS"; break;
		case 68: result.second = "GENERATE_PERCUSSION_INSTRUMENTS"; break;
		case 69: result.second = "GENERATE_POETIC_FORMS"; break;
		case 70: result.second = "GENERATE_MUSICAL_FORMS"; break;
		case 71: result.second = "GENERATE_DANCE_FORMS"; break;
		case 72: result.second = "SET_SCHOLARS_ON_VALUES_AND_JOBS"; break;
		case 73: result.second = "NO_ARTIFACT_CLAIMS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_site_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "PLAYER_FORTRESS"; break;
		case 1: result.second = "DARK_FORTRESS"; break;
		case 2: result.second = "CAVE"; break;
		case 3: result.second = "CAVE_DETAILED"; break;
		case 4: result.second = "TREE_CITY"; break;
		case 5: result.second = "CITY"; break;
		case 6: result.second = "anon_1"; break;
		case 7: result.second = "anon_2"; break;
		case 8: result.second = "FORTRESS"; break;
		case 9: result.second = "anon_3"; break;
		case 10: result.second = "MONUMENT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ethic_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "KILL_ENTITY_MEMBER"; break;
		case 1: result.second = "KILL_NEUTRAL"; break;
		case 2: result.second = "KILL_ENEMY"; break;
		case 3: result.second = "KILL_ANIMAL"; break;
		case 4: result.second = "KILL_PLANT"; break;
		case 5: result.second = "TORTURE_AS_EXAMPLE"; break;
		case 6: result.second = "TORTURE_FOR_INFORMATION"; break;
		case 7: result.second = "TORTURE_FOR_FUN"; break;
		case 8: result.second = "TORTURE_ANIMALS"; break;
		case 9: result.second = "TREASON"; break;
		case 10: result.second = "OATH_BREAKING"; break;
		case 11: result.second = "LYING"; break;
		case 12: result.second = "VANDALISM"; break;
		case 13: result.second = "TRESPASSING"; break;
		case 14: result.second = "THEFT"; break;
		case 15: result.second = "ASSAULT"; break;
		case 16: result.second = "SLAVERY"; break;
		case 17: result.second = "EAT_SAPIENT_OTHER"; break;
		case 18: result.second = "EAT_SAPIENT_KILL"; break;
		case 19: result.second = "MAKE_TROPHY_SAME_RACE"; break;
		case 20: result.second = "MAKE_TROPHY_SAPIENT"; break;
		case 21: result.second = "MAKE_TROPHY_ANIMAL"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ethic_response_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "NOT_APPLICABLE"; break;
		case 1: result.second = "ACCEPTABLE"; break;
		case 2: result.second = "PERSONAL_MATTER"; break;
		case 3: result.second = "JUSTIFIED_IF_NO_REPERCUSSIONS"; break;
		case 4: result.second = "JUSTIFIED_IF_GOOD_REASON"; break;
		case 5: result.second = "JUSTIFIED_IF_EXTREME_REASON"; break;
		case 6: result.second = "JUSTIFIED_IF_SELF_DEFENSE"; break;
		case 7: result.second = "ONLY_IF_SANCTIONED"; break;
		case 8: result.second = "MISGUIDED"; break;
		case 9: result.second = "SHUN"; break;
		case 10: result.second = "APPALLING"; break;
		case 11: result.second = "PUNISH_REPRIMAND"; break;
		case 12: result.second = "PUNISH_SERIOUS"; break;
		case 13: result.second = "PUNISH_EXILE"; break;
		case 14: result.second = "PUNISH_CAPITAL"; break;
		case 15: result.second = "UNTHINKABLE"; break;
		case 16: result.second = "REQUIRED"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_name_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "OTHER"; break;
		case 1: result.second = "CIV"; break;
		case 2: result.second = "SITE"; break;
		case 3: result.second = "VESSEL"; break;
		case 4: result.second = "MILITARY_UNIT"; break;
		case 5: result.second = "RELIGION"; break;
		case 6: result.second = "TEMPLE"; break;
		case 7: result.second = "WAR"; break;
		case 8: result.second = "BATTLE"; break;
		case 9: result.second = "SIEGE"; break;
		case 10: result.second = "ROAD"; break;
		case 11: result.second = "BRIDGE"; break;
		case 12: result.second = "TUNNEL"; break;
		case 13: result.second = "WALL"; break;
		case 14: result.second = "LIBRARY"; break;
		case 15: result.second = "FESTIVAL"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_position_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SITE"; break;
		case 1: result.second = "ELECTED"; break;
		case 2: result.second = "CONQUERED_SITE"; break;
		case 3: result.second = "MILITARY_SCREEN_ONLY"; break;
		case 4: result.second = "GENDER_MALE"; break;
		case 5: result.second = "GENDER_FEMALE"; break;
		case 6: result.second = "SUCCESSION_BY_HEIR"; break;
		case 7: result.second = "EXPORTED_IN_LEGENDS"; break;
		case 8: result.second = "FLASHES"; break;
		case 9: result.second = "BRAG_ON_KILL"; break;
		case 10: result.second = "CHAT_WORTHY"; break;
		case 11: result.second = "DO_NOT_CULL"; break;
		case 12: result.second = "KILL_QUEST"; break;
		case 13: result.second = "DETERMINES_COIN_DESIGN"; break;
		case 14: result.second = "ACCOUNT_EXEMPT"; break;
		case 15: result.second = "DUTY_BOUND"; break;
		case 16: result.second = "COLOR"; break;
		case 17: result.second = "RULES_FROM_LOCATION"; break;
		case 18: result.second = "MENIAL_WORK_EXEMPTION"; break;
		case 19: result.second = "MENIAL_WORK_EXEMPTION_SPOUSE"; break;
		case 20: result.second = "SLEEP_PRETENSION"; break;
		case 21: result.second = "PUNISHMENT_EXEMPTION"; break;
		case 22: result.second = "QUEST_GIVER"; break;
		case 23: result.second = "SPECIAL_BURIAL"; break;
		case 24: result.second = "REQUIRES_MARKET"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_position_responsibility_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "LAW_MAKING"; break;
		case 1: result.second = "LAW_ENFORCEMENT"; break;
		case 2: result.second = "RECEIVE_DIPLOMATS"; break;
		case 3: result.second = "MEET_WORKERS"; break;
		case 4: result.second = "MANAGE_PRODUCTION"; break;
		case 5: result.second = "TRADE"; break;
		case 6: result.second = "ACCOUNTING"; break;
		case 7: result.second = "ESTABLISH_COLONY_TRADE_AGREEMENTS"; break;
		case 8: result.second = "MAKE_INTRODUCTIONS"; break;
		case 9: result.second = "MAKE_PEACE_AGREEMENTS"; break;
		case 10: result.second = "MAKE_TOPIC_AGREEMENTS"; break;
		case 11: result.second = "COLLECT_TAXES"; break;
		case 12: result.second = "ESCORT_TAX_COLLECTOR"; break;
		case 13: result.second = "EXECUTIONS"; break;
		case 14: result.second = "TAME_EXOTICS"; break;
		case 15: result.second = "RELIGION"; break;
		case 16: result.second = "ATTACK_ENEMIES"; break;
		case 17: result.second = "PATROL_TERRITORY"; break;
		case 18: result.second = "MILITARY_GOALS"; break;
		case 19: result.second = "MILITARY_STRATEGY"; break;
		case 20: result.second = "UPGRADE_SQUAD_EQUIPMENT"; break;
		case 21: result.second = "EQUIPMENT_MANIFESTS"; break;
		case 22: result.second = "SORT_AMMUNITION"; break;
		case 23: result.second = "BUILD_MORALE"; break;
		case 24: result.second = "HEALTH_MANAGEMENT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_weather_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "None"; break;
		case 1: result.second = "Rain"; break;
		case 2: result.second = "Snow"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_game_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DWARF"; break;
		case 1: result.second = "ADVENTURE"; break;
		case 2: result.second = "num"; break;
		case 3: result.second = "NONE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_game_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DWARF_MAIN"; break;
		case 1: result.second = "ADVENTURE_MAIN"; break;
		case 2: result.second = "VIEW_LEGENDS"; break;
		case 3: result.second = "DWARF_RECLAIM"; break;
		case 4: result.second = "DWARF_ARENA"; break;
		case 5: result.second = "ADVENTURE_ARENA"; break;
		case 6: result.second = "ADVENTURE_DUNGEON"; break;
		case 7: result.second = "DWARF_TUTORIAL"; break;
		case 8: result.second = "DWARF_UNRETIRE"; break;
		case 9: result.second = "ADVENTURE_WORLD_DEBUG"; break;
		case 10: result.second = "num"; break;
		case 11: result.second = "NONE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_lever_target_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 66: result.second = "BarsVertical"; break;
		case 70: result.second = "BarsFloor"; break;
		case 83: result.second = "SpearsSpikes"; break;
		case 84: result.second = "TrackStop"; break;
		case 97: result.second = "GearAssembly"; break;
		case 98: result.second = "Bridge"; break;
		case 99: result.second = "Chain"; break;
		case 100: result.second = "Door"; break;
		case 101: result.second = "EncrustGems"; break;
		case 102: result.second = "Floodgate"; break;
		case 103: result.second = "GrateFloor"; break;
		case 104: result.second = "Hatch"; break;
		case 106: result.second = "Cage"; break;
		case 115: result.second = "Support"; break;
		case 119: result.second = "GrateWall"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_zoom_commands_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "zoom_in"; break;
		case 1: result.second = "zoom_out"; break;
		case 2: result.second = "zoom_reset"; break;
		case 3: result.second = "zoom_fullscreen"; break;
		case 4: result.second = "zoom_resetgrid"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_reputation_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Hero"; break;
		case 1: result.second = "Buddy"; break;
		case 2: result.second = "Grudge"; break;
		case 3: result.second = "AnimalPartner"; break;
		case 4: result.second = "Brawler"; break;
		case 5: result.second = "Psycho"; break;
		case 6: result.second = "TradePartner"; break;
		case 7: result.second = "Friendly"; break;
		case 8: result.second = "Killer"; break;
		case 9: result.second = "Murderer"; break;
		case 10: result.second = "Comrade"; break;
		case 11: result.second = "RespectedGroup"; break;
		case 12: result.second = "HatedGroup"; break;
		case 13: result.second = "EnemyFighter"; break;
		case 14: result.second = "FriendlyFighter"; break;
		case 15: result.second = "Bully"; break;
		case 16: result.second = "Brigand"; break;
		case 17: result.second = "LoyalSoldier"; break;
		case 18: result.second = "Monster"; break;
		case 19: result.second = "Storyteller"; break;
		case 20: result.second = "Poet"; break;
		case 21: result.second = "Bard"; break;
		case 22: result.second = "Dancer"; break;
		case 23: result.second = "Quarreler"; break;
		case 24: result.second = "Flatterer"; break;
		case 25: result.second = "Hunter"; break;
		case 26: result.second = "ProtectorOfWeak"; break;
		case 27: result.second = "TreasureHunter"; break;
		case 28: result.second = "Thief"; break;
		case 29: result.second = "InformationSource"; break;
		case 30: result.second = "PreserverOfKnowledge"; break;
		case 31: result.second = "Intruder"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_histfig_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "reveal_artwork"; break;
		case 1: result.second = "equipment_created"; break;
		case 2: result.second = "deity"; break;
		case 3: result.second = "force"; break;
		case 4: result.second = "skeletal_deity"; break;
		case 5: result.second = "rotting_deity"; break;
		case 6: result.second = "worldgen_acted"; break;
		case 7: result.second = "ghost"; break;
		case 8: result.second = "skin_destroyed"; break;
		case 9: result.second = "meat_destroyed"; break;
		case 10: result.second = "bones_destroyed"; break;
		case 11: result.second = "brag_on_kill"; break;
		case 12: result.second = "kill_quest"; break;
		case 13: result.second = "chatworthy"; break;
		case 14: result.second = "flashes"; break;
		case 15: result.second = "never_cull"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_histfig_relationship_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Mother"; break;
		case 1: result.second = "Father"; break;
		case 2: result.second = "Parent"; break;
		case 3: result.second = "Husband"; break;
		case 4: result.second = "Wife"; break;
		case 5: result.second = "Spouse"; break;
		case 6: result.second = "SonEldest"; break;
		case 7: result.second = "SonEldest2"; break;
		case 8: result.second = "SonEldest3"; break;
		case 9: result.second = "SonEldest4"; break;
		case 10: result.second = "SonEldest5"; break;
		case 11: result.second = "SonEldest6"; break;
		case 12: result.second = "SonEldest7"; break;
		case 13: result.second = "SonEldest8"; break;
		case 14: result.second = "SonEldest9"; break;
		case 15: result.second = "SonEldest10"; break;
		case 16: result.second = "Son"; break;
		case 17: result.second = "SonYoungest"; break;
		case 18: result.second = "SonOnly"; break;
		case 19: result.second = "DaughterEldest"; break;
		case 20: result.second = "DaughterEldest2"; break;
		case 21: result.second = "DaughterEldest3"; break;
		case 22: result.second = "DaughterEldest4"; break;
		case 23: result.second = "DaughterEldest5"; break;
		case 24: result.second = "DaughterEldest6"; break;
		case 25: result.second = "DaughterEldest7"; break;
		case 26: result.second = "DaughterEldest8"; break;
		case 27: result.second = "DaughterEldest9"; break;
		case 28: result.second = "DaughterEldest10"; break;
		case 29: result.second = "Daughter"; break;
		case 30: result.second = "DaughterOnly"; break;
		case 31: result.second = "DaughterYoungest"; break;
		case 32: result.second = "ChildEldest"; break;
		case 33: result.second = "ChildEldest2"; break;
		case 34: result.second = "ChildEldest3"; break;
		case 35: result.second = "ChildEldest4"; break;
		case 36: result.second = "ChildEldest5"; break;
		case 37: result.second = "ChildEldest6"; break;
		case 38: result.second = "ChildEldest7"; break;
		case 39: result.second = "ChildEldest8"; break;
		case 40: result.second = "ChildEldest9"; break;
		case 41: result.second = "ChildEldest10"; break;
		case 42: result.second = "Child"; break;
		case 43: result.second = "ChildYoungest"; break;
		case 44: result.second = "ChildOnly"; break;
		case 45: result.second = "PaternalGrandmother"; break;
		case 46: result.second = "PaternalGrandfather"; break;
		case 47: result.second = "MaternalGrandmother"; break;
		case 48: result.second = "MaternalGrandfather"; break;
		case 49: result.second = "Grandmother"; break;
		case 50: result.second = "Grandfather"; break;
		case 51: result.second = "Grandparent"; break;
		case 52: result.second = "OlderBrother"; break;
		case 53: result.second = "OlderSister"; break;
		case 54: result.second = "OlderSibling"; break;
		case 55: result.second = "YoungerBrother"; break;
		case 56: result.second = "YoungerSister"; break;
		case 57: result.second = "YoungerSibling"; break;
		case 58: result.second = "Cousin"; break;
		case 59: result.second = "Aunt"; break;
		case 60: result.second = "Uncle"; break;
		case 61: result.second = "Niece"; break;
		case 62: result.second = "Nephew"; break;
		case 63: result.second = "Sibling"; break;
		case 64: result.second = "Grandchild"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_mental_picture_property_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DATE"; break;
		case 1: result.second = "ACTION"; break;
		case 2: result.second = "TOOL"; break;
		case 3: result.second = "EMOTION"; break;
		case 4: result.second = "COLOR_PATTERN"; break;
		case 5: result.second = "SHAPE"; break;
		case 6: result.second = "ADJECTIVE"; break;
		case 7: result.second = "POSITION"; break;
		case 8: result.second = "TIME"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_mental_picture_element_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "HF"; break;
		case 1: result.second = "SITE"; break;
		case 2: result.second = "REGION"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "WAR_ATTACKED_SITE"; break;
		case 1: result.second = "WAR_DESTROYED_SITE"; break;
		case 2: result.second = "CREATED_SITE"; break;
		case 3: result.second = "HIST_FIGURE_DIED"; break;
		case 4: result.second = "ADD_HF_ENTITY_LINK"; break;
		case 5: result.second = "REMOVE_HF_ENTITY_LINK"; break;
		case 6: result.second = "FIRST_CONTACT"; break;
		case 7: result.second = "FIRST_CONTACT_FAILED"; break;
		case 8: result.second = "TOPICAGREEMENT_CONCLUDED"; break;
		case 9: result.second = "TOPICAGREEMENT_REJECTED"; break;
		case 10: result.second = "TOPICAGREEMENT_MADE"; break;
		case 11: result.second = "WAR_PEACE_ACCEPTED"; break;
		case 12: result.second = "WAR_PEACE_REJECTED"; break;
		case 13: result.second = "DIPLOMAT_LOST"; break;
		case 14: result.second = "AGREEMENTS_VOIDED"; break;
		case 15: result.second = "MERCHANT"; break;
		case 16: result.second = "ARTIFACT_HIDDEN"; break;
		case 17: result.second = "ARTIFACT_POSSESSED"; break;
		case 18: result.second = "ARTIFACT_CREATED"; break;
		case 19: result.second = "ARTIFACT_LOST"; break;
		case 20: result.second = "ARTIFACT_FOUND"; break;
		case 21: result.second = "ARTIFACT_RECOVERED"; break;
		case 22: result.second = "ARTIFACT_DROPPED"; break;
		case 23: result.second = "RECLAIM_SITE"; break;
		case 24: result.second = "HF_DESTROYED_SITE"; break;
		case 25: result.second = "SITE_DIED"; break;
		case 26: result.second = "SITE_RETIRED"; break;
		case 27: result.second = "ENTITY_CREATED"; break;
		case 28: result.second = "ENTITY_ACTION"; break;
		case 29: result.second = "ENTITY_INCORPORATED"; break;
		case 30: result.second = "CREATED_BUILDING"; break;
		case 31: result.second = "REPLACED_BUILDING"; break;
		case 32: result.second = "ADD_HF_SITE_LINK"; break;
		case 33: result.second = "REMOVE_HF_SITE_LINK"; break;
		case 34: result.second = "ADD_HF_HF_LINK"; break;
		case 35: result.second = "REMOVE_HF_HF_LINK"; break;
		case 36: result.second = "ENTITY_RAZED_BUILDING"; break;
		case 37: result.second = "MASTERPIECE_CREATED_ARCH_DESIGN"; break;
		case 38: result.second = "MASTERPIECE_CREATED_ARCH_CONSTRUCT"; break;
		case 39: result.second = "MASTERPIECE_CREATED_ITEM"; break;
		case 40: result.second = "MASTERPIECE_CREATED_DYE_ITEM"; break;
		case 41: result.second = "MASTERPIECE_CREATED_ITEM_IMPROVEMENT"; break;
		case 42: result.second = "MASTERPIECE_CREATED_FOOD"; break;
		case 43: result.second = "MASTERPIECE_CREATED_ENGRAVING"; break;
		case 44: result.second = "MASTERPIECE_LOST"; break;
		case 45: result.second = "CHANGE_HF_STATE"; break;
		case 46: result.second = "CHANGE_HF_JOB"; break;
		case 47: result.second = "WAR_FIELD_BATTLE"; break;
		case 48: result.second = "WAR_PLUNDERED_SITE"; break;
		case 49: result.second = "WAR_SITE_NEW_LEADER"; break;
		case 50: result.second = "WAR_SITE_TRIBUTE_FORCED"; break;
		case 51: result.second = "WAR_SITE_TAKEN_OVER"; break;
		case 52: result.second = "BODY_ABUSED"; break;
		case 53: result.second = "HIST_FIGURE_ABDUCTED"; break;
		case 54: result.second = "ITEM_STOLEN"; break;
		case 55: result.second = "HF_RAZED_BUILDING"; break;
		case 56: result.second = "CREATURE_DEVOURED"; break;
		case 57: result.second = "HIST_FIGURE_WOUNDED"; break;
		case 58: result.second = "HIST_FIGURE_SIMPLE_BATTLE_EVENT"; break;
		case 59: result.second = "CREATED_WORLD_CONSTRUCTION"; break;
		case 60: result.second = "HIST_FIGURE_REUNION"; break;
		case 61: result.second = "HIST_FIGURE_REACH_SUMMIT"; break;
		case 62: result.second = "HIST_FIGURE_TRAVEL"; break;
		case 63: result.second = "HIST_FIGURE_NEW_PET"; break;
		case 64: result.second = "ASSUME_IDENTITY"; break;
		case 65: result.second = "CREATE_ENTITY_POSITION"; break;
		case 66: result.second = "CHANGE_CREATURE_TYPE"; break;
		case 67: result.second = "HIST_FIGURE_REVIVED"; break;
		case 68: result.second = "HF_LEARNS_SECRET"; break;
		case 69: result.second = "CHANGE_HF_BODY_STATE"; break;
		case 70: result.second = "HF_ACT_ON_BUILDING"; break;
		case 71: result.second = "HF_DOES_INTERACTION"; break;
		case 72: result.second = "HF_CONFRONTED"; break;
		case 73: result.second = "ENTITY_LAW"; break;
		case 74: result.second = "HF_GAINS_SECRET_GOAL"; break;
		case 75: result.second = "ARTIFACT_STORED"; break;
		case 76: result.second = "AGREEMENT_FORMED"; break;
		case 77: result.second = "SITE_DISPUTE"; break;
		case 78: result.second = "AGREEMENT_CONCLUDED"; break;
		case 79: result.second = "INSURRECTION_STARTED"; break;
		case 80: result.second = "INSURRECTION_ENDED"; break;
		case 81: result.second = "HF_ATTACKED_SITE"; break;
		case 82: result.second = "PERFORMANCE"; break;
		case 83: result.second = "COMPETITION"; break;
		case 84: result.second = "PROCESSION"; break;
		case 85: result.second = "CEREMONY"; break;
		case 86: result.second = "KNOWLEDGE_DISCOVERED"; break;
		case 87: result.second = "ARTIFACT_TRANSFORMED"; break;
		case 88: result.second = "ARTIFACT_DESTROYED"; break;
		case 89: result.second = "HF_RELATIONSHIP_DENIED"; break;
		case 90: result.second = "REGIONPOP_INCORPORATED_INTO_ENTITY"; break;
		case 91: result.second = "POETIC_FORM_CREATED"; break;
		case 92: result.second = "MUSICAL_FORM_CREATED"; break;
		case 93: result.second = "DANCE_FORM_CREATED"; break;
		case 94: result.second = "WRITTEN_CONTENT_COMPOSED"; break;
		case 95: result.second = "CHANGE_HF_MOOD"; break;
		case 96: result.second = "ARTIFACT_CLAIM_FORMED"; break;
		case 97: result.second = "ARTIFACT_GIVEN"; break;
		case 98: result.second = "HF_ACT_ON_ARTIFACT"; break;
		case 99: result.second = "HF_RECRUITED_UNIT_TYPE_FOR_ENTITY"; break;
		case 100: result.second = "HFS_FORMED_REPUTATION_RELATIONSHIP"; break;
		case 101: result.second = "ARTIFACT_COPIED"; break;
		case 102: result.second = "SNEAK_INTO_SITE"; break;
		case 103: result.second = "SPOTTED_LEAVING_SITE"; break;
		case 104: result.second = "ENTITY_SEARCHED_SITE"; break;
		case 105: result.second = "HF_FREED"; break;
		case 106: result.second = "HIST_FIGURE_SIMPLE_ACTION"; break;
		case 107: result.second = "ENTITY_RAMPAGED_IN_SITE"; break;
		case 108: result.second = "ENTITY_FLED_SITE"; break;
		case 109: result.second = "TACTICAL_SITUATION"; break;
		case 110: result.second = "SQUAD_VS_SQUAD"; break;
		case 111: result.second = "SITE_SURRENDERED"; break;
		case 112: result.second = "ENTITY_EXPELS_HF"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_reason_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "none"; break;
		case 0: result.second = "insurrection"; break;
		case 1: result.second = "adventure"; break;
		case 2: result.second = "guide"; break;
		case 3: result.second = "rescued"; break;
		case 4: result.second = "sphere_alignment"; break;
		case 5: result.second = "maintain_balance_in_universe"; break;
		case 6: result.second = "highlight_boundaries_between_worlds"; break;
		case 7: result.second = "sow_the_seeds_of_chaos_in_the_world"; break;
		case 8: result.second = "provide_opportunities_for_courage"; break;
		case 9: result.second = "bring_death_to_the_world"; break;
		case 10: result.second = "liked_appearance"; break;
		case 11: result.second = "because_it_was_destined"; break;
		case 12: result.second = "great_fortresses_built_and_tested"; break;
		case 13: result.second = "whim"; break;
		case 14: result.second = "bring_misery_to_the_world"; break;
		case 15: result.second = "bring_murder_to_the_world"; break;
		case 16: result.second = "bring_nightmares_into_reality"; break;
		case 17: result.second = "bring_thralldom_to_the_world"; break;
		case 18: result.second = "bring_torture_to_the_world"; break;
		case 19: result.second = "provide_opportunities_for_acts_of_valor"; break;
		case 20: result.second = "bring_war_to_the_world"; break;
		case 21: result.second = "find_relative"; break;
		case 22: result.second = "offer_condolences"; break;
		case 23: result.second = "be_brought_to_safety"; break;
		case 24: result.second = "help_with_rescue"; break;
		case 25: result.second = "insufficient_work"; break;
		case 26: result.second = "work_request"; break;
		case 27: result.second = "make_weapon"; break;
		case 28: result.second = "vent_at_boss"; break;
		case 29: result.second = "cry_on_boss"; break;
		case 30: result.second = "should_have_reached_goal"; break;
		case 31: result.second = "insufficient_progress_toward_goal"; break;
		case 32: result.second = "going_wrong_direction"; break;
		case 33: result.second = "arrived_at_location"; break;
		case 34: result.second = "entity_no_longer_rules"; break;
		case 35: result.second = "left_site"; break;
		case 36: result.second = "reunited_with_loved_one"; break;
		case 37: result.second = "violent_disagreement"; break;
		case 38: result.second = "adopted"; break;
		case 39: result.second = "true_name_invocation"; break;
		case 40: result.second = "arrived_at_person"; break;
		case 41: result.second = "eradicate_beasts"; break;
		case 42: result.second = "entertain_people"; break;
		case 43: result.second = "make_a_living_as_a_warrior"; break;
		case 44: result.second = "study"; break;
		case 45: result.second = "flight"; break;
		case 46: result.second = "scholarship"; break;
		case 47: result.second = "be_with_master"; break;
		case 48: result.second = "become_citizen"; break;
		case 49: result.second = "prefers_working_alone"; break;
		case 50: result.second = "jealousy"; break;
		case 51: result.second = "glorify_hf"; break;
		case 52: result.second = "have_not_performed"; break;
		case 53: result.second = "prevented_from_leaving"; break;
		case 54: result.second = "curiosity"; break;
		case 55: result.second = "hire_on_as_mercenary"; break;
		case 56: result.second = "hire_on_as_performer"; break;
		case 57: result.second = "hire_on_as_scholar"; break;
		case 58: result.second = "drink"; break;
		case 59: result.second = "admire_architecture"; break;
		case 60: result.second = "pray"; break;
		case 61: result.second = "relax"; break;
		case 62: result.second = "danger"; break;
		case 63: result.second = "cannot_find_artifact"; break;
		case 64: result.second = "failed_mood"; break;
		case 65: result.second = "lack_of_sleep"; break;
		case 66: result.second = "trapped_in_cage"; break;
		case 67: result.second = "great_deal_of_stress"; break;
		case 68: result.second = "unable_to_leave_location"; break;
		case 69: result.second = "sanctify_hf"; break;
		case 70: result.second = "artifact_is_heirloom_of_family_hfid"; break;
		case 71: result.second = "cement_bonds_of_friendship"; break;
		case 72: result.second = "as_a_symbol_of_everlasting_peace"; break;
		case 73: result.second = "on_a_pilgrimage"; break;
		case 74: result.second = "gather_information"; break;
		case 75: result.second = "seek_sanctuary"; break;
		case 76: result.second = "part_of_trade_negotiation"; break;
		case 77: result.second = "artifact_is_symbol_of_entity_position"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_death_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "OLD_AGE"; break;
		case 1: result.second = "HUNGER"; break;
		case 2: result.second = "THIRST"; break;
		case 3: result.second = "SHOT"; break;
		case 4: result.second = "BLEED"; break;
		case 5: result.second = "DROWN"; break;
		case 6: result.second = "SUFFOCATE"; break;
		case 7: result.second = "STRUCK_DOWN"; break;
		case 8: result.second = "SCUTTLE"; break;
		case 9: result.second = "COLLISION"; break;
		case 10: result.second = "MAGMA"; break;
		case 11: result.second = "MAGMA_MIST"; break;
		case 12: result.second = "DRAGONFIRE"; break;
		case 13: result.second = "FIRE"; break;
		case 14: result.second = "SCALD"; break;
		case 15: result.second = "CAVEIN"; break;
		case 16: result.second = "DRAWBRIDGE"; break;
		case 17: result.second = "FALLING_ROCKS"; break;
		case 18: result.second = "CHASM"; break;
		case 19: result.second = "CAGE"; break;
		case 20: result.second = "MURDER"; break;
		case 21: result.second = "TRAP"; break;
		case 22: result.second = "VANISH"; break;
		case 23: result.second = "QUIT"; break;
		case 24: result.second = "ABANDON"; break;
		case 25: result.second = "HEAT"; break;
		case 26: result.second = "COLD"; break;
		case 27: result.second = "SPIKE"; break;
		case 28: result.second = "ENCASE_LAVA"; break;
		case 29: result.second = "ENCASE_MAGMA"; break;
		case 30: result.second = "ENCASE_ICE"; break;
		case 31: result.second = "BEHEAD"; break;
		case 32: result.second = "CRUCIFY"; break;
		case 33: result.second = "BURY_ALIVE"; break;
		case 34: result.second = "DROWN_ALT"; break;
		case 35: result.second = "BURN_ALIVE"; break;
		case 36: result.second = "FEED_TO_BEASTS"; break;
		case 37: result.second = "HACK_TO_PIECES"; break;
		case 38: result.second = "LEAVE_OUT_IN_AIR"; break;
		case 39: result.second = "BOIL"; break;
		case 40: result.second = "MELT"; break;
		case 41: result.second = "CONDENSE"; break;
		case 42: result.second = "SOLIDIFY"; break;
		case 43: result.second = "INFECTION"; break;
		case 44: result.second = "MEMORIALIZE"; break;
		case 45: result.second = "SCARE"; break;
		case 46: result.second = "DARKNESS"; break;
		case 47: result.second = "COLLAPSE"; break;
		case 48: result.second = "DRAIN_BLOOD"; break;
		case 49: result.second = "SLAUGHTER"; break;
		case 50: result.second = "VEHICLE"; break;
		case 51: result.second = "FALLING_OBJECT"; break;
		case 52: result.second = "LEAPT_FROM_HEIGHT"; break;
		case 53: result.second = "DROWN_ALT2"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_action_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "entity_primary_criminals"; break;
		case 1: result.second = "entity_relocate"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_masterpiece_loss_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MELT"; break;
		case 1: result.second = "MAGMA"; break;
		case 2: result.second = "FORTIFICATION"; break;
		case 3: result.second = "MINING"; break;
		case 4: result.second = "CAVEIN"; break;
		case 5: result.second = "VEGETATION"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_hist_figure_woundedst__T_injury_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Smash"; break;
		case 1: result.second = "Slash"; break;
		case 2: result.second = "Stab"; break;
		case 3: result.second = "Rip"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_simple_battle_subtype_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SCUFFLE"; break;
		case 1: result.second = "ATTACK"; break;
		case 2: result.second = "SURPRISE"; break;
		case 3: result.second = "AMBUSH"; break;
		case 4: result.second = "HAPPEN_UPON"; break;
		case 5: result.second = "CORNER"; break;
		case 6: result.second = "CONFRONT"; break;
		case 7: result.second = "LOSE_AFTER_RECEIVE_WOUND"; break;
		case 8: result.second = "LOSE_AFTER_INFLICT_WOUND"; break;
		case 9: result.second = "LOSE_AFTER_EXCHANGE_WOUND"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_histfig_body_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Active"; break;
		case 1: result.second = "BuriedAtSite"; break;
		case 2: result.second = "UnburiedAtBattlefield"; break;
		case 3: result.second = "UnburiedAtSubregion"; break;
		case 4: result.second = "UnburiedAtFeatureLayer"; break;
		case 5: result.second = "EntombedAtSite"; break;
		case 6: result.second = "UnburiedAtSite"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_hf_act_on_buildingst__T_action_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Profane"; break;
		case 1: result.second = "Disturb"; break;
		case 2: result.second = "PrayedInside"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_site_dispute_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Territory"; break;
		case 1: result.second = "WaterRights"; break;
		case 2: result.second = "GrazingRights"; break;
		case 3: result.second = "FishingRights"; break;
		case 4: result.second = "RightsOfWay"; break;
		case 5: result.second = "LivestockOwnership"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_insurrection_outcome_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "LeadershipOverthrown"; break;
		case 1: result.second = "PopulationGone"; break;
		case 2: result.second = "Crushed"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_hf_act_on_artifactst__T_action_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "View"; break;
		case 1: result.second = "AskAbout"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tactical_situation_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "attacker_strongly_favored"; break;
		case 1: result.second = "attacker_favored"; break;
		case 2: result.second = "attacker_slightly_favored"; break;
		case 3: result.second = "defender_strongly_favored"; break;
		case 4: result.second = "defender_favored"; break;
		case 5: result.second = "defender_slightly_favored"; break;
		case 6: result.second = "neither_favored"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_collection_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "WAR"; break;
		case 1: result.second = "BATTLE"; break;
		case 2: result.second = "DUEL"; break;
		case 3: result.second = "SITE_CONQUERED"; break;
		case 4: result.second = "ABDUCTION"; break;
		case 5: result.second = "THEFT"; break;
		case 6: result.second = "BEAST_ATTACK"; break;
		case 7: result.second = "JOURNEY"; break;
		case 8: result.second = "INSURRECTION"; break;
		case 9: result.second = "OCCASION"; break;
		case 10: result.second = "PERFORMANCE"; break;
		case 11: result.second = "COMPETITION"; break;
		case 12: result.second = "PROCESSION"; break;
		case 13: result.second = "CEREMONY"; break;
		case 14: result.second = "PURGE"; break;
		case 15: result.second = "RAID"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_era_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ThreePowers"; break;
		case 1: result.second = "TwoPowers"; break;
		case 2: result.second = "OnePower"; break;
		case 3: result.second = "Myth"; break;
		case 4: result.second = "Legends"; break;
		case 5: result.second = "Twilight"; break;
		case 6: result.second = "FairyTales"; break;
		case 7: result.second = "Race"; break;
		case 8: result.second = "Heroes"; break;
		case 9: result.second = "Golden"; break;
		case 10: result.second = "Death"; break;
		case 11: result.second = "Civilization"; break;
		case 12: result.second = "Emptiness"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_init_display_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "USE_GRAPHICS"; break;
		case 1: result.second = "BLACK_SPACE"; break;
		case 2: result.second = "PARTIAL_PRINT"; break;
		case 3: result.second = "FRAME_BUFFER"; break;
		case 4: result.second = "SINGLE_BUFFER"; break;
		case 5: result.second = "ACCUM_BUFFER"; break;
		case 6: result.second = "VBO"; break;
		case 7: result.second = "RENDER_2D"; break;
		case 8: result.second = "RENDER_2DHW"; break;
		case 9: result.second = "RENDER_2DASYNC"; break;
		case 10: result.second = "UNUSED_01_08"; break;
		case 11: result.second = "TEXT"; break;
		case 12: result.second = "SHADER"; break;
		case 13: result.second = "NOT_RESIZABLE"; break;
		case 14: result.second = "ARB_SYNC"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_init_media_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SOUND_OFF"; break;
		case 1: result.second = "INTRO_OFF"; break;
		case 2: result.second = "COMPRESS_SAVES"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_init_input_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MOUSE_OFF"; break;
		case 1: result.second = "MOUSE_PICTURE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_init_window_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TOPMOST"; break;
		case 1: result.second = "VSYNC_ON"; break;
		case 2: result.second = "VSYNC_OFF"; break;
		case 3: result.second = "TEXTURE_LINEAR"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interaction_effect_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ANIMATE"; break;
		case 1: result.second = "ADD_SYNDROME"; break;
		case 2: result.second = "RESURRECT"; break;
		case 3: result.second = "CLEAN"; break;
		case 4: result.second = "CONTACT"; break;
		case 5: result.second = "MATERIAL_EMISSION"; break;
		case 6: result.second = "HIDE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interaction_effect_location_hint_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "IN_WATER"; break;
		case 1: result.second = "IN_MAGMA"; break;
		case 2: result.second = "NO_WATER"; break;
		case 3: result.second = "NO_MAGMA"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interaction_source_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "REGION"; break;
		case 1: result.second = "SECRET"; break;
		case 2: result.second = "DISTURBANCE"; break;
		case 3: result.second = "DEITY"; break;
		case 4: result.second = "ATTACK"; break;
		case 5: result.second = "INGESTION"; break;
		case 6: result.second = "CREATURE_ACTION"; break;
		case 7: result.second = "UNDERGROUND_SPECIAL"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interaction_source_usage_hint_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MAJOR_CURSE"; break;
		case 1: result.second = "GREETING"; break;
		case 2: result.second = "CLEAN_SELF"; break;
		case 3: result.second = "CLEAN_FRIEND"; break;
		case 4: result.second = "ATTACK"; break;
		case 5: result.second = "FLEEING"; break;
		case 6: result.second = "NEGATIVE_SOCIAL_RESPONSE"; break;
		case 7: result.second = "TORMENT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interaction_target_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "CORPSE"; break;
		case 1: result.second = "CREATURE"; break;
		case 2: result.second = "MATERIAL"; break;
		case 3: result.second = "LOCATION"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interaction_target_location_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "CONTEXT_NONE"; break;
		case 0: result.second = "CONTEXT_REGION"; break;
		case 1: result.second = "CONTEXT_CREATURE"; break;
		case 2: result.second = "CONTEXT_ITEM"; break;
		case 3: result.second = "CONTEXT_BP"; break;
		case 4: result.second = "CONTEXT_LOCATION"; break;
		case 5: result.second = "CONTEXT_CREATURE_OR_LOCATION"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_breath_attack_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TRAILING_DUST_FLOW"; break;
		case 1: result.second = "TRAILING_VAPOR_FLOW"; break;
		case 2: result.second = "TRAILING_GAS_FLOW"; break;
		case 3: result.second = "SOLID_GLOB"; break;
		case 4: result.second = "LIQUID_GLOB"; break;
		case 5: result.second = "UNDIRECTED_GAS"; break;
		case 6: result.second = "UNDIRECTED_VAPOR"; break;
		case 7: result.second = "UNDIRECTED_DUST"; break;
		case 8: result.second = "WEB_SPRAY"; break;
		case 9: result.second = "DRAGONFIRE"; break;
		case 10: result.second = "FIREJET"; break;
		case 11: result.second = "FIREBALL"; break;
		case 12: result.second = "WEATHER_CREEPING_GAS"; break;
		case 13: result.second = "WEATHER_CREEPING_VAPOR"; break;
		case 14: result.second = "WEATHER_CREEPING_DUST"; break;
		case 15: result.second = "WEATHER_FALLING_MATERIAL"; break;
		case 16: result.second = "SPATTER_POWDER"; break;
		case 17: result.second = "SPATTER_LIQUID"; break;
		case 18: result.second = "UNDIRECTED_ITEM_CLOUD"; break;
		case 19: result.second = "TRAILING_ITEM_FLOW"; break;
		case 20: result.second = "OTHER"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_item_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "BAR"; break;
		case 1: result.second = "SMALLGEM"; break;
		case 2: result.second = "BLOCKS"; break;
		case 3: result.second = "ROUGH"; break;
		case 4: result.second = "BOULDER"; break;
		case 5: result.second = "WOOD"; break;
		case 6: result.second = "DOOR"; break;
		case 7: result.second = "FLOODGATE"; break;
		case 8: result.second = "BED"; break;
		case 9: result.second = "CHAIR"; break;
		case 10: result.second = "CHAIN"; break;
		case 11: result.second = "FLASK"; break;
		case 12: result.second = "GOBLET"; break;
		case 13: result.second = "INSTRUMENT"; break;
		case 14: result.second = "TOY"; break;
		case 15: result.second = "WINDOW"; break;
		case 16: result.second = "CAGE"; break;
		case 17: result.second = "BARREL"; break;
		case 18: result.second = "BUCKET"; break;
		case 19: result.second = "ANIMALTRAP"; break;
		case 20: result.second = "TABLE"; break;
		case 21: result.second = "COFFIN"; break;
		case 22: result.second = "STATUE"; break;
		case 23: result.second = "CORPSE"; break;
		case 24: result.second = "WEAPON"; break;
		case 25: result.second = "ARMOR"; break;
		case 26: result.second = "SHOES"; break;
		case 27: result.second = "SHIELD"; break;
		case 28: result.second = "HELM"; break;
		case 29: result.second = "GLOVES"; break;
		case 30: result.second = "BOX"; break;
		case 31: result.second = "BIN"; break;
		case 32: result.second = "ARMORSTAND"; break;
		case 33: result.second = "WEAPONRACK"; break;
		case 34: result.second = "CABINET"; break;
		case 35: result.second = "FIGURINE"; break;
		case 36: result.second = "AMULET"; break;
		case 37: result.second = "SCEPTER"; break;
		case 38: result.second = "AMMO"; break;
		case 39: result.second = "CROWN"; break;
		case 40: result.second = "RING"; break;
		case 41: result.second = "EARRING"; break;
		case 42: result.second = "BRACELET"; break;
		case 43: result.second = "GEM"; break;
		case 44: result.second = "ANVIL"; break;
		case 45: result.second = "CORPSEPIECE"; break;
		case 46: result.second = "REMAINS"; break;
		case 47: result.second = "MEAT"; break;
		case 48: result.second = "FISH"; break;
		case 49: result.second = "FISH_RAW"; break;
		case 50: result.second = "VERMIN"; break;
		case 51: result.second = "PET"; break;
		case 52: result.second = "SEEDS"; break;
		case 53: result.second = "PLANT"; break;
		case 54: result.second = "SKIN_TANNED"; break;
		case 55: result.second = "PLANT_GROWTH"; break;
		case 56: result.second = "THREAD"; break;
		case 57: result.second = "CLOTH"; break;
		case 58: result.second = "TOTEM"; break;
		case 59: result.second = "PANTS"; break;
		case 60: result.second = "BACKPACK"; break;
		case 61: result.second = "QUIVER"; break;
		case 62: result.second = "CATAPULTPARTS"; break;
		case 63: result.second = "BALLISTAPARTS"; break;
		case 64: result.second = "SIEGEAMMO"; break;
		case 65: result.second = "BALLISTAARROWHEAD"; break;
		case 66: result.second = "TRAPPARTS"; break;
		case 67: result.second = "TRAPCOMP"; break;
		case 68: result.second = "DRINK"; break;
		case 69: result.second = "POWDER_MISC"; break;
		case 70: result.second = "CHEESE"; break;
		case 71: result.second = "FOOD"; break;
		case 72: result.second = "LIQUID_MISC"; break;
		case 73: result.second = "COIN"; break;
		case 74: result.second = "GLOB"; break;
		case 75: result.second = "ROCK"; break;
		case 76: result.second = "PIPE_SECTION"; break;
		case 77: result.second = "HATCH_COVER"; break;
		case 78: result.second = "GRATE"; break;
		case 79: result.second = "QUERN"; break;
		case 80: result.second = "MILLSTONE"; break;
		case 81: result.second = "SPLINT"; break;
		case 82: result.second = "CRUTCH"; break;
		case 83: result.second = "TRACTION_BENCH"; break;
		case 84: result.second = "ORTHOPEDIC_CAST"; break;
		case 85: result.second = "TOOL"; break;
		case 86: result.second = "SLAB"; break;
		case 87: result.second = "EGG"; break;
		case 88: result.second = "BOOK"; break;
		case 89: result.second = "SHEET"; break;
		case 90: result.second = "BRANCH"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ammo_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "HAS_EDGE_ATTACK"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_armor_general_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SOFT"; break;
		case 1: result.second = "HARD"; break;
		case 2: result.second = "METAL"; break;
		case 3: result.second = "BARRED"; break;
		case 4: result.second = "SCALED"; break;
		case 5: result.second = "LEATHER"; break;
		case 6: result.second = "SHAPED"; break;
		case 7: result.second = "CHAIN_METAL_TEXT"; break;
		case 8: result.second = "STRUCTURAL_ELASTICITY_WOVEN_THREAD"; break;
		case 9: result.second = "STRUCTURAL_ELASTICITY_CHAIN_METAL"; break;
		case 10: result.second = "STRUCTURAL_ELASTICITY_CHAIN_ALL"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_armor_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_gloves_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_helm_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_instrument_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "INDEFINITE_PITCH"; break;
		case 1: result.second = "PLACED_AS_BUILDING"; break;
		case 2: result.second = "METAL_MAT"; break;
		case 3: result.second = "STONE_MAT"; break;
		case 4: result.second = "WOOD_MAT"; break;
		case 5: result.second = "GLASS_MAT"; break;
		case 6: result.second = "CERAMIC_MAT"; break;
		case 7: result.second = "SHELL_MAT"; break;
		case 8: result.second = "BONE_MAT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_sound_production_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "PLUCKED_BY_BP"; break;
		case 1: result.second = "PLUCKED"; break;
		case 2: result.second = "BOWED"; break;
		case 3: result.second = "STRUCK_BY_BP"; break;
		case 4: result.second = "STRUCK"; break;
		case 5: result.second = "VIBRATE_BP_AGAINST_OPENING"; break;
		case 6: result.second = "BLOW_AGAINST_FIPPLE"; break;
		case 7: result.second = "BLOW_OVER_OPENING_SIDE"; break;
		case 8: result.second = "BLOW_OVER_OPENING_END"; break;
		case 9: result.second = "BLOW_OVER_SINGLE_REED"; break;
		case 10: result.second = "BLOW_OVER_DOUBLE_REED"; break;
		case 11: result.second = "BLOW_OVER_FREE_REED"; break;
		case 12: result.second = "STRUCK_TOGETHER"; break;
		case 13: result.second = "SHAKEN"; break;
		case 14: result.second = "SCRAPED"; break;
		case 15: result.second = "FRICTION"; break;
		case 16: result.second = "RESONATOR"; break;
		case 17: result.second = "BAG_OVER_REED"; break;
		case 18: result.second = "AIR_OVER_REED"; break;
		case 19: result.second = "AIR_OVER_FREE_REED"; break;
		case 20: result.second = "AIR_AGAINST_FIPPLE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_pitch_choice_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MEMBRANE_POSITION"; break;
		case 1: result.second = "SUBPART_CHOICE"; break;
		case 2: result.second = "KEYBOARD"; break;
		case 3: result.second = "STOPPING_FRET"; break;
		case 4: result.second = "STOPPING_AGAINST_BODY"; break;
		case 5: result.second = "STOPPING_HOLE"; break;
		case 6: result.second = "STOPPING_HOLE_KEY"; break;
		case 7: result.second = "SLIDE"; break;
		case 8: result.second = "HARMONIC_SERIES"; break;
		case 9: result.second = "VALVE_ROUTES_AIR"; break;
		case 10: result.second = "BP_IN_BELL"; break;
		case 11: result.second = "FOOT_PEDALS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tuning_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "PEGS"; break;
		case 1: result.second = "ADJUSTABLE_BRIDGES"; break;
		case 2: result.second = "CROOKS"; break;
		case 3: result.second = "TIGHTENING"; break;
		case 4: result.second = "LEVERS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_timbre_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "CLEAR"; break;
		case 1: result.second = "NOISY"; break;
		case 2: result.second = "FULL"; break;
		case 3: result.second = "THIN"; break;
		case 4: result.second = "ROUND"; break;
		case 5: result.second = "SHARP"; break;
		case 6: result.second = "SMOOTH"; break;
		case 7: result.second = "CHOPPY"; break;
		case 8: result.second = "STEADY"; break;
		case 9: result.second = "EVOLVING"; break;
		case 10: result.second = "STRONG"; break;
		case 11: result.second = "DELICATE"; break;
		case 12: result.second = "BRIGHT"; break;
		case 13: result.second = "GRACEFUL"; break;
		case 14: result.second = "SPARSE"; break;
		case 15: result.second = "BREATHY"; break;
		case 16: result.second = "STRAINED"; break;
		case 17: result.second = "BROAD"; break;
		case 18: result.second = "LIGHT"; break;
		case 19: result.second = "MELLOW"; break;
		case 20: result.second = "WOBBLING"; break;
		case 21: result.second = "FOCUSED"; break;
		case 22: result.second = "EVEN"; break;
		case 23: result.second = "FLUID"; break;
		case 24: result.second = "VIBRATING"; break;
		case 25: result.second = "QUAVERING"; break;
		case 26: result.second = "EERIE"; break;
		case 27: result.second = "FRAGILE"; break;
		case 28: result.second = "BRITTLE"; break;
		case 29: result.second = "PURE_"; break;
		case 30: result.second = "PIERCING"; break;
		case 31: result.second = "STRIDENT"; break;
		case 32: result.second = "WAVERING"; break;
		case 33: result.second = "HARSH"; break;
		case 34: result.second = "REEDY"; break;
		case 35: result.second = "NASAL"; break;
		case 36: result.second = "BUZZY"; break;
		case 37: result.second = "ROUGH"; break;
		case 38: result.second = "WARM"; break;
		case 39: result.second = "RUGGED"; break;
		case 40: result.second = "HEAVY"; break;
		case 41: result.second = "FLAT"; break;
		case 42: result.second = "DARK"; break;
		case 43: result.second = "CRISP"; break;
		case 44: result.second = "SONOROUS"; break;
		case 45: result.second = "WATERY"; break;
		case 46: result.second = "GENTLE"; break;
		case 47: result.second = "SLICING"; break;
		case 48: result.second = "LIQUID"; break;
		case 49: result.second = "RAUCOUS"; break;
		case 50: result.second = "BREEZY"; break;
		case 51: result.second = "RASPY"; break;
		case 52: result.second = "WISPY"; break;
		case 53: result.second = "SHRILL"; break;
		case 54: result.second = "MUDDY"; break;
		case 55: result.second = "RICH"; break;
		case 56: result.second = "DULL"; break;
		case 57: result.second = "FLOATING"; break;
		case 58: result.second = "RINGING"; break;
		case 59: result.second = "RESONANT"; break;
		case 60: result.second = "SWEET"; break;
		case 61: result.second = "RIPPLING"; break;
		case 62: result.second = "SPARKLING"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_pants_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_shoes_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "METAL_ARMOR_LEVELS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tool_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "HARD_MAT"; break;
		case 1: result.second = "METAL_MAT"; break;
		case 2: result.second = "HAS_EDGE_ATTACK"; break;
		case 3: result.second = "METAL_WEAPON_MAT"; break;
		case 4: result.second = "UNIMPROVABLE"; break;
		case 5: result.second = "SOFT_MAT"; break;
		case 6: result.second = "WOOD_MAT"; break;
		case 7: result.second = "INVERTED_TILE"; break;
		case 8: result.second = "FURNITURE"; break;
		case 9: result.second = "LEATHER_MAT"; break;
		case 10: result.second = "SILK_MAT"; break;
		case 11: result.second = "THREAD_PLANT_MAT"; break;
		case 12: result.second = "GLASS_MAT"; break;
		case 13: result.second = "CERAMIC_MAT"; break;
		case 14: result.second = "STONE_MAT"; break;
		case 15: result.second = "SHELL_MAT"; break;
		case 16: result.second = "BONE_MAT"; break;
		case 17: result.second = "NO_DEFAULT_JOB"; break;
		case 18: result.second = "INCOMPLETE_ITEM"; break;
		case 19: result.second = "SHEET_MAT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tool_uses_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "LIQUID_COOKING"; break;
		case 1: result.second = "LIQUID_SCOOP"; break;
		case 2: result.second = "GRIND_POWDER_RECEPTACLE"; break;
		case 3: result.second = "GRIND_POWDER_GRINDER"; break;
		case 4: result.second = "MEAT_CARVING"; break;
		case 5: result.second = "MEAT_BONING"; break;
		case 6: result.second = "MEAT_SLICING"; break;
		case 7: result.second = "MEAT_CLEAVING"; break;
		case 8: result.second = "HOLD_MEAT_FOR_CARVING"; break;
		case 9: result.second = "MEAL_CONTAINER"; break;
		case 10: result.second = "LIQUID_CONTAINER"; break;
		case 11: result.second = "FOOD_STORAGE"; break;
		case 12: result.second = "HIVE"; break;
		case 13: result.second = "NEST_BOX"; break;
		case 14: result.second = "SMALL_OBJECT_STORAGE"; break;
		case 15: result.second = "TRACK_CART"; break;
		case 16: result.second = "HEAVY_OBJECT_HAULING"; break;
		case 17: result.second = "STAND_AND_WORK_ABOVE"; break;
		case 18: result.second = "ROLL_UP_SHEET"; break;
		case 19: result.second = "PROTECT_FOLDED_SHEETS"; break;
		case 20: result.second = "CONTAIN_WRITING"; break;
		case 21: result.second = "BOOKCASE"; break;
		case 22: result.second = "DISPLAY_OBJECT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_toy_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "HARD_MAT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_trapcomp_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "IS_SCREW"; break;
		case 1: result.second = "IS_SPIKE"; break;
		case 2: result.second = "WOOD"; break;
		case 3: result.second = "METAL"; break;
		case 4: result.second = "HAS_EDGE_ATTACK"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_weapon_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "CAN_STONE"; break;
		case 1: result.second = "HAS_EDGE_ATTACK"; break;
		case 2: result.second = "TRAINING"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_items_other_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "ANY"; break;
		case 0: result.second = "IN_PLAY"; break;
		case 1: result.second = "ANY_ARTIFACT"; break;
		case 2: result.second = "WEAPON"; break;
		case 3: result.second = "ANY_WEAPON"; break;
		case 4: result.second = "ANY_SPIKE"; break;
		case 5: result.second = "ANY_TRUE_ARMOR"; break;
		case 6: result.second = "ANY_ARMOR_HELM"; break;
		case 7: result.second = "ANY_ARMOR_SHOES"; break;
		case 8: result.second = "SHIELD"; break;
		case 9: result.second = "ANY_ARMOR_GLOVES"; break;
		case 10: result.second = "ANY_ARMOR_PANTS"; break;
		case 11: result.second = "QUIVER"; break;
		case 12: result.second = "SPLINT"; break;
		case 13: result.second = "ORTHOPEDIC_CAST"; break;
		case 14: result.second = "CRUTCH"; break;
		case 15: result.second = "BACKPACK"; break;
		case 16: result.second = "AMMO"; break;
		case 17: result.second = "WOOD"; break;
		case 18: result.second = "BRANCH"; break;
		case 19: result.second = "BOULDER"; break;
		case 20: result.second = "ROCK"; break;
		case 21: result.second = "ANY_REFUSE"; break;
		case 22: result.second = "ANY_GOOD_FOOD"; break;
		case 23: result.second = "ANY_AUTO_CLEAN"; break;
		case 24: result.second = "ANY_GENERIC24"; break;
		case 25: result.second = "ANY_GENERIC25"; break;
		case 26: result.second = "ANY_FURNITURE"; break;
		case 27: result.second = "ANY_CAGE_OR_TRAP"; break;
		case 28: result.second = "ANY_EDIBLE_RAW"; break;
		case 29: result.second = "ANY_EDIBLE_CARNIVORE"; break;
		case 30: result.second = "ANY_EDIBLE_BONECARN"; break;
		case 31: result.second = "ANY_EDIBLE_VERMIN"; break;
		case 32: result.second = "ANY_EDIBLE_VERMIN_BOX"; break;
		case 33: result.second = "ANY_CAN_ROT"; break;
		case 34: result.second = "ANY_MURDERED"; break;
		case 35: result.second = "ANY_DEAD_DWARF"; break;
		case 36: result.second = "ANY_GENERIC36"; break;
		case 37: result.second = "ANY_GENERIC37"; break;
		case 38: result.second = "ANY_GENERIC38"; break;
		case 39: result.second = "ANY_GENERIC39"; break;
		case 40: result.second = "DOOR"; break;
		case 41: result.second = "FLOODGATE"; break;
		case 42: result.second = "HATCH_COVER"; break;
		case 43: result.second = "GRATE"; break;
		case 44: result.second = "CAGE"; break;
		case 45: result.second = "FLASK"; break;
		case 46: result.second = "WINDOW"; break;
		case 47: result.second = "GOBLET"; break;
		case 48: result.second = "INSTRUMENT"; break;
		case 49: result.second = "INSTRUMENT_STATIONARY"; break;
		case 50: result.second = "TOY"; break;
		case 51: result.second = "TOOL"; break;
		case 52: result.second = "BUCKET"; break;
		case 53: result.second = "BARREL"; break;
		case 54: result.second = "CHAIN"; break;
		case 55: result.second = "ANIMALTRAP"; break;
		case 56: result.second = "BED"; break;
		case 57: result.second = "TRACTION_BENCH"; break;
		case 58: result.second = "CHAIR"; break;
		case 59: result.second = "COFFIN"; break;
		case 60: result.second = "TABLE"; break;
		case 61: result.second = "STATUE"; break;
		case 62: result.second = "SLAB"; break;
		case 63: result.second = "QUERN"; break;
		case 64: result.second = "MILLSTONE"; break;
		case 65: result.second = "BOX"; break;
		case 66: result.second = "BIN"; break;
		case 67: result.second = "ARMORSTAND"; break;
		case 68: result.second = "WEAPONRACK"; break;
		case 69: result.second = "CABINET"; break;
		case 70: result.second = "ANVIL"; break;
		case 71: result.second = "CATAPULTPARTS"; break;
		case 72: result.second = "BALLISTAPARTS"; break;
		case 73: result.second = "SIEGEAMMO"; break;
		case 74: result.second = "TRAPPARTS"; break;
		case 75: result.second = "ANY_WEBS"; break;
		case 76: result.second = "PIPE_SECTION"; break;
		case 77: result.second = "ANY_ENCASED"; break;
		case 78: result.second = "ANY_IN_CONSTRUCTION"; break;
		case 79: result.second = "DRINK"; break;
		case 80: result.second = "ANY_DRINK"; break;
		case 81: result.second = "LIQUID_MISC"; break;
		case 82: result.second = "POWDER_MISC"; break;
		case 83: result.second = "ANY_COOKABLE"; break;
		case 84: result.second = "ANY_GENERIC84"; break;
		case 85: result.second = "VERMIN"; break;
		case 86: result.second = "PET"; break;
		case 87: result.second = "ANY_CRITTER"; break;
		case 88: result.second = "COIN"; break;
		case 89: result.second = "GLOB"; break;
		case 90: result.second = "TRAPCOMP"; break;
		case 91: result.second = "BAR"; break;
		case 92: result.second = "SMALLGEM"; break;
		case 93: result.second = "BLOCKS"; break;
		case 94: result.second = "ROUGH"; break;
		case 95: result.second = "ANY_CORPSE"; break;
		case 96: result.second = "CORPSE"; break;
		case 97: result.second = "BOOK"; break;
		case 98: result.second = "FIGURINE"; break;
		case 99: result.second = "AMULET"; break;
		case 100: result.second = "SCEPTER"; break;
		case 101: result.second = "CROWN"; break;
		case 102: result.second = "RING"; break;
		case 103: result.second = "EARRING"; break;
		case 104: result.second = "BRACELET"; break;
		case 105: result.second = "GEM"; break;
		case 106: result.second = "CORPSEPIECE"; break;
		case 107: result.second = "REMAINS"; break;
		case 108: result.second = "MEAT"; break;
		case 109: result.second = "FISH"; break;
		case 110: result.second = "FISH_RAW"; break;
		case 111: result.second = "EGG"; break;
		case 112: result.second = "SEEDS"; break;
		case 113: result.second = "PLANT"; break;
		case 114: result.second = "SKIN_TANNED"; break;
		case 115: result.second = "PLANT_GROWTH"; break;
		case 116: result.second = "THREAD"; break;
		case 117: result.second = "CLOTH"; break;
		case 118: result.second = "SHEET"; break;
		case 119: result.second = "TOTEM"; break;
		case 120: result.second = "PANTS"; break;
		case 121: result.second = "CHEESE"; break;
		case 122: result.second = "FOOD"; break;
		case 123: result.second = "BALLISTAARROWHEAD"; break;
		case 124: result.second = "ARMOR"; break;
		case 125: result.second = "SHOES"; break;
		case 126: result.second = "HELM"; break;
		case 127: result.second = "GLOVES"; break;
		case 128: result.second = "ANY_GENERIC128"; break;
		case 129: result.second = "FOOD_STORAGE"; break;
		case 130: result.second = "ANY_RECENTLY_DROPPED"; break;
		case 131: result.second = "ANY_MELT_DESIGNATED"; break;
		case 132: result.second = "BAD"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_job_item_vector_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ANY"; break;
		case 1: result.second = "IN_PLAY"; break;
		case 2: result.second = "ANY_ARTIFACT"; break;
		case 3: result.second = "WEAPON"; break;
		case 4: result.second = "ANY_WEAPON"; break;
		case 5: result.second = "ANY_SPIKE"; break;
		case 6: result.second = "ANY_TRUE_ARMOR"; break;
		case 7: result.second = "ANY_ARMOR_HELM"; break;
		case 8: result.second = "ANY_ARMOR_SHOES"; break;
		case 9: result.second = "SHIELD"; break;
		case 10: result.second = "ANY_ARMOR_GLOVES"; break;
		case 11: result.second = "ANY_ARMOR_PANTS"; break;
		case 12: result.second = "QUIVER"; break;
		case 13: result.second = "SPLINT"; break;
		case 14: result.second = "ANY_14"; break;
		case 15: result.second = "CRUTCH"; break;
		case 16: result.second = "BACKPACK"; break;
		case 17: result.second = "AMMO"; break;
		case 18: result.second = "WOOD"; break;
		case 19: result.second = "BOULDER"; break;
		case 20: result.second = "ROCK"; break;
		case 21: result.second = "ANY_REFUSE"; break;
		case 22: result.second = "ANY_GOOD_FOOD"; break;
		case 23: result.second = "ANY_AUTO_CLEAN"; break;
		case 24: result.second = "ANY_GENERIC24"; break;
		case 25: result.second = "ANY_GENERIC25"; break;
		case 26: result.second = "ANY_FURNITURE"; break;
		case 27: result.second = "ANY_CAGE_OR_TRAP"; break;
		case 28: result.second = "ANY_EDIBLE_RAW"; break;
		case 29: result.second = "ANY_EDIBLE_CARNIVORE"; break;
		case 30: result.second = "ANY_EDIBLE_BONECARN"; break;
		case 31: result.second = "ANY_EDIBLE_VERMIN"; break;
		case 32: result.second = "ANY_EDIBLE_VERMIN_BOX"; break;
		case 33: result.second = "ANY_CAN_ROT"; break;
		case 34: result.second = "ANY_MURDERED"; break;
		case 35: result.second = "ANY_DEAD_DWARF"; break;
		case 36: result.second = "ANY_GENERIC36"; break;
		case 37: result.second = "ANY_GENERIC37"; break;
		case 38: result.second = "ANY_GENERIC38"; break;
		case 39: result.second = "ANY_GENERIC39"; break;
		case 40: result.second = "DOOR"; break;
		case 41: result.second = "FLOODGATE"; break;
		case 42: result.second = "HATCH_COVER"; break;
		case 43: result.second = "GRATE"; break;
		case 44: result.second = "CAGE"; break;
		case 45: result.second = "FLASK"; break;
		case 46: result.second = "WINDOW"; break;
		case 47: result.second = "GOBLET"; break;
		case 48: result.second = "INSTRUMENT"; break;
		case 49: result.second = "TOY"; break;
		case 50: result.second = "BUCKET"; break;
		case 51: result.second = "BARREL"; break;
		case 52: result.second = "CHAIN"; break;
		case 53: result.second = "ANIMALTRAP"; break;
		case 54: result.second = "BED"; break;
		case 55: result.second = "TRACTION_BENCH"; break;
		case 56: result.second = "CHAIR"; break;
		case 57: result.second = "COFFIN"; break;
		case 58: result.second = "TABLE"; break;
		case 59: result.second = "STATUE"; break;
		case 60: result.second = "QUERN"; break;
		case 61: result.second = "MILLSTONE"; break;
		case 62: result.second = "BOX"; break;
		case 63: result.second = "BIN"; break;
		case 64: result.second = "ARMORSTAND"; break;
		case 65: result.second = "WEAPONRACK"; break;
		case 66: result.second = "CABINET"; break;
		case 67: result.second = "ANVIL"; break;
		case 68: result.second = "CATAPULTPARTS"; break;
		case 69: result.second = "BALLISTAPARTS"; break;
		case 70: result.second = "SIEGEAMMO"; break;
		case 71: result.second = "TRAPPARTS"; break;
		case 72: result.second = "ANY_WEBS"; break;
		case 73: result.second = "PIPE_SECTION"; break;
		case 74: result.second = "ANY_ENCASED"; break;
		case 75: result.second = "ANY_IN_CONSTRUCTION"; break;
		case 76: result.second = "DRINK"; break;
		case 77: result.second = "ANY_DRINK"; break;
		case 78: result.second = "LIQUID_MISC"; break;
		case 79: result.second = "POWDER_MISC"; break;
		case 80: result.second = "ANY_COOKABLE"; break;
		case 81: result.second = "ANY_GENERIC84"; break;
		case 82: result.second = "VERMIN"; break;
		case 83: result.second = "PET"; break;
		case 84: result.second = "ANY_CRITTER"; break;
		case 85: result.second = "COIN"; break;
		case 86: result.second = "GLOB"; break;
		case 87: result.second = "ANY_RECENTLY_DROPPED"; break;
		case 88: result.second = "ANY_MELT_DESIGNATED"; break;
		case 89: result.second = "BAD"; break;
		case 90: result.second = "TRAPCOMP"; break;
		case 91: result.second = "BAR"; break;
		case 92: result.second = "SMALLGEM"; break;
		case 93: result.second = "BLOCKS"; break;
		case 94: result.second = "ROUGH"; break;
		case 95: result.second = "CORPSE"; break;
		case 96: result.second = "FIGURINE"; break;
		case 97: result.second = "AMULET"; break;
		case 98: result.second = "SCEPTER"; break;
		case 99: result.second = "CROWN"; break;
		case 100: result.second = "RING"; break;
		case 101: result.second = "EARRING"; break;
		case 102: result.second = "BRACELET"; break;
		case 103: result.second = "GEM"; break;
		case 104: result.second = "CORPSEPIECE"; break;
		case 105: result.second = "REMAINS"; break;
		case 106: result.second = "MEAT"; break;
		case 107: result.second = "FISH"; break;
		case 108: result.second = "FISH_RAW"; break;
		case 109: result.second = "SEEDS"; break;
		case 110: result.second = "PLANT"; break;
		case 111: result.second = "SKIN_TANNED"; break;
		case 112: result.second = "PLANT_GROWTH"; break;
		case 113: result.second = "THREAD"; break;
		case 114: result.second = "CLOTH"; break;
		case 115: result.second = "TOTEM"; break;
		case 116: result.second = "PANTS"; break;
		case 117: result.second = "CHEESE"; break;
		case 118: result.second = "FOOD"; break;
		case 119: result.second = "BALLISTAARROWHEAD"; break;
		case 120: result.second = "ARMOR"; break;
		case 121: result.second = "SHOES"; break;
		case 122: result.second = "HELM"; break;
		case 123: result.second = "GLOVES"; break;
		case 124: result.second = "ANY_124"; break;
		case 125: result.second = "ANY_125"; break;
		case 126: result.second = "EGG"; break;
		case 127: result.second = "ANY_127"; break;
		case 128: result.second = "ANY_CORPSE"; break;
		case 129: result.second = "BOOK"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_improvement_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ART_IMAGE"; break;
		case 1: result.second = "COVERED"; break;
		case 2: result.second = "RINGS_HANGING"; break;
		case 3: result.second = "BANDS"; break;
		case 4: result.second = "SPIKES"; break;
		case 5: result.second = "ITEMSPECIFIC"; break;
		case 6: result.second = "THREAD"; break;
		case 7: result.second = "CLOTH"; break;
		case 8: result.second = "SEWN_IMAGE"; break;
		case 9: result.second = "PAGES"; break;
		case 10: result.second = "ILLUSTRATION"; break;
		case 11: result.second = "INSTRUMENT_PIECE"; break;
		case 12: result.second = "WRITING"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_itemimprovement_specific_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "HANDLE"; break;
		case 1: result.second = "ROLLERS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_written_content_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Manual"; break;
		case 1: result.second = "Guide"; break;
		case 2: result.second = "Chronicle"; break;
		case 3: result.second = "ShortStory"; break;
		case 4: result.second = "Novel"; break;
		case 5: result.second = "Biography"; break;
		case 6: result.second = "Autobiography"; break;
		case 7: result.second = "Poem"; break;
		case 8: result.second = "Play"; break;
		case 9: result.second = "Letter"; break;
		case 10: result.second = "Essay"; break;
		case 11: result.second = "Dialog"; break;
		case 12: result.second = "MusicalComposition"; break;
		case 13: result.second = "Choreography"; break;
		case 14: result.second = "ComparativeBiography"; break;
		case 15: result.second = "BiographicalDictionary"; break;
		case 16: result.second = "Genealogy"; break;
		case 17: result.second = "Encyclopedia"; break;
		case 18: result.second = "CulturalHistory"; break;
		case 19: result.second = "CulturalComparison"; break;
		case 20: result.second = "AlternateHistory"; break;
		case 21: result.second = "TreatiseOnTechnologicalEvolution"; break;
		case 22: result.second = "Dictionary"; break;
		case 23: result.second = "StarChart"; break;
		case 24: result.second = "StarCatalogue"; break;
		case 25: result.second = "Atlas"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_written_content_style_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Meandering"; break;
		case 1: result.second = "Cheerful"; break;
		case 2: result.second = "Depressing"; break;
		case 3: result.second = "Rigid"; break;
		case 4: result.second = "Serious"; break;
		case 5: result.second = "Disjointed"; break;
		case 6: result.second = "Ornate"; break;
		case 7: result.second = "Forceful"; break;
		case 8: result.second = "Humorous"; break;
		case 9: result.second = "Immature"; break;
		case 10: result.second = "SelfIndulgent"; break;
		case 11: result.second = "Touching"; break;
		case 12: result.second = "Compassionate"; break;
		case 13: result.second = "Vicious"; break;
		case 14: result.second = "Concise"; break;
		case 15: result.second = "Scornful"; break;
		case 16: result.second = "Witty"; break;
		case 17: result.second = "Ranting"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_item_magicness_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Sparkle"; break;
		case 1: result.second = "AirWarped"; break;
		case 2: result.second = "Whistle"; break;
		case 3: result.second = "OddlySquare"; break;
		case 4: result.second = "SmallBumps"; break;
		case 5: result.second = "EarthSmell"; break;
		case 6: result.second = "Lightning"; break;
		case 7: result.second = "GrayHairs"; break;
		case 8: result.second = "RustlingLeaves"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_item_quality_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Ordinary"; break;
		case 1: result.second = "WellCrafted"; break;
		case 2: result.second = "FinelyCrafted"; break;
		case 3: result.second = "Superior"; break;
		case 4: result.second = "Exceptional"; break;
		case 5: result.second = "Masterful"; break;
		case 6: result.second = "Artifact"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_slab_engraving_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "Slab"; break;
		case 0: result.second = "Memorial"; break;
		case 1: result.second = "CraftShopSign"; break;
		case 2: result.second = "WeaponsmithShopSign"; break;
		case 3: result.second = "ArmorsmithShopSign"; break;
		case 4: result.second = "GeneralStoreSign"; break;
		case 5: result.second = "FoodShopSign"; break;
		case 6: result.second = "Secrets"; break;
		case 7: result.second = "FoodImportsSign"; break;
		case 8: result.second = "ClothingImportsSign"; break;
		case 9: result.second = "GeneralImportsSign"; break;
		case 10: result.second = "ClothShopSign"; break;
		case 11: result.second = "LeatherShopSign"; break;
		case 12: result.second = "WovenClothingShopSign"; break;
		case 13: result.second = "LeatherClothingShopSign"; break;
		case 14: result.second = "BoneCarverShopSign"; break;
		case 15: result.second = "GemCutterShopSign"; break;
		case 16: result.second = "WeaponsmithShopSign2"; break;
		case 17: result.second = "BowyerShopSign"; break;
		case 18: result.second = "BlacksmithShopSign"; break;
		case 19: result.second = "ArmorsmithShopSign2"; break;
		case 20: result.second = "MetalCraftShopSign"; break;
		case 21: result.second = "LeatherGoodsShopSign"; break;
		case 22: result.second = "CarpenterShopSign"; break;
		case 23: result.second = "StoneFurnitureShopSign"; break;
		case 24: result.second = "MetalFurnitureShopSign"; break;
		case 25: result.second = "DemonIdentity"; break;
		case 26: result.second = "TavernSign"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_corpse_material_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Plant"; break;
		case 1: result.second = "Silk"; break;
		case 2: result.second = "Leather"; break;
		case 3: result.second = "Bone"; break;
		case 4: result.second = "Shell"; break;
		case 5: result.second = "anon_1"; break;
		case 6: result.second = "Soap"; break;
		case 7: result.second = "Tooth"; break;
		case 8: result.second = "Horn"; break;
		case 9: result.second = "Pearl"; break;
		case 10: result.second = "HairWool"; break;
		case 11: result.second = "Yarn"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_job_type_class_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Misc"; break;
		case 1: result.second = "Digging"; break;
		case 2: result.second = "Building"; break;
		case 3: result.second = "Hauling"; break;
		case 4: result.second = "LifeSupport"; break;
		case 5: result.second = "TidyUp"; break;
		case 6: result.second = "Leisure"; break;
		case 7: result.second = "Gathering"; break;
		case 8: result.second = "Manufacture"; break;
		case 9: result.second = "Improvement"; break;
		case 10: result.second = "Crime"; break;
		case 11: result.second = "LawEnforcement"; break;
		case 12: result.second = "StrangeMood"; break;
		case 13: result.second = "UnitHandling"; break;
		case 14: result.second = "SiegeWeapon"; break;
		case 15: result.second = "Medicine"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_job_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "CarveFortification"; break;
		case 1: result.second = "DetailWall"; break;
		case 2: result.second = "DetailFloor"; break;
		case 3: result.second = "Dig"; break;
		case 4: result.second = "CarveUpwardStaircase"; break;
		case 5: result.second = "CarveDownwardStaircase"; break;
		case 6: result.second = "CarveUpDownStaircase"; break;
		case 7: result.second = "CarveRamp"; break;
		case 8: result.second = "DigChannel"; break;
		case 9: result.second = "FellTree"; break;
		case 10: result.second = "GatherPlants"; break;
		case 11: result.second = "RemoveConstruction"; break;
		case 12: result.second = "CollectWebs"; break;
		case 13: result.second = "BringItemToDepot"; break;
		case 14: result.second = "BringItemToShop"; break;
		case 15: result.second = "Eat"; break;
		case 16: result.second = "GetProvisions"; break;
		case 17: result.second = "Drink"; break;
		case 18: result.second = "Drink2"; break;
		case 19: result.second = "FillWaterskin"; break;
		case 20: result.second = "FillWaterskin2"; break;
		case 21: result.second = "Sleep"; break;
		case 22: result.second = "CollectSand"; break;
		case 23: result.second = "Fish"; break;
		case 24: result.second = "Hunt"; break;
		case 25: result.second = "HuntVermin"; break;
		case 26: result.second = "Kidnap"; break;
		case 27: result.second = "BeatCriminal"; break;
		case 28: result.second = "StartingFistFight"; break;
		case 29: result.second = "CollectTaxes"; break;
		case 30: result.second = "GuardTaxCollector"; break;
		case 31: result.second = "CatchLiveLandAnimal"; break;
		case 32: result.second = "CatchLiveFish"; break;
		case 33: result.second = "ReturnKill"; break;
		case 34: result.second = "CheckChest"; break;
		case 35: result.second = "StoreOwnedItem"; break;
		case 36: result.second = "PlaceItemInTomb"; break;
		case 37: result.second = "StoreItemInStockpile"; break;
		case 38: result.second = "StoreItemInBag"; break;
		case 39: result.second = "StoreItemInHospital"; break;
		case 40: result.second = "StoreItemInLocation"; break;
		case 41: result.second = "anon_1"; break;
		case 42: result.second = "StoreWeapon"; break;
		case 43: result.second = "StoreArmor"; break;
		case 44: result.second = "StoreItemInBarrel"; break;
		case 45: result.second = "StoreItemInBin"; break;
		case 46: result.second = "SeekArtifact"; break;
		case 47: result.second = "SeekInfant"; break;
		case 48: result.second = "AttendParty"; break;
		case 49: result.second = "GoShopping"; break;
		case 50: result.second = "GoShopping2"; break;
		case 51: result.second = "Clean"; break;
		case 52: result.second = "Rest"; break;
		case 53: result.second = "PickupEquipment"; break;
		case 54: result.second = "DumpItem"; break;
		case 55: result.second = "StrangeMoodCrafter"; break;
		case 56: result.second = "StrangeMoodJeweller"; break;
		case 57: result.second = "StrangeMoodForge"; break;
		case 58: result.second = "StrangeMoodMagmaForge"; break;
		case 59: result.second = "StrangeMoodBrooding"; break;
		case 60: result.second = "StrangeMoodFell"; break;
		case 61: result.second = "StrangeMoodCarpenter"; break;
		case 62: result.second = "StrangeMoodMason"; break;
		case 63: result.second = "StrangeMoodBowyer"; break;
		case 64: result.second = "StrangeMoodTanner"; break;
		case 65: result.second = "StrangeMoodWeaver"; break;
		case 66: result.second = "StrangeMoodGlassmaker"; break;
		case 67: result.second = "StrangeMoodMechanics"; break;
		case 68: result.second = "ConstructBuilding"; break;
		case 69: result.second = "ConstructDoor"; break;
		case 70: result.second = "ConstructFloodgate"; break;
		case 71: result.second = "ConstructBed"; break;
		case 72: result.second = "ConstructThrone"; break;
		case 73: result.second = "ConstructCoffin"; break;
		case 74: result.second = "ConstructTable"; break;
		case 75: result.second = "ConstructChest"; break;
		case 76: result.second = "ConstructBin"; break;
		case 77: result.second = "ConstructArmorStand"; break;
		case 78: result.second = "ConstructWeaponRack"; break;
		case 79: result.second = "ConstructCabinet"; break;
		case 80: result.second = "ConstructStatue"; break;
		case 81: result.second = "ConstructBlocks"; break;
		case 82: result.second = "MakeRawGlass"; break;
		case 83: result.second = "MakeCrafts"; break;
		case 84: result.second = "MintCoins"; break;
		case 85: result.second = "CutGems"; break;
		case 86: result.second = "CutGlass"; break;
		case 87: result.second = "EncrustWithGems"; break;
		case 88: result.second = "EncrustWithGlass"; break;
		case 89: result.second = "DestroyBuilding"; break;
		case 90: result.second = "SmeltOre"; break;
		case 91: result.second = "MeltMetalObject"; break;
		case 92: result.second = "ExtractMetalStrands"; break;
		case 93: result.second = "PlantSeeds"; break;
		case 94: result.second = "HarvestPlants"; break;
		case 95: result.second = "TrainHuntingAnimal"; break;
		case 96: result.second = "TrainWarAnimal"; break;
		case 97: result.second = "MakeWeapon"; break;
		case 98: result.second = "ForgeAnvil"; break;
		case 99: result.second = "ConstructCatapultParts"; break;
		case 100: result.second = "ConstructBallistaParts"; break;
		case 101: result.second = "MakeArmor"; break;
		case 102: result.second = "MakeHelm"; break;
		case 103: result.second = "MakePants"; break;
		case 104: result.second = "StudWith"; break;
		case 105: result.second = "ButcherAnimal"; break;
		case 106: result.second = "PrepareRawFish"; break;
		case 107: result.second = "MillPlants"; break;
		case 108: result.second = "BaitTrap"; break;
		case 109: result.second = "MilkCreature"; break;
		case 110: result.second = "MakeCheese"; break;
		case 111: result.second = "ProcessPlants"; break;
		case 112: result.second = "anon_2"; break;
		case 113: result.second = "ProcessPlantsVial"; break;
		case 114: result.second = "ProcessPlantsBarrel"; break;
		case 115: result.second = "PrepareMeal"; break;
		case 116: result.second = "WeaveCloth"; break;
		case 117: result.second = "MakeGloves"; break;
		case 118: result.second = "MakeShoes"; break;
		case 119: result.second = "MakeShield"; break;
		case 120: result.second = "MakeCage"; break;
		case 121: result.second = "MakeChain"; break;
		case 122: result.second = "MakeFlask"; break;
		case 123: result.second = "MakeGoblet"; break;
		case 124: result.second = "anon_3"; break;
		case 125: result.second = "MakeToy"; break;
		case 126: result.second = "MakeAnimalTrap"; break;
		case 127: result.second = "MakeBarrel"; break;
		case 128: result.second = "MakeBucket"; break;
		case 129: result.second = "MakeWindow"; break;
		case 130: result.second = "MakeTotem"; break;
		case 131: result.second = "MakeAmmo"; break;
		case 132: result.second = "DecorateWith"; break;
		case 133: result.second = "MakeBackpack"; break;
		case 134: result.second = "MakeQuiver"; break;
		case 135: result.second = "MakeBallistaArrowHead"; break;
		case 136: result.second = "AssembleSiegeAmmo"; break;
		case 137: result.second = "LoadCatapult"; break;
		case 138: result.second = "LoadBallista"; break;
		case 139: result.second = "FireCatapult"; break;
		case 140: result.second = "FireBallista"; break;
		case 141: result.second = "ConstructMechanisms"; break;
		case 142: result.second = "MakeTrapComponent"; break;
		case 143: result.second = "LoadCageTrap"; break;
		case 144: result.second = "LoadStoneTrap"; break;
		case 145: result.second = "LoadWeaponTrap"; break;
		case 146: result.second = "CleanTrap"; break;
		case 147: result.second = "CastSpell"; break;
		case 148: result.second = "LinkBuildingToTrigger"; break;
		case 149: result.second = "PullLever"; break;
		case 150: result.second = "anon_4"; break;
		case 151: result.second = "ExtractFromPlants"; break;
		case 152: result.second = "ExtractFromRawFish"; break;
		case 153: result.second = "ExtractFromLandAnimal"; break;
		case 154: result.second = "TameVermin"; break;
		case 155: result.second = "TameAnimal"; break;
		case 156: result.second = "ChainAnimal"; break;
		case 157: result.second = "UnchainAnimal"; break;
		case 158: result.second = "UnchainPet"; break;
		case 159: result.second = "ReleaseLargeCreature"; break;
		case 160: result.second = "ReleasePet"; break;
		case 161: result.second = "ReleaseSmallCreature"; break;
		case 162: result.second = "HandleSmallCreature"; break;
		case 163: result.second = "HandleLargeCreature"; break;
		case 164: result.second = "CageLargeCreature"; break;
		case 165: result.second = "CageSmallCreature"; break;
		case 166: result.second = "RecoverWounded"; break;
		case 167: result.second = "DiagnosePatient"; break;
		case 168: result.second = "ImmobilizeBreak"; break;
		case 169: result.second = "DressWound"; break;
		case 170: result.second = "CleanPatient"; break;
		case 171: result.second = "Surgery"; break;
		case 172: result.second = "Suture"; break;
		case 173: result.second = "SetBone"; break;
		case 174: result.second = "PlaceInTraction"; break;
		case 175: result.second = "DrainAquarium"; break;
		case 176: result.second = "FillAquarium"; break;
		case 177: result.second = "FillPond"; break;
		case 178: result.second = "GiveWater"; break;
		case 179: result.second = "GiveFood"; break;
		case 180: result.second = "GiveWater2"; break;
		case 181: result.second = "GiveFood2"; break;
		case 182: result.second = "RecoverPet"; break;
		case 183: result.second = "PitLargeAnimal"; break;
		case 184: result.second = "PitSmallAnimal"; break;
		case 185: result.second = "SlaughterAnimal"; break;
		case 186: result.second = "MakeCharcoal"; break;
		case 187: result.second = "MakeAsh"; break;
		case 188: result.second = "MakeLye"; break;
		case 189: result.second = "MakePotashFromLye"; break;
		case 190: result.second = "FertilizeField"; break;
		case 191: result.second = "MakePotashFromAsh"; break;
		case 192: result.second = "DyeThread"; break;
		case 193: result.second = "DyeCloth"; break;
		case 194: result.second = "SewImage"; break;
		case 195: result.second = "MakePipeSection"; break;
		case 196: result.second = "OperatePump"; break;
		case 197: result.second = "ManageWorkOrders"; break;
		case 198: result.second = "UpdateStockpileRecords"; break;
		case 199: result.second = "TradeAtDepot"; break;
		case 200: result.second = "ConstructHatchCover"; break;
		case 201: result.second = "ConstructGrate"; break;
		case 202: result.second = "RemoveStairs"; break;
		case 203: result.second = "ConstructQuern"; break;
		case 204: result.second = "ConstructMillstone"; break;
		case 205: result.second = "ConstructSplint"; break;
		case 206: result.second = "ConstructCrutch"; break;
		case 207: result.second = "ConstructTractionBench"; break;
		case 208: result.second = "CleanSelf"; break;
		case 209: result.second = "BringCrutch"; break;
		case 210: result.second = "ApplyCast"; break;
		case 211: result.second = "CustomReaction"; break;
		case 212: result.second = "ConstructSlab"; break;
		case 213: result.second = "EngraveSlab"; break;
		case 214: result.second = "ShearCreature"; break;
		case 215: result.second = "SpinThread"; break;
		case 216: result.second = "PenLargeAnimal"; break;
		case 217: result.second = "PenSmallAnimal"; break;
		case 218: result.second = "MakeTool"; break;
		case 219: result.second = "CollectClay"; break;
		case 220: result.second = "InstallColonyInHive"; break;
		case 221: result.second = "CollectHiveProducts"; break;
		case 222: result.second = "CauseTrouble"; break;
		case 223: result.second = "DrinkBlood"; break;
		case 224: result.second = "ReportCrime"; break;
		case 225: result.second = "ExecuteCriminal"; break;
		case 226: result.second = "TrainAnimal"; break;
		case 227: result.second = "CarveTrack"; break;
		case 228: result.second = "PushTrackVehicle"; break;
		case 229: result.second = "PlaceTrackVehicle"; break;
		case 230: result.second = "StoreItemInVehicle"; break;
		case 231: result.second = "GeldAnimal"; break;
		case 232: result.second = "MakeFigurine"; break;
		case 233: result.second = "MakeAmulet"; break;
		case 234: result.second = "MakeScepter"; break;
		case 235: result.second = "MakeCrown"; break;
		case 236: result.second = "MakeRing"; break;
		case 237: result.second = "MakeEarring"; break;
		case 238: result.second = "MakeBracelet"; break;
		case 239: result.second = "MakeGem"; break;
		case 240: result.second = "PutItemOnDisplay"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_job_subtype_surgery_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Surgery"; break;
		case 1: result.second = "StopBleeding"; break;
		case 2: result.second = "RepairCompoundFracture"; break;
		case 3: result.second = "RemoveRottenTissue"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_job_art_specification__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "HistoricalFigure"; break;
		case 1: result.second = "Site"; break;
		case 2: result.second = "Entity"; break;
		case 3: result.second = "ArtImage"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_manager_order_condition_order__T_condition_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Activated"; break;
		case 1: result.second = "Completed"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_guild_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Miners"; break;
		case 1: result.second = "Carpenters"; break;
		case 2: result.second = "Masons"; break;
		case 3: result.second = "Metalsmiths"; break;
		case 4: result.second = "Jewelers"; break;
		case 5: result.second = "Craftsmen"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interface_key_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "NONE"; break;
		case 1: result.second = "SELECT"; break;
		case 2: result.second = "SEC_SELECT"; break;
		case 3: result.second = "DESELECT"; break;
		case 4: result.second = "SELECT_ALL"; break;
		case 5: result.second = "DESELECT_ALL"; break;
		case 6: result.second = "LEAVESCREEN"; break;
		case 7: result.second = "LEAVESCREEN_ALL"; break;
		case 8: result.second = "CLOSE_MEGA_ANNOUNCEMENT"; break;
		case 9: result.second = "OPTIONS"; break;
		case 10: result.second = "OPTION_EXPORT"; break;
		case 11: result.second = "HELP"; break;
		case 12: result.second = "TOGGLE_FULLSCREEN"; break;
		case 13: result.second = "MOVIES"; break;
		case 14: result.second = "ZOOM_IN"; break;
		case 15: result.second = "ZOOM_OUT"; break;
		case 16: result.second = "ZOOM_TOGGLE"; break;
		case 17: result.second = "ZOOM_RESET"; break;
		case 18: result.second = "MOVIE_RECORD"; break;
		case 19: result.second = "MOVIE_PLAY"; break;
		case 20: result.second = "MOVIE_SAVE"; break;
		case 21: result.second = "MOVIE_LOAD"; break;
		case 22: result.second = "TOGGLE_TTF"; break;
		case 23: result.second = "FPS_UP"; break;
		case 24: result.second = "FPS_DOWN"; break;
		case 25: result.second = "CHANGETAB"; break;
		case 26: result.second = "SEC_CHANGETAB"; break;
		case 27: result.second = "STANDARDSCROLL_UP"; break;
		case 28: result.second = "STANDARDSCROLL_DOWN"; break;
		case 29: result.second = "STANDARDSCROLL_LEFT"; break;
		case 30: result.second = "STANDARDSCROLL_RIGHT"; break;
		case 31: result.second = "STANDARDSCROLL_PAGEUP"; break;
		case 32: result.second = "STANDARDSCROLL_PAGEDOWN"; break;
		case 33: result.second = "SECONDSCROLL_UP"; break;
		case 34: result.second = "SECONDSCROLL_DOWN"; break;
		case 35: result.second = "SECONDSCROLL_PAGEUP"; break;
		case 36: result.second = "SECONDSCROLL_PAGEDOWN"; break;
		case 37: result.second = "CURSOR_UP"; break;
		case 38: result.second = "CURSOR_DOWN"; break;
		case 39: result.second = "CURSOR_LEFT"; break;
		case 40: result.second = "CURSOR_RIGHT"; break;
		case 41: result.second = "CURSOR_UPLEFT"; break;
		case 42: result.second = "CURSOR_UPRIGHT"; break;
		case 43: result.second = "CURSOR_DOWNLEFT"; break;
		case 44: result.second = "CURSOR_DOWNRIGHT"; break;
		case 45: result.second = "CURSOR_UP_FAST"; break;
		case 46: result.second = "CURSOR_DOWN_FAST"; break;
		case 47: result.second = "CURSOR_LEFT_FAST"; break;
		case 48: result.second = "CURSOR_RIGHT_FAST"; break;
		case 49: result.second = "CURSOR_UPLEFT_FAST"; break;
		case 50: result.second = "CURSOR_UPRIGHT_FAST"; break;
		case 51: result.second = "CURSOR_DOWNLEFT_FAST"; break;
		case 52: result.second = "CURSOR_DOWNRIGHT_FAST"; break;
		case 53: result.second = "CURSOR_UP_Z"; break;
		case 54: result.second = "CURSOR_DOWN_Z"; break;
		case 55: result.second = "CURSOR_UP_Z_AUX"; break;
		case 56: result.second = "CURSOR_DOWN_Z_AUX"; break;
		case 57: result.second = "MENU_CONFIRM"; break;
		case 58: result.second = "SAVE_BINDINGS"; break;
		case 59: result.second = "LOAD_BINDINGS"; break;
		case 60: result.second = "MACRO_BREAK"; break;
		case 61: result.second = "RECORD_MACRO"; break;
		case 62: result.second = "PLAY_MACRO"; break;
		case 63: result.second = "SAVE_MACRO"; break;
		case 64: result.second = "LOAD_MACRO"; break;
		case 65: result.second = "PREFIX"; break;
		case 66: result.second = "OPTION1"; break;
		case 67: result.second = "OPTION2"; break;
		case 68: result.second = "OPTION3"; break;
		case 69: result.second = "OPTION4"; break;
		case 70: result.second = "OPTION5"; break;
		case 71: result.second = "OPTION6"; break;
		case 72: result.second = "OPTION7"; break;
		case 73: result.second = "OPTION8"; break;
		case 74: result.second = "OPTION9"; break;
		case 75: result.second = "OPTION10"; break;
		case 76: result.second = "OPTION11"; break;
		case 77: result.second = "OPTION12"; break;
		case 78: result.second = "OPTION13"; break;
		case 79: result.second = "OPTION14"; break;
		case 80: result.second = "OPTION15"; break;
		case 81: result.second = "OPTION16"; break;
		case 82: result.second = "OPTION17"; break;
		case 83: result.second = "OPTION18"; break;
		case 84: result.second = "OPTION19"; break;
		case 85: result.second = "OPTION20"; break;
		case 86: result.second = "SEC_OPTION1"; break;
		case 87: result.second = "SEC_OPTION2"; break;
		case 88: result.second = "SEC_OPTION3"; break;
		case 89: result.second = "SEC_OPTION4"; break;
		case 90: result.second = "SEC_OPTION5"; break;
		case 91: result.second = "SEC_OPTION6"; break;
		case 92: result.second = "SEC_OPTION7"; break;
		case 93: result.second = "SEC_OPTION8"; break;
		case 94: result.second = "SEC_OPTION9"; break;
		case 95: result.second = "SEC_OPTION10"; break;
		case 96: result.second = "SEC_OPTION11"; break;
		case 97: result.second = "SEC_OPTION12"; break;
		case 98: result.second = "SEC_OPTION13"; break;
		case 99: result.second = "SEC_OPTION14"; break;
		case 100: result.second = "SEC_OPTION15"; break;
		case 101: result.second = "SEC_OPTION16"; break;
		case 102: result.second = "SEC_OPTION17"; break;
		case 103: result.second = "SEC_OPTION18"; break;
		case 104: result.second = "SEC_OPTION19"; break;
		case 105: result.second = "SEC_OPTION20"; break;
		case 106: result.second = "CUSTOM_A"; break;
		case 107: result.second = "CUSTOM_B"; break;
		case 108: result.second = "CUSTOM_C"; break;
		case 109: result.second = "CUSTOM_D"; break;
		case 110: result.second = "CUSTOM_E"; break;
		case 111: result.second = "CUSTOM_F"; break;
		case 112: result.second = "CUSTOM_G"; break;
		case 113: result.second = "CUSTOM_H"; break;
		case 114: result.second = "CUSTOM_I"; break;
		case 115: result.second = "CUSTOM_J"; break;
		case 116: result.second = "CUSTOM_K"; break;
		case 117: result.second = "CUSTOM_L"; break;
		case 118: result.second = "CUSTOM_M"; break;
		case 119: result.second = "CUSTOM_N"; break;
		case 120: result.second = "CUSTOM_O"; break;
		case 121: result.second = "CUSTOM_P"; break;
		case 122: result.second = "CUSTOM_Q"; break;
		case 123: result.second = "CUSTOM_R"; break;
		case 124: result.second = "CUSTOM_S"; break;
		case 125: result.second = "CUSTOM_T"; break;
		case 126: result.second = "CUSTOM_U"; break;
		case 127: result.second = "CUSTOM_V"; break;
		case 128: result.second = "CUSTOM_W"; break;
		case 129: result.second = "CUSTOM_X"; break;
		case 130: result.second = "CUSTOM_Y"; break;
		case 131: result.second = "CUSTOM_Z"; break;
		case 132: result.second = "CUSTOM_SHIFT_A"; break;
		case 133: result.second = "CUSTOM_SHIFT_B"; break;
		case 134: result.second = "CUSTOM_SHIFT_C"; break;
		case 135: result.second = "CUSTOM_SHIFT_D"; break;
		case 136: result.second = "CUSTOM_SHIFT_E"; break;
		case 137: result.second = "CUSTOM_SHIFT_F"; break;
		case 138: result.second = "CUSTOM_SHIFT_G"; break;
		case 139: result.second = "CUSTOM_SHIFT_H"; break;
		case 140: result.second = "CUSTOM_SHIFT_I"; break;
		case 141: result.second = "CUSTOM_SHIFT_J"; break;
		case 142: result.second = "CUSTOM_SHIFT_K"; break;
		case 143: result.second = "CUSTOM_SHIFT_L"; break;
		case 144: result.second = "CUSTOM_SHIFT_M"; break;
		case 145: result.second = "CUSTOM_SHIFT_N"; break;
		case 146: result.second = "CUSTOM_SHIFT_O"; break;
		case 147: result.second = "CUSTOM_SHIFT_P"; break;
		case 148: result.second = "CUSTOM_SHIFT_Q"; break;
		case 149: result.second = "CUSTOM_SHIFT_R"; break;
		case 150: result.second = "CUSTOM_SHIFT_S"; break;
		case 151: result.second = "CUSTOM_SHIFT_T"; break;
		case 152: result.second = "CUSTOM_SHIFT_U"; break;
		case 153: result.second = "CUSTOM_SHIFT_V"; break;
		case 154: result.second = "CUSTOM_SHIFT_W"; break;
		case 155: result.second = "CUSTOM_SHIFT_X"; break;
		case 156: result.second = "CUSTOM_SHIFT_Y"; break;
		case 157: result.second = "CUSTOM_SHIFT_Z"; break;
		case 158: result.second = "CUSTOM_CTRL_A"; break;
		case 159: result.second = "CUSTOM_CTRL_B"; break;
		case 160: result.second = "CUSTOM_CTRL_C"; break;
		case 161: result.second = "CUSTOM_CTRL_D"; break;
		case 162: result.second = "CUSTOM_CTRL_E"; break;
		case 163: result.second = "CUSTOM_CTRL_F"; break;
		case 164: result.second = "CUSTOM_CTRL_G"; break;
		case 165: result.second = "CUSTOM_CTRL_H"; break;
		case 166: result.second = "CUSTOM_CTRL_I"; break;
		case 167: result.second = "CUSTOM_CTRL_J"; break;
		case 168: result.second = "CUSTOM_CTRL_K"; break;
		case 169: result.second = "CUSTOM_CTRL_L"; break;
		case 170: result.second = "CUSTOM_CTRL_M"; break;
		case 171: result.second = "CUSTOM_CTRL_N"; break;
		case 172: result.second = "CUSTOM_CTRL_O"; break;
		case 173: result.second = "CUSTOM_CTRL_P"; break;
		case 174: result.second = "CUSTOM_CTRL_Q"; break;
		case 175: result.second = "CUSTOM_CTRL_R"; break;
		case 176: result.second = "CUSTOM_CTRL_S"; break;
		case 177: result.second = "CUSTOM_CTRL_T"; break;
		case 178: result.second = "CUSTOM_CTRL_U"; break;
		case 179: result.second = "CUSTOM_CTRL_V"; break;
		case 180: result.second = "CUSTOM_CTRL_W"; break;
		case 181: result.second = "CUSTOM_CTRL_X"; break;
		case 182: result.second = "CUSTOM_CTRL_Y"; break;
		case 183: result.second = "CUSTOM_CTRL_Z"; break;
		case 184: result.second = "CUSTOM_ALT_A"; break;
		case 185: result.second = "CUSTOM_ALT_B"; break;
		case 186: result.second = "CUSTOM_ALT_C"; break;
		case 187: result.second = "CUSTOM_ALT_D"; break;
		case 188: result.second = "CUSTOM_ALT_E"; break;
		case 189: result.second = "CUSTOM_ALT_F"; break;
		case 190: result.second = "CUSTOM_ALT_G"; break;
		case 191: result.second = "CUSTOM_ALT_H"; break;
		case 192: result.second = "CUSTOM_ALT_I"; break;
		case 193: result.second = "CUSTOM_ALT_J"; break;
		case 194: result.second = "CUSTOM_ALT_K"; break;
		case 195: result.second = "CUSTOM_ALT_L"; break;
		case 196: result.second = "CUSTOM_ALT_M"; break;
		case 197: result.second = "CUSTOM_ALT_N"; break;
		case 198: result.second = "CUSTOM_ALT_O"; break;
		case 199: result.second = "CUSTOM_ALT_P"; break;
		case 200: result.second = "CUSTOM_ALT_Q"; break;
		case 201: result.second = "CUSTOM_ALT_R"; break;
		case 202: result.second = "CUSTOM_ALT_S"; break;
		case 203: result.second = "CUSTOM_ALT_T"; break;
		case 204: result.second = "CUSTOM_ALT_U"; break;
		case 205: result.second = "CUSTOM_ALT_V"; break;
		case 206: result.second = "CUSTOM_ALT_W"; break;
		case 207: result.second = "CUSTOM_ALT_X"; break;
		case 208: result.second = "CUSTOM_ALT_Y"; break;
		case 209: result.second = "CUSTOM_ALT_Z"; break;
		case 210: result.second = "WORLD_PARAM_TITLE"; break;
		case 211: result.second = "WORLD_PARAM_ADD"; break;
		case 212: result.second = "WORLD_PARAM_COPY"; break;
		case 213: result.second = "WORLD_PARAM_DELETE"; break;
		case 214: result.second = "WORLD_PARAM_NAME_RANDOM"; break;
		case 215: result.second = "WORLD_PARAM_NAME_ENTER"; break;
		case 216: result.second = "WORLD_PARAM_SEED_RANDOM"; break;
		case 217: result.second = "WORLD_PARAM_SEED_ENTER"; break;
		case 218: result.second = "WORLD_PARAM_LOAD"; break;
		case 219: result.second = "WORLD_PARAM_SAVE"; break;
		case 220: result.second = "WORLD_PARAM_DIM_X_UP"; break;
		case 221: result.second = "WORLD_PARAM_DIM_X_DOWN"; break;
		case 222: result.second = "WORLD_PARAM_DIM_Y_UP"; break;
		case 223: result.second = "WORLD_PARAM_DIM_Y_DOWN"; break;
		case 224: result.second = "WORLD_PARAM_SET"; break;
		case 225: result.second = "WORLD_PARAM_INCREASE"; break;
		case 226: result.second = "WORLD_PARAM_DECREASE"; break;
		case 227: result.second = "WORLD_PARAM_ENTER_VALUE"; break;
		case 228: result.second = "WORLD_PARAM_NULLIFY"; break;
		case 229: result.second = "WORLD_PARAM_PRESET"; break;
		case 230: result.second = "WORLD_PARAM_REJECT_CONTINUE"; break;
		case 231: result.second = "WORLD_PARAM_REJECT_ABORT"; break;
		case 232: result.second = "WORLD_PARAM_REJECT_ALLOW_THIS"; break;
		case 233: result.second = "WORLD_PARAM_REJECT_ALLOW_ALL"; break;
		case 234: result.second = "WORLD_GEN_CONTINUE"; break;
		case 235: result.second = "WORLD_GEN_USE"; break;
		case 236: result.second = "WORLD_GEN_ABORT"; break;
		case 237: result.second = "WORLDGEN_EXPORT_MAP"; break;
		case 238: result.second = "LEGENDS_EXPORT_MAP"; break;
		case 239: result.second = "LEGENDS_EXPORT_XML"; break;
		case 240: result.second = "LEGENDS_EXPORT_DETAILED_MAP"; break;
		case 241: result.second = "LEGENDS_TOGGLE_CIVSITE"; break;
		case 242: result.second = "LEGENDS_STRING_FILTER"; break;
		case 243: result.second = "A_RETURN_TO_ARENA"; break;
		case 244: result.second = "A_MOVE_N"; break;
		case 245: result.second = "A_MOVE_S"; break;
		case 246: result.second = "A_MOVE_E"; break;
		case 247: result.second = "A_MOVE_W"; break;
		case 248: result.second = "A_MOVE_NW"; break;
		case 249: result.second = "A_MOVE_NE"; break;
		case 250: result.second = "A_MOVE_SW"; break;
		case 251: result.second = "A_MOVE_SE"; break;
		case 252: result.second = "A_MOVE_SAME_SQUARE"; break;
		case 253: result.second = "A_CARE_MOVE_N"; break;
		case 254: result.second = "A_CARE_MOVE_S"; break;
		case 255: result.second = "A_CARE_MOVE_E"; break;
		case 256: result.second = "A_CARE_MOVE_W"; break;
		case 257: result.second = "A_CARE_MOVE_NW"; break;
		case 258: result.second = "A_CARE_MOVE_NE"; break;
		case 259: result.second = "A_CARE_MOVE_SW"; break;
		case 260: result.second = "A_CARE_MOVE_SE"; break;
		case 261: result.second = "A_CARE_MOVE_UPDOWN"; break;
		case 262: result.second = "A_MOVE_N_UP"; break;
		case 263: result.second = "A_MOVE_S_UP"; break;
		case 264: result.second = "A_MOVE_E_UP"; break;
		case 265: result.second = "A_MOVE_W_UP"; break;
		case 266: result.second = "A_MOVE_NW_UP"; break;
		case 267: result.second = "A_MOVE_NE_UP"; break;
		case 268: result.second = "A_MOVE_SW_UP"; break;
		case 269: result.second = "A_MOVE_SE_UP"; break;
		case 270: result.second = "A_MOVE_UP"; break;
		case 271: result.second = "A_MOVE_N_DOWN"; break;
		case 272: result.second = "A_MOVE_S_DOWN"; break;
		case 273: result.second = "A_MOVE_E_DOWN"; break;
		case 274: result.second = "A_MOVE_W_DOWN"; break;
		case 275: result.second = "A_MOVE_NW_DOWN"; break;
		case 276: result.second = "A_MOVE_NE_DOWN"; break;
		case 277: result.second = "A_MOVE_SW_DOWN"; break;
		case 278: result.second = "A_MOVE_SE_DOWN"; break;
		case 279: result.second = "A_MOVE_DOWN"; break;
		case 280: result.second = "A_MOVE_UP_AUX"; break;
		case 281: result.second = "A_MOVE_DOWN_AUX"; break;
		case 282: result.second = "A_COMBAT_ATTACK"; break;
		case 283: result.second = "A_COMBAT_DODGE"; break;
		case 284: result.second = "A_COMBAT_CHARGEDEF"; break;
		case 285: result.second = "A_STATUS"; break;
		case 286: result.second = "A_STATUS_WRESTLE"; break;
		case 287: result.second = "A_STATUS_CUSTOMIZE"; break;
		case 288: result.second = "A_STATUS_KILLS"; break;
		case 289: result.second = "A_STATUS_HEALTH"; break;
		case 290: result.second = "A_STATUS_ATT_SKILL"; break;
		case 291: result.second = "A_STATUS_DESC"; break;
		case 292: result.second = "A_CLEAR_ANNOUNCEMENTS"; break;
		case 293: result.second = "A_SLEEP"; break;
		case 294: result.second = "A_SLEEP_SLEEP"; break;
		case 295: result.second = "A_SLEEP_WAIT"; break;
		case 296: result.second = "A_SLEEP_DAWN"; break;
		case 297: result.second = "A_WAIT"; break;
		case 298: result.second = "A_SHORT_WAIT"; break;
		case 299: result.second = "A_ATTACK"; break;
		case 300: result.second = "A_ATTACK_CONFIRM"; break;
		case 301: result.second = "QUICK_ATTACK"; break;
		case 302: result.second = "HEAVY_ATTACK"; break;
		case 303: result.second = "WILD_ATTACK"; break;
		case 304: result.second = "PRECISE_ATTACK"; break;
		case 305: result.second = "CHARGE_ATTACK"; break;
		case 306: result.second = "MULTI_ATTACK"; break;
		case 307: result.second = "A_LOOK"; break;
		case 308: result.second = "A_SEARCH"; break;
		case 309: result.second = "A_ODOR"; break;
		case 310: result.second = "A_DISPLAY_ODOR"; break;
		case 311: result.second = "A_YIELD"; break;
		case 312: result.second = "A_DISPLAY_TRACKS"; break;
		case 313: result.second = "A_FRESHEST_TRACK"; break;
		case 314: result.second = "A_INV_DRAW_WEAPON"; break;
		case 315: result.second = "A_JUMP"; break;
		case 316: result.second = "A_HOLD"; break;
		case 317: result.second = "A_TALK"; break;
		case 318: result.second = "A_ASSUME_IDENTITY_NEW"; break;
		case 319: result.second = "A_ASSUME_IDENTITY_NONE"; break;
		case 320: result.second = "A_ASSUME_IDENTITY_NAME"; break;
		case 321: result.second = "A_ASSUME_IDENTITY_ORIGIN"; break;
		case 322: result.second = "A_ASSUME_IDENTITY_PROFESSION"; break;
		case 323: result.second = "A_ASSUME_IDENTITY_WORSHIP"; break;
		case 324: result.second = "A_INTERACT"; break;
		case 325: result.second = "A_ACTION"; break;
		case 326: result.second = "A_ACTION_CREATE"; break;
		case 327: result.second = "A_ACTION_BUTCHER"; break;
		case 328: result.second = "A_ACTION_ABILITY"; break;
		case 329: result.second = "A_ACTION_POWER"; break;
		case 330: result.second = "A_ACTION_COMPOSE"; break;
		case 331: result.second = "A_ACTION_WRITE"; break;
		case 332: result.second = "A_CONSTRUCTION"; break;
		case 333: result.second = "ADV_CONSTRUCTION_ZONE_NEW"; break;
		case 334: result.second = "ADV_CONSTRUCTION_ZONE_EDIT"; break;
		case 335: result.second = "ADV_CONSTRUCTION_ZONE_ASSIGN"; break;
		case 336: result.second = "ADV_CONSTRUCTION_ZONE_DELETE"; break;
		case 337: result.second = "ADV_CONSTRUCTION_ZONE_RECT"; break;
		case 338: result.second = "ADV_CONSTRUCTION_ZONE_FLOW"; break;
		case 339: result.second = "ADV_CONSTRUCTION_ZONE_REMOVE_RECT"; break;
		case 340: result.second = "ADV_CONSTRUCTION_STAIR_UPDOWN"; break;
		case 341: result.second = "ADV_CONSTRUCTION_REMOVE_PLANS"; break;
		case 342: result.second = "ADV_CONSTRUCTION_REMOVE_EXISTING"; break;
		case 343: result.second = "ADV_CONSTRUCTION_MATERIAL"; break;
		case 344: result.second = "ADV_CONSTRUCTION_CONSTRUCTION"; break;
		case 345: result.second = "ADV_CONSTRUCTION_BUILDING"; break;
		case 346: result.second = "ADV_CONSTRUCTION_ZONE"; break;
		case 347: result.second = "ADV_CONSTRUCTION_WORK_MENU"; break;
		case 348: result.second = "ADV_CONSTRUCTION_NAME_SITE"; break;
		case 349: result.second = "ADV_CONSTRUCTION_YOU_WORK"; break;
		case 350: result.second = "ADV_CONSTRUCTION_START"; break;
		case 351: result.second = "A_COMPOSE_FILTER"; break;
		case 352: result.second = "A_INV_LOOK"; break;
		case 353: result.second = "A_INV_REMOVE"; break;
		case 354: result.second = "A_INV_WEAR"; break;
		case 355: result.second = "A_INV_EATDRINK"; break;
		case 356: result.second = "A_INV_PUTIN"; break;
		case 357: result.second = "A_INV_DROP"; break;
		case 358: result.second = "A_GROUND"; break;
		case 359: result.second = "A_THROW"; break;
		case 360: result.second = "A_SHOOT"; break;
		case 361: result.second = "A_ANNOUNCEMENTS"; break;
		case 362: result.second = "A_COMBAT"; break;
		case 363: result.second = "A_MOVEMENT"; break;
		case 364: result.second = "A_MOVEMENT_SWIM"; break;
		case 365: result.second = "A_SNEAK"; break;
		case 366: result.second = "A_SPEED_SNEAK"; break;
		case 367: result.second = "A_CENTER"; break;
		case 368: result.second = "A_COMPANIONS"; break;
		case 369: result.second = "A_BUILDING"; break;
		case 370: result.second = "A_TRAVEL"; break;
		case 371: result.second = "A_TRAVEL_SLEEP"; break;
		case 372: result.second = "A_TRAVEL_MAP"; break;
		case 373: result.second = "A_TRAVEL_HIDE_INSTRUCTIONS"; break;
		case 374: result.second = "A_DATE"; break;
		case 375: result.second = "A_WEATHER"; break;
		case 376: result.second = "A_TEMPERATURE"; break;
		case 377: result.second = "A_STANCE"; break;
		case 378: result.second = "A_ENTER_NAME"; break;
		case 379: result.second = "A_CUST_NAME"; break;
		case 380: result.second = "A_RANDOM_NAME"; break;
		case 381: result.second = "A_RANDOM_APPEARANCE"; break;
		case 382: result.second = "A_RANDOM_APPEARANCE_FULL"; break;
		case 383: result.second = "A_RANDOM_PERSONALITY"; break;
		case 384: result.second = "A_CUSTOM_PERSONALITY"; break;
		case 385: result.second = "A_CHANGE_DREAM"; break;
		case 386: result.second = "A_CHANGE_GENDER"; break;
		case 387: result.second = "A_END_TRAVEL"; break;
		case 388: result.second = "A_TRAVEL_CLOUDS"; break;
		case 389: result.second = "A_LOG"; break;
		case 390: result.second = "A_TRAVEL_LOG"; break;
		case 391: result.second = "A_LOG_SORT"; break;
		case 392: result.second = "A_LOG_PIN"; break;
		case 393: result.second = "A_LOG_ENTITIES"; break;
		case 394: result.second = "A_LOG_SITES"; break;
		case 395: result.second = "A_LOG_SUBREGIONS"; break;
		case 396: result.second = "A_LOG_FEATURE_LAYERS"; break;
		case 397: result.second = "A_LOG_PEOPLE"; break;
		case 398: result.second = "A_LOG_AGREEMENTS"; break;
		case 399: result.second = "A_LOG_EVENTS"; break;
		case 400: result.second = "A_LOG_BESTIARY"; break;
		case 401: result.second = "A_LOG_ARTIFACTS"; break;
		case 402: result.second = "A_LOG_FILTER"; break;
		case 403: result.second = "A_LOG_ZOOM_CURRENT_LOCATION"; break;
		case 404: result.second = "A_LOG_ZOOM_SELECTED"; break;
		case 405: result.second = "A_LOG_LINE"; break;
		case 406: result.second = "A_LOG_MAP"; break;
		case 407: result.second = "A_BARTER_VIEW"; break;
		case 408: result.second = "A_BARTER_CURRENCY_1"; break;
		case 409: result.second = "A_BARTER_CURRENCY_2"; break;
		case 410: result.second = "A_BARTER_TRADE"; break;
		case 411: result.second = "A_BARTER_SHOW"; break;
		case 412: result.second = "SETUP_EMBARK"; break;
		case 413: result.second = "SETUP_NAME_FORT"; break;
		case 414: result.second = "SETUP_NAME_GROUP"; break;
		case 415: result.second = "SETUP_SYMBOL"; break;
		case 416: result.second = "SETUP_RECLAIM"; break;
		case 417: result.second = "SETUP_FIND"; break;
		case 418: result.second = "SETUP_NOTES"; break;
		case 419: result.second = "SETUP_NOTES_TAKE_NOTES"; break;
		case 420: result.second = "SETUP_NOTES_DELETE_NOTE"; break;
		case 421: result.second = "SETUP_NOTES_CHANGE_SYMBOL_SELECTION"; break;
		case 422: result.second = "SETUP_NOTES_ADOPT_SYMBOL"; break;
		case 423: result.second = "SETUP_LOCAL_Y_UP"; break;
		case 424: result.second = "SETUP_LOCAL_Y_DOWN"; break;
		case 425: result.second = "SETUP_LOCAL_X_UP"; break;
		case 426: result.second = "SETUP_LOCAL_X_DOWN"; break;
		case 427: result.second = "SETUP_LOCAL_Y_MUP"; break;
		case 428: result.second = "SETUP_LOCAL_Y_MDOWN"; break;
		case 429: result.second = "SETUP_LOCAL_X_MUP"; break;
		case 430: result.second = "SETUP_LOCAL_X_MDOWN"; break;
		case 431: result.second = "SETUP_BIOME_1"; break;
		case 432: result.second = "SETUP_BIOME_2"; break;
		case 433: result.second = "SETUP_BIOME_3"; break;
		case 434: result.second = "SETUP_BIOME_4"; break;
		case 435: result.second = "SETUP_BIOME_5"; break;
		case 436: result.second = "SETUP_BIOME_6"; break;
		case 437: result.second = "SETUP_BIOME_7"; break;
		case 438: result.second = "SETUP_BIOME_8"; break;
		case 439: result.second = "SETUP_BIOME_9"; break;
		case 440: result.second = "CHOOSE_NAME_RANDOM"; break;
		case 441: result.second = "CHOOSE_NAME_CLEAR"; break;
		case 442: result.second = "CHOOSE_NAME_TYPE"; break;
		case 443: result.second = "CHOOSE_NAME_FIRST"; break;
		case 444: result.second = "SETUPGAME_NEW"; break;
		case 445: result.second = "SETUPGAME_VIEW"; break;
		case 446: result.second = "SETUPGAME_CUSTOMIZE_UNIT"; break;
		case 447: result.second = "SETUPGAME_SAVE_PROFILE"; break;
		case 448: result.second = "SETUPGAME_SAVE_PROFILE_ABORT"; break;
		case 449: result.second = "SETUPGAME_SAVE_PROFILE_GO"; break;
		case 450: result.second = "SETUPGAME_VIEW_PROFILE_PROBLEMS"; break;
		case 451: result.second = "BUILDJOB_ADD"; break;
		case 452: result.second = "BUILDJOB_CANCEL"; break;
		case 453: result.second = "BUILDJOB_NAME"; break;
		case 454: result.second = "BUILDJOB_PROMOTE"; break;
		case 455: result.second = "BUILDJOB_NOW"; break;
		case 456: result.second = "BUILDJOB_REPEAT"; break;
		case 457: result.second = "BUILDJOB_SUSPEND"; break;
		case 458: result.second = "BUILDJOB_WORKSHOP_PROFILE"; break;
		case 459: result.second = "BUILDJOB_DETAILS"; break;
		case 460: result.second = "BUILDJOB_DETAILS_FILTER"; break;
		case 461: result.second = "BUILDJOB_WELL_FREE"; break;
		case 462: result.second = "BUILDJOB_WELL_SIZE"; break;
		case 463: result.second = "BUILDJOB_TARGET_FREE"; break;
		case 464: result.second = "BUILDJOB_TARGET_SIZE"; break;
		case 465: result.second = "BUILDJOB_TARGET_DOWN"; break;
		case 466: result.second = "BUILDJOB_TARGET_UP"; break;
		case 467: result.second = "BUILDJOB_TARGET_RIGHT"; break;
		case 468: result.second = "BUILDJOB_TARGET_LEFT"; break;
		case 469: result.second = "BUILDJOB_STATUE_ASSIGN"; break;
		case 470: result.second = "BUILDJOB_STATUE_FREE"; break;
		case 471: result.second = "BUILDJOB_STATUE_SIZE"; break;
		case 472: result.second = "BUILDJOB_CAGE_JUSTICE"; break;
		case 473: result.second = "BUILDJOB_CAGE_FREE"; break;
		case 474: result.second = "BUILDJOB_CAGE_SIZE"; break;
		case 475: result.second = "BUILDJOB_CAGE_ASSIGN_OCC"; break;
		case 476: result.second = "BUILDJOB_CAGE_WATER"; break;
		case 477: result.second = "BUILDJOB_CAGE_ASSIGN"; break;
		case 478: result.second = "BUILDJOB_CHAIN_ASSIGN_OCC"; break;
		case 479: result.second = "BUILDJOB_CHAIN_JUSTICE"; break;
		case 480: result.second = "BUILDJOB_CHAIN_ASSIGN"; break;
		case 481: result.second = "BUILDJOB_CHAIN_FREE"; break;
		case 482: result.second = "BUILDJOB_CHAIN_SIZE"; break;
		case 483: result.second = "BUILDJOB_SIEGE_FIRING"; break;
		case 484: result.second = "BUILDJOB_SIEGE_ORIENT"; break;
		case 485: result.second = "BUILDJOB_DOOR_INTERNAL"; break;
		case 486: result.second = "BUILDJOB_DOOR_LOCK"; break;
		case 487: result.second = "BUILDJOB_DOOR_AJAR"; break;
		case 488: result.second = "BUILDJOB_COFFIN_ASSIGN"; break;
		case 489: result.second = "BUILDJOB_COFFIN_FREE"; break;
		case 490: result.second = "BUILDJOB_COFFIN_SIZE"; break;
		case 491: result.second = "BUILDJOB_COFFIN_BURIAL"; break;
		case 492: result.second = "BUILDJOB_COFFIN_CIV"; break;
		case 493: result.second = "BUILDJOB_COFFIN_PET"; break;
		case 494: result.second = "BUILDJOB_CHAIR_ASSIGN"; break;
		case 495: result.second = "BUILDJOB_CHAIR_FREE"; break;
		case 496: result.second = "BUILDJOB_CHAIR_SIZE"; break;
		case 497: result.second = "BUILDJOB_TABLE_ASSIGN"; break;
		case 498: result.second = "BUILDJOB_TABLE_HALL"; break;
		case 499: result.second = "BUILDJOB_TABLE_FREE"; break;
		case 500: result.second = "BUILDJOB_TABLE_SIZE"; break;
		case 501: result.second = "BUILDJOB_BED_ASSIGN"; break;
		case 502: result.second = "BUILDJOB_BED_FREE"; break;
		case 503: result.second = "BUILDJOB_BED_BARRACKS"; break;
		case 504: result.second = "BUILDJOB_BED_DORMITORY"; break;
		case 505: result.second = "BUILDJOB_BED_RENT"; break;
		case 506: result.second = "BUILDJOB_BED_SIZE"; break;
		case 507: result.second = "BUILDJOB_BED_SLEEP"; break;
		case 508: result.second = "BUILDJOB_BED_TRAIN"; break;
		case 509: result.second = "BUILDJOB_BED_INDIV_EQ"; break;
		case 510: result.second = "BUILDJOB_BED_SQUAD_EQ"; break;
		case 511: result.second = "BUILDJOB_BED_POSITION"; break;
		case 512: result.second = "BUILDJOB_DEPOT_BRING"; break;
		case 513: result.second = "BUILDJOB_DEPOT_TRADE"; break;
		case 514: result.second = "BUILDJOB_DEPOT_REQUEST_TRADER"; break;
		case 515: result.second = "BUILDJOB_DEPOT_BROKER_ONLY"; break;
		case 516: result.second = "BUILDJOB_ANIMALTRAP_BAIT_NONE"; break;
		case 517: result.second = "BUILDJOB_ANIMALTRAP_BAIT_MEAT"; break;
		case 518: result.second = "BUILDJOB_ANIMALTRAP_BAIT_FISH"; break;
		case 519: result.second = "BUILDJOB_ANIMALTRAP_BAIT_GEM"; break;
		case 520: result.second = "BUILDJOB_FARM_FALLOW"; break;
		case 521: result.second = "BUILDJOB_FARM_FERTILIZE"; break;
		case 522: result.second = "BUILDJOB_FARM_SEASFERT"; break;
		case 523: result.second = "BUILDJOB_FARM_SPRING"; break;
		case 524: result.second = "BUILDJOB_FARM_SUMMER"; break;
		case 525: result.second = "BUILDJOB_FARM_AUTUMN"; break;
		case 526: result.second = "BUILDJOB_FARM_WINTER"; break;
		case 527: result.second = "BUILDJOB_RACK_MAT_BONE"; break;
		case 528: result.second = "BUILDJOB_RACK_MAT_BRONZE"; break;
		case 529: result.second = "BUILDJOB_RACK_MAT_COPPER"; break;
		case 530: result.second = "BUILDJOB_RACK_MAT_IRON"; break;
		case 531: result.second = "BUILDJOB_RACK_MAT_STEEL"; break;
		case 532: result.second = "BUILDJOB_RACK_MAT_WOOD"; break;
		case 533: result.second = "BUILDJOB_RACK_MAT_METAL"; break;
		case 534: result.second = "BUILDJOB_STAND_MAT_BONE"; break;
		case 535: result.second = "BUILDJOB_STAND_MAT_LEATHER"; break;
		case 536: result.second = "BUILDJOB_STAND_MAT_COPPER"; break;
		case 537: result.second = "BUILDJOB_STAND_MAT_BRONZE"; break;
		case 538: result.second = "BUILDJOB_STAND_MAT_STEEL"; break;
		case 539: result.second = "BUILDJOB_STAND_MAT_IRON"; break;
		case 540: result.second = "BUILDJOB_STAND_MAT_WOOD"; break;
		case 541: result.second = "BUILDJOB_STAND_MAT_METAL"; break;
		case 542: result.second = "BUILDJOB_RACKSTAND_ASSIGN"; break;
		case 543: result.second = "BUILDJOB_RACKSTAND_FREE"; break;
		case 544: result.second = "BUILDJOB_RACKSTAND_SIZE"; break;
		case 545: result.second = "BUILDJOB_RACKSTAND_ITEM"; break;
		case 546: result.second = "BUILDJOB_RACKSTAND_MAT"; break;
		case 547: result.second = "BUILDJOB_RACKSTAND_DEFAULTS1"; break;
		case 548: result.second = "BUILDJOB_RACKSTAND_KILL1"; break;
		case 549: result.second = "BUILDJOB_RACKSTAND_DEFAULTS2"; break;
		case 550: result.second = "BUILDJOB_RACKSTAND_KILL2"; break;
		case 551: result.second = "BUILDJOB_DISPLAY_FURNITURE_SET"; break;
		case 552: result.second = "BUILDJOB_DISPLAY_FURNITURE_CANCEL"; break;
		case 553: result.second = "HOTKEY_BUILDING_ARMORSTAND"; break;
		case 554: result.second = "HOTKEY_BUILDING_BED"; break;
		case 555: result.second = "HOTKEY_BUILDING_CHAIR"; break;
		case 556: result.second = "HOTKEY_BUILDING_COFFIN"; break;
		case 557: result.second = "HOTKEY_BUILDING_DOOR"; break;
		case 558: result.second = "HOTKEY_BUILDING_FLOODGATE"; break;
		case 559: result.second = "HOTKEY_BUILDING_HATCH"; break;
		case 560: result.second = "HOTKEY_BUILDING_GRATE_WALL"; break;
		case 561: result.second = "HOTKEY_BUILDING_GRATE_FLOOR"; break;
		case 562: result.second = "HOTKEY_BUILDING_BARS_VERTICAL"; break;
		case 563: result.second = "HOTKEY_BUILDING_BARS_FLOOR"; break;
		case 564: result.second = "HOTKEY_BUILDING_CABINET"; break;
		case 565: result.second = "HOTKEY_BUILDING_BOX"; break;
		case 566: result.second = "HOTKEY_BUILDING_KENNEL"; break;
		case 567: result.second = "HOTKEY_BUILDING_FARMPLOT"; break;
		case 568: result.second = "HOTKEY_BUILDING_WEAPONRACK"; break;
		case 569: result.second = "HOTKEY_BUILDING_STATUE"; break;
		case 570: result.second = "HOTKEY_BUILDING_TABLE"; break;
		case 571: result.second = "HOTKEY_BUILDING_ROAD_DIRT"; break;
		case 572: result.second = "HOTKEY_BUILDING_ROAD_PAVED"; break;
		case 573: result.second = "HOTKEY_BUILDING_BRIDGE"; break;
		case 574: result.second = "HOTKEY_BUILDING_WELL"; break;
		case 575: result.second = "HOTKEY_BUILDING_SIEGEENGINE"; break;
		case 576: result.second = "HOTKEY_BUILDING_WORKSHOP"; break;
		case 577: result.second = "HOTKEY_BUILDING_FURNACE"; break;
		case 578: result.second = "HOTKEY_BUILDING_WINDOW_GLASS"; break;
		case 579: result.second = "HOTKEY_BUILDING_WINDOW_GEM"; break;
		case 580: result.second = "HOTKEY_BUILDING_SHOP"; break;
		case 581: result.second = "HOTKEY_BUILDING_ANIMALTRAP"; break;
		case 582: result.second = "HOTKEY_BUILDING_CHAIN"; break;
		case 583: result.second = "HOTKEY_BUILDING_CAGE"; break;
		case 584: result.second = "HOTKEY_BUILDING_TRADEDEPOT"; break;
		case 585: result.second = "HOTKEY_BUILDING_TRAP"; break;
		case 586: result.second = "HOTKEY_BUILDING_MACHINE"; break;
		case 587: result.second = "HOTKEY_BUILDING_INSTRUMENT"; break;
		case 588: result.second = "HOTKEY_BUILDING_SUPPORT"; break;
		case 589: result.second = "HOTKEY_BUILDING_ARCHERYTARGET"; break;
		case 590: result.second = "HOTKEY_BUILDING_TRACTION_BENCH"; break;
		case 591: result.second = "HOTKEY_BUILDING_SLAB"; break;
		case 592: result.second = "HOTKEY_BUILDING_NEST_BOX"; break;
		case 593: result.second = "HOTKEY_BUILDING_BOOKCASE"; break;
		case 594: result.second = "HOTKEY_BUILDING_HIVE"; break;
		case 595: result.second = "HOTKEY_BUILDING_DISPLAY_FURNITURE"; break;
		case 596: result.second = "HOTKEY_BUILDING_MACHINE_SCREW_PUMP"; break;
		case 597: result.second = "HOTKEY_BUILDING_MACHINE_WATER_WHEEL"; break;
		case 598: result.second = "HOTKEY_BUILDING_MACHINE_WINDMILL"; break;
		case 599: result.second = "HOTKEY_BUILDING_MACHINE_GEAR_ASSEMBLY"; break;
		case 600: result.second = "HOTKEY_BUILDING_MACHINE_AXLE_VERTICAL"; break;
		case 601: result.second = "HOTKEY_BUILDING_MACHINE_AXLE_HORIZONTAL"; break;
		case 602: result.second = "HOTKEY_BUILDING_MACHINE_ROLLERS"; break;
		case 603: result.second = "HOTKEY_BUILDING_SIEGEENGINE_BALLISTA"; break;
		case 604: result.second = "HOTKEY_BUILDING_SIEGEENGINE_CATAPULT"; break;
		case 605: result.second = "HOTKEY_BUILDING_TRAP_STONE"; break;
		case 606: result.second = "HOTKEY_BUILDING_TRAP_WEAPON"; break;
		case 607: result.second = "HOTKEY_BUILDING_TRAP_LEVER"; break;
		case 608: result.second = "HOTKEY_BUILDING_TRAP_TRIGGER"; break;
		case 609: result.second = "HOTKEY_BUILDING_TRAP_CAGE"; break;
		case 610: result.second = "HOTKEY_BUILDING_TRAP_SPIKE"; break;
		case 611: result.second = "HOTKEY_BUILDING_CONSTRUCTION"; break;
		case 612: result.second = "HOTKEY_BUILDING_CONSTRUCTION_WALL"; break;
		case 613: result.second = "HOTKEY_BUILDING_CONSTRUCTION_FLOOR"; break;
		case 614: result.second = "HOTKEY_BUILDING_CONSTRUCTION_RAMP"; break;
		case 615: result.second = "HOTKEY_BUILDING_CONSTRUCTION_STAIR_UP"; break;
		case 616: result.second = "HOTKEY_BUILDING_CONSTRUCTION_STAIR_DOWN"; break;
		case 617: result.second = "HOTKEY_BUILDING_CONSTRUCTION_STAIR_UPDOWN"; break;
		case 618: result.second = "HOTKEY_BUILDING_CONSTRUCTION_FORTIFICATION"; break;
		case 619: result.second = "HOTKEY_BUILDING_CONSTRUCTION_TRACK"; break;
		case 620: result.second = "HOTKEY_BUILDING_CONSTRUCTION_TRACK_STOP"; break;
		case 621: result.second = "HOTKEY_BUILDING_WORKSHOP_LEATHER"; break;
		case 622: result.second = "HOTKEY_BUILDING_WORKSHOP_QUERN"; break;
		case 623: result.second = "HOTKEY_BUILDING_WORKSHOP_MILLSTONE"; break;
		case 624: result.second = "HOTKEY_BUILDING_WORKSHOP_LOOM"; break;
		case 625: result.second = "HOTKEY_BUILDING_WORKSHOP_CLOTHES"; break;
		case 626: result.second = "HOTKEY_BUILDING_WORKSHOP_BOWYER"; break;
		case 627: result.second = "HOTKEY_BUILDING_WORKSHOP_CARPENTER"; break;
		case 628: result.second = "HOTKEY_BUILDING_WORKSHOP_METALSMITH"; break;
		case 629: result.second = "HOTKEY_BUILDING_WORKSHOP_LAVAMILL"; break;
		case 630: result.second = "HOTKEY_BUILDING_WORKSHOP_JEWELER"; break;
		case 631: result.second = "HOTKEY_BUILDING_WORKSHOP_MASON"; break;
		case 632: result.second = "HOTKEY_BUILDING_WORKSHOP_BUTCHER"; break;
		case 633: result.second = "HOTKEY_BUILDING_WORKSHOP_TANNER"; break;
		case 634: result.second = "HOTKEY_BUILDING_WORKSHOP_DYER"; break;
		case 635: result.second = "HOTKEY_BUILDING_WORKSHOP_CRAFTSMAN"; break;
		case 636: result.second = "HOTKEY_BUILDING_WORKSHOP_SIEGE"; break;
		case 637: result.second = "HOTKEY_BUILDING_WORKSHOP_MECHANIC"; break;
		case 638: result.second = "HOTKEY_BUILDING_WORKSHOP_STILL"; break;
		case 639: result.second = "HOTKEY_BUILDING_WORKSHOP_FARMER"; break;
		case 640: result.second = "HOTKEY_BUILDING_WORKSHOP_KITCHEN"; break;
		case 641: result.second = "HOTKEY_BUILDING_WORKSHOP_FISHERY"; break;
		case 642: result.second = "HOTKEY_BUILDING_WORKSHOP_ASHERY"; break;
		case 643: result.second = "HOTKEY_BUILDING_FURNACE_WOOD"; break;
		case 644: result.second = "HOTKEY_BUILDING_FURNACE_SMELTER"; break;
		case 645: result.second = "HOTKEY_BUILDING_FURNACE_GLASS"; break;
		case 646: result.second = "HOTKEY_BUILDING_FURNACE_KILN"; break;
		case 647: result.second = "HOTKEY_BUILDING_FURNACE_SMELTER_LAVA"; break;
		case 648: result.second = "HOTKEY_BUILDING_FURNACE_GLASS_LAVA"; break;
		case 649: result.second = "HOTKEY_BUILDING_FURNACE_KILN_LAVA"; break;
		case 650: result.second = "HIVE_INSTALL_COLONY"; break;
		case 651: result.second = "HIVE_GATHER_PRODUCTS"; break;
		case 652: result.second = "BUILDING_DIM_Y_UP"; break;
		case 653: result.second = "BUILDING_DIM_Y_DOWN"; break;
		case 654: result.second = "BUILDING_DIM_X_UP"; break;
		case 655: result.second = "BUILDING_DIM_X_DOWN"; break;
		case 656: result.second = "BUILDING_ORIENT_UP"; break;
		case 657: result.second = "BUILDING_ORIENT_LEFT"; break;
		case 658: result.second = "BUILDING_ORIENT_RIGHT"; break;
		case 659: result.second = "BUILDING_ORIENT_DOWN"; break;
		case 660: result.second = "BUILDING_ORIENT_NONE"; break;
		case 661: result.second = "BUILDING_VIEW_ITEM"; break;
		case 662: result.second = "BUILDING_ADVANCE_STAGE"; break;
		case 663: result.second = "BUILDING_EXPAND_CONTRACT"; break;
		case 664: result.second = "BUILDING_TRIGGER_ENABLE_WATER"; break;
		case 665: result.second = "BUILDING_TRIGGER_MIN_WATER_UP"; break;
		case 666: result.second = "BUILDING_TRIGGER_MIN_WATER_DOWN"; break;
		case 667: result.second = "BUILDING_TRIGGER_MAX_WATER_UP"; break;
		case 668: result.second = "BUILDING_TRIGGER_MAX_WATER_DOWN"; break;
		case 669: result.second = "BUILDING_TRIGGER_ENABLE_MAGMA"; break;
		case 670: result.second = "BUILDING_TRIGGER_MIN_MAGMA_UP"; break;
		case 671: result.second = "BUILDING_TRIGGER_MIN_MAGMA_DOWN"; break;
		case 672: result.second = "BUILDING_TRIGGER_MAX_MAGMA_UP"; break;
		case 673: result.second = "BUILDING_TRIGGER_MAX_MAGMA_DOWN"; break;
		case 674: result.second = "BUILDING_TRIGGER_ENABLE_TRACK_CART"; break;
		case 675: result.second = "BUILDING_TRIGGER_MIN_TRACK_CART_DOWN"; break;
		case 676: result.second = "BUILDING_TRIGGER_MIN_TRACK_CART_UP"; break;
		case 677: result.second = "BUILDING_TRIGGER_MAX_TRACK_CART_DOWN"; break;
		case 678: result.second = "BUILDING_TRIGGER_MAX_TRACK_CART_UP"; break;
		case 679: result.second = "BUILDING_TRIGGER_ENABLE_CREATURE"; break;
		case 680: result.second = "BUILDING_TRIGGER_ENABLE_LOCALS"; break;
		case 681: result.second = "BUILDING_TRIGGER_RESETS"; break;
		case 682: result.second = "BUILDING_TRIGGER_MIN_SIZE_UP"; break;
		case 683: result.second = "BUILDING_TRIGGER_MIN_SIZE_DOWN"; break;
		case 684: result.second = "BUILDING_TRIGGER_MAX_SIZE_UP"; break;
		case 685: result.second = "BUILDING_TRIGGER_MAX_SIZE_DOWN"; break;
		case 686: result.second = "BUILDING_TRIGGER_MIN_SIZE_UP_PLUS"; break;
		case 687: result.second = "BUILDING_TRIGGER_MIN_SIZE_DOWN_PLUS"; break;
		case 688: result.second = "BUILDING_TRIGGER_MAX_SIZE_UP_PLUS"; break;
		case 689: result.second = "BUILDING_TRIGGER_MAX_SIZE_DOWN_PLUS"; break;
		case 690: result.second = "BUILDING_ROLLERS_SPEED_UP"; break;
		case 691: result.second = "BUILDING_ROLLERS_SPEED_DOWN"; break;
		case 692: result.second = "BUILDING_TRACK_STOP_FRICTION_UP"; break;
		case 693: result.second = "BUILDING_TRACK_STOP_FRICTION_DOWN"; break;
		case 694: result.second = "BUILDING_TRACK_STOP_DUMP"; break;
		case 695: result.second = "DESTROYBUILDING"; break;
		case 696: result.second = "SUSPENDBUILDING"; break;
		case 697: result.second = "BUILDINGLIST_ZOOM_T"; break;
		case 698: result.second = "BUILDINGLIST_ZOOM_Q"; break;
		case 699: result.second = "RECENTER_ON_LEVER"; break;
		case 700: result.second = "ASSIGN_LOCATION"; break;
		case 701: result.second = "LOCATION_NEW"; break;
		case 702: result.second = "LOCATION_RETIRE"; break;
		case 703: result.second = "LOCATION_INN_TAVERN"; break;
		case 704: result.second = "LOCATION_TEMPLE"; break;
		case 705: result.second = "LOCATION_LIBRARY"; break;
		case 706: result.second = "LOCATION_MAIN_HALL"; break;
		case 707: result.second = "LOCATION_RENAME"; break;
		case 708: result.second = "LOCATION_DETAILS"; break;
		case 709: result.second = "LOCATION_RESTRICTION"; break;
		case 710: result.second = "LOCATION_SET_NUMBER_1"; break;
		case 711: result.second = "LOCATION_SET_NUMBER_2"; break;
		case 712: result.second = "HOTKEY_MAKE_ASH"; break;
		case 713: result.second = "HOTKEY_MAKE_CHARCOAL"; break;
		case 714: result.second = "HOTKEY_MELT_OBJECT"; break;
		case 715: result.second = "HOTKEY_GLASS_GREEN"; break;
		case 716: result.second = "HOTKEY_GLASS_CLEAR"; break;
		case 717: result.second = "HOTKEY_GLASS_CRYSTAL"; break;
		case 718: result.second = "HOTKEY_COLLECT_SAND"; break;
		case 719: result.second = "HOTKEY_COLLECT_CLAY"; break;
		case 720: result.second = "HOTKEY_GLASS_ROUGH"; break;
		case 721: result.second = "HOTKEY_GLASS_ARMORSTAND"; break;
		case 722: result.second = "HOTKEY_GLASS_BOX"; break;
		case 723: result.second = "HOTKEY_GLASS_CABINET"; break;
		case 724: result.second = "HOTKEY_GLASS_COFFIN"; break;
		case 725: result.second = "HOTKEY_GLASS_FLOODGATE"; break;
		case 726: result.second = "HOTKEY_GLASS_HATCH_COVER"; break;
		case 727: result.second = "HOTKEY_GLASS_GRATE"; break;
		case 728: result.second = "HOTKEY_GLASS_GOBLET"; break;
		case 729: result.second = "HOTKEY_GLASS_TOY"; break;
		case 730: result.second = "HOTKEY_GLASS_DOOR"; break;
		case 731: result.second = "HOTKEY_GLASS_STATUE"; break;
		case 732: result.second = "HOTKEY_GLASS_TABLE"; break;
		case 733: result.second = "HOTKEY_GLASS_CAGE"; break;
		case 734: result.second = "HOTKEY_GLASS_CHAIR"; break;
		case 735: result.second = "HOTKEY_GLASS_BLOCKS"; break;
		case 736: result.second = "HOTKEY_GLASS_FLASK"; break;
		case 737: result.second = "HOTKEY_GLASS_WEAPONRACK"; break;
		case 738: result.second = "HOTKEY_GLASS_WINDOW"; break;
		case 739: result.second = "HOTKEY_ASHERY_LYE"; break;
		case 740: result.second = "HOTKEY_ASHERY_POTASH"; break;
		case 741: result.second = "HOTKEY_ASHERY_POTASH_DIRECT"; break;
		case 742: result.second = "HOTKEY_CARPENTER_BARREL"; break;
		case 743: result.second = "HOTKEY_CARPENTER_BLOCKS"; break;
		case 744: result.second = "HOTKEY_CARPENTER_BUCKET"; break;
		case 745: result.second = "HOTKEY_CARPENTER_TRAP_ANIMAL"; break;
		case 746: result.second = "HOTKEY_CARPENTER_CAGE"; break;
		case 747: result.second = "HOTKEY_CARPENTER_ARMORSTAND"; break;
		case 748: result.second = "HOTKEY_CARPENTER_BED"; break;
		case 749: result.second = "HOTKEY_CARPENTER_CHAIR"; break;
		case 750: result.second = "HOTKEY_CARPENTER_COFFIN"; break;
		case 751: result.second = "HOTKEY_CARPENTER_DOOR"; break;
		case 752: result.second = "HOTKEY_CARPENTER_FLOODGATE"; break;
		case 753: result.second = "HOTKEY_CARPENTER_HATCH_COVER"; break;
		case 754: result.second = "HOTKEY_CARPENTER_GRATE"; break;
		case 755: result.second = "HOTKEY_CARPENTER_CABINET"; break;
		case 756: result.second = "HOTKEY_CARPENTER_BIN"; break;
		case 757: result.second = "HOTKEY_CARPENTER_BOX"; break;
		case 758: result.second = "HOTKEY_CARPENTER_WEAPONRACK"; break;
		case 759: result.second = "HOTKEY_CARPENTER_TABLE"; break;
		case 760: result.second = "HOTKEY_SIEGE_BALLISTA"; break;
		case 761: result.second = "HOTKEY_SIEGE_CATAPULT"; break;
		case 762: result.second = "HOTKEY_LEATHER_BOX"; break;
		case 763: result.second = "HOTKEY_LEATHER_FLASK"; break;
		case 764: result.second = "HOTKEY_LEATHER_SHIRT"; break;
		case 765: result.second = "HOTKEY_LEATHER_CLOAK"; break;
		case 766: result.second = "HOTKEY_LEATHER_BACKPACK"; break;
		case 767: result.second = "HOTKEY_LEATHER_QUIVER"; break;
		case 768: result.second = "HOTKEY_LEATHER_IMAGE"; break;
		case 769: result.second = "HOTKEY_CLOTHES_MAT_PLANT"; break;
		case 770: result.second = "HOTKEY_CLOTHES_MAT_SILK"; break;
		case 771: result.second = "HOTKEY_CLOTHES_MAT_YARN"; break;
		case 772: result.second = "HOTKEY_CLOTHES_SHIRT"; break;
		case 773: result.second = "HOTKEY_CLOTHES_CLOAK"; break;
		case 774: result.second = "HOTKEY_CLOTHES_BOX"; break;
		case 775: result.second = "HOTKEY_CLOTHES_CHAIN"; break;
		case 776: result.second = "HOTKEY_CLOTHES_IMAGE"; break;
		case 777: result.second = "HOTKEY_CRAFTS_MAT_STONE"; break;
		case 778: result.second = "HOTKEY_CRAFTS_MAT_WOOD"; break;
		case 779: result.second = "HOTKEY_CRAFTS_DEC_BONE"; break;
		case 780: result.second = "HOTKEY_CRAFTS_DEC_SHELL"; break;
		case 781: result.second = "HOTKEY_CRAFTS_DEC_TOOTH"; break;
		case 782: result.second = "HOTKEY_CRAFTS_DEC_HORN"; break;
		case 783: result.second = "HOTKEY_CRAFTS_DEC_PEARL"; break;
		case 784: result.second = "HOTKEY_CRAFTS_TOTEM"; break;
		case 785: result.second = "HOTKEY_CRAFTS_CLOTH"; break;
		case 786: result.second = "HOTKEY_CRAFTS_SILK"; break;
		case 787: result.second = "HOTKEY_CRAFTS_YARN"; break;
		case 788: result.second = "HOTKEY_CRAFTS_SEL_WOOD"; break;
		case 789: result.second = "HOTKEY_CRAFTS_SEL_BONE"; break;
		case 790: result.second = "HOTKEY_CRAFTS_SEL_SHELL"; break;
		case 791: result.second = "HOTKEY_CRAFTS_SHELL"; break;
		case 792: result.second = "HOTKEY_CRAFTS_TOOTH"; break;
		case 793: result.second = "HOTKEY_CRAFTS_HORN"; break;
		case 794: result.second = "HOTKEY_CRAFTS_PEARL"; break;
		case 795: result.second = "HOTKEY_CRAFTS_BONE"; break;
		case 796: result.second = "HOTKEY_CRAFTS_LEATHER"; break;
		case 797: result.second = "HOTKEY_CRAFTS_SLAB"; break;
		case 798: result.second = "HOTKEY_CRAFTS_MAT_CRAFTS"; break;
		case 799: result.second = "HOTKEY_CRAFTS_MAT_GOBLET"; break;
		case 800: result.second = "HOTKEY_CRAFTS_MAT_TOY"; break;
		case 801: result.second = "HOTKEY_SMITH_WEAPON"; break;
		case 802: result.second = "HOTKEY_SMITH_ARMOR"; break;
		case 803: result.second = "HOTKEY_SMITH_FURNITURE"; break;
		case 804: result.second = "HOTKEY_SMITH_SIEGE"; break;
		case 805: result.second = "HOTKEY_SMITH_TRAP"; break;
		case 806: result.second = "HOTKEY_SMITH_OTHER"; break;
		case 807: result.second = "HOTKEY_SMITH_METAL"; break;
		case 808: result.second = "HOTKEY_ALCHEMIST_SOAP"; break;
		case 809: result.second = "HOTKEY_STILL_BREW"; break;
		case 810: result.second = "HOTKEY_STILL_EXTRACT"; break;
		case 811: result.second = "HOTKEY_LOOM_COLLECT_SILK"; break;
		case 812: result.second = "HOTKEY_LOOM_WEAVE_CLOTH"; break;
		case 813: result.second = "HOTKEY_LOOM_WEAVE_SILK"; break;
		case 814: result.second = "HOTKEY_LOOM_WEAVE_YARN"; break;
		case 815: result.second = "HOTKEY_LOOM_WEAVE_METAL"; break;
		case 816: result.second = "HOTKEY_KITCHEN_COOK_2"; break;
		case 817: result.second = "HOTKEY_KITCHEN_COOK_3"; break;
		case 818: result.second = "HOTKEY_KITCHEN_COOK_4"; break;
		case 819: result.second = "HOTKEY_KITCHEN_RENDER_FAT"; break;
		case 820: result.second = "HOTKEY_FARMER_PROCESS"; break;
		case 821: result.second = "HOTKEY_FARMER_PROCESS_VIAL"; break;
		case 822: result.second = "HOTKEY_FARMER_PROCESS_BAG"; break;
		case 823: result.second = "HOTKEY_FARMER_PROCESS_BARREL"; break;
		case 824: result.second = "HOTKEY_FARMER_CHEESE"; break;
		case 825: result.second = "HOTKEY_FARMER_MILK"; break;
		case 826: result.second = "HOTKEY_FARMER_SHEAR_CREATURE"; break;
		case 827: result.second = "HOTKEY_FARMER_SPIN_THREAD"; break;
		case 828: result.second = "HOTKEY_MILL_MILL"; break;
		case 829: result.second = "HOTKEY_KENNEL_CATCH_VERMIN"; break;
		case 830: result.second = "HOTKEY_KENNEL_TAME_VERMIN"; break;
		case 831: result.second = "HOTKEY_FISHERY_PROCESS"; break;
		case 832: result.second = "HOTKEY_FISHERY_EXTRACT"; break;
		case 833: result.second = "HOTKEY_FISHERY_CATCH"; break;
		case 834: result.second = "HOTKEY_BUTCHER_BUTCHER"; break;
		case 835: result.second = "HOTKEY_BUTCHER_EXTRACT"; break;
		case 836: result.second = "HOTKEY_BUTCHER_CATCH"; break;
		case 837: result.second = "HOTKEY_TANNER_TAN"; break;
		case 838: result.second = "HOTKEY_DYER_THREAD"; break;
		case 839: result.second = "HOTKEY_DYER_CLOTH"; break;
		case 840: result.second = "HOTKEY_JEWELER_FURNITURE"; break;
		case 841: result.second = "HOTKEY_JEWELER_FINISHED"; break;
		case 842: result.second = "HOTKEY_JEWELER_AMMO"; break;
		case 843: result.second = "HOTKEY_JEWELER_CUT"; break;
		case 844: result.second = "HOTKEY_JEWELER_ENCRUST"; break;
		case 845: result.second = "HOTKEY_MECHANIC_PARTS"; break;
		case 846: result.second = "HOTKEY_MECHANIC_TRACTION_BENCH"; break;
		case 847: result.second = "HOTKEY_MASON_ARMORSTAND"; break;
		case 848: result.second = "HOTKEY_MASON_BLOCKS"; break;
		case 849: result.second = "HOTKEY_MASON_CHAIR"; break;
		case 850: result.second = "HOTKEY_MASON_COFFIN"; break;
		case 851: result.second = "HOTKEY_MASON_DOOR"; break;
		case 852: result.second = "HOTKEY_MASON_FLOODGATE"; break;
		case 853: result.second = "HOTKEY_MASON_HATCH_COVER"; break;
		case 854: result.second = "HOTKEY_MASON_GRATE"; break;
		case 855: result.second = "HOTKEY_MASON_CABINET"; break;
		case 856: result.second = "HOTKEY_MASON_BOX"; break;
		case 857: result.second = "HOTKEY_MASON_STATUE"; break;
		case 858: result.second = "HOTKEY_MASON_TABLE"; break;
		case 859: result.second = "HOTKEY_MASON_WEAPONRACK"; break;
		case 860: result.second = "HOTKEY_MASON_QUERN"; break;
		case 861: result.second = "HOTKEY_MASON_MILLSTONE"; break;
		case 862: result.second = "HOTKEY_MASON_SLAB"; break;
		case 863: result.second = "HOTKEY_TRAP_BRIDGE"; break;
		case 864: result.second = "HOTKEY_TRAP_DOOR"; break;
		case 865: result.second = "HOTKEY_TRAP_FLOODGATE"; break;
		case 866: result.second = "HOTKEY_TRAP_SPIKE"; break;
		case 867: result.second = "HOTKEY_TRAP_HATCH"; break;
		case 868: result.second = "HOTKEY_TRAP_GRATE_WALL"; break;
		case 869: result.second = "HOTKEY_TRAP_GRATE_FLOOR"; break;
		case 870: result.second = "HOTKEY_TRAP_BARS_VERTICAL"; break;
		case 871: result.second = "HOTKEY_TRAP_BARS_FLOOR"; break;
		case 872: result.second = "HOTKEY_TRAP_SUPPORT"; break;
		case 873: result.second = "HOTKEY_TRAP_CHAIN"; break;
		case 874: result.second = "HOTKEY_TRAP_CAGE"; break;
		case 875: result.second = "HOTKEY_TRAP_GEAR_ASSEMBLY"; break;
		case 876: result.second = "HOTKEY_TRAP_TRACK_STOP"; break;
		case 877: result.second = "HOTKEY_TRAP_PULL_LEVER"; break;
		case 878: result.second = "BUILDJOB_STOCKPILE_MASTER"; break;
		case 879: result.second = "BUILDJOB_STOCKPILE_LINK_ANYWHERE"; break;
		case 880: result.second = "BUILDJOB_STOCKPILE_GIVE_TO"; break;
		case 881: result.second = "BUILDJOB_STOCKPILE_DELETE_CHILD"; break;
		case 882: result.second = "BUILDJOB_STOCKPILE_SETTINGS"; break;
		case 883: result.second = "BUILDJOB_STOCKPILE_BARREL_UP"; break;
		case 884: result.second = "BUILDJOB_STOCKPILE_BARREL_DOWN"; break;
		case 885: result.second = "BUILDJOB_STOCKPILE_BARREL_ZERO"; break;
		case 886: result.second = "BUILDJOB_STOCKPILE_BARREL_MAX"; break;
		case 887: result.second = "BUILDJOB_STOCKPILE_BIN_UP"; break;
		case 888: result.second = "BUILDJOB_STOCKPILE_BIN_DOWN"; break;
		case 889: result.second = "BUILDJOB_STOCKPILE_BIN_ZERO"; break;
		case 890: result.second = "BUILDJOB_STOCKPILE_BIN_MAX"; break;
		case 891: result.second = "BUILDJOB_STOCKPILE_WHEELBARROW"; break;
		case 892: result.second = "STOCKPILE_ANIMAL"; break;
		case 893: result.second = "STOCKPILE_FOOD"; break;
		case 894: result.second = "STOCKPILE_WEAPON"; break;
		case 895: result.second = "STOCKPILE_ARMOR"; break;
		case 896: result.second = "STOCKPILE_CUSTOM"; break;
		case 897: result.second = "STOCKPILE_CUSTOM_SETTINGS"; break;
		case 898: result.second = "STOCKPILE_FURNITURE"; break;
		case 899: result.second = "STOCKPILE_GRAVEYARD"; break;
		case 900: result.second = "STOCKPILE_REFUSE"; break;
		case 901: result.second = "STOCKPILE_WOOD"; break;
		case 902: result.second = "STOCKPILE_STONE"; break;
		case 903: result.second = "STOCKPILE_GEM"; break;
		case 904: result.second = "STOCKPILE_BARBLOCK"; break;
		case 905: result.second = "STOCKPILE_CLOTH"; break;
		case 906: result.second = "STOCKPILE_LEATHER"; break;
		case 907: result.second = "STOCKPILE_AMMO"; break;
		case 908: result.second = "STOCKPILE_COINS"; break;
		case 909: result.second = "STOCKPILE_FINISHED"; break;
		case 910: result.second = "STOCKPILE_SHEET"; break;
		case 911: result.second = "STOCKPILE_NONE"; break;
		case 912: result.second = "STOCKPILE_SETTINGS_ENABLE"; break;
		case 913: result.second = "STOCKPILE_SETTINGS_DISABLE"; break;
		case 914: result.second = "STOCKPILE_SETTINGS_PERMIT_ALL"; break;
		case 915: result.second = "STOCKPILE_SETTINGS_FORBID_ALL"; break;
		case 916: result.second = "STOCKPILE_SETTINGS_PERMIT_SUB"; break;
		case 917: result.second = "STOCKPILE_SETTINGS_FORBID_SUB"; break;
		case 918: result.second = "STOCKPILE_SETTINGS_SPECIFIC1"; break;
		case 919: result.second = "STOCKPILE_SETTINGS_SPECIFIC2"; break;
		case 920: result.second = "CIVZONE_NAME"; break;
		case 921: result.second = "CIVZONE_REMOVE"; break;
		case 922: result.second = "CIVZONE_REMOVE_ZONE"; break;
		case 923: result.second = "CIVZONE_SHAPE"; break;
		case 924: result.second = "CIVZONE_NEXT"; break;
		case 925: result.second = "CIVZONE_WATER_SOURCE"; break;
		case 926: result.second = "CIVZONE_FISH"; break;
		case 927: result.second = "CIVZONE_GATHER"; break;
		case 928: result.second = "CIVZONE_DUMP"; break;
		case 929: result.second = "CIVZONE_POND"; break;
		case 930: result.second = "CIVZONE_HOSPITAL"; break;
		case 931: result.second = "CIVZONE_SAND_COLLECT"; break;
		case 932: result.second = "CIVZONE_CLAY_COLLECT"; break;
		case 933: result.second = "CIVZONE_ACTIVE"; break;
		case 934: result.second = "CIVZONE_MEETING"; break;
		case 935: result.second = "CIVZONE_ANIMAL_TRAINING"; break;
		case 936: result.second = "CIVZONE_PEN"; break;
		case 937: result.second = "CIVZONE_PEN_OPTIONS"; break;
		case 938: result.second = "CIVZONE_POND_OPTIONS"; break;
		case 939: result.second = "CIVZONE_POND_WATER"; break;
		case 940: result.second = "CIVZONE_HOSPITAL_OPTIONS"; break;
		case 941: result.second = "CIVZONE_GATHER_OPTIONS"; break;
		case 942: result.second = "CIVZONE_GATHER_OPTIONS_PICK_TREES"; break;
		case 943: result.second = "CIVZONE_GATHER_OPTIONS_PICK_SHRUBS"; break;
		case 944: result.second = "CIVZONE_GATHER_OPTIONS_GATHER_FALLEN"; break;
		case 945: result.second = "STORES_VIEW"; break;
		case 946: result.second = "STORES_ZOOM"; break;
		case 947: result.second = "STORES_FORBID"; break;
		case 948: result.second = "STORES_MELT"; break;
		case 949: result.second = "STORES_DUMP"; break;
		case 950: result.second = "STORES_HIDE"; break;
		case 951: result.second = "PET_BUTCHER"; break;
		case 952: result.second = "PET_GELD"; break;
		case 953: result.second = "ANIMAL_SELECT_TRAINER"; break;
		case 954: result.second = "ANIMAL_WAR_TRAINING"; break;
		case 955: result.second = "ANIMAL_HUNTING_TRAINING"; break;
		case 956: result.second = "KITCHEN_COOK"; break;
		case 957: result.second = "KITCHEN_BREW"; break;
		case 958: result.second = "ORDERS_AUTOFORBID"; break;
		case 959: result.second = "ORDERS_FORBID_PROJECTILE"; break;
		case 960: result.second = "ORDERS_FORBID_YOUR_CORPSE"; break;
		case 961: result.second = "ORDERS_FORBID_YOUR_ITEMS"; break;
		case 962: result.second = "ORDERS_FORBID_OTHER_CORPSE"; break;
		case 963: result.second = "ORDERS_FORBID_OTHER_ITEMS"; break;
		case 964: result.second = "ORDERS_REFUSE_GATHER"; break;
		case 965: result.second = "ORDERS_REFUSE_OUTSIDE"; break;
		case 966: result.second = "ORDERS_REFUSE_OUTSIDE_VERMIN"; break;
		case 967: result.second = "ORDERS_REFUSE_DUMP_CORPSE"; break;
		case 968: result.second = "ORDERS_REFUSE_DUMP_SKULL"; break;
		case 969: result.second = "ORDERS_REFUSE_DUMP_BONE"; break;
		case 970: result.second = "ORDERS_REFUSE_DUMP_SHELL"; break;
		case 971: result.second = "ORDERS_REFUSE_DUMP_SKIN"; break;
		case 972: result.second = "ORDERS_REFUSE_DUMP_OTHER"; break;
		case 973: result.second = "ORDERS_REFUSE_DUMP_STRAND_TISSUE"; break;
		case 974: result.second = "ORDERS_GATHER_FURNITURE"; break;
		case 975: result.second = "ORDERS_GATHER_ANIMALS"; break;
		case 976: result.second = "ORDERS_GATHER_FOOD"; break;
		case 977: result.second = "ORDERS_GATHER_BODIES"; break;
		case 978: result.second = "ORDERS_REFUSE"; break;
		case 979: result.second = "ORDERS_GATHER_STONE"; break;
		case 980: result.second = "ORDERS_GATHER_WOOD"; break;
		case 981: result.second = "ORDERS_ALL_HARVEST"; break;
		case 982: result.second = "ORDERS_SAMEPILE"; break;
		case 983: result.second = "ORDERS_MIXFOODS"; break;
		case 984: result.second = "ORDERS_LOOM"; break;
		case 985: result.second = "ORDERS_DYED_CLOTH"; break;
		case 986: result.second = "ORDERS_EXCEPTIONS"; break;
		case 987: result.second = "ORDERS_WORKSHOP"; break;
		case 988: result.second = "ORDERS_COLLECT_WEB"; break;
		case 989: result.second = "ORDERS_SLAUGHTER"; break;
		case 990: result.second = "ORDERS_BUTCHER"; break;
		case 991: result.second = "ORDERS_TAN"; break;
		case 992: result.second = "ORDERS_AUTO_FISHERY"; break;
		case 993: result.second = "ORDERS_AUTO_KITCHEN"; break;
		case 994: result.second = "ORDERS_AUTO_KILN"; break;
		case 995: result.second = "ORDERS_AUTO_SMELTER"; break;
		case 996: result.second = "ORDERS_AUTO_OTHER"; break;
		case 997: result.second = "ORDERS_ZONE"; break;
		case 998: result.second = "ORDERS_ZONE_DRINKING"; break;
		case 999: result.second = "ORDERS_ZONE_FISHING"; break;
		case 1000: result.second = "D_ONESTEP"; break;
		case 1001: result.second = "D_PAUSE"; break;
		case 1002: result.second = "D_DEPOT"; break;
		case 1003: result.second = "D_HOT_KEYS"; break;
		case 1004: result.second = "D_HOTKEY1"; break;
		case 1005: result.second = "D_HOTKEY2"; break;
		case 1006: result.second = "D_HOTKEY3"; break;
		case 1007: result.second = "D_HOTKEY4"; break;
		case 1008: result.second = "D_HOTKEY5"; break;
		case 1009: result.second = "D_HOTKEY6"; break;
		case 1010: result.second = "D_HOTKEY7"; break;
		case 1011: result.second = "D_HOTKEY8"; break;
		case 1012: result.second = "D_HOTKEY9"; break;
		case 1013: result.second = "D_HOTKEY10"; break;
		case 1014: result.second = "D_HOTKEY11"; break;
		case 1015: result.second = "D_HOTKEY12"; break;
		case 1016: result.second = "D_HOTKEY13"; break;
		case 1017: result.second = "D_HOTKEY14"; break;
		case 1018: result.second = "D_HOTKEY15"; break;
		case 1019: result.second = "D_HOTKEY16"; break;
		case 1020: result.second = "D_HOTKEY_CHANGE_NAME"; break;
		case 1021: result.second = "D_HOTKEY_ZOOM"; break;
		case 1022: result.second = "D_ANNOUNCE"; break;
		case 1023: result.second = "D_REPORTS"; break;
		case 1024: result.second = "D_BUILDING"; break;
		case 1025: result.second = "D_CIVLIST"; break;
		case 1026: result.second = "D_DESIGNATE"; break;
		case 1027: result.second = "D_ARTLIST"; break;
		case 1028: result.second = "D_NOBLES"; break;
		case 1029: result.second = "D_ORDERS"; break;
		case 1030: result.second = "D_PETITIONS"; break;
		case 1031: result.second = "D_LOCATIONS"; break;
		case 1032: result.second = "D_MILITARY"; break;
		case 1033: result.second = "D_ROOMS"; break;
		case 1034: result.second = "D_SQUADS"; break;
		case 1035: result.second = "D_STOCKPILES"; break;
		case 1036: result.second = "D_CIVZONE"; break;
		case 1037: result.second = "D_VIEWUNIT"; break;
		case 1038: result.second = "D_JOBLIST"; break;
		case 1039: result.second = "D_UNITLIST"; break;
		case 1040: result.second = "D_LOOK"; break;
		case 1041: result.second = "D_HAULING"; break;
		case 1042: result.second = "D_HAULING_NEW_ROUTE"; break;
		case 1043: result.second = "D_HAULING_NEW_STOP"; break;
		case 1044: result.second = "D_HAULING_REMOVE"; break;
		case 1045: result.second = "D_HAULING_PROMOTE"; break;
		case 1046: result.second = "D_HAULING_VEHICLE"; break;
		case 1047: result.second = "D_HAULING_NICKNAME"; break;
		case 1048: result.second = "D_HAULING_STOP_NEW_DEPART"; break;
		case 1049: result.second = "D_HAULING_STOP_NEW_LINK"; break;
		case 1050: result.second = "D_HAULING_STOP_REMOVE"; break;
		case 1051: result.second = "D_HAULING_STOP_SL_SELECT_PILE"; break;
		case 1052: result.second = "D_HAULING_STOP_SL_TAKE_GIVE"; break;
		case 1053: result.second = "D_HAULING_STOP_LC_DIR"; break;
		case 1054: result.second = "D_HAULING_STOP_LC_MODE"; break;
		case 1055: result.second = "D_HAULING_STOP_LC_TIMER_UP"; break;
		case 1056: result.second = "D_HAULING_STOP_LC_TIMER_DOWN"; break;
		case 1057: result.second = "D_HAULING_STOP_LC_FULLNESS_UP"; break;
		case 1058: result.second = "D_HAULING_STOP_LC_FULLNESS_DOWN"; break;
		case 1059: result.second = "D_HAULING_STOP_LC_MORE_LESS"; break;
		case 1060: result.second = "D_HAULING_STOP_LC_DESIRED_TOTAL"; break;
		case 1061: result.second = "D_HAULING_STOP_LC_CHANGE"; break;
		case 1062: result.second = "D_HAULING_STOP_LC_ADVANCED"; break;
		case 1063: result.second = "D_BURROWS"; break;
		case 1064: result.second = "D_BURROWS_ADD"; break;
		case 1065: result.second = "D_BURROWS_DELETE"; break;
		case 1066: result.second = "D_BURROWS_DEFINE"; break;
		case 1067: result.second = "D_BURROWS_ADD_UNIT"; break;
		case 1068: result.second = "D_BURROWS_WORKSHOP_LIMIT"; break;
		case 1069: result.second = "D_BURROWS_CENTER"; break;
		case 1070: result.second = "D_BURROWS_NAME"; break;
		case 1071: result.second = "D_BURROWS_CHANGE_SELECTION"; break;
		case 1072: result.second = "D_BURROWS_BRUSH"; break;
		case 1073: result.second = "D_BURROWS_REMOVE"; break;
		case 1074: result.second = "D_NOTE"; break;
		case 1075: result.second = "D_NOTE_PLACE"; break;
		case 1076: result.second = "D_NOTE_DELETE"; break;
		case 1077: result.second = "D_NOTE_NAME"; break;
		case 1078: result.second = "D_NOTE_ENTER"; break;
		case 1079: result.second = "D_NOTE_ADOPT_SYMBOL"; break;
		case 1080: result.second = "D_NOTE_CHANGE_SELECTION"; break;
		case 1081: result.second = "D_NOTE_POINTS"; break;
		case 1082: result.second = "D_NOTE_ROUTE"; break;
		case 1083: result.second = "D_NOTE_ROUTE_ADD"; break;
		case 1084: result.second = "D_NOTE_ROUTE_EDIT"; break;
		case 1085: result.second = "D_NOTE_ROUTE_DELETE"; break;
		case 1086: result.second = "D_NOTE_ROUTE_CENTER"; break;
		case 1087: result.second = "D_NOTE_ROUTE_NAME"; break;
		case 1088: result.second = "D_BUILDJOB"; break;
		case 1089: result.second = "D_STATUS"; break;
		case 1090: result.second = "D_STATUS_OVERALL_HEALTH_RECENTER"; break;
		case 1091: result.second = "D_BUILDITEM"; break;
		case 1092: result.second = "D_BITEM_FORBID"; break;
		case 1093: result.second = "D_BITEM_DUMP"; break;
		case 1094: result.second = "D_BITEM_MELT"; break;
		case 1095: result.second = "D_BITEM_HIDE"; break;
		case 1096: result.second = "D_BITEM_NAME"; break;
		case 1097: result.second = "D_LOOK_FORBID"; break;
		case 1098: result.second = "D_LOOK_DUMP"; break;
		case 1099: result.second = "D_LOOK_MELT"; break;
		case 1100: result.second = "D_LOOK_HIDE"; break;
		case 1101: result.second = "D_LOOK_FOLLOW"; break;
		case 1102: result.second = "D_LOOK_ARENA_CREATURE"; break;
		case 1103: result.second = "D_LOOK_ARENA_ADV_MODE"; break;
		case 1104: result.second = "D_LOOK_ARENA_WATER"; break;
		case 1105: result.second = "D_LOOK_ARENA_MAGMA"; break;
		case 1106: result.second = "ARENA_CREATURE_SIDE_DOWN"; break;
		case 1107: result.second = "ARENA_CREATURE_SIDE_UP"; break;
		case 1108: result.second = "ARENA_CREATURE_NEW_ITEM"; break;
		case 1109: result.second = "ARENA_CREATURE_BLANK_LIST"; break;
		case 1110: result.second = "ARENA_CREATURE_REMOVE_ITEM"; break;
		case 1111: result.second = "ARENA_CREATURE_UNDEAD"; break;
		case 1112: result.second = "ARENA_CREATURE_STRING"; break;
		case 1113: result.second = "ARENA_CONFLICT_STATE_1"; break;
		case 1114: result.second = "ARENA_CONFLICT_STATE_2"; break;
		case 1115: result.second = "ARENA_MORALE"; break;
		case 1116: result.second = "ARENA_WEATHER"; break;
		case 1117: result.second = "ARENA_WEATHER_SNOW"; break;
		case 1118: result.second = "ARENA_WEATHER_MUD"; break;
		case 1119: result.second = "ARENA_WEATHER_CLEAR_SPATTER"; break;
		case 1120: result.second = "D_LOOK_ARENA_TREE"; break;
		case 1121: result.second = "ARENA_TREE_FILTER"; break;
		case 1122: result.second = "ARENA_TREE_AGE"; break;
		case 1123: result.second = "D_LOOK_ARENA_MOUNT"; break;
		case 1124: result.second = "ASSIGNTRADE_VIEW"; break;
		case 1125: result.second = "ASSIGNTRADE_STRING"; break;
		case 1126: result.second = "ASSIGNTRADE_EXCLUDE_PROHIBITED"; break;
		case 1127: result.second = "ASSIGNTRADE_PENDING"; break;
		case 1128: result.second = "ASSIGNTRADE_SORT"; break;
		case 1129: result.second = "NOBLELIST_REPLACE"; break;
		case 1130: result.second = "NOBLELIST_SETTINGS"; break;
		case 1131: result.second = "NOBLELIST_CAPITAL"; break;
		case 1132: result.second = "NOBLELIST_VIEW_CANDIDATE"; break;
		case 1133: result.second = "TRADE_VIEW"; break;
		case 1134: result.second = "TRADE_TRADE"; break;
		case 1135: result.second = "TRADE_OFFER"; break;
		case 1136: result.second = "TRADE_SEIZE"; break;
		case 1137: result.second = "MILITARY_ACTIVATE"; break;
		case 1138: result.second = "MILITARY_VIEW"; break;
		case 1139: result.second = "MILITARY_WEAPON"; break;
		case 1140: result.second = "MILITARY_ZOOM"; break;
		case 1141: result.second = "ANNOUNCE_ZOOM"; break;
		case 1142: result.second = "ANNOUNCE_ZOOM_2"; break;
		case 1143: result.second = "UNITJOB_REMOVE_CRE"; break;
		case 1144: result.second = "UNITJOB_ZOOM_CRE"; break;
		case 1145: result.second = "UNITJOB_ZOOM_BUILD"; break;
		case 1146: result.second = "UNITJOB_VIEW_UNIT"; break;
		case 1147: result.second = "UNITJOB_VIEW_JOB"; break;
		case 1148: result.second = "UNITJOB_MANAGER"; break;
		case 1149: result.second = "MANAGER_NEW_ORDER"; break;
		case 1150: result.second = "MANAGER_REMOVE"; break;
		case 1151: result.second = "MANAGER_PROMOTE"; break;
		case 1152: result.second = "MANAGER_MAX"; break;
		case 1153: result.second = "MANAGER_WAGES"; break;
		case 1154: result.second = "MANAGER_CONDITIONS"; break;
		case 1155: result.second = "MANAGER_DETAILS"; break;
		case 1156: result.second = "WORK_ORDER_CONDITION_ADD_ITEM"; break;
		case 1157: result.second = "WORK_ORDER_CONDITION_ADD_ORDER"; break;
		case 1158: result.second = "WORK_ORDER_CONDITION_ITEM_TYPE"; break;
		case 1159: result.second = "WORK_ORDER_CONDITION_ITEM_MATERIAL"; break;
		case 1160: result.second = "WORK_ORDER_CONDITION_ITEM_TRAITS"; break;
		case 1161: result.second = "WORK_ORDER_CONDITION_ITEM_INEQUALITY"; break;
		case 1162: result.second = "WORK_ORDER_CONDITION_ITEM_NUMBER"; break;
		case 1163: result.second = "WORK_ORDER_CONDITION_DELETE"; break;
		case 1164: result.second = "WORK_ORDER_CONDITION_ORDER_ACTIVATION"; break;
		case 1165: result.second = "WORK_ORDER_CONDITION_REAGENTS"; break;
		case 1166: result.second = "WORK_ORDER_CONDITION_PRODUCTS"; break;
		case 1167: result.second = "DESIGNATE_BITEM"; break;
		case 1168: result.second = "DESIGNATE_CLAIM"; break;
		case 1169: result.second = "DESIGNATE_UNCLAIM"; break;
		case 1170: result.second = "DESIGNATE_MELT"; break;
		case 1171: result.second = "DESIGNATE_NO_MELT"; break;
		case 1172: result.second = "DESIGNATE_DUMP"; break;
		case 1173: result.second = "DESIGNATE_NO_DUMP"; break;
		case 1174: result.second = "DESIGNATE_HIDE"; break;
		case 1175: result.second = "DESIGNATE_NO_HIDE"; break;
		case 1176: result.second = "DESIGNATE_DIG"; break;
		case 1177: result.second = "DESIGNATE_DIG_REMOVE_STAIRS_RAMPS"; break;
		case 1178: result.second = "DESIGNATE_TRAFFIC"; break;
		case 1179: result.second = "DESIGNATE_TRAFFIC_HIGH"; break;
		case 1180: result.second = "DESIGNATE_TRAFFIC_NORMAL"; break;
		case 1181: result.second = "DESIGNATE_TRAFFIC_LOW"; break;
		case 1182: result.second = "DESIGNATE_TRAFFIC_RESTRICTED"; break;
		case 1183: result.second = "DESIGNATE_TRAFFIC_INCREASE_WEIGHT"; break;
		case 1184: result.second = "DESIGNATE_TRAFFIC_DECREASE_WEIGHT"; break;
		case 1185: result.second = "DESIGNATE_TRAFFIC_INCREASE_WEIGHT_MORE"; break;
		case 1186: result.second = "DESIGNATE_TRAFFIC_DECREASE_WEIGHT_MORE"; break;
		case 1187: result.second = "DESIGNATE_STAIR_UP"; break;
		case 1188: result.second = "DESIGNATE_STAIR_DOWN"; break;
		case 1189: result.second = "DESIGNATE_STAIR_UPDOWN"; break;
		case 1190: result.second = "DESIGNATE_RAMP"; break;
		case 1191: result.second = "DESIGNATE_CHANNEL"; break;
		case 1192: result.second = "DESIGNATE_CHOP"; break;
		case 1193: result.second = "DESIGNATE_PLANTS"; break;
		case 1194: result.second = "DESIGNATE_SMOOTH"; break;
		case 1195: result.second = "DESIGNATE_ENGRAVE"; break;
		case 1196: result.second = "DESIGNATE_DETAILS"; break;
		case 1197: result.second = "DESIGNATE_FORTIFY"; break;
		case 1198: result.second = "DESIGNATE_TRACK"; break;
		case 1199: result.second = "DESIGNATE_TOGGLE_ENGRAVING"; break;
		case 1200: result.second = "DESIGNATE_STANDARD_MARKER"; break;
		case 1201: result.second = "DESIGNATE_MINE_MODE"; break;
		case 1202: result.second = "DESIGNATE_TOGGLE_MARKER"; break;
		case 1203: result.second = "DESIGNATE_UNDO"; break;
		case 1204: result.second = "DESIGNATE_REMOVE_CONSTRUCTION"; break;
		case 1205: result.second = "ITEM_DESCRIPTION"; break;
		case 1206: result.second = "ITEM_FORBID"; break;
		case 1207: result.second = "ITEM_MELT"; break;
		case 1208: result.second = "ITEM_DUMP"; break;
		case 1209: result.second = "ITEM_HIDE"; break;
		case 1210: result.second = "UNITVIEW_CUSTOMIZE"; break;
		case 1211: result.second = "UNITVIEW_HEALTH"; break;
		case 1212: result.second = "UNITVIEW_RELATIONSHIPS"; break;
		case 1213: result.second = "UNITVIEW_RELATIONSHIPS_ZOOM"; break;
		case 1214: result.second = "UNITVIEW_RELATIONSHIPS_VIEW"; break;
		case 1215: result.second = "UNITVIEW_KILLS"; break;
		case 1216: result.second = "UNITVIEW_GEN"; break;
		case 1217: result.second = "UNITVIEW_INV"; break;
		case 1218: result.second = "UNITVIEW_PRF"; break;
		case 1219: result.second = "UNITVIEW_WND"; break;
		case 1220: result.second = "UNITVIEW_FOLLOW"; break;
		case 1221: result.second = "UNITVIEW_NEXT"; break;
		case 1222: result.second = "UNITVIEW_SLAUGHTER"; break;
		case 1223: result.second = "UNITVIEW_GELD"; break;
		case 1224: result.second = "UNITVIEW_GEN_COMBAT"; break;
		case 1225: result.second = "UNITVIEW_GEN_LABOR"; break;
		case 1226: result.second = "UNITVIEW_GEN_MISC"; break;
		case 1227: result.second = "UNITVIEW_PRF_PROF"; break;
		case 1228: result.second = "UNITVIEW_PRF_PET"; break;
		case 1229: result.second = "UNITVIEW_PRF_EXPEL"; break;
		case 1230: result.second = "UNITVIEW_PRF_VIEW"; break;
		case 1231: result.second = "UNITVIEW_PRF_NEW_SQUAD"; break;
		case 1232: result.second = "UNITVIEW_PRF_REMOVE_FROM_SQUAD"; break;
		case 1233: result.second = "UNITVIEW_PRF_NAME_CURRENT_SQUAD"; break;
		case 1234: result.second = "UNITVIEW_PRF_NAME_SELECTED_SQUAD"; break;
		case 1235: result.second = "UNITVIEW_PRF_OCCUPATION"; break;
		case 1236: result.second = "CUSTOMIZE_UNIT_NICKNAME"; break;
		case 1237: result.second = "CUSTOMIZE_UNIT_PROFNAME"; break;
		case 1238: result.second = "IMAGE_CREATOR_FILTER"; break;
		case 1239: result.second = "IMAGE_CREATOR_NAME"; break;
		case 1240: result.second = "IMAGE_CREATOR_DONE"; break;
		case 1241: result.second = "CIV_RAID"; break;
		case 1242: result.second = "CIV_CENTER_ON_FORT"; break;
		case 1243: result.second = "CIV_HOLDINGS"; break;
		case 1244: result.second = "CIV_MAP_LEGEND"; break;
		case 1245: result.second = "CIV_REMOVE_MISSION"; break;
		case 1246: result.second = "CIV_RESCUE"; break;
		case 1247: result.second = "CIV_RECOVER"; break;
		case 1248: result.second = "CIV_WORLD"; break;
		case 1249: result.second = "CIV_MISSIONS"; break;
		case 1250: result.second = "CIV_MISSION_DETAILS"; break;
		case 1251: result.second = "CIV_MISSION_FREE_CAPTIVES"; break;
		case 1252: result.second = "CIV_MISSION_RELEASE_OTHERS"; break;
		case 1253: result.second = "CIV_MISSION_TAKE_ARTIFACTS"; break;
		case 1254: result.second = "CIV_MISSION_TAKE_ITEMS"; break;
		case 1255: result.second = "CIV_MISSION_TAKE_LIVESTOCK"; break;
		case 1256: result.second = "CIV_MISSION_RAID"; break;
		case 1257: result.second = "CIV_MISSION_PILLAGE"; break;
		case 1258: result.second = "CIV_MISSION_RAZE"; break;
		case 1259: result.second = "CIV_MISSION_TRIBUTE_ONE_TIME"; break;
		case 1260: result.second = "CIV_MISSION_TRIBUTE_ONGOING"; break;
		case 1261: result.second = "CIV_MISSION_CONQUER"; break;
		case 1262: result.second = "CIV_MISSION_DEMAND_SURRENDER"; break;
		case 1263: result.second = "CIV_NEWS"; break;
		case 1264: result.second = "CIV_PEOPLE"; break;
		case 1265: result.second = "CIV_ARTIFACTS"; break;
		case 1266: result.second = "CIV_CIVS"; break;
		case 1267: result.second = "D_MILITARY_CREATE_SQUAD"; break;
		case 1268: result.second = "D_MILITARY_DISBAND_SQUAD"; break;
		case 1269: result.second = "D_MILITARY_CREATE_SUB_SQUAD"; break;
		case 1270: result.second = "D_MILITARY_CANCEL_ORDERS"; break;
		case 1271: result.second = "D_MILITARY_POSITIONS"; break;
		case 1272: result.second = "D_MILITARY_ALERTS"; break;
		case 1273: result.second = "D_MILITARY_ALERTS_ADD"; break;
		case 1274: result.second = "D_MILITARY_ALERTS_DELETE"; break;
		case 1275: result.second = "D_MILITARY_ALERTS_SET"; break;
		case 1276: result.second = "D_MILITARY_ALERTS_NAME"; break;
		case 1277: result.second = "D_MILITARY_ALERTS_SET_RETAIN"; break;
		case 1278: result.second = "D_MILITARY_EQUIP"; break;
		case 1279: result.second = "D_MILITARY_EQUIP_CUSTOMIZE"; break;
		case 1280: result.second = "D_MILITARY_EQUIP_UNIFORM"; break;
		case 1281: result.second = "D_MILITARY_EQUIP_PRIORITY"; break;
		case 1282: result.second = "D_MILITARY_UNIFORMS"; break;
		case 1283: result.second = "D_MILITARY_SUPPLIES"; break;
		case 1284: result.second = "D_MILITARY_SUPPLIES_WATER_DOWN"; break;
		case 1285: result.second = "D_MILITARY_SUPPLIES_WATER_UP"; break;
		case 1286: result.second = "D_MILITARY_SUPPLIES_FOOD_DOWN"; break;
		case 1287: result.second = "D_MILITARY_SUPPLIES_FOOD_UP"; break;
		case 1288: result.second = "D_MILITARY_AMMUNITION"; break;
		case 1289: result.second = "D_MILITARY_AMMUNITION_ADD_ITEM"; break;
		case 1290: result.second = "D_MILITARY_AMMUNITION_REMOVE_ITEM"; break;
		case 1291: result.second = "D_MILITARY_AMMUNITION_LOWER_AMOUNT"; break;
		case 1292: result.second = "D_MILITARY_AMMUNITION_RAISE_AMOUNT"; break;
		case 1293: result.second = "D_MILITARY_AMMUNITION_LOWER_AMOUNT_LOTS"; break;
		case 1294: result.second = "D_MILITARY_AMMUNITION_RAISE_AMOUNT_LOTS"; break;
		case 1295: result.second = "D_MILITARY_AMMUNITION_MATERIAL"; break;
		case 1296: result.second = "D_MILITARY_AMMUNITION_COMBAT"; break;
		case 1297: result.second = "D_MILITARY_AMMUNITION_TRAINING"; break;
		case 1298: result.second = "D_MILITARY_TRAINING"; break;
		case 1299: result.second = "D_MILITARY_SCHEDULE"; break;
		case 1300: result.second = "D_MILITARY_ADD_UNIFORM"; break;
		case 1301: result.second = "D_MILITARY_DELETE_UNIFORM"; break;
		case 1302: result.second = "D_MILITARY_NAME_UNIFORM"; break;
		case 1303: result.second = "D_MILITARY_NAME_SQUAD"; break;
		case 1304: result.second = "D_MILITARY_ADD_ARMOR"; break;
		case 1305: result.second = "D_MILITARY_ADD_PANTS"; break;
		case 1306: result.second = "D_MILITARY_ADD_HELM"; break;
		case 1307: result.second = "D_MILITARY_ADD_GLOVES"; break;
		case 1308: result.second = "D_MILITARY_ADD_BOOTS"; break;
		case 1309: result.second = "D_MILITARY_ADD_SHIELD"; break;
		case 1310: result.second = "D_MILITARY_ADD_WEAPON"; break;
		case 1311: result.second = "D_MILITARY_ADD_MATERIAL"; break;
		case 1312: result.second = "D_MILITARY_ADD_COLOR"; break;
		case 1313: result.second = "D_MILITARY_REPLACE_CLOTHING"; break;
		case 1314: result.second = "D_MILITARY_EXACT_MATCH"; break;
		case 1315: result.second = "D_SQUADS_MOVE"; break;
		case 1316: result.second = "D_SQUADS_KILL"; break;
		case 1317: result.second = "D_SQUADS_KILL_LIST"; break;
		case 1318: result.second = "D_SQUADS_KILL_RECT"; break;
		case 1319: result.second = "D_SQUADS_SCHEDULE"; break;
		case 1320: result.second = "D_SQUADS_CANCEL_ORDER"; break;
		case 1321: result.second = "D_SQUADS_ALERT"; break;
		case 1322: result.second = "D_SQUADS_SELECT_INDIVIDUALS"; break;
		case 1323: result.second = "D_SQUADS_CENTER"; break;
		case 1324: result.second = "D_SQUAD_SCH_SLEEP"; break;
		case 1325: result.second = "D_SQUAD_SCH_CIVILIAN_UNIFORM"; break;
		case 1326: result.second = "D_SQUAD_SCH_GIVE_ORDER"; break;
		case 1327: result.second = "D_SQUAD_SCH_EDIT_ORDER"; break;
		case 1328: result.second = "D_SQUAD_SCH_CANCEL_ORDER"; break;
		case 1329: result.second = "D_SQUAD_SCH_COPY_ORDERS"; break;
		case 1330: result.second = "D_SQUAD_SCH_PASTE_ORDERS"; break;
		case 1331: result.second = "D_SQUAD_SCH_MS_NAME"; break;
		case 1332: result.second = "STRING_A000"; break;
		case 1333: result.second = "STRING_A001"; break;
		case 1334: result.second = "STRING_A002"; break;
		case 1335: result.second = "STRING_A003"; break;
		case 1336: result.second = "STRING_A004"; break;
		case 1337: result.second = "STRING_A005"; break;
		case 1338: result.second = "STRING_A006"; break;
		case 1339: result.second = "STRING_A007"; break;
		case 1340: result.second = "STRING_A008"; break;
		case 1341: result.second = "STRING_A009"; break;
		case 1342: result.second = "STRING_A010"; break;
		case 1343: result.second = "STRING_A011"; break;
		case 1344: result.second = "STRING_A012"; break;
		case 1345: result.second = "STRING_A013"; break;
		case 1346: result.second = "STRING_A014"; break;
		case 1347: result.second = "STRING_A015"; break;
		case 1348: result.second = "STRING_A016"; break;
		case 1349: result.second = "STRING_A017"; break;
		case 1350: result.second = "STRING_A018"; break;
		case 1351: result.second = "STRING_A019"; break;
		case 1352: result.second = "STRING_A020"; break;
		case 1353: result.second = "STRING_A021"; break;
		case 1354: result.second = "STRING_A022"; break;
		case 1355: result.second = "STRING_A023"; break;
		case 1356: result.second = "STRING_A024"; break;
		case 1357: result.second = "STRING_A025"; break;
		case 1358: result.second = "STRING_A026"; break;
		case 1359: result.second = "STRING_A027"; break;
		case 1360: result.second = "STRING_A028"; break;
		case 1361: result.second = "STRING_A029"; break;
		case 1362: result.second = "STRING_A030"; break;
		case 1363: result.second = "STRING_A031"; break;
		case 1364: result.second = "STRING_A032"; break;
		case 1365: result.second = "STRING_A033"; break;
		case 1366: result.second = "STRING_A034"; break;
		case 1367: result.second = "STRING_A035"; break;
		case 1368: result.second = "STRING_A036"; break;
		case 1369: result.second = "STRING_A037"; break;
		case 1370: result.second = "STRING_A038"; break;
		case 1371: result.second = "STRING_A039"; break;
		case 1372: result.second = "STRING_A040"; break;
		case 1373: result.second = "STRING_A041"; break;
		case 1374: result.second = "STRING_A042"; break;
		case 1375: result.second = "STRING_A043"; break;
		case 1376: result.second = "STRING_A044"; break;
		case 1377: result.second = "STRING_A045"; break;
		case 1378: result.second = "STRING_A046"; break;
		case 1379: result.second = "STRING_A047"; break;
		case 1380: result.second = "STRING_A048"; break;
		case 1381: result.second = "STRING_A049"; break;
		case 1382: result.second = "STRING_A050"; break;
		case 1383: result.second = "STRING_A051"; break;
		case 1384: result.second = "STRING_A052"; break;
		case 1385: result.second = "STRING_A053"; break;
		case 1386: result.second = "STRING_A054"; break;
		case 1387: result.second = "STRING_A055"; break;
		case 1388: result.second = "STRING_A056"; break;
		case 1389: result.second = "STRING_A057"; break;
		case 1390: result.second = "STRING_A058"; break;
		case 1391: result.second = "STRING_A059"; break;
		case 1392: result.second = "STRING_A060"; break;
		case 1393: result.second = "STRING_A061"; break;
		case 1394: result.second = "STRING_A062"; break;
		case 1395: result.second = "STRING_A063"; break;
		case 1396: result.second = "STRING_A064"; break;
		case 1397: result.second = "STRING_A065"; break;
		case 1398: result.second = "STRING_A066"; break;
		case 1399: result.second = "STRING_A067"; break;
		case 1400: result.second = "STRING_A068"; break;
		case 1401: result.second = "STRING_A069"; break;
		case 1402: result.second = "STRING_A070"; break;
		case 1403: result.second = "STRING_A071"; break;
		case 1404: result.second = "STRING_A072"; break;
		case 1405: result.second = "STRING_A073"; break;
		case 1406: result.second = "STRING_A074"; break;
		case 1407: result.second = "STRING_A075"; break;
		case 1408: result.second = "STRING_A076"; break;
		case 1409: result.second = "STRING_A077"; break;
		case 1410: result.second = "STRING_A078"; break;
		case 1411: result.second = "STRING_A079"; break;
		case 1412: result.second = "STRING_A080"; break;
		case 1413: result.second = "STRING_A081"; break;
		case 1414: result.second = "STRING_A082"; break;
		case 1415: result.second = "STRING_A083"; break;
		case 1416: result.second = "STRING_A084"; break;
		case 1417: result.second = "STRING_A085"; break;
		case 1418: result.second = "STRING_A086"; break;
		case 1419: result.second = "STRING_A087"; break;
		case 1420: result.second = "STRING_A088"; break;
		case 1421: result.second = "STRING_A089"; break;
		case 1422: result.second = "STRING_A090"; break;
		case 1423: result.second = "STRING_A091"; break;
		case 1424: result.second = "STRING_A092"; break;
		case 1425: result.second = "STRING_A093"; break;
		case 1426: result.second = "STRING_A094"; break;
		case 1427: result.second = "STRING_A095"; break;
		case 1428: result.second = "STRING_A096"; break;
		case 1429: result.second = "STRING_A097"; break;
		case 1430: result.second = "STRING_A098"; break;
		case 1431: result.second = "STRING_A099"; break;
		case 1432: result.second = "STRING_A100"; break;
		case 1433: result.second = "STRING_A101"; break;
		case 1434: result.second = "STRING_A102"; break;
		case 1435: result.second = "STRING_A103"; break;
		case 1436: result.second = "STRING_A104"; break;
		case 1437: result.second = "STRING_A105"; break;
		case 1438: result.second = "STRING_A106"; break;
		case 1439: result.second = "STRING_A107"; break;
		case 1440: result.second = "STRING_A108"; break;
		case 1441: result.second = "STRING_A109"; break;
		case 1442: result.second = "STRING_A110"; break;
		case 1443: result.second = "STRING_A111"; break;
		case 1444: result.second = "STRING_A112"; break;
		case 1445: result.second = "STRING_A113"; break;
		case 1446: result.second = "STRING_A114"; break;
		case 1447: result.second = "STRING_A115"; break;
		case 1448: result.second = "STRING_A116"; break;
		case 1449: result.second = "STRING_A117"; break;
		case 1450: result.second = "STRING_A118"; break;
		case 1451: result.second = "STRING_A119"; break;
		case 1452: result.second = "STRING_A120"; break;
		case 1453: result.second = "STRING_A121"; break;
		case 1454: result.second = "STRING_A122"; break;
		case 1455: result.second = "STRING_A123"; break;
		case 1456: result.second = "STRING_A124"; break;
		case 1457: result.second = "STRING_A125"; break;
		case 1458: result.second = "STRING_A126"; break;
		case 1459: result.second = "STRING_A128"; break;
		case 1460: result.second = "STRING_A129"; break;
		case 1461: result.second = "STRING_A130"; break;
		case 1462: result.second = "STRING_A131"; break;
		case 1463: result.second = "STRING_A132"; break;
		case 1464: result.second = "STRING_A133"; break;
		case 1465: result.second = "STRING_A134"; break;
		case 1466: result.second = "STRING_A135"; break;
		case 1467: result.second = "STRING_A136"; break;
		case 1468: result.second = "STRING_A137"; break;
		case 1469: result.second = "STRING_A138"; break;
		case 1470: result.second = "STRING_A139"; break;
		case 1471: result.second = "STRING_A140"; break;
		case 1472: result.second = "STRING_A141"; break;
		case 1473: result.second = "STRING_A142"; break;
		case 1474: result.second = "STRING_A143"; break;
		case 1475: result.second = "STRING_A144"; break;
		case 1476: result.second = "STRING_A145"; break;
		case 1477: result.second = "STRING_A146"; break;
		case 1478: result.second = "STRING_A147"; break;
		case 1479: result.second = "STRING_A148"; break;
		case 1480: result.second = "STRING_A149"; break;
		case 1481: result.second = "STRING_A150"; break;
		case 1482: result.second = "STRING_A151"; break;
		case 1483: result.second = "STRING_A152"; break;
		case 1484: result.second = "STRING_A153"; break;
		case 1485: result.second = "STRING_A154"; break;
		case 1486: result.second = "STRING_A155"; break;
		case 1487: result.second = "STRING_A156"; break;
		case 1488: result.second = "STRING_A157"; break;
		case 1489: result.second = "STRING_A158"; break;
		case 1490: result.second = "STRING_A159"; break;
		case 1491: result.second = "STRING_A160"; break;
		case 1492: result.second = "STRING_A161"; break;
		case 1493: result.second = "STRING_A162"; break;
		case 1494: result.second = "STRING_A163"; break;
		case 1495: result.second = "STRING_A164"; break;
		case 1496: result.second = "STRING_A165"; break;
		case 1497: result.second = "STRING_A166"; break;
		case 1498: result.second = "STRING_A167"; break;
		case 1499: result.second = "STRING_A168"; break;
		case 1500: result.second = "STRING_A169"; break;
		case 1501: result.second = "STRING_A170"; break;
		case 1502: result.second = "STRING_A171"; break;
		case 1503: result.second = "STRING_A172"; break;
		case 1504: result.second = "STRING_A173"; break;
		case 1505: result.second = "STRING_A174"; break;
		case 1506: result.second = "STRING_A175"; break;
		case 1507: result.second = "STRING_A176"; break;
		case 1508: result.second = "STRING_A177"; break;
		case 1509: result.second = "STRING_A178"; break;
		case 1510: result.second = "STRING_A179"; break;
		case 1511: result.second = "STRING_A180"; break;
		case 1512: result.second = "STRING_A181"; break;
		case 1513: result.second = "STRING_A182"; break;
		case 1514: result.second = "STRING_A183"; break;
		case 1515: result.second = "STRING_A184"; break;
		case 1516: result.second = "STRING_A185"; break;
		case 1517: result.second = "STRING_A186"; break;
		case 1518: result.second = "STRING_A187"; break;
		case 1519: result.second = "STRING_A188"; break;
		case 1520: result.second = "STRING_A189"; break;
		case 1521: result.second = "STRING_A190"; break;
		case 1522: result.second = "STRING_A191"; break;
		case 1523: result.second = "STRING_A192"; break;
		case 1524: result.second = "STRING_A193"; break;
		case 1525: result.second = "STRING_A194"; break;
		case 1526: result.second = "STRING_A195"; break;
		case 1527: result.second = "STRING_A196"; break;
		case 1528: result.second = "STRING_A197"; break;
		case 1529: result.second = "STRING_A198"; break;
		case 1530: result.second = "STRING_A199"; break;
		case 1531: result.second = "STRING_A200"; break;
		case 1532: result.second = "STRING_A201"; break;
		case 1533: result.second = "STRING_A202"; break;
		case 1534: result.second = "STRING_A203"; break;
		case 1535: result.second = "STRING_A204"; break;
		case 1536: result.second = "STRING_A205"; break;
		case 1537: result.second = "STRING_A206"; break;
		case 1538: result.second = "STRING_A207"; break;
		case 1539: result.second = "STRING_A208"; break;
		case 1540: result.second = "STRING_A209"; break;
		case 1541: result.second = "STRING_A210"; break;
		case 1542: result.second = "STRING_A211"; break;
		case 1543: result.second = "STRING_A212"; break;
		case 1544: result.second = "STRING_A213"; break;
		case 1545: result.second = "STRING_A214"; break;
		case 1546: result.second = "STRING_A215"; break;
		case 1547: result.second = "STRING_A216"; break;
		case 1548: result.second = "STRING_A217"; break;
		case 1549: result.second = "STRING_A218"; break;
		case 1550: result.second = "STRING_A219"; break;
		case 1551: result.second = "STRING_A220"; break;
		case 1552: result.second = "STRING_A221"; break;
		case 1553: result.second = "STRING_A222"; break;
		case 1554: result.second = "STRING_A223"; break;
		case 1555: result.second = "STRING_A224"; break;
		case 1556: result.second = "STRING_A225"; break;
		case 1557: result.second = "STRING_A226"; break;
		case 1558: result.second = "STRING_A227"; break;
		case 1559: result.second = "STRING_A228"; break;
		case 1560: result.second = "STRING_A229"; break;
		case 1561: result.second = "STRING_A230"; break;
		case 1562: result.second = "STRING_A231"; break;
		case 1563: result.second = "STRING_A232"; break;
		case 1564: result.second = "STRING_A233"; break;
		case 1565: result.second = "STRING_A234"; break;
		case 1566: result.second = "STRING_A235"; break;
		case 1567: result.second = "STRING_A236"; break;
		case 1568: result.second = "STRING_A237"; break;
		case 1569: result.second = "STRING_A238"; break;
		case 1570: result.second = "STRING_A239"; break;
		case 1571: result.second = "STRING_A240"; break;
		case 1572: result.second = "STRING_A241"; break;
		case 1573: result.second = "STRING_A242"; break;
		case 1574: result.second = "STRING_A243"; break;
		case 1575: result.second = "STRING_A244"; break;
		case 1576: result.second = "STRING_A245"; break;
		case 1577: result.second = "STRING_A246"; break;
		case 1578: result.second = "STRING_A247"; break;
		case 1579: result.second = "STRING_A248"; break;
		case 1580: result.second = "STRING_A249"; break;
		case 1581: result.second = "STRING_A250"; break;
		case 1582: result.second = "STRING_A251"; break;
		case 1583: result.second = "STRING_A252"; break;
		case 1584: result.second = "STRING_A253"; break;
		case 1585: result.second = "STRING_A254"; break;
		case 1586: result.second = "STRING_A255"; break;
		case 1587: result.second = "KEYBINDING_COMPLETE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_dfhack_knowledge_scholar_flag_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "philosophy_logic_formal_reasoning"; break;
		case 1: result.second = "philosophy_logic_deductive_reasoning"; break;
		case 2: result.second = "philosophy_logic_syllogistic_logic"; break;
		case 3: result.second = "philosophy_logic_hypothetical_syllogisms"; break;
		case 4: result.second = "philosophy_logic_propositional_logic"; break;
		case 5: result.second = "philosophy_logic_dialectic_reasoning"; break;
		case 6: result.second = "philosophy_logic_analogical_inference"; break;
		case 7: result.second = "philosophy_ethics_applied_medical"; break;
		case 8: result.second = "philosophy_ethics_individual_value"; break;
		case 9: result.second = "philosophy_ethics_state_consequentialism"; break;
		case 10: result.second = "philosophy_epistemology_truth"; break;
		case 11: result.second = "philosophy_epistemology_perception"; break;
		case 12: result.second = "philosophy_epistemology_justification"; break;
		case 13: result.second = "philosophy_epistemology_belief"; break;
		case 14: result.second = "philosophy_metaphysics_existence"; break;
		case 15: result.second = "philosophy_metaphysics_time"; break;
		case 16: result.second = "philosophy_metaphysics_mind_body"; break;
		case 17: result.second = "philosophy_metaphysics_objects_and_properties"; break;
		case 18: result.second = "philosophy_metaphysics_wholes_and_parts"; break;
		case 19: result.second = "philosophy_metaphysics_events"; break;
		case 20: result.second = "philosophy_metaphysics_processes"; break;
		case 21: result.second = "philosophy_metaphysics_causation"; break;
		case 22: result.second = "philosophy_ethics_applied_military"; break;
		case 23: result.second = "philosophy_ethics_applied_interpersonal_conduct"; break;
		case 24: result.second = "philosophy_specialized_law"; break;
		case 25: result.second = "philosophy_specialized_education"; break;
		case 26: result.second = "philosophy_specialized_language_grammar"; break;
		case 27: result.second = "philosophy_specialized_language_etymology"; break;
		case 28: result.second = "philosophy_specialized_politics_diplomacy"; break;
		case 29: result.second = "philosophy_specialized_politics_government_forms"; break;
		case 30: result.second = "philosophy_specialized_politics_economic_policy"; break;
		case 31: result.second = "philosophy_specialized_politics_social_welfare"; break;
		case 32: result.second = "philosophy_logic_inductive_reasoning"; break;
		case 33: result.second = "philosophy_logic_direct_inference"; break;
		case 34: result.second = "philosophy_aesthetics_nature_of_beauty"; break;
		case 35: result.second = "philosophy_aesthetics_value_of_art"; break;
		case 36: result.second = "philosophy_specialized_language_dictionary"; break;
		case 64: result.second = "mathematics_method_proof_by_contradiction"; break;
		case 65: result.second = "mathematics_notation_zero"; break;
		case 66: result.second = "mathematics_notation_negative_numbers"; break;
		case 67: result.second = "mathematics_notation_large_numbers"; break;
		case 68: result.second = "mathematics_notation_positional"; break;
		case 69: result.second = "mathematics_geometry_basic_objects"; break;
		case 70: result.second = "mathematics_method_exhaustion"; break;
		case 71: result.second = "mathematics_geometry_similar_and_congruent_triangles"; break;
		case 72: result.second = "mathematics_geometry_geometric_mean_theorem"; break;
		case 73: result.second = "mathematics_geometry_isosceles_base_angles_equal"; break;
		case 74: result.second = "mathematics_geometry_inscribed_triangle_on_diameter_is_right"; break;
		case 75: result.second = "mathematics_geometry_pythagorean_theorem"; break;
		case 76: result.second = "mathematics_geometry_pythagorean_triples_small"; break;
		case 77: result.second = "mathematics_geometry_pythagorean_triples_3_digit"; break;
		case 78: result.second = "mathematics_geometry_pythagorean_triples_4_digit"; break;
		case 79: result.second = "mathematics_geometry_existence_of_incommensurable_ratios"; break;
		case 80: result.second = "mathematics_method_axiomatic_reasoning"; break;
		case 81: result.second = "mathematics_numbers_unique_prime_factorization"; break;
		case 82: result.second = "mathematics_numbers_algorithm_for_computing_gcd"; break;
		case 83: result.second = "mathematics_geometry_volume_of_pyramid"; break;
		case 84: result.second = "mathematics_geometry_volume_of_cone"; break;
		case 85: result.second = "mathematics_geometry_volume_of_sphere"; break;
		case 86: result.second = "mathematics_geometry_pi_to_4_digits"; break;
		case 87: result.second = "mathematics_numbers_division_algorithm"; break;
		case 88: result.second = "mathematics_geometry_table_of_chord_values"; break;
		case 89: result.second = "mathematics_geometry_area_of_triangle_from_side_lengths"; break;
		case 90: result.second = "mathematics_geometry_area_of_circle"; break;
		case 91: result.second = "mathematics_geometry_pi_to_6_digits"; break;
		case 92: result.second = "mathematics_geometry_definitions_and_basic_properties_of_conic_sections"; break;
		case 93: result.second = "mathematics_numbers_chinese_remainder_algorithm"; break;
		case 94: result.second = "mathematics_geometry_area_enclosed_by_line_and_parabola"; break;
		case 95: result.second = "mathematics_numbers_sieve_algorithm_for_primes"; break;
		case 96: result.second = "mathematics_numbers_root_2_to_5_digits"; break;
		case 97: result.second = "mathematics_numbers_infinite_primes"; break;
		case 98: result.second = "mathematics_numbers_root_2_irrational"; break;
		case 99: result.second = "mathematics_geometry_surface_area_of_sphere"; break;
		case 100: result.second = "mathematics_algebra_finite_summation_formulas"; break;
		case 101: result.second = "mathematics_algebra_solving_linear_systems"; break;
		case 102: result.second = "mathematics_algebra_balancing_and_completion"; break;
		case 103: result.second = "mathematics_algebra_quadratic_by_completing_square"; break;
		case 104: result.second = "mathematics_algebra_quadratic_formula"; break;
		case 105: result.second = "mathematics_notation_syncopated_algebra"; break;
		case 106: result.second = "mathematics_geometry_law_of_sines"; break;
		case 107: result.second = "mathematics_geometry_angle_sum_difference_trig_identities"; break;
		case 108: result.second = "mathematics_algebra_pascals_triangle"; break;
		case 109: result.second = "mathematics_algebra_solving_higher_order_polynomials"; break;
		case 110: result.second = "mathematics_notation_early_symbols_for_operations"; break;
		case 111: result.second = "mathematics_algebra_divergence_of_harmonic_series"; break;
		case 112: result.second = "mathematics_geometry_properties_of_chords"; break;
		case 128: result.second = "history_sourcing_basic_reliability"; break;
		case 129: result.second = "history_sourcing_role_of_systemic_bias"; break;
		case 130: result.second = "history_sourcing_role_of_state_bias_and_propaganda"; break;
		case 131: result.second = "history_sourcing_personal_interviews"; break;
		case 132: result.second = "history_theory_historical_causation"; break;
		case 133: result.second = "history_theory_historical_cycles"; break;
		case 134: result.second = "history_theory_social_cohesion"; break;
		case 135: result.second = "history_theory_social_conflict"; break;
		case 136: result.second = "history_form_biography"; break;
		case 137: result.second = "history_form_comparative_biography"; break;
		case 138: result.second = "history_form_biographical_dictionaries"; break;
		case 139: result.second = "history_form_autobiographical_adventure"; break;
		case 140: result.second = "history_form_genealogy"; break;
		case 141: result.second = "history_form_encyclopedia"; break;
		case 142: result.second = "history_form_cultural_history"; break;
		case 143: result.second = "history_form_cultural_comparison"; break;
		case 144: result.second = "history_sourcing_role_of_cultural_differences"; break;
		case 145: result.second = "history_form_alternate_history"; break;
		case 146: result.second = "history_sourcing_basic_archaeology"; break;
		case 147: result.second = "history_form_treatise_on_tech_evolution"; break;
		case 160: result.second = "astronomy_phases_of_the_moon"; break;
		case 161: result.second = "astronomy_summer_winter_moon"; break;
		case 162: result.second = "astronomy_path_of_the_moon"; break;
		case 163: result.second = "astronomy_tides_and_the_moon"; break;
		case 164: result.second = "astronomy_height_of_tides_vs_moon_and_sun"; break;
		case 165: result.second = "astronomy_summer_winter_sun"; break;
		case 166: result.second = "astronomy_relationship_between_lunar_solar_year"; break;
		case 167: result.second = "astronomy_daylight_variation_with_solar_year"; break;
		case 168: result.second = "astronomy_geocentric_model"; break;
		case 169: result.second = "astronomy_heliocentric_model"; break;
		case 170: result.second = "astronomy_dates_of_lunar_and_solar_eclipses"; break;
		case 171: result.second = "astronomy_star_charts"; break;
		case 172: result.second = "astronomy_star_catalogues_100"; break;
		case 173: result.second = "astronomy_star_catalogues_1000"; break;
		case 174: result.second = "astronomy_star_color_classification"; break;
		case 175: result.second = "astronomy_star_magnitude_classification"; break;
		case 176: result.second = "astronomy_shape_of_the_world"; break;
		case 177: result.second = "astronomy_precession_of_equinoxes"; break;
		case 178: result.second = "astronomy_method_empirical_observation"; break;
		case 179: result.second = "astronomy_method_path_models"; break;
		case 192: result.second = "naturalist_method_dissection"; break;
		case 193: result.second = "naturalist_observation_anatomy"; break;
		case 194: result.second = "naturalist_theory_comparative_anatomy"; break;
		case 195: result.second = "naturalist_theory_classification_by_physical_features"; break;
		case 196: result.second = "naturalist_observation_migration_patterns"; break;
		case 197: result.second = "naturalist_observation_reproductive_behavior"; break;
		case 198: result.second = "naturalist_observation_foraging_behavior_and_diet"; break;
		case 199: result.second = "naturalist_theory_food_chain"; break;
		case 200: result.second = "naturalist_observation_social_behavior"; break;
		case 201: result.second = "naturalist_observation_diseases"; break;
		case 202: result.second = "naturalist_theory_climactic_adaptation"; break;
		case 203: result.second = "naturalist_observation_embriological_development"; break;
		case 204: result.second = "naturalist_theory_struggle_for_existence"; break;
		case 224: result.second = "chemistry_classification_combustibles"; break;
		case 225: result.second = "chemistry_classification_ores"; break;
		case 226: result.second = "chemistry_metallurgy_alloys"; break;
		case 227: result.second = "chemistry_classification_scratch_test"; break;
		case 228: result.second = "chemistry_classification_elemental_theory"; break;
		case 229: result.second = "chemistry_chemicals_adhesives"; break;
		case 230: result.second = "chemistry_laboratory_blast_furnace"; break;
		case 231: result.second = "chemistry_laboratory_alembic"; break;
		case 232: result.second = "chemistry_laboratory_theory_of_liquid_liquid_extraction"; break;
		case 233: result.second = "chemistry_laboratory_theory_of_distillation"; break;
		case 234: result.second = "chemistry_laboratory_theory_of_evaporation"; break;
		case 235: result.second = "chemistry_classification_alkali_and_acids"; break;
		case 236: result.second = "chemistry_laboratory_systematic_experiments"; break;
		case 237: result.second = "chemistry_laboratory_glass_flask"; break;
		case 238: result.second = "chemistry_laboratory_glass_beaker"; break;
		case 239: result.second = "chemistry_laboratory_glass_vial"; break;
		case 240: result.second = "chemistry_laboratory_glass_funnel"; break;
		case 241: result.second = "chemistry_laboratory_crucible"; break;
		case 242: result.second = "chemistry_chemicals_nitric_acid"; break;
		case 243: result.second = "chemistry_chemicals_sulfuric_acid"; break;
		case 244: result.second = "chemistry_chemicals_aqua_regia"; break;
		case 245: result.second = "chemistry_laboratory_glass_ampoule"; break;
		case 246: result.second = "chemistry_laboratory_glass_retort"; break;
		case 247: result.second = "chemistry_laboratory_lab_ovens"; break;
		case 256: result.second = "geography_surveying_basic"; break;
		case 257: result.second = "geography_surveying_staff"; break;
		case 258: result.second = "geography_cartography_basic"; break;
		case 259: result.second = "geography_surveying_triangulation"; break;
		case 260: result.second = "geography_surveying_cartographical"; break;
		case 261: result.second = "geography_surveying_land"; break;
		case 262: result.second = "geography_surveying_military"; break;
		case 263: result.second = "geography_surveying_engineering"; break;
		case 264: result.second = "geography_cartography_geological"; break;
		case 265: result.second = "geography_cartography_grid_system"; break;
		case 266: result.second = "geography_cartography_distance_scale"; break;
		case 267: result.second = "geography_cartography_height_measurements"; break;
		case 268: result.second = "geography_method_economic_data_collection"; break;
		case 269: result.second = "geography_cartography_economic"; break;
		case 270: result.second = "geography_form_atlas"; break;
		case 271: result.second = "geography_theory_delta_formation"; break;
		case 272: result.second = "geography_theory_wind_patterns"; break;
		case 273: result.second = "geography_theory_origin_of_rainfall_from_evap_condense"; break;
		case 274: result.second = "geography_theory_water_cycle"; break;
		case 275: result.second = "geography_theory_latitude_climate_zones"; break;
		case 276: result.second = "geography_cartography_accurate_maps"; break;
		case 277: result.second = "geography_cartography_map_projections"; break;
		case 288: result.second = "medicine_theory_disease_and_fouled_water"; break;
		case 289: result.second = "medicine_method_physical_examination"; break;
		case 290: result.second = "medicine_method_autopsy"; break;
		case 291: result.second = "medicine_theory_prognosis"; break;
		case 292: result.second = "medicine_tool_herbal_remedies"; break;
		case 293: result.second = "medicine_tool_animal_remedies"; break;
		case 294: result.second = "medicine_tool_mineral_remedies"; break;
		case 295: result.second = "medicine_tool_bandages"; break;
		case 296: result.second = "medicine_theory_disease_classification"; break;
		case 297: result.second = "medicine_theory_toxicology"; break;
		case 298: result.second = "medicine_theory_acute_and_chronic_conditions"; break;
		case 299: result.second = "medicine_theory_endemic_disease"; break;
		case 300: result.second = "medicine_theory_epidemic_disease"; break;
		case 301: result.second = "medicine_theory_exacerbation"; break;
		case 302: result.second = "medicine_theory_paroxysm"; break;
		case 303: result.second = "medicine_theory_relapse"; break;
		case 304: result.second = "medicine_theory_convalescence"; break;
		case 305: result.second = "medicine_method_treatment_of_traumatic_injuries"; break;
		case 306: result.second = "medicine_method_fracture_treatment"; break;
		case 307: result.second = "medicine_theory_fracture_classification"; break;
		case 308: result.second = "medicine_tool_traction_bench"; break;
		case 309: result.second = "medicine_method_fracture_immobilization"; break;
		case 310: result.second = "medicine_tool_orthopedic_cast"; break;
		case 311: result.second = "medicine_method_surgery_excision"; break;
		case 312: result.second = "medicine_method_surgery_incision"; break;
		case 313: result.second = "medicine_method_hernia_surgery"; break;
		case 314: result.second = "medicine_method_tracheotomy_surgery"; break;
		case 315: result.second = "medicine_method_lithotomy_surgery"; break;
		case 316: result.second = "medicine_method_surgery_scraping"; break;
		case 317: result.second = "medicine_method_surgery_draining"; break;
		case 318: result.second = "medicine_method_surgery_probing"; break;
		case 319: result.second = "medicine_method_surgery_suturing"; break;
		case 320: result.second = "medicine_method_surgery_ligature"; break;
		case 321: result.second = "medicine_theory_surgical_models"; break;
		case 322: result.second = "medicine_tool_mud_bags_as_surgical_models"; break;
		case 323: result.second = "medicine_tool_plants_as_surgical_models"; break;
		case 324: result.second = "medicine_tool_animals_as_surgical_models"; break;
		case 325: result.second = "medicine_theory_specialized_surgical_instruments"; break;
		case 326: result.second = "medicine_tool_forceps"; break;
		case 327: result.second = "medicine_tool_scalpel"; break;
		case 328: result.second = "medicine_tool_surgical_scissors"; break;
		case 329: result.second = "medicine_tool_surgical_needles"; break;
		case 330: result.second = "medicine_method_cataract_surgery"; break;
		case 331: result.second = "medicine_method_cauterization"; break;
		case 332: result.second = "medicine_method_anesthesia"; break;
		case 333: result.second = "medicine_theory_pulmonary_medicine"; break;
		case 334: result.second = "medicine_theory_anatomical_studies"; break;
		case 335: result.second = "medicine_theory_classification_of_bodily_fluids"; break;
		case 336: result.second = "medicine_theory_eye_anatomy"; break;
		case 337: result.second = "medicine_theory_motor_vs_sensory_nerves"; break;
		case 338: result.second = "medicine_theory_nervous_system_function"; break;
		case 339: result.second = "medicine_theory_reaction_time"; break;
		case 340: result.second = "medicine_theory_blood_vessels"; break;
		case 341: result.second = "medicine_theory_pulmonary_circulation"; break;
		case 342: result.second = "medicine_theory_comparative_anatomy"; break;
		case 343: result.second = "medicine_theory_the_voice"; break;
		case 344: result.second = "medicine_theory_classification_of_muscles"; break;
		case 345: result.second = "medicine_theory_classification_of_mental_illnesses"; break;
		case 346: result.second = "medicine_theory_treatment_of_mental_illnesses"; break;
		case 347: result.second = "medicine_tool_dedicated_hospitals"; break;
		case 348: result.second = "medicine_method_professional_hospital_staff"; break;
		case 349: result.second = "medicine_method_specialized_wards"; break;
		case 350: result.second = "medicine_method_hospital_lab"; break;
		case 351: result.second = "medicine_method_medical_school"; break;
		case 352: result.second = "medicine_method_asylum_for_mentally_ill"; break;
		case 384: result.second = "engineering_horology_shadow_clock"; break;
		case 385: result.second = "engineering_horology_water_clock"; break;
		case 386: result.second = "engineering_horology_conical_water_clock"; break;
		case 387: result.second = "engineering_horology_water_clock_reservoir"; break;
		case 388: result.second = "engineering_horology_astrarium"; break;
		case 389: result.second = "engineering_horology_hourglass"; break;
		case 390: result.second = "engineering_horology_mechanical_clock"; break;
		case 391: result.second = "engineering_machine_theory_of_pulley"; break;
		case 392: result.second = "engineering_machine_pulley"; break;
		case 393: result.second = "engineering_machine_theory_of_screw"; break;
		case 394: result.second = "engineering_machine_screw"; break;
		case 395: result.second = "engineering_machine_theory_of_wheel_and_axle"; break;
		case 396: result.second = "engineering_machine_windlass"; break;
		case 397: result.second = "engineering_machine_theory_of_wedge"; break;
		case 398: result.second = "engineering_machine_theory_of_lever"; break;
		case 399: result.second = "engineering_machine_lever"; break;
		case 400: result.second = "engineering_machine_straight_beam_balance"; break;
		case 401: result.second = "engineering_machine_theory_of_gears"; break;
		case 402: result.second = "engineering_machine_warded_lock"; break;
		case 403: result.second = "engineering_machine_tumbler_lock"; break;
		case 404: result.second = "engineering_machine_padlock"; break;
		case 405: result.second = "engineering_machine_camshaft"; break;
		case 406: result.second = "engineering_machine_crankshaft"; break;
		case 407: result.second = "engineering_machine_water_powered_sawmill"; break;
		case 408: result.second = "engineering_machine_chariot_odometer"; break;
		case 409: result.second = "engineering_machine_chain_drive"; break;
		case 410: result.second = "engineering_machine_mechanical_compass"; break;
		case 411: result.second = "engineering_machine_differential_gear"; break;
		case 412: result.second = "engineering_machine_combination_lock"; break;
		case 413: result.second = "engineering_machine_verge_escapement"; break;
		case 414: result.second = "engineering_machine_balance_wheel"; break;
		case 415: result.second = "engineering_fluid_theory_of_siphon"; break;
		case 416: result.second = "engineering_fluid_valves"; break;
		case 417: result.second = "engineering_fluid_force_pump"; break;
		case 418: result.second = "engineering_optics_crystal_lens"; break;
		case 419: result.second = "engineering_optics_water_filled_spheres"; break;
		case 420: result.second = "engineering_optics_glass_lens"; break;
		case 421: result.second = "engineering_optics_camera_obscura"; break;
		case 422: result.second = "engineering_optics_parabolic_mirror"; break;
		case 423: result.second = "engineering_optics_theory_of_color"; break;
		case 424: result.second = "engineering_optics_theory_of_rainbows"; break;
		case 425: result.second = "engineering_optics_law_of_refraction"; break;
		case 426: result.second = "engineering_design_models_and_templates"; break;
		case 427: result.second = "engineering_construction_wood_lamination"; break;
		case 428: result.second = "engineering_astronomy_dioptra"; break;
		case 429: result.second = "engineering_astronomy_astrolabe"; break;
		case 430: result.second = "engineering_astronomy_armillary_sphere"; break;
		case 431: result.second = "engineering_astronomy_spherical_astrolabe"; break;
		case 432: result.second = "engineering_astronomy_mural_instrument"; break;
		case 433: result.second = "engineering_astronomy_orrery"; break;
		case 434: result.second = "engineering_machine_water_powered_trip_hammer"; break;
		case 435: result.second = "engineering_machine_double_acting_piston_bellows"; break;
		case 436: result.second = "engineering_fluid_archimedes_principle"; break;
		case 437: result.second = "engineering_optics_atmospheric_refraction"; break;
		case 438: result.second = "engineering_optics_cause_of_twilight"; break;
		case 439: result.second = "engineering_optics_height_of_atmosphere"; break;
		case 440: result.second = "engineering_machine_piston"; break;
		case 441: result.second = "engineering_machine_crank"; break;
		case 442: result.second = "engineering_machine_bellows"; break;
		case 443: result.second = "engineering_machine_water_powered_piston_bellows"; break;
		case 444: result.second = "engineering_machine_water_wheel"; break;
		case 445: result.second = "engineering_machine_trip_hammer"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_part_of_speech_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Noun"; break;
		case 1: result.second = "NounPlural"; break;
		case 2: result.second = "Adjective"; break;
		case 3: result.second = "Prefix"; break;
		case 4: result.second = "Verb"; break;
		case 5: result.second = "Verb3rdPerson"; break;
		case 6: result.second = "VerbPast"; break;
		case 7: result.second = "VerbPassive"; break;
		case 8: result.second = "VerbGerund"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_sphere_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "AGRICULTURE"; break;
		case 1: result.second = "ANIMALS"; break;
		case 2: result.second = "ART"; break;
		case 3: result.second = "BALANCE"; break;
		case 4: result.second = "BEAUTY"; break;
		case 5: result.second = "BIRTH"; break;
		case 6: result.second = "BLIGHT"; break;
		case 7: result.second = "BOUNDARIES"; break;
		case 8: result.second = "CAVERNS"; break;
		case 9: result.second = "CHAOS"; break;
		case 10: result.second = "CHARITY"; break;
		case 11: result.second = "CHILDREN"; break;
		case 12: result.second = "COASTS"; break;
		case 13: result.second = "CONSOLATION"; break;
		case 14: result.second = "COURAGE"; break;
		case 15: result.second = "CRAFTS"; break;
		case 16: result.second = "CREATION"; break;
		case 17: result.second = "DANCE"; break;
		case 18: result.second = "DARKNESS"; break;
		case 19: result.second = "DAWN"; break;
		case 20: result.second = "DAY"; break;
		case 21: result.second = "DEATH"; break;
		case 22: result.second = "DEFORMITY"; break;
		case 23: result.second = "DEPRAVITY"; break;
		case 24: result.second = "DISCIPLINE"; break;
		case 25: result.second = "DISEASE"; break;
		case 26: result.second = "DREAMS"; break;
		case 27: result.second = "DUSK"; break;
		case 28: result.second = "DUTY"; break;
		case 29: result.second = "EARTH"; break;
		case 30: result.second = "FAMILY"; break;
		case 31: result.second = "FAME"; break;
		case 32: result.second = "FATE"; break;
		case 33: result.second = "FERTILITY"; break;
		case 34: result.second = "FESTIVALS"; break;
		case 35: result.second = "FIRE"; break;
		case 36: result.second = "FISH"; break;
		case 37: result.second = "FISHING"; break;
		case 38: result.second = "FOOD"; break;
		case 39: result.second = "FORGIVENESS"; break;
		case 40: result.second = "FORTRESSES"; break;
		case 41: result.second = "FREEDOM"; break;
		case 42: result.second = "GAMBLING"; break;
		case 43: result.second = "GAMES"; break;
		case 44: result.second = "GENEROSITY"; break;
		case 45: result.second = "HAPPINESS"; break;
		case 46: result.second = "HEALING"; break;
		case 47: result.second = "HOSPITALITY"; break;
		case 48: result.second = "HUNTING"; break;
		case 49: result.second = "INSPIRATION"; break;
		case 50: result.second = "JEALOUSY"; break;
		case 51: result.second = "JEWELS"; break;
		case 52: result.second = "JUSTICE"; break;
		case 53: result.second = "LABOR"; break;
		case 54: result.second = "LAKES"; break;
		case 55: result.second = "LAWS"; break;
		case 56: result.second = "LIES"; break;
		case 57: result.second = "LIGHT"; break;
		case 58: result.second = "LIGHTNING"; break;
		case 59: result.second = "LONGEVITY"; break;
		case 60: result.second = "LOVE"; break;
		case 61: result.second = "LOYALTY"; break;
		case 62: result.second = "LUCK"; break;
		case 63: result.second = "LUST"; break;
		case 64: result.second = "MARRIAGE"; break;
		case 65: result.second = "MERCY"; break;
		case 66: result.second = "METALS"; break;
		case 67: result.second = "MINERALS"; break;
		case 68: result.second = "MISERY"; break;
		case 69: result.second = "MIST"; break;
		case 70: result.second = "MOON"; break;
		case 71: result.second = "MOUNTAINS"; break;
		case 72: result.second = "MUCK"; break;
		case 73: result.second = "MURDER"; break;
		case 74: result.second = "MUSIC"; break;
		case 75: result.second = "NATURE"; break;
		case 76: result.second = "NIGHT"; break;
		case 77: result.second = "NIGHTMARES"; break;
		case 78: result.second = "OATHS"; break;
		case 79: result.second = "OCEANS"; break;
		case 80: result.second = "ORDER"; break;
		case 81: result.second = "PAINTING"; break;
		case 82: result.second = "PEACE"; break;
		case 83: result.second = "PERSUASION"; break;
		case 84: result.second = "PLANTS"; break;
		case 85: result.second = "POETRY"; break;
		case 86: result.second = "PREGNANCY"; break;
		case 87: result.second = "RAIN"; break;
		case 88: result.second = "RAINBOWS"; break;
		case 89: result.second = "REBIRTH"; break;
		case 90: result.second = "REVELRY"; break;
		case 91: result.second = "REVENGE"; break;
		case 92: result.second = "RIVERS"; break;
		case 93: result.second = "RULERSHIP"; break;
		case 94: result.second = "RUMORS"; break;
		case 95: result.second = "SACRIFICE"; break;
		case 96: result.second = "SALT"; break;
		case 97: result.second = "SCHOLARSHIP"; break;
		case 98: result.second = "SEASONS"; break;
		case 99: result.second = "SILENCE"; break;
		case 100: result.second = "SKY"; break;
		case 101: result.second = "SONG"; break;
		case 102: result.second = "SPEECH"; break;
		case 103: result.second = "STARS"; break;
		case 104: result.second = "STORMS"; break;
		case 105: result.second = "STRENGTH"; break;
		case 106: result.second = "SUICIDE"; break;
		case 107: result.second = "SUN"; break;
		case 108: result.second = "THEFT"; break;
		case 109: result.second = "THRALLDOM"; break;
		case 110: result.second = "THUNDER"; break;
		case 111: result.second = "TORTURE"; break;
		case 112: result.second = "TRADE"; break;
		case 113: result.second = "TRAVELERS"; break;
		case 114: result.second = "TREACHERY"; break;
		case 115: result.second = "TREES"; break;
		case 116: result.second = "TRICKERY"; break;
		case 117: result.second = "TRUTH"; break;
		case 118: result.second = "TWILIGHT"; break;
		case 119: result.second = "VALOR"; break;
		case 120: result.second = "VICTORY"; break;
		case 121: result.second = "VOLCANOS"; break;
		case 122: result.second = "WAR"; break;
		case 123: result.second = "WATER"; break;
		case 124: result.second = "WEALTH"; break;
		case 125: result.second = "WEATHER"; break;
		case 126: result.second = "WIND"; break;
		case 127: result.second = "WISDOM"; break;
		case 128: result.second = "WRITING"; break;
		case 129: result.second = "YOUTH"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_language_name_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Unit"; break;
		case 1: result.second = "Artifact"; break;
		case 2: result.second = "ArtifactEvil"; break;
		case 3: result.second = "Swamp"; break;
		case 4: result.second = "Desert"; break;
		case 5: result.second = "Forest"; break;
		case 6: result.second = "Mountains"; break;
		case 7: result.second = "Lake"; break;
		case 8: result.second = "Ocean"; break;
		case 9: result.second = "Glacier"; break;
		case 10: result.second = "Tundra"; break;
		case 11: result.second = "Grassland"; break;
		case 12: result.second = "Hills"; break;
		case 13: result.second = "Region"; break;
		case 14: result.second = "Cave"; break;
		case 15: result.second = "SwampEvil"; break;
		case 16: result.second = "DesertEvil"; break;
		case 17: result.second = "ForestEvil"; break;
		case 18: result.second = "MountainsEvil"; break;
		case 19: result.second = "LakeEvil"; break;
		case 20: result.second = "OceanEvil"; break;
		case 21: result.second = "GlacierEvil"; break;
		case 22: result.second = "TundraEvil"; break;
		case 23: result.second = "GrasslandEvil"; break;
		case 24: result.second = "HillsEvil"; break;
		case 25: result.second = "SwampGood"; break;
		case 26: result.second = "DesertGood"; break;
		case 27: result.second = "ForestGood"; break;
		case 28: result.second = "MountainsGood"; break;
		case 29: result.second = "LakeGood"; break;
		case 30: result.second = "OceanGood"; break;
		case 31: result.second = "GlacierGood"; break;
		case 32: result.second = "TundraGood"; break;
		case 33: result.second = "GrasslandGood"; break;
		case 34: result.second = "HillsGood"; break;
		case 35: result.second = "ArtImage"; break;
		case 36: result.second = "MountainPeak"; break;
		case 37: result.second = "Unknown1"; break;
		case 38: result.second = "Volcano"; break;
		case 39: result.second = "SmallIsland"; break;
		case 40: result.second = "Island"; break;
		case 41: result.second = "Continent"; break;
		case 42: result.second = "CommonReligion"; break;
		case 43: result.second = "Temple"; break;
		case 44: result.second = "Keep"; break;
		case 45: result.second = "Unknown2"; break;
		case 46: result.second = "SymbolArtifice"; break;
		case 47: result.second = "SymbolViolent"; break;
		case 48: result.second = "SymbolProtect"; break;
		case 49: result.second = "SymbolDomestic"; break;
		case 50: result.second = "SymbolFood"; break;
		case 51: result.second = "War"; break;
		case 52: result.second = "Battle"; break;
		case 53: result.second = "Siege"; break;
		case 54: result.second = "Road"; break;
		case 55: result.second = "Wall"; break;
		case 56: result.second = "Bridge"; break;
		case 57: result.second = "Tunnel"; break;
		case 58: result.second = "Tomb"; break;
		case 59: result.second = "SymbolProtect2"; break;
		case 60: result.second = "Library"; break;
		case 61: result.second = "Festival"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_nemesis_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ACTIVE_ADVENTURER"; break;
		case 1: result.second = "RETIRED_ADVENTURER"; break;
		case 2: result.second = "ADVENTURER"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_machine_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "standard"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_screw_pump_direction_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "FromNorth"; break;
		case 1: result.second = "FromEast"; break;
		case 2: result.second = "FromSouth"; break;
		case 3: result.second = "FromWest"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tile_traffic_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Normal"; break;
		case 1: result.second = "Low"; break;
		case 2: result.second = "High"; break;
		case 3: result.second = "Restricted"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tile_dig_designation_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "No"; break;
		case 1: result.second = "Default"; break;
		case 2: result.second = "UpDownStair"; break;
		case 3: result.second = "Channel"; break;
		case 4: result.second = "Ramp"; break;
		case 5: result.second = "DownStair"; break;
		case 6: result.second = "UpStair"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tile_liquid_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Water"; break;
		case 1: result.second = "Magma"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tile_building_occ_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "None"; break;
		case 1: result.second = "Planned"; break;
		case 2: result.second = "Passable"; break;
		case 3: result.second = "Obstacle"; break;
		case 4: result.second = "Well"; break;
		case 5: result.second = "Floored"; break;
		case 6: result.second = "Impassable"; break;
		case 7: result.second = "Dynamic"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tile_liquid_flow_dir_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "none"; break;
		case 1: result.second = "south"; break;
		case 2: result.second = "east"; break;
		case 3: result.second = "northeast"; break;
		case 4: result.second = "west"; break;
		case 5: result.second = "northwest"; break;
		case 6: result.second = "southeast"; break;
		case 7: result.second = "southwest"; break;
		case 8: result.second = "inv_8"; break;
		case 9: result.second = "inv_9"; break;
		case 10: result.second = "north"; break;
		case 11: result.second = "inv_b"; break;
		case 12: result.second = "inv_c"; break;
		case 13: result.second = "inv_d"; break;
		case 14: result.second = "inv_e"; break;
		case 15: result.second = "inv_f"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_block_square_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "mineral"; break;
		case 1: result.second = "frozen_liquid"; break;
		case 2: result.second = "world_construction"; break;
		case 3: result.second = "material_spatter"; break;
		case 4: result.second = "grass"; break;
		case 5: result.second = "spoor"; break;
		case 6: result.second = "item_spatter"; break;
		case 7: result.second = "designation_priority"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_feature_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "outdoor_river"; break;
		case 1: result.second = "cave"; break;
		case 2: result.second = "pit"; break;
		case 3: result.second = "magma_pool"; break;
		case 4: result.second = "volcano"; break;
		case 5: result.second = "deep_special_tube"; break;
		case 6: result.second = "deep_surface_portal"; break;
		case 7: result.second = "subterranean_from_layer"; break;
		case 8: result.second = "magma_core_from_layer"; break;
		case 9: result.second = "underworld_from_layer"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_feature_init_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "anon_1"; break;
		case 1: result.second = "anon_2"; break;
		case 2: result.second = "anon_3"; break;
		case 3: result.second = "Discovered"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_feature_alteration_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "new_pop_max"; break;
		case 1: result.second = "new_lava_fill_z"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_world_construction_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ROAD"; break;
		case 1: result.second = "TUNNEL"; break;
		case 2: result.second = "BRIDGE"; break;
		case 3: result.second = "WALL"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_biome_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MOUNTAIN"; break;
		case 1: result.second = "GLACIER"; break;
		case 2: result.second = "TUNDRA"; break;
		case 3: result.second = "SWAMP_TEMPERATE_FRESHWATER"; break;
		case 4: result.second = "SWAMP_TEMPERATE_SALTWATER"; break;
		case 5: result.second = "MARSH_TEMPERATE_FRESHWATER"; break;
		case 6: result.second = "MARSH_TEMPERATE_SALTWATER"; break;
		case 7: result.second = "SWAMP_TROPICAL_FRESHWATER"; break;
		case 8: result.second = "SWAMP_TROPICAL_SALTWATER"; break;
		case 9: result.second = "SWAMP_MANGROVE"; break;
		case 10: result.second = "MARSH_TROPICAL_FRESHWATER"; break;
		case 11: result.second = "MARSH_TROPICAL_SALTWATER"; break;
		case 12: result.second = "FOREST_TAIGA"; break;
		case 13: result.second = "FOREST_TEMPERATE_CONIFER"; break;
		case 14: result.second = "FOREST_TEMPERATE_BROADLEAF"; break;
		case 15: result.second = "FOREST_TROPICAL_CONIFER"; break;
		case 16: result.second = "FOREST_TROPICAL_DRY_BROADLEAF"; break;
		case 17: result.second = "FOREST_TROPICAL_MOIST_BROADLEAF"; break;
		case 18: result.second = "GRASSLAND_TEMPERATE"; break;
		case 19: result.second = "SAVANNA_TEMPERATE"; break;
		case 20: result.second = "SHRUBLAND_TEMPERATE"; break;
		case 21: result.second = "GRASSLAND_TROPICAL"; break;
		case 22: result.second = "SAVANNA_TROPICAL"; break;
		case 23: result.second = "SHRUBLAND_TROPICAL"; break;
		case 24: result.second = "DESERT_BADLAND"; break;
		case 25: result.second = "DESERT_ROCK"; break;
		case 26: result.second = "DESERT_SAND"; break;
		case 27: result.second = "OCEAN_TROPICAL"; break;
		case 28: result.second = "OCEAN_TEMPERATE"; break;
		case 29: result.second = "OCEAN_ARCTIC"; break;
		case 30: result.second = "POOL_TEMPERATE_FRESHWATER"; break;
		case 31: result.second = "POOL_TEMPERATE_BRACKISHWATER"; break;
		case 32: result.second = "POOL_TEMPERATE_SALTWATER"; break;
		case 33: result.second = "POOL_TROPICAL_FRESHWATER"; break;
		case 34: result.second = "POOL_TROPICAL_BRACKISHWATER"; break;
		case 35: result.second = "POOL_TROPICAL_SALTWATER"; break;
		case 36: result.second = "LAKE_TEMPERATE_FRESHWATER"; break;
		case 37: result.second = "LAKE_TEMPERATE_BRACKISHWATER"; break;
		case 38: result.second = "LAKE_TEMPERATE_SALTWATER"; break;
		case 39: result.second = "LAKE_TROPICAL_FRESHWATER"; break;
		case 40: result.second = "LAKE_TROPICAL_BRACKISHWATER"; break;
		case 41: result.second = "LAKE_TROPICAL_SALTWATER"; break;
		case 42: result.second = "RIVER_TEMPERATE_FRESHWATER"; break;
		case 43: result.second = "RIVER_TEMPERATE_BRACKISHWATER"; break;
		case 44: result.second = "RIVER_TEMPERATE_SALTWATER"; break;
		case 45: result.second = "RIVER_TROPICAL_FRESHWATER"; break;
		case 46: result.second = "RIVER_TROPICAL_BRACKISHWATER"; break;
		case 47: result.second = "RIVER_TROPICAL_SALTWATER"; break;
		case 48: result.second = "SUBTERRANEAN_WATER"; break;
		case 49: result.second = "SUBTERRANEAN_CHASM"; break;
		case 50: result.second = "SUBTERRANEAN_LAVA"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_flow_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Miasma"; break;
		case 1: result.second = "Steam"; break;
		case 2: result.second = "Mist"; break;
		case 3: result.second = "MaterialDust"; break;
		case 4: result.second = "MagmaMist"; break;
		case 5: result.second = "Smoke"; break;
		case 6: result.second = "Dragonfire"; break;
		case 7: result.second = "Fire"; break;
		case 8: result.second = "Web"; break;
		case 9: result.second = "MaterialGas"; break;
		case 10: result.second = "MaterialVapor"; break;
		case 11: result.second = "OceanWave"; break;
		case 12: result.second = "SeaFoam"; break;
		case 13: result.second = "ItemCloud"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_flow_guide_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TrailingFlow"; break;
		case 1: result.second = "ItemCloud"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_region_block_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SphereField"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_craft_material_class_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Metal"; break;
		case 1: result.second = "Wood"; break;
		case 2: result.second = "Gem"; break;
		case 3: result.second = "Glass"; break;
		case 4: result.second = "Stone"; break;
		case 5: result.second = "Bone"; break;
		case 6: result.second = "Ivory"; break;
		case 7: result.second = "Horn"; break;
		case 8: result.second = "Pearl"; break;
		case 9: result.second = "Shell"; break;
		case 10: result.second = "Leather"; break;
		case 11: result.second = "Cloth"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_builtin_mats_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "INORGANIC"; break;
		case 1: result.second = "AMBER"; break;
		case 2: result.second = "CORAL"; break;
		case 3: result.second = "GLASS_GREEN"; break;
		case 4: result.second = "GLASS_CLEAR"; break;
		case 5: result.second = "GLASS_CRYSTAL"; break;
		case 6: result.second = "WATER"; break;
		case 7: result.second = "COAL"; break;
		case 8: result.second = "POTASH"; break;
		case 9: result.second = "ASH"; break;
		case 10: result.second = "PEARLASH"; break;
		case 11: result.second = "LYE"; break;
		case 12: result.second = "MUD"; break;
		case 13: result.second = "VOMIT"; break;
		case 14: result.second = "SALT"; break;
		case 15: result.second = "FILTH_B"; break;
		case 16: result.second = "FILTH_Y"; break;
		case 17: result.second = "UNKNOWN_SUBSTANCE"; break;
		case 18: result.second = "GRIME"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_material_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "BONE"; break;
		case 1: result.second = "MEAT"; break;
		case 2: result.second = "EDIBLE_VERMIN"; break;
		case 3: result.second = "EDIBLE_RAW"; break;
		case 4: result.second = "EDIBLE_COOKED"; break;
		case 5: result.second = "ALCOHOL"; break;
		case 6: result.second = "ITEMS_METAL"; break;
		case 7: result.second = "ITEMS_BARRED"; break;
		case 8: result.second = "ITEMS_SCALED"; break;
		case 9: result.second = "ITEMS_LEATHER"; break;
		case 10: result.second = "ITEMS_SOFT"; break;
		case 11: result.second = "ITEMS_HARD"; break;
		case 12: result.second = "IMPLIES_ANIMAL_KILL"; break;
		case 13: result.second = "ALCOHOL_PLANT"; break;
		case 14: result.second = "ALCOHOL_CREATURE"; break;
		case 15: result.second = "CHEESE_PLANT"; break;
		case 16: result.second = "CHEESE_CREATURE"; break;
		case 17: result.second = "POWDER_MISC_PLANT"; break;
		case 18: result.second = "POWDER_MISC_CREATURE"; break;
		case 19: result.second = "STOCKPILE_GLOB"; break;
		case 20: result.second = "LIQUID_MISC_PLANT"; break;
		case 21: result.second = "LIQUID_MISC_CREATURE"; break;
		case 22: result.second = "LIQUID_MISC_OTHER"; break;
		case 23: result.second = "WOOD"; break;
		case 24: result.second = "THREAD_PLANT"; break;
		case 25: result.second = "TOOTH"; break;
		case 26: result.second = "HORN"; break;
		case 27: result.second = "PEARL"; break;
		case 28: result.second = "SHELL"; break;
		case 29: result.second = "LEATHER"; break;
		case 30: result.second = "SILK"; break;
		case 31: result.second = "SOAP"; break;
		case 32: result.second = "ROTS"; break;
		case 33: result.second = "IS_DYE"; break;
		case 34: result.second = "POWDER_MISC"; break;
		case 35: result.second = "LIQUID_MISC"; break;
		case 36: result.second = "STRUCTURAL_PLANT_MAT"; break;
		case 37: result.second = "SEED_MAT"; break;
		case 38: result.second = "LEAF_MAT"; break;
		case 39: result.second = "CHEESE"; break;
		case 40: result.second = "ENTERS_BLOOD"; break;
		case 41: result.second = "BLOOD_MAP_DESCRIPTOR"; break;
		case 42: result.second = "ICHOR_MAP_DESCRIPTOR"; break;
		case 43: result.second = "GOO_MAP_DESCRIPTOR"; break;
		case 44: result.second = "SLIME_MAP_DESCRIPTOR"; break;
		case 45: result.second = "PUS_MAP_DESCRIPTOR"; break;
		case 46: result.second = "GENERATES_MIASMA"; break;
		case 47: result.second = "IS_METAL"; break;
		case 48: result.second = "IS_GEM"; break;
		case 49: result.second = "IS_GLASS"; break;
		case 50: result.second = "CRYSTAL_GLASSABLE"; break;
		case 51: result.second = "ITEMS_WEAPON"; break;
		case 52: result.second = "ITEMS_WEAPON_RANGED"; break;
		case 53: result.second = "ITEMS_ANVIL"; break;
		case 54: result.second = "ITEMS_AMMO"; break;
		case 55: result.second = "ITEMS_DIGGER"; break;
		case 56: result.second = "ITEMS_ARMOR"; break;
		case 57: result.second = "ITEMS_DELICATE"; break;
		case 58: result.second = "ITEMS_SIEGE_ENGINE"; break;
		case 59: result.second = "ITEMS_QUERN"; break;
		case 60: result.second = "IS_STONE"; break;
		case 61: result.second = "UNDIGGABLE"; break;
		case 62: result.second = "YARN"; break;
		case 63: result.second = "STOCKPILE_GLOB_PASTE"; break;
		case 64: result.second = "STOCKPILE_GLOB_PRESSED"; break;
		case 65: result.second = "DISPLAY_UNGLAZED"; break;
		case 66: result.second = "DO_NOT_CLEAN_GLOB"; break;
		case 67: result.second = "NO_STONE_STOCKPILE"; break;
		case 68: result.second = "STOCKPILE_THREAD_METAL"; break;
		case 69: result.second = "SWEAT_MAP_DESCRIPTOR"; break;
		case 70: result.second = "TEARS_MAP_DESCRIPTOR"; break;
		case 71: result.second = "SPIT_MAP_DESCRIPTOR"; break;
		case 72: result.second = "EVAPORATES"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_matter_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Solid"; break;
		case 1: result.second = "Liquid"; break;
		case 2: result.second = "Gas"; break;
		case 3: result.second = "Powder"; break;
		case 4: result.second = "Paste"; break;
		case 5: result.second = "Pressed"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_strain_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "BENDING"; break;
		case 1: result.second = "SHEAR"; break;
		case 2: result.second = "TORSION"; break;
		case 3: result.second = "IMPACT"; break;
		case 4: result.second = "TENSILE"; break;
		case 5: result.second = "COMPRESSIVE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_inorganic_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "LAVA"; break;
		case 1: result.second = "GENERATED"; break;
		case 2: result.second = "ENVIRONMENT_NON_SOIL_OCEAN"; break;
		case 3: result.second = "SEDIMENTARY"; break;
		case 4: result.second = "SEDIMENTARY_OCEAN_SHALLOW"; break;
		case 5: result.second = "IGNEOUS_INTRUSIVE"; break;
		case 6: result.second = "IGNEOUS_EXTRUSIVE"; break;
		case 7: result.second = "METAMORPHIC"; break;
		case 8: result.second = "DEEP_SURFACE"; break;
		case 9: result.second = "METAL_ORE"; break;
		case 10: result.second = "AQUIFER"; break;
		case 11: result.second = "SOIL_ANY"; break;
		case 12: result.second = "SOIL_OCEAN"; break;
		case 13: result.second = "SOIL_SAND"; break;
		case 14: result.second = "SEDIMENTARY_OCEAN_DEEP"; break;
		case 15: result.second = "THREAD_METAL"; break;
		case 16: result.second = "SPECIAL"; break;
		case 17: result.second = "SOIL"; break;
		case 18: result.second = "DEEP_SPECIAL"; break;
		case 19: result.second = "DIVINE"; break;
		case 20: result.second = "anon_1"; break;
		case 21: result.second = "anon_2"; break;
		case 22: result.second = "anon_3"; break;
		case 23: result.second = "anon_4"; break;
		case 24: result.second = "anon_5"; break;
		case 25: result.second = "WAFERS"; break;
		case 26: result.second = "anon_6"; break;
		case 27: result.second = "anon_7"; break;
		case 28: result.second = "anon_8"; break;
		case 29: result.second = "anon_9"; break;
		case 30: result.second = "anon_10"; break;
		case 31: result.second = "anon_11"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_environment_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SOIL"; break;
		case 1: result.second = "SOIL_OCEAN"; break;
		case 2: result.second = "SOIL_SAND"; break;
		case 3: result.second = "METAMORPHIC"; break;
		case 4: result.second = "SEDIMENTARY"; break;
		case 5: result.second = "IGNEOUS_INTRUSIVE"; break;
		case 6: result.second = "IGNEOUS_EXTRUSIVE"; break;
		case 7: result.second = "ALLUVIAL"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_inclusion_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "anon_1"; break;
		case 1: result.second = "VEIN"; break;
		case 2: result.second = "CLUSTER"; break;
		case 3: result.second = "CLUSTER_SMALL"; break;
		case 4: result.second = "CLUSTER_ONE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_organic_mat_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Meat"; break;
		case 1: result.second = "Fish"; break;
		case 2: result.second = "UnpreparedFish"; break;
		case 3: result.second = "Eggs"; break;
		case 4: result.second = "Plants"; break;
		case 5: result.second = "PlantDrink"; break;
		case 6: result.second = "CreatureDrink"; break;
		case 7: result.second = "PlantCheese"; break;
		case 8: result.second = "CreatureCheese"; break;
		case 9: result.second = "Seed"; break;
		case 10: result.second = "Leaf"; break;
		case 11: result.second = "PlantPowder"; break;
		case 12: result.second = "CreaturePowder"; break;
		case 13: result.second = "Glob"; break;
		case 14: result.second = "PlantLiquid"; break;
		case 15: result.second = "CreatureLiquid"; break;
		case 16: result.second = "MiscLiquid"; break;
		case 17: result.second = "Leather"; break;
		case 18: result.second = "Silk"; break;
		case 19: result.second = "PlantFiber"; break;
		case 20: result.second = "Bone"; break;
		case 21: result.second = "Shell"; break;
		case 22: result.second = "Wood"; break;
		case 23: result.second = "Horn"; break;
		case 24: result.second = "Pearl"; break;
		case 25: result.second = "Tooth"; break;
		case 26: result.second = "EdibleCheese"; break;
		case 27: result.second = "AnyDrink"; break;
		case 28: result.second = "EdiblePlant"; break;
		case 29: result.second = "CookableLiquid"; break;
		case 30: result.second = "CookablePowder"; break;
		case 31: result.second = "CookableSeed"; break;
		case 32: result.second = "CookableLeaf"; break;
		case 33: result.second = "Paste"; break;
		case 34: result.second = "Pressed"; break;
		case 35: result.second = "Yarn"; break;
		case 36: result.second = "MetalThread"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_meeting_topic_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DiscussCurrent"; break;
		case 1: result.second = "RequestPeace"; break;
		case 2: result.second = "TreeQuota"; break;
		case 3: result.second = "BecomeLandHolder"; break;
		case 4: result.second = "PromoteLandHolder"; break;
		case 5: result.second = "ExportAgreement"; break;
		case 6: result.second = "ImportAgreement"; break;
		case 7: result.second = "PleasantPlace"; break;
		case 8: result.second = "WorldStatus"; break;
		case 9: result.second = "TributeAgreement"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_meeting_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "AcceptAgreement"; break;
		case 1: result.second = "RejectAgreement"; break;
		case 2: result.second = "AcceptPeace"; break;
		case 3: result.second = "RejectPeace"; break;
		case 4: result.second = "ExportAgreement"; break;
		case 5: result.second = "ImportAgreement"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_activity_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TrainingSession"; break;
		case 1: result.second = "CombatTraining"; break;
		case 2: result.second = "SkillDemonstration"; break;
		case 3: result.second = "IndividualSkillDrill"; break;
		case 4: result.second = "Sparring"; break;
		case 5: result.second = "RangedPractice"; break;
		case 6: result.second = "Harassment"; break;
		case 7: result.second = "Conversation"; break;
		case 8: result.second = "Conflict"; break;
		case 9: result.second = "Guard"; break;
		case 10: result.second = "Reunion"; break;
		case 11: result.second = "Prayer"; break;
		case 12: result.second = "Socialize"; break;
		case 13: result.second = "Worship"; break;
		case 14: result.second = "Performance"; break;
		case 15: result.second = "Research"; break;
		case 16: result.second = "PonderTopic"; break;
		case 17: result.second = "DiscussTopic"; break;
		case 18: result.second = "Read"; break;
		case 19: result.second = "FillServiceOrder"; break;
		case 20: result.second = "Write"; break;
		case 21: result.second = "CopyWrittenContent"; break;
		case 22: result.second = "TeachTopic"; break;
		case 23: result.second = "Play"; break;
		case 24: result.second = "MakeBelieve"; break;
		case 25: result.second = "PlayWithToy"; break;
		case 26: result.second = "Encounter"; break;
		case 27: result.second = "StoreObject"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_conversation_menu_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "RespondGreeting"; break;
		case 1: result.second = "MainMenu"; break;
		case 2: result.second = "anon_1"; break;
		case 3: result.second = "anon_2"; break;
		case 4: result.second = "anon_3"; break;
		case 5: result.second = "anon_4"; break;
		case 6: result.second = "anon_5"; break;
		case 7: result.second = "RespondGoodbye"; break;
		case 8: result.second = "anon_6"; break;
		case 9: result.second = "DenyPermissionSleep"; break;
		case 10: result.second = "AskJoin"; break;
		case 11: result.second = "RespondJoin"; break;
		case 12: result.second = "DiscussRescue"; break;
		case 13: result.second = "DiscussAgreement"; break;
		case 14: result.second = "DiscussTrade"; break;
		case 15: result.second = "DiscussSurroundingArea"; break;
		case 16: result.second = "RespondAccusation"; break;
		case 17: result.second = "DiscussFamily"; break;
		case 18: result.second = "RespondArmistice"; break;
		case 19: result.second = "RespondDemandYield"; break;
		case 20: result.second = "anon_7"; break;
		case 21: result.second = "anon_8"; break;
		case 22: result.second = "anon_9"; break;
		case 23: result.second = "AskDirections"; break;
		case 24: result.second = "anon_10"; break;
		case 25: result.second = "anon_11"; break;
		case 26: result.second = "anon_12"; break;
		case 27: result.second = "anon_13"; break;
		case 28: result.second = "anon_14"; break;
		case 29: result.second = "anon_15"; break;
		case 30: result.second = "Demand"; break;
		case 31: result.second = "anon_16"; break;
		case 32: result.second = "anon_17"; break;
		case 33: result.second = "anon_18"; break;
		case 34: result.second = "Barter"; break;
		case 35: result.second = "DiscussHearthpersonDuties"; break;
		case 36: result.second = "anon_19"; break;
		case 37: result.second = "DiscussJourney"; break;
		case 38: result.second = "DiscussGroup"; break;
		case 39: result.second = "DiscussConflict"; break;
		case 40: result.second = "DiscussSite"; break;
		case 41: result.second = "RespondDemand"; break;
		case 42: result.second = "anon_20"; break;
		case 43: result.second = "RespondTributeDemand"; break;
		case 44: result.second = "RespondTributeOffer"; break;
		case 45: result.second = "DiscussTradeCancellation"; break;
		case 46: result.second = "RespondPeaceOffer"; break;
		case 47: result.second = "DiscussAgreementConclusion"; break;
		case 48: result.second = "RespondAdoptionRequest"; break;
		case 49: result.second = "anon_21"; break;
		case 50: result.second = "anon_22"; break;
		case 51: result.second = "RespondPositionOffer"; break;
		case 52: result.second = "RespondInvocation"; break;
		case 53: result.second = "anon_23"; break;
		case 54: result.second = "AskAboutPerson"; break;
		case 55: result.second = "anon_24"; break;
		case 56: result.second = "DiscussFeelings"; break;
		case 57: result.second = "anon_25"; break;
		case 58: result.second = "anon_26"; break;
		case 59: result.second = "anon_27"; break;
		case 60: result.second = "anon_28"; break;
		case 61: result.second = "anon_29"; break;
		case 62: result.second = "anon_30"; break;
		case 63: result.second = "anon_31"; break;
		case 64: result.second = "anon_32"; break;
		case 65: result.second = "StateGeneralThoughts"; break;
		case 66: result.second = "DiscussValues"; break;
		case 67: result.second = "RespondValues"; break;
		case 68: result.second = "RespondPassiveReply"; break;
		case 69: result.second = "RespondFlattery"; break;
		case 70: result.second = "RespondDismissal"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_performance_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "STORY"; break;
		case 1: result.second = "POETRY"; break;
		case 2: result.second = "MUSIC"; break;
		case 3: result.second = "DANCE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_performance_participant_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TELL_STORY"; break;
		case 1: result.second = "RECITE_POETRY"; break;
		case 2: result.second = "MAKE_MUSIC"; break;
		case 3: result.second = "PERFORM_DANCE"; break;
		case 4: result.second = "LISTEN"; break;
		case 5: result.second = "HEAR"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_uniform_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "body"; break;
		case 1: result.second = "head"; break;
		case 2: result.second = "pants"; break;
		case 3: result.second = "gloves"; break;
		case 4: result.second = "shoes"; break;
		case 5: result.second = "shield"; break;
		case 6: result.second = "weapon"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_barrack_preference_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Bed"; break;
		case 1: result.second = "Armorstand"; break;
		case 2: result.second = "Box"; break;
		case 3: result.second = "Cabinet"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_squad_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Unk0"; break;
		case 1: result.second = "Unk1"; break;
		case 2: result.second = "Unk2"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_squad_order_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MOVE"; break;
		case 1: result.second = "KILL_LIST"; break;
		case 2: result.second = "DEFEND_BURROWS"; break;
		case 3: result.second = "PATROL_ROUTE"; break;
		case 4: result.second = "TRAIN"; break;
		case 5: result.second = "DRIVE_ENTITY_OFF_SITE"; break;
		case 6: result.second = "CAUSE_TROUBLE_FOR_ENTITY"; break;
		case 7: result.second = "KILL_HF"; break;
		case 8: result.second = "DRIVE_ARMIES_FROM_SITE"; break;
		case 9: result.second = "RETRIEVE_ARTIFACT"; break;
		case 10: result.second = "RAID_SITE"; break;
		case 11: result.second = "RESCUE_HF"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_squad_order_cannot_reason_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "not_following_order"; break;
		case 1: result.second = "activity_cancelled"; break;
		case 2: result.second = "no_barracks"; break;
		case 3: result.second = "improper_barracks"; break;
		case 4: result.second = "no_activity"; break;
		case 5: result.second = "cannot_individually_drill"; break;
		case 6: result.second = "does_not_exist"; break;
		case 7: result.second = "no_archery_target"; break;
		case 8: result.second = "improper_building"; break;
		case 9: result.second = "unreachable_location"; break;
		case 10: result.second = "invalid_location"; break;
		case 11: result.second = "no_reachable_valid_target"; break;
		case 12: result.second = "no_burrow"; break;
		case 13: result.second = "not_in_squad"; break;
		case 14: result.second = "no_patrol_route"; break;
		case 15: result.second = "no_reachable_point_on_route"; break;
		case 16: result.second = "invalid_order"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_army_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "player"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_path_goal_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "ComeToJobBuilding"; break;
		case 1: result.second = "ValidPondDumpUnit"; break;
		case 2: result.second = "ValidPondDump"; break;
		case 3: result.second = "ConflictDefense"; break;
		case 4: result.second = "AdventureMove"; break;
		case 5: result.second = "MarauderMill"; break;
		case 6: result.second = "WildernessCuriousStealTarget"; break;
		case 7: result.second = "WildernessRoamer"; break;
		case 8: result.second = "ThiefTarget"; break;
		case 9: result.second = "Owner"; break;
		case 10: result.second = "CheckChest"; break;
		case 11: result.second = "SleepBed"; break;
		case 12: result.second = "SleepBarracks"; break;
		case 13: result.second = "SleepGround"; break;
		case 14: result.second = "LeaveWall"; break;
		case 15: result.second = "FleeTerrain"; break;
		case 16: result.second = "TaxRoom"; break;
		case 17: result.second = "GuardTaxes"; break;
		case 18: result.second = "RansackTaxes"; break;
		case 19: result.second = "GetEmptySandBag"; break;
		case 20: result.second = "SandZone"; break;
		case 21: result.second = "GrabCage"; break;
		case 22: result.second = "UncageAnimal"; break;
		case 23: result.second = "CaptureSmallPet"; break;
		case 24: result.second = "GrabCageUnit"; break;
		case 25: result.second = "GoToCage"; break;
		case 26: result.second = "GrabAnimalTrap"; break;
		case 27: result.second = "CageVermin"; break;
		case 28: result.second = "GrabUnfillBucket"; break;
		case 29: result.second = "SeekFillBucket"; break;
		case 30: result.second = "SeekPatientForCarry"; break;
		case 31: result.second = "SeekPatientForDiagnosis"; break;
		case 32: result.second = "SeekPatientForImmobilizeBreak"; break;
		case 33: result.second = "SeekPatientForCrutch"; break;
		case 34: result.second = "SeekPatientForSuturing"; break;
		case 35: result.second = "SeekSurgerySite"; break;
		case 36: result.second = "CarryPatientToBed"; break;
		case 37: result.second = "SeekGiveWaterBucket"; break;
		case 38: result.second = "SeekJobItem"; break;
		case 39: result.second = "SeekUnitForItemDrop"; break;
		case 40: result.second = "SeekUnitForJob"; break;
		case 41: result.second = "SeekSplint"; break;
		case 42: result.second = "SeekCrutch"; break;
		case 43: result.second = "SeekSutureThread"; break;
		case 44: result.second = "SeekDressingCloth"; break;
		case 45: result.second = "GoToGiveWaterTarget"; break;
		case 46: result.second = "SeekFoodForTarget"; break;
		case 47: result.second = "SeekTargetForFood"; break;
		case 48: result.second = "SeekAnimalForSlaughter"; break;
		case 49: result.second = "SeekSlaughterBuilding"; break;
		case 50: result.second = "SeekAnimalForChain"; break;
		case 51: result.second = "SeekChainForAnimal"; break;
		case 52: result.second = "SeekCageForUnchain"; break;
		case 53: result.second = "SeekAnimalForUnchain"; break;
		case 54: result.second = "GrabFoodForTaming"; break;
		case 55: result.second = "SeekAnimalForTaming"; break;
		case 56: result.second = "SeekDrinkItem"; break;
		case 57: result.second = "SeekFoodItem"; break;
		case 58: result.second = "SeekEatingChair"; break;
		case 59: result.second = "SeekEatingChair2"; break;
		case 60: result.second = "SeekBadMoodBuilding"; break;
		case 61: result.second = "SetGlassMoodBuilding"; break;
		case 62: result.second = "SetMoodBuilding"; break;
		case 63: result.second = "SeekFellVictim"; break;
		case 64: result.second = "CleanBuildingSite"; break;
		case 65: result.second = "ResetPriorityGoal"; break;
		case 66: result.second = "MainJobBuilding"; break;
		case 67: result.second = "DropOffJobItems"; break;
		case 68: result.second = "GrabJobResources"; break;
		case 69: result.second = "WorkAtBuilding"; break;
		case 70: result.second = "GrabUniform"; break;
		case 71: result.second = "GrabClothing"; break;
		case 72: result.second = "GrabWeapon"; break;
		case 73: result.second = "GrabAmmunition"; break;
		case 74: result.second = "GrabShield"; break;
		case 75: result.second = "GrabArmor"; break;
		case 76: result.second = "GrabHelm"; break;
		case 77: result.second = "GrabBoots"; break;
		case 78: result.second = "GrabGloves"; break;
		case 79: result.second = "GrabPants"; break;
		case 80: result.second = "GrabQuiver"; break;
		case 81: result.second = "GrabBackpack"; break;
		case 82: result.second = "GrabWaterskin"; break;
		case 83: result.second = "StartHunt"; break;
		case 84: result.second = "StartFish"; break;
		case 85: result.second = "Clean"; break;
		case 86: result.second = "HuntVermin"; break;
		case 87: result.second = "Patrol"; break;
		case 88: result.second = "SquadStation"; break;
		case 89: result.second = "SeekInfant"; break;
		case 90: result.second = "ShopSpecific"; break;
		case 91: result.second = "MillInShop"; break;
		case 92: result.second = "GoToShop"; break;
		case 93: result.second = "SeekTrainingAmmunition"; break;
		case 94: result.second = "ArcheryTrainingSite"; break;
		case 95: result.second = "SparringPartner"; break;
		case 96: result.second = "SparringSite"; break;
		case 97: result.second = "AttendParty"; break;
		case 98: result.second = "SeekArtifact"; break;
		case 99: result.second = "GrabAmmunitionForBuilding"; break;
		case 100: result.second = "SeekBuildingForAmmunition"; break;
		case 101: result.second = "SeekItemForStorage"; break;
		case 102: result.second = "StoreItem"; break;
		case 103: result.second = "GrabKill"; break;
		case 104: result.second = "DropKillAtButcher"; break;
		case 105: result.second = "DropKillOutFront"; break;
		case 106: result.second = "GoToBeatingTarget"; break;
		case 107: result.second = "SeekKidnapVictim"; break;
		case 108: result.second = "SeekHuntingTarget"; break;
		case 109: result.second = "SeekTargetMechanism"; break;
		case 110: result.second = "SeekTargetForMechanism"; break;
		case 111: result.second = "SeekMechanismForTrigger"; break;
		case 112: result.second = "SeekTriggerForMechanism"; break;
		case 113: result.second = "SeekTrapForVerminCatch"; break;
		case 114: result.second = "SeekVerminForCatching"; break;
		case 115: result.second = "SeekVerminCatchLocation"; break;
		case 116: result.second = "WanderVerminCatchLocation"; break;
		case 117: result.second = "SeekVerminForHunting"; break;
		case 118: result.second = "SeekVerminHuntingSpot"; break;
		case 119: result.second = "WanderVerminHuntingSpot"; break;
		case 120: result.second = "SeekFishTrap"; break;
		case 121: result.second = "SeekFishCatchLocation"; break;
		case 122: result.second = "SeekWellForWater"; break;
		case 123: result.second = "SeekDrinkAreaForWater"; break;
		case 124: result.second = "UpgradeSquadEquipment"; break;
		case 125: result.second = "PrepareEquipmentManifests"; break;
		case 126: result.second = "WanderDepot"; break;
		case 127: result.second = "SeekUpdateOffice"; break;
		case 128: result.second = "SeekManageOffice"; break;
		case 129: result.second = "AssignedBuildingJob"; break;
		case 130: result.second = "ChaseOpponent"; break;
		case 131: result.second = "FleeFromOpponent"; break;
		case 132: result.second = "AttackBuilding"; break;
		case 133: result.second = "StartBedCarry"; break;
		case 134: result.second = "StartGiveFoodWater"; break;
		case 135: result.second = "StartMedicalAid"; break;
		case 136: result.second = "SeekStationFlood"; break;
		case 137: result.second = "SeekStation"; break;
		case 138: result.second = "StartWaterJobWell"; break;
		case 139: result.second = "StartWaterJobDrinkArea"; break;
		case 140: result.second = "StartEatJob"; break;
		case 141: result.second = "ScheduledMeal"; break;
		case 142: result.second = "ScheduledSleepBed"; break;
		case 143: result.second = "ScheduledSleepGround"; break;
		case 144: result.second = "Rest"; break;
		case 145: result.second = "RemoveConstruction"; break;
		case 146: result.second = "Chop"; break;
		case 147: result.second = "Detail"; break;
		case 148: result.second = "GatherPlant"; break;
		case 149: result.second = "Dig"; break;
		case 150: result.second = "Mischief"; break;
		case 151: result.second = "ChaseOpponentSameSquare"; break;
		case 152: result.second = "RestRecovered"; break;
		case 153: result.second = "RestReset"; break;
		case 154: result.second = "CombatTraining"; break;
		case 155: result.second = "SkillDemonstration"; break;
		case 156: result.second = "IndividualSkillDrill"; break;
		case 157: result.second = "SeekBuildingForItemDrop"; break;
		case 158: result.second = "SeekBuildingForJob"; break;
		case 159: result.second = "GrabMilkUnit"; break;
		case 160: result.second = "GoToMilkStation"; break;
		case 161: result.second = "SeekPatientForDressWound"; break;
		case 162: result.second = "UndeadHunt"; break;
		case 163: result.second = "GrabShearUnit"; break;
		case 164: result.second = "GoToShearStation"; break;
		case 165: result.second = "LayEggNestBox"; break;
		case 166: result.second = "ClayZone"; break;
		case 167: result.second = "ColonyToInstall"; break;
		case 168: result.second = "ReturnColonyToInstall"; break;
		case 169: result.second = "Nonsense"; break;
		case 170: result.second = "SeekBloodSuckVictim"; break;
		case 171: result.second = "SeekSheriff"; break;
		case 172: result.second = "GrabExecutionWeapon"; break;
		case 173: result.second = "TrainAnimal"; break;
		case 174: result.second = "GuardPath"; break;
		case 175: result.second = "Harass"; break;
		case 176: result.second = "SiteWalk"; break;
		case 177: result.second = "SiteWalkToBuilding"; break;
		case 178: result.second = "Reunion"; break;
		case 179: result.second = "ArmyWalk"; break;
		case 180: result.second = "ChaseOpponentFlood"; break;
		case 181: result.second = "ChargeAttack"; break;
		case 182: result.second = "FleeFromOpponentClimb"; break;
		case 183: result.second = "SeekLadderToClimb"; break;
		case 184: result.second = "SeekLadderToMove"; break;
		case 185: result.second = "PlaceLadder"; break;
		case 186: result.second = "SeekAnimalForGelding"; break;
		case 187: result.second = "SeekGeldingBuilding"; break;
		case 188: result.second = "Prayer"; break;
		case 189: result.second = "Socialize"; break;
		case 190: result.second = "Performance"; break;
		case 191: result.second = "Research"; break;
		case 192: result.second = "PonderTopic"; break;
		case 193: result.second = "FillServiceOrder"; break;
		case 194: result.second = "GetWrittenContent"; break;
		case 195: result.second = "GoToReadingPlace"; break;
		case 196: result.second = "GetWritingMaterials"; break;
		case 197: result.second = "GoToWritingPlace"; break;
		case 198: result.second = "Worship"; break;
		case 199: result.second = "GrabInstrument"; break;
		case 200: result.second = "Play"; break;
		case 201: result.second = "MakeBelieve"; break;
		case 202: result.second = "PlayWithToy"; break;
		case 203: result.second = "GrabToy"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_station_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Nonsense"; break;
		case 1: result.second = "DungeonCommander"; break;
		case 2: result.second = "InsaneMood"; break;
		case 3: result.second = "UndeadHunt"; break;
		case 4: result.second = "SiegerPatrol"; break;
		case 5: result.second = "MaraudeTarget"; break;
		case 6: result.second = "SiegerBasepoint"; break;
		case 7: result.second = "SiegerMill"; break;
		case 8: result.second = "AmbushPatrol"; break;
		case 9: result.second = "MarauderMill"; break;
		case 10: result.second = "WildernessCuriousWander"; break;
		case 11: result.second = "WildernessCuriousStealTarget"; break;
		case 12: result.second = "WildernessRoamer"; break;
		case 13: result.second = "PatternPatrol"; break;
		case 14: result.second = "InactiveMarauder"; break;
		case 15: result.second = "Owner"; break;
		case 16: result.second = "Commander"; break;
		case 17: result.second = "ChainedAnimal"; break;
		case 18: result.second = "MeetingLocation"; break;
		case 19: result.second = "MeetingLocationBuilding"; break;
		case 20: result.second = "Depot"; break;
		case 21: result.second = "VerminHunting"; break;
		case 22: result.second = "SeekCommander"; break;
		case 23: result.second = "ReturnToBase"; break;
		case 24: result.second = "MillAnywhere"; break;
		case 25: result.second = "Wagon"; break;
		case 26: result.second = "MillBuilding"; break;
		case 27: result.second = "HeadForEdge"; break;
		case 28: result.second = "MillingFlood"; break;
		case 29: result.second = "MillingBurrow"; break;
		case 30: result.second = "SquadMove"; break;
		case 31: result.second = "SquadKillList"; break;
		case 32: result.second = "SquadPatrol"; break;
		case 33: result.second = "SquadDefendBurrow"; break;
		case 34: result.second = "SquadDefendBurrowFromTarget"; break;
		case 35: result.second = "LairHunter"; break;
		case 36: result.second = "Graze"; break;
		case 37: result.second = "Guard"; break;
		case 38: result.second = "Alarm"; break;
		case 39: result.second = "MoveToSite"; break;
		case 40: result.second = "ClaimSite"; break;
		case 41: result.second = "WaitOrder"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_plant_raw_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SPRING"; break;
		case 1: result.second = "SUMMER"; break;
		case 2: result.second = "AUTUMN"; break;
		case 3: result.second = "WINTER"; break;
		case 4: result.second = "anon_1"; break;
		case 5: result.second = "SEED"; break;
		case 6: result.second = "TREE_HAS_MUSHROOM_CAP"; break;
		case 7: result.second = "DRINK"; break;
		case 8: result.second = "EXTRACT_BARREL"; break;
		case 9: result.second = "EXTRACT_VIAL"; break;
		case 10: result.second = "EXTRACT_STILL_VIAL"; break;
		case 11: result.second = "GENERATED"; break;
		case 12: result.second = "THREAD"; break;
		case 13: result.second = "MILL"; break;
		case 14: result.second = "anon_2"; break;
		case 15: result.second = "anon_3"; break;
		case 16: result.second = "anon_4"; break;
		case 17: result.second = "anon_5"; break;
		case 18: result.second = "anon_6"; break;
		case 19: result.second = "anon_7"; break;
		case 20: result.second = "WET"; break;
		case 21: result.second = "DRY"; break;
		case 22: result.second = "BIOME_MOUNTAIN"; break;
		case 23: result.second = "BIOME_GLACIER"; break;
		case 24: result.second = "BIOME_TUNDRA"; break;
		case 25: result.second = "BIOME_SWAMP_TEMPERATE_FRESHWATER"; break;
		case 26: result.second = "BIOME_SWAMP_TEMPERATE_SALTWATER"; break;
		case 27: result.second = "BIOME_MARSH_TEMPERATE_FRESHWATER"; break;
		case 28: result.second = "BIOME_MARSH_TEMPERATE_SALTWATER"; break;
		case 29: result.second = "BIOME_SWAMP_TROPICAL_FRESHWATER"; break;
		case 30: result.second = "BIOME_SWAMP_TROPICAL_SALTWATER"; break;
		case 31: result.second = "BIOME_SWAMP_MANGROVE"; break;
		case 32: result.second = "BIOME_MARSH_TROPICAL_FRESHWATER"; break;
		case 33: result.second = "BIOME_MARSH_TROPICAL_SALTWATER"; break;
		case 34: result.second = "BIOME_FOREST_TAIGA"; break;
		case 35: result.second = "BIOME_FOREST_TEMPERATE_CONIFER"; break;
		case 36: result.second = "BIOME_FOREST_TEMPERATE_BROADLEAF"; break;
		case 37: result.second = "BIOME_FOREST_TROPICAL_CONIFER"; break;
		case 38: result.second = "BIOME_FOREST_TROPICAL_DRY_BROADLEAF"; break;
		case 39: result.second = "BIOME_FOREST_TROPICAL_MOIST_BROADLEAF"; break;
		case 40: result.second = "BIOME_GRASSLAND_TEMPERATE"; break;
		case 41: result.second = "BIOME_SAVANNA_TEMPERATE"; break;
		case 42: result.second = "BIOME_SHRUBLAND_TEMPERATE"; break;
		case 43: result.second = "BIOME_GRASSLAND_TROPICAL"; break;
		case 44: result.second = "BIOME_SAVANNA_TROPICAL"; break;
		case 45: result.second = "BIOME_SHRUBLAND_TROPICAL"; break;
		case 46: result.second = "BIOME_DESERT_BADLAND"; break;
		case 47: result.second = "BIOME_DESERT_ROCK"; break;
		case 48: result.second = "BIOME_DESERT_SAND"; break;
		case 49: result.second = "BIOME_OCEAN_TROPICAL"; break;
		case 50: result.second = "BIOME_OCEAN_TEMPERATE"; break;
		case 51: result.second = "BIOME_OCEAN_ARCTIC"; break;
		case 52: result.second = "BIOME_POOL_TEMPERATE_FRESHWATER"; break;
		case 53: result.second = "BIOME_SUBTERRANEAN_WATER"; break;
		case 54: result.second = "BIOME_SUBTERRANEAN_CHASM"; break;
		case 55: result.second = "BIOME_SUBTERRANEAN_LAVA"; break;
		case 56: result.second = "GOOD"; break;
		case 57: result.second = "EVIL"; break;
		case 58: result.second = "SAVAGE"; break;
		case 59: result.second = "BIOME_POOL_TEMPERATE_BRACKISHWATER"; break;
		case 60: result.second = "BIOME_POOL_TEMPERATE_SALTWATER"; break;
		case 61: result.second = "BIOME_POOL_TROPICAL_FRESHWATER"; break;
		case 62: result.second = "BIOME_POOL_TROPICAL_BRACKISHWATER"; break;
		case 63: result.second = "BIOME_POOL_TROPICAL_SALTWATER"; break;
		case 64: result.second = "BIOME_LAKE_TEMPERATE_FRESHWATER"; break;
		case 65: result.second = "BIOME_LAKE_TEMPERATE_BRACKISHWATER"; break;
		case 66: result.second = "BIOME_LAKE_TEMPERATE_SALTWATER"; break;
		case 67: result.second = "BIOME_LAKE_TROPICAL_FRESHWATER"; break;
		case 68: result.second = "BIOME_LAKE_TROPICAL_BRACKISHWATER"; break;
		case 69: result.second = "BIOME_LAKE_TROPICAL_SALTWATER"; break;
		case 70: result.second = "BIOME_RIVER_TEMPERATE_FRESHWATER"; break;
		case 71: result.second = "BIOME_RIVER_TEMPERATE_BRACKISHWATER"; break;
		case 72: result.second = "BIOME_RIVER_TEMPERATE_SALTWATER"; break;
		case 73: result.second = "BIOME_RIVER_TROPICAL_FRESHWATER"; break;
		case 74: result.second = "BIOME_RIVER_TROPICAL_BRACKISHWATER"; break;
		case 75: result.second = "BIOME_RIVER_TROPICAL_SALTWATER"; break;
		case 76: result.second = "TWIGS_SIDE_BRANCHES"; break;
		case 77: result.second = "SAPLING"; break;
		case 78: result.second = "TREE"; break;
		case 79: result.second = "GRASS"; break;
		case 80: result.second = "TWIGS_ABOVE_BRANCHES"; break;
		case 81: result.second = "TWIGS_BELOW_BRANCHES"; break;
		case 82: result.second = "TWIGS_SIDE_HEAVY_BRANCHES"; break;
		case 83: result.second = "TWIGS_ABOVE_HEAVY_BRANCHES"; break;
		case 84: result.second = "TWIGS_BELOW_HEAVY_BRANCHES"; break;
		case 85: result.second = "TWIGS_SIDE_TRUNK"; break;
		case 86: result.second = "TWIGS_ABOVE_TRUNK"; break;
		case 87: result.second = "TWIGS_BELOW_TRUNK"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_projectile_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Item"; break;
		case 1: result.second = "Unit"; break;
		case 2: result.second = "Magic"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_reaction_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "FUEL"; break;
		case 1: result.second = "AUTOMATIC"; break;
		case 2: result.second = "ADVENTURE_MODE_ENABLED"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_reaction_reagent_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "item"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_reaction_product_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "item"; break;
		case 1: result.second = "improvement"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_reaction_product_item_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "GET_MATERIAL_SAME"; break;
		case 1: result.second = "GET_MATERIAL_PRODUCT"; break;
		case 2: result.second = "FORCE_EDGE"; break;
		case 3: result.second = "PASTE"; break;
		case 4: result.second = "PRESSED"; break;
		case 5: result.second = "CRAFTS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_reaction_product_improvement_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "GET_MATERIAL_SAME"; break;
		case 1: result.second = "GET_MATERIAL_PRODUCT"; break;
		case 2: result.second = "GLAZED"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_general_ref_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ARTIFACT"; break;
		case 1: result.second = "IS_ARTIFACT"; break;
		case 2: result.second = "NEMESIS"; break;
		case 3: result.second = "IS_NEMESIS"; break;
		case 4: result.second = "ITEM"; break;
		case 5: result.second = "ITEM_TYPE"; break;
		case 6: result.second = "COINBATCH"; break;
		case 7: result.second = "MAPSQUARE"; break;
		case 8: result.second = "ENTITY_ART_IMAGE"; break;
		case 9: result.second = "CONTAINS_UNIT"; break;
		case 10: result.second = "CONTAINS_ITEM"; break;
		case 11: result.second = "CONTAINED_IN_ITEM"; break;
		case 12: result.second = "PROJECTILE"; break;
		case 13: result.second = "UNIT"; break;
		case 14: result.second = "UNIT_MILKEE"; break;
		case 15: result.second = "UNIT_TRAINEE"; break;
		case 16: result.second = "UNIT_ITEMOWNER"; break;
		case 17: result.second = "UNIT_TRADEBRINGER"; break;
		case 18: result.second = "UNIT_HOLDER"; break;
		case 19: result.second = "UNIT_WORKER"; break;
		case 20: result.second = "UNIT_CAGEE"; break;
		case 21: result.second = "UNIT_BEATEE"; break;
		case 22: result.second = "UNIT_FOODRECEIVER"; break;
		case 23: result.second = "UNIT_KIDNAPEE"; break;
		case 24: result.second = "UNIT_PATIENT"; break;
		case 25: result.second = "UNIT_INFANT"; break;
		case 26: result.second = "UNIT_SLAUGHTEREE"; break;
		case 27: result.second = "UNIT_SHEAREE"; break;
		case 28: result.second = "UNIT_SUCKEE"; break;
		case 29: result.second = "UNIT_REPORTEE"; break;
		case 30: result.second = "BUILDING"; break;
		case 31: result.second = "BUILDING_CIVZONE_ASSIGNED"; break;
		case 32: result.second = "BUILDING_TRIGGER"; break;
		case 33: result.second = "BUILDING_TRIGGERTARGET"; break;
		case 34: result.second = "BUILDING_CHAIN"; break;
		case 35: result.second = "BUILDING_CAGED"; break;
		case 36: result.second = "BUILDING_HOLDER"; break;
		case 37: result.second = "BUILDING_WELL_TAG"; break;
		case 38: result.second = "BUILDING_USE_TARGET_1"; break;
		case 39: result.second = "BUILDING_USE_TARGET_2"; break;
		case 40: result.second = "BUILDING_DESTINATION"; break;
		case 41: result.second = "BUILDING_NEST_BOX"; break;
		case 42: result.second = "ENTITY"; break;
		case 43: result.second = "ENTITY_STOLEN"; break;
		case 44: result.second = "ENTITY_OFFERED"; break;
		case 45: result.second = "ENTITY_ITEMOWNER"; break;
		case 46: result.second = "LOCATION"; break;
		case 47: result.second = "INTERACTION"; break;
		case 48: result.second = "ABSTRACT_BUILDING"; break;
		case 49: result.second = "HISTORICAL_EVENT"; break;
		case 50: result.second = "SPHERE"; break;
		case 51: result.second = "SITE"; break;
		case 52: result.second = "SUBREGION"; break;
		case 53: result.second = "FEATURE_LAYER"; break;
		case 54: result.second = "HISTORICAL_FIGURE"; break;
		case 55: result.second = "ENTITY_POP"; break;
		case 56: result.second = "CREATURE"; break;
		case 57: result.second = "UNIT_RIDER"; break;
		case 58: result.second = "UNIT_CLIMBER"; break;
		case 59: result.second = "UNIT_GELDEE"; break;
		case 60: result.second = "KNOWLEDGE_SCHOLAR_FLAG"; break;
		case 61: result.second = "ACTIVITY_EVENT"; break;
		case 62: result.second = "VALUE_LEVEL"; break;
		case 63: result.second = "LANGUAGE"; break;
		case 64: result.second = "WRITTEN_CONTENT"; break;
		case 65: result.second = "POETIC_FORM"; break;
		case 66: result.second = "MUSICAL_FORM"; break;
		case 67: result.second = "DANCE_FORM"; break;
		case 68: result.second = "BUILDING_DISPLAY_FURNITURE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_specific_ref_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "anon_1"; break;
		case 1: result.second = "UNIT_INVENTORY"; break;
		case 2: result.second = "JOB"; break;
		case 3: result.second = "BUILDING_PARTY"; break;
		case 4: result.second = "ACTIVITY"; break;
		case 5: result.second = "ITEM_GENERAL"; break;
		case 6: result.second = "EFFECT"; break;
		case 7: result.second = "PETINFO_PET"; break;
		case 8: result.second = "PETINFO_OWNER"; break;
		case 9: result.second = "VERMIN_EVENT"; break;
		case 10: result.second = "VERMIN_ESCAPED_PET"; break;
		case 11: result.second = "ENTITY"; break;
		case 12: result.second = "PLOT_INFO"; break;
		case 13: result.second = "VIEWSCREEN"; break;
		case 14: result.second = "UNIT_ITEM_WRESTLE"; break;
		case 15: result.second = "NULL_REF"; break;
		case 16: result.second = "HIST_FIG"; break;
		case 17: result.second = "SITE"; break;
		case 18: result.second = "ARTIFACT"; break;
		case 19: result.second = "ITEM_IMPROVEMENT"; break;
		case 20: result.second = "COIN_FRONT"; break;
		case 21: result.second = "COIN_BACK"; break;
		case 22: result.second = "DETAIL_EVENT"; break;
		case 23: result.second = "SUBREGION"; break;
		case 24: result.second = "FEATURE_LAYER"; break;
		case 25: result.second = "ART_IMAGE"; break;
		case 26: result.second = "CREATURE_DEF"; break;
		case 27: result.second = "anon_2"; break;
		case 28: result.second = "anon_3"; break;
		case 29: result.second = "ENTITY_POPULATION"; break;
		case 30: result.second = "BREED"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_histfig_entity_link_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MEMBER"; break;
		case 1: result.second = "FORMER_MEMBER"; break;
		case 2: result.second = "MERCENARY"; break;
		case 3: result.second = "FORMER_MERCENARY"; break;
		case 4: result.second = "SLAVE"; break;
		case 5: result.second = "FORMER_SLAVE"; break;
		case 6: result.second = "PRISONER"; break;
		case 7: result.second = "FORMER_PRISONER"; break;
		case 8: result.second = "ENEMY"; break;
		case 9: result.second = "CRIMINAL"; break;
		case 10: result.second = "POSITION"; break;
		case 11: result.second = "FORMER_POSITION"; break;
		case 12: result.second = "POSITION_CLAIM"; break;
		case 13: result.second = "SQUAD"; break;
		case 14: result.second = "FORMER_SQUAD"; break;
		case 15: result.second = "OCCUPATION"; break;
		case 16: result.second = "FORMER_OCCUPATION"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_histfig_site_link_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "OCCUPATION"; break;
		case 1: result.second = "SEAT_OF_POWER"; break;
		case 2: result.second = "HANGOUT"; break;
		case 3: result.second = "HOME_SITE_ABSTRACT_BUILDING"; break;
		case 4: result.second = "HOME_SITE_REALIZATION_BUILDING"; break;
		case 5: result.second = "LAIR"; break;
		case 6: result.second = "HOME_SITE_REALIZATION_SUL"; break;
		case 7: result.second = "HOME_SITE_SAVED_CIVZONE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_histfig_hf_link_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MOTHER"; break;
		case 1: result.second = "FATHER"; break;
		case 2: result.second = "SPOUSE"; break;
		case 3: result.second = "CHILD"; break;
		case 4: result.second = "DEITY"; break;
		case 5: result.second = "LOVER"; break;
		case 6: result.second = "PRISONER"; break;
		case 7: result.second = "IMPRISONER"; break;
		case 8: result.second = "MASTER"; break;
		case 9: result.second = "APPRENTICE"; break;
		case 10: result.second = "COMPANION"; break;
		case 11: result.second = "FORMER_MASTER"; break;
		case 12: result.second = "FORMER_APPRENTICE"; break;
		case 13: result.second = "PET_OWNER"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_entity_link_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "PARENT"; break;
		case 1: result.second = "CHILD"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_resource_allotment_specifier_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "CROP"; break;
		case 1: result.second = "STONE"; break;
		case 2: result.second = "METAL"; break;
		case 3: result.second = "WOOD"; break;
		case 4: result.second = "ARMOR_BODY"; break;
		case 5: result.second = "ARMOR_PANTS"; break;
		case 6: result.second = "ARMOR_GLOVES"; break;
		case 7: result.second = "ARMOR_BOOTS"; break;
		case 8: result.second = "ARMOR_HELM"; break;
		case 9: result.second = "CLOTHING_BODY"; break;
		case 10: result.second = "CLOTHING_PANTS"; break;
		case 11: result.second = "CLOTHING_GLOVES"; break;
		case 12: result.second = "CLOTHING_BOOTS"; break;
		case 13: result.second = "CLOTHING_HELM"; break;
		case 14: result.second = "WEAPON_MELEE"; break;
		case 15: result.second = "WEAPON_RANGED"; break;
		case 16: result.second = "ANVIL"; break;
		case 17: result.second = "GEMS"; break;
		case 18: result.second = "THREAD"; break;
		case 19: result.second = "CLOTH"; break;
		case 20: result.second = "LEATHER"; break;
		case 21: result.second = "QUIVER"; break;
		case 22: result.second = "BACKPACK"; break;
		case 23: result.second = "FLASK"; break;
		case 24: result.second = "BAG"; break;
		case 25: result.second = "TABLE"; break;
		case 26: result.second = "CABINET"; break;
		case 27: result.second = "CHAIR"; break;
		case 28: result.second = "BOX"; break;
		case 29: result.second = "BED"; break;
		case 30: result.second = "CRAFTS"; break;
		case 31: result.second = "MEAT"; break;
		case 32: result.second = "BONE"; break;
		case 33: result.second = "HORN"; break;
		case 34: result.second = "SHELL"; break;
		case 35: result.second = "TALLOW"; break;
		case 36: result.second = "TOOTH"; break;
		case 37: result.second = "PEARL"; break;
		case 38: result.second = "SOAP"; break;
		case 39: result.second = "EXTRACT"; break;
		case 40: result.second = "CHEESE"; break;
		case 41: result.second = "SKIN"; break;
		case 42: result.second = "POWDER"; break;
		case 43: result.second = "AMMO"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_profession_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "MINER"; break;
		case 1: result.second = "WOODWORKER"; break;
		case 2: result.second = "CARPENTER"; break;
		case 3: result.second = "BOWYER"; break;
		case 4: result.second = "WOODCUTTER"; break;
		case 5: result.second = "STONEWORKER"; break;
		case 6: result.second = "ENGRAVER"; break;
		case 7: result.second = "MASON"; break;
		case 8: result.second = "RANGER"; break;
		case 9: result.second = "ANIMAL_CARETAKER"; break;
		case 10: result.second = "ANIMAL_TRAINER"; break;
		case 11: result.second = "HUNTER"; break;
		case 12: result.second = "TRAPPER"; break;
		case 13: result.second = "ANIMAL_DISSECTOR"; break;
		case 14: result.second = "METALSMITH"; break;
		case 15: result.second = "FURNACE_OPERATOR"; break;
		case 16: result.second = "WEAPONSMITH"; break;
		case 17: result.second = "ARMORER"; break;
		case 18: result.second = "BLACKSMITH"; break;
		case 19: result.second = "METALCRAFTER"; break;
		case 20: result.second = "JEWELER"; break;
		case 21: result.second = "GEM_CUTTER"; break;
		case 22: result.second = "GEM_SETTER"; break;
		case 23: result.second = "CRAFTSMAN"; break;
		case 24: result.second = "WOODCRAFTER"; break;
		case 25: result.second = "STONECRAFTER"; break;
		case 26: result.second = "LEATHERWORKER"; break;
		case 27: result.second = "BONE_CARVER"; break;
		case 28: result.second = "WEAVER"; break;
		case 29: result.second = "CLOTHIER"; break;
		case 30: result.second = "GLASSMAKER"; break;
		case 31: result.second = "POTTER"; break;
		case 32: result.second = "GLAZER"; break;
		case 33: result.second = "WAX_WORKER"; break;
		case 34: result.second = "STRAND_EXTRACTOR"; break;
		case 35: result.second = "FISHERY_WORKER"; break;
		case 36: result.second = "FISHERMAN"; break;
		case 37: result.second = "FISH_DISSECTOR"; break;
		case 38: result.second = "FISH_CLEANER"; break;
		case 39: result.second = "FARMER"; break;
		case 40: result.second = "CHEESE_MAKER"; break;
		case 41: result.second = "MILKER"; break;
		case 42: result.second = "COOK"; break;
		case 43: result.second = "THRESHER"; break;
		case 44: result.second = "MILLER"; break;
		case 45: result.second = "BUTCHER"; break;
		case 46: result.second = "TANNER"; break;
		case 47: result.second = "DYER"; break;
		case 48: result.second = "PLANTER"; break;
		case 49: result.second = "HERBALIST"; break;
		case 50: result.second = "BREWER"; break;
		case 51: result.second = "SOAP_MAKER"; break;
		case 52: result.second = "POTASH_MAKER"; break;
		case 53: result.second = "LYE_MAKER"; break;
		case 54: result.second = "WOOD_BURNER"; break;
		case 55: result.second = "SHEARER"; break;
		case 56: result.second = "SPINNER"; break;
		case 57: result.second = "PRESSER"; break;
		case 58: result.second = "BEEKEEPER"; break;
		case 59: result.second = "ENGINEER"; break;
		case 60: result.second = "MECHANIC"; break;
		case 61: result.second = "SIEGE_ENGINEER"; break;
		case 62: result.second = "SIEGE_OPERATOR"; break;
		case 63: result.second = "PUMP_OPERATOR"; break;
		case 64: result.second = "CLERK"; break;
		case 65: result.second = "ADMINISTRATOR"; break;
		case 66: result.second = "TRADER"; break;
		case 67: result.second = "ARCHITECT"; break;
		case 68: result.second = "ALCHEMIST"; break;
		case 69: result.second = "DOCTOR"; break;
		case 70: result.second = "DIAGNOSER"; break;
		case 71: result.second = "BONE_SETTER"; break;
		case 72: result.second = "SUTURER"; break;
		case 73: result.second = "SURGEON"; break;
		case 74: result.second = "MERCHANT"; break;
		case 75: result.second = "HAMMERMAN"; break;
		case 76: result.second = "MASTER_HAMMERMAN"; break;
		case 77: result.second = "SPEARMAN"; break;
		case 78: result.second = "MASTER_SPEARMAN"; break;
		case 79: result.second = "CROSSBOWMAN"; break;
		case 80: result.second = "MASTER_CROSSBOWMAN"; break;
		case 81: result.second = "WRESTLER"; break;
		case 82: result.second = "MASTER_WRESTLER"; break;
		case 83: result.second = "AXEMAN"; break;
		case 84: result.second = "MASTER_AXEMAN"; break;
		case 85: result.second = "SWORDSMAN"; break;
		case 86: result.second = "MASTER_SWORDSMAN"; break;
		case 87: result.second = "MACEMAN"; break;
		case 88: result.second = "MASTER_MACEMAN"; break;
		case 89: result.second = "PIKEMAN"; break;
		case 90: result.second = "MASTER_PIKEMAN"; break;
		case 91: result.second = "BOWMAN"; break;
		case 92: result.second = "MASTER_BOWMAN"; break;
		case 93: result.second = "BLOWGUNMAN"; break;
		case 94: result.second = "MASTER_BLOWGUNMAN"; break;
		case 95: result.second = "LASHER"; break;
		case 96: result.second = "MASTER_LASHER"; break;
		case 97: result.second = "RECRUIT"; break;
		case 98: result.second = "TRAINED_HUNTER"; break;
		case 99: result.second = "TRAINED_WAR"; break;
		case 100: result.second = "MASTER_THIEF"; break;
		case 101: result.second = "THIEF"; break;
		case 102: result.second = "STANDARD"; break;
		case 103: result.second = "CHILD"; break;
		case 104: result.second = "BABY"; break;
		case 105: result.second = "DRUNK"; break;
		case 106: result.second = "MONSTER_SLAYER"; break;
		case 107: result.second = "SCOUT"; break;
		case 108: result.second = "BEAST_HUNTER"; break;
		case 109: result.second = "SNATCHER"; break;
		case 110: result.second = "MERCENARY"; break;
		case 111: result.second = "GELDER"; break;
		case 112: result.second = "PERFORMER"; break;
		case 113: result.second = "POET"; break;
		case 114: result.second = "BARD"; break;
		case 115: result.second = "DANCER"; break;
		case 116: result.second = "SAGE"; break;
		case 117: result.second = "SCHOLAR"; break;
		case 118: result.second = "PHILOSOPHER"; break;
		case 119: result.second = "MATHEMATICIAN"; break;
		case 120: result.second = "HISTORIAN"; break;
		case 121: result.second = "ASTRONOMER"; break;
		case 122: result.second = "NATURALIST"; break;
		case 123: result.second = "CHEMIST"; break;
		case 124: result.second = "GEOGRAPHER"; break;
		case 125: result.second = "SCRIBE"; break;
		case 126: result.second = "PAPERMAKER"; break;
		case 127: result.second = "BOOKBINDER"; break;
		case 128: result.second = "TAVERN_KEEPER"; break;
		case 129: result.second = "CRIMINAL"; break;
		case 130: result.second = "PEDDLER"; break;
		case 131: result.second = "PROPHET"; break;
		case 132: result.second = "PILGRIM"; break;
		case 133: result.second = "MONK"; break;
		case 134: result.second = "MESSENGER"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_labor_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -13: result.second = "Other"; break;
		case -12: result.second = "Hauling"; break;
		case -11: result.second = "Engineering"; break;
		case -10: result.second = "Crafts"; break;
		case -9: result.second = "Jewelry"; break;
		case -8: result.second = "Metalsmithing"; break;
		case -7: result.second = "Fishing"; break;
		case -6: result.second = "Farming"; break;
		case -5: result.second = "Healthcare"; break;
		case -4: result.second = "Hunting"; break;
		case -3: result.second = "Stoneworking"; break;
		case -2: result.second = "Woodworking"; break;
		case -1: result.second = "None"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_labor_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "MINE"; break;
		case 1: result.second = "HAUL_STONE"; break;
		case 2: result.second = "HAUL_WOOD"; break;
		case 3: result.second = "HAUL_BODY"; break;
		case 4: result.second = "HAUL_FOOD"; break;
		case 5: result.second = "HAUL_REFUSE"; break;
		case 6: result.second = "HAUL_ITEM"; break;
		case 7: result.second = "HAUL_FURNITURE"; break;
		case 8: result.second = "HAUL_ANIMALS"; break;
		case 9: result.second = "CLEAN"; break;
		case 10: result.second = "CUTWOOD"; break;
		case 11: result.second = "CARPENTER"; break;
		case 12: result.second = "DETAIL"; break;
		case 13: result.second = "MASON"; break;
		case 14: result.second = "ARCHITECT"; break;
		case 15: result.second = "ANIMALTRAIN"; break;
		case 16: result.second = "ANIMALCARE"; break;
		case 17: result.second = "DIAGNOSE"; break;
		case 18: result.second = "SURGERY"; break;
		case 19: result.second = "BONE_SETTING"; break;
		case 20: result.second = "SUTURING"; break;
		case 21: result.second = "DRESSING_WOUNDS"; break;
		case 22: result.second = "FEED_WATER_CIVILIANS"; break;
		case 23: result.second = "RECOVER_WOUNDED"; break;
		case 24: result.second = "BUTCHER"; break;
		case 25: result.second = "TRAPPER"; break;
		case 26: result.second = "DISSECT_VERMIN"; break;
		case 27: result.second = "LEATHER"; break;
		case 28: result.second = "TANNER"; break;
		case 29: result.second = "BREWER"; break;
		case 30: result.second = "ALCHEMIST"; break;
		case 31: result.second = "SOAP_MAKER"; break;
		case 32: result.second = "WEAVER"; break;
		case 33: result.second = "CLOTHESMAKER"; break;
		case 34: result.second = "MILLER"; break;
		case 35: result.second = "PROCESS_PLANT"; break;
		case 36: result.second = "MAKE_CHEESE"; break;
		case 37: result.second = "MILK"; break;
		case 38: result.second = "COOK"; break;
		case 39: result.second = "PLANT"; break;
		case 40: result.second = "HERBALIST"; break;
		case 41: result.second = "FISH"; break;
		case 42: result.second = "CLEAN_FISH"; break;
		case 43: result.second = "DISSECT_FISH"; break;
		case 44: result.second = "HUNT"; break;
		case 45: result.second = "SMELT"; break;
		case 46: result.second = "FORGE_WEAPON"; break;
		case 47: result.second = "FORGE_ARMOR"; break;
		case 48: result.second = "FORGE_FURNITURE"; break;
		case 49: result.second = "METAL_CRAFT"; break;
		case 50: result.second = "CUT_GEM"; break;
		case 51: result.second = "ENCRUST_GEM"; break;
		case 52: result.second = "WOOD_CRAFT"; break;
		case 53: result.second = "STONE_CRAFT"; break;
		case 54: result.second = "BONE_CARVE"; break;
		case 55: result.second = "GLASSMAKER"; break;
		case 56: result.second = "EXTRACT_STRAND"; break;
		case 57: result.second = "SIEGECRAFT"; break;
		case 58: result.second = "SIEGEOPERATE"; break;
		case 59: result.second = "BOWYER"; break;
		case 60: result.second = "MECHANIC"; break;
		case 61: result.second = "POTASH_MAKING"; break;
		case 62: result.second = "LYE_MAKING"; break;
		case 63: result.second = "DYER"; break;
		case 64: result.second = "BURN_WOOD"; break;
		case 65: result.second = "OPERATE_PUMP"; break;
		case 66: result.second = "SHEARER"; break;
		case 67: result.second = "SPINNER"; break;
		case 68: result.second = "POTTERY"; break;
		case 69: result.second = "GLAZING"; break;
		case 70: result.second = "PRESSING"; break;
		case 71: result.second = "BEEKEEPING"; break;
		case 72: result.second = "WAX_WORKING"; break;
		case 73: result.second = "HANDLE_VEHICLES"; break;
		case 74: result.second = "HAUL_TRADE"; break;
		case 75: result.second = "PULL_LEVER"; break;
		case 76: result.second = "REMOVE_CONSTRUCTION"; break;
		case 77: result.second = "HAUL_WATER"; break;
		case 78: result.second = "GELD"; break;
		case 79: result.second = "BUILD_ROAD"; break;
		case 80: result.second = "BUILD_CONSTRUCTION"; break;
		case 81: result.second = "PAPERMAKING"; break;
		case 82: result.second = "BOOKBINDING"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_job_skill_class_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Normal"; break;
		case 1: result.second = "Medical"; break;
		case 2: result.second = "Personal"; break;
		case 3: result.second = "Social"; break;
		case 4: result.second = "Cultural"; break;
		case 5: result.second = "MilitaryWeapon"; break;
		case 6: result.second = "MilitaryUnarmed"; break;
		case 7: result.second = "MilitaryAttack"; break;
		case 8: result.second = "MilitaryDefense"; break;
		case 9: result.second = "MilitaryMisc"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_job_skill_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "MINING"; break;
		case 1: result.second = "WOODCUTTING"; break;
		case 2: result.second = "CARPENTRY"; break;
		case 3: result.second = "DETAILSTONE"; break;
		case 4: result.second = "MASONRY"; break;
		case 5: result.second = "ANIMALTRAIN"; break;
		case 6: result.second = "ANIMALCARE"; break;
		case 7: result.second = "DISSECT_FISH"; break;
		case 8: result.second = "DISSECT_VERMIN"; break;
		case 9: result.second = "PROCESSFISH"; break;
		case 10: result.second = "BUTCHER"; break;
		case 11: result.second = "TRAPPING"; break;
		case 12: result.second = "TANNER"; break;
		case 13: result.second = "WEAVING"; break;
		case 14: result.second = "BREWING"; break;
		case 15: result.second = "ALCHEMY"; break;
		case 16: result.second = "CLOTHESMAKING"; break;
		case 17: result.second = "MILLING"; break;
		case 18: result.second = "PROCESSPLANTS"; break;
		case 19: result.second = "CHEESEMAKING"; break;
		case 20: result.second = "MILK"; break;
		case 21: result.second = "COOK"; break;
		case 22: result.second = "PLANT"; break;
		case 23: result.second = "HERBALISM"; break;
		case 24: result.second = "FISH"; break;
		case 25: result.second = "SMELT"; break;
		case 26: result.second = "EXTRACT_STRAND"; break;
		case 27: result.second = "FORGE_WEAPON"; break;
		case 28: result.second = "FORGE_ARMOR"; break;
		case 29: result.second = "FORGE_FURNITURE"; break;
		case 30: result.second = "CUTGEM"; break;
		case 31: result.second = "ENCRUSTGEM"; break;
		case 32: result.second = "WOODCRAFT"; break;
		case 33: result.second = "STONECRAFT"; break;
		case 34: result.second = "METALCRAFT"; break;
		case 35: result.second = "GLASSMAKER"; break;
		case 36: result.second = "LEATHERWORK"; break;
		case 37: result.second = "BONECARVE"; break;
		case 38: result.second = "AXE"; break;
		case 39: result.second = "SWORD"; break;
		case 40: result.second = "DAGGER"; break;
		case 41: result.second = "MACE"; break;
		case 42: result.second = "HAMMER"; break;
		case 43: result.second = "SPEAR"; break;
		case 44: result.second = "CROSSBOW"; break;
		case 45: result.second = "SHIELD"; break;
		case 46: result.second = "ARMOR"; break;
		case 47: result.second = "SIEGECRAFT"; break;
		case 48: result.second = "SIEGEOPERATE"; break;
		case 49: result.second = "BOWYER"; break;
		case 50: result.second = "PIKE"; break;
		case 51: result.second = "WHIP"; break;
		case 52: result.second = "BOW"; break;
		case 53: result.second = "BLOWGUN"; break;
		case 54: result.second = "THROW"; break;
		case 55: result.second = "MECHANICS"; break;
		case 56: result.second = "MAGIC_NATURE"; break;
		case 57: result.second = "SNEAK"; break;
		case 58: result.second = "DESIGNBUILDING"; break;
		case 59: result.second = "DRESS_WOUNDS"; break;
		case 60: result.second = "DIAGNOSE"; break;
		case 61: result.second = "SURGERY"; break;
		case 62: result.second = "SET_BONE"; break;
		case 63: result.second = "SUTURE"; break;
		case 64: result.second = "CRUTCH_WALK"; break;
		case 65: result.second = "WOOD_BURNING"; break;
		case 66: result.second = "LYE_MAKING"; break;
		case 67: result.second = "SOAP_MAKING"; break;
		case 68: result.second = "POTASH_MAKING"; break;
		case 69: result.second = "DYER"; break;
		case 70: result.second = "OPERATE_PUMP"; break;
		case 71: result.second = "SWIMMING"; break;
		case 72: result.second = "PERSUASION"; break;
		case 73: result.second = "NEGOTIATION"; break;
		case 74: result.second = "JUDGING_INTENT"; break;
		case 75: result.second = "APPRAISAL"; break;
		case 76: result.second = "ORGANIZATION"; break;
		case 77: result.second = "RECORD_KEEPING"; break;
		case 78: result.second = "LYING"; break;
		case 79: result.second = "INTIMIDATION"; break;
		case 80: result.second = "CONVERSATION"; break;
		case 81: result.second = "COMEDY"; break;
		case 82: result.second = "FLATTERY"; break;
		case 83: result.second = "CONSOLE"; break;
		case 84: result.second = "PACIFY"; break;
		case 85: result.second = "TRACKING"; break;
		case 86: result.second = "KNOWLEDGE_ACQUISITION"; break;
		case 87: result.second = "CONCENTRATION"; break;
		case 88: result.second = "DISCIPLINE"; break;
		case 89: result.second = "SITUATIONAL_AWARENESS"; break;
		case 90: result.second = "WRITING"; break;
		case 91: result.second = "PROSE"; break;
		case 92: result.second = "POETRY"; break;
		case 93: result.second = "READING"; break;
		case 94: result.second = "SPEAKING"; break;
		case 95: result.second = "COORDINATION"; break;
		case 96: result.second = "BALANCE"; break;
		case 97: result.second = "LEADERSHIP"; break;
		case 98: result.second = "TEACHING"; break;
		case 99: result.second = "MELEE_COMBAT"; break;
		case 100: result.second = "RANGED_COMBAT"; break;
		case 101: result.second = "WRESTLING"; break;
		case 102: result.second = "BITE"; break;
		case 103: result.second = "GRASP_STRIKE"; break;
		case 104: result.second = "STANCE_STRIKE"; break;
		case 105: result.second = "DODGING"; break;
		case 106: result.second = "MISC_WEAPON"; break;
		case 107: result.second = "KNAPPING"; break;
		case 108: result.second = "MILITARY_TACTICS"; break;
		case 109: result.second = "SHEARING"; break;
		case 110: result.second = "SPINNING"; break;
		case 111: result.second = "POTTERY"; break;
		case 112: result.second = "GLAZING"; break;
		case 113: result.second = "PRESSING"; break;
		case 114: result.second = "BEEKEEPING"; break;
		case 115: result.second = "WAX_WORKING"; break;
		case 116: result.second = "CLIMBING"; break;
		case 117: result.second = "GELD"; break;
		case 118: result.second = "DANCE"; break;
		case 119: result.second = "MAKE_MUSIC"; break;
		case 120: result.second = "SING_MUSIC"; break;
		case 121: result.second = "PLAY_KEYBOARD_INSTRUMENT"; break;
		case 122: result.second = "PLAY_STRINGED_INSTRUMENT"; break;
		case 123: result.second = "PLAY_WIND_INSTRUMENT"; break;
		case 124: result.second = "PLAY_PERCUSSION_INSTRUMENT"; break;
		case 125: result.second = "CRITICAL_THINKING"; break;
		case 126: result.second = "LOGIC"; break;
		case 127: result.second = "MATHEMATICS"; break;
		case 128: result.second = "ASTRONOMY"; break;
		case 129: result.second = "CHEMISTRY"; break;
		case 130: result.second = "GEOGRAPHY"; break;
		case 131: result.second = "OPTICS_ENGINEER"; break;
		case 132: result.second = "FLUID_ENGINEER"; break;
		case 133: result.second = "PAPERMAKING"; break;
		case 134: result.second = "BOOKBINDING"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_hauler_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Any"; break;
		case 1: result.second = "Stone"; break;
		case 2: result.second = "Wood"; break;
		case 3: result.second = "Item"; break;
		case 4: result.second = "Bin"; break;
		case 5: result.second = "Body"; break;
		case 6: result.second = "Food"; break;
		case 7: result.second = "Refuse"; break;
		case 8: result.second = "Furniture"; break;
		case 9: result.second = "Animal"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_furniture_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "FLOODGATE"; break;
		case 1: result.second = "HATCH_COVER"; break;
		case 2: result.second = "GRATE"; break;
		case 3: result.second = "DOOR"; break;
		case 4: result.second = "CATAPULTPARTS"; break;
		case 5: result.second = "BALLISTAPARTS"; break;
		case 6: result.second = "TRAPPARTS"; break;
		case 7: result.second = "BED"; break;
		case 8: result.second = "TRACTION_BENCH"; break;
		case 9: result.second = "WINDOW"; break;
		case 10: result.second = "CHAIR"; break;
		case 11: result.second = "TABLE"; break;
		case 12: result.second = "COFFIN"; break;
		case 13: result.second = "STATUE"; break;
		case 14: result.second = "SLAB"; break;
		case 15: result.second = "QUERN"; break;
		case 16: result.second = "MILLSTONE"; break;
		case 17: result.second = "ARMORSTAND"; break;
		case 18: result.second = "WEAPONRACK"; break;
		case 19: result.second = "CABINET"; break;
		case 20: result.second = "ANVIL"; break;
		case 21: result.second = "BUCKET"; break;
		case 22: result.second = "BIN"; break;
		case 23: result.second = "BOX"; break;
		case 24: result.second = "SIEGEAMMO"; break;
		case 25: result.second = "BARREL"; break;
		case 26: result.second = "BALLISTAARROWHEAD"; break;
		case 27: result.second = "PIPE_SECTION"; break;
		case 28: result.second = "FOOD_STORAGE"; break;
		case 29: result.second = "MINECART"; break;
		case 30: result.second = "WHEELBARROW"; break;
		case 31: result.second = "OTHER_LARGE_TOOLS"; break;
		case 32: result.second = "SAND_BAG"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_stockpile_category_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "Remove"; break;
		case 0: result.second = "Animals"; break;
		case 1: result.second = "Food"; break;
		case 2: result.second = "Furniture"; break;
		case 3: result.second = "Corpses"; break;
		case 4: result.second = "Refuse"; break;
		case 5: result.second = "Stone"; break;
		case 6: result.second = "Ore"; break;
		case 7: result.second = "Ammo"; break;
		case 8: result.second = "Coins"; break;
		case 9: result.second = "Bars"; break;
		case 10: result.second = "Gems"; break;
		case 11: result.second = "Goods"; break;
		case 12: result.second = "Leather"; break;
		case 13: result.second = "Cloth"; break;
		case 14: result.second = "Wood"; break;
		case 15: result.second = "Weapons"; break;
		case 16: result.second = "Armor"; break;
		case 17: result.second = "Sheets"; break;
		case 18: result.second = "Custom"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_stockpile_list_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Animals"; break;
		case 1: result.second = "Food"; break;
		case 2: result.second = "FoodMeat"; break;
		case 3: result.second = "FoodFish"; break;
		case 4: result.second = "FoodUnpreparedFish"; break;
		case 5: result.second = "FoodEgg"; break;
		case 6: result.second = "FoodPlants"; break;
		case 7: result.second = "FoodDrinkPlant"; break;
		case 8: result.second = "FoodDrinkAnimal"; break;
		case 9: result.second = "FoodCheesePlant"; break;
		case 10: result.second = "FoodCheeseAnimal"; break;
		case 11: result.second = "FoodSeeds"; break;
		case 12: result.second = "FoodLeaves"; break;
		case 13: result.second = "FoodMilledPlant"; break;
		case 14: result.second = "FoodBoneMeal"; break;
		case 15: result.second = "FoodFat"; break;
		case 16: result.second = "FoodPaste"; break;
		case 17: result.second = "FoodPressedMaterial"; break;
		case 18: result.second = "FoodExtractPlant"; break;
		case 19: result.second = "FoodExtractAnimal"; break;
		case 20: result.second = "FoodMiscLiquid"; break;
		case 21: result.second = "Furniture"; break;
		case 22: result.second = "FurnitureType"; break;
		case 23: result.second = "FurnitureStoneClay"; break;
		case 24: result.second = "FurnitureMetal"; break;
		case 25: result.second = "FurnitureOtherMaterials"; break;
		case 26: result.second = "FurnitureCoreQuality"; break;
		case 27: result.second = "FurnitureTotalQuality"; break;
		case 28: result.second = "Corpses"; break;
		case 29: result.second = "Refuse"; break;
		case 30: result.second = "RefuseItems"; break;
		case 31: result.second = "RefuseCorpses"; break;
		case 32: result.second = "RefuseParts"; break;
		case 33: result.second = "RefuseSkulls"; break;
		case 34: result.second = "RefuseBones"; break;
		case 35: result.second = "RefuseShells"; break;
		case 36: result.second = "RefuseTeeth"; break;
		case 37: result.second = "RefuseHorns"; break;
		case 38: result.second = "RefuseHair"; break;
		case 39: result.second = "Stone"; break;
		case 40: result.second = "StoneOres"; break;
		case 41: result.second = "StoneEconomic"; break;
		case 42: result.second = "StoneOther"; break;
		case 43: result.second = "StoneClay"; break;
		case 44: result.second = "Ammo"; break;
		case 45: result.second = "AmmoType"; break;
		case 46: result.second = "AmmoMetal"; break;
		case 47: result.second = "AmmoOther"; break;
		case 48: result.second = "AmmoCoreQuality"; break;
		case 49: result.second = "AmmoTotalQuality"; break;
		case 50: result.second = "Coins"; break;
		case 51: result.second = "BarsBlocks"; break;
		case 52: result.second = "BarsMetal"; break;
		case 53: result.second = "BarsOther"; break;
		case 54: result.second = "BlocksStone"; break;
		case 55: result.second = "BlocksMetal"; break;
		case 56: result.second = "BlocksOther"; break;
		case 57: result.second = "Gems"; break;
		case 58: result.second = "RoughGem"; break;
		case 59: result.second = "RoughGlass"; break;
		case 60: result.second = "CutGem"; break;
		case 61: result.second = "CutGlass"; break;
		case 62: result.second = "CutStone"; break;
		case 63: result.second = "Goods"; break;
		case 64: result.second = "GoodsType"; break;
		case 65: result.second = "GoodsStone"; break;
		case 66: result.second = "GoodsMetal"; break;
		case 67: result.second = "GoodsGem"; break;
		case 68: result.second = "GoodsOther"; break;
		case 69: result.second = "GoodsCoreQuality"; break;
		case 70: result.second = "GoodsTotalQuality"; break;
		case 71: result.second = "Leather"; break;
		case 72: result.second = "Cloth"; break;
		case 73: result.second = "ThreadSilk"; break;
		case 74: result.second = "ThreadPlant"; break;
		case 75: result.second = "ThreadYarn"; break;
		case 76: result.second = "ThreadMetal"; break;
		case 77: result.second = "ClothSilk"; break;
		case 78: result.second = "ClothPlant"; break;
		case 79: result.second = "ClothYarn"; break;
		case 80: result.second = "ClothMetal"; break;
		case 81: result.second = "Wood"; break;
		case 82: result.second = "Weapons"; break;
		case 83: result.second = "WeaponsType"; break;
		case 84: result.second = "WeaponsTrapcomp"; break;
		case 85: result.second = "WeaponsMetal"; break;
		case 86: result.second = "WeaponsStone"; break;
		case 87: result.second = "WeaponsOther"; break;
		case 88: result.second = "WeaponsCoreQuality"; break;
		case 89: result.second = "WeaponsTotalQuality"; break;
		case 90: result.second = "Armor"; break;
		case 91: result.second = "ArmorBody"; break;
		case 92: result.second = "ArmorHead"; break;
		case 93: result.second = "ArmorFeet"; break;
		case 94: result.second = "ArmorHands"; break;
		case 95: result.second = "ArmorLegs"; break;
		case 96: result.second = "ArmorShield"; break;
		case 97: result.second = "ArmorMetal"; break;
		case 98: result.second = "ArmorOther"; break;
		case 99: result.second = "ArmorCoreQuality"; break;
		case 100: result.second = "ArmorTotalQuality"; break;
		case 101: result.second = "Sheet"; break;
		case 102: result.second = "SheetPaper"; break;
		case 103: result.second = "SheetParchment"; break;
		case 104: result.second = "AdditionalOptions"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_creature_interaction_effect_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "PAIN"; break;
		case 1: result.second = "SWELLING"; break;
		case 2: result.second = "OOZING"; break;
		case 3: result.second = "BRUISING"; break;
		case 4: result.second = "BLISTERS"; break;
		case 5: result.second = "NUMBNESS"; break;
		case 6: result.second = "PARALYSIS"; break;
		case 7: result.second = "FEVER"; break;
		case 8: result.second = "BLEEDING"; break;
		case 9: result.second = "COUGH_BLOOD"; break;
		case 10: result.second = "VOMIT_BLOOD"; break;
		case 11: result.second = "NAUSEA"; break;
		case 12: result.second = "UNCONSCIOUSNESS"; break;
		case 13: result.second = "NECROSIS"; break;
		case 14: result.second = "IMPAIR_FUNCTION"; break;
		case 15: result.second = "DROWSINESS"; break;
		case 16: result.second = "DIZZINESS"; break;
		case 17: result.second = "ADD_TAG"; break;
		case 18: result.second = "REMOVE_TAG"; break;
		case 19: result.second = "DISPLAY_TILE"; break;
		case 20: result.second = "FLASH_TILE"; break;
		case 21: result.second = "SPEED_CHANGE"; break;
		case 22: result.second = "CAN_DO_INTERACTION"; break;
		case 23: result.second = "SKILL_ROLL_ADJUST"; break;
		case 24: result.second = "BODY_TRANSFORMATION"; break;
		case 25: result.second = "PHYS_ATT_CHANGE"; break;
		case 26: result.second = "MENT_ATT_CHANGE"; break;
		case 27: result.second = "MATERIAL_FORCE_MULTIPLIER"; break;
		case 28: result.second = "BODY_MAT_INTERACTION"; break;
		case 29: result.second = "BODY_APPEARANCE_MODIFIER"; break;
		case 30: result.second = "BP_APPEARANCE_MODIFIER"; break;
		case 31: result.second = "DISPLAY_NAME"; break;
		case 32: result.second = "SENSE_CREATURE_CLASS"; break;
		case 33: result.second = "FEEL_EMOTION"; break;
		case 34: result.second = "CHANGE_PERSONALITY"; break;
		case 35: result.second = "ERRATIC_BEHAVIOR"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_creature_interaction_effect_target_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "BY_TYPE"; break;
		case 1: result.second = "BY_TOKEN"; break;
		case 2: result.second = "BY_CATEGORY"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tiletype_shape_basic_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Open"; break;
		case 1: result.second = "Floor"; break;
		case 2: result.second = "Ramp"; break;
		case 3: result.second = "Wall"; break;
		case 4: result.second = "Stair"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tiletype_shape_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "EMPTY"; break;
		case 1: result.second = "FLOOR"; break;
		case 2: result.second = "BOULDER"; break;
		case 3: result.second = "PEBBLES"; break;
		case 4: result.second = "WALL"; break;
		case 5: result.second = "FORTIFICATION"; break;
		case 6: result.second = "STAIR_UP"; break;
		case 7: result.second = "STAIR_DOWN"; break;
		case 8: result.second = "STAIR_UPDOWN"; break;
		case 9: result.second = "RAMP"; break;
		case 10: result.second = "RAMP_TOP"; break;
		case 11: result.second = "BROOK_BED"; break;
		case 12: result.second = "BROOK_TOP"; break;
		case 13: result.second = "BRANCH"; break;
		case 14: result.second = "TRUNK_BRANCH"; break;
		case 15: result.second = "TWIG"; break;
		case 16: result.second = "SAPLING"; break;
		case 17: result.second = "SHRUB"; break;
		case 18: result.second = "ENDLESS_PIT"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tiletype_material_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "AIR"; break;
		case 1: result.second = "SOIL"; break;
		case 2: result.second = "STONE"; break;
		case 3: result.second = "FEATURE"; break;
		case 4: result.second = "LAVA_STONE"; break;
		case 5: result.second = "MINERAL"; break;
		case 6: result.second = "FROZEN_LIQUID"; break;
		case 7: result.second = "CONSTRUCTION"; break;
		case 8: result.second = "GRASS_LIGHT"; break;
		case 9: result.second = "GRASS_DARK"; break;
		case 10: result.second = "GRASS_DRY"; break;
		case 11: result.second = "GRASS_DEAD"; break;
		case 12: result.second = "PLANT"; break;
		case 13: result.second = "HFS"; break;
		case 14: result.second = "CAMPFIRE"; break;
		case 15: result.second = "FIRE"; break;
		case 16: result.second = "ASHES"; break;
		case 17: result.second = "MAGMA"; break;
		case 18: result.second = "DRIFTWOOD"; break;
		case 19: result.second = "POOL"; break;
		case 20: result.second = "BROOK"; break;
		case 21: result.second = "RIVER"; break;
		case 22: result.second = "ROOT"; break;
		case 23: result.second = "TREE"; break;
		case 24: result.second = "MUSHROOM"; break;
		case 25: result.second = "UNDERWORLD_GATE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tiletype_variant_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "VAR_1"; break;
		case 1: result.second = "VAR_2"; break;
		case 2: result.second = "VAR_3"; break;
		case 3: result.second = "VAR_4"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tiletype_special_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "NORMAL"; break;
		case 1: result.second = "RIVER_SOURCE"; break;
		case 2: result.second = "WATERFALL"; break;
		case 3: result.second = "SMOOTH"; break;
		case 4: result.second = "FURROWED"; break;
		case 5: result.second = "WET"; break;
		case 6: result.second = "DEAD"; break;
		case 7: result.second = "WORN_1"; break;
		case 8: result.second = "WORN_2"; break;
		case 9: result.second = "WORN_3"; break;
		case 10: result.second = "TRACK"; break;
		case 11: result.second = "SMOOTH_DEAD"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tiletype_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Void"; break;
		case 1: result.second = "RampTop"; break;
		case 2: result.second = "MurkyPool"; break;
		case 3: result.second = "MurkyPoolRamp"; break;
		case 4: result.second = "UnderworldGateStairU"; break;
		case 5: result.second = "UnderworldGateStairD"; break;
		case 6: result.second = "UnderworldGateStairUD"; break;
		case 7: result.second = "anon_1"; break;
		case 8: result.second = "anon_2"; break;
		case 9: result.second = "anon_3"; break;
		case 10: result.second = "anon_4"; break;
		case 11: result.second = "anon_5"; break;
		case 12: result.second = "anon_6"; break;
		case 13: result.second = "anon_7"; break;
		case 14: result.second = "anon_8"; break;
		case 15: result.second = "anon_9"; break;
		case 16: result.second = "anon_10"; break;
		case 17: result.second = "anon_11"; break;
		case 18: result.second = "anon_12"; break;
		case 19: result.second = "Driftwood"; break;
		case 20: result.second = "anon_13"; break;
		case 21: result.second = "anon_14"; break;
		case 22: result.second = "anon_15"; break;
		case 23: result.second = "anon_16"; break;
		case 24: result.second = "anon_17"; break;
		case 25: result.second = "FrozenStairUD"; break;
		case 26: result.second = "FrozenStairD"; break;
		case 27: result.second = "FrozenStairU"; break;
		case 28: result.second = "anon_18"; break;
		case 29: result.second = "anon_19"; break;
		case 30: result.second = "anon_20"; break;
		case 31: result.second = "anon_21"; break;
		case 32: result.second = "OpenSpace"; break;
		case 33: result.second = "anon_22"; break;
		case 34: result.second = "Shrub"; break;
		case 35: result.second = "Chasm"; break;
		case 36: result.second = "LavaStairUD"; break;
		case 37: result.second = "LavaStairD"; break;
		case 38: result.second = "LavaStairU"; break;
		case 39: result.second = "SoilStairUD"; break;
		case 40: result.second = "SoilStairD"; break;
		case 41: result.second = "SoilStairU"; break;
		case 42: result.second = "EeriePit"; break;
		case 43: result.second = "StoneFloorSmooth"; break;
		case 44: result.second = "LavaFloorSmooth"; break;
		case 45: result.second = "FeatureFloorSmooth"; break;
		case 46: result.second = "MineralFloorSmooth"; break;
		case 47: result.second = "FrozenFloorSmooth"; break;
		case 48: result.second = "anon_23"; break;
		case 49: result.second = "Grass1StairUD"; break;
		case 50: result.second = "Grass1StairD"; break;
		case 51: result.second = "Grass1StairU"; break;
		case 52: result.second = "Grass2StairUD"; break;
		case 53: result.second = "Grass2StairD"; break;
		case 54: result.second = "Grass2StairU"; break;
		case 55: result.second = "StoneStairUD"; break;
		case 56: result.second = "StoneStairD"; break;
		case 57: result.second = "StoneStairU"; break;
		case 58: result.second = "MineralStairUD"; break;
		case 59: result.second = "MineralStairD"; break;
		case 60: result.second = "MineralStairU"; break;
		case 61: result.second = "FeatureStairUD"; break;
		case 62: result.second = "FeatureStairD"; break;
		case 63: result.second = "FeatureStairU"; break;
		case 64: result.second = "anon_24"; break;
		case 65: result.second = "StoneFortification"; break;
		case 66: result.second = "anon_25"; break;
		case 67: result.second = "Campfire"; break;
		case 68: result.second = "anon_26"; break;
		case 69: result.second = "anon_27"; break;
		case 70: result.second = "Fire"; break;
		case 71: result.second = "BurningTreeTrunk"; break;
		case 72: result.second = "BurningTreeBranches"; break;
		case 73: result.second = "BurningTreeTwigs"; break;
		case 74: result.second = "BurningTreeCapWall"; break;
		case 75: result.second = "BurningTreeCapRamp"; break;
		case 76: result.second = "BurningTreeCapFloor"; break;
		case 77: result.second = "anon_28"; break;
		case 78: result.second = "anon_29"; break;
		case 79: result.second = "StonePillar"; break;
		case 80: result.second = "LavaPillar"; break;
		case 81: result.second = "FeaturePillar"; break;
		case 82: result.second = "MineralPillar"; break;
		case 83: result.second = "FrozenPillar"; break;
		case 84: result.second = "anon_30"; break;
		case 85: result.second = "anon_31"; break;
		case 86: result.second = "anon_32"; break;
		case 87: result.second = "anon_33"; break;
		case 88: result.second = "anon_34"; break;
		case 89: result.second = "Waterfall"; break;
		case 90: result.second = "RiverSource"; break;
		case 91: result.second = "TreeRootSloping"; break;
		case 92: result.second = "TreeRoots"; break;
		case 93: result.second = "TreeTrunkPillar"; break;
		case 94: result.second = "TreeTrunkSloping"; break;
		case 95: result.second = "TreeTrunkN"; break;
		case 96: result.second = "TreeTrunkS"; break;
		case 97: result.second = "TreeTrunkE"; break;
		case 98: result.second = "TreeTrunkW"; break;
		case 99: result.second = "TreeTrunkNW"; break;
		case 100: result.second = "TreeTrunkNE"; break;
		case 101: result.second = "TreeTrunkSW"; break;
		case 102: result.second = "TreeTrunkSE"; break;
		case 103: result.second = "TreeTrunkBranchN"; break;
		case 104: result.second = "TreeTrunkBranchS"; break;
		case 105: result.second = "TreeTrunkBranchE"; break;
		case 106: result.second = "TreeTrunkBranchW"; break;
		case 107: result.second = "TreeBranchNS"; break;
		case 108: result.second = "TreeBranchEW"; break;
		case 109: result.second = "TreeBranchesSmooth"; break;
		case 110: result.second = "TreeDeadBranchesSmooth"; break;
		case 111: result.second = "TreeBranchNW"; break;
		case 112: result.second = "TreeBranchNE"; break;
		case 113: result.second = "TreeBranchSW"; break;
		case 114: result.second = "TreeBranchSE"; break;
		case 115: result.second = "TreeBranches"; break;
		case 116: result.second = "TreeTwigs"; break;
		case 117: result.second = "TreeCapRamp"; break;
		case 118: result.second = "TreeCapPillar"; break;
		case 119: result.second = "TreeCapWallN"; break;
		case 120: result.second = "TreeCapWallS"; break;
		case 121: result.second = "TreeCapWallE"; break;
		case 122: result.second = "TreeCapWallW"; break;
		case 123: result.second = "TreeCapWallNW"; break;
		case 124: result.second = "TreeCapWallNE"; break;
		case 125: result.second = "TreeCapWallSW"; break;
		case 126: result.second = "TreeCapWallSE"; break;
		case 127: result.second = "TreeCapFloor1"; break;
		case 128: result.second = "TreeCapFloor2"; break;
		case 129: result.second = "TreeCapFloor3"; break;
		case 130: result.second = "TreeCapFloor4"; break;
		case 131: result.second = "TreeDeadRootSloping"; break;
		case 132: result.second = "TreeDeadRoots"; break;
		case 133: result.second = "TreeDeadTrunkPillar"; break;
		case 134: result.second = "TreeDeadTrunkSloping"; break;
		case 135: result.second = "TreeDeadTrunkN"; break;
		case 136: result.second = "TreeDeadTrunkS"; break;
		case 137: result.second = "TreeDeadTrunkE"; break;
		case 138: result.second = "TreeDeadTrunkW"; break;
		case 139: result.second = "TreeDeadTrunkNW"; break;
		case 140: result.second = "TreeDeadTrunkNE"; break;
		case 141: result.second = "TreeDeadTrunkSW"; break;
		case 142: result.second = "TreeDeadTrunkSE"; break;
		case 143: result.second = "TreeDeadTrunkBranchN"; break;
		case 144: result.second = "TreeDeadTrunkBranchS"; break;
		case 145: result.second = "TreeDeadTrunkBranchE"; break;
		case 146: result.second = "TreeDeadTrunkBranchW"; break;
		case 147: result.second = "TreeDeadBranchNS"; break;
		case 148: result.second = "TreeDeadBranchEW"; break;
		case 149: result.second = "anon_35"; break;
		case 150: result.second = "anon_36"; break;
		case 151: result.second = "TreeDeadBranchNW"; break;
		case 152: result.second = "TreeDeadBranchNE"; break;
		case 153: result.second = "TreeDeadBranchSW"; break;
		case 154: result.second = "TreeDeadBranchSE"; break;
		case 155: result.second = "TreeDeadBranches"; break;
		case 156: result.second = "TreeDeadTwigs"; break;
		case 157: result.second = "TreeDeadCapRamp"; break;
		case 158: result.second = "TreeDeadCapPillar"; break;
		case 159: result.second = "TreeDeadCapWallN"; break;
		case 160: result.second = "TreeDeadCapWallS"; break;
		case 161: result.second = "TreeDeadCapWallE"; break;
		case 162: result.second = "TreeDeadCapWallW"; break;
		case 163: result.second = "TreeDeadCapWallNW"; break;
		case 164: result.second = "TreeDeadCapWallNE"; break;
		case 165: result.second = "TreeDeadCapWallSW"; break;
		case 166: result.second = "TreeDeadCapWallSE"; break;
		case 167: result.second = "TreeDeadCapFloor1"; break;
		case 168: result.second = "TreeDeadCapFloor2"; break;
		case 169: result.second = "TreeDeadCapFloor3"; break;
		case 170: result.second = "TreeDeadCapFloor4"; break;
		case 171: result.second = "anon_37"; break;
		case 172: result.second = "StoneWallWorn1"; break;
		case 173: result.second = "StoneWallWorn2"; break;
		case 174: result.second = "StoneWallWorn3"; break;
		case 175: result.second = "TreeBranchNSE"; break;
		case 176: result.second = "TreeBranchNSW"; break;
		case 177: result.second = "TreeBranchNEW"; break;
		case 178: result.second = "TreeBranchSEW"; break;
		case 179: result.second = "TreeBranchNSEW"; break;
		case 180: result.second = "TreeDeadBranchNSE"; break;
		case 181: result.second = "TreeDeadBranchNSW"; break;
		case 182: result.second = "TreeDeadBranchNEW"; break;
		case 183: result.second = "TreeDeadBranchSEW"; break;
		case 184: result.second = "TreeDeadBranchNSEW"; break;
		case 185: result.second = "TreeTrunkNSE"; break;
		case 186: result.second = "TreeTrunkNSW"; break;
		case 187: result.second = "TreeTrunkNEW"; break;
		case 188: result.second = "TreeTrunkSEW"; break;
		case 189: result.second = "TreeTrunkNS"; break;
		case 190: result.second = "TreeTrunkEW"; break;
		case 191: result.second = "TreeTrunkNSEW"; break;
		case 192: result.second = "TreeTrunkInterior"; break;
		case 193: result.second = "TreeDeadTrunkNSE"; break;
		case 194: result.second = "TreeDeadTrunkNSW"; break;
		case 195: result.second = "TreeDeadTrunkNEW"; break;
		case 196: result.second = "TreeDeadTrunkSEW"; break;
		case 197: result.second = "TreeDeadTrunkNS"; break;
		case 198: result.second = "TreeDeadTrunkEW"; break;
		case 199: result.second = "TreeDeadTrunkNSEW"; break;
		case 200: result.second = "TreeDeadTrunkInterior"; break;
		case 201: result.second = "anon_38"; break;
		case 202: result.second = "anon_39"; break;
		case 203: result.second = "anon_40"; break;
		case 204: result.second = "anon_41"; break;
		case 205: result.second = "anon_42"; break;
		case 206: result.second = "anon_43"; break;
		case 207: result.second = "anon_44"; break;
		case 208: result.second = "anon_45"; break;
		case 209: result.second = "anon_46"; break;
		case 210: result.second = "anon_47"; break;
		case 211: result.second = "anon_48"; break;
		case 212: result.second = "anon_49"; break;
		case 213: result.second = "anon_50"; break;
		case 214: result.second = "anon_51"; break;
		case 215: result.second = "StoneWall"; break;
		case 216: result.second = "anon_52"; break;
		case 217: result.second = "anon_53"; break;
		case 218: result.second = "anon_54"; break;
		case 219: result.second = "anon_55"; break;
		case 220: result.second = "anon_56"; break;
		case 221: result.second = "anon_57"; break;
		case 222: result.second = "anon_58"; break;
		case 223: result.second = "anon_59"; break;
		case 224: result.second = "anon_60"; break;
		case 225: result.second = "anon_61"; break;
		case 226: result.second = "anon_62"; break;
		case 227: result.second = "Sapling"; break;
		case 228: result.second = "anon_63"; break;
		case 229: result.second = "GrassDryRamp"; break;
		case 230: result.second = "GrassDeadRamp"; break;
		case 231: result.second = "GrassLightRamp"; break;
		case 232: result.second = "GrassDarkRamp"; break;
		case 233: result.second = "StoneRamp"; break;
		case 234: result.second = "LavaRamp"; break;
		case 235: result.second = "FeatureRamp"; break;
		case 236: result.second = "MineralRamp"; break;
		case 237: result.second = "SoilRamp"; break;
		case 238: result.second = "Ashes1"; break;
		case 239: result.second = "Ashes2"; break;
		case 240: result.second = "Ashes3"; break;
		case 241: result.second = "FrozenRamp"; break;
		case 242: result.second = "anon_64"; break;
		case 243: result.second = "anon_65"; break;
		case 244: result.second = "anon_66"; break;
		case 245: result.second = "anon_67"; break;
		case 246: result.second = "anon_68"; break;
		case 247: result.second = "anon_69"; break;
		case 248: result.second = "anon_70"; break;
		case 249: result.second = "anon_71"; break;
		case 250: result.second = "anon_72"; break;
		case 251: result.second = "anon_73"; break;
		case 252: result.second = "anon_74"; break;
		case 253: result.second = "anon_75"; break;
		case 254: result.second = "FrozenFloor2"; break;
		case 255: result.second = "FrozenFloor3"; break;
		case 256: result.second = "FrozenFloor4"; break;
		case 257: result.second = "FurrowedSoil"; break;
		case 258: result.second = "FrozenFloor1"; break;
		case 259: result.second = "SemiMoltenRock"; break;
		case 260: result.second = "MagmaFlow"; break;
		case 261: result.second = "SoilWall"; break;
		case 262: result.second = "GlowingBarrier"; break;
		case 263: result.second = "GlowingFloor"; break;
		case 264: result.second = "anon_76"; break;
		case 265: result.second = "LavaWallSmoothRD2"; break;
		case 266: result.second = "LavaWallSmoothR2D"; break;
		case 267: result.second = "LavaWallSmoothR2U"; break;
		case 268: result.second = "LavaWallSmoothRU2"; break;
		case 269: result.second = "LavaWallSmoothL2U"; break;
		case 270: result.second = "LavaWallSmoothLU2"; break;
		case 271: result.second = "LavaWallSmoothL2D"; break;
		case 272: result.second = "LavaWallSmoothLD2"; break;
		case 273: result.second = "LavaWallSmoothLRUD"; break;
		case 274: result.second = "LavaWallSmoothRUD"; break;
		case 275: result.second = "LavaWallSmoothLRD"; break;
		case 276: result.second = "LavaWallSmoothLRU"; break;
		case 277: result.second = "LavaWallSmoothLUD"; break;
		case 278: result.second = "LavaWallSmoothRD"; break;
		case 279: result.second = "LavaWallSmoothRU"; break;
		case 280: result.second = "LavaWallSmoothLU"; break;
		case 281: result.second = "LavaWallSmoothLD"; break;
		case 282: result.second = "LavaWallSmoothUD"; break;
		case 283: result.second = "LavaWallSmoothLR"; break;
		case 284: result.second = "FeatureWallSmoothRD2"; break;
		case 285: result.second = "FeatureWallSmoothR2D"; break;
		case 286: result.second = "FeatureWallSmoothR2U"; break;
		case 287: result.second = "FeatureWallSmoothRU2"; break;
		case 288: result.second = "FeatureWallSmoothL2U"; break;
		case 289: result.second = "FeatureWallSmoothLU2"; break;
		case 290: result.second = "FeatureWallSmoothL2D"; break;
		case 291: result.second = "FeatureWallSmoothLD2"; break;
		case 292: result.second = "FeatureWallSmoothLRUD"; break;
		case 293: result.second = "FeatureWallSmoothRUD"; break;
		case 294: result.second = "FeatureWallSmoothLRD"; break;
		case 295: result.second = "FeatureWallSmoothLRU"; break;
		case 296: result.second = "FeatureWallSmoothLUD"; break;
		case 297: result.second = "FeatureWallSmoothRD"; break;
		case 298: result.second = "FeatureWallSmoothRU"; break;
		case 299: result.second = "FeatureWallSmoothLU"; break;
		case 300: result.second = "FeatureWallSmoothLD"; break;
		case 301: result.second = "FeatureWallSmoothUD"; break;
		case 302: result.second = "FeatureWallSmoothLR"; break;
		case 303: result.second = "StoneWallSmoothRD2"; break;
		case 304: result.second = "StoneWallSmoothR2D"; break;
		case 305: result.second = "StoneWallSmoothR2U"; break;
		case 306: result.second = "StoneWallSmoothRU2"; break;
		case 307: result.second = "StoneWallSmoothL2U"; break;
		case 308: result.second = "StoneWallSmoothLU2"; break;
		case 309: result.second = "StoneWallSmoothL2D"; break;
		case 310: result.second = "StoneWallSmoothLD2"; break;
		case 311: result.second = "StoneWallSmoothLRUD"; break;
		case 312: result.second = "StoneWallSmoothRUD"; break;
		case 313: result.second = "StoneWallSmoothLRD"; break;
		case 314: result.second = "StoneWallSmoothLRU"; break;
		case 315: result.second = "StoneWallSmoothLUD"; break;
		case 316: result.second = "StoneWallSmoothRD"; break;
		case 317: result.second = "StoneWallSmoothRU"; break;
		case 318: result.second = "StoneWallSmoothLU"; break;
		case 319: result.second = "StoneWallSmoothLD"; break;
		case 320: result.second = "StoneWallSmoothUD"; break;
		case 321: result.second = "StoneWallSmoothLR"; break;
		case 322: result.second = "LavaFortification"; break;
		case 323: result.second = "FeatureFortification"; break;
		case 324: result.second = "LavaWallWorn1"; break;
		case 325: result.second = "LavaWallWorn2"; break;
		case 326: result.second = "LavaWallWorn3"; break;
		case 327: result.second = "LavaWall"; break;
		case 328: result.second = "FeatureWallWorn1"; break;
		case 329: result.second = "FeatureWallWorn2"; break;
		case 330: result.second = "FeatureWallWorn3"; break;
		case 331: result.second = "FeatureWall"; break;
		case 332: result.second = "StoneFloor1"; break;
		case 333: result.second = "StoneFloor2"; break;
		case 334: result.second = "StoneFloor3"; break;
		case 335: result.second = "StoneFloor4"; break;
		case 336: result.second = "LavaFloor1"; break;
		case 337: result.second = "LavaFloor2"; break;
		case 338: result.second = "LavaFloor3"; break;
		case 339: result.second = "LavaFloor4"; break;
		case 340: result.second = "FeatureFloor1"; break;
		case 341: result.second = "FeatureFloor2"; break;
		case 342: result.second = "FeatureFloor3"; break;
		case 343: result.second = "FeatureFloor4"; break;
		case 344: result.second = "GrassDarkFloor1"; break;
		case 345: result.second = "GrassDarkFloor2"; break;
		case 346: result.second = "GrassDarkFloor3"; break;
		case 347: result.second = "GrassDarkFloor4"; break;
		case 348: result.second = "SoilFloor1"; break;
		case 349: result.second = "SoilFloor2"; break;
		case 350: result.second = "SoilFloor3"; break;
		case 351: result.second = "SoilFloor4"; break;
		case 352: result.second = "SoilWetFloor1"; break;
		case 353: result.second = "SoilWetFloor2"; break;
		case 354: result.second = "SoilWetFloor3"; break;
		case 355: result.second = "SoilWetFloor4"; break;
		case 356: result.second = "FrozenFortification"; break;
		case 357: result.second = "FrozenWallWorn1"; break;
		case 358: result.second = "FrozenWallWorn2"; break;
		case 359: result.second = "FrozenWallWorn3"; break;
		case 360: result.second = "FrozenWall"; break;
		case 361: result.second = "RiverN"; break;
		case 362: result.second = "RiverS"; break;
		case 363: result.second = "RiverE"; break;
		case 364: result.second = "RiverW"; break;
		case 365: result.second = "RiverNW"; break;
		case 366: result.second = "RiverNE"; break;
		case 367: result.second = "RiverSW"; break;
		case 368: result.second = "RiverSE"; break;
		case 369: result.second = "BrookN"; break;
		case 370: result.second = "BrookS"; break;
		case 371: result.second = "BrookE"; break;
		case 372: result.second = "BrookW"; break;
		case 373: result.second = "BrookNW"; break;
		case 374: result.second = "BrookNE"; break;
		case 375: result.second = "BrookSW"; break;
		case 376: result.second = "BrookSE"; break;
		case 377: result.second = "BrookTop"; break;
		case 378: result.second = "anon_77"; break;
		case 379: result.second = "anon_78"; break;
		case 380: result.second = "anon_79"; break;
		case 381: result.second = "anon_80"; break;
		case 382: result.second = "anon_81"; break;
		case 383: result.second = "GrassDryFloor1"; break;
		case 384: result.second = "GrassDryFloor2"; break;
		case 385: result.second = "GrassDryFloor3"; break;
		case 386: result.second = "GrassDryFloor4"; break;
		case 387: result.second = "anon_82"; break;
		case 388: result.second = "SaplingDead"; break;
		case 389: result.second = "ShrubDead"; break;
		case 390: result.second = "GrassDeadFloor1"; break;
		case 391: result.second = "GrassDeadFloor2"; break;
		case 392: result.second = "GrassDeadFloor3"; break;
		case 393: result.second = "GrassDeadFloor4"; break;
		case 394: result.second = "GrassLightFloor1"; break;
		case 395: result.second = "GrassLightFloor2"; break;
		case 396: result.second = "GrassLightFloor3"; break;
		case 397: result.second = "GrassLightFloor4"; break;
		case 398: result.second = "StoneBoulder"; break;
		case 399: result.second = "LavaBoulder"; break;
		case 400: result.second = "FeatureBoulder"; break;
		case 401: result.second = "StonePebbles1"; break;
		case 402: result.second = "StonePebbles2"; break;
		case 403: result.second = "StonePebbles3"; break;
		case 404: result.second = "StonePebbles4"; break;
		case 405: result.second = "LavaPebbles1"; break;
		case 406: result.second = "LavaPebbles2"; break;
		case 407: result.second = "LavaPebbles3"; break;
		case 408: result.second = "LavaPebbles4"; break;
		case 409: result.second = "FeaturePebbles1"; break;
		case 410: result.second = "FeaturePebbles2"; break;
		case 411: result.second = "FeaturePebbles3"; break;
		case 412: result.second = "FeaturePebbles4"; break;
		case 413: result.second = "MineralWallSmoothRD2"; break;
		case 414: result.second = "MineralWallSmoothR2D"; break;
		case 415: result.second = "MineralWallSmoothR2U"; break;
		case 416: result.second = "MineralWallSmoothRU2"; break;
		case 417: result.second = "MineralWallSmoothL2U"; break;
		case 418: result.second = "MineralWallSmoothLU2"; break;
		case 419: result.second = "MineralWallSmoothL2D"; break;
		case 420: result.second = "MineralWallSmoothLD2"; break;
		case 421: result.second = "MineralWallSmoothLRUD"; break;
		case 422: result.second = "MineralWallSmoothRUD"; break;
		case 423: result.second = "MineralWallSmoothLRD"; break;
		case 424: result.second = "MineralWallSmoothLRU"; break;
		case 425: result.second = "MineralWallSmoothLUD"; break;
		case 426: result.second = "MineralWallSmoothRD"; break;
		case 427: result.second = "MineralWallSmoothRU"; break;
		case 428: result.second = "MineralWallSmoothLU"; break;
		case 429: result.second = "MineralWallSmoothLD"; break;
		case 430: result.second = "MineralWallSmoothUD"; break;
		case 431: result.second = "MineralWallSmoothLR"; break;
		case 432: result.second = "MineralFortification"; break;
		case 433: result.second = "MineralWallWorn1"; break;
		case 434: result.second = "MineralWallWorn2"; break;
		case 435: result.second = "MineralWallWorn3"; break;
		case 436: result.second = "MineralWall"; break;
		case 437: result.second = "MineralFloor1"; break;
		case 438: result.second = "MineralFloor2"; break;
		case 439: result.second = "MineralFloor3"; break;
		case 440: result.second = "MineralFloor4"; break;
		case 441: result.second = "MineralBoulder"; break;
		case 442: result.second = "MineralPebbles1"; break;
		case 443: result.second = "MineralPebbles2"; break;
		case 444: result.second = "MineralPebbles3"; break;
		case 445: result.second = "MineralPebbles4"; break;
		case 446: result.second = "FrozenWallSmoothRD2"; break;
		case 447: result.second = "FrozenWallSmoothR2D"; break;
		case 448: result.second = "FrozenWallSmoothR2U"; break;
		case 449: result.second = "FrozenWallSmoothRU2"; break;
		case 450: result.second = "FrozenWallSmoothL2U"; break;
		case 451: result.second = "FrozenWallSmoothLU2"; break;
		case 452: result.second = "FrozenWallSmoothL2D"; break;
		case 453: result.second = "FrozenWallSmoothLD2"; break;
		case 454: result.second = "FrozenWallSmoothLRUD"; break;
		case 455: result.second = "FrozenWallSmoothRUD"; break;
		case 456: result.second = "FrozenWallSmoothLRD"; break;
		case 457: result.second = "FrozenWallSmoothLRU"; break;
		case 458: result.second = "FrozenWallSmoothLUD"; break;
		case 459: result.second = "FrozenWallSmoothRD"; break;
		case 460: result.second = "FrozenWallSmoothRU"; break;
		case 461: result.second = "FrozenWallSmoothLU"; break;
		case 462: result.second = "FrozenWallSmoothLD"; break;
		case 463: result.second = "FrozenWallSmoothUD"; break;
		case 464: result.second = "FrozenWallSmoothLR"; break;
		case 465: result.second = "RiverRampN"; break;
		case 466: result.second = "RiverRampS"; break;
		case 467: result.second = "RiverRampE"; break;
		case 468: result.second = "RiverRampW"; break;
		case 469: result.second = "RiverRampNW"; break;
		case 470: result.second = "RiverRampNE"; break;
		case 471: result.second = "RiverRampSW"; break;
		case 472: result.second = "RiverRampSE"; break;
		case 473: result.second = "anon_83"; break;
		case 474: result.second = "anon_84"; break;
		case 475: result.second = "anon_85"; break;
		case 476: result.second = "anon_86"; break;
		case 477: result.second = "anon_87"; break;
		case 478: result.second = "anon_88"; break;
		case 479: result.second = "anon_89"; break;
		case 480: result.second = "anon_90"; break;
		case 481: result.second = "anon_91"; break;
		case 482: result.second = "anon_92"; break;
		case 483: result.second = "anon_93"; break;
		case 484: result.second = "anon_94"; break;
		case 485: result.second = "anon_95"; break;
		case 486: result.second = "anon_96"; break;
		case 487: result.second = "anon_97"; break;
		case 488: result.second = "anon_98"; break;
		case 489: result.second = "ConstructedFloor"; break;
		case 490: result.second = "ConstructedFortification"; break;
		case 491: result.second = "ConstructedPillar"; break;
		case 492: result.second = "ConstructedWallRD2"; break;
		case 493: result.second = "ConstructedWallR2D"; break;
		case 494: result.second = "ConstructedWallR2U"; break;
		case 495: result.second = "ConstructedWallRU2"; break;
		case 496: result.second = "ConstructedWallL2U"; break;
		case 497: result.second = "ConstructedWallLU2"; break;
		case 498: result.second = "ConstructedWallL2D"; break;
		case 499: result.second = "ConstructedWallLD2"; break;
		case 500: result.second = "ConstructedWallLRUD"; break;
		case 501: result.second = "ConstructedWallRUD"; break;
		case 502: result.second = "ConstructedWallLRD"; break;
		case 503: result.second = "ConstructedWallLRU"; break;
		case 504: result.second = "ConstructedWallLUD"; break;
		case 505: result.second = "ConstructedWallRD"; break;
		case 506: result.second = "ConstructedWallRU"; break;
		case 507: result.second = "ConstructedWallLU"; break;
		case 508: result.second = "ConstructedWallLD"; break;
		case 509: result.second = "ConstructedWallUD"; break;
		case 510: result.second = "ConstructedWallLR"; break;
		case 511: result.second = "ConstructedStairUD"; break;
		case 512: result.second = "ConstructedStairD"; break;
		case 513: result.second = "ConstructedStairU"; break;
		case 514: result.second = "ConstructedRamp"; break;
		case 515: result.second = "StoneFloorTrackN"; break;
		case 516: result.second = "StoneFloorTrackS"; break;
		case 517: result.second = "StoneFloorTrackE"; break;
		case 518: result.second = "StoneFloorTrackW"; break;
		case 519: result.second = "StoneFloorTrackNS"; break;
		case 520: result.second = "StoneFloorTrackNE"; break;
		case 521: result.second = "StoneFloorTrackNW"; break;
		case 522: result.second = "StoneFloorTrackSE"; break;
		case 523: result.second = "StoneFloorTrackSW"; break;
		case 524: result.second = "StoneFloorTrackEW"; break;
		case 525: result.second = "StoneFloorTrackNSE"; break;
		case 526: result.second = "StoneFloorTrackNSW"; break;
		case 527: result.second = "StoneFloorTrackNEW"; break;
		case 528: result.second = "StoneFloorTrackSEW"; break;
		case 529: result.second = "StoneFloorTrackNSEW"; break;
		case 530: result.second = "LavaFloorTrackN"; break;
		case 531: result.second = "LavaFloorTrackS"; break;
		case 532: result.second = "LavaFloorTrackE"; break;
		case 533: result.second = "LavaFloorTrackW"; break;
		case 534: result.second = "LavaFloorTrackNS"; break;
		case 535: result.second = "LavaFloorTrackNE"; break;
		case 536: result.second = "LavaFloorTrackNW"; break;
		case 537: result.second = "LavaFloorTrackSE"; break;
		case 538: result.second = "LavaFloorTrackSW"; break;
		case 539: result.second = "LavaFloorTrackEW"; break;
		case 540: result.second = "LavaFloorTrackNSE"; break;
		case 541: result.second = "LavaFloorTrackNSW"; break;
		case 542: result.second = "LavaFloorTrackNEW"; break;
		case 543: result.second = "LavaFloorTrackSEW"; break;
		case 544: result.second = "LavaFloorTrackNSEW"; break;
		case 545: result.second = "FeatureFloorTrackN"; break;
		case 546: result.second = "FeatureFloorTrackS"; break;
		case 547: result.second = "FeatureFloorTrackE"; break;
		case 548: result.second = "FeatureFloorTrackW"; break;
		case 549: result.second = "FeatureFloorTrackNS"; break;
		case 550: result.second = "FeatureFloorTrackNE"; break;
		case 551: result.second = "FeatureFloorTrackNW"; break;
		case 552: result.second = "FeatureFloorTrackSE"; break;
		case 553: result.second = "FeatureFloorTrackSW"; break;
		case 554: result.second = "FeatureFloorTrackEW"; break;
		case 555: result.second = "FeatureFloorTrackNSE"; break;
		case 556: result.second = "FeatureFloorTrackNSW"; break;
		case 557: result.second = "FeatureFloorTrackNEW"; break;
		case 558: result.second = "FeatureFloorTrackSEW"; break;
		case 559: result.second = "FeatureFloorTrackNSEW"; break;
		case 560: result.second = "MineralFloorTrackN"; break;
		case 561: result.second = "MineralFloorTrackS"; break;
		case 562: result.second = "MineralFloorTrackE"; break;
		case 563: result.second = "MineralFloorTrackW"; break;
		case 564: result.second = "MineralFloorTrackNS"; break;
		case 565: result.second = "MineralFloorTrackNE"; break;
		case 566: result.second = "MineralFloorTrackNW"; break;
		case 567: result.second = "MineralFloorTrackSE"; break;
		case 568: result.second = "MineralFloorTrackSW"; break;
		case 569: result.second = "MineralFloorTrackEW"; break;
		case 570: result.second = "MineralFloorTrackNSE"; break;
		case 571: result.second = "MineralFloorTrackNSW"; break;
		case 572: result.second = "MineralFloorTrackNEW"; break;
		case 573: result.second = "MineralFloorTrackSEW"; break;
		case 574: result.second = "MineralFloorTrackNSEW"; break;
		case 575: result.second = "FrozenFloorTrackN"; break;
		case 576: result.second = "FrozenFloorTrackS"; break;
		case 577: result.second = "FrozenFloorTrackE"; break;
		case 578: result.second = "FrozenFloorTrackW"; break;
		case 579: result.second = "FrozenFloorTrackNS"; break;
		case 580: result.second = "FrozenFloorTrackNE"; break;
		case 581: result.second = "FrozenFloorTrackNW"; break;
		case 582: result.second = "FrozenFloorTrackSE"; break;
		case 583: result.second = "FrozenFloorTrackSW"; break;
		case 584: result.second = "FrozenFloorTrackEW"; break;
		case 585: result.second = "FrozenFloorTrackNSE"; break;
		case 586: result.second = "FrozenFloorTrackNSW"; break;
		case 587: result.second = "FrozenFloorTrackNEW"; break;
		case 588: result.second = "FrozenFloorTrackSEW"; break;
		case 589: result.second = "FrozenFloorTrackNSEW"; break;
		case 590: result.second = "ConstructedFloorTrackN"; break;
		case 591: result.second = "ConstructedFloorTrackS"; break;
		case 592: result.second = "ConstructedFloorTrackE"; break;
		case 593: result.second = "ConstructedFloorTrackW"; break;
		case 594: result.second = "ConstructedFloorTrackNS"; break;
		case 595: result.second = "ConstructedFloorTrackNE"; break;
		case 596: result.second = "ConstructedFloorTrackNW"; break;
		case 597: result.second = "ConstructedFloorTrackSE"; break;
		case 598: result.second = "ConstructedFloorTrackSW"; break;
		case 599: result.second = "ConstructedFloorTrackEW"; break;
		case 600: result.second = "ConstructedFloorTrackNSE"; break;
		case 601: result.second = "ConstructedFloorTrackNSW"; break;
		case 602: result.second = "ConstructedFloorTrackNEW"; break;
		case 603: result.second = "ConstructedFloorTrackSEW"; break;
		case 604: result.second = "ConstructedFloorTrackNSEW"; break;
		case 605: result.second = "StoneRampTrackN"; break;
		case 606: result.second = "StoneRampTrackS"; break;
		case 607: result.second = "StoneRampTrackE"; break;
		case 608: result.second = "StoneRampTrackW"; break;
		case 609: result.second = "StoneRampTrackNS"; break;
		case 610: result.second = "StoneRampTrackNE"; break;
		case 611: result.second = "StoneRampTrackNW"; break;
		case 612: result.second = "StoneRampTrackSE"; break;
		case 613: result.second = "StoneRampTrackSW"; break;
		case 614: result.second = "StoneRampTrackEW"; break;
		case 615: result.second = "StoneRampTrackNSE"; break;
		case 616: result.second = "StoneRampTrackNSW"; break;
		case 617: result.second = "StoneRampTrackNEW"; break;
		case 618: result.second = "StoneRampTrackSEW"; break;
		case 619: result.second = "StoneRampTrackNSEW"; break;
		case 620: result.second = "LavaRampTrackN"; break;
		case 621: result.second = "LavaRampTrackS"; break;
		case 622: result.second = "LavaRampTrackE"; break;
		case 623: result.second = "LavaRampTrackW"; break;
		case 624: result.second = "LavaRampTrackNS"; break;
		case 625: result.second = "LavaRampTrackNE"; break;
		case 626: result.second = "LavaRampTrackNW"; break;
		case 627: result.second = "LavaRampTrackSE"; break;
		case 628: result.second = "LavaRampTrackSW"; break;
		case 629: result.second = "LavaRampTrackEW"; break;
		case 630: result.second = "LavaRampTrackNSE"; break;
		case 631: result.second = "LavaRampTrackNSW"; break;
		case 632: result.second = "LavaRampTrackNEW"; break;
		case 633: result.second = "LavaRampTrackSEW"; break;
		case 634: result.second = "LavaRampTrackNSEW"; break;
		case 635: result.second = "FeatureRampTrackN"; break;
		case 636: result.second = "FeatureRampTrackS"; break;
		case 637: result.second = "FeatureRampTrackE"; break;
		case 638: result.second = "FeatureRampTrackW"; break;
		case 639: result.second = "FeatureRampTrackNS"; break;
		case 640: result.second = "FeatureRampTrackNE"; break;
		case 641: result.second = "FeatureRampTrackNW"; break;
		case 642: result.second = "FeatureRampTrackSE"; break;
		case 643: result.second = "FeatureRampTrackSW"; break;
		case 644: result.second = "FeatureRampTrackEW"; break;
		case 645: result.second = "FeatureRampTrackNSE"; break;
		case 646: result.second = "FeatureRampTrackNSW"; break;
		case 647: result.second = "FeatureRampTrackNEW"; break;
		case 648: result.second = "FeatureRampTrackSEW"; break;
		case 649: result.second = "FeatureRampTrackNSEW"; break;
		case 650: result.second = "MineralRampTrackN"; break;
		case 651: result.second = "MineralRampTrackS"; break;
		case 652: result.second = "MineralRampTrackE"; break;
		case 653: result.second = "MineralRampTrackW"; break;
		case 654: result.second = "MineralRampTrackNS"; break;
		case 655: result.second = "MineralRampTrackNE"; break;
		case 656: result.second = "MineralRampTrackNW"; break;
		case 657: result.second = "MineralRampTrackSE"; break;
		case 658: result.second = "MineralRampTrackSW"; break;
		case 659: result.second = "MineralRampTrackEW"; break;
		case 660: result.second = "MineralRampTrackNSE"; break;
		case 661: result.second = "MineralRampTrackNSW"; break;
		case 662: result.second = "MineralRampTrackNEW"; break;
		case 663: result.second = "MineralRampTrackSEW"; break;
		case 664: result.second = "MineralRampTrackNSEW"; break;
		case 665: result.second = "FrozenRampTrackN"; break;
		case 666: result.second = "FrozenRampTrackS"; break;
		case 667: result.second = "FrozenRampTrackE"; break;
		case 668: result.second = "FrozenRampTrackW"; break;
		case 669: result.second = "FrozenRampTrackNS"; break;
		case 670: result.second = "FrozenRampTrackNE"; break;
		case 671: result.second = "FrozenRampTrackNW"; break;
		case 672: result.second = "FrozenRampTrackSE"; break;
		case 673: result.second = "FrozenRampTrackSW"; break;
		case 674: result.second = "FrozenRampTrackEW"; break;
		case 675: result.second = "FrozenRampTrackNSE"; break;
		case 676: result.second = "FrozenRampTrackNSW"; break;
		case 677: result.second = "FrozenRampTrackNEW"; break;
		case 678: result.second = "FrozenRampTrackSEW"; break;
		case 679: result.second = "FrozenRampTrackNSEW"; break;
		case 680: result.second = "ConstructedRampTrackN"; break;
		case 681: result.second = "ConstructedRampTrackS"; break;
		case 682: result.second = "ConstructedRampTrackE"; break;
		case 683: result.second = "ConstructedRampTrackW"; break;
		case 684: result.second = "ConstructedRampTrackNS"; break;
		case 685: result.second = "ConstructedRampTrackNE"; break;
		case 686: result.second = "ConstructedRampTrackNW"; break;
		case 687: result.second = "ConstructedRampTrackSE"; break;
		case 688: result.second = "ConstructedRampTrackSW"; break;
		case 689: result.second = "ConstructedRampTrackEW"; break;
		case 690: result.second = "ConstructedRampTrackNSE"; break;
		case 691: result.second = "ConstructedRampTrackNSW"; break;
		case 692: result.second = "ConstructedRampTrackNEW"; break;
		case 693: result.second = "ConstructedRampTrackSEW"; break;
		case 694: result.second = "ConstructedRampTrackNSEW"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_build_req_choice_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "General"; break;
		case 1: result.second = "Specific"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_hotkey__T_cmd_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Zoom"; break;
		case 1: result.second = "FollowUnit"; break;
		case 2: result.second = "FollowItem"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_sidebar_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Default"; break;
		case 1: result.second = "Squads"; break;
		case 2: result.second = "DesignateMine"; break;
		case 3: result.second = "DesignateRemoveRamps"; break;
		case 4: result.second = "DesignateUpStair"; break;
		case 5: result.second = "DesignateDownStair"; break;
		case 6: result.second = "DesignateUpDownStair"; break;
		case 7: result.second = "DesignateUpRamp"; break;
		case 8: result.second = "DesignateChannel"; break;
		case 9: result.second = "DesignateGatherPlants"; break;
		case 10: result.second = "DesignateRemoveDesignation"; break;
		case 11: result.second = "DesignateSmooth"; break;
		case 12: result.second = "DesignateCarveTrack"; break;
		case 13: result.second = "DesignateEngrave"; break;
		case 14: result.second = "DesignateCarveFortification"; break;
		case 15: result.second = "Stockpiles"; break;
		case 16: result.second = "Build"; break;
		case 17: result.second = "QueryBuilding"; break;
		case 18: result.second = "Orders"; break;
		case 19: result.second = "OrdersForbid"; break;
		case 20: result.second = "OrdersRefuse"; break;
		case 21: result.second = "OrdersWorkshop"; break;
		case 22: result.second = "OrdersZone"; break;
		case 23: result.second = "BuildingItems"; break;
		case 24: result.second = "ViewUnits"; break;
		case 25: result.second = "LookAround"; break;
		case 26: result.second = "DesignateItemsClaim"; break;
		case 27: result.second = "DesignateItemsForbid"; break;
		case 28: result.second = "DesignateItemsMelt"; break;
		case 29: result.second = "DesignateItemsUnmelt"; break;
		case 30: result.second = "DesignateItemsDump"; break;
		case 31: result.second = "DesignateItemsUndump"; break;
		case 32: result.second = "DesignateItemsHide"; break;
		case 33: result.second = "DesignateItemsUnhide"; break;
		case 34: result.second = "DesignateChopTrees"; break;
		case 35: result.second = "DesignateToggleEngravings"; break;
		case 36: result.second = "DesignateToggleMarker"; break;
		case 37: result.second = "Hotkeys"; break;
		case 38: result.second = "DesignateTrafficHigh"; break;
		case 39: result.second = "DesignateTrafficNormal"; break;
		case 40: result.second = "DesignateTrafficLow"; break;
		case 41: result.second = "DesignateTrafficRestricted"; break;
		case 42: result.second = "Zones"; break;
		case 43: result.second = "ZonesPenInfo"; break;
		case 44: result.second = "ZonesPitInfo"; break;
		case 45: result.second = "ZonesHospitalInfo"; break;
		case 46: result.second = "ZonesGatherInfo"; break;
		case 47: result.second = "DesignateRemoveConstruction"; break;
		case 48: result.second = "DepotAccess"; break;
		case 49: result.second = "NotesPoints"; break;
		case 50: result.second = "NotesRoutes"; break;
		case 51: result.second = "Burrows"; break;
		case 52: result.second = "Hauling"; break;
		case 53: result.second = "ArenaWeather"; break;
		case 54: result.second = "ArenaTrees"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_kitchen_exc_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 1: result.second = "Cook"; break;
		case 2: result.second = "Brew"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_timed_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Caravan"; break;
		case 1: result.second = "Migrants"; break;
		case 2: result.second = "Diplomat"; break;
		case 3: result.second = "FeatureAttack"; break;
		case 4: result.second = "Megabeast"; break;
		case 5: result.second = "WildlifeCurious"; break;
		case 6: result.second = "WildlifeMischievous"; break;
		case 7: result.second = "WildlifeFlier"; break;
		case 8: result.second = "NightCreature"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_emotion_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "ANYTHING"; break;
		case 0: result.second = "ACCEPTANCE"; break;
		case 1: result.second = "ADORATION"; break;
		case 2: result.second = "AFFECTION"; break;
		case 3: result.second = "AGITATION"; break;
		case 4: result.second = "AGGRAVATION"; break;
		case 5: result.second = "AGONY"; break;
		case 6: result.second = "ALARM"; break;
		case 7: result.second = "ALIENATION"; break;
		case 8: result.second = "AMAZEMENT"; break;
		case 9: result.second = "AMBIVALENCE"; break;
		case 10: result.second = "AMUSEMENT"; break;
		case 11: result.second = "ANGER"; break;
		case 12: result.second = "ANGST"; break;
		case 13: result.second = "ANGUISH"; break;
		case 14: result.second = "ANNOYANCE"; break;
		case 15: result.second = "anon_1"; break;
		case 16: result.second = "ANXIETY"; break;
		case 17: result.second = "APATHY"; break;
		case 18: result.second = "anon_2"; break;
		case 19: result.second = "AROUSAL"; break;
		case 20: result.second = "ASTONISHMENT"; break;
		case 21: result.second = "anon_3"; break;
		case 22: result.second = "AVERSION"; break;
		case 23: result.second = "AWE"; break;
		case 24: result.second = "BITTERNESS"; break;
		case 25: result.second = "BLISS"; break;
		case 26: result.second = "BOREDOM"; break;
		case 27: result.second = "CARING"; break;
		case 28: result.second = "anon_4"; break;
		case 29: result.second = "CONFUSION"; break;
		case 30: result.second = "CONTEMPT"; break;
		case 31: result.second = "CONTENTMENT"; break;
		case 32: result.second = "anon_5"; break;
		case 33: result.second = "anon_6"; break;
		case 34: result.second = "DEFEAT"; break;
		case 35: result.second = "DEJECTION"; break;
		case 36: result.second = "DELIGHT"; break;
		case 37: result.second = "anon_7"; break;
		case 38: result.second = "anon_8"; break;
		case 39: result.second = "DESPAIR"; break;
		case 40: result.second = "DISAPPOINTMENT"; break;
		case 41: result.second = "DISGUST"; break;
		case 42: result.second = "DISILLUSIONMENT"; break;
		case 43: result.second = "DISLIKE"; break;
		case 44: result.second = "DISMAY"; break;
		case 45: result.second = "DISPLEASURE"; break;
		case 46: result.second = "DISTRESS"; break;
		case 47: result.second = "DOUBT"; break;
		case 48: result.second = "anon_9"; break;
		case 49: result.second = "EAGERNESS"; break;
		case 50: result.second = "anon_10"; break;
		case 51: result.second = "ELATION"; break;
		case 52: result.second = "EMBARRASSMENT"; break;
		case 53: result.second = "EMPATHY"; break;
		case 54: result.second = "EMPTINESS"; break;
		case 55: result.second = "ENJOYMENT"; break;
		case 56: result.second = "anon_11"; break;
		case 57: result.second = "ENTHUSIASM"; break;
		case 58: result.second = "anon_12"; break;
		case 59: result.second = "EUPHORIA"; break;
		case 60: result.second = "EXASPERATION"; break;
		case 61: result.second = "EXCITEMENT"; break;
		case 62: result.second = "EXHILARATION"; break;
		case 63: result.second = "EXPECTANCY"; break;
		case 64: result.second = "FEAR"; break;
		case 65: result.second = "FEROCITY"; break;
		case 66: result.second = "FONDNESS"; break;
		case 67: result.second = "FREEDOM"; break;
		case 68: result.second = "FRIGHT"; break;
		case 69: result.second = "FRUSTRATION"; break;
		case 70: result.second = "anon_13"; break;
		case 71: result.second = "GAIETY"; break;
		case 72: result.second = "anon_14"; break;
		case 73: result.second = "GLEE"; break;
		case 74: result.second = "GLOOM"; break;
		case 75: result.second = "GLUMNESS"; break;
		case 76: result.second = "GRATITUDE"; break;
		case 77: result.second = "anon_15"; break;
		case 78: result.second = "GRIEF"; break;
		case 79: result.second = "GRIM_SATISFACTION"; break;
		case 80: result.second = "GROUCHINESS"; break;
		case 81: result.second = "GRUMPINESS"; break;
		case 82: result.second = "GUILT"; break;
		case 83: result.second = "HAPPINESS"; break;
		case 84: result.second = "HATRED"; break;
		case 85: result.second = "anon_16"; break;
		case 86: result.second = "HOPE"; break;
		case 87: result.second = "HOPELESSNESS"; break;
		case 88: result.second = "HORROR"; break;
		case 89: result.second = "anon_17"; break;
		case 90: result.second = "HUMILIATION"; break;
		case 91: result.second = "anon_18"; break;
		case 92: result.second = "anon_19"; break;
		case 93: result.second = "anon_20"; break;
		case 94: result.second = "anon_21"; break;
		case 95: result.second = "INSULT"; break;
		case 96: result.second = "INTEREST"; break;
		case 97: result.second = "IRRITATION"; break;
		case 98: result.second = "ISOLATION"; break;
		case 99: result.second = "anon_22"; break;
		case 100: result.second = "JOLLINESS"; break;
		case 101: result.second = "JOVIALITY"; break;
		case 102: result.second = "JOY"; break;
		case 103: result.second = "JUBILATION"; break;
		case 104: result.second = "anon_23"; break;
		case 105: result.second = "LOATHING"; break;
		case 106: result.second = "LONELINESS"; break;
		case 107: result.second = "anon_24"; break;
		case 108: result.second = "LOVE"; break;
		case 109: result.second = "anon_25"; break;
		case 110: result.second = "LUST"; break;
		case 111: result.second = "anon_26"; break;
		case 112: result.second = "MISERY"; break;
		case 113: result.second = "MORTIFICATION"; break;
		case 114: result.second = "anon_27"; break;
		case 115: result.second = "NERVOUSNESS"; break;
		case 116: result.second = "NOSTALGIA"; break;
		case 117: result.second = "OPTIMISM"; break;
		case 118: result.second = "OUTRAGE"; break;
		case 119: result.second = "PANIC"; break;
		case 120: result.second = "PATIENCE"; break;
		case 121: result.second = "PASSION"; break;
		case 122: result.second = "PESSIMISM"; break;
		case 123: result.second = "anon_28"; break;
		case 124: result.second = "PLEASURE"; break;
		case 125: result.second = "PRIDE"; break;
		case 126: result.second = "RAGE"; break;
		case 127: result.second = "RAPTURE"; break;
		case 128: result.second = "REJECTION"; break;
		case 129: result.second = "RELIEF"; break;
		case 130: result.second = "REGRET"; break;
		case 131: result.second = "REMORSE"; break;
		case 132: result.second = "REPENTANCE"; break;
		case 133: result.second = "RESENTMENT"; break;
		case 134: result.second = "anon_29"; break;
		case 135: result.second = "RIGHTEOUS_INDIGNATION"; break;
		case 136: result.second = "SADNESS"; break;
		case 137: result.second = "SATISFACTION"; break;
		case 138: result.second = "anon_30"; break;
		case 139: result.second = "SELF_PITY"; break;
		case 140: result.second = "anon_31"; break;
		case 141: result.second = "SERVILE"; break;
		case 142: result.second = "SHAKEN"; break;
		case 143: result.second = "SHAME"; break;
		case 144: result.second = "SHOCK"; break;
		case 145: result.second = "anon_32"; break;
		case 146: result.second = "anon_33"; break;
		case 147: result.second = "anon_34"; break;
		case 148: result.second = "anon_35"; break;
		case 149: result.second = "SUSPICION"; break;
		case 150: result.second = "SYMPATHY"; break;
		case 151: result.second = "TENDERNESS"; break;
		case 152: result.second = "anon_36"; break;
		case 153: result.second = "TERROR"; break;
		case 154: result.second = "THRILL"; break;
		case 155: result.second = "anon_37"; break;
		case 156: result.second = "TRIUMPH"; break;
		case 157: result.second = "UNEASINESS"; break;
		case 158: result.second = "UNHAPPINESS"; break;
		case 159: result.second = "VENGEFULNESS"; break;
		case 160: result.second = "anon_38"; break;
		case 161: result.second = "WONDER"; break;
		case 162: result.second = "WORRY"; break;
		case 163: result.second = "WRATH"; break;
		case 164: result.second = "ZEAL"; break;
		case 165: result.second = "anon_39"; break;
		case 166: result.second = "anon_40"; break;
		case 167: result.second = "anon_41"; break;
		case 168: result.second = "RESTLESS"; break;
		case 169: result.second = "ADMIRATION"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_thought_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Conflict"; break;
		case 1: result.second = "Trauma"; break;
		case 2: result.second = "WitnessDeath"; break;
		case 3: result.second = "UnexpectedDeath"; break;
		case 4: result.second = "Death"; break;
		case 5: result.second = "Kill"; break;
		case 6: result.second = "LoveSeparated"; break;
		case 7: result.second = "LoveReunited"; break;
		case 8: result.second = "JoinConflict"; break;
		case 9: result.second = "MakeMasterwork"; break;
		case 10: result.second = "MadeArtifact"; break;
		case 11: result.second = "MasterSkill"; break;
		case 12: result.second = "NewRomance"; break;
		case 13: result.second = "BecomeParent"; break;
		case 14: result.second = "NearConflict"; break;
		case 15: result.second = "CancelAgreement"; break;
		case 16: result.second = "JoinTravel"; break;
		case 17: result.second = "SiteControlled"; break;
		case 18: result.second = "TributeCancel"; break;
		case 19: result.second = "Incident"; break;
		case 20: result.second = "HearRumor"; break;
		case 21: result.second = "MilitaryRemoved"; break;
		case 22: result.second = "StrangerWeapon"; break;
		case 23: result.second = "StrangerSneaking"; break;
		case 24: result.second = "SawDrinkBlood"; break;
		case 25: result.second = "Complained"; break;
		case 26: result.second = "ReceivedComplaint"; break;
		case 27: result.second = "AdmireBuilding"; break;
		case 28: result.second = "AdmireOwnBuilding"; break;
		case 29: result.second = "AdmireArrangedBuilding"; break;
		case 30: result.second = "AdmireOwnArrangedBuilding"; break;
		case 31: result.second = "LostPet"; break;
		case 32: result.second = "ThrownStuff"; break;
		case 33: result.second = "JailReleased"; break;
		case 34: result.second = "Miscarriage"; break;
		case 35: result.second = "SpouseMiscarriage"; break;
		case 36: result.second = "OldClothing"; break;
		case 37: result.second = "TatteredClothing"; break;
		case 38: result.second = "RottedClothing"; break;
		case 39: result.second = "GhostNightmare"; break;
		case 40: result.second = "GhostHaunt"; break;
		case 41: result.second = "Spar"; break;
		case 42: result.second = "UnableComplain"; break;
		case 43: result.second = "LongPatrol"; break;
		case 44: result.second = "SunNausea"; break;
		case 45: result.second = "SunIrritated"; break;
		case 46: result.second = "Drowsy"; break;
		case 47: result.second = "VeryDrowsy"; break;
		case 48: result.second = "Thirsty"; break;
		case 49: result.second = "Dehydrated"; break;
		case 50: result.second = "Hungry"; break;
		case 51: result.second = "Starving"; break;
		case 52: result.second = "MajorInjuries"; break;
		case 53: result.second = "MinorInjuries"; break;
		case 54: result.second = "SleepNoise"; break;
		case 55: result.second = "Rest"; break;
		case 56: result.second = "FreakishWeather"; break;
		case 57: result.second = "Rain"; break;
		case 58: result.second = "SnowStorm"; break;
		case 59: result.second = "Miasma"; break;
		case 60: result.second = "Smoke"; break;
		case 61: result.second = "Waterfall"; break;
		case 62: result.second = "Dust"; break;
		case 63: result.second = "Demands"; break;
		case 64: result.second = "ImproperPunishment"; break;
		case 65: result.second = "PunishmentReduced"; break;
		case 66: result.second = "Elected"; break;
		case 67: result.second = "Reelected"; break;
		case 68: result.second = "RequestApproved"; break;
		case 69: result.second = "RequestIgnored"; break;
		case 70: result.second = "NoPunishment"; break;
		case 71: result.second = "PunishmentDelayed"; break;
		case 72: result.second = "DelayedPunishment"; break;
		case 73: result.second = "ScarceCageChain"; break;
		case 74: result.second = "MandateIgnored"; break;
		case 75: result.second = "MandateDeadlineMissed"; break;
		case 76: result.second = "LackWork"; break;
		case 77: result.second = "SmashedBuilding"; break;
		case 78: result.second = "ToppledStuff"; break;
		case 79: result.second = "NoblePromotion"; break;
		case 80: result.second = "BecomeNoble"; break;
		case 81: result.second = "Cavein"; break;
		case 82: result.second = "MandateDeadlineMet"; break;
		case 83: result.second = "Uncovered"; break;
		case 84: result.second = "NoShirt"; break;
		case 85: result.second = "NoShoes"; break;
		case 86: result.second = "EatPet"; break;
		case 87: result.second = "EatLikedCreature"; break;
		case 88: result.second = "EatVermin"; break;
		case 89: result.second = "FistFight"; break;
		case 90: result.second = "GaveBeating"; break;
		case 91: result.second = "GotBeaten"; break;
		case 92: result.second = "GaveHammering"; break;
		case 93: result.second = "GotHammered"; break;
		case 94: result.second = "NoHammer"; break;
		case 95: result.second = "SameFood"; break;
		case 96: result.second = "AteRotten"; break;
		case 97: result.second = "GoodMeal"; break;
		case 98: result.second = "GoodDrink"; break;
		case 99: result.second = "MoreChests"; break;
		case 100: result.second = "MoreCabinets"; break;
		case 101: result.second = "MoreWeaponRacks"; break;
		case 102: result.second = "MoreArmorStands"; break;
		case 103: result.second = "RoomPretension"; break;
		case 104: result.second = "LackTables"; break;
		case 105: result.second = "CrowdedTables"; break;
		case 106: result.second = "DiningQuality"; break;
		case 107: result.second = "NoDining"; break;
		case 108: result.second = "LackChairs"; break;
		case 109: result.second = "TrainingBond"; break;
		case 110: result.second = "Rescued"; break;
		case 111: result.second = "RescuedOther"; break;
		case 112: result.second = "SatisfiedAtWork"; break;
		case 113: result.second = "TaxedLostProperty"; break;
		case 114: result.second = "Taxed"; break;
		case 115: result.second = "LackProtection"; break;
		case 116: result.second = "TaxRoomUnreachable"; break;
		case 117: result.second = "TaxRoomMisinformed"; break;
		case 118: result.second = "PleasedNoble"; break;
		case 119: result.second = "TaxCollectionSmooth"; break;
		case 120: result.second = "DisappointedNoble"; break;
		case 121: result.second = "TaxCollectionRough"; break;
		case 122: result.second = "MadeFriend"; break;
		case 123: result.second = "FormedGrudge"; break;
		case 124: result.second = "AnnoyedVermin"; break;
		case 125: result.second = "NearVermin"; break;
		case 126: result.second = "PesteredVermin"; break;
		case 127: result.second = "AcquiredItem"; break;
		case 128: result.second = "AdoptedPet"; break;
		case 129: result.second = "Jailed"; break;
		case 130: result.second = "Bath"; break;
		case 131: result.second = "SoapyBath"; break;
		case 132: result.second = "SparringAccident"; break;
		case 133: result.second = "Attacked"; break;
		case 134: result.second = "AttackedByDead"; break;
		case 135: result.second = "SameBooze"; break;
		case 136: result.second = "DrinkBlood"; break;
		case 137: result.second = "DrinkSlime"; break;
		case 138: result.second = "DrinkVomit"; break;
		case 139: result.second = "DrinkGoo"; break;
		case 140: result.second = "DrinkIchor"; break;
		case 141: result.second = "DrinkPus"; break;
		case 142: result.second = "NastyWater"; break;
		case 143: result.second = "DrankSpoiled"; break;
		case 144: result.second = "LackWell"; break;
		case 145: result.second = "NearCaged"; break;
		case 146: result.second = "NearCagedHated"; break;
		case 147: result.second = "LackBedroom"; break;
		case 148: result.second = "BedroomQuality"; break;
		case 149: result.second = "SleptFloor"; break;
		case 150: result.second = "SleptMud"; break;
		case 151: result.second = "SleptGrass"; break;
		case 152: result.second = "SleptRoughFloor"; break;
		case 153: result.second = "SleptRocks"; break;
		case 154: result.second = "SleptIce"; break;
		case 155: result.second = "SleptDirt"; break;
		case 156: result.second = "SleptDriftwood"; break;
		case 157: result.second = "ArtDefacement"; break;
		case 158: result.second = "Evicted"; break;
		case 159: result.second = "GaveBirth"; break;
		case 160: result.second = "SpouseGaveBirth"; break;
		case 161: result.second = "ReceivedWater"; break;
		case 162: result.second = "GaveWater"; break;
		case 163: result.second = "ReceivedFood"; break;
		case 164: result.second = "GaveFood"; break;
		case 165: result.second = "Talked"; break;
		case 166: result.second = "OfficeQuality"; break;
		case 167: result.second = "MeetingInBedroom"; break;
		case 168: result.second = "MeetingInDiningRoom"; break;
		case 169: result.second = "NoRooms"; break;
		case 170: result.second = "TombQuality"; break;
		case 171: result.second = "TombLack"; break;
		case 172: result.second = "TalkToNoble"; break;
		case 173: result.second = "InteractPet"; break;
		case 174: result.second = "ConvictionCorpse"; break;
		case 175: result.second = "ConvictionAnimal"; break;
		case 176: result.second = "ConvictionVictim"; break;
		case 177: result.second = "ConvictionJusticeSelf"; break;
		case 178: result.second = "ConvictionJusticeFamily"; break;
		case 179: result.second = "Decay"; break;
		case 180: result.second = "NeedsUnfulfilled"; break;
		case 181: result.second = "Prayer"; break;
		case 182: result.second = "DrinkWithoutCup"; break;
		case 183: result.second = "ResearchBreakthrough"; break;
		case 184: result.second = "ResearchStalled"; break;
		case 185: result.second = "PonderTopic"; break;
		case 186: result.second = "DiscussTopic"; break;
		case 187: result.second = "Syndrome"; break;
		case 188: result.second = "Perform"; break;
		case 189: result.second = "WatchPerform"; break;
		case 190: result.second = "RemoveTroupe"; break;
		case 191: result.second = "LearnTopic"; break;
		case 192: result.second = "LearnSkill"; break;
		case 193: result.second = "LearnBook"; break;
		case 194: result.second = "LearnInteraction"; break;
		case 195: result.second = "LearnPoetry"; break;
		case 196: result.second = "LearnMusic"; break;
		case 197: result.second = "LearnDance"; break;
		case 198: result.second = "TeachTopic"; break;
		case 199: result.second = "TeachSkill"; break;
		case 200: result.second = "ReadBook"; break;
		case 201: result.second = "WriteBook"; break;
		case 202: result.second = "BecomeResident"; break;
		case 203: result.second = "BecomeCitizen"; break;
		case 204: result.second = "DenyResident"; break;
		case 205: result.second = "DenyCitizen"; break;
		case 206: result.second = "LeaveTroupe"; break;
		case 207: result.second = "MakeBelieve"; break;
		case 208: result.second = "PlayToy"; break;
		case 209: result.second = "DreamAbout"; break;
		case 210: result.second = "Dream"; break;
		case 211: result.second = "Nightmare"; break;
		case 212: result.second = "Argument"; break;
		case 213: result.second = "CombatDrills"; break;
		case 214: result.second = "ArcheryPractice"; break;
		case 215: result.second = "ImproveSkill"; break;
		case 216: result.second = "WearItem"; break;
		case 217: result.second = "RealizeValue"; break;
		case 218: result.second = "OpinionStoryteller"; break;
		case 219: result.second = "OpinionRecitation"; break;
		case 220: result.second = "OpinionInstrumentSimulation"; break;
		case 221: result.second = "OpinionInstrumentPlayer"; break;
		case 222: result.second = "OpinionSinger"; break;
		case 223: result.second = "OpinionChanter"; break;
		case 224: result.second = "OpinionDancer"; break;
		case 225: result.second = "OpinionStory"; break;
		case 226: result.second = "OpinionPoetry"; break;
		case 227: result.second = "OpinionMusic"; break;
		case 228: result.second = "OpinionDance"; break;
		case 229: result.second = "Defeated"; break;
		case 230: result.second = "FavoritePossession"; break;
		case 231: result.second = "PreserveBody"; break;
		case 232: result.second = "Murdered"; break;
		case 233: result.second = "HistEventCollection"; break;
		case 234: result.second = "ViewOwnDisplay"; break;
		case 235: result.second = "ViewDisplay"; break;
		case 236: result.second = "AcquireArtifact"; break;
		case 237: result.second = "DenySanctuary"; break;
		case 238: result.second = "CaughtSneaking"; break;
		case 239: result.second = "GaveArtifact"; break;
		case 240: result.second = "SawDeadBody"; break;
		case 241: result.second = "Expelled"; break;
		case 242: result.second = "RelativeExpelled"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_value_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "LAW"; break;
		case 1: result.second = "LOYALTY"; break;
		case 2: result.second = "FAMILY"; break;
		case 3: result.second = "FRIENDSHIP"; break;
		case 4: result.second = "POWER"; break;
		case 5: result.second = "TRUTH"; break;
		case 6: result.second = "CUNNING"; break;
		case 7: result.second = "ELOQUENCE"; break;
		case 8: result.second = "FAIRNESS"; break;
		case 9: result.second = "DECORUM"; break;
		case 10: result.second = "TRADITION"; break;
		case 11: result.second = "ARTWORK"; break;
		case 12: result.second = "COOPERATION"; break;
		case 13: result.second = "INDEPENDENCE"; break;
		case 14: result.second = "STOICISM"; break;
		case 15: result.second = "INTROSPECTION"; break;
		case 16: result.second = "SELF_CONTROL"; break;
		case 17: result.second = "TRANQUILITY"; break;
		case 18: result.second = "HARMONY"; break;
		case 19: result.second = "MERRIMENT"; break;
		case 20: result.second = "CRAFTSMANSHIP"; break;
		case 21: result.second = "MARTIAL_PROWESS"; break;
		case 22: result.second = "SKILL"; break;
		case 23: result.second = "HARD_WORK"; break;
		case 24: result.second = "SACRIFICE"; break;
		case 25: result.second = "COMPETITION"; break;
		case 26: result.second = "PERSEVERENCE"; break;
		case 27: result.second = "LEISURE_TIME"; break;
		case 28: result.second = "COMMERCE"; break;
		case 29: result.second = "ROMANCE"; break;
		case 30: result.second = "NATURE"; break;
		case 31: result.second = "PEACE"; break;
		case 32: result.second = "KNOWLEDGE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_goal_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "STAY_ALIVE"; break;
		case 1: result.second = "MAINTAIN_ENTITY_STATUS"; break;
		case 2: result.second = "START_A_FAMILY"; break;
		case 3: result.second = "RULE_THE_WORLD"; break;
		case 4: result.second = "CREATE_A_GREAT_WORK_OF_ART"; break;
		case 5: result.second = "CRAFT_A_MASTERWORK"; break;
		case 6: result.second = "BRING_PEACE_TO_THE_WORLD"; break;
		case 7: result.second = "BECOME_A_LEGENDARY_WARRIOR"; break;
		case 8: result.second = "MASTER_A_SKILL"; break;
		case 9: result.second = "FALL_IN_LOVE"; break;
		case 10: result.second = "SEE_THE_GREAT_NATURAL_SITES"; break;
		case 11: result.second = "IMMORTALITY"; break;
		case 12: result.second = "MAKE_A_GREAT_DISCOVERY"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_personality_facet_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "LOVE_PROPENSITY"; break;
		case 1: result.second = "HATE_PROPENSITY"; break;
		case 2: result.second = "ENVY_PROPENSITY"; break;
		case 3: result.second = "CHEER_PROPENSITY"; break;
		case 4: result.second = "DEPRESSION_PROPENSITY"; break;
		case 5: result.second = "ANGER_PROPENSITY"; break;
		case 6: result.second = "ANXIETY_PROPENSITY"; break;
		case 7: result.second = "LUST_PROPENSITY"; break;
		case 8: result.second = "STRESS_VULNERABILITY"; break;
		case 9: result.second = "GREED"; break;
		case 10: result.second = "IMMODERATION"; break;
		case 11: result.second = "VIOLENT"; break;
		case 12: result.second = "PERSEVERENCE"; break;
		case 13: result.second = "WASTEFULNESS"; break;
		case 14: result.second = "DISCORD"; break;
		case 15: result.second = "FRIENDLINESS"; break;
		case 16: result.second = "POLITENESS"; break;
		case 17: result.second = "DISDAIN_ADVICE"; break;
		case 18: result.second = "BRAVERY"; break;
		case 19: result.second = "CONFIDENCE"; break;
		case 20: result.second = "VANITY"; break;
		case 21: result.second = "AMBITION"; break;
		case 22: result.second = "GRATITUDE"; break;
		case 23: result.second = "IMMODESTY"; break;
		case 24: result.second = "HUMOR"; break;
		case 25: result.second = "VENGEFUL"; break;
		case 26: result.second = "PRIDE"; break;
		case 27: result.second = "CRUELTY"; break;
		case 28: result.second = "SINGLEMINDED"; break;
		case 29: result.second = "HOPEFUL"; break;
		case 30: result.second = "CURIOUS"; break;
		case 31: result.second = "BASHFUL"; break;
		case 32: result.second = "PRIVACY"; break;
		case 33: result.second = "PERFECTIONIST"; break;
		case 34: result.second = "CLOSEMINDED"; break;
		case 35: result.second = "TOLERANT"; break;
		case 36: result.second = "EMOTIONALLY_OBSESSIVE"; break;
		case 37: result.second = "SWAYED_BY_EMOTIONS"; break;
		case 38: result.second = "ALTRUISM"; break;
		case 39: result.second = "DUTIFULNESS"; break;
		case 40: result.second = "THOUGHTLESSNESS"; break;
		case 41: result.second = "ORDERLINESS"; break;
		case 42: result.second = "TRUST"; break;
		case 43: result.second = "GREGARIOUSNESS"; break;
		case 44: result.second = "ASSERTIVENESS"; break;
		case 45: result.second = "ACTIVITY_LEVEL"; break;
		case 46: result.second = "EXCITEMENT_SEEKING"; break;
		case 47: result.second = "IMAGINATION"; break;
		case 48: result.second = "ABSTRACT_INCLINED"; break;
		case 49: result.second = "ART_INCLINED"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_physical_attribute_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "STRENGTH"; break;
		case 1: result.second = "AGILITY"; break;
		case 2: result.second = "TOUGHNESS"; break;
		case 3: result.second = "ENDURANCE"; break;
		case 4: result.second = "RECUPERATION"; break;
		case 5: result.second = "DISEASE_RESISTANCE"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_mental_attribute_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ANALYTICAL_ABILITY"; break;
		case 1: result.second = "FOCUS"; break;
		case 2: result.second = "WILLPOWER"; break;
		case 3: result.second = "CREATIVITY"; break;
		case 4: result.second = "INTUITION"; break;
		case 5: result.second = "PATIENCE"; break;
		case 6: result.second = "MEMORY"; break;
		case 7: result.second = "LINGUISTIC_ABILITY"; break;
		case 8: result.second = "SPATIAL_SENSE"; break;
		case 9: result.second = "MUSICALITY"; break;
		case 10: result.second = "KINESTHETIC_SENSE"; break;
		case 11: result.second = "EMPATHY"; break;
		case 12: result.second = "SOCIAL_AWARENESS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_mood_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Fey"; break;
		case 1: result.second = "Secretive"; break;
		case 2: result.second = "Possessed"; break;
		case 3: result.second = "Macabre"; break;
		case 4: result.second = "Fell"; break;
		case 5: result.second = "Melancholy"; break;
		case 6: result.second = "Raving"; break;
		case 7: result.second = "Berserk"; break;
		case 8: result.second = "Baby"; break;
		case 9: result.second = "Traumatized"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ghost_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MurderousGhost"; break;
		case 1: result.second = "SadisticGhost"; break;
		case 2: result.second = "SecretivePoltergeist"; break;
		case 3: result.second = "EnergeticPoltergeist"; break;
		case 4: result.second = "AngryGhost"; break;
		case 5: result.second = "ViolentGhost"; break;
		case 6: result.second = "MoaningSpirit"; break;
		case 7: result.second = "HowlingSpirit"; break;
		case 8: result.second = "TroublesomePoltergeist"; break;
		case 9: result.second = "RestlessHaunt"; break;
		case 10: result.second = "ForlornHaunt"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_animal_training_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SemiWild"; break;
		case 1: result.second = "Trained"; break;
		case 2: result.second = "WellTrained"; break;
		case 3: result.second = "SkilfullyTrained"; break;
		case 4: result.second = "ExpertlyTrained"; break;
		case 5: result.second = "ExceptionallyTrained"; break;
		case 6: result.second = "MasterfullyTrained"; break;
		case 7: result.second = "Domesticated"; break;
		case 8: result.second = "Unk8"; break;
		case 9: result.second = "WildUntamed"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_report_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Combat"; break;
		case 1: result.second = "Sparring"; break;
		case 2: result.second = "Hunting"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_skill_rating_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Dabbling"; break;
		case 1: result.second = "Novice"; break;
		case 2: result.second = "Adequate"; break;
		case 3: result.second = "Competent"; break;
		case 4: result.second = "Skilled"; break;
		case 5: result.second = "Proficient"; break;
		case 6: result.second = "Talented"; break;
		case 7: result.second = "Adept"; break;
		case 8: result.second = "Expert"; break;
		case 9: result.second = "Professional"; break;
		case 10: result.second = "Accomplished"; break;
		case 11: result.second = "Great"; break;
		case 12: result.second = "Master"; break;
		case 13: result.second = "HighMaster"; break;
		case 14: result.second = "GrandMaster"; break;
		case 15: result.second = "Legendary"; break;
		case 16: result.second = "Legendary1"; break;
		case 17: result.second = "Legendary2"; break;
		case 18: result.second = "Legendary3"; break;
		case 19: result.second = "Legendary4"; break;
		case 20: result.second = "Legendary5"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_relationship_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Pet"; break;
		case 1: result.second = "Spouse"; break;
		case 2: result.second = "Mother"; break;
		case 3: result.second = "Father"; break;
		case 4: result.second = "LastAttacker"; break;
		case 5: result.second = "GroupLeader"; break;
		case 6: result.second = "Draggee"; break;
		case 7: result.second = "Dragger"; break;
		case 8: result.second = "RiderMount"; break;
		case 9: result.second = "Lover"; break;
		case 10: result.second = "unk10"; break;
		case 11: result.second = "Sibling"; break;
		case 12: result.second = "Child"; break;
		case 13: result.second = "Friend"; break;
		case 14: result.second = "Grudge"; break;
		case 15: result.second = "Worship"; break;
		case 16: result.second = "AcquaintanceLong"; break;
		case 17: result.second = "AcquaintancePassing"; break;
		case 18: result.second = "Bonded"; break;
		case 19: result.second = "Hero"; break;
		case 20: result.second = "ConsidersViolent"; break;
		case 21: result.second = "ConsidersPsychotic"; break;
		case 22: result.second = "GoodForBusiness"; break;
		case 23: result.second = "FriendlyTerms"; break;
		case 24: result.second = "ConsidersKiller"; break;
		case 25: result.second = "ConsidersMurderer"; break;
		case 26: result.second = "Comrade"; break;
		case 27: result.second = "MemberOfRespectedGroup"; break;
		case 28: result.second = "MemberOfHatedGroup"; break;
		case 29: result.second = "EnemyFighter"; break;
		case 30: result.second = "FriendlyFighter"; break;
		case 31: result.second = "ConsidersBully"; break;
		case 32: result.second = "ConsidersBrigand"; break;
		case 33: result.second = "LoyalSoldier"; break;
		case 34: result.second = "ConsidersMonster"; break;
		case 35: result.second = "ConsidersStoryteller"; break;
		case 36: result.second = "ConsidersPoet"; break;
		case 37: result.second = "ConsidersBard"; break;
		case 38: result.second = "ConsidersDancer"; break;
		case 39: result.second = "Master"; break;
		case 40: result.second = "Apprentice"; break;
		case 41: result.second = "Companion"; break;
		case 42: result.second = "FormerMaster"; break;
		case 43: result.second = "FormerApprentice"; break;
		case 44: result.second = "ConsidersQuarreler"; break;
		case 45: result.second = "ConsidersFlatterer"; break;
		case 46: result.second = "Hunter"; break;
		case 47: result.second = "ProtectorOfTheWeak"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_need_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Socialize"; break;
		case 1: result.second = "DrinkAlcohol"; break;
		case 2: result.second = "PrayOrMedidate"; break;
		case 3: result.second = "StayOccupied"; break;
		case 4: result.second = "BeCreative"; break;
		case 5: result.second = "Excitement"; break;
		case 6: result.second = "LearnSomething"; break;
		case 7: result.second = "BeWithFamily"; break;
		case 8: result.second = "BeWithFriends"; break;
		case 9: result.second = "HearEloquence"; break;
		case 10: result.second = "UpholdTradition"; break;
		case 11: result.second = "SelfExamination"; break;
		case 12: result.second = "MakeMerry"; break;
		case 13: result.second = "CraftObject"; break;
		case 14: result.second = "MartialTraining"; break;
		case 15: result.second = "PracticeSkill"; break;
		case 16: result.second = "TakeItEasy"; break;
		case 17: result.second = "MakeRomance"; break;
		case 18: result.second = "SeeAnimal"; break;
		case 19: result.second = "SeeGreatBeast"; break;
		case 20: result.second = "AcquireObject"; break;
		case 21: result.second = "EatGoodMeal"; break;
		case 22: result.second = "Fight"; break;
		case 23: result.second = "CauseTrouble"; break;
		case 24: result.second = "Argue"; break;
		case 25: result.second = "BeExtravagant"; break;
		case 26: result.second = "Wander"; break;
		case 27: result.second = "HelpSomebody"; break;
		case 28: result.second = "ThinkAbstractly"; break;
		case 29: result.second = "AdmireArt"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ghost_goal_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "ScareToDeath"; break;
		case 1: result.second = "Stun"; break;
		case 2: result.second = "Batter"; break;
		case 3: result.second = "Possess"; break;
		case 4: result.second = "MisplaceItem"; break;
		case 5: result.second = "Haunt"; break;
		case 6: result.second = "Torment"; break;
		case 7: result.second = "ToppleBuilding"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_wound_effect_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Bruise"; break;
		case 1: result.second = "Burn"; break;
		case 2: result.second = "Frostbite"; break;
		case 3: result.second = "Burn2"; break;
		case 4: result.second = "Melting"; break;
		case 5: result.second = "Boiling"; break;
		case 6: result.second = "Freezing"; break;
		case 7: result.second = "Condensation"; break;
		case 8: result.second = "Necrosis"; break;
		case 9: result.second = "Blister"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_misc_trait_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "RequestWaterCooldown"; break;
		case 1: result.second = "RequestFoodCooldown"; break;
		case 2: result.second = "RequestRescueCooldown"; break;
		case 3: result.second = "RequestHealthcareCooldown"; break;
		case 4: result.second = "GetDrinkCooldown"; break;
		case 5: result.second = "GetFoodCooldown"; break;
		case 6: result.second = "CleanSelfCooldown"; break;
		case 7: result.second = "Migrant"; break;
		case 8: result.second = "RoomComplaint"; break;
		case 9: result.second = "UnnamedResident"; break;
		case 10: result.second = "RentBedroomCooldown"; break;
		case 11: result.second = "ClaimTrinketCooldown"; break;
		case 12: result.second = "ClaimClothingCooldown"; break;
		case 13: result.second = "WantsDrink"; break;
		case 14: result.second = "anon_1"; break;
		case 15: result.second = "anon_2"; break;
		case 16: result.second = "anon_3"; break;
		case 17: result.second = "anon_4"; break;
		case 18: result.second = "PrepareToDie"; break;
		case 19: result.second = "CaveAdapt"; break;
		case 20: result.second = "anon_5"; break;
		case 21: result.second = "anon_6"; break;
		case 22: result.second = "anon_7"; break;
		case 23: result.second = "anon_8"; break;
		case 24: result.second = "FollowUnitCooldown"; break;
		case 25: result.second = "anon_9"; break;
		case 26: result.second = "anon_10"; break;
		case 27: result.second = "anon_11"; break;
		case 28: result.second = "DangerousTerrainCooldown"; break;
		case 29: result.second = "Beaching"; break;
		case 30: result.second = "IdleAreaCooldown"; break;
		case 31: result.second = "anon_12"; break;
		case 32: result.second = "PartiedOut"; break;
		case 33: result.second = "DiagnosePatientCooldown"; break;
		case 34: result.second = "DressWoundCooldown"; break;
		case 35: result.second = "CleanPatientCooldown"; break;
		case 36: result.second = "SurgeryCooldown"; break;
		case 37: result.second = "SutureCooldown"; break;
		case 38: result.second = "SetBoneCooldown"; break;
		case 39: result.second = "PlaceInTractionCooldown"; break;
		case 40: result.second = "ApplyCastCooldown"; break;
		case 41: result.second = "ImmobilizeBreakCooldown"; break;
		case 42: result.second = "BringCrutchCooldown"; break;
		case 43: result.second = "anon_13"; break;
		case 44: result.second = "MilkCounter"; break;
		case 45: result.second = "HadDrill"; break;
		case 46: result.second = "CompletedDrill"; break;
		case 47: result.second = "EggSpent"; break;
		case 48: result.second = "GroundedAnimalAnger"; break;
		case 49: result.second = "anon_14"; break;
		case 50: result.second = "TimeSinceSuckedBlood"; break;
		case 51: result.second = "DrinkingBlood"; break;
		case 52: result.second = "anon_15"; break;
		case 53: result.second = "anon_16"; break;
		case 54: result.second = "RevertWildTimer"; break;
		case 55: result.second = "anon_17"; break;
		case 56: result.second = "NoPantsAnger"; break;
		case 57: result.second = "NoShirtAnger"; break;
		case 58: result.second = "NoShoesAnger"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_action_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Move"; break;
		case 1: result.second = "Attack"; break;
		case 2: result.second = "Jump"; break;
		case 3: result.second = "HoldTerrain"; break;
		case 4: result.second = "ReleaseTerrain"; break;
		case 5: result.second = "Climb"; break;
		case 6: result.second = "Job"; break;
		case 7: result.second = "Talk"; break;
		case 8: result.second = "Unsteady"; break;
		case 9: result.second = "Parry"; break;
		case 10: result.second = "Block"; break;
		case 11: result.second = "Dodge"; break;
		case 12: result.second = "Recover"; break;
		case 13: result.second = "StandUp"; break;
		case 14: result.second = "LieDown"; break;
		case 15: result.second = "Job2"; break;
		case 16: result.second = "PushObject"; break;
		case 17: result.second = "SuckBlood"; break;
		case 18: result.second = "HoldItem"; break;
		case 19: result.second = "ReleaseItem"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interface_breakdown_types_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "NONE"; break;
		case 1: result.second = "QUIT"; break;
		case 2: result.second = "STOPSCREEN"; break;
		case 3: result.second = "TOFIRST"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_embark_finder_option_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DimensionX"; break;
		case 1: result.second = "DimensionY"; break;
		case 2: result.second = "Savagery"; break;
		case 3: result.second = "Evil"; break;
		case 4: result.second = "Elevation"; break;
		case 5: result.second = "Temperature"; break;
		case 6: result.second = "Rain"; break;
		case 7: result.second = "Drainage"; break;
		case 8: result.second = "FluxStone"; break;
		case 9: result.second = "Aquifer"; break;
		case 10: result.second = "River"; break;
		case 11: result.second = "UndergroundRiver"; break;
		case 12: result.second = "UndergroundPool"; break;
		case 13: result.second = "MagmaPool"; break;
		case 14: result.second = "MagmaPipe"; break;
		case 15: result.second = "Chasm"; break;
		case 16: result.second = "BottomlessPit"; break;
		case 17: result.second = "OtherFeatures"; break;
		case 18: result.second = "ShallowMetal"; break;
		case 19: result.second = "DeepMetal"; break;
		case 20: result.second = "Soil"; break;
		case 21: result.second = "Clay"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_image_creator_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "ArtistToChoose"; break;
		case 1: result.second = "Histfig"; break;
		case 2: result.second = "Site"; break;
		case 3: result.second = "Entity"; break;
		case 4: result.second = "HistoryEvent"; break;
		case 5: result.second = "ExistingImage"; break;
		case 6: result.second = "NewImage"; break;
		case 7: result.second = "AddCreature"; break;
		case 8: result.second = "AddHistfig"; break;
		case 9: result.second = "AddPlant"; break;
		case 10: result.second = "AddTree"; break;
		case 11: result.second = "AddShape"; break;
		case 12: result.second = "AddObject"; break;
		case 13: result.second = "AddArtifact"; break;
		case 14: result.second = "AddRelationship"; break;
		case 15: result.second = "ChooseRelationshipX"; break;
		case 16: result.second = "ChooseRelationshipY"; break;
		case 17: result.second = "EnterNumber"; break;
		case 18: result.second = "DeleteElement"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_kitchenpref_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "VegetablesFruitLeaves"; break;
		case 1: result.second = "Seeds"; break;
		case 2: result.second = "Drinks"; break;
		case 3: result.second = "MeatFishOther"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_adventurer_attribute_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "VeryLow"; break;
		case 1: result.second = "Low"; break;
		case 2: result.second = "BelowAverage"; break;
		case 3: result.second = "Average"; break;
		case 4: result.second = "AboveAverage"; break;
		case 5: result.second = "High"; break;
		case 6: result.second = "Superior"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_unitlist_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Citizens"; break;
		case 1: result.second = "Livestock"; break;
		case 2: result.second = "Others"; break;
		case 3: result.second = "Dead"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_world_population_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Animal"; break;
		case 1: result.second = "Vermin"; break;
		case 2: result.second = "Unk2"; break;
		case 3: result.second = "VerminInnumerable"; break;
		case 4: result.second = "ColonyInsect"; break;
		case 5: result.second = "Tree"; break;
		case 6: result.second = "Grass"; break;
		case 7: result.second = "Bush"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_world_region_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Swamp"; break;
		case 1: result.second = "Desert"; break;
		case 2: result.second = "Jungle"; break;
		case 3: result.second = "Mountains"; break;
		case 4: result.second = "Ocean"; break;
		case 5: result.second = "Lake"; break;
		case 6: result.second = "Glacier"; break;
		case 7: result.second = "Tundra"; break;
		case 8: result.second = "Steppe"; break;
		case 9: result.second = "Hills"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_geo_layer_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SOIL"; break;
		case 1: result.second = "SEDIMENTARY"; break;
		case 2: result.second = "METAMORPHIC"; break;
		case 3: result.second = "IGNEOUS_EXTRUSIVE"; break;
		case 4: result.second = "IGNEOUS_INTRUSIVE"; break;
		case 5: result.second = "SOIL_OCEAN"; break;
		case 6: result.second = "SOIL_SAND"; break;
		case 7: result.second = "SEDIMENTARY_OCEAN_SHALLOW"; break;
		case 8: result.second = "SEDIMENTARY_OCEAN_DEEP"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_region_map_entry_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "has_river"; break;
		case 1: result.second = "tile_variant"; break;
		case 2: result.second = "anon_1"; break;
		case 3: result.second = "has_site"; break;
		case 4: result.second = "anon_2"; break;
		case 5: result.second = "river_up"; break;
		case 6: result.second = "river_down"; break;
		case 7: result.second = "river_right"; break;
		case 8: result.second = "river_left"; break;
		case 9: result.second = "discovered"; break;
		case 10: result.second = "anon_3"; break;
		case 11: result.second = "anon_4"; break;
		case 12: result.second = "anon_5"; break;
		case 13: result.second = "is_peak"; break;
		case 14: result.second = "is_lake"; break;
		case 15: result.second = "is_brook"; break;
		case 16: result.second = "has_road"; break;
		case 17: result.second = "anon_6"; break;
		case 18: result.second = "anon_7"; break;
		case 19: result.second = "anon_8"; break;
		case 20: result.second = "anon_9"; break;
		case 21: result.second = "anon_10"; break;
		case 22: result.second = "anon_11"; break;
		case 23: result.second = "anon_12"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_front_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "front_none"; break;
		case 1: result.second = "front_warm"; break;
		case 2: result.second = "front_cold"; break;
		case 3: result.second = "front_occluded"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_cumulus_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "cumulus_none"; break;
		case 1: result.second = "cumulus_medium"; break;
		case 2: result.second = "cumulus_multi"; break;
		case 3: result.second = "cumulus_nimbus"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_stratus_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "stratus_none"; break;
		case 1: result.second = "stratus_alto"; break;
		case 2: result.second = "stratus_proper"; break;
		case 3: result.second = "stratus_nimbus"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_fog_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "fog_none"; break;
		case 1: result.second = "fog_mist"; break;
		case 2: result.second = "fog_normal"; break;
		case 3: result.second = "fog_thick"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_mountain_peak_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "is_volcano"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_abstract_building_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MEAD_HALL"; break;
		case 1: result.second = "KEEP"; break;
		case 2: result.second = "TEMPLE"; break;
		case 3: result.second = "DARK_TOWER"; break;
		case 4: result.second = "MARKET"; break;
		case 5: result.second = "TOMB"; break;
		case 6: result.second = "DUNGEON"; break;
		case 7: result.second = "UNDERWORLD_SPIRE"; break;
		case 8: result.second = "INN_TAVERN"; break;
		case 9: result.second = "LIBRARY"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_abstract_building_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Unk0"; break;
		case 1: result.second = "Unk1"; break;
		case 2: result.second = "Unk2"; break;
		case 3: result.second = "Unk3"; break;
		case 4: result.second = "AllowVisitors"; break;
		case 5: result.second = "AllowResidents"; break;
		case 6: result.second = "Unk6"; break;
		case 7: result.second = "Unk7"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_world_site_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "PlayerFortress"; break;
		case 1: result.second = "DarkFortress"; break;
		case 2: result.second = "Cave"; break;
		case 3: result.second = "MountainHalls"; break;
		case 4: result.second = "ForestRetreat"; break;
		case 5: result.second = "Town"; break;
		case 6: result.second = "ImportantLocation"; break;
		case 7: result.second = "LairShrine"; break;
		case 8: result.second = "Fortress"; break;
		case 9: result.second = "Camp"; break;
		case 10: result.second = "Monument"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_world_site_flags_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Undiscovered"; break;
		case 1: result.second = "anon_1"; break;
		case 2: result.second = "anon_2"; break;
		case 3: result.second = "Town"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_site_realization_building_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "cottage_plot"; break;
		case 1: result.second = "castle_wall"; break;
		case 2: result.second = "castle_tower"; break;
		case 3: result.second = "castle_courtyard"; break;
		case 4: result.second = "house"; break;
		case 5: result.second = "temple"; break;
		case 6: result.second = "tomb"; break;
		case 7: result.second = "shop_house"; break;
		case 8: result.second = "warehouse"; break;
		case 9: result.second = "market_square"; break;
		case 10: result.second = "pasture"; break;
		case 11: result.second = "waste"; break;
		case 12: result.second = "courtyard"; break;
		case 13: result.second = "well"; break;
		case 14: result.second = "vault"; break;
		case 15: result.second = "great_tower"; break;
		case 16: result.second = "trenches"; break;
		case 17: result.second = "tree_house"; break;
		case 18: result.second = "hillock_house"; break;
		case 19: result.second = "mead_hall"; break;
		case 20: result.second = "fortress_entrance"; break;
		case 21: result.second = "library"; break;
		case 22: result.second = "tavern"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_site_shop_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "GeneralImports"; break;
		case 1: result.second = "FoodImports"; break;
		case 2: result.second = "ClothingImports"; break;
		case 3: result.second = "Cloth"; break;
		case 4: result.second = "Leather"; break;
		case 5: result.second = "WovenClothing"; break;
		case 6: result.second = "LeatherClothing"; break;
		case 7: result.second = "BoneCarver"; break;
		case 8: result.second = "GemCutter"; break;
		case 9: result.second = "Weaponsmith"; break;
		case 10: result.second = "Bowyer"; break;
		case 11: result.second = "Blacksmith"; break;
		case 12: result.second = "Armorsmith"; break;
		case 13: result.second = "MetalCraft"; break;
		case 14: result.second = "LeatherGoods"; break;
		case 15: result.second = "Carpenter"; break;
		case 16: result.second = "StoneFurniture"; break;
		case 17: result.second = "MetalFurniture"; break;
		case 18: result.second = "ImportedGoodsMarket"; break;
		case 19: result.second = "ImportedFoodMarket"; break;
		case 20: result.second = "ImportedClothingMarket"; break;
		case 21: result.second = "MeatMarket"; break;
		case 22: result.second = "FruitAndVegetableMarket"; break;
		case 23: result.second = "CheeseMarket"; break;
		case 24: result.second = "ProcessedGoodsMarket"; break;
		case 25: result.second = "Tavern"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_tree_house_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TreeHouse"; break;
		case 1: result.second = "HomeTree"; break;
		case 2: result.second = "ShapingTree"; break;
		case 3: result.second = "MarketTree"; break;
		case 4: result.second = "Unknown1"; break;
		case 5: result.second = "Unknown2"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_hillock_house_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "anon_1"; break;
		case 1: result.second = "CivicMound"; break;
		case 2: result.second = "CastleMound"; break;
		case 3: result.second = "DrinkingMound"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_creation_zone_pwg_alteration_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "location_death"; break;
		case 1: result.second = "camp"; break;
		case 2: result.second = "srb_ruined"; break;
		case 3: result.second = "srp_ruined"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_worldgen_region_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SWAMP"; break;
		case 1: result.second = "DESERT"; break;
		case 2: result.second = "FOREST"; break;
		case 3: result.second = "MOUNTAINS"; break;
		case 4: result.second = "OCEAN"; break;
		case 5: result.second = "LAKE"; break;
		case 6: result.second = "GLACIER"; break;
		case 7: result.second = "TUNDRA"; break;
		case 8: result.second = "GRASSLAND"; break;
		case 9: result.second = "HILLS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_worldgen_range_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ELEVATION"; break;
		case 1: result.second = "RAINFALL"; break;
		case 2: result.second = "anon_1"; break;
		case 3: result.second = "TEMPERATURE"; break;
		case 4: result.second = "anon_2"; break;
		case 5: result.second = "DRAINAGE"; break;
		case 6: result.second = "VOLCANISM"; break;
		case 7: result.second = "SAVAGERY"; break;
		case 8: result.second = "anon_3"; break;
		case 9: result.second = "anon_4"; break;
		case 10: result.second = "anon_5"; break;
		case 11: result.second = "anon_6"; break;
		case 12: result.second = "anon_7"; break;
		case 13: result.second = "anon_8"; break;
		case 14: result.second = "anon_9"; break;
		case 15: result.second = "anon_10"; break;
		case 16: result.second = "anon_11"; break;
		case 17: result.second = "anon_12"; break;
		case 18: result.second = "anon_13"; break;
		case 19: result.second = "anon_14"; break;
		case 20: result.second = "anon_15"; break;
		case 21: result.second = "anon_16"; break;
		case 22: result.second = "anon_17"; break;
		case 23: result.second = "anon_18"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_units_other_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ANY_RIDER"; break;
		case 1: result.second = "ANY_BABY2"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_conflict_level_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "Encounter"; break;
		case 1: result.second = "Horseplay"; break;
		case 2: result.second = "Training"; break;
		case 3: result.second = "Brawl"; break;
		case 4: result.second = "Nonlethal"; break;
		case 5: result.second = "Lethal"; break;
		case 6: result.second = "NoQuarter"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_combat_report_event_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "anon_1"; break;
		case 1: result.second = "Deflected"; break;
		case 2: result.second = "anon_2"; break;
		case 3: result.second = "anon_3"; break;
		case 4: result.second = "anon_4"; break;
		case 5: result.second = "anon_5"; break;
		case 6: result.second = "Unconscious"; break;
		case 7: result.second = "Stunned"; break;
		case 8: result.second = "MoreStunned"; break;
		case 9: result.second = "Winded"; break;
		case 10: result.second = "MoreWinded"; break;
		case 11: result.second = "Nausea"; break;
		case 12: result.second = "MoreNausea"; break;
		case 13: result.second = "anon_6"; break;
		case 14: result.second = "anon_7"; break;
		case 15: result.second = "ExtractInjected"; break;
		case 16: result.second = "ExtractSprayed"; break;
		case 17: result.second = "BloodSucked"; break;
		case 18: result.second = "SeveredPart"; break;
		case 19: result.second = "anon_8"; break;
		case 20: result.second = "KnockedBack"; break;
		case 21: result.second = "StuckIn"; break;
		case 22: result.second = "LatchOnPart"; break;
		case 23: result.second = "LatchOn"; break;
		case 24: result.second = "Enraged"; break;
		case 25: result.second = "PassThrough"; break;
		case 26: result.second = "GlancesAway"; break;
		case 27: result.second = "anon_9"; break;
		case 28: result.second = "anon_10"; break;
		case 29: result.second = "MajorArtery"; break;
		case 30: result.second = "Artery"; break;
		case 31: result.second = "MotorNerve"; break;
		case 32: result.second = "SensoryNerve"; break;
		case 33: result.second = "NoForce"; break;
		case 34: result.second = "Interrupted"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_conversation__T_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "started"; break;
		case 1: result.second = "active"; break;
		case 2: result.second = "finished"; break;
		case 3: result.second = "quit"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_building_archerytargetst__T_archery_direction_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TopToBottom"; break;
		case 1: result.second = "BottomToTop"; break;
		case 2: result.second = "LeftToRight"; break;
		case 3: result.second = "RightToLeft"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_building_bridgest__T_direction_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "Retracting"; break;
		case 0: result.second = "Left"; break;
		case 1: result.second = "Right"; break;
		case 2: result.second = "Up"; break;
		case 3: result.second = "Down"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_building_siegeenginest__T_facing_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Left"; break;
		case 1: result.second = "Up"; break;
		case 2: result.second = "Right"; break;
		case 3: result.second = "Down"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_building_siegeenginest__T_action_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "NotInUse"; break;
		case 1: result.second = "PrepareToFire"; break;
		case 2: result.second = "FireAtWill"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_caste_body_info__T_interactions__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "RETRACT_INTO_BP"; break;
		case 1: result.second = "CAN_DO_INTERACTION"; break;
		case 2: result.second = "ROOT_AROUND"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_caravan_state__T_trade_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "None"; break;
		case 1: result.second = "Approaching"; break;
		case 2: result.second = "AtDepot"; break;
		case 3: result.second = "Leaving"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_entity_event__T_data__T_insurrection_end__T_result_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Overthrow"; break;
		case 1: result.second = "Failure"; break;
		case 2: result.second = "Crushing"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_change_hf_statest__T_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Wandering"; break;
		case 1: result.second = "Settled"; break;
		case 2: result.second = "Refugee"; break;
		case 3: result.second = "anon_1"; break;
		case 4: result.second = "anon_2"; break;
		case 5: result.second = "Visiting"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_body_abusedst__T_props__T_pile_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "GrislyMound"; break;
		case 1: result.second = "GrotesquePillar"; break;
		case 2: result.second = "GruesomeSculpture"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_body_abusedst__T_abuse_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Impaled"; break;
		case 1: result.second = "Piled"; break;
		case 2: result.second = "Flayed"; break;
		case 3: result.second = "Hung"; break;
		case 4: result.second = "Mutilated"; break;
		case 5: result.second = "Animated"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_hist_figure_travelst__T_reason_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Journey"; break;
		case 1: result.second = "Return"; break;
		case 2: result.second = "Escape"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_history_event_artifact_claim_formedst__T_claim_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Symbol"; break;
		case 1: result.second = "Heirloom"; break;
		case 2: result.second = "Treasure"; break;
		case 3: result.second = "HolyRelic"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_init_display__T_windowed_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "True"; break;
		case 1: result.second = "False"; break;
		case 2: result.second = "Prompt"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_init_font__T_use_ttf_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "TTF_OFF"; break;
		case 1: result.second = "TTF_ON"; break;
		case 2: result.second = "TTF_AUTO"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_job_item_ref__T_role_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "anon_1"; break;
		case 1: result.second = "Reagent"; break;
		case 2: result.second = "Hauled"; break;
		case 3: result.second = "LinkToTarget"; break;
		case 4: result.second = "LinkToTrigger"; break;
		case 5: result.second = "anon_2"; break;
		case 6: result.second = "TargetContainer"; break;
		case 7: result.second = "QueuedContainer"; break;
		case 8: result.second = "PushHaulVehicle"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_manager_order__T_frequency_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "OneTime"; break;
		case 1: result.second = "Daily"; break;
		case 2: result.second = "Monthly"; break;
		case 3: result.second = "Seasonally"; break;
		case 4: result.second = "Yearly"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_manager_order_condition_item__T_compare_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "AtLeast"; break;
		case 1: result.second = "AtMost"; break;
		case 2: result.second = "GreaterThan"; break;
		case 3: result.second = "LessThan"; break;
		case 4: result.second = "Exactly"; break;
		case 5: result.second = "Not"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_mandate__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Export"; break;
		case 1: result.second = "Make"; break;
		case 2: result.second = "Guild"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_demand__T_place_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Office"; break;
		case 1: result.second = "Bedroom"; break;
		case 2: result.second = "DiningRoom"; break;
		case 3: result.second = "Tomb"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_advmode__T_conversation__T_targets__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Talk"; break;
		case 1: result.second = "anon_1"; break;
		case 2: result.second = "anon_2"; break;
		case 3: result.second = "Shout"; break;
		case 4: result.second = "Perform"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_advmode__T_travel_right_map_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "MapNone"; break;
		case 1: result.second = "MapSite"; break;
		case 2: result.second = "MapWorld"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_advmode__T_show_menu_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "TwoBlankRows"; break;
		case 0: result.second = "Hidden"; break;
		case 1: result.second = "TwoRowsWithKeybindingHints"; break;
		case 2: result.second = "TwoRows"; break;
		case 3: result.second = "OneRow"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_stop_depart_condition__T_direction_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "North"; break;
		case 1: result.second = "South"; break;
		case 2: result.second = "East"; break;
		case 3: result.second = "West"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_stop_depart_condition__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Push"; break;
		case 1: result.second = "Ride"; break;
		case 2: result.second = "Guide"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_interface_button_construction_category_selectorst__T_category_id_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 1: result.second = "SiegeEngines"; break;
		case 2: result.second = "Traps"; break;
		case 3: result.second = "Workshops"; break;
		case 4: result.second = "Furnaces"; break;
		case 5: result.second = "Constructions"; break;
		case 6: result.second = "MachineComponents"; break;
		case 7: result.second = "Track"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_sidebar_menus__T_designation__T_mine_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "All"; break;
		case 1: result.second = "AutoMine"; break;
		case 2: result.second = "Economic"; break;
		case 3: result.second = "Gems"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_sidebar_menus__T_zone__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Rectangle"; break;
		case 1: result.second = "Flow"; break;
		case 2: result.second = "FloorFlow"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_sidebar_menus__T_unit__T_expel_error_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "NONE"; break;
		case 0: result.second = "NOBILITY"; break;
		case 1: result.second = "HOLDS_OFFICE"; break;
		case 2: result.second = "DOES_EXPELLING"; break;
		case 3: result.second = "SPOUSE_IS_NOT_PRESENT"; break;
		case 4: result.second = "SPOUSE_IS_NOBILITY"; break;
		case 5: result.second = "SPOUSE_IS_ELECTED"; break;
		case 6: result.second = "SPOUSE_DOES_EXPELLING"; break;
		case 7: result.second = "CHILD_IS_NOT_PRESENT"; break;
		case 8: result.second = "CHILD_IS_NOBILITY"; break;
		case 9: result.second = "CHILD_IS_ELECTED"; break;
		case 10: result.second = "CHILD_DOES_EXPELLING"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_look_list__T_items__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Item"; break;
		case 1: result.second = "Floor"; break;
		case 2: result.second = "Unit"; break;
		case 3: result.second = "Building"; break;
		case 4: result.second = "Vermin"; break;
		case 5: result.second = "Flow"; break;
		case 6: result.second = "Campfire"; break;
		case 7: result.second = "Spatter"; break;
		case 8: result.second = "BuildingItem"; break;
		case 9: result.second = "Fire"; break;
		case 10: result.second = "Water"; break;
		case 11: result.second = "Magma"; break;
		case 12: result.second = "Spoor"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_ui_unit_view_mode__T_value_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "General"; break;
		case 1: result.second = "Inventory"; break;
		case 2: result.second = "Preferences"; break;
		case 3: result.second = "Wounds"; break;
		case 4: result.second = "PrefLabor"; break;
		case 5: result.second = "PrefDogs"; break;
		case 6: result.second = "PrefOccupation"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit__T_meeting__T_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SelectNoble"; break;
		case 1: result.second = "FollowNoble"; break;
		case 2: result.second = "DoMeeting"; break;
		case 3: result.second = "LeaveMap"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit__T_counters__T_soldier_mood_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "MartialTrance"; break;
		case 1: result.second = "Enraged"; break;
		case 2: result.second = "Tantrum"; break;
		case 3: result.second = "Depressed"; break;
		case 4: result.second = "Oblivious"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_inventory_item__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Hauled"; break;
		case 1: result.second = "Weapon"; break;
		case 2: result.second = "Worn"; break;
		case 3: result.second = "Piercing"; break;
		case 4: result.second = "Flask"; break;
		case 5: result.second = "WrappedAround"; break;
		case 6: result.second = "StuckIn"; break;
		case 7: result.second = "InMouth"; break;
		case 8: result.second = "Pet"; break;
		case 9: result.second = "SewnInto"; break;
		case 10: result.second = "Strapped"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_preference__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "LikeMaterial"; break;
		case 1: result.second = "LikeCreature"; break;
		case 2: result.second = "LikeFood"; break;
		case 3: result.second = "HateCreature"; break;
		case 4: result.second = "LikeItem"; break;
		case 5: result.second = "LikePlant"; break;
		case 6: result.second = "LikeTree"; break;
		case 7: result.second = "LikeColor"; break;
		case 8: result.second = "LikeShape"; break;
		case 9: result.second = "LikePoeticForm"; break;
		case 10: result.second = "LikeMusicalForm"; break;
		case 11: result.second = "LikeDanceForm"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_complaint__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 25: result.second = "SelfUnemployed"; break;
		case 26: result.second = "GuildUnemployed"; break;
		case 27: result.second = "NeedWeapons"; break;
		case 28: result.second = "IsAngry"; break;
		case 29: result.second = "IsSad"; break;
		case 30: result.second = "anon_1"; break;
		case 31: result.second = "anon_2"; break;
		case 32: result.second = "anon_3"; break;
		case 33: result.second = "anon_4"; break;
		case 34: result.second = "anon_5"; break;
		case 35: result.second = "anon_6"; break;
		case 36: result.second = "anon_7"; break;
		case 37: result.second = "anon_8"; break;
		case 38: result.second = "anon_9"; break;
		case 39: result.second = "anon_10"; break;
		case 40: result.second = "anon_11"; break;
		case 41: result.second = "anon_12"; break;
		case 42: result.second = "anon_13"; break;
		case 43: result.second = "anon_14"; break;
		case 44: result.second = "anon_15"; break;
		case 45: result.second = "anon_16"; break;
		case 46: result.second = "anon_17"; break;
		case 47: result.second = "anon_18"; break;
		case 48: result.second = "Petition"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_unit_request__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DoGuildJobs"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_KeybindingScreen__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Main"; break;
		case 1: result.second = "KeyL"; break;
		case 2: result.second = "KeyR"; break;
		case 3: result.second = "Macro"; break;
		case 4: result.second = "Register"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_adventure_logst__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Info"; break;
		case 1: result.second = "Map"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_adventure_logst__T_info_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Events"; break;
		case 1: result.second = "Agreements"; break;
		case 2: result.second = "People"; break;
		case 3: result.second = "Sites"; break;
		case 4: result.second = "Groups"; break;
		case 5: result.second = "Regions"; break;
		case 6: result.second = "Bestiary"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_assign_display_itemst__T_sel_column_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ItemTypes"; break;
		case 1: result.second = "Items"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_choose_start_sitest__T_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Biome"; break;
		case 1: result.second = "Neighbors"; break;
		case 2: result.second = "Civilization"; break;
		case 3: result.second = "Elevation"; break;
		case 4: result.second = "Cliffs"; break;
		case 5: result.second = "Reclaim"; break;
		case 6: result.second = "Reclaim2"; break;
		case 7: result.second = "Find"; break;
		case 8: result.second = "Notes"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_mission__T_details__T_raid__T_raid_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Raze"; break;
		case 1: result.second = "TakeOver"; break;
		case 2: result.second = "Occupy"; break;
		case 3: result.second = "DemandTribute"; break;
		case 4: result.second = "Raid"; break;
		case 5: result.second = "Explore"; break;
		case 6: result.second = "Pillage"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_mission__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 2: result.second = "Raid"; break;
		case 17: result.second = "RecoverArtifact"; break;
		case 18: result.second = "RescuePerson"; break;
		case 19: result.second = "RequestWorkers"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_civlistst__T_rumors__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ArmyMarched"; break;
		case 1: result.second = "Kidnapped"; break;
		case 3: result.second = "Unknown3"; break;
		case 7: result.second = "RefugeesFled"; break;
		case 8: result.second = "MovedOn"; break;
		case 9: result.second = "Reclaimed"; break;
		case 10: result.second = "Founded"; break;
		case 13: result.second = "GaveUpOccupation"; break;
		case 16: result.second = "BecameRuler"; break;
		case 17: result.second = "Claimed"; break;
		case 25: result.second = "ArtifactLocation"; break;
		case 28: result.second = "Unknown28"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_civlistst__T_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Civilizations"; break;
		case 1: result.second = "News"; break;
		case 2: result.second = "World"; break;
		case 3: result.second = "Missions"; break;
		case 4: result.second = "MissionSquads"; break;
		case 5: result.second = "MissionMessengers"; break;
		case 6: result.second = "MissionDetails"; break;
		case 7: result.second = "People"; break;
		case 8: result.second = "Artifacts"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_game_cleanerst__T_state_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "CleaningGameObjects"; break;
		case 1: result.second = "CleaningStrandedObjects"; break;
		case 2: result.second = "CleaningPlayObjects"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_justicest__T_cur_column_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Crimes"; break;
		case 1: result.second = "Suspects"; break;
		case 2: result.second = "ConvictChoices"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_assign_trade_status__T_status_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -2: result.second = "RemoveTrading"; break;
		case -1: result.second = "RemovePending"; break;
		case 0: result.second = "None"; break;
		case 1: result.second = "AddPending"; break;
		case 2: result.second = "Pending"; break;
		case 3: result.second = "Trading"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_layer_choose_language_namest__T_current_component_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "FrontCompound"; break;
		case 1: result.second = "RearCompound"; break;
		case 2: result.second = "FirstAdjective"; break;
		case 3: result.second = "SecondAdjective"; break;
		case 4: result.second = "HyphenCompound"; break;
		case 5: result.second = "TheX"; break;
		case 6: result.second = "OfX"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_layer_militaryst__T_equip__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Customize"; break;
		case 1: result.second = "Uniform"; break;
		case 2: result.second = "Priority"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_layer_militaryst__T_equip__T_edit_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Armor"; break;
		case 1: result.second = "Helm"; break;
		case 2: result.second = "Legs"; break;
		case 3: result.second = "Gloves"; break;
		case 4: result.second = "Boots"; break;
		case 5: result.second = "Shield"; break;
		case 6: result.second = "Weapon"; break;
		case 7: result.second = "Material"; break;
		case 8: result.second = "Color"; break;
		case 9: result.second = "SpecificArmor"; break;
		case 10: result.second = "SpecificHelm"; break;
		case 11: result.second = "SpecificLegs"; break;
		case 12: result.second = "SpecificGloves"; break;
		case 13: result.second = "SpecificBoots"; break;
		case 14: result.second = "SpecificShield"; break;
		case 15: result.second = "SpecificWeapon"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_layer_militaryst__T_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Positions"; break;
		case 1: result.second = "Alerts"; break;
		case 2: result.second = "Equip"; break;
		case 3: result.second = "Uniforms"; break;
		case 4: result.second = "Supplies"; break;
		case 5: result.second = "Ammunition"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_layer_noblelistst__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "List"; break;
		case 1: result.second = "Appoint"; break;
		case 2: result.second = "Settings"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_legendsst__T_cur_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Main"; break;
		case 1: result.second = "HistoricalFigures"; break;
		case 2: result.second = "Sites"; break;
		case 3: result.second = "Artifacts"; break;
		case 4: result.second = "Regions"; break;
		case 5: result.second = "Civilizations"; break;
		case 6: result.second = "Art"; break;
		case 7: result.second = "Structures"; break;
		case 8: result.second = "Age"; break;
		case 9: result.second = "HistoricalMaps"; break;
		case 10: result.second = "UndergroundRegions"; break;
		case 11: result.second = "Populations"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_locationsst__T_in_edit_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "None"; break;
		case 1: result.second = "Goblets"; break;
		case 2: result.second = "Instruments"; break;
		case 3: result.second = "WritingCopies"; break;
		case 4: result.second = "WritingMaterial"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_locationsst__T_menu_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Locations"; break;
		case 1: result.second = "Occupations"; break;
		case 2: result.second = "AssignOccupation"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_petst__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "List"; break;
		case 1: result.second = "TrainingKnowledge"; break;
		case 2: result.second = "SelectTrainer"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_setup_character_info__T_status_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Peasant"; break;
		case 1: result.second = "Hero"; break;
		case 2: result.second = "Demigod"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_setupadventurest__T_page_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ChooseRace"; break;
		case 1: result.second = "ChooseAnimalRace"; break;
		case 2: result.second = "ChooseHistfig"; break;
		case 3: result.second = "ChooseCiv"; break;
		case 4: result.second = "Skills"; break;
		case 5: result.second = "PhysicalTraits"; break;
		case 6: result.second = "MentalTraits"; break;
		case 7: result.second = "Background"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_setupadventurest__T_sel_trait_column_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "SkillsColumn"; break;
		case 1: result.second = "AttributesColumn"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_setupdwarfgamest__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Dwarves"; break;
		case 1: result.second = "Items"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_titlest__T_sel_subpage_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "None"; break;
		case 1: result.second = "StartSelectWorld"; break;
		case 2: result.second = "StartSelectMode"; break;
		case 3: result.second = "Arena"; break;
		case 4: result.second = "About"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_workquota_conditionst__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "List"; break;
		case 0: result.second = "ItemType"; break;
		case 1: result.second = "Material"; break;
		case 2: result.second = "Traits"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_viewscreen_workshop_profilest__T_tab_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Workers"; break;
		case 1: result.second = "Orders"; break;
		case 2: result.second = "Restrictions"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_world_underground_region__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Cavern"; break;
		case 1: result.second = "MagmaSea"; break;
		case 2: result.second = "Underworld"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_world_data__T_flip_latitude_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case -1: result.second = "None"; break;
		case 0: result.second = "North"; break;
		case 1: result.second = "South"; break;
		case 2: result.second = "Both"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_abstract_building_dungeonst__T_dungeon_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "DUNGEON"; break;
		case 1: result.second = "SEWERS"; break;
		case 2: result.second = "CATACOMBS"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_cultural_identity__T_group_log__T_join_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Peaceful"; break;
		case 1: result.second = "CompleteTakeOver"; break;
		case 2: result.second = "TakeOver"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_world_site_realization__T_areas__T_type_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "Crops1"; break;
		case 1: result.second = "Crops2"; break;
		case 2: result.second = "Crops3"; break;
		case 3: result.second = "Meadow"; break;
		case 4: result.second = "Pasture"; break;
		case 5: result.second = "Orchard"; break;
		case 6: result.second = "Woodland"; break;
		case 7: result.second = "Waste"; break;
		case 8: result.second = "Unknown1"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_crime__T_mode_value_decoded(DF_Type p_base_type, uint64_t p_address)
{
	std::pair<int64_t, std::string> result;
	result.first  = cast(p_base_type, p_address);
	result.second = "UNKNOWN-VALUE";
	switch (result.first)
	{
		case 0: result.second = "ProductionOrderViolation"; break;
		case 1: result.second = "ExportViolation"; break;
		case 2: result.second = "JobOrderViolation"; break;
		case 3: result.second = "ConspiracyToSlowLabor"; break;
		case 4: result.second = "Murder"; break;
		case 5: result.second = "DisorderlyBehavior"; break;
		case 6: result.second = "BuildingDestruction"; break;
		case 7: result.second = "Vandalism"; break;
		case 8: result.second = "Theft"; break;
		case 9: result.second = "Robbery"; break;
		case 10: result.second = "BloodDrinking"; break;
		default: break;
	}
	return result;
}

std::pair<int64_t, std::string> get_enum_decoded(const NodeEnum* p_node)
{
	switch(p_node->m_df_type)
	{
		case DF_Type::ui_advmode_menu: return get_ui_advmode_menu_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::talk_choice_type: return get_talk_choice_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::announcement_type: return get_announcement_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::art_image_element_type: return get_art_image_element_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::art_image_property_type: return get_art_image_property_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::art_image_property_verb: return get_art_image_property_verb_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::art_facet_type: return get_art_facet_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_action: return get_poetic_form_action_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_pattern: return get_poetic_form_pattern_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_caesura_position: return get_poetic_form_caesura_position_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_mood: return get_poetic_form_mood_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_subject: return get_poetic_form_subject_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_additional_feature: return get_poetic_form_additional_feature_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::poetic_form_perspective__T_type: return get_poetic_form_perspective__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::occupation_type: return get_occupation_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::buildings_other_id: return get_buildings_other_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_type: return get_building_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::civzone_type: return get_civzone_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::furnace_type: return get_furnace_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::workshop_type: return get_workshop_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::construction_type: return get_construction_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::shop_type: return get_shop_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::siegeengine_type: return get_siegeengine_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::trap_type: return get_trap_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::dfhack_room_quality_level: return get_dfhack_room_quality_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creature_raw_flags: return get_creature_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::caste_raw_flags: return get_caste_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::body_part_raw_flags: return get_body_part_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::appearance_modifier_type: return get_appearance_modifier_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::body_part_layer_flags: return get_body_part_layer_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::appearance_modifier_growth_interval: return get_appearance_modifier_growth_interval_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::gait_type: return get_gait_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creature_graphics_role: return get_creature_graphics_role_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tissue_style_type: return get_tissue_style_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::body_part_template_flags: return get_body_part_template_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::body_part_template_contype: return get_body_part_template_contype_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tissue_flags: return get_tissue_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_nickname: return get_d_init_nickname_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_z_view: return get_d_init_z_view_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_embark_confirm: return get_d_init_embark_confirm_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_idlers: return get_d_init_idlers_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_tunnel: return get_d_init_tunnel_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_flags1: return get_d_init_flags1_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_flags2: return get_d_init_flags2_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_flags3: return get_d_init_flags3_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::d_init_flags4: return get_d_init_flags4_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::pattern_type: return get_pattern_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::occasion_schedule_type: return get_occasion_schedule_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::occasion_schedule_feature: return get_occasion_schedule_feature_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_sell_category: return get_entity_sell_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::historical_entity_type: return get_historical_entity_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::training_knowledge_level: return get_training_knowledge_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_position_flags: return get_entity_position_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_material_category: return get_entity_material_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_event_type: return get_entity_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_raw_flags: return get_entity_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::site_type: return get_site_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ethic_type: return get_ethic_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ethic_response: return get_ethic_response_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_name_type: return get_entity_name_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_position_raw_flags: return get_entity_position_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_position_responsibility: return get_entity_position_responsibility_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::weather_type: return get_weather_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::game_mode: return get_game_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::game_type: return get_game_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::lever_target_type: return get_lever_target_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::zoom_commands: return get_zoom_commands_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reputation_type: return get_reputation_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_flags: return get_histfig_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_relationship_type: return get_histfig_relationship_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mental_picture_property_type: return get_mental_picture_property_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mental_picture_element_type: return get_mental_picture_element_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_type: return get_history_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_reason: return get_history_event_reason_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::death_type: return get_death_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_action_type: return get_entity_action_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::masterpiece_loss_type: return get_masterpiece_loss_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return get_history_event_hist_figure_woundedst__T_injury_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_simple_battle_subtype: return get_history_event_simple_battle_subtype_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_body_state: return get_histfig_body_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return get_history_event_hf_act_on_buildingst__T_action_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::site_dispute_type: return get_site_dispute_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::insurrection_outcome: return get_insurrection_outcome_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return get_history_event_hf_act_on_artifactst__T_action_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tactical_situation: return get_tactical_situation_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_collection_type: return get_history_event_collection_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::era_type: return get_era_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_display_flags: return get_init_display_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_media_flags: return get_init_media_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_input_flags: return get_init_input_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_window_flags: return get_init_window_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_effect_type: return get_interaction_effect_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_effect_location_hint: return get_interaction_effect_location_hint_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_source_type: return get_interaction_source_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_source_usage_hint: return get_interaction_source_usage_hint_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_target_type: return get_interaction_target_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interaction_target_location_type: return get_interaction_target_location_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::breath_attack_type: return get_breath_attack_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::item_type: return get_item_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ammo_flags: return get_ammo_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::armor_general_flags: return get_armor_general_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::armor_flags: return get_armor_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::gloves_flags: return get_gloves_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::helm_flags: return get_helm_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::instrument_flags: return get_instrument_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::sound_production_type: return get_sound_production_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::pitch_choice_type: return get_pitch_choice_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tuning_type: return get_tuning_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::timbre_type: return get_timbre_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::pants_flags: return get_pants_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::shoes_flags: return get_shoes_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tool_flags: return get_tool_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tool_uses: return get_tool_uses_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::toy_flags: return get_toy_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::trapcomp_flags: return get_trapcomp_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::weapon_flags: return get_weapon_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::items_other_id: return get_items_other_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_item_vector_id: return get_job_item_vector_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::improvement_type: return get_improvement_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::itemimprovement_specific_type: return get_itemimprovement_specific_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::written_content_type: return get_written_content_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::written_content_style: return get_written_content_style_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::item_magicness_type: return get_item_magicness_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::item_quality: return get_item_quality_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::slab_engraving_type: return get_slab_engraving_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::corpse_material_type: return get_corpse_material_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_type_class: return get_job_type_class_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_type: return get_job_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_subtype_surgery: return get_job_subtype_surgery_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_art_specification__T_type: return get_job_art_specification__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::manager_order_condition_order__T_condition: return get_manager_order_condition_order__T_condition_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::guild_id: return get_guild_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interface_key: return get_interface_key_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::dfhack_knowledge_scholar_flag: return get_dfhack_knowledge_scholar_flag_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::part_of_speech: return get_part_of_speech_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::sphere_type: return get_sphere_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::language_name_category: return get_language_name_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::nemesis_flags: return get_nemesis_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::machine_type: return get_machine_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::screw_pump_direction: return get_screw_pump_direction_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_traffic: return get_tile_traffic_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_dig_designation: return get_tile_dig_designation_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_liquid: return get_tile_liquid_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_building_occ: return get_tile_building_occ_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tile_liquid_flow_dir: return get_tile_liquid_flow_dir_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::block_square_event_type: return get_block_square_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::feature_type: return get_feature_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::feature_init_flags: return get_feature_init_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::feature_alteration_type: return get_feature_alteration_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_construction_type: return get_world_construction_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::biome_type: return get_biome_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::flow_type: return get_flow_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::flow_guide_type: return get_flow_guide_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::region_block_event_type: return get_region_block_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::craft_material_class: return get_craft_material_class_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::builtin_mats: return get_builtin_mats_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::material_flags: return get_material_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::matter_state: return get_matter_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::strain_type: return get_strain_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::inorganic_flags: return get_inorganic_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::environment_type: return get_environment_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::inclusion_type: return get_inclusion_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::organic_mat_category: return get_organic_mat_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::meeting_topic: return get_meeting_topic_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::meeting_event_type: return get_meeting_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::activity_event_type: return get_activity_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::conversation_menu: return get_conversation_menu_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::performance_event_type: return get_performance_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::performance_participant_type: return get_performance_participant_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::uniform_category: return get_uniform_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::barrack_preference_category: return get_barrack_preference_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::squad_event_type: return get_squad_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::squad_order_type: return get_squad_order_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::squad_order_cannot_reason: return get_squad_order_cannot_reason_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::army_flags: return get_army_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_path_goal: return get_unit_path_goal_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_station_type: return get_unit_station_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::plant_raw_flags: return get_plant_raw_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::projectile_type: return get_projectile_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_flags: return get_reaction_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_reagent_type: return get_reaction_reagent_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_product_type: return get_reaction_product_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_product_item_flags: return get_reaction_product_item_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::reaction_product_improvement_flags: return get_reaction_product_improvement_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::general_ref_type: return get_general_ref_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::specific_ref_type: return get_specific_ref_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_entity_link_type: return get_histfig_entity_link_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_site_link_type: return get_histfig_site_link_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::histfig_hf_link_type: return get_histfig_hf_link_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_entity_link_type: return get_entity_entity_link_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::resource_allotment_specifier_type: return get_resource_allotment_specifier_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::profession: return get_profession_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_labor_category: return get_unit_labor_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_labor: return get_unit_labor_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_skill_class: return get_job_skill_class_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_skill: return get_job_skill_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::hauler_type: return get_hauler_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::furniture_type: return get_furniture_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stockpile_category: return get_stockpile_category_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stockpile_list: return get_stockpile_list_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creature_interaction_effect_type: return get_creature_interaction_effect_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creature_interaction_effect_target_mode: return get_creature_interaction_effect_target_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_shape_basic: return get_tiletype_shape_basic_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_shape: return get_tiletype_shape_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_material: return get_tiletype_material_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_variant: return get_tiletype_variant_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype_special: return get_tiletype_special_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tiletype: return get_tiletype_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::build_req_choice_type: return get_build_req_choice_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_hotkey__T_cmd: return get_ui_hotkey__T_cmd_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_sidebar_mode: return get_ui_sidebar_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::kitchen_exc_type: return get_kitchen_exc_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::timed_event_type: return get_timed_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::emotion_type: return get_emotion_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_thought_type: return get_unit_thought_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::value_type: return get_value_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::goal_type: return get_goal_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::personality_facet_type: return get_personality_facet_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::physical_attribute_type: return get_physical_attribute_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mental_attribute_type: return get_mental_attribute_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mood_type: return get_mood_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ghost_type: return get_ghost_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::animal_training_level: return get_animal_training_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_report_type: return get_unit_report_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::skill_rating: return get_skill_rating_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_relationship_type: return get_unit_relationship_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::need_type: return get_need_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ghost_goal: return get_ghost_goal_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::wound_effect_type: return get_wound_effect_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::misc_trait_type: return get_misc_trait_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_action_type: return get_unit_action_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interface_breakdown_types: return get_interface_breakdown_types_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::embark_finder_option: return get_embark_finder_option_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_image_creator_mode: return get_viewscreen_image_creator_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_kitchenpref_page: return get_viewscreen_kitchenpref_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::adventurer_attribute_level: return get_adventurer_attribute_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_unitlist_page: return get_viewscreen_unitlist_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_population_type: return get_world_population_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_region_type: return get_world_region_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::geo_layer_type: return get_geo_layer_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::region_map_entry_flags: return get_region_map_entry_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::front_type: return get_front_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::cumulus_type: return get_cumulus_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stratus_type: return get_stratus_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::fog_type: return get_fog_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mountain_peak_flags: return get_mountain_peak_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::abstract_building_type: return get_abstract_building_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::abstract_building_flags: return get_abstract_building_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_site_type: return get_world_site_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_site_flags: return get_world_site_flags_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::site_realization_building_type: return get_site_realization_building_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::site_shop_type: return get_site_shop_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::tree_house_type: return get_tree_house_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::hillock_house_type: return get_hillock_house_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::creation_zone_pwg_alteration_type: return get_creation_zone_pwg_alteration_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::worldgen_region_type: return get_worldgen_region_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::worldgen_range_type: return get_worldgen_range_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::units_other_id: return get_units_other_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::conflict_level: return get_conflict_level_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::combat_report_event_type: return get_combat_report_event_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::conversation__T_state: return get_conversation__T_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_archerytargetst__T_archery_direction: return get_building_archerytargetst__T_archery_direction_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_bridgest__T_direction: return get_building_bridgest__T_direction_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_siegeenginest__T_facing: return get_building_siegeenginest__T_facing_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::building_siegeenginest__T_action: return get_building_siegeenginest__T_action_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::caste_body_info__T_interactions__T_type: return get_caste_body_info__T_interactions__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::caravan_state__T_trade_state: return get_caravan_state__T_trade_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return get_entity_event__T_data__T_insurrection_end__T_result_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_change_hf_statest__T_state: return get_history_event_change_hf_statest__T_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_body_abusedst__T_props__T_pile_type: return get_history_event_body_abusedst__T_props__T_pile_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_body_abusedst__T_abuse_type: return get_history_event_body_abusedst__T_abuse_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_hist_figure_travelst__T_reason: return get_history_event_hist_figure_travelst__T_reason_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::history_event_artifact_claim_formedst__T_claim_type: return get_history_event_artifact_claim_formedst__T_claim_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_display__T_windowed: return get_init_display__T_windowed_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::init_font__T_use_ttf: return get_init_font__T_use_ttf_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::job_item_ref__T_role: return get_job_item_ref__T_role_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::manager_order__T_frequency: return get_manager_order__T_frequency_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::manager_order_condition_item__T_compare_type: return get_manager_order_condition_item__T_compare_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mandate__T_mode: return get_mandate__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_demand__T_place: return get_unit_demand__T_place_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return get_ui_advmode__T_conversation__T_targets__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_advmode__T_travel_right_map: return get_ui_advmode__T_travel_right_map_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_advmode__T_show_menu: return get_ui_advmode__T_show_menu_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stop_depart_condition__T_direction: return get_stop_depart_condition__T_direction_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::stop_depart_condition__T_mode: return get_stop_depart_condition__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return get_interface_button_construction_category_selectorst__T_category_id_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return get_ui_sidebar_menus__T_designation__T_mine_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return get_ui_sidebar_menus__T_zone__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return get_ui_sidebar_menus__T_unit__T_expel_error_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_look_list__T_items__T_type: return get_ui_look_list__T_items__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::ui_unit_view_mode__T_value: return get_ui_unit_view_mode__T_value_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit__T_meeting__T_state: return get_unit__T_meeting__T_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit__T_counters__T_soldier_mood: return get_unit__T_counters__T_soldier_mood_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_inventory_item__T_mode: return get_unit_inventory_item__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_preference__T_type: return get_unit_preference__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_complaint__T_type: return get_unit_complaint__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::unit_request__T_type: return get_unit_request__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::KeybindingScreen__T_mode: return get_KeybindingScreen__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_adventure_logst__T_mode: return get_viewscreen_adventure_logst__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return get_viewscreen_adventure_logst__T_info_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return get_viewscreen_assign_display_itemst__T_sel_column_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_choose_start_sitest__T_page: return get_viewscreen_choose_start_sitest__T_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mission__T_details__T_raid__T_raid_type: return get_mission__T_details__T_raid__T_raid_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::mission__T_type: return get_mission__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return get_viewscreen_civlistst__T_rumors__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_civlistst__T_page: return get_viewscreen_civlistst__T_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_game_cleanerst__T_state: return get_viewscreen_game_cleanerst__T_state_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_justicest__T_cur_column: return get_viewscreen_justicest__T_cur_column_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::assign_trade_status__T_status: return get_assign_trade_status__T_status_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return get_viewscreen_layer_choose_language_namest__T_current_component_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return get_viewscreen_layer_militaryst__T_equip__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return get_viewscreen_layer_militaryst__T_equip__T_edit_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_militaryst__T_page: return get_viewscreen_layer_militaryst__T_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return get_viewscreen_layer_noblelistst__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_legendsst__T_cur_page: return get_viewscreen_legendsst__T_cur_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_locationsst__T_in_edit: return get_viewscreen_locationsst__T_in_edit_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_locationsst__T_menu: return get_viewscreen_locationsst__T_menu_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_petst__T_mode: return get_viewscreen_petst__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::setup_character_info__T_status: return get_setup_character_info__T_status_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_setupadventurest__T_page: return get_viewscreen_setupadventurest__T_page_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_setupadventurest__T_sel_trait_column: return get_viewscreen_setupadventurest__T_sel_trait_column_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return get_viewscreen_setupdwarfgamest__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_titlest__T_sel_subpage: return get_viewscreen_titlest__T_sel_subpage_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return get_viewscreen_workquota_conditionst__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::viewscreen_workshop_profilest__T_tab: return get_viewscreen_workshop_profilest__T_tab_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_underground_region__T_type: return get_world_underground_region__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_data__T_flip_latitude: return get_world_data__T_flip_latitude_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return get_abstract_building_dungeonst__T_dungeon_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::cultural_identity__T_group_log__T_join_type: return get_cultural_identity__T_group_log__T_join_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::world_site_realization__T_areas__T_type: return get_world_site_realization__T_areas__T_type_value_decoded(p_node->m_base_type, p_node->m_address);
		case DF_Type::crime__T_mode: return get_crime__T_mode_value_decoded(p_node->m_base_type, p_node->m_address);
		default: break;
	}
	return std::pair<int64_t, std::string>(-1111,"UNKNOWN DF_TYPE");
}

