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

#ifdef _LINUX // Needed for gcc 4.8
namespace std
{
template<>
struct hash<rdf::DF_Type>
{
    typedef rdf::DF_Type argument_type;
    typedef size_t       result_type;

    result_type operator()(const argument_type& x) const
    {
        using type = typename std::underlying_type<argument_type>::type;
        return std::hash<type>()(static_cast<type>(x));
    }
};
} // namespace std
#endif

#include "offsets_cache.h"

namespace rdf

{
std::unordered_map<DF_Type, OffsetTable> OffsetsCache::m_df_types_offset_table;

extern void generate_ui_advmode_menu_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_talk_choice_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_assume_identity_mode_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_text_info_elementst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_text_info_element_longst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_text_info_element_stringst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_optionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_item_interact_choicest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_item_interact_pull_outst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_item_interact_readst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_item_interact_strugglest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_announcement_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_announcement_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_popup_message_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_element_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_element_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_element_creaturest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_element_plantst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_element_treest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_element_shapest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_property_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_property_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_property_verb_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_facet_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_ref_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_action_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_pattern_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_caesura_position_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_mood_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_subject_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_feature_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_additional_feature_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_perspective_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_purpose_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_style_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_pitch_style_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_feature_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_sub4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_interval_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dance_form_sub1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dance_form_sub2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_scale_sub1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_scale_sub2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_rhythm_sub2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_occupation_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_occupation_sub1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_buildings_other_id_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_door_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_gate_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_extents_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_drawbuffer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_hospital_supplies_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_civzone_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_furnace_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_workshop_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_users_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_construction_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_hive_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_shop_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_siegeengine_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_trap_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_pressure_plate_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dfhack_room_quality_level_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_raw_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_part_raw_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_appearance_modifier_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_part_layer_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_appearance_modifier_growth_interval_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_part_layer_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_color_modifier_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_gait_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_gait_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_target_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_graphics_role_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tissue_style_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_graphics_appointment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_variation_convert_tag_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_part_template_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_part_template_contype_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tissue_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_detail_plan_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_nickname_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_z_view_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_embark_confirm_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_idlers_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_tunnel_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_flags1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_flags2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_flags3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_flags4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_pattern_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_descriptor_color_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_descriptor_shape_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_occasion_schedule_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_occasion_schedule_feature_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_activity_statistics__T_food_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_activity_statistics__T_wealth_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_activity_statistics_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_sell_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_sell_requests_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_tissue_style_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_training_knowledge_level_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_position_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_position_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_position_assignment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_material_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ethic_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ethic_response_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_name_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_animal_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_position_raw_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_position_responsibility_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_weather_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_game_mode_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_game_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_lever_target_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_large_integer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_large_integer__T_u_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_large_integer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_renderer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_zoom_commands_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reputation_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_relationship_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_identity_unk_94_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_propertyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_datest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_actionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_toolst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_emotionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_color_patternst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_shapest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_adjectivest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_positionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_property_timest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_element_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_elementst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_element_hfst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_element_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_element_regionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_reason_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_context_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_attacked_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_destroyed_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_created_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_death_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_expels_hfst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_first_contactst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_first_contact_failedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_diplomat_lostst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_agreements_voidedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_merchantst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_hiddenst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_createdst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_lostst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_foundst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_recoveredst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_droppedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_reclaim_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_destroyed_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_site_diedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_site_retiredst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_createdst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_action_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_incorporatedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_created_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_replaced_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_razed_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_createdst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_created_arch_designst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_created_arch_constructst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_created_foodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_masterpiece_loss_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_plundered_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_site_new_leaderst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_site_tribute_forcedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_site_taken_overst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_site_surrenderedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_abductedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_razed_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_creature_devouredst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_woundedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_simple_battle_subtype_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_created_world_constructionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_reunionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_assume_identityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_create_entity_positionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_change_creature_typest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_learns_secretst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_body_state_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_act_on_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_does_interactionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_lawst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_storedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_agreement_formedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_dispute_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_insurrection_startedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_insurrection_outcome_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_attacked_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_performancest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_competitionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_processionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_ceremonyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_transformedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_destroyedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_regionpop_incorporated_into_entityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_act_on_artifactst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_copiedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_sneak_into_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_spotted_leaving_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_searched_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_freedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_simple_actionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_rampaged_in_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_fled_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tactical_situation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_squad_vs_squadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_site_conqueredst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_journeyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_insurrectionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_occasionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_performancest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_competitionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_processionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_ceremonyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_purgest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_era_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_display_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_media_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_media_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_input_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_input_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_window_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_window_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_page_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_location_hint_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_regionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_disturbancest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_usage_hint_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_attackst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_ingestionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_creature_actionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_underground_specialst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_target_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_target_location_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_target_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_breath_attack_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_instance_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_weapon_attack_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ammo_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_armor_general_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_armor_properties_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_armor_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_foodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_gloves_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_helm_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_instrument_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_sound_production_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_pitch_choice_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tuning_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_timbre_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_instrument_piece_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_pants_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_shieldst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_shoes_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_siegeammost_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tool_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tool_uses_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_toy_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_toyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_trapcomp_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_weapon_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_items_other_id_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_item_vector_id_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_improvement_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_specific_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_written_content_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_written_content_style_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_engraving_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_flags2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_magicness_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_temperaturest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_quality_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_slab_engraving_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_part_status_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_layer_status_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_size_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_corpse_material_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_matstate_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_stockpile_ref_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_type_class_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_material_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dfhack_material_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_subtype_surgery_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_item_flags1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_item_flags2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_item_flags3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_manager_order_status_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_art_specification_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_manager_order_condition_order_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_guild_id_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_training_assignment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_key_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_0_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_5_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_6_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_9_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_10_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_11_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_12_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_flags_13_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dfhack_knowledge_scholar_flag_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_language_word_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_part_of_speech_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_sphere_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_language_translation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_language_symbol_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_language_name_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_invasion_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_nemesis_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_machine_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_machine_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_power_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_machine_conn_modes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_screw_pump_direction_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_coord2d_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_coord2d_path_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_coord_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_coord_path_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_traffic_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_dig_designation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_liquid_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_designation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_building_occ_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_occupancy_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_z_level_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_liquid_flow_dir_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_liquid_flow_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tile_bitmask_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_cave_column_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_cave_column_rectangle_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_material_spatterst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_grassst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_spoorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_designation_priorityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_alteration_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_alteration_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_alteration_new_pop_maxst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_alteration_new_lava_fill_zst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_biome_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_construction_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_flow_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_flow_reuse_pool_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_flow_guide_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_flow_guide_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_region_block_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_region_block_eventst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_region_block_event_sphere_fieldst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_craft_material_class_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_builtin_mats_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_matter_state_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_strain_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_vec_ref_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_inorganic_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_environment_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_inclusion_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_organic_mat_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_stepst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_setvarst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_simpleactionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_conditionalst__T_condition_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_conditionalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_textviewerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_diphistoryst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_discussst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_topicdiscussionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_constructtopiclistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_eventst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_dipeventst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_step_invasionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_varst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_var_unitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_script_var_longst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_active_script_varst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_active_script_var_longst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_meeting_topic_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_meeting_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_participants_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_conversation_menu_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_performance_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_performance_participant_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_schedule_slot_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_uniform_indiv_choice_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_use_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_uniform_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_uniform_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_barrack_preference_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_cannot_reason_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_kill_listst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_defend_burrowsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_patrol_routest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_trainst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_drive_entity_off_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_cause_trouble_for_entityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_kill_hfst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_drive_armies_from_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub5_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub6_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub16_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub17_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub18_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_path_goal_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_station_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_raw_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_growth_print_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_tree_tile_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_projectile_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_projectile_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_reagent_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_reagent_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_product_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_product_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_product_item_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_product_improvement_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_artifact_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_nemesis_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_coinbatch_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_entity_art_image_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_projectile_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_entity_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_locationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_interactionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_abstract_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_historical_eventst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_subregionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_feature_layerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_historical_figurest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_entity_popst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_creaturest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_activity_eventst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_languagest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_written_contentst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_poetic_formst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_musical_formst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_dance_formst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_is_artifactst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_is_nemesisst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_contains_unitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_contains_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_contained_in_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_milkeest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_traineest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_itemownerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_tradebringerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_holderst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_workerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_cageest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_beateest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_foodreceiverst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_kidnapeest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_patientst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_infantst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_slaughtereest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_sheareest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_suckeest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_reporteest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_riderst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_climberst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_unit_geldeest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_civzone_assignedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_triggerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_triggertargetst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_chainst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_cagedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_holderst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_well_tag_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_use_target_1st_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_use_target_2st_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_destinationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_nest_boxst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_building_display_furniturest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_entity_stolenst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_entity_offeredst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_entity_itemownerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_specific_ref_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_memberst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_former_memberst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_mercenaryst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_former_mercenaryst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_slavest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_former_slavest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_prisonerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_former_prisonerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_enemyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_criminalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_positionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_former_positionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_position_claimst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_squadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_former_squadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_occupationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_entity_link_former_occupationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_seat_of_powerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_hangoutst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_home_site_abstract_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_home_site_realization_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_lairst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_home_site_realization_sulst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_home_site_saved_civzonest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_site_link_occupationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_motherst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_fatherst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_spousest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_childst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_deityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_loverst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_prisonerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_imprisonerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_masterst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_apprenticest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_companionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_former_apprenticest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_former_masterst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_histfig_hf_link_pet_ownerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_entity_link_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_cropst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_stonest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_metalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_woodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_armor_bodyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_armor_pantsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_armor_glovesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_armor_bootsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_armor_helmst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_clothing_bodyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_clothing_pantsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_clothing_glovesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_clothing_bootsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_clothing_helmst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_weapon_meleest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_weapon_rangedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_ammost_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_anvilst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_gemsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_threadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_clothst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_leatherst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_quiverst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_backpackst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_flaskst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_bagst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_tablest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_cabinetst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_chairst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_boxst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_bedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_craftsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_meatst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_bonest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_hornst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_shellst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_tallowst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_toothst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_pearlst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_soapst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_extractst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_cheesest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_skinst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_specifier_powderst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_profession_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_labor_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_labor_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_skill_class_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_skill_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_hauler_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_furniture_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_category_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_group_set_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_list_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_route_stockpile_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_cie_add_tag_mask1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_cie_add_tag_mask2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_target_mode_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_syndrome_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tiletype_shape_basic_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tiletype_shape_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tiletype_material_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tiletype_variant_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tiletype_special_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tiletype_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_build_req_choice_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_build_req_choicest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_burrow_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_hotkey_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_hotkey_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_mode_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_kitchen_exc_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_timed_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_map_viewport_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_emotion_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_thought_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_flags1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_flags2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_flags3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_flags4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_value_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_goal_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_personality_facet_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_physical_attribute_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_attribute_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mood_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ghost_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_animal_training_level_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_report_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_skill_rating_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_relationship_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_need_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ghost_goal_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_genes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_attribute_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_wound_effect_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_wound_damage_flags1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_wound_damage_flags2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_curse_attr_change_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_misc_trait_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_item_wrestle_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_item_use_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_health_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_bp_health_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_orientation_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_unk_138_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_coin_debt_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_vermin_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_file_compressorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_breakdown_types_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_layer_object_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_layer_object_buttonst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_widget_menu_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_widget_textbox_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_log_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_embark_finder_option_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creator_mode_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_kitchenpref_page_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_kitchen_pref_flag_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_health_view_bits1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_health_view_bits2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_health_view_bits3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_gen_param_basest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_gen_param_seedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_gen_param_valuest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_gen_param_charst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_gen_param_memberst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_matgloss_list_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventurer_attribute_level_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_unitlist_page_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_population_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_population_ref_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_region_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_geo_layer_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_region_map_entry_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_front_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_cumulus_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stratus_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_fog_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mountain_peak_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_scribejob_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_reputation_report_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_contents_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_inhabitant_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_infost_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tower_shape_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_castle_courtyardst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_shop_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tree_house_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_hillock_house_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creation_zone_pwg_alteration_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creation_zone_pwg_alterationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creation_zone_pwg_alteration_campst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creation_zone_pwg_alteration_srb_ruinedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creation_zone_pwg_alteration_srp_ruinedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_worldgen_region_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_worldgen_range_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_units_other_id_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_conflict_level_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident_hfid_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mission_campaign_report_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_coord_rect_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_unk_a8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_unk_b4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_combat_report_event_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ocean_wave_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_coin_batch__T_image_front_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_coin_batch__T_image_back_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_coin_batch_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_conversation__T_speech_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_conversation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_talk_choice__T_unk_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_talk_choice_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_option_eat_item_contaminantst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_optionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_place_in_it_containerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_ingest_from_containerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_pickup_ignite_vegst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_ingest_materialst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_pickup_make_campfirest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_place_in_bld_containerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_pickup_vermin_eventst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_pickup_chop_treest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_environment_unit_suck_bloodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_optionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_release_hold_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_release_hold_tilest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_attack_creaturest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_hold_tilest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_movest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_climbst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_hold_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_building_interactst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_item_interactst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_item_interact_guidest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_item_interact_ridest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_movement_item_interact_pushst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_item_interact_heat_from_tilest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_item_interact_fill_from_containerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_item_interact_fill_with_materialst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_item_interact_give_namest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_announcements_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_report_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_element_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_property_transitive_verbst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_property_intransitive_verbst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_chunk_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_part__T_line_subject_targets_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_part_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_vocals_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_instruments_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_melodies_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_scale__T_unk1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_scale_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_rhythm_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_rhythm_sub1__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_rhythm_sub1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_occupation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_def_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_def_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_def_workshopst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_def_furnacest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building__T_job_claim_suppress_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building__T_activities_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_links_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_civzonest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_actual__T_contained_items_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_actual_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_design_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_workshop_profile_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_furnacest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_workshopst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_animaltrapst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_archerytargetst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_armorstandst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_bars_verticalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_bars_floorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_bedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_bookcasest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_boxst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_bridgest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_cabinetst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_cagest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_chainst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_chairst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_coffinst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_constructionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_display_furniturest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_doorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_farmplotst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_floodgatest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_grate_floorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_grate_wallst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_hatchst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_hivest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_instrumentst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_nestst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_nest_boxst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_roadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_road_dirtst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_road_pavedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_shopst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_siegeenginest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_slabst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_statuest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_supportst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_tablest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_traction_benchst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_tradedepotst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_trapst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_wagonst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_weaponst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_squad_use_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_weaponrackst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_wellst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_windowst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_window_glassst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_window_gemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_part_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_appearance_modifier_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_bp_appearance_modifier_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_clothing_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_attack_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_body_info__T_interactions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_body_info__T_extra_butcher_objects_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_body_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_misc_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_personality_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_attributes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_bp_appearance_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_shearable_tissue_layer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_caste_profession_name_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_extracts_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_secretion_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw__T_unknown2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caste_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tissue_style_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_raw__T_graphics_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_raw__T_profession_name_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_raw__T_hive_product_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_variation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_part_template_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_template_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tissue_template_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_tissue_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init__T_wound_color_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init__T_store_dist_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_d_init_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_descriptor_pattern_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_occasion_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_occasion_schedule_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_occasion_schedule_feature_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_caravan_state_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_buy_prices_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_buy_requests_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_sell_prices_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_recipe_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_uniform_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_uniform_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_invasion_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_abduction_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_incident_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_occupation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_beast_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_group_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_harass_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_flee_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_abandon_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_reclaimed_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_founded_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_reclaiming_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_founding_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_leave_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_insurrection_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_insurrection_end_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_succession_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_claim_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_accept_tribute_offer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_refuse_tribute_offer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_accept_tribute_demand_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_refuse_tribute_demand_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_accept_peace_offer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_refuse_peace_offer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_cease_tribute_offer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_in_site_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_in_subregion_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_in_feature_layer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_in_inventory_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_not_in_site_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_not_in_subregion_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_not_in_feature_layer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_not_in_inventory_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data__T_artifact_destroyed_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event__T_data_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_event_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_agreement__T_parties__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_agreement__T_parties_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_agreement__T_details__T_data__T_data0_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_agreement__T_details__T_data__T_data1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_agreement__T_details__T_data_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_agreement__T_details_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_agreement_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_position_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_graphic_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_kills_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_hit_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_diedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_add_hf_entity_linkst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_remove_hf_entity_linkst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_topicagreement_concludedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_topicagreement_rejectedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_topicagreement_madest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_peace_acceptedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_peace_rejectedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_possessedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_entity_actionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_add_hf_site_linkst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_remove_hf_site_linkst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_add_hf_hf_linkst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_remove_hf_hf_linkst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_created_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_created_dye_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_created_item_improvementst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_created_engravingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_masterpiece_lostst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_change_hf_statest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_change_hf_jobst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_war_field_battlest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_body_abusedst__T_props__T_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_body_abusedst__T_props__T_hung_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_body_abusedst__T_props_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_body_abusedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_item_stolenst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_simple_battle_eventst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_reach_summitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_travelst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_new_petst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hist_figure_revivedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_change_hf_body_statest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_confrontedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_gains_secret_goalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_site_disputest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_agreement_concludedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_insurrection_endedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_relationship_deniedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_poetic_form_createdst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_musical_form_createdst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_dance_form_createdst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_written_content_composedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_change_hf_moodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_claim_formedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_artifact_givenst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hf_recruited_unit_type_for_entityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_hfs_formed_reputation_relationshipst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_tactical_situationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_duelst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_abductionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_theftst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_beast_attackst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_raidst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_era__T_title_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_era__T_details_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_era_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_display_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_font_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_init_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_texture_handler_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_animatest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_add_syndromest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_resurrectst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_cleanst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_contactst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_material_emissionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_effect_hidest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_secretst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_source_deityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_target_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_target_corpsest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_target_creaturest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_target_materialst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interaction_target_locationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_ammost_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_armorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_glovesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_helmst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_instrumentst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_instrument_register_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_pantsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_shoesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_toolst__T_default_improvements_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_toolst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_trapcompst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemdef_weaponst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dye_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_art_imagest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_coveredst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_rings_hangingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_bandsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_spikesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_itemspecificst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_threadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_clothst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_sewn_imagest__T_cloth_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_sewn_imagest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_pagesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_illustrationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_instrument_piecest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_itemimprovement_writingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_written_content_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_engraving_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_magicness_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_spatter_common_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_option_eat_unit_contaminantst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_adventure_option_view_contaminantst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_spatter_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_kill_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_history_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_actual_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_crafted_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_constructed_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_body_component_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_body_component__T_body_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_body_component__T_appearance_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_body_component__T_bone1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_body_component__T_bone2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_body_component_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_corpsest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_corpsepiecest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_liquipowder_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_liquid_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_powder_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_barst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_smallgemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_blocksst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_roughst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_boulderst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_woodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_branchst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_rockst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_seedsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_skin_tannedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_meatst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_plantst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_plant_growthst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_cheesest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_globst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_remainsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_fishst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_fish_rawst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_foodst__T_ingredients_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_foodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_drinkst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_powder_miscst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_liquid_miscst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_threadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_eggst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_doorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_floodgatest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_bedst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_chairst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_chainst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_flaskst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_gobletst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_windowst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_cagest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_bucketst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_animaltrapst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_tablest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_coffinst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_boxst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_armorstandst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_weaponrackst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_cabinetst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_amuletst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_scepterst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_crownst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_ringst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_earringst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_braceletst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_anvilst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_backpackst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_quiverst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_catapultpartsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_ballistapartsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_trappartsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_pipe_sectionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_hatch_coverst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_gratest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_quernst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_millstonest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_splintst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_crutchst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_traction_benchst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_instrumentst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_toyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_armorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_shoesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_shieldst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_helmst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_glovesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_pantsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_siegeammost_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_weaponst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_ammost_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_trapcompst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_toolst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_barrelst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_binst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_gemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_statuest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_figurinest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_slabst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_orthopedic_castst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_coinst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_totemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_clothst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_bookst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_ballistaarrowheadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_sheetst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_list_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_item_ref_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_item_filter_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_manager_order_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_manager_order_condition_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_manager_order_template_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mandate__T_punishment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mandate_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_demand_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_category_flag__T_flags_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_knowledge_scholar_category_flag_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_knowledge_discoveredst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_language_word_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_language_name_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_v40_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_3170__T_unk_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_3170_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_3124_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_conversation__T_choices_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_conversation__T_targets_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_conversation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_companions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_interactions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_v40_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_v40_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_v40_4__T_unk_v40_4a_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_v40_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_v40_5_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_unk_v42_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode__T_assume_identity_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_advmode_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_art_image_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_poetic_form_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_musical_form_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dance_form_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_occasion_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_resources__T_metal_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_resources__T_organic_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_resources__T_refuse_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_resources__T_misc_mat_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_resources__T_wood_products_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_resources__T_animals_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_resources__T_unk13_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_resources_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_unknown1b__T_unk32e_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_unknown1b__T_diplomacy_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_unknown1b_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_positions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_tissue_styles_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_unknown1d_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_training_knowledge_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_unknown1e_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_derived_resources_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_claims_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity__T_unknown2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_entity_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure__T_unk_fc_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_identity_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_warst__T_unk_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_warst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_history_event_collection_battlest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_history__T_event_collections_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_history_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_critter_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_verminst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_petst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_language_word_table_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw__T_equipment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw__T_symbols_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw__T_progress_trigger_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw__T_jobs_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw__T_tissue_styles_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw__T_workshops_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw__T_land_holder_trigger_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_population_unk4__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_population_unk4__T_anon_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_population_unk4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_population_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_nemesis_record_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_artifact_record_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_machine_tile_set_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_machine__T_components_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_machine_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_machine_standardst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_axle_horizontalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_axle_verticalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_gear_assemblyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_windmillst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_water_wheelst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_screw_pumpst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_rollersst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_burrow_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_burrow_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_map_block_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_cave_column_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_map_block_column__T_unmined_glyphs_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_map_block_column_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_mineralst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_frozen_liquidst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_world_constructionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_block_square_event_item_spatterst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_outdoor_riverst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_cavest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_pitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_magma_poolst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_volcanost_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_deep_special_tubest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_deep_surface_portalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_subterranean_from_layerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_magma_core_from_layerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_underworld_from_layerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_outdoor_riverst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_cavest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_pitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_magma_poolst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_volcanost_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_deep_special_tubest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_deep_surface_portalst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_subterranean_from_layerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_magma_core_from_layerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_feature_init_underworld_from_layerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_square_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_square_roadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_square_tunnelst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_square_bridgest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_square_wallst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_roadst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_tunnelst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_bridgest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_construction_wallst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_construction_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_flow_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_flow_guide_trailing_flowst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_flow_guide_item_cloudst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_effect_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_common__T_heat_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_common__T_strength_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_common__T_reaction_product_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_common__T_hardens_with_water_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_common_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_material_template_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_inorganic_raw__T_metal_ore_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_inorganic_raw__T_thread_metal_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_inorganic_raw__T_environment_spec_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_inorganic_raw__T_environment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_inorganic_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_special_mat_table_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dipscript_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_dipscript_popup_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_active_script_var_unitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_meeting_context_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_meeting_diplomat_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_meeting_event_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_party_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_room_rent_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_entry_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event__T_unk_v42_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event__T_unk_v42_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_training_sessionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_combat_trainingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_skill_demonstrationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_individual_skill_drillst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_sparringst__T_groups_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_sparringst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_ranged_practicest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_harassmentst__T_anon_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_harassmentst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conversationst__T_participants_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conversationst__T_anon_6_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conversationst__T_unk_b4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conversationst__T_turns_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conversationst__T_unk2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conversationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conflictst__T_sides__T_enemies_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conflictst__T_sides_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_conflictst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_guardst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_reunionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_prayerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_socializest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_worshipst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_performancest__T_participant_actions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_performancest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_performance_play_orderst__T_anon_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_performance_play_orderst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_researchst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_ponder_topicst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_discuss_topicst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_readst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_fill_service_orderst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_writest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_copy_written_contentst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_teach_topicst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_playst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_make_believest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_play_with_toyst__T_unk_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_play_with_toyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_encounterst__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_encounterst__T_anon_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_encounterst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_activity_event_store_objectst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_schedule_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_item_filter_spec_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_uniform_spec_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_ammo_spec_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_position_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_schedule_order_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_schedule_entry_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad__T_rooms_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_movest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_retrieve_artifactst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_raid_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_squad_order_rescue_hfst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller__T_unk_64_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub2__T_anon_5_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub7__T_anon_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub11__T_anon_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub11_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub12__T_anon_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub12_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub13__T_anon_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub13_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub14__T_anon_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub14_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub15__T_anon_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_controller_sub15_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army__T_members_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army__T_unk_2c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_army_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_raw__T_tiles_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_raw__T_colors_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_raw__T_material_defs_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_raw_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_growth_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_plant_tree_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_proj_list_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_projectile_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_proj_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_proj_unitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_proj_magicst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_handler_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_plants_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_bodyglosses_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_itemdefs_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_language_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_descriptors_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_reactions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_buildings_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_syndromes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws__T_effects_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_raws_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction__T_building_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_description_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_reagent_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_reagent_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_product_itemst__T_get_material_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_product_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_product_item_improvementst__T_get_material_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_reaction_product_item_improvementst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_item_type_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_mapsquare_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_spherest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_knowledge_scholar_flagst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_general_ref_value_levelst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_specific_ref_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_specific_ref__T_arg2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_specific_ref_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_meeting_variable_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_entity_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_site_link__T_anon_8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_site_link_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_data__T_unk_654_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_resource_allotment_data_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_animals_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_food_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_furniture_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_refuse_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_stone_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_ore_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_ammo_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_coins_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_bars_blocks_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_gems_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_finished_goods_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_leather_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_cloth_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_wood_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_weapons_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_armor_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings__T_sheet_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stockpile_settings_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_stockpilest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_hauling_route_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_hauling_stop_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_stop_depart_condition_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_vehicle_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_target_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect__T_counter_trigger_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_painst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_swellingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_oozingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_bruisingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_blistersst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_numbnessst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_paralysisst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_feverst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_bleedingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_cough_bloodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_vomit_bloodst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_nauseast_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_unconsciousnessst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_necrosisst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_impair_functionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_drowsinessst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_dizzinessst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_display_namest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_body_appearance_modifierst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_bp_appearance_modifierst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_body_transformationst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_skill_roll_adjustst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_display_symbolst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_flash_symbolst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_phys_att_changest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_ment_att_changest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_add_simple_flagst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_remove_simple_flagst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_speed_changest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_body_mat_interactionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_material_force_adjustst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_can_do_interactionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_sense_creature_classst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_feel_emotionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_change_personalityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creature_interaction_effect_erratic_behaviorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_syndrome_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_build_item_req_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_build_req_choice_genst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_build_req_choice_specst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_build_selector_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_building_category_selectorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_building_material_selectorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_building_new_jobst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_building_custom_category_selectorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_constructionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_construction_donest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_construction_category_selectorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interface_button_construction_building_selectorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_designation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_workshop_job_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_building_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_zone_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_unit_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_hospital_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_location_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_job_details_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_unit_cursor_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_unit_skills_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_barracks_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_minimap_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus__T_command_line_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_sidebar_menus_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_look_list__T_items_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_look_list__T_items_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_look_list_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_unit_view_mode_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_punishment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_timed_event_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_map_renderer__T_anon_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_map_renderer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_path_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_meeting_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_military_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_animal_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_opponent_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_job_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_body_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_appearance_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_counters_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_curse_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_counters2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_status__T_eat_history__T_food_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_status__T_eat_history__T_drink_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_status__T_eat_history_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_status_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_status2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_unknown7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_syndromes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_reports_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_undead_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_witness_reports_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_unk_448__T_unk_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_unk_448_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_unk_44c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_unk_v40_sub3__T_unk_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_unk_v40_sub3__T_unk_6_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_unk_v40_sub3__T_unk_7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy__T_unk_v40_sub3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit__T_enemy_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_ghost_info__T_target_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_ghost_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_inventory_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_syndrome__T_symptoms_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_syndrome_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_wound__T_parts_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_wound_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_wound_curse_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_misc_trait_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_health_info__T_op_history__T_info__T_crutch_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_health_info__T_op_history__T_info__T_bandage_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_health_info__T_op_history__T_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_health_info__T_op_history_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_health_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_instrument_skill_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_poetic_skill_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_musical_skill_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_dance_skill_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_emotion_memory_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_values_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_unk_v40_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_emotions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_dreams_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_unk_v40_6_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_unk5_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_needs_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_memories__T_reflected_on_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality__T_memories_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_personality_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_skills_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_personality_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_masterpieces_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_unk_14_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_wounds_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_secret__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_secret__T_anon_7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_secret__T_knowledge_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_secret__T_unk_a8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_secret_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_curse_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_books_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_reputation__T_wanted_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_reputation__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_reputation__T_unk_2c__T_anon_12_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_reputation__T_unk_2c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_reputation_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_relationships__T_list_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_relationships__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_relationships__T_anon_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_relationships__T_anon_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info__T_relationships_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_historical_figure_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_soul__T_performance_skills_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_soul_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_move_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_attack__T_unk_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_attack_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_jump_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_holdterrain_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_releaseterrain_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_climb_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_job_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_talk_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_unsteady_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_parry_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_block_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_dodge_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_recover_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_standup_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_liedown_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_job2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_pushobject_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_suckblood_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_holditem_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data__T_releaseitem_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action__T_data_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_action_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_skill_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_preference_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_preference_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_complaint_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_request_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_chunk__T_units_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_chunk_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_appearance_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_vermin_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_interfacest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_layer_object_listst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_KeybindingScreen_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_MacroScreenLoad_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_MacroScreenSave_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_dat_summary_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_adopt_regionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_adventure_logst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_announcelistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_assign_display_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_barterst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_buildingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_buildinglistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_embark_location_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_choose_start_sitest__T_finder_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_choose_start_sitest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mission__T_details__T_raid_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mission__T_details__T_recovery_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mission__T_details__T_rescue_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mission__T_details__T_request_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mission__T_details_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mission_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_civlistst__T_artifact_details_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_civlistst__T_rumors_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_civlistst__T_unk_cache__T_tmp1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_civlistst__T_unk_cache__T_tmp2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_civlistst__T_unk_cache_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_civlistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_createquotast_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_customize_unitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_dungeon_monsterstatusst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_dungeon_wrestlest__T_unk1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_dungeon_wrestlest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_dungeonmodest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_dwarfmodest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_entityst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_export_graphical_mapst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_export_regionst__T_unk1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_export_regionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_game_cleanerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst__T_descriptions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst__T_sites_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst__T_entities_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst__T_plants_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst__T_trees_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst__T_shapes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst__T_objects_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst__T_artifacts_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_image_creatorst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_itemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_jobst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_joblistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_jobmanagementst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_justicest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_kitchenprefst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_arena_creaturest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_assign_trade_status_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_assigntradest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_choose_language_namest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_currencyst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_export_play_mapst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_squads_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_positions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_squad_members_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_equip__T_assigned_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_equip__T_uniform_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_equip__T_add_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_equip__T_material_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_equip__T_color_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_equip_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_ammo__T_add_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_ammo__T_material_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst__T_ammo_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_militaryst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_musicsoundst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_unit_storage_status_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_noblelistst__T_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_noblelistst__T_candidates_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_noblelistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_overall_healthst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_reactionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_squad_schedulest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_stockpilest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_stone_restrictionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_unit_actionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_unit_healthst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_unit_relationshipst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_world_gen_paramst__T_unk1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_world_gen_paramst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_layer_world_gen_param_presetst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_legendsst__T_anon_7__T_anon_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_legendsst__T_anon_7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_legendsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_locationsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_loadgame_save_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_loadgamest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_meetingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_movieplayerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_new_regionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_noblest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_optionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_overallstatusst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_petitionsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_petst__T_animal_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_petst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_pricest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_reportlistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_requestagreementst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_nemesis_offload_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_tax_collection_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_becoming_capital_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_invasions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_kitchen_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_economy_prices__T_price_adjustment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_economy_prices__T_price_setter_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_economy_prices_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_stockpile_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_unk2a8c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_map_edge_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_waypoints__T_points_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_waypoints__T_routes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_waypoints_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_burrows_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_alerts__T_list_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_alerts_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_equipment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_hauling_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_main__T_dead_citizens_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_main_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui__T_squads_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_ui_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_savegamest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_selectitemst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_setup_character_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_setupadventurest__T_races_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_setupadventurest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_embark_item_choice__T_list_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_embark_item_choice_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_embark_profile_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_setupdwarfgamest__T_animals_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_setupdwarfgamest__T_unk_v43_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_setupdwarfgamest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_storesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_textviewerst__T_formatted_text_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_textviewerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_titlest__T_start_savegames_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_titlest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_topicmeetingst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_topicmeeting_fill_land_holder_positionsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_topicmeeting_takerequestsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_tradeagreementst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_tradegoodsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_tradelistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_treasurelistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_unitst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_unitlistst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_wagesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_workquota_conditionst__T_traits_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_workquota_conditionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_workquota_detailsst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_workshop_profilest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_viewscreen_update_regionst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_unk130__T_unk_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_unk130_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_embark_note_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_local_population_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_local_population_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_population_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_population_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_landmass_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_region_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_underground_region_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_river_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_geo_layer_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_geo_biome_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_region_feature_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_region_details__T_edges_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_region_details__T_rivers_vertical_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_region_details__T_rivers_horizontal_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_region_details_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_region_map_entry_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_claim_mask__T_map_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_entity_claim_mask_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_moving_party__T_members_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_moving_party_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_object_data__T_offloaded_items_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_object_data__T_offloaded_buildings_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_object_data__T_unk_94_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_object_data_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_b4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_constructions_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_150__T_unk_8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_150__T_unk_18_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_150__T_unk_28_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_150_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_170__T_unk_4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_170_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_freakish_weather_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_mountain_peaks_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_feature_map__T_features_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_feature_map_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_274__T_unk_10_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_274_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data__T_unk_482f8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_data_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_reputation_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_location_scribe_jobs_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_unk__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_unk_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building__T_inhabitants_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building__T_unk1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_keepst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_templest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_dark_towerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_marketst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_tombst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_dungeonst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_underworld_spirest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_inn_tavernst__T_room_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_inn_tavernst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_libraryst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_1__T_units_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_118_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_13c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_v40_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_subtype_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_21c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_v40_4a_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_v40_4b_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_v40_4c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_v40_4d__T_anon_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_v40_4d_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_v43_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_188__T_unk1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site__T_unk_188_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_cultural_identity__T_group_log_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_cultural_identity_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_crossroads_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_building_item_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_abstract_building_mead_hallst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building__T_unk_4c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_realization__T_river_map_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_realization__T_unk_55e8__T_unk_v40_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_realization__T_unk_55e8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_realization__T_building_map_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_realization__T_areas_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_realization__T_unk_193bc__T_unk_8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_realization__T_unk_193bc_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_site_realization_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_castle_wallst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_castle_towerst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_shop_housest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_market_squarest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_trenchesst__T_spokes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_trenchesst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_tree_housest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_site_realization_building_info_hillock_housest_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creation_zone_pwg_alteration_location_deathst__T_unk_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_creation_zone_pwg_alteration_location_deathst_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident__T_unk_v42_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident_sub6_performance__T_participants_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident_sub6_performance_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident_sub7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident_sub8_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident_sub9_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_incident_sub10_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_crime__T_punishment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_crime__T_reports_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_crime_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mission_report_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_spoils_report_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_unk_20__T_anon_7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_unk_20_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_unk_6c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_unk_9c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_unk_c0__T_anon_7_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_unk_c0_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_glowing_barrier_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_deep_vein_hollow_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_campfire_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_web_cluster_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_fire_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_handler__T_postings_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_handler__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_job_handler_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_building_handler_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_machine_handler_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_mental_picture_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_belief_system_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_vermin_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_entities_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_worldgen_coord_buf_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_units_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_nemesis_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_items_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_artifacts_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_flow_guides_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_stockpile__T_simple1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_stockpile__T_simple2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_stockpile__T_simple3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_stockpile_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_plants_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_enemy_status_cache_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_schedules_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_squads_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_formations_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_activities_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_status__T_slots_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_status_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_interaction_instances_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_written_contents_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_identities_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_incidents_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_crimes_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_vehicles_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_armies_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_army_controllers_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_army_tracking_info_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_cultural_identities_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_agreements_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_poetic_forms_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_musical_forms_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_dance_forms_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_scales_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_rhythms_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_occupations_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_belief_systems_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_map_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_profession_skills_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_math__T_approx_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_math_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_map_extras_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_worldgen_status_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_59dc4__T_unk1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_59dc4_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_flow_engine_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_worldgen__T_worldgen_parms_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_worldgen_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_v40_6_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_131ec0_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_languages_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_131ef0__T_unk_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_131ef0_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_pathfinder__T_boundary_heap_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_pathfinder_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_cur_savegame_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_features_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_arena_spawn__T_item_types_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_arena_spawn__T_equipment_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_arena_spawn_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_arena_settings_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_19325c__T_anon_1_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_19325c__T_anon_2_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_19325c__T_anon_3_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world__T_unk_19325c_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_world_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_T_cursor_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

extern void generate_T_selection_rect_offsets(void* p_df_structure, std::unordered_map<std::string, std::size_t>& p_table);

void fill_offsets(DF_Type p_type, OffsetTable& p_table)

{
    switch (p_type)

    {
        case DF_Type::abstract_building:
            generate_abstract_building_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building__T_inhabitants:
            generate_abstract_building__T_inhabitants_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building__T_unk1:
            generate_abstract_building__T_unk1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_contents:
            generate_abstract_building_contents_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_dark_towerst:
            generate_abstract_building_dark_towerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_dungeonst:
            generate_abstract_building_dungeonst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_inn_tavernst:
            generate_abstract_building_inn_tavernst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_inn_tavernst__T_room_info:
            generate_abstract_building_inn_tavernst__T_room_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_keepst:
            generate_abstract_building_keepst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_libraryst:
            generate_abstract_building_libraryst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_marketst:
            generate_abstract_building_marketst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_mead_hallst:
            generate_abstract_building_mead_hallst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_templest:
            generate_abstract_building_templest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_tombst:
            generate_abstract_building_tombst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_underworld_spirest:
            generate_abstract_building_underworld_spirest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_unk:
            generate_abstract_building_unk_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::abstract_building_unk__T_anon_1:
            generate_abstract_building_unk__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::active_script_var_longst:
            generate_active_script_var_longst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::active_script_var_unitst:
            generate_active_script_var_unitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::active_script_varst:
            generate_active_script_varst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_entry:
            generate_activity_entry_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event:
            generate_activity_event_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event__T_unk_v42_1:
            generate_activity_event__T_unk_v42_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event__T_unk_v42_2:
            generate_activity_event__T_unk_v42_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_combat_trainingst:
            generate_activity_event_combat_trainingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conflictst:
            generate_activity_event_conflictst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conflictst__T_sides:
            generate_activity_event_conflictst__T_sides_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conflictst__T_sides__T_enemies:
            generate_activity_event_conflictst__T_sides__T_enemies_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conversationst:
            generate_activity_event_conversationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conversationst__T_anon_6:
            generate_activity_event_conversationst__T_anon_6_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conversationst__T_participants:
            generate_activity_event_conversationst__T_participants_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conversationst__T_turns:
            generate_activity_event_conversationst__T_turns_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conversationst__T_unk2:
            generate_activity_event_conversationst__T_unk2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_conversationst__T_unk_b4:
            generate_activity_event_conversationst__T_unk_b4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_copy_written_contentst:
            generate_activity_event_copy_written_contentst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_discuss_topicst:
            generate_activity_event_discuss_topicst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_encounterst:
            generate_activity_event_encounterst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_encounterst__T_anon_1:
            generate_activity_event_encounterst__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_encounterst__T_anon_2:
            generate_activity_event_encounterst__T_anon_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_fill_service_orderst:
            generate_activity_event_fill_service_orderst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_guardst:
            generate_activity_event_guardst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_harassmentst:
            generate_activity_event_harassmentst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_harassmentst__T_anon_2:
            generate_activity_event_harassmentst__T_anon_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_individual_skill_drillst:
            generate_activity_event_individual_skill_drillst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_make_believest:
            generate_activity_event_make_believest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_participants:
            generate_activity_event_participants_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_performancest:
            generate_activity_event_performancest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_performancest__T_participant_actions:
            generate_activity_event_performancest__T_participant_actions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_play_with_toyst:
            generate_activity_event_play_with_toyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_play_with_toyst__T_unk:
            generate_activity_event_play_with_toyst__T_unk_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_playst:
            generate_activity_event_playst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_ponder_topicst:
            generate_activity_event_ponder_topicst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_prayerst:
            generate_activity_event_prayerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_ranged_practicest:
            generate_activity_event_ranged_practicest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_readst:
            generate_activity_event_readst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_researchst:
            generate_activity_event_researchst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_reunionst:
            generate_activity_event_reunionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_skill_demonstrationst:
            generate_activity_event_skill_demonstrationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_socializest:
            generate_activity_event_socializest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_sparringst:
            generate_activity_event_sparringst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_sparringst__T_groups:
            generate_activity_event_sparringst__T_groups_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_store_objectst:
            generate_activity_event_store_objectst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_teach_topicst:
            generate_activity_event_teach_topicst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_training_sessionst:
            generate_activity_event_training_sessionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_worshipst:
            generate_activity_event_worshipst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_event_writest:
            generate_activity_event_writest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::activity_info:
            generate_activity_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_ingest_from_containerst:
            generate_adventure_environment_ingest_from_containerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_ingest_materialst:
            generate_adventure_environment_ingest_materialst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_optionst:
            generate_adventure_environment_optionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_pickup_chop_treest:
            generate_adventure_environment_pickup_chop_treest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_pickup_ignite_vegst:
            generate_adventure_environment_pickup_ignite_vegst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_pickup_make_campfirest:
            generate_adventure_environment_pickup_make_campfirest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_pickup_vermin_eventst:
            generate_adventure_environment_pickup_vermin_eventst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_place_in_bld_containerst:
            generate_adventure_environment_place_in_bld_containerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_place_in_it_containerst:
            generate_adventure_environment_place_in_it_containerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_environment_unit_suck_bloodst:
            generate_adventure_environment_unit_suck_bloodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_item_interact_choicest:
            generate_adventure_item_interact_choicest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_item_interact_fill_from_containerst:
            generate_adventure_item_interact_fill_from_containerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_item_interact_fill_with_materialst:
            generate_adventure_item_interact_fill_with_materialst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_item_interact_give_namest:
            generate_adventure_item_interact_give_namest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_item_interact_heat_from_tilest:
            generate_adventure_item_interact_heat_from_tilest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_item_interact_pull_outst:
            generate_adventure_item_interact_pull_outst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_item_interact_readst:
            generate_adventure_item_interact_readst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_item_interact_strugglest:
            generate_adventure_item_interact_strugglest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_log_item:
            generate_adventure_log_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_attack_creaturest:
            generate_adventure_movement_attack_creaturest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_building_interactst:
            generate_adventure_movement_building_interactst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_climbst:
            generate_adventure_movement_climbst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_hold_itemst:
            generate_adventure_movement_hold_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_hold_tilest:
            generate_adventure_movement_hold_tilest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_item_interact_guidest:
            generate_adventure_movement_item_interact_guidest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_item_interact_pushst:
            generate_adventure_movement_item_interact_pushst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_item_interact_ridest:
            generate_adventure_movement_item_interact_ridest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_item_interactst:
            generate_adventure_movement_item_interactst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_movest:
            generate_adventure_movement_movest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_optionst:
            generate_adventure_movement_optionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_release_hold_itemst:
            generate_adventure_movement_release_hold_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_movement_release_hold_tilest:
            generate_adventure_movement_release_hold_tilest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_option_eat_item_contaminantst:
            generate_adventure_option_eat_item_contaminantst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_option_eat_unit_contaminantst:
            generate_adventure_option_eat_unit_contaminantst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_option_view_contaminantst:
            generate_adventure_option_view_contaminantst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::adventure_optionst:
            generate_adventure_optionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::agreement:
            generate_agreement_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::agreement__T_details:
            generate_agreement__T_details_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::agreement__T_details__T_data:
            generate_agreement__T_details__T_data_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::agreement__T_details__T_data__T_data0:
            generate_agreement__T_details__T_data__T_data0_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::agreement__T_details__T_data__T_data1:
            generate_agreement__T_details__T_data__T_data1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::agreement__T_parties:
            generate_agreement__T_parties_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::agreement__T_parties__T_anon_1:
            generate_agreement__T_parties__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::announcements:
            generate_announcements_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::armor_properties:
            generate_armor_properties_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army:
            generate_army_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army__T_members:
            generate_army__T_members_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army__T_unk_2c:
            generate_army__T_unk_2c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller:
            generate_army_controller_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller__T_unk_64:
            generate_army_controller__T_unk_64_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub1:
            generate_army_controller_sub1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub11:
            generate_army_controller_sub11_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub11__T_anon_3:
            generate_army_controller_sub11__T_anon_3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub12:
            generate_army_controller_sub12_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub12__T_anon_4:
            generate_army_controller_sub12__T_anon_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub13:
            generate_army_controller_sub13_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub13__T_anon_4:
            generate_army_controller_sub13__T_anon_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub14:
            generate_army_controller_sub14_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub14__T_anon_4:
            generate_army_controller_sub14__T_anon_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub15:
            generate_army_controller_sub15_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub15__T_anon_3:
            generate_army_controller_sub15__T_anon_3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub16:
            generate_army_controller_sub16_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub17:
            generate_army_controller_sub17_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub18:
            generate_army_controller_sub18_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub2:
            generate_army_controller_sub2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub2__T_anon_5:
            generate_army_controller_sub2__T_anon_5_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub4:
            generate_army_controller_sub4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub5:
            generate_army_controller_sub5_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub6:
            generate_army_controller_sub6_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub7:
            generate_army_controller_sub7_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::army_controller_sub7__T_anon_3:
            generate_army_controller_sub7__T_anon_3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image:
            generate_art_image_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_chunk:
            generate_art_image_chunk_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_element:
            generate_art_image_element_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_element_creaturest:
            generate_art_image_element_creaturest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_element_itemst:
            generate_art_image_element_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_element_plantst:
            generate_art_image_element_plantst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_element_shapest:
            generate_art_image_element_shapest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_element_treest:
            generate_art_image_element_treest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_property:
            generate_art_image_property_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_property_intransitive_verbst:
            generate_art_image_property_intransitive_verbst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_property_transitive_verbst:
            generate_art_image_property_transitive_verbst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::art_image_ref:
            generate_art_image_ref_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::artifact_record:
            generate_artifact_record_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::assign_trade_status:
            generate_assign_trade_status_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::belief_system:
            generate_belief_system_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_burrow:
            generate_block_burrow_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_burrow_link:
            generate_block_burrow_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event:
            generate_block_square_event_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event_designation_priorityst:
            generate_block_square_event_designation_priorityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event_frozen_liquidst:
            generate_block_square_event_frozen_liquidst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event_grassst:
            generate_block_square_event_grassst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event_item_spatterst:
            generate_block_square_event_item_spatterst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event_material_spatterst:
            generate_block_square_event_material_spatterst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event_mineralst:
            generate_block_square_event_mineralst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event_spoorst:
            generate_block_square_event_spoorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::block_square_event_world_constructionst:
            generate_block_square_event_world_constructionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::body_appearance_modifier:
            generate_body_appearance_modifier_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::body_component_info:
            generate_body_component_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::body_detail_plan:
            generate_body_detail_plan_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::body_part_layer_raw:
            generate_body_part_layer_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::body_part_raw:
            generate_body_part_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::body_part_template:
            generate_body_part_template_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::body_size_info:
            generate_body_size_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::body_template:
            generate_body_template_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::bp_appearance_modifier:
            generate_bp_appearance_modifier_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::build_req_choice_genst:
            generate_build_req_choice_genst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::build_req_choice_specst:
            generate_build_req_choice_specst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::build_req_choicest:
            generate_build_req_choicest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building:
            generate_building_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building__T_activities:
            generate_building__T_activities_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building__T_job_claim_suppress:
            generate_building__T_job_claim_suppress_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_actual:
            generate_building_actual_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_actual__T_contained_items:
            generate_building_actual__T_contained_items_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_animaltrapst:
            generate_building_animaltrapst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_archerytargetst:
            generate_building_archerytargetst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_armorstandst:
            generate_building_armorstandst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_axle_horizontalst:
            generate_building_axle_horizontalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_axle_verticalst:
            generate_building_axle_verticalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_bars_floorst:
            generate_building_bars_floorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_bars_verticalst:
            generate_building_bars_verticalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_bedst:
            generate_building_bedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_bookcasest:
            generate_building_bookcasest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_boxst:
            generate_building_boxst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_bridgest:
            generate_building_bridgest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_cabinetst:
            generate_building_cabinetst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_cagest:
            generate_building_cagest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_chainst:
            generate_building_chainst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_chairst:
            generate_building_chairst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_civzonest:
            generate_building_civzonest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_coffinst:
            generate_building_coffinst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_constructionst:
            generate_building_constructionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_def:
            generate_building_def_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_def_furnacest:
            generate_building_def_furnacest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_def_item:
            generate_building_def_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_def_workshopst:
            generate_building_def_workshopst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_design:
            generate_building_design_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_display_furniturest:
            generate_building_display_furniturest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_doorst:
            generate_building_doorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_drawbuffer:
            generate_building_drawbuffer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_extents:
            generate_building_extents_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_farmplotst:
            generate_building_farmplotst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_floodgatest:
            generate_building_floodgatest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_furnacest:
            generate_building_furnacest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_gear_assemblyst:
            generate_building_gear_assemblyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_grate_floorst:
            generate_building_grate_floorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_grate_wallst:
            generate_building_grate_wallst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_handler:
            generate_building_handler_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_hatchst:
            generate_building_hatchst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_hivest:
            generate_building_hivest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_instrumentst:
            generate_building_instrumentst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_nest_boxst:
            generate_building_nest_boxst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_nestst:
            generate_building_nestst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_road_dirtst:
            generate_building_road_dirtst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_road_pavedst:
            generate_building_road_pavedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_roadst:
            generate_building_roadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_rollersst:
            generate_building_rollersst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_screw_pumpst:
            generate_building_screw_pumpst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_shopst:
            generate_building_shopst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_siegeenginest:
            generate_building_siegeenginest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_slabst:
            generate_building_slabst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_squad_use:
            generate_building_squad_use_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_statuest:
            generate_building_statuest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_stockpilest:
            generate_building_stockpilest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_supportst:
            generate_building_supportst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_tablest:
            generate_building_tablest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_traction_benchst:
            generate_building_traction_benchst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_tradedepotst:
            generate_building_tradedepotst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_trapst:
            generate_building_trapst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_users:
            generate_building_users_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_wagonst:
            generate_building_wagonst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_water_wheelst:
            generate_building_water_wheelst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_weaponrackst:
            generate_building_weaponrackst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_weaponst:
            generate_building_weaponst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_wellst:
            generate_building_wellst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_windmillst:
            generate_building_windmillst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_window_gemst:
            generate_building_window_gemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_window_glassst:
            generate_building_window_glassst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_windowst:
            generate_building_windowst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::building_workshopst:
            generate_building_workshopst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::burrow:
            generate_burrow_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::campfire:
            generate_campfire_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caravan_state:
            generate_caravan_state_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_attack:
            generate_caste_attack_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_body_info:
            generate_caste_body_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_body_info__T_extra_butcher_objects:
            generate_caste_body_info__T_extra_butcher_objects_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_body_info__T_interactions:
            generate_caste_body_info__T_interactions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_clothing_item:
            generate_caste_clothing_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw:
            generate_caste_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_attributes:
            generate_caste_raw__T_attributes_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_bp_appearance:
            generate_caste_raw__T_bp_appearance_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_caste_profession_name:
            generate_caste_raw__T_caste_profession_name_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_extracts:
            generate_caste_raw__T_extracts_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_misc:
            generate_caste_raw__T_misc_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_personality:
            generate_caste_raw__T_personality_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_secretion:
            generate_caste_raw__T_secretion_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_shearable_tissue_layer:
            generate_caste_raw__T_shearable_tissue_layer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::caste_raw__T_unknown2:
            generate_caste_raw__T_unknown2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::cave_column:
            generate_cave_column_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::cave_column_link:
            generate_cave_column_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::cave_column_rectangle:
            generate_cave_column_rectangle_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::coin_batch:
            generate_coin_batch_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::coin_batch__T_image_back:
            generate_coin_batch__T_image_back_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::coin_batch__T_image_front:
            generate_coin_batch__T_image_front_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::color_modifier_raw:
            generate_color_modifier_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::construction:
            generate_construction_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::conversation:
            generate_conversation_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::conversation__T_speech:
            generate_conversation__T_speech_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::coord:
            generate_coord_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::coord2d:
            generate_coord2d_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::coord2d_path:
            generate_coord2d_path_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::coord_path:
            generate_coord_path_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::coord_rect:
            generate_coord_rect_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creation_zone_pwg_alteration_campst:
            generate_creation_zone_pwg_alteration_campst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creation_zone_pwg_alteration_location_deathst:
            generate_creation_zone_pwg_alteration_location_deathst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1:
            generate_creation_zone_pwg_alteration_location_deathst__T_unk_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1:
            generate_creation_zone_pwg_alteration_location_deathst__T_unk_1__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creation_zone_pwg_alteration_srb_ruinedst:
            generate_creation_zone_pwg_alteration_srb_ruinedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creation_zone_pwg_alteration_srp_ruinedst:
            generate_creation_zone_pwg_alteration_srp_ruinedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creation_zone_pwg_alterationst:
            generate_creation_zone_pwg_alterationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_graphics_appointment:
            generate_creature_graphics_appointment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_handler:
            generate_creature_handler_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction:
            generate_creature_interaction_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect:
            generate_creature_interaction_effect_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect__T_counter_trigger:
            generate_creature_interaction_effect__T_counter_trigger_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_add_simple_flagst:
            generate_creature_interaction_effect_add_simple_flagst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_bleedingst:
            generate_creature_interaction_effect_bleedingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_blistersst:
            generate_creature_interaction_effect_blistersst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_body_appearance_modifierst:
            generate_creature_interaction_effect_body_appearance_modifierst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_body_mat_interactionst:
            generate_creature_interaction_effect_body_mat_interactionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_body_transformationst:
            generate_creature_interaction_effect_body_transformationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_bp_appearance_modifierst:
            generate_creature_interaction_effect_bp_appearance_modifierst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_bruisingst:
            generate_creature_interaction_effect_bruisingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_can_do_interactionst:
            generate_creature_interaction_effect_can_do_interactionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_change_personalityst:
            generate_creature_interaction_effect_change_personalityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_cough_bloodst:
            generate_creature_interaction_effect_cough_bloodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_display_namest:
            generate_creature_interaction_effect_display_namest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_display_symbolst:
            generate_creature_interaction_effect_display_symbolst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_dizzinessst:
            generate_creature_interaction_effect_dizzinessst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_drowsinessst:
            generate_creature_interaction_effect_drowsinessst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_erratic_behaviorst:
            generate_creature_interaction_effect_erratic_behaviorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_feel_emotionst:
            generate_creature_interaction_effect_feel_emotionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_feverst:
            generate_creature_interaction_effect_feverst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_flash_symbolst:
            generate_creature_interaction_effect_flash_symbolst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_impair_functionst:
            generate_creature_interaction_effect_impair_functionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_material_force_adjustst:
            generate_creature_interaction_effect_material_force_adjustst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_ment_att_changest:
            generate_creature_interaction_effect_ment_att_changest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_nauseast:
            generate_creature_interaction_effect_nauseast_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_necrosisst:
            generate_creature_interaction_effect_necrosisst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_numbnessst:
            generate_creature_interaction_effect_numbnessst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_oozingst:
            generate_creature_interaction_effect_oozingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_painst:
            generate_creature_interaction_effect_painst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_paralysisst:
            generate_creature_interaction_effect_paralysisst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_phys_att_changest:
            generate_creature_interaction_effect_phys_att_changest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_remove_simple_flagst:
            generate_creature_interaction_effect_remove_simple_flagst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_sense_creature_classst:
            generate_creature_interaction_effect_sense_creature_classst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_skill_roll_adjustst:
            generate_creature_interaction_effect_skill_roll_adjustst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_speed_changest:
            generate_creature_interaction_effect_speed_changest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_swellingst:
            generate_creature_interaction_effect_swellingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_target:
            generate_creature_interaction_effect_target_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_unconsciousnessst:
            generate_creature_interaction_effect_unconsciousnessst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_interaction_effect_vomit_bloodst:
            generate_creature_interaction_effect_vomit_bloodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_raw:
            generate_creature_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_raw__T_graphics:
            generate_creature_raw__T_graphics_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_raw__T_hive_product:
            generate_creature_raw__T_hive_product_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_raw__T_profession_name:
            generate_creature_raw__T_profession_name_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_variation:
            generate_creature_variation_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::creature_variation_convert_tag:
            generate_creature_variation_convert_tag_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::crime:
            generate_crime_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::crime__T_punishment:
            generate_crime__T_punishment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::crime__T_reports:
            generate_crime__T_reports_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::cultural_identity:
            generate_cultural_identity_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::cultural_identity__T_group_log:
            generate_cultural_identity__T_group_log_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::curse_attr_change:
            generate_curse_attr_change_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::d_init:
            generate_d_init_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::d_init__T_store_dist:
            generate_d_init__T_store_dist_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::d_init__T_wound_color:
            generate_d_init__T_wound_color_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::dance_form:
            generate_dance_form_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::dance_form_sub1:
            generate_dance_form_sub1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::dance_form_sub2:
            generate_dance_form_sub2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::deep_vein_hollow:
            generate_deep_vein_hollow_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::descriptor_color:
            generate_descriptor_color_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::descriptor_pattern:
            generate_descriptor_pattern_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::descriptor_shape:
            generate_descriptor_shape_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::dipscript_info:
            generate_dipscript_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::dipscript_popup:
            generate_dipscript_popup_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::dye_info:
            generate_dye_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::effect_info:
            generate_effect_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::embark_item_choice:
            generate_embark_item_choice_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::embark_item_choice__T_list:
            generate_embark_item_choice__T_list_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::embark_location:
            generate_embark_location_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::embark_note:
            generate_embark_note_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::embark_profile:
            generate_embark_profile_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::engraving:
            generate_engraving_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_activity_statistics:
            generate_entity_activity_statistics_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_activity_statistics__T_food:
            generate_entity_activity_statistics__T_food_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_activity_statistics__T_wealth:
            generate_entity_activity_statistics__T_wealth_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_animal_raw:
            generate_entity_animal_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_buy_prices:
            generate_entity_buy_prices_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_buy_requests:
            generate_entity_buy_requests_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_claim_mask:
            generate_entity_claim_mask_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_claim_mask__T_map:
            generate_entity_claim_mask__T_map_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_entity_link:
            generate_entity_entity_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event:
            generate_entity_event_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data:
            generate_entity_event__T_data_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_abandon:
            generate_entity_event__T_data__T_abandon_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_abduction:
            generate_entity_event__T_data__T_abduction_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_accept_peace_offer:
            generate_entity_event__T_data__T_accept_peace_offer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_accept_tribute_demand:
            generate_entity_event__T_data__T_accept_tribute_demand_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_accept_tribute_offer:
            generate_entity_event__T_data__T_accept_tribute_offer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_destroyed:
            generate_entity_event__T_data__T_artifact_destroyed_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_in_feature_layer:
            generate_entity_event__T_data__T_artifact_in_feature_layer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_in_inventory:
            generate_entity_event__T_data__T_artifact_in_inventory_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_in_site:
            generate_entity_event__T_data__T_artifact_in_site_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_in_subregion:
            generate_entity_event__T_data__T_artifact_in_subregion_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_not_in_feature_layer:
            generate_entity_event__T_data__T_artifact_not_in_feature_layer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_not_in_inventory:
            generate_entity_event__T_data__T_artifact_not_in_inventory_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_not_in_site:
            generate_entity_event__T_data__T_artifact_not_in_site_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_artifact_not_in_subregion:
            generate_entity_event__T_data__T_artifact_not_in_subregion_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_beast:
            generate_entity_event__T_data__T_beast_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_cease_tribute_offer:
            generate_entity_event__T_data__T_cease_tribute_offer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_claim:
            generate_entity_event__T_data__T_claim_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_flee:
            generate_entity_event__T_data__T_flee_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_founded:
            generate_entity_event__T_data__T_founded_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_founding:
            generate_entity_event__T_data__T_founding_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_group:
            generate_entity_event__T_data__T_group_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_harass:
            generate_entity_event__T_data__T_harass_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_incident:
            generate_entity_event__T_data__T_incident_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_insurrection:
            generate_entity_event__T_data__T_insurrection_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_insurrection_end:
            generate_entity_event__T_data__T_insurrection_end_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_invasion:
            generate_entity_event__T_data__T_invasion_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_leave:
            generate_entity_event__T_data__T_leave_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_occupation:
            generate_entity_event__T_data__T_occupation_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_reclaimed:
            generate_entity_event__T_data__T_reclaimed_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_reclaiming:
            generate_entity_event__T_data__T_reclaiming_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_refuse_peace_offer:
            generate_entity_event__T_data__T_refuse_peace_offer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_refuse_tribute_demand:
            generate_entity_event__T_data__T_refuse_tribute_demand_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_refuse_tribute_offer:
            generate_entity_event__T_data__T_refuse_tribute_offer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_event__T_data__T_succession:
            generate_entity_event__T_data__T_succession_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_occasion:
            generate_entity_occasion_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_occasion_info:
            generate_entity_occasion_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_occasion_schedule:
            generate_entity_occasion_schedule_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_occasion_schedule_feature:
            generate_entity_occasion_schedule_feature_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_population:
            generate_entity_population_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_population_unk4:
            generate_entity_population_unk4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_population_unk4__T_anon_1:
            generate_entity_population_unk4__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_population_unk4__T_anon_3:
            generate_entity_population_unk4__T_anon_3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_position:
            generate_entity_position_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_position_assignment:
            generate_entity_position_assignment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_position_raw:
            generate_entity_position_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_raw:
            generate_entity_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_raw__T_equipment:
            generate_entity_raw__T_equipment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_raw__T_jobs:
            generate_entity_raw__T_jobs_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_raw__T_land_holder_trigger:
            generate_entity_raw__T_land_holder_trigger_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_raw__T_progress_trigger:
            generate_entity_raw__T_progress_trigger_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_raw__T_symbols:
            generate_entity_raw__T_symbols_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_raw__T_tissue_styles:
            generate_entity_raw__T_tissue_styles_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_raw__T_workshops:
            generate_entity_raw__T_workshops_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_recipe:
            generate_entity_recipe_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_sell_prices:
            generate_entity_sell_prices_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_sell_requests:
            generate_entity_sell_requests_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_site_link:
            generate_entity_site_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_site_link__T_anon_8:
            generate_entity_site_link__T_anon_8_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_tissue_style:
            generate_entity_tissue_style_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_uniform:
            generate_entity_uniform_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::entity_uniform_item:
            generate_entity_uniform_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature:
            generate_feature_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_alteration:
            generate_feature_alteration_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_alteration_new_lava_fill_zst:
            generate_feature_alteration_new_lava_fill_zst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_alteration_new_pop_maxst:
            generate_feature_alteration_new_pop_maxst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_cavest:
            generate_feature_cavest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_deep_special_tubest:
            generate_feature_deep_special_tubest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_deep_surface_portalst:
            generate_feature_deep_surface_portalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init:
            generate_feature_init_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_cavest:
            generate_feature_init_cavest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_deep_special_tubest:
            generate_feature_init_deep_special_tubest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_deep_surface_portalst:
            generate_feature_init_deep_surface_portalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_magma_core_from_layerst:
            generate_feature_init_magma_core_from_layerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_magma_poolst:
            generate_feature_init_magma_poolst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_outdoor_riverst:
            generate_feature_init_outdoor_riverst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_pitst:
            generate_feature_init_pitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_subterranean_from_layerst:
            generate_feature_init_subterranean_from_layerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_underworld_from_layerst:
            generate_feature_init_underworld_from_layerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_init_volcanost:
            generate_feature_init_volcanost_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_magma_core_from_layerst:
            generate_feature_magma_core_from_layerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_magma_poolst:
            generate_feature_magma_poolst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_outdoor_riverst:
            generate_feature_outdoor_riverst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_pitst:
            generate_feature_pitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_subterranean_from_layerst:
            generate_feature_subterranean_from_layerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_underworld_from_layerst:
            generate_feature_underworld_from_layerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::feature_volcanost:
            generate_feature_volcanost_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::file_compressorst:
            generate_file_compressorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::fire:
            generate_fire_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::flow_guide:
            generate_flow_guide_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::flow_guide_item_cloudst:
            generate_flow_guide_item_cloudst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::flow_guide_trailing_flowst:
            generate_flow_guide_trailing_flowst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::flow_info:
            generate_flow_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::flow_reuse_pool:
            generate_flow_reuse_pool_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::gait_info:
            generate_gait_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref:
            generate_general_ref_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_abstract_buildingst:
            generate_general_ref_abstract_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_activity_eventst:
            generate_general_ref_activity_eventst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_artifact:
            generate_general_ref_artifact_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building:
            generate_general_ref_building_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_cagedst:
            generate_general_ref_building_cagedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_chainst:
            generate_general_ref_building_chainst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_civzone_assignedst:
            generate_general_ref_building_civzone_assignedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_destinationst:
            generate_general_ref_building_destinationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_display_furniturest:
            generate_general_ref_building_display_furniturest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_holderst:
            generate_general_ref_building_holderst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_nest_boxst:
            generate_general_ref_building_nest_boxst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_triggerst:
            generate_general_ref_building_triggerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_triggertargetst:
            generate_general_ref_building_triggertargetst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_use_target_1st:
            generate_general_ref_building_use_target_1st_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_use_target_2st:
            generate_general_ref_building_use_target_2st_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_building_well_tag:
            generate_general_ref_building_well_tag_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_coinbatch:
            generate_general_ref_coinbatch_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_contained_in_itemst:
            generate_general_ref_contained_in_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_contains_itemst:
            generate_general_ref_contains_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_contains_unitst:
            generate_general_ref_contains_unitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_creaturest:
            generate_general_ref_creaturest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_dance_formst:
            generate_general_ref_dance_formst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_entity:
            generate_general_ref_entity_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_entity_art_image:
            generate_general_ref_entity_art_image_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_entity_itemownerst:
            generate_general_ref_entity_itemownerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_entity_offeredst:
            generate_general_ref_entity_offeredst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_entity_popst:
            generate_general_ref_entity_popst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_entity_stolenst:
            generate_general_ref_entity_stolenst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_feature_layerst:
            generate_general_ref_feature_layerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_historical_eventst:
            generate_general_ref_historical_eventst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_historical_figurest:
            generate_general_ref_historical_figurest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_interactionst:
            generate_general_ref_interactionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_is_artifactst:
            generate_general_ref_is_artifactst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_is_nemesisst:
            generate_general_ref_is_nemesisst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_item:
            generate_general_ref_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_item_type:
            generate_general_ref_item_type_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_knowledge_scholar_flagst:
            generate_general_ref_knowledge_scholar_flagst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_languagest:
            generate_general_ref_languagest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_locationst:
            generate_general_ref_locationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_mapsquare:
            generate_general_ref_mapsquare_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_musical_formst:
            generate_general_ref_musical_formst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_nemesis:
            generate_general_ref_nemesis_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_poetic_formst:
            generate_general_ref_poetic_formst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_projectile:
            generate_general_ref_projectile_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_sitest:
            generate_general_ref_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_spherest:
            generate_general_ref_spherest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_subregionst:
            generate_general_ref_subregionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit:
            generate_general_ref_unit_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_beateest:
            generate_general_ref_unit_beateest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_cageest:
            generate_general_ref_unit_cageest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_climberst:
            generate_general_ref_unit_climberst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_foodreceiverst:
            generate_general_ref_unit_foodreceiverst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_geldeest:
            generate_general_ref_unit_geldeest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_holderst:
            generate_general_ref_unit_holderst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_infantst:
            generate_general_ref_unit_infantst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_itemownerst:
            generate_general_ref_unit_itemownerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_kidnapeest:
            generate_general_ref_unit_kidnapeest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_milkeest:
            generate_general_ref_unit_milkeest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_patientst:
            generate_general_ref_unit_patientst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_reporteest:
            generate_general_ref_unit_reporteest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_riderst:
            generate_general_ref_unit_riderst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_sheareest:
            generate_general_ref_unit_sheareest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_slaughtereest:
            generate_general_ref_unit_slaughtereest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_suckeest:
            generate_general_ref_unit_suckeest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_tradebringerst:
            generate_general_ref_unit_tradebringerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_traineest:
            generate_general_ref_unit_traineest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_unit_workerst:
            generate_general_ref_unit_workerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_value_levelst:
            generate_general_ref_value_levelst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::general_ref_written_contentst:
            generate_general_ref_written_contentst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::glowing_barrier:
            generate_glowing_barrier_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::graphic:
            generate_graphic_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::hauling_route:
            generate_hauling_route_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::hauling_stop:
            generate_hauling_stop_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link:
            generate_histfig_entity_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_criminalst:
            generate_histfig_entity_link_criminalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_enemyst:
            generate_histfig_entity_link_enemyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_former_memberst:
            generate_histfig_entity_link_former_memberst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_former_mercenaryst:
            generate_histfig_entity_link_former_mercenaryst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_former_occupationst:
            generate_histfig_entity_link_former_occupationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_former_positionst:
            generate_histfig_entity_link_former_positionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_former_prisonerst:
            generate_histfig_entity_link_former_prisonerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_former_slavest:
            generate_histfig_entity_link_former_slavest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_former_squadst:
            generate_histfig_entity_link_former_squadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_memberst:
            generate_histfig_entity_link_memberst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_mercenaryst:
            generate_histfig_entity_link_mercenaryst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_occupationst:
            generate_histfig_entity_link_occupationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_position_claimst:
            generate_histfig_entity_link_position_claimst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_positionst:
            generate_histfig_entity_link_positionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_prisonerst:
            generate_histfig_entity_link_prisonerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_slavest:
            generate_histfig_entity_link_slavest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_entity_link_squadst:
            generate_histfig_entity_link_squadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link:
            generate_histfig_hf_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_apprenticest:
            generate_histfig_hf_link_apprenticest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_childst:
            generate_histfig_hf_link_childst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_companionst:
            generate_histfig_hf_link_companionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_deityst:
            generate_histfig_hf_link_deityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_fatherst:
            generate_histfig_hf_link_fatherst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_former_apprenticest:
            generate_histfig_hf_link_former_apprenticest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_former_masterst:
            generate_histfig_hf_link_former_masterst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_imprisonerst:
            generate_histfig_hf_link_imprisonerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_loverst:
            generate_histfig_hf_link_loverst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_masterst:
            generate_histfig_hf_link_masterst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_motherst:
            generate_histfig_hf_link_motherst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_pet_ownerst:
            generate_histfig_hf_link_pet_ownerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_prisonerst:
            generate_histfig_hf_link_prisonerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_hf_link_spousest:
            generate_histfig_hf_link_spousest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link:
            generate_histfig_site_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link_hangoutst:
            generate_histfig_site_link_hangoutst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link_home_site_abstract_buildingst:
            generate_histfig_site_link_home_site_abstract_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link_home_site_realization_buildingst:
            generate_histfig_site_link_home_site_realization_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link_home_site_realization_sulst:
            generate_histfig_site_link_home_site_realization_sulst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link_home_site_saved_civzonest:
            generate_histfig_site_link_home_site_saved_civzonest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link_lairst:
            generate_histfig_site_link_lairst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link_occupationst:
            generate_histfig_site_link_occupationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::histfig_site_link_seat_of_powerst:
            generate_histfig_site_link_seat_of_powerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity:
            generate_historical_entity_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_claims:
            generate_historical_entity__T_claims_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_derived_resources:
            generate_historical_entity__T_derived_resources_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_positions:
            generate_historical_entity__T_positions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_resources:
            generate_historical_entity__T_resources_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_resources__T_animals:
            generate_historical_entity__T_resources__T_animals_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_resources__T_metal:
            generate_historical_entity__T_resources__T_metal_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_resources__T_misc_mat:
            generate_historical_entity__T_resources__T_misc_mat_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_resources__T_organic:
            generate_historical_entity__T_resources__T_organic_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_resources__T_refuse:
            generate_historical_entity__T_resources__T_refuse_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_resources__T_unk13:
            generate_historical_entity__T_resources__T_unk13_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_resources__T_wood_products:
            generate_historical_entity__T_resources__T_wood_products_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_tissue_styles:
            generate_historical_entity__T_tissue_styles_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_training_knowledge:
            generate_historical_entity__T_training_knowledge_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_unknown1b:
            generate_historical_entity__T_unknown1b_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_unknown1b__T_diplomacy:
            generate_historical_entity__T_unknown1b__T_diplomacy_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_unknown1b__T_unk32e:
            generate_historical_entity__T_unknown1b__T_unk32e_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_unknown1d:
            generate_historical_entity__T_unknown1d_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_unknown1e:
            generate_historical_entity__T_unknown1e_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_entity__T_unknown2:
            generate_historical_entity__T_unknown2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure:
            generate_historical_figure_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure__T_unk_fc:
            generate_historical_figure__T_unk_fc_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info:
            generate_historical_figure_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_books:
            generate_historical_figure_info__T_books_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_curse:
            generate_historical_figure_info__T_curse_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_masterpieces:
            generate_historical_figure_info__T_masterpieces_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_personality:
            generate_historical_figure_info__T_personality_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_relationships:
            generate_historical_figure_info__T_relationships_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_relationships__T_anon_1:
            generate_historical_figure_info__T_relationships__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_relationships__T_anon_2:
            generate_historical_figure_info__T_relationships__T_anon_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_relationships__T_anon_3:
            generate_historical_figure_info__T_relationships__T_anon_3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_relationships__T_list:
            generate_historical_figure_info__T_relationships__T_list_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_reputation:
            generate_historical_figure_info__T_reputation_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_reputation__T_anon_1:
            generate_historical_figure_info__T_reputation__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_reputation__T_unk_2c:
            generate_historical_figure_info__T_reputation__T_unk_2c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_reputation__T_unk_2c__T_anon_12:
            generate_historical_figure_info__T_reputation__T_unk_2c__T_anon_12_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_reputation__T_wanted:
            generate_historical_figure_info__T_reputation__T_wanted_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_secret:
            generate_historical_figure_info__T_secret_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_secret__T_anon_1:
            generate_historical_figure_info__T_secret__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_secret__T_anon_7:
            generate_historical_figure_info__T_secret__T_anon_7_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_secret__T_knowledge:
            generate_historical_figure_info__T_secret__T_knowledge_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_secret__T_unk_a8:
            generate_historical_figure_info__T_secret__T_unk_a8_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_skills:
            generate_historical_figure_info__T_skills_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_unk_14:
            generate_historical_figure_info__T_unk_14_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_figure_info__T_wounds:
            generate_historical_figure_info__T_wounds_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::historical_kills:
            generate_historical_kills_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_era:
            generate_history_era_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_era__T_details:
            generate_history_era__T_details_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_era__T_title:
            generate_history_era__T_title_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event:
            generate_history_event_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_add_hf_entity_linkst:
            generate_history_event_add_hf_entity_linkst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_add_hf_hf_linkst:
            generate_history_event_add_hf_hf_linkst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_add_hf_site_linkst:
            generate_history_event_add_hf_site_linkst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_agreement_concludedst:
            generate_history_event_agreement_concludedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_agreement_formedst:
            generate_history_event_agreement_formedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_agreements_voidedst:
            generate_history_event_agreements_voidedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_claim_formedst:
            generate_history_event_artifact_claim_formedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_copiedst:
            generate_history_event_artifact_copiedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_createdst:
            generate_history_event_artifact_createdst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_destroyedst:
            generate_history_event_artifact_destroyedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_droppedst:
            generate_history_event_artifact_droppedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_foundst:
            generate_history_event_artifact_foundst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_givenst:
            generate_history_event_artifact_givenst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_hiddenst:
            generate_history_event_artifact_hiddenst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_lostst:
            generate_history_event_artifact_lostst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_possessedst:
            generate_history_event_artifact_possessedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_recoveredst:
            generate_history_event_artifact_recoveredst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_storedst:
            generate_history_event_artifact_storedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_artifact_transformedst:
            generate_history_event_artifact_transformedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_assume_identityst:
            generate_history_event_assume_identityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_body_abusedst:
            generate_history_event_body_abusedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_body_abusedst__T_props:
            generate_history_event_body_abusedst__T_props_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_body_abusedst__T_props__T_hung:
            generate_history_event_body_abusedst__T_props__T_hung_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_body_abusedst__T_props__T_item:
            generate_history_event_body_abusedst__T_props__T_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_ceremonyst:
            generate_history_event_ceremonyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_change_creature_typest:
            generate_history_event_change_creature_typest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_change_hf_body_statest:
            generate_history_event_change_hf_body_statest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_change_hf_jobst:
            generate_history_event_change_hf_jobst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_change_hf_moodst:
            generate_history_event_change_hf_moodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_change_hf_statest:
            generate_history_event_change_hf_statest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection:
            generate_history_event_collection_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_abductionst:
            generate_history_event_collection_abductionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_battlest:
            generate_history_event_collection_battlest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_beast_attackst:
            generate_history_event_collection_beast_attackst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_ceremonyst:
            generate_history_event_collection_ceremonyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_competitionst:
            generate_history_event_collection_competitionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_duelst:
            generate_history_event_collection_duelst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_insurrectionst:
            generate_history_event_collection_insurrectionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_journeyst:
            generate_history_event_collection_journeyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_occasionst:
            generate_history_event_collection_occasionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_performancest:
            generate_history_event_collection_performancest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_processionst:
            generate_history_event_collection_processionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_purgest:
            generate_history_event_collection_purgest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_raidst:
            generate_history_event_collection_raidst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_site_conqueredst:
            generate_history_event_collection_site_conqueredst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_theftst:
            generate_history_event_collection_theftst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_warst:
            generate_history_event_collection_warst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_collection_warst__T_unk:
            generate_history_event_collection_warst__T_unk_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_competitionst:
            generate_history_event_competitionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_context:
            generate_history_event_context_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_create_entity_positionst:
            generate_history_event_create_entity_positionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_created_buildingst:
            generate_history_event_created_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_created_sitest:
            generate_history_event_created_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_created_world_constructionst:
            generate_history_event_created_world_constructionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_creature_devouredst:
            generate_history_event_creature_devouredst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_dance_form_createdst:
            generate_history_event_dance_form_createdst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_diplomat_lostst:
            generate_history_event_diplomat_lostst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_actionst:
            generate_history_event_entity_actionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_createdst:
            generate_history_event_entity_createdst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_expels_hfst:
            generate_history_event_entity_expels_hfst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_fled_sitest:
            generate_history_event_entity_fled_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_incorporatedst:
            generate_history_event_entity_incorporatedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_lawst:
            generate_history_event_entity_lawst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_rampaged_in_sitest:
            generate_history_event_entity_rampaged_in_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_razed_buildingst:
            generate_history_event_entity_razed_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_entity_searched_sitest:
            generate_history_event_entity_searched_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_first_contact_failedst:
            generate_history_event_first_contact_failedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_first_contactst:
            generate_history_event_first_contactst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_act_on_artifactst:
            generate_history_event_hf_act_on_artifactst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_act_on_buildingst:
            generate_history_event_hf_act_on_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_attacked_sitest:
            generate_history_event_hf_attacked_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_confrontedst:
            generate_history_event_hf_confrontedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_destroyed_sitest:
            generate_history_event_hf_destroyed_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_does_interactionst:
            generate_history_event_hf_does_interactionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_freedst:
            generate_history_event_hf_freedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_gains_secret_goalst:
            generate_history_event_hf_gains_secret_goalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_learns_secretst:
            generate_history_event_hf_learns_secretst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_razed_buildingst:
            generate_history_event_hf_razed_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_recruited_unit_type_for_entityst:
            generate_history_event_hf_recruited_unit_type_for_entityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hf_relationship_deniedst:
            generate_history_event_hf_relationship_deniedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hfs_formed_reputation_relationshipst:
            generate_history_event_hfs_formed_reputation_relationshipst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_abductedst:
            generate_history_event_hist_figure_abductedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_diedst:
            generate_history_event_hist_figure_diedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_new_petst:
            generate_history_event_hist_figure_new_petst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_reach_summitst:
            generate_history_event_hist_figure_reach_summitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_reunionst:
            generate_history_event_hist_figure_reunionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_revivedst:
            generate_history_event_hist_figure_revivedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_simple_actionst:
            generate_history_event_hist_figure_simple_actionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_simple_battle_eventst:
            generate_history_event_hist_figure_simple_battle_eventst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_travelst:
            generate_history_event_hist_figure_travelst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_hist_figure_woundedst:
            generate_history_event_hist_figure_woundedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_insurrection_endedst:
            generate_history_event_insurrection_endedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_insurrection_startedst:
            generate_history_event_insurrection_startedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_item_stolenst:
            generate_history_event_item_stolenst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_knowledge_discoveredst:
            generate_history_event_knowledge_discoveredst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_created_arch_constructst:
            generate_history_event_masterpiece_created_arch_constructst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_created_arch_designst:
            generate_history_event_masterpiece_created_arch_designst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_created_dye_itemst:
            generate_history_event_masterpiece_created_dye_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_created_engravingst:
            generate_history_event_masterpiece_created_engravingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_created_foodst:
            generate_history_event_masterpiece_created_foodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_created_item_improvementst:
            generate_history_event_masterpiece_created_item_improvementst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_created_itemst:
            generate_history_event_masterpiece_created_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_createdst:
            generate_history_event_masterpiece_createdst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_masterpiece_lostst:
            generate_history_event_masterpiece_lostst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_merchantst:
            generate_history_event_merchantst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_musical_form_createdst:
            generate_history_event_musical_form_createdst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_performancest:
            generate_history_event_performancest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_poetic_form_createdst:
            generate_history_event_poetic_form_createdst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_processionst:
            generate_history_event_processionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_reclaim_sitest:
            generate_history_event_reclaim_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_regionpop_incorporated_into_entityst:
            generate_history_event_regionpop_incorporated_into_entityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_remove_hf_entity_linkst:
            generate_history_event_remove_hf_entity_linkst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_remove_hf_hf_linkst:
            generate_history_event_remove_hf_hf_linkst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_remove_hf_site_linkst:
            generate_history_event_remove_hf_site_linkst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_replaced_buildingst:
            generate_history_event_replaced_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_site_diedst:
            generate_history_event_site_diedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_site_disputest:
            generate_history_event_site_disputest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_site_retiredst:
            generate_history_event_site_retiredst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_site_surrenderedst:
            generate_history_event_site_surrenderedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_sneak_into_sitest:
            generate_history_event_sneak_into_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_spotted_leaving_sitest:
            generate_history_event_spotted_leaving_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_squad_vs_squadst:
            generate_history_event_squad_vs_squadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_tactical_situationst:
            generate_history_event_tactical_situationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_topicagreement_concludedst:
            generate_history_event_topicagreement_concludedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_topicagreement_madest:
            generate_history_event_topicagreement_madest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_topicagreement_rejectedst:
            generate_history_event_topicagreement_rejectedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_attacked_sitest:
            generate_history_event_war_attacked_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_destroyed_sitest:
            generate_history_event_war_destroyed_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_field_battlest:
            generate_history_event_war_field_battlest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_peace_acceptedst:
            generate_history_event_war_peace_acceptedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_peace_rejectedst:
            generate_history_event_war_peace_rejectedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_plundered_sitest:
            generate_history_event_war_plundered_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_site_new_leaderst:
            generate_history_event_war_site_new_leaderst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_site_taken_overst:
            generate_history_event_war_site_taken_overst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_war_site_tribute_forcedst:
            generate_history_event_war_site_tribute_forcedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_event_written_content_composedst:
            generate_history_event_written_content_composedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::history_hit_item:
            generate_history_hit_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::hospital_supplies:
            generate_hospital_supplies_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::identity:
            generate_identity_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::identity_unk_94:
            generate_identity_unk_94_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident:
            generate_incident_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident__T_unk_v42_1:
            generate_incident__T_unk_v42_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident_hfid:
            generate_incident_hfid_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident_sub10:
            generate_incident_sub10_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident_sub6_performance:
            generate_incident_sub6_performance_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident_sub6_performance__T_participants:
            generate_incident_sub6_performance__T_participants_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident_sub7:
            generate_incident_sub7_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident_sub8:
            generate_incident_sub8_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::incident_sub9:
            generate_incident_sub9_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::init:
            generate_init_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::init_display:
            generate_init_display_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::init_font:
            generate_init_font_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::init_input:
            generate_init_input_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::init_media:
            generate_init_media_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::init_window:
            generate_init_window_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::inorganic_raw:
            generate_inorganic_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::inorganic_raw__T_environment:
            generate_inorganic_raw__T_environment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::inorganic_raw__T_environment_spec:
            generate_inorganic_raw__T_environment_spec_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::inorganic_raw__T_metal_ore:
            generate_inorganic_raw__T_metal_ore_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::inorganic_raw__T_thread_metal:
            generate_inorganic_raw__T_thread_metal_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::instrument_piece:
            generate_instrument_piece_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::instrument_register:
            generate_instrument_register_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction:
            generate_interaction_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_effect:
            generate_interaction_effect_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_effect_add_syndromest:
            generate_interaction_effect_add_syndromest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_effect_animatest:
            generate_interaction_effect_animatest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_effect_cleanst:
            generate_interaction_effect_cleanst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_effect_contactst:
            generate_interaction_effect_contactst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_effect_hidest:
            generate_interaction_effect_hidest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_effect_material_emissionst:
            generate_interaction_effect_material_emissionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_effect_resurrectst:
            generate_interaction_effect_resurrectst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_instance:
            generate_interaction_instance_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source:
            generate_interaction_source_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source_attackst:
            generate_interaction_source_attackst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source_creature_actionst:
            generate_interaction_source_creature_actionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source_deityst:
            generate_interaction_source_deityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source_disturbancest:
            generate_interaction_source_disturbancest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source_ingestionst:
            generate_interaction_source_ingestionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source_regionst:
            generate_interaction_source_regionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source_secretst:
            generate_interaction_source_secretst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_source_underground_specialst:
            generate_interaction_source_underground_specialst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_target:
            generate_interaction_target_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_target_corpsest:
            generate_interaction_target_corpsest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_target_creaturest:
            generate_interaction_target_creaturest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_target_info:
            generate_interaction_target_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_target_locationst:
            generate_interaction_target_locationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interaction_target_materialst:
            generate_interaction_target_materialst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button:
            generate_interface_button_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_building_category_selectorst:
            generate_interface_button_building_category_selectorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_building_custom_category_selectorst:
            generate_interface_button_building_custom_category_selectorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_building_material_selectorst:
            generate_interface_button_building_material_selectorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_building_new_jobst:
            generate_interface_button_building_new_jobst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_buildingst:
            generate_interface_button_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_construction_building_selectorst:
            generate_interface_button_construction_building_selectorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_construction_category_selectorst:
            generate_interface_button_construction_category_selectorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_construction_donest:
            generate_interface_button_construction_donest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interface_button_constructionst:
            generate_interface_button_constructionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::interfacest:
            generate_interfacest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::invasion_info:
            generate_invasion_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item:
            generate_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_actual:
            generate_item_actual_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_ammost:
            generate_item_ammost_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_amuletst:
            generate_item_amuletst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_animaltrapst:
            generate_item_animaltrapst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_anvilst:
            generate_item_anvilst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_armorst:
            generate_item_armorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_armorstandst:
            generate_item_armorstandst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_backpackst:
            generate_item_backpackst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_ballistaarrowheadst:
            generate_item_ballistaarrowheadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_ballistapartsst:
            generate_item_ballistapartsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_barrelst:
            generate_item_barrelst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_barst:
            generate_item_barst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_bedst:
            generate_item_bedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_binst:
            generate_item_binst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_blocksst:
            generate_item_blocksst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_body_component:
            generate_item_body_component_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_body_component__T_appearance:
            generate_item_body_component__T_appearance_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_body_component__T_body:
            generate_item_body_component__T_body_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_body_component__T_bone1:
            generate_item_body_component__T_bone1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_body_component__T_bone2:
            generate_item_body_component__T_bone2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_bookst:
            generate_item_bookst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_boulderst:
            generate_item_boulderst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_boxst:
            generate_item_boxst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_braceletst:
            generate_item_braceletst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_branchst:
            generate_item_branchst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_bucketst:
            generate_item_bucketst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_cabinetst:
            generate_item_cabinetst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_cagest:
            generate_item_cagest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_catapultpartsst:
            generate_item_catapultpartsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_chainst:
            generate_item_chainst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_chairst:
            generate_item_chairst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_cheesest:
            generate_item_cheesest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_clothst:
            generate_item_clothst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_coffinst:
            generate_item_coffinst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_coinst:
            generate_item_coinst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_constructed:
            generate_item_constructed_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_corpsepiecest:
            generate_item_corpsepiecest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_corpsest:
            generate_item_corpsest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_crafted:
            generate_item_crafted_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_critter:
            generate_item_critter_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_crownst:
            generate_item_crownst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_crutchst:
            generate_item_crutchst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_doorst:
            generate_item_doorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_drinkst:
            generate_item_drinkst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_earringst:
            generate_item_earringst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_eggst:
            generate_item_eggst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_figurinest:
            generate_item_figurinest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_filter_spec:
            generate_item_filter_spec_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_fish_rawst:
            generate_item_fish_rawst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_fishst:
            generate_item_fishst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_flaskst:
            generate_item_flaskst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_floodgatest:
            generate_item_floodgatest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_foodst:
            generate_item_foodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_foodst__T_ingredients:
            generate_item_foodst__T_ingredients_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_gemst:
            generate_item_gemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_globst:
            generate_item_globst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_glovesst:
            generate_item_glovesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_gobletst:
            generate_item_gobletst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_gratest:
            generate_item_gratest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_hatch_coverst:
            generate_item_hatch_coverst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_helmst:
            generate_item_helmst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_history_info:
            generate_item_history_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_instrumentst:
            generate_item_instrumentst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_kill_info:
            generate_item_kill_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_liquid:
            generate_item_liquid_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_liquid_miscst:
            generate_item_liquid_miscst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_liquipowder:
            generate_item_liquipowder_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_magicness:
            generate_item_magicness_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_meatst:
            generate_item_meatst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_millstonest:
            generate_item_millstonest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_orthopedic_castst:
            generate_item_orthopedic_castst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_pantsst:
            generate_item_pantsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_petst:
            generate_item_petst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_pipe_sectionst:
            generate_item_pipe_sectionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_plant_growthst:
            generate_item_plant_growthst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_plantst:
            generate_item_plantst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_powder:
            generate_item_powder_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_powder_miscst:
            generate_item_powder_miscst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_quernst:
            generate_item_quernst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_quiverst:
            generate_item_quiverst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_remainsst:
            generate_item_remainsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_ringst:
            generate_item_ringst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_rockst:
            generate_item_rockst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_roughst:
            generate_item_roughst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_scepterst:
            generate_item_scepterst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_seedsst:
            generate_item_seedsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_sheetst:
            generate_item_sheetst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_shieldst:
            generate_item_shieldst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_shoesst:
            generate_item_shoesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_siegeammost:
            generate_item_siegeammost_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_skin_tannedst:
            generate_item_skin_tannedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_slabst:
            generate_item_slabst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_smallgemst:
            generate_item_smallgemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_splintst:
            generate_item_splintst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_statuest:
            generate_item_statuest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_stockpile_ref:
            generate_item_stockpile_ref_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_tablest:
            generate_item_tablest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_threadst:
            generate_item_threadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_toolst:
            generate_item_toolst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_totemst:
            generate_item_totemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_toyst:
            generate_item_toyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_traction_benchst:
            generate_item_traction_benchst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_trapcompst:
            generate_item_trapcompst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_trappartsst:
            generate_item_trappartsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_verminst:
            generate_item_verminst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_weaponrackst:
            generate_item_weaponrackst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_weaponst:
            generate_item_weaponst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_windowst:
            generate_item_windowst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::item_woodst:
            generate_item_woodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef:
            generate_itemdef_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_ammost:
            generate_itemdef_ammost_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_armorst:
            generate_itemdef_armorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_foodst:
            generate_itemdef_foodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_glovesst:
            generate_itemdef_glovesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_helmst:
            generate_itemdef_helmst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_instrumentst:
            generate_itemdef_instrumentst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_pantsst:
            generate_itemdef_pantsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_shieldst:
            generate_itemdef_shieldst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_shoesst:
            generate_itemdef_shoesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_siegeammost:
            generate_itemdef_siegeammost_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_toolst:
            generate_itemdef_toolst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_toolst__T_default_improvements:
            generate_itemdef_toolst__T_default_improvements_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_toyst:
            generate_itemdef_toyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_trapcompst:
            generate_itemdef_trapcompst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemdef_weaponst:
            generate_itemdef_weaponst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement:
            generate_itemimprovement_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_art_imagest:
            generate_itemimprovement_art_imagest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_bandsst:
            generate_itemimprovement_bandsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_clothst:
            generate_itemimprovement_clothst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_coveredst:
            generate_itemimprovement_coveredst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_illustrationst:
            generate_itemimprovement_illustrationst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_instrument_piecest:
            generate_itemimprovement_instrument_piecest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_itemspecificst:
            generate_itemimprovement_itemspecificst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_pagesst:
            generate_itemimprovement_pagesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_rings_hangingst:
            generate_itemimprovement_rings_hangingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_sewn_imagest:
            generate_itemimprovement_sewn_imagest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_sewn_imagest__T_cloth:
            generate_itemimprovement_sewn_imagest__T_cloth_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_spikesst:
            generate_itemimprovement_spikesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_threadst:
            generate_itemimprovement_threadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::itemimprovement_writingst:
            generate_itemimprovement_writingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job:
            generate_job_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job_art_specification:
            generate_job_art_specification_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job_handler:
            generate_job_handler_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job_handler__T_anon_1:
            generate_job_handler__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job_handler__T_postings:
            generate_job_handler__T_postings_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job_item:
            generate_job_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job_item_filter:
            generate_job_item_filter_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job_item_ref:
            generate_job_item_ref_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::job_list_link:
            generate_job_list_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::KeybindingScreen:
            generate_KeybindingScreen_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::knowledge_scholar_category_flag:
            generate_knowledge_scholar_category_flag_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::knowledge_scholar_category_flag__T_flags:
            generate_knowledge_scholar_category_flag__T_flags_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::language_name:
            generate_language_name_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::language_symbol:
            generate_language_symbol_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::language_translation:
            generate_language_translation_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::language_word:
            generate_language_word_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::language_word_table:
            generate_language_word_table_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::large_integer:
            generate_large_integer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::large_integer__T_u:
            generate_large_integer__T_u_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::layer_object:
            generate_layer_object_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::layer_object_buttonst:
            generate_layer_object_buttonst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::layer_object_listst:
            generate_layer_object_listst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::loadgame_save_info:
            generate_loadgame_save_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::local_population:
            generate_local_population_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::location_scribe_jobs:
            generate_location_scribe_jobs_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::machine:
            generate_machine_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::machine__T_components:
            generate_machine__T_components_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::machine_handler:
            generate_machine_handler_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::machine_info:
            generate_machine_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::machine_standardst:
            generate_machine_standardst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::machine_tile_set:
            generate_machine_tile_set_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::MacroScreenLoad:
            generate_MacroScreenLoad_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::MacroScreenSave:
            generate_MacroScreenSave_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::manager_order:
            generate_manager_order_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::manager_order_condition_item:
            generate_manager_order_condition_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::manager_order_condition_order:
            generate_manager_order_condition_order_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::manager_order_template:
            generate_manager_order_template_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mandate:
            generate_mandate_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mandate__T_punishment:
            generate_mandate__T_punishment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::map_block:
            generate_map_block_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::map_block_column:
            generate_map_block_column_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::map_block_column__T_unmined_glyphs:
            generate_map_block_column__T_unmined_glyphs_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::map_renderer:
            generate_map_renderer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::map_renderer__T_anon_4:
            generate_map_renderer__T_anon_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::map_viewport:
            generate_map_viewport_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::material:
            generate_material_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::material_common:
            generate_material_common_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::material_common__T_hardens_with_water:
            generate_material_common__T_hardens_with_water_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::material_common__T_heat:
            generate_material_common__T_heat_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::material_common__T_reaction_product:
            generate_material_common__T_reaction_product_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::material_common__T_strength:
            generate_material_common__T_strength_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::material_template:
            generate_material_template_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::material_vec_ref:
            generate_material_vec_ref_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::matgloss_list:
            generate_matgloss_list_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::meeting_context:
            generate_meeting_context_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::meeting_diplomat_info:
            generate_meeting_diplomat_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::meeting_event:
            generate_meeting_event_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::meeting_variable:
            generate_meeting_variable_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture:
            generate_mental_picture_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_element_hfst:
            generate_mental_picture_element_hfst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_element_regionst:
            generate_mental_picture_element_regionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_element_sitest:
            generate_mental_picture_element_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_elementst:
            generate_mental_picture_elementst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_actionst:
            generate_mental_picture_property_actionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_adjectivest:
            generate_mental_picture_property_adjectivest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_color_patternst:
            generate_mental_picture_property_color_patternst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_datest:
            generate_mental_picture_property_datest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_emotionst:
            generate_mental_picture_property_emotionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_positionst:
            generate_mental_picture_property_positionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_shapest:
            generate_mental_picture_property_shapest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_timest:
            generate_mental_picture_property_timest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_property_toolst:
            generate_mental_picture_property_toolst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mental_picture_propertyst:
            generate_mental_picture_propertyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mission:
            generate_mission_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mission__T_details:
            generate_mission__T_details_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mission__T_details__T_raid:
            generate_mission__T_details__T_raid_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mission__T_details__T_recovery:
            generate_mission__T_details__T_recovery_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mission__T_details__T_request:
            generate_mission__T_details__T_request_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mission__T_details__T_rescue:
            generate_mission__T_details__T_rescue_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mission_campaign_report:
            generate_mission_campaign_report_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::mission_report:
            generate_mission_report_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::moving_party:
            generate_moving_party_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::moving_party__T_members:
            generate_moving_party__T_members_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::musical_form:
            generate_musical_form_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::musical_form_instruments:
            generate_musical_form_instruments_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::musical_form_interval:
            generate_musical_form_interval_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::musical_form_melodies:
            generate_musical_form_melodies_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::musical_form_sub4:
            generate_musical_form_sub4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::musical_form_vocals:
            generate_musical_form_vocals_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::nemesis_offload:
            generate_nemesis_offload_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::nemesis_record:
            generate_nemesis_record_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::occupation:
            generate_occupation_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::occupation_sub1:
            generate_occupation_sub1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ocean_wave:
            generate_ocean_wave_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::party_info:
            generate_party_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::performance_play_orderst:
            generate_performance_play_orderst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::performance_play_orderst__T_anon_4:
            generate_performance_play_orderst__T_anon_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::plant:
            generate_plant_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::plant_growth:
            generate_plant_growth_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::plant_growth_print:
            generate_plant_growth_print_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::plant_raw:
            generate_plant_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::plant_raw__T_colors:
            generate_plant_raw__T_colors_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::plant_raw__T_material_defs:
            generate_plant_raw__T_material_defs_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::plant_raw__T_tiles:
            generate_plant_raw__T_tiles_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::plant_tree_info:
            generate_plant_tree_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::poetic_form:
            generate_poetic_form_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::poetic_form_part:
            generate_poetic_form_part_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::poetic_form_part__T_line_subject_targets:
            generate_poetic_form_part__T_line_subject_targets_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::poetic_form_perspective:
            generate_poetic_form_perspective_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::popup_message:
            generate_popup_message_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::power_info:
            generate_power_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::pressure_plate_info:
            generate_pressure_plate_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::proj_itemst:
            generate_proj_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::proj_list_link:
            generate_proj_list_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::proj_magicst:
            generate_proj_magicst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::proj_unitst:
            generate_proj_unitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::projectile:
            generate_projectile_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::punishment:
            generate_punishment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction:
            generate_reaction_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction__T_building:
            generate_reaction__T_building_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_category:
            generate_reaction_category_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_description:
            generate_reaction_description_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_product:
            generate_reaction_product_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_product_item_improvementst:
            generate_reaction_product_item_improvementst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_product_item_improvementst__T_get_material:
            generate_reaction_product_item_improvementst__T_get_material_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_product_itemst:
            generate_reaction_product_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_product_itemst__T_get_material:
            generate_reaction_product_itemst__T_get_material_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_reagent:
            generate_reaction_reagent_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::reaction_reagent_itemst:
            generate_reaction_reagent_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::region_block_event_sphere_fieldst:
            generate_region_block_event_sphere_fieldst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::region_block_eventst:
            generate_region_block_eventst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::region_map_entry:
            generate_region_map_entry_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::renderer:
            generate_renderer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::report:
            generate_report_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_data:
            generate_resource_allotment_data_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_data__T_unk_654:
            generate_resource_allotment_data__T_unk_654_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier:
            generate_resource_allotment_specifier_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_ammost:
            generate_resource_allotment_specifier_ammost_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_anvilst:
            generate_resource_allotment_specifier_anvilst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_armor_bodyst:
            generate_resource_allotment_specifier_armor_bodyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_armor_bootsst:
            generate_resource_allotment_specifier_armor_bootsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_armor_glovesst:
            generate_resource_allotment_specifier_armor_glovesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_armor_helmst:
            generate_resource_allotment_specifier_armor_helmst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_armor_pantsst:
            generate_resource_allotment_specifier_armor_pantsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_backpackst:
            generate_resource_allotment_specifier_backpackst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_bagst:
            generate_resource_allotment_specifier_bagst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_bedst:
            generate_resource_allotment_specifier_bedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_bonest:
            generate_resource_allotment_specifier_bonest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_boxst:
            generate_resource_allotment_specifier_boxst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_cabinetst:
            generate_resource_allotment_specifier_cabinetst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_chairst:
            generate_resource_allotment_specifier_chairst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_cheesest:
            generate_resource_allotment_specifier_cheesest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_clothing_bodyst:
            generate_resource_allotment_specifier_clothing_bodyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_clothing_bootsst:
            generate_resource_allotment_specifier_clothing_bootsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_clothing_glovesst:
            generate_resource_allotment_specifier_clothing_glovesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_clothing_helmst:
            generate_resource_allotment_specifier_clothing_helmst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_clothing_pantsst:
            generate_resource_allotment_specifier_clothing_pantsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_clothst:
            generate_resource_allotment_specifier_clothst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_craftsst:
            generate_resource_allotment_specifier_craftsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_cropst:
            generate_resource_allotment_specifier_cropst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_extractst:
            generate_resource_allotment_specifier_extractst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_flaskst:
            generate_resource_allotment_specifier_flaskst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_gemsst:
            generate_resource_allotment_specifier_gemsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_hornst:
            generate_resource_allotment_specifier_hornst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_leatherst:
            generate_resource_allotment_specifier_leatherst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_meatst:
            generate_resource_allotment_specifier_meatst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_metalst:
            generate_resource_allotment_specifier_metalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_pearlst:
            generate_resource_allotment_specifier_pearlst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_powderst:
            generate_resource_allotment_specifier_powderst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_quiverst:
            generate_resource_allotment_specifier_quiverst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_shellst:
            generate_resource_allotment_specifier_shellst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_skinst:
            generate_resource_allotment_specifier_skinst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_soapst:
            generate_resource_allotment_specifier_soapst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_stonest:
            generate_resource_allotment_specifier_stonest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_tablest:
            generate_resource_allotment_specifier_tablest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_tallowst:
            generate_resource_allotment_specifier_tallowst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_threadst:
            generate_resource_allotment_specifier_threadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_toothst:
            generate_resource_allotment_specifier_toothst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_weapon_meleest:
            generate_resource_allotment_specifier_weapon_meleest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_weapon_rangedst:
            generate_resource_allotment_specifier_weapon_rangedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::resource_allotment_specifier_woodst:
            generate_resource_allotment_specifier_woodst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::rhythm:
            generate_rhythm_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::rhythm_sub1:
            generate_rhythm_sub1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::rhythm_sub1__T_anon_1:
            generate_rhythm_sub1__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::rhythm_sub2:
            generate_rhythm_sub2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::room_rent_info:
            generate_room_rent_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::route_stockpile_link:
            generate_route_stockpile_link_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::scale:
            generate_scale_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::scale__T_unk1:
            generate_scale__T_unk1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::scale_sub1:
            generate_scale_sub1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::scale_sub2:
            generate_scale_sub2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::schedule_info:
            generate_schedule_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::schedule_slot:
            generate_schedule_slot_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::scribejob:
            generate_scribejob_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_conditionalst:
            generate_script_step_conditionalst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_conditionalst__T_condition:
            generate_script_step_conditionalst__T_condition_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_constructtopiclistst:
            generate_script_step_constructtopiclistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_dipeventst:
            generate_script_step_dipeventst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_diphistoryst:
            generate_script_step_diphistoryst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_discussst:
            generate_script_step_discussst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_eventst:
            generate_script_step_eventst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_invasionst:
            generate_script_step_invasionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_setvarst:
            generate_script_step_setvarst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_simpleactionst:
            generate_script_step_simpleactionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_textviewerst:
            generate_script_step_textviewerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_step_topicdiscussionst:
            generate_script_step_topicdiscussionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_stepst:
            generate_script_stepst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_var_longst:
            generate_script_var_longst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_var_unitst:
            generate_script_var_unitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::script_varst:
            generate_script_varst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::setup_character_info:
            generate_setup_character_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_building_item:
            generate_site_building_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building:
            generate_site_realization_building_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building__T_unk_4c:
            generate_site_realization_building__T_unk_4c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_castle_courtyardst:
            generate_site_realization_building_info_castle_courtyardst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_castle_towerst:
            generate_site_realization_building_info_castle_towerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_castle_wallst:
            generate_site_realization_building_info_castle_wallst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_hillock_housest:
            generate_site_realization_building_info_hillock_housest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_market_squarest:
            generate_site_realization_building_info_market_squarest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_shop_housest:
            generate_site_realization_building_info_shop_housest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_tree_housest:
            generate_site_realization_building_info_tree_housest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_trenchesst:
            generate_site_realization_building_info_trenchesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_info_trenchesst__T_spokes:
            generate_site_realization_building_info_trenchesst__T_spokes_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_building_infost:
            generate_site_realization_building_infost_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_realization_crossroads:
            generate_site_realization_crossroads_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_reputation_info:
            generate_site_reputation_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::site_reputation_report:
            generate_site_reputation_report_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::spatter:
            generate_spatter_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::spatter_common:
            generate_spatter_common_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::special_mat_table:
            generate_special_mat_table_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::specific_ref:
            generate_specific_ref_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::specific_ref__T_arg2:
            generate_specific_ref__T_arg2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::spoils_report:
            generate_spoils_report_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad:
            generate_squad_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad__T_rooms:
            generate_squad__T_rooms_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_ammo_spec:
            generate_squad_ammo_spec_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order:
            generate_squad_order_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_cause_trouble_for_entityst:
            generate_squad_order_cause_trouble_for_entityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_defend_burrowsst:
            generate_squad_order_defend_burrowsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_drive_armies_from_sitest:
            generate_squad_order_drive_armies_from_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_drive_entity_off_sitest:
            generate_squad_order_drive_entity_off_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_kill_hfst:
            generate_squad_order_kill_hfst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_kill_listst:
            generate_squad_order_kill_listst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_movest:
            generate_squad_order_movest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_patrol_routest:
            generate_squad_order_patrol_routest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_raid_sitest:
            generate_squad_order_raid_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_rescue_hfst:
            generate_squad_order_rescue_hfst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_retrieve_artifactst:
            generate_squad_order_retrieve_artifactst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_order_trainst:
            generate_squad_order_trainst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_position:
            generate_squad_position_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_schedule_entry:
            generate_squad_schedule_entry_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_schedule_order:
            generate_squad_schedule_order_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::squad_uniform_spec:
            generate_squad_uniform_spec_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_links:
            generate_stockpile_links_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings:
            generate_stockpile_settings_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_ammo:
            generate_stockpile_settings__T_ammo_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_animals:
            generate_stockpile_settings__T_animals_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_armor:
            generate_stockpile_settings__T_armor_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_bars_blocks:
            generate_stockpile_settings__T_bars_blocks_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_cloth:
            generate_stockpile_settings__T_cloth_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_coins:
            generate_stockpile_settings__T_coins_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_finished_goods:
            generate_stockpile_settings__T_finished_goods_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_food:
            generate_stockpile_settings__T_food_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_furniture:
            generate_stockpile_settings__T_furniture_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_gems:
            generate_stockpile_settings__T_gems_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_leather:
            generate_stockpile_settings__T_leather_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_ore:
            generate_stockpile_settings__T_ore_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_refuse:
            generate_stockpile_settings__T_refuse_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_sheet:
            generate_stockpile_settings__T_sheet_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_stone:
            generate_stockpile_settings__T_stone_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_weapons:
            generate_stockpile_settings__T_weapons_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stockpile_settings__T_wood:
            generate_stockpile_settings__T_wood_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::stop_depart_condition:
            generate_stop_depart_condition_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::syndrome:
            generate_syndrome_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::T_cursor:
            generate_T_cursor_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::T_selection_rect:
            generate_T_selection_rect_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::talk_choice:
            generate_talk_choice_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::talk_choice__T_unk:
            generate_talk_choice__T_unk_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::temperaturest:
            generate_temperaturest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::text_info_element_longst:
            generate_text_info_element_longst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::text_info_element_stringst:
            generate_text_info_element_stringst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::text_info_elementst:
            generate_text_info_elementst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::texture_handler:
            generate_texture_handler_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::tile_bitmask:
            generate_tile_bitmask_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::tile_page:
            generate_tile_page_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::timed_event:
            generate_timed_event_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::tissue:
            generate_tissue_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::tissue_style_raw:
            generate_tissue_style_raw_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::tissue_template:
            generate_tissue_template_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::training_assignment:
            generate_training_assignment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui:
            generate_ui_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_alerts:
            generate_ui__T_alerts_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_alerts__T_list:
            generate_ui__T_alerts__T_list_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_becoming_capital:
            generate_ui__T_becoming_capital_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_burrows:
            generate_ui__T_burrows_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_economy_prices:
            generate_ui__T_economy_prices_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_economy_prices__T_price_adjustment:
            generate_ui__T_economy_prices__T_price_adjustment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_economy_prices__T_price_setter:
            generate_ui__T_economy_prices__T_price_setter_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_equipment:
            generate_ui__T_equipment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_hauling:
            generate_ui__T_hauling_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_invasions:
            generate_ui__T_invasions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_kitchen:
            generate_ui__T_kitchen_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_main:
            generate_ui__T_main_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_main__T_dead_citizens:
            generate_ui__T_main__T_dead_citizens_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_map_edge:
            generate_ui__T_map_edge_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_squads:
            generate_ui__T_squads_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_stockpile:
            generate_ui__T_stockpile_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_tax_collection:
            generate_ui__T_tax_collection_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_unk2a8c:
            generate_ui__T_unk2a8c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_waypoints:
            generate_ui__T_waypoints_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_waypoints__T_points:
            generate_ui__T_waypoints__T_points_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui__T_waypoints__T_routes:
            generate_ui__T_waypoints__T_routes_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode:
            generate_ui_advmode_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_assume_identity:
            generate_ui_advmode__T_assume_identity_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_companions:
            generate_ui_advmode__T_companions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_conversation:
            generate_ui_advmode__T_conversation_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_conversation__T_choices:
            generate_ui_advmode__T_conversation__T_choices_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_conversation__T_targets:
            generate_ui_advmode__T_conversation__T_targets_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_interactions:
            generate_ui_advmode__T_interactions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_3124:
            generate_ui_advmode__T_unk_3124_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_3170:
            generate_ui_advmode__T_unk_3170_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_3170__T_unk_2:
            generate_ui_advmode__T_unk_3170__T_unk_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_v40_1:
            generate_ui_advmode__T_unk_v40_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_v40_2:
            generate_ui_advmode__T_unk_v40_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_v40_3:
            generate_ui_advmode__T_unk_v40_3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_v40_4:
            generate_ui_advmode__T_unk_v40_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_v40_4__T_unk_v40_4a:
            generate_ui_advmode__T_unk_v40_4__T_unk_v40_4a_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_v40_5:
            generate_ui_advmode__T_unk_v40_5_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_advmode__T_unk_v42_1:
            generate_ui_advmode__T_unk_v42_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_build_item_req:
            generate_ui_build_item_req_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_build_selector:
            generate_ui_build_selector_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_hotkey:
            generate_ui_hotkey_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_look_list:
            generate_ui_look_list_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_look_list__T_items:
            generate_ui_look_list__T_items_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus:
            generate_ui_sidebar_menus_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_barracks:
            generate_ui_sidebar_menus__T_barracks_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_building:
            generate_ui_sidebar_menus__T_building_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_command_line:
            generate_ui_sidebar_menus__T_command_line_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_designation:
            generate_ui_sidebar_menus__T_designation_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_hospital:
            generate_ui_sidebar_menus__T_hospital_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_job_details:
            generate_ui_sidebar_menus__T_job_details_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_location:
            generate_ui_sidebar_menus__T_location_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_minimap:
            generate_ui_sidebar_menus__T_minimap_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_unit:
            generate_ui_sidebar_menus__T_unit_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_unit_cursor:
            generate_ui_sidebar_menus__T_unit_cursor_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_unit_skills:
            generate_ui_sidebar_menus__T_unit_skills_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_workshop_job:
            generate_ui_sidebar_menus__T_workshop_job_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_sidebar_menus__T_zone:
            generate_ui_sidebar_menus__T_zone_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::ui_unit_view_mode:
            generate_ui_unit_view_mode_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit:
            generate_unit_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_animal:
            generate_unit__T_animal_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_appearance:
            generate_unit__T_appearance_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_body:
            generate_unit__T_body_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_counters:
            generate_unit__T_counters_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_counters2:
            generate_unit__T_counters2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_curse:
            generate_unit__T_curse_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy:
            generate_unit__T_enemy_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_undead:
            generate_unit__T_enemy__T_undead_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_unk_448:
            generate_unit__T_enemy__T_unk_448_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_unk_448__T_unk:
            generate_unit__T_enemy__T_unk_448__T_unk_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_unk_44c:
            generate_unit__T_enemy__T_unk_44c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_unk_v40_sub3:
            generate_unit__T_enemy__T_unk_v40_sub3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_2:
            generate_unit__T_enemy__T_unk_v40_sub3__T_unk_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_6:
            generate_unit__T_enemy__T_unk_v40_sub3__T_unk_6_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7:
            generate_unit__T_enemy__T_unk_v40_sub3__T_unk_7_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1:
            generate_unit__T_enemy__T_unk_v40_sub3__T_unk_7__T_unk_sub1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_enemy__T_witness_reports:
            generate_unit__T_enemy__T_witness_reports_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_job:
            generate_unit__T_job_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_meeting:
            generate_unit__T_meeting_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_military:
            generate_unit__T_military_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_opponent:
            generate_unit__T_opponent_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_path:
            generate_unit__T_path_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_reports:
            generate_unit__T_reports_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_status:
            generate_unit__T_status_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_status2:
            generate_unit__T_status2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_status__T_eat_history:
            generate_unit__T_status__T_eat_history_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_status__T_eat_history__T_drink:
            generate_unit__T_status__T_eat_history__T_drink_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_status__T_eat_history__T_food:
            generate_unit__T_status__T_eat_history__T_food_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_syndromes:
            generate_unit__T_syndromes_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit__T_unknown7:
            generate_unit__T_unknown7_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action:
            generate_unit_action_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data:
            generate_unit_action__T_data_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_attack:
            generate_unit_action__T_data__T_attack_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_attack__T_unk_4:
            generate_unit_action__T_data__T_attack__T_unk_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_block:
            generate_unit_action__T_data__T_block_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_climb:
            generate_unit_action__T_data__T_climb_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_dodge:
            generate_unit_action__T_data__T_dodge_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_holditem:
            generate_unit_action__T_data__T_holditem_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_holdterrain:
            generate_unit_action__T_data__T_holdterrain_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_job:
            generate_unit_action__T_data__T_job_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_job2:
            generate_unit_action__T_data__T_job2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_jump:
            generate_unit_action__T_data__T_jump_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_liedown:
            generate_unit_action__T_data__T_liedown_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_move:
            generate_unit_action__T_data__T_move_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_parry:
            generate_unit_action__T_data__T_parry_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_pushobject:
            generate_unit_action__T_data__T_pushobject_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_recover:
            generate_unit_action__T_data__T_recover_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_releaseitem:
            generate_unit_action__T_data__T_releaseitem_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_releaseterrain:
            generate_unit_action__T_data__T_releaseterrain_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_standup:
            generate_unit_action__T_data__T_standup_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_suckblood:
            generate_unit_action__T_data__T_suckblood_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_talk:
            generate_unit_action__T_data__T_talk_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_action__T_data__T_unsteady:
            generate_unit_action__T_data__T_unsteady_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_appearance:
            generate_unit_appearance_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_attribute:
            generate_unit_attribute_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_chunk:
            generate_unit_chunk_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_chunk__T_units:
            generate_unit_chunk__T_units_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_coin_debt:
            generate_unit_coin_debt_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_complaint:
            generate_unit_complaint_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_dance_skill:
            generate_unit_dance_skill_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_demand:
            generate_unit_demand_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_emotion_memory:
            generate_unit_emotion_memory_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_genes:
            generate_unit_genes_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_ghost_info:
            generate_unit_ghost_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_ghost_info__T_target:
            generate_unit_ghost_info__T_target_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_health_info:
            generate_unit_health_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_health_info__T_op_history:
            generate_unit_health_info__T_op_history_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_health_info__T_op_history__T_info:
            generate_unit_health_info__T_op_history__T_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_health_info__T_op_history__T_info__T_bandage:
            generate_unit_health_info__T_op_history__T_info__T_bandage_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_health_info__T_op_history__T_info__T_crutch:
            generate_unit_health_info__T_op_history__T_info__T_crutch_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_instrument_skill:
            generate_unit_instrument_skill_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_inventory_item:
            generate_unit_inventory_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_item_use:
            generate_unit_item_use_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_item_wrestle:
            generate_unit_item_wrestle_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_misc_trait:
            generate_unit_misc_trait_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_musical_skill:
            generate_unit_musical_skill_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality:
            generate_unit_personality_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_dreams:
            generate_unit_personality__T_dreams_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_emotions:
            generate_unit_personality__T_emotions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_memories:
            generate_unit_personality__T_memories_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_memories__T_reflected_on:
            generate_unit_personality__T_memories__T_reflected_on_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_needs:
            generate_unit_personality__T_needs_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_unk5:
            generate_unit_personality__T_unk5_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_unk_v40_2:
            generate_unit_personality__T_unk_v40_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_unk_v40_6:
            generate_unit_personality__T_unk_v40_6_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_personality__T_values:
            generate_unit_personality__T_values_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_poetic_skill:
            generate_unit_poetic_skill_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_preference:
            generate_unit_preference_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_request:
            generate_unit_request_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_skill:
            generate_unit_skill_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_soul:
            generate_unit_soul_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_soul__T_performance_skills:
            generate_unit_soul__T_performance_skills_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_storage_status:
            generate_unit_storage_status_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_syndrome:
            generate_unit_syndrome_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_syndrome__T_symptoms:
            generate_unit_syndrome__T_symptoms_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_unk_138:
            generate_unit_unk_138_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_wound:
            generate_unit_wound_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::unit_wound__T_parts:
            generate_unit_wound__T_parts_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::vehicle:
            generate_vehicle_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::vermin:
            generate_vermin_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen:
            generate_viewscreen_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_adopt_regionst:
            generate_viewscreen_adopt_regionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_adventure_logst:
            generate_viewscreen_adventure_logst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_announcelistst:
            generate_viewscreen_announcelistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_assign_display_itemst:
            generate_viewscreen_assign_display_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_barterst:
            generate_viewscreen_barterst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_buildinglistst:
            generate_viewscreen_buildinglistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_buildingst:
            generate_viewscreen_buildingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_choose_start_sitest:
            generate_viewscreen_choose_start_sitest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_choose_start_sitest__T_finder:
            generate_viewscreen_choose_start_sitest__T_finder_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_civlistst:
            generate_viewscreen_civlistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_civlistst__T_artifact_details:
            generate_viewscreen_civlistst__T_artifact_details_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_civlistst__T_rumors:
            generate_viewscreen_civlistst__T_rumors_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_civlistst__T_unk_cache:
            generate_viewscreen_civlistst__T_unk_cache_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp1:
            generate_viewscreen_civlistst__T_unk_cache__T_tmp1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_civlistst__T_unk_cache__T_tmp2:
            generate_viewscreen_civlistst__T_unk_cache__T_tmp2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_createquotast:
            generate_viewscreen_createquotast_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_customize_unitst:
            generate_viewscreen_customize_unitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_dungeon_monsterstatusst:
            generate_viewscreen_dungeon_monsterstatusst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_dungeon_wrestlest:
            generate_viewscreen_dungeon_wrestlest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_dungeon_wrestlest__T_unk1:
            generate_viewscreen_dungeon_wrestlest__T_unk1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_dungeonmodest:
            generate_viewscreen_dungeonmodest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_dwarfmodest:
            generate_viewscreen_dwarfmodest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_entityst:
            generate_viewscreen_entityst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_export_graphical_mapst:
            generate_viewscreen_export_graphical_mapst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_export_regionst:
            generate_viewscreen_export_regionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_export_regionst__T_unk1:
            generate_viewscreen_export_regionst__T_unk1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_game_cleanerst:
            generate_viewscreen_game_cleanerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst:
            generate_viewscreen_image_creatorst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst__T_artifacts:
            generate_viewscreen_image_creatorst__T_artifacts_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst__T_descriptions:
            generate_viewscreen_image_creatorst__T_descriptions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst__T_entities:
            generate_viewscreen_image_creatorst__T_entities_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst__T_objects:
            generate_viewscreen_image_creatorst__T_objects_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst__T_plants:
            generate_viewscreen_image_creatorst__T_plants_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst__T_shapes:
            generate_viewscreen_image_creatorst__T_shapes_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst__T_sites:
            generate_viewscreen_image_creatorst__T_sites_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_image_creatorst__T_trees:
            generate_viewscreen_image_creatorst__T_trees_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_itemst:
            generate_viewscreen_itemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_joblistst:
            generate_viewscreen_joblistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_jobmanagementst:
            generate_viewscreen_jobmanagementst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_jobst:
            generate_viewscreen_jobst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_justicest:
            generate_viewscreen_justicest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_kitchenprefst:
            generate_viewscreen_kitchenprefst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer:
            generate_viewscreen_layer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_arena_creaturest:
            generate_viewscreen_layer_arena_creaturest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_assigntradest:
            generate_viewscreen_layer_assigntradest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_choose_language_namest:
            generate_viewscreen_layer_choose_language_namest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_currencyst:
            generate_viewscreen_layer_currencyst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_export_play_mapst:
            generate_viewscreen_layer_export_play_mapst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst:
            generate_viewscreen_layer_militaryst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_ammo:
            generate_viewscreen_layer_militaryst__T_ammo_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_ammo__T_add_item:
            generate_viewscreen_layer_militaryst__T_ammo__T_add_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_ammo__T_material:
            generate_viewscreen_layer_militaryst__T_ammo__T_material_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_equip:
            generate_viewscreen_layer_militaryst__T_equip_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_equip__T_add_item:
            generate_viewscreen_layer_militaryst__T_equip__T_add_item_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_equip__T_assigned:
            generate_viewscreen_layer_militaryst__T_equip__T_assigned_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_equip__T_color:
            generate_viewscreen_layer_militaryst__T_equip__T_color_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_equip__T_material:
            generate_viewscreen_layer_militaryst__T_equip__T_material_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_equip__T_uniform:
            generate_viewscreen_layer_militaryst__T_equip__T_uniform_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_positions:
            generate_viewscreen_layer_militaryst__T_positions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_squad_members:
            generate_viewscreen_layer_militaryst__T_squad_members_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_militaryst__T_squads:
            generate_viewscreen_layer_militaryst__T_squads_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_musicsoundst:
            generate_viewscreen_layer_musicsoundst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_noblelistst:
            generate_viewscreen_layer_noblelistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_noblelistst__T_candidates:
            generate_viewscreen_layer_noblelistst__T_candidates_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_noblelistst__T_info:
            generate_viewscreen_layer_noblelistst__T_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_overall_healthst:
            generate_viewscreen_layer_overall_healthst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_reactionst:
            generate_viewscreen_layer_reactionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_squad_schedulest:
            generate_viewscreen_layer_squad_schedulest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_stockpilest:
            generate_viewscreen_layer_stockpilest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_stone_restrictionst:
            generate_viewscreen_layer_stone_restrictionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_unit_actionst:
            generate_viewscreen_layer_unit_actionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_unit_healthst:
            generate_viewscreen_layer_unit_healthst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_unit_relationshipst:
            generate_viewscreen_layer_unit_relationshipst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_world_gen_param_presetst:
            generate_viewscreen_layer_world_gen_param_presetst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_world_gen_paramst:
            generate_viewscreen_layer_world_gen_paramst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_layer_world_gen_paramst__T_unk1:
            generate_viewscreen_layer_world_gen_paramst__T_unk1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_legendsst:
            generate_viewscreen_legendsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_legendsst__T_anon_7:
            generate_viewscreen_legendsst__T_anon_7_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_legendsst__T_anon_7__T_anon_3:
            generate_viewscreen_legendsst__T_anon_7__T_anon_3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_loadgamest:
            generate_viewscreen_loadgamest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_locationsst:
            generate_viewscreen_locationsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_meetingst:
            generate_viewscreen_meetingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_movieplayerst:
            generate_viewscreen_movieplayerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_new_regionst:
            generate_viewscreen_new_regionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_noblest:
            generate_viewscreen_noblest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_optionst:
            generate_viewscreen_optionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_overallstatusst:
            generate_viewscreen_overallstatusst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_petitionsst:
            generate_viewscreen_petitionsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_petst:
            generate_viewscreen_petst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_petst__T_animal:
            generate_viewscreen_petst__T_animal_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_pricest:
            generate_viewscreen_pricest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_reportlistst:
            generate_viewscreen_reportlistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_requestagreementst:
            generate_viewscreen_requestagreementst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_savegamest:
            generate_viewscreen_savegamest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_selectitemst:
            generate_viewscreen_selectitemst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_setupadventurest:
            generate_viewscreen_setupadventurest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_setupadventurest__T_races_info:
            generate_viewscreen_setupadventurest__T_races_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_setupdwarfgamest:
            generate_viewscreen_setupdwarfgamest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_setupdwarfgamest__T_animals:
            generate_viewscreen_setupdwarfgamest__T_animals_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43:
            generate_viewscreen_setupdwarfgamest__T_unk_v43_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9:
            generate_viewscreen_setupdwarfgamest__T_unk_v43__T_unk_v43_sub9_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_storesst:
            generate_viewscreen_storesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_textviewerst:
            generate_viewscreen_textviewerst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_textviewerst__T_formatted_text:
            generate_viewscreen_textviewerst__T_formatted_text_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_titlest:
            generate_viewscreen_titlest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_titlest__T_start_savegames:
            generate_viewscreen_titlest__T_start_savegames_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_topicmeeting_fill_land_holder_positionsst:
            generate_viewscreen_topicmeeting_fill_land_holder_positionsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_topicmeeting_takerequestsst:
            generate_viewscreen_topicmeeting_takerequestsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_topicmeetingst:
            generate_viewscreen_topicmeetingst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_tradeagreementst:
            generate_viewscreen_tradeagreementst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_tradegoodsst:
            generate_viewscreen_tradegoodsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_tradelistst:
            generate_viewscreen_tradelistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_treasurelistst:
            generate_viewscreen_treasurelistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_unitlistst:
            generate_viewscreen_unitlistst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_unitst:
            generate_viewscreen_unitst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_update_regionst:
            generate_viewscreen_update_regionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_wagesst:
            generate_viewscreen_wagesst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_workquota_conditionst:
            generate_viewscreen_workquota_conditionst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_workquota_conditionst__T_traits:
            generate_viewscreen_workquota_conditionst__T_traits_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_workquota_detailsst:
            generate_viewscreen_workquota_detailsst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::viewscreen_workshop_profilest:
            generate_viewscreen_workshop_profilest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::weapon_attack:
            generate_weapon_attack_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::web_cluster:
            generate_web_cluster_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::widget_menu:
            generate_widget_menu_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::widget_textbox:
            generate_widget_textbox_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::workshop_profile:
            generate_workshop_profile_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world:
            generate_world_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_activities:
            generate_world__T_activities_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_agreements:
            generate_world__T_agreements_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_arena_settings:
            generate_world__T_arena_settings_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_arena_spawn:
            generate_world__T_arena_spawn_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_arena_spawn__T_equipment:
            generate_world__T_arena_spawn__T_equipment_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_arena_spawn__T_item_types:
            generate_world__T_arena_spawn__T_item_types_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_armies:
            generate_world__T_armies_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_army_controllers:
            generate_world__T_army_controllers_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_army_tracking_info:
            generate_world__T_army_tracking_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_artifacts:
            generate_world__T_artifacts_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_belief_systems:
            generate_world__T_belief_systems_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_crimes:
            generate_world__T_crimes_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_cultural_identities:
            generate_world__T_cultural_identities_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_cur_savegame:
            generate_world__T_cur_savegame_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_dance_forms:
            generate_world__T_dance_forms_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_enemy_status_cache:
            generate_world__T_enemy_status_cache_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_entities:
            generate_world__T_entities_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_features:
            generate_world__T_features_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_flow_engine:
            generate_world__T_flow_engine_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_flow_guides:
            generate_world__T_flow_guides_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_formations:
            generate_world__T_formations_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_identities:
            generate_world__T_identities_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_incidents:
            generate_world__T_incidents_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_interaction_instances:
            generate_world__T_interaction_instances_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_items:
            generate_world__T_items_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_languages:
            generate_world__T_languages_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_map:
            generate_world__T_map_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_map_extras:
            generate_world__T_map_extras_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_math:
            generate_world__T_math_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_math__T_approx:
            generate_world__T_math__T_approx_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_musical_forms:
            generate_world__T_musical_forms_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_nemesis:
            generate_world__T_nemesis_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_occupations:
            generate_world__T_occupations_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_pathfinder:
            generate_world__T_pathfinder_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_pathfinder__T_boundary_heap:
            generate_world__T_pathfinder__T_boundary_heap_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_plants:
            generate_world__T_plants_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_poetic_forms:
            generate_world__T_poetic_forms_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_profession_skills:
            generate_world__T_profession_skills_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_rhythms:
            generate_world__T_rhythms_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_scales:
            generate_world__T_scales_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_schedules:
            generate_world__T_schedules_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_squads:
            generate_world__T_squads_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_status:
            generate_world__T_status_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_status__T_slots:
            generate_world__T_status__T_slots_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_stockpile:
            generate_world__T_stockpile_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_stockpile__T_simple1:
            generate_world__T_stockpile__T_simple1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_stockpile__T_simple2:
            generate_world__T_stockpile__T_simple2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_stockpile__T_simple3:
            generate_world__T_stockpile__T_simple3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_units:
            generate_world__T_units_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_131ec0:
            generate_world__T_unk_131ec0_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_131ef0:
            generate_world__T_unk_131ef0_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_131ef0__T_unk_2:
            generate_world__T_unk_131ef0__T_unk_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_19325c:
            generate_world__T_unk_19325c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_19325c__T_anon_1:
            generate_world__T_unk_19325c__T_anon_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_19325c__T_anon_2:
            generate_world__T_unk_19325c__T_anon_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_19325c__T_anon_3:
            generate_world__T_unk_19325c__T_anon_3_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_59dc4:
            generate_world__T_unk_59dc4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_59dc4__T_unk1:
            generate_world__T_unk_59dc4__T_unk1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_unk_v40_6:
            generate_world__T_unk_v40_6_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_vehicles:
            generate_world__T_vehicles_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_vermin:
            generate_world__T_vermin_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_worldgen:
            generate_world__T_worldgen_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_worldgen__T_worldgen_parms:
            generate_world__T_worldgen__T_worldgen_parms_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_worldgen_coord_buf:
            generate_world__T_worldgen_coord_buf_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_worldgen_status:
            generate_world__T_worldgen_status_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world__T_written_contents:
            generate_world__T_written_contents_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction:
            generate_world_construction_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_bridgest:
            generate_world_construction_bridgest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_roadst:
            generate_world_construction_roadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_square:
            generate_world_construction_square_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_square_bridgest:
            generate_world_construction_square_bridgest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_square_roadst:
            generate_world_construction_square_roadst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_square_tunnelst:
            generate_world_construction_square_tunnelst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_square_wallst:
            generate_world_construction_square_wallst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_tunnelst:
            generate_world_construction_tunnelst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_construction_wallst:
            generate_world_construction_wallst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_dat_summary:
            generate_world_dat_summary_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data:
            generate_world_data_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_constructions:
            generate_world_data__T_constructions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_feature_map:
            generate_world_data__T_feature_map_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_feature_map__T_features:
            generate_world_data__T_feature_map__T_features_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_freakish_weather:
            generate_world_data__T_freakish_weather_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_mountain_peaks:
            generate_world_data__T_mountain_peaks_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_150:
            generate_world_data__T_unk_150_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_150__T_unk_18:
            generate_world_data__T_unk_150__T_unk_18_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_150__T_unk_28:
            generate_world_data__T_unk_150__T_unk_28_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_150__T_unk_8:
            generate_world_data__T_unk_150__T_unk_8_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_170:
            generate_world_data__T_unk_170_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_170__T_unk_4:
            generate_world_data__T_unk_170__T_unk_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_274:
            generate_world_data__T_unk_274_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_274__T_unk_10:
            generate_world_data__T_unk_274__T_unk_10_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_482f8:
            generate_world_data__T_unk_482f8_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_data__T_unk_b4:
            generate_world_data__T_unk_b4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_gen_param_basest:
            generate_world_gen_param_basest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_gen_param_charst:
            generate_world_gen_param_charst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_gen_param_memberst:
            generate_world_gen_param_memberst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_gen_param_seedst:
            generate_world_gen_param_seedst_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_gen_param_valuest:
            generate_world_gen_param_valuest_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_geo_biome:
            generate_world_geo_biome_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_geo_layer:
            generate_world_geo_layer_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_history:
            generate_world_history_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_history__T_event_collections:
            generate_world_history__T_event_collections_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_landmass:
            generate_world_landmass_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_object_data:
            generate_world_object_data_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_object_data__T_offloaded_buildings:
            generate_world_object_data__T_offloaded_buildings_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_object_data__T_offloaded_items:
            generate_world_object_data__T_offloaded_items_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_object_data__T_unk_94:
            generate_world_object_data__T_unk_94_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_population:
            generate_world_population_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_population_ref:
            generate_world_population_ref_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws:
            generate_world_raws_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_bodyglosses:
            generate_world_raws__T_bodyglosses_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_buildings:
            generate_world_raws__T_buildings_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_descriptors:
            generate_world_raws__T_descriptors_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_effects:
            generate_world_raws__T_effects_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_itemdefs:
            generate_world_raws__T_itemdefs_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_language:
            generate_world_raws__T_language_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_plants:
            generate_world_raws__T_plants_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_reactions:
            generate_world_raws__T_reactions_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_raws__T_syndromes:
            generate_world_raws__T_syndromes_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_region:
            generate_world_region_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_region_details:
            generate_world_region_details_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_region_details__T_edges:
            generate_world_region_details__T_edges_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_region_details__T_rivers_horizontal:
            generate_world_region_details__T_rivers_horizontal_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_region_details__T_rivers_vertical:
            generate_world_region_details__T_rivers_vertical_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_region_feature:
            generate_world_region_feature_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_river:
            generate_world_river_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site:
            generate_world_site_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_subtype_info:
            generate_world_site__T_subtype_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_1:
            generate_world_site__T_unk_1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_118:
            generate_world_site__T_unk_118_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_13c:
            generate_world_site__T_unk_13c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_188:
            generate_world_site__T_unk_188_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_188__T_unk1:
            generate_world_site__T_unk_188__T_unk1_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_1__T_units:
            generate_world_site__T_unk_1__T_units_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_21c:
            generate_world_site__T_unk_21c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_v40_2:
            generate_world_site__T_unk_v40_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_v40_4a:
            generate_world_site__T_unk_v40_4a_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_v40_4b:
            generate_world_site__T_unk_v40_4b_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_v40_4c:
            generate_world_site__T_unk_v40_4c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_v40_4d:
            generate_world_site__T_unk_v40_4d_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_v40_4d__T_anon_2:
            generate_world_site__T_unk_v40_4d__T_anon_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site__T_unk_v43_2:
            generate_world_site__T_unk_v43_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_inhabitant:
            generate_world_site_inhabitant_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_realization:
            generate_world_site_realization_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_realization__T_areas:
            generate_world_site_realization__T_areas_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_realization__T_building_map:
            generate_world_site_realization__T_building_map_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_realization__T_river_map:
            generate_world_site_realization__T_river_map_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_realization__T_unk_193bc:
            generate_world_site_realization__T_unk_193bc_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_realization__T_unk_193bc__T_unk_8:
            generate_world_site_realization__T_unk_193bc__T_unk_8_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_realization__T_unk_55e8:
            generate_world_site_realization__T_unk_55e8_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_realization__T_unk_55e8__T_unk_v40_2:
            generate_world_site_realization__T_unk_55e8__T_unk_v40_2_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_unk130:
            generate_world_site_unk130_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_site_unk130__T_unk_4:
            generate_world_site_unk130__T_unk_4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_underground_region:
            generate_world_underground_region_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_unk_20:
            generate_world_unk_20_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_unk_20__T_anon_7:
            generate_world_unk_20__T_anon_7_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_unk_6c:
            generate_world_unk_6c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_unk_9c:
            generate_world_unk_9c_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_unk_a8:
            generate_world_unk_a8_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_unk_b4:
            generate_world_unk_b4_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_unk_c0:
            generate_world_unk_c0_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::world_unk_c0__T_anon_7:
            generate_world_unk_c0__T_anon_7_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::wound_curse_info:
            generate_wound_curse_info_offsets(nullptr, p_table.m_offsets);
            break;

        case DF_Type::written_content:
            generate_written_content_offsets(nullptr, p_table.m_offsets);
            break;

        default:
            break;
    }
}

std::size_t OffsetsCache::get_offset(DF_Type p_type, const std::string& p_field)

{
    auto result = m_df_types_offset_table.find(p_type);

    if (result == m_df_types_offset_table.end())

    {
        auto new_table = new OffsetTable;

        fill_offsets(p_type, *new_table);

        m_df_types_offset_table[p_type] = *new_table;
    }

    result = m_df_types_offset_table.find(p_type);

    auto offset_table = (*result).second;

    auto result2 = offset_table.m_offsets.find(p_field);

    if (result2 != offset_table.m_offsets.end())

    {
        return (*result2).second;
    }

    throw "field not found";

    return 0;
}

} // namespace rdf
