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
#include "node.h"
#include "offsets_cache.h"


using namespace rdf;


DF_Type enum_base_type(DF_Type p_enum)
{
	switch(p_enum)
	{
		case DF_Type::ui_advmode_menu: return DF_Type::int16_t;
		case DF_Type::talk_choice_type: return DF_Type::int32_t;
		case DF_Type::assume_identity_mode: return DF_Type::int32_t;
		case DF_Type::announcement_type: return DF_Type::int16_t;
		case DF_Type::art_image_element_type: return DF_Type::int32_t;
		case DF_Type::art_image_property_type: return DF_Type::int32_t;
		case DF_Type::art_image_property_verb: return DF_Type::int16_t;
		case DF_Type::art_facet_type: return DF_Type::int32_t;
		case DF_Type::poetic_form_action: return DF_Type::int32_t;
		case DF_Type::poetic_form_pattern: return DF_Type::int32_t;
		case DF_Type::poetic_form_caesura_position: return DF_Type::int32_t;
		case DF_Type::poetic_form_mood: return DF_Type::int32_t;
		case DF_Type::poetic_form_subject: return DF_Type::int32_t;
		case DF_Type::poetic_form_additional_feature: return DF_Type::int32_t;
		case DF_Type::poetic_form_perspective__T_type: return DF_Type::int32_t;
		case DF_Type::musical_form_purpose: return DF_Type::int32_t;
		case DF_Type::musical_form_style: return DF_Type::int32_t;
		case DF_Type::musical_form_pitch_style: return DF_Type::int32_t;
		case DF_Type::unk_scale_enum_type: return DF_Type::int32_t;
		case DF_Type::occupation_type: return DF_Type::int32_t;
		case DF_Type::buildings_other_id: return DF_Type::int32_t;
		case DF_Type::building_type: return DF_Type::int32_t;
		case DF_Type::civzone_type: return DF_Type::int32_t;
		case DF_Type::furnace_type: return DF_Type::int16_t;
		case DF_Type::workshop_type: return DF_Type::int16_t;
		case DF_Type::construction_type: return DF_Type::int16_t;
		case DF_Type::shop_type: return DF_Type::int16_t;
		case DF_Type::siegeengine_type: return DF_Type::int16_t;
		case DF_Type::trap_type: return DF_Type::int16_t;
		case DF_Type::dfhack_room_quality_level: return DF_Type::int32_t;
		case DF_Type::creature_raw_flags: return DF_Type::int32_t;
		case DF_Type::caste_raw_flags: return DF_Type::int32_t;
		case DF_Type::body_part_raw_flags: return DF_Type::int32_t;
		case DF_Type::appearance_modifier_type: return DF_Type::int16_t;
		case DF_Type::body_part_layer_flags: return DF_Type::int32_t;
		case DF_Type::appearance_modifier_growth_interval: return DF_Type::int16_t;
		case DF_Type::gait_type: return DF_Type::int32_t;
		case DF_Type::creature_graphics_role: return DF_Type::int32_t;
		case DF_Type::tissue_style_type: return DF_Type::int16_t;
		case DF_Type::body_part_template_flags: return DF_Type::int32_t;
		case DF_Type::body_part_template_contype: return DF_Type::int16_t;
		case DF_Type::tissue_flags: return DF_Type::int32_t;
		case DF_Type::d_init_nickname: return DF_Type::int32_t;
		case DF_Type::d_init_z_view: return DF_Type::int32_t;
		case DF_Type::d_init_embark_confirm: return DF_Type::int32_t;
		case DF_Type::d_init_idlers: return DF_Type::int16_t;
		case DF_Type::d_init_tunnel: return DF_Type::int16_t;
		case DF_Type::d_init_flags1: return DF_Type::int32_t;
		case DF_Type::d_init_flags2: return DF_Type::int32_t;
		case DF_Type::d_init_flags3: return DF_Type::int32_t;
		case DF_Type::d_init_flags4: return DF_Type::int32_t;
		case DF_Type::pattern_type: return DF_Type::int16_t;
		case DF_Type::occasion_schedule_type: return DF_Type::int32_t;
		case DF_Type::occasion_schedule_feature: return DF_Type::int32_t;
		case DF_Type::entity_sell_category: return DF_Type::int16_t;
		case DF_Type::historical_entity_type: return DF_Type::int16_t;
		case DF_Type::training_knowledge_level: return DF_Type::int32_t;
		case DF_Type::entity_position_flags: return DF_Type::int32_t;
		case DF_Type::entity_material_category: return DF_Type::int16_t;
		case DF_Type::entity_event_type: return DF_Type::int32_t;
		case DF_Type::crime_type: return DF_Type::int32_t;
		case DF_Type::agreement_details_type: return DF_Type::int32_t;
		case DF_Type::entity_raw_flags: return DF_Type::int32_t;
		case DF_Type::site_type: return DF_Type::int32_t;
		case DF_Type::ethic_type: return DF_Type::int32_t;
		case DF_Type::ethic_response: return DF_Type::int16_t;
		case DF_Type::entity_name_type: return DF_Type::int32_t;
		case DF_Type::entity_position_raw_flags: return DF_Type::int32_t;
		case DF_Type::entity_position_responsibility: return DF_Type::int16_t;
		case DF_Type::weather_type: return DF_Type::int8_t;
		case DF_Type::next_global_id: return DF_Type::int32_t;
		case DF_Type::game_mode: return DF_Type::int32_t;
		case DF_Type::game_type: return DF_Type::int32_t;
		case DF_Type::lever_target_type: return DF_Type::int8_t;
		case DF_Type::zoom_commands: return DF_Type::int32_t;
		case DF_Type::justification: return DF_Type::uint8_t;
		case DF_Type::reputation_type: return DF_Type::int32_t;
		case DF_Type::whereabouts_type: return DF_Type::int16_t;
		case DF_Type::death_condition_type: return DF_Type::int8_t;
		case DF_Type::plot_role_type: return DF_Type::int32_t;
		case DF_Type::plot_strategy_type: return DF_Type::int32_t;
		case DF_Type::histfig_flags: return DF_Type::int32_t;
		case DF_Type::histfig_relationship_type: return DF_Type::int16_t;
		case DF_Type::vague_relationship_type: return DF_Type::int16_t;
		case DF_Type::identity_type: return DF_Type::int32_t;
		case DF_Type::mental_picture_property_type: return DF_Type::int32_t;
		case DF_Type::mental_picture_element_type: return DF_Type::int32_t;
		case DF_Type::history_event_type: return DF_Type::int32_t;
		case DF_Type::history_event_reason: return DF_Type::int32_t;
		case DF_Type::architectural_element: return DF_Type::int16_t;
		case DF_Type::history_event_flags: return DF_Type::int32_t;
		case DF_Type::history_event_war_attacked_sitest__T_unk_1: return DF_Type::int8_t;
		case DF_Type::death_type: return DF_Type::int16_t;
		case DF_Type::entity_action_type: return DF_Type::int32_t;
		case DF_Type::masterpiece_loss_type: return DF_Type::int16_t;
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return DF_Type::int16_t;
		case DF_Type::history_event_simple_battle_subtype: return DF_Type::int16_t;
		case DF_Type::artifact_claim_type: return DF_Type::int32_t;
		case DF_Type::histfig_body_state: return DF_Type::int8_t;
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return DF_Type::int32_t;
		case DF_Type::site_dispute_type: return DF_Type::int32_t;
		case DF_Type::insurrection_outcome: return DF_Type::int32_t;
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return DF_Type::int32_t;
		case DF_Type::tactical_situation: return DF_Type::int32_t;
		case DF_Type::history_event_collection_type: return DF_Type::int32_t;
		case DF_Type::era_type: return DF_Type::int16_t;
		case DF_Type::init_display_flags: return DF_Type::int32_t;
		case DF_Type::init_media_flags: return DF_Type::int32_t;
		case DF_Type::init_input_flags: return DF_Type::int32_t;
		case DF_Type::init_window_flags: return DF_Type::int32_t;
		case DF_Type::interaction_flags: return DF_Type::int32_t;
		case DF_Type::interaction_effect_type: return DF_Type::int32_t;
		case DF_Type::interaction_effect_location_hint: return DF_Type::int32_t;
		case DF_Type::interaction_source_type: return DF_Type::int32_t;
		case DF_Type::interaction_source_usage_hint: return DF_Type::int32_t;
		case DF_Type::interaction_target_type: return DF_Type::int32_t;
		case DF_Type::interaction_target_location_type: return DF_Type::int32_t;
		case DF_Type::breath_attack_type: return DF_Type::int16_t;
		case DF_Type::item_type: return DF_Type::int16_t;
		case DF_Type::itemdef_flags: return DF_Type::int32_t;
		case DF_Type::ammo_flags: return DF_Type::int32_t;
		case DF_Type::armor_general_flags: return DF_Type::int32_t;
		case DF_Type::armor_flags: return DF_Type::int32_t;
		case DF_Type::gloves_flags: return DF_Type::int32_t;
		case DF_Type::helm_flags: return DF_Type::int32_t;
		case DF_Type::instrument_flags: return DF_Type::int32_t;
		case DF_Type::sound_production_type: return DF_Type::int32_t;
		case DF_Type::pitch_choice_type: return DF_Type::int32_t;
		case DF_Type::tuning_type: return DF_Type::int32_t;
		case DF_Type::timbre_type: return DF_Type::int32_t;
		case DF_Type::pants_flags: return DF_Type::int32_t;
		case DF_Type::shoes_flags: return DF_Type::int32_t;
		case DF_Type::tool_flags: return DF_Type::int32_t;
		case DF_Type::tool_uses: return DF_Type::int16_t;
		case DF_Type::toy_flags: return DF_Type::int32_t;
		case DF_Type::trapcomp_flags: return DF_Type::int32_t;
		case DF_Type::weapon_flags: return DF_Type::int32_t;
		case DF_Type::items_other_id: return DF_Type::int32_t;
		case DF_Type::job_item_vector_id: return DF_Type::int16_t;
		case DF_Type::improvement_type: return DF_Type::int32_t;
		case DF_Type::itemimprovement_specific_type: return DF_Type::int32_t;
		case DF_Type::written_content_type: return DF_Type::int32_t;
		case DF_Type::written_content_style: return DF_Type::int32_t;
		case DF_Type::item_magicness_type: return DF_Type::int16_t;
		case DF_Type::item_quality: return DF_Type::int16_t;
		case DF_Type::slab_engraving_type: return DF_Type::int16_t;
		case DF_Type::corpse_material_type: return DF_Type::int32_t;
		case DF_Type::job_type_class: return DF_Type::int32_t;
		case DF_Type::job_type: return DF_Type::int16_t;
		case DF_Type::job_subtype_surgery: return DF_Type::int32_t;
		case DF_Type::job_art_specification__T_type: return DF_Type::int32_t;
		case DF_Type::manager_order_condition_order__T_condition: return DF_Type::int32_t;
		case DF_Type::guild_id: return DF_Type::int16_t;
		case DF_Type::interface_key: return DF_Type::Long;
		case DF_Type::dfhack_knowledge_scholar_flag: return DF_Type::int32_t;
		case DF_Type::part_of_speech: return DF_Type::int16_t;
		case DF_Type::sphere_type: return DF_Type::int16_t;
		case DF_Type::language_name_category: return DF_Type::int32_t;
		case DF_Type::nemesis_flags: return DF_Type::int32_t;
		case DF_Type::machine_type: return DF_Type::int32_t;
		case DF_Type::screw_pump_direction: return DF_Type::int8_t;
		case DF_Type::tile_traffic: return DF_Type::uint32_t;
		case DF_Type::tile_dig_designation: return DF_Type::uint32_t;
		case DF_Type::tile_liquid: return DF_Type::uint32_t;
		case DF_Type::tile_building_occ: return DF_Type::uint32_t;
		case DF_Type::tile_liquid_flow_dir: return DF_Type::uint16_t;
		case DF_Type::block_square_event_type: return DF_Type::int32_t;
		case DF_Type::feature_type: return DF_Type::int32_t;
		case DF_Type::feature_init_flags: return DF_Type::int32_t;
		case DF_Type::layer_type: return DF_Type::int16_t;
		case DF_Type::feature_alteration_type: return DF_Type::int32_t;
		case DF_Type::world_construction_type: return DF_Type::int32_t;
		case DF_Type::biome_type: return DF_Type::int32_t;
		case DF_Type::flow_type: return DF_Type::int16_t;
		case DF_Type::flow_guide_type: return DF_Type::int32_t;
		case DF_Type::region_block_event_type: return DF_Type::int32_t;
		case DF_Type::craft_material_class: return DF_Type::int32_t;
		case DF_Type::builtin_mats: return DF_Type::int32_t;
		case DF_Type::material_flags: return DF_Type::int32_t;
		case DF_Type::matter_state: return DF_Type::int16_t;
		case DF_Type::strain_type: return DF_Type::int32_t;
		case DF_Type::inorganic_flags: return DF_Type::int32_t;
		case DF_Type::environment_type: return DF_Type::int16_t;
		case DF_Type::inclusion_type: return DF_Type::int16_t;
		case DF_Type::organic_mat_category: return DF_Type::int32_t;
		case DF_Type::meeting_topic: return DF_Type::int16_t;
		case DF_Type::meeting_event_type: return DF_Type::int16_t;
		case DF_Type::activity_entry_type: return DF_Type::int16_t;
		case DF_Type::activity_event_type: return DF_Type::int32_t;
		case DF_Type::conversation_menu: return DF_Type::int32_t;
		case DF_Type::performance_event_type: return DF_Type::int32_t;
		case DF_Type::performance_participant_type: return DF_Type::int32_t;
		case DF_Type::uniform_category: return DF_Type::int16_t;
		case DF_Type::barrack_preference_category: return DF_Type::int32_t;
		case DF_Type::squad_event_type: return DF_Type::int16_t;
		case DF_Type::squad_order_type: return DF_Type::int32_t;
		case DF_Type::squad_order_cannot_reason: return DF_Type::int32_t;
		case DF_Type::army_flags: return DF_Type::int32_t;
		case DF_Type::unit_path_goal: return DF_Type::int16_t;
		case DF_Type::unit_station_type: return DF_Type::int16_t;
		case DF_Type::plant_raw_flags: return DF_Type::int32_t;
		case DF_Type::projectile_type: return DF_Type::int32_t;
		case DF_Type::reaction_flags: return DF_Type::int32_t;
		case DF_Type::reaction_reagent_type: return DF_Type::int32_t;
		case DF_Type::reaction_product_type: return DF_Type::int32_t;
		case DF_Type::reaction_product_item_flags: return DF_Type::int32_t;
		case DF_Type::reaction_product_improvement_flags: return DF_Type::int32_t;
		case DF_Type::general_ref_type: return DF_Type::int32_t;
		case DF_Type::specific_ref_type: return DF_Type::int32_t;
		case DF_Type::histfig_entity_link_type: return DF_Type::int32_t;
		case DF_Type::histfig_site_link_type: return DF_Type::int32_t;
		case DF_Type::histfig_hf_link_type: return DF_Type::int32_t;
		case DF_Type::entity_entity_link_type: return DF_Type::int16_t;
		case DF_Type::entity_site_link_type: return DF_Type::int32_t;
		case DF_Type::resource_allotment_specifier_type: return DF_Type::int32_t;
		case DF_Type::profession: return DF_Type::int16_t;
		case DF_Type::unit_labor_category: return DF_Type::int32_t;
		case DF_Type::unit_labor: return DF_Type::int32_t;
		case DF_Type::job_skill_class: return DF_Type::int32_t;
		case DF_Type::job_skill: return DF_Type::int16_t;
		case DF_Type::hauler_type: return DF_Type::int32_t;
		case DF_Type::furniture_type: return DF_Type::int32_t;
		case DF_Type::stockpile_category: return DF_Type::int16_t;
		case DF_Type::stockpile_list: return DF_Type::int32_t;
		case DF_Type::creature_interaction_effect_type: return DF_Type::int32_t;
		case DF_Type::creature_interaction_effect_target_mode: return DF_Type::int16_t;
		case DF_Type::tiletype_shape_basic: return DF_Type::int32_t;
		case DF_Type::tiletype_shape: return DF_Type::int32_t;
		case DF_Type::tiletype_material: return DF_Type::int32_t;
		case DF_Type::tiletype_variant: return DF_Type::int32_t;
		case DF_Type::tiletype_special: return DF_Type::int32_t;
		case DF_Type::tiletype: return DF_Type::int16_t;
		case DF_Type::build_req_choice_type: return DF_Type::int32_t;
		case DF_Type::ui_hotkey__T_cmd: return DF_Type::int16_t;
		case DF_Type::ui_sidebar_mode: return DF_Type::int16_t;
		case DF_Type::kitchen_exc_type: return DF_Type::int8_t;
		case DF_Type::timed_event_type: return DF_Type::int16_t;
		case DF_Type::emotion_type: return DF_Type::int32_t;
		case DF_Type::unit_thought_type: return DF_Type::int32_t;
		case DF_Type::value_type: return DF_Type::int32_t;
		case DF_Type::goal_type: return DF_Type::int32_t;
		case DF_Type::personality_facet_type: return DF_Type::int32_t;
		case DF_Type::physical_attribute_type: return DF_Type::int32_t;
		case DF_Type::mental_attribute_type: return DF_Type::int32_t;
		case DF_Type::mood_type: return DF_Type::int16_t;
		case DF_Type::ghost_type: return DF_Type::int16_t;
		case DF_Type::animal_training_level: return DF_Type::int32_t;
		case DF_Type::unit_report_type: return DF_Type::int16_t;
		case DF_Type::skill_rating: return DF_Type::int32_t;
		case DF_Type::unit_relationship_type: return DF_Type::int16_t;
		case DF_Type::need_type: return DF_Type::int32_t;
		case DF_Type::ghost_goal: return DF_Type::int16_t;
		case DF_Type::wound_effect_type: return DF_Type::int16_t;
		case DF_Type::misc_trait_type: return DF_Type::int16_t;
		case DF_Type::unit_action_type: return DF_Type::int32_t;
		case DF_Type::interface_breakdown_types: return DF_Type::int8_t;
		case DF_Type::embark_finder_option: return DF_Type::int32_t;
		case DF_Type::export_map_type: return DF_Type::int32_t;
		case DF_Type::viewscreen_image_creator_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_kitchenpref_page: return DF_Type::int32_t;
		case DF_Type::adventurer_attribute_level: return DF_Type::int32_t;
		case DF_Type::viewscreen_unitlist_page: return DF_Type::int32_t;
		case DF_Type::world_population_type: return DF_Type::int8_t;
		case DF_Type::world_region_type: return DF_Type::int16_t;
		case DF_Type::geo_layer_type: return DF_Type::int16_t;
		case DF_Type::region_map_entry_flags: return DF_Type::int32_t;
		case DF_Type::front_type: return DF_Type::uint16_t;
		case DF_Type::cumulus_type: return DF_Type::uint16_t;
		case DF_Type::stratus_type: return DF_Type::uint16_t;
		case DF_Type::fog_type: return DF_Type::uint16_t;
		case DF_Type::mountain_peak_flags: return DF_Type::int32_t;
		case DF_Type::abstract_building_type: return DF_Type::int32_t;
		case DF_Type::abstract_building_flags: return DF_Type::int32_t;
		case DF_Type::temple_deity_type: return DF_Type::int32_t;
		case DF_Type::world_site_type: return DF_Type::int16_t;
		case DF_Type::world_site_flags: return DF_Type::int32_t;
		case DF_Type::fortress_type: return DF_Type::int16_t;
		case DF_Type::monument_type: return DF_Type::int16_t;
		case DF_Type::lair_type: return DF_Type::int16_t;
		case DF_Type::site_realization_building_type: return DF_Type::int32_t;
		case DF_Type::site_shop_type: return DF_Type::int32_t;
		case DF_Type::tree_house_type: return DF_Type::int32_t;
		case DF_Type::hillock_house_type: return DF_Type::int32_t;
		case DF_Type::creation_zone_pwg_alteration_type: return DF_Type::int32_t;
		case DF_Type::worldgen_region_type: return DF_Type::int32_t;
		case DF_Type::worldgen_range_type: return DF_Type::int32_t;
		case DF_Type::units_other_id: return DF_Type::int32_t;
		case DF_Type::conflict_level: return DF_Type::int32_t;
		case DF_Type::combat_report_event_type: return DF_Type::int16_t;
		case DF_Type::conversation__T_state: return DF_Type::int32_t;
		case DF_Type::building_archerytargetst__T_archery_direction: return DF_Type::int8_t;
		case DF_Type::building_bridgest__T_direction: return DF_Type::int8_t;
		case DF_Type::building_siegeenginest__T_facing: return DF_Type::int8_t;
		case DF_Type::building_siegeenginest__T_action: return DF_Type::int8_t;
		case DF_Type::caste_body_info__T_interactions__T_type: return DF_Type::int32_t;
		case DF_Type::caravan_state__T_trade_state: return DF_Type::int8_t;
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return DF_Type::int32_t;
		case DF_Type::history_event_change_hf_statest__T_state: return DF_Type::int16_t;
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type: return DF_Type::int32_t;
		case DF_Type::history_event_body_abusedst__T_abuse_type: return DF_Type::int16_t;
		case DF_Type::history_event_hist_figure_travelst__T_reason: return DF_Type::int32_t;
		case DF_Type::init_display__T_windowed: return DF_Type::int32_t;
		case DF_Type::init_font__T_use_ttf: return DF_Type::int32_t;
		case DF_Type::job_item_ref__T_role: return DF_Type::int32_t;
		case DF_Type::manager_order__T_frequency: return DF_Type::int32_t;
		case DF_Type::manager_order_condition_item__T_compare_type: return DF_Type::int32_t;
		case DF_Type::mandate__T_mode: return DF_Type::int16_t;
		case DF_Type::unit_demand__T_place: return DF_Type::int16_t;
		case DF_Type::knowledge_scholar_category_flag__T_flag_type: return DF_Type::int32_t;
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return DF_Type::int32_t;
		case DF_Type::ui_advmode__T_travel_right_map: return DF_Type::int8_t;
		case DF_Type::ui_advmode__T_show_menu: return DF_Type::int8_t;
		case DF_Type::history_event_collection_battlest__T_attacker_merc_type: return DF_Type::int8_t;
		case DF_Type::army_controller__T_type: return DF_Type::int32_t;
		case DF_Type::stop_depart_condition__T_direction: return DF_Type::int32_t;
		case DF_Type::stop_depart_condition__T_mode: return DF_Type::int32_t;
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return DF_Type::int32_t;
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return DF_Type::int32_t;
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return DF_Type::int16_t;
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return DF_Type::int32_t;
		case DF_Type::ui_look_list__T_items__T_type: return DF_Type::int16_t;
		case DF_Type::ui_unit_view_mode__T_value: return DF_Type::int32_t;
		case DF_Type::unit_inventory_item__T_mode: return DF_Type::int16_t;
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type: return DF_Type::int32_t;
		case DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type: return DF_Type::int32_t;
		case DF_Type::unit_preference__T_type: return DF_Type::int16_t;
		case DF_Type::unit_complaint__T_type: return DF_Type::int32_t;
		case DF_Type::unit_request__T_type: return DF_Type::int16_t;
		case DF_Type::KeybindingScreen__T_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_adventure_logst__T_mode: return DF_Type::int8_t;
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return DF_Type::int16_t;
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return DF_Type::int32_t;
		case DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state: return DF_Type::int16_t;
		case DF_Type::viewscreen_choose_start_sitest__T_page: return DF_Type::int32_t;
		case DF_Type::mission__T_details__T_raid__T_raid_type: return DF_Type::int32_t;
		case DF_Type::mission__T_type: return DF_Type::int32_t;
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return DF_Type::int32_t;
		case DF_Type::viewscreen_civlistst__T_page: return DF_Type::int32_t;
		case DF_Type::viewscreen_game_cleanerst__T_state: return DF_Type::int32_t;
		case DF_Type::viewscreen_justicest__T_cur_column: return DF_Type::int32_t;
		case DF_Type::assign_trade_status__T_status: return DF_Type::int8_t;
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return DF_Type::int32_t;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_layer_militaryst__T_page: return DF_Type::int32_t;
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return DF_Type::int16_t;
		case DF_Type::viewscreen_legendsst__T_cur_page: return DF_Type::int16_t;
		case DF_Type::viewscreen_locationsst__T_in_edit: return DF_Type::int32_t;
		case DF_Type::viewscreen_locationsst__T_menu: return DF_Type::int32_t;
		case DF_Type::viewscreen_loadgamest__T_cur_step: return DF_Type::int32_t;
		case DF_Type::viewscreen_petst__T_mode: return DF_Type::int32_t;
		case DF_Type::setup_character_info__T_status: return DF_Type::int16_t;
		case DF_Type::setup_character_info__T_page: return DF_Type::int32_t;
		case DF_Type::setup_character_info__T_sel_trait_column: return DF_Type::int8_t;
		case DF_Type::viewscreen_setupadventurest__T_page: return DF_Type::int32_t;
		case DF_Type::viewscreen_setupadventurest__T_status: return DF_Type::int16_t;
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_titlest__T_sel_subpage: return DF_Type::int16_t;
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return DF_Type::int32_t;
		case DF_Type::viewscreen_workshop_profilest__T_tab: return DF_Type::int32_t;
		case DF_Type::unit__T_meeting__T_state: return DF_Type::int8_t;
		case DF_Type::unit__T_counters__T_soldier_mood: return DF_Type::int16_t;
		case DF_Type::world_underground_region__T_type: return DF_Type::int16_t;
		case DF_Type::world_data__T_flip_latitude: return DF_Type::int16_t;
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return DF_Type::int16_t;
		case DF_Type::cultural_identity__T_group_log__T_join_type: return DF_Type::int32_t;
		case DF_Type::world_site_realization__T_areas__T_type: return DF_Type::int32_t;
		case DF_Type::incident__T_type: return DF_Type::int32_t;
		case DF_Type::crime__T_mode: return DF_Type::int32_t;
		case DF_Type::world__T_arena_spawn__T_tame: return DF_Type::int32_t;
		default: break;
	}
	return DF_Type::None;
}
std::pair<int,int> enum_min_max(DF_Type p_enum)
{
	switch(p_enum)
	{
		case DF_Type::ui_advmode_menu: return std::pair<int,int>(0,48);
		case DF_Type::talk_choice_type: return std::pair<int,int>(0,224);
		case DF_Type::assume_identity_mode: return std::pair<int,int>(0,4);
		case DF_Type::announcement_type: return std::pair<int,int>(0,338);
		case DF_Type::art_image_element_type: return std::pair<int,int>(0,4);
		case DF_Type::art_image_property_type: return std::pair<int,int>(0,1);
		case DF_Type::art_image_property_verb: return std::pair<int,int>(0,47);
		case DF_Type::art_facet_type: return std::pair<int,int>(0,3);
		case DF_Type::poetic_form_action: return std::pair<int,int>(-1,22);
		case DF_Type::poetic_form_pattern: return std::pair<int,int>(-1,11);
		case DF_Type::poetic_form_caesura_position: return std::pair<int,int>(-1,2);
		case DF_Type::poetic_form_mood: return std::pair<int,int>(-1,6);
		case DF_Type::poetic_form_subject: return std::pair<int,int>(-1,20);
		case DF_Type::poetic_form_additional_feature: return std::pair<int,int>(0,8);
		case DF_Type::poetic_form_perspective__T_type: return std::pair<int,int>(0,7);
		case DF_Type::musical_form_purpose: return std::pair<int,int>(0,3);
		case DF_Type::musical_form_style: return std::pair<int,int>(-1,72);
		case DF_Type::musical_form_pitch_style: return std::pair<int,int>(-1,4);
		case DF_Type::unk_scale_enum_type: return std::pair<int,int>(0,2);
		case DF_Type::occupation_type: return std::pair<int,int>(0,6);
		case DF_Type::buildings_other_id: return std::pair<int,int>(-1,90);
		case DF_Type::building_type: return std::pair<int,int>(-1,54);
		case DF_Type::civzone_type: return std::pair<int,int>(0,68);
		case DF_Type::furnace_type: return std::pair<int,int>(0,7);
		case DF_Type::workshop_type: return std::pair<int,int>(0,24);
		case DF_Type::construction_type: return std::pair<int,int>(-1,36);
		case DF_Type::shop_type: return std::pair<int,int>(0,3);
		case DF_Type::siegeengine_type: return std::pair<int,int>(0,1);
		case DF_Type::trap_type: return std::pair<int,int>(0,5);
		case DF_Type::dfhack_room_quality_level: return std::pair<int,int>(0,7);
		case DF_Type::creature_raw_flags: return std::pair<int,int>(0,118);
		case DF_Type::caste_raw_flags: return std::pair<int,int>(0,178);
		case DF_Type::body_part_raw_flags: return std::pair<int,int>(0,38);
		case DF_Type::appearance_modifier_type: return std::pair<int,int>(0,23);
		case DF_Type::body_part_layer_flags: return std::pair<int,int>(0,0);
		case DF_Type::appearance_modifier_growth_interval: return std::pair<int,int>(0,3);
		case DF_Type::gait_type: return std::pair<int,int>(0,4);
		case DF_Type::creature_graphics_role: return std::pair<int,int>(0,5);
		case DF_Type::tissue_style_type: return std::pair<int,int>(0,4);
		case DF_Type::body_part_template_flags: return std::pair<int,int>(0,30);
		case DF_Type::body_part_template_contype: return std::pair<int,int>(-1,4);
		case DF_Type::tissue_flags: return std::pair<int,int>(0,21);
		case DF_Type::d_init_nickname: return std::pair<int,int>(0,2);
		case DF_Type::d_init_z_view: return std::pair<int,int>(0,3);
		case DF_Type::d_init_embark_confirm: return std::pair<int,int>(0,2);
		case DF_Type::d_init_idlers: return std::pair<int,int>(-1,1);
		case DF_Type::d_init_tunnel: return std::pair<int,int>(0,2);
		case DF_Type::d_init_flags1: return std::pair<int,int>(0,3);
		case DF_Type::d_init_flags2: return std::pair<int,int>(0,2);
		case DF_Type::d_init_flags3: return std::pair<int,int>(0,0);
		case DF_Type::d_init_flags4: return std::pair<int,int>(0,18);
		case DF_Type::pattern_type: return std::pair<int,int>(0,5);
		case DF_Type::occasion_schedule_type: return std::pair<int,int>(0,14);
		case DF_Type::occasion_schedule_feature: return std::pair<int,int>(0,18);
		case DF_Type::entity_sell_category: return std::pair<int,int>(0,63);
		case DF_Type::historical_entity_type: return std::pair<int,int>(0,10);
		case DF_Type::training_knowledge_level: return std::pair<int,int>(0,5);
		case DF_Type::entity_position_flags: return std::pair<int,int>(0,31);
		case DF_Type::entity_material_category: return std::pair<int,int>(-1,31);
		case DF_Type::entity_event_type: return std::pair<int,int>(0,33);
		case DF_Type::crime_type: return std::pair<int,int>(0,3);
		case DF_Type::agreement_details_type: return std::pair<int,int>(0,15);
		case DF_Type::entity_raw_flags: return std::pair<int,int>(0,73);
		case DF_Type::site_type: return std::pair<int,int>(0,10);
		case DF_Type::ethic_type: return std::pair<int,int>(-1,21);
		case DF_Type::ethic_response: return std::pair<int,int>(0,16);
		case DF_Type::entity_name_type: return std::pair<int,int>(0,17);
		case DF_Type::entity_position_raw_flags: return std::pair<int,int>(0,24);
		case DF_Type::entity_position_responsibility: return std::pair<int,int>(-1,41);
		case DF_Type::weather_type: return std::pair<int,int>(0,2);
		case DF_Type::next_global_id: return std::pair<int,int>(0,40);
		case DF_Type::game_mode: return std::pair<int,int>(0,3);
		case DF_Type::game_type: return std::pair<int,int>(0,11);
		case DF_Type::lever_target_type: return std::pair<int,int>(-1,119);
		case DF_Type::zoom_commands: return std::pair<int,int>(0,4);
		case DF_Type::justification: return std::pair<int,int>(0,4);
		case DF_Type::reputation_type: return std::pair<int,int>(0,31);
		case DF_Type::whereabouts_type: return std::pair<int,int>(-1,5);
		case DF_Type::death_condition_type: return std::pair<int,int>(0,6);
		case DF_Type::plot_role_type: return std::pair<int,int>(-1,21);
		case DF_Type::plot_strategy_type: return std::pair<int,int>(-1,8);
		case DF_Type::histfig_flags: return std::pair<int,int>(0,15);
		case DF_Type::histfig_relationship_type: return std::pair<int,int>(-1,64);
		case DF_Type::vague_relationship_type: return std::pair<int,int>(0,15);
		case DF_Type::identity_type: return std::pair<int,int>(0,5);
		case DF_Type::mental_picture_property_type: return std::pair<int,int>(0,8);
		case DF_Type::mental_picture_element_type: return std::pair<int,int>(0,2);
		case DF_Type::history_event_type: return std::pair<int,int>(0,133);
		case DF_Type::history_event_reason: return std::pair<int,int>(-1,93);
		case DF_Type::architectural_element: return std::pair<int,int>(-1,11);
		case DF_Type::history_event_flags: return std::pair<int,int>(0,0);
		case DF_Type::history_event_war_attacked_sitest__T_unk_1: return std::pair<int,int>(0,2);
		case DF_Type::death_type: return std::pair<int,int>(-1,54);
		case DF_Type::entity_action_type: return std::pair<int,int>(0,1);
		case DF_Type::masterpiece_loss_type: return std::pair<int,int>(0,5);
		case DF_Type::history_event_hist_figure_woundedst__T_injury_type: return std::pair<int,int>(0,4);
		case DF_Type::history_event_simple_battle_subtype: return std::pair<int,int>(0,11);
		case DF_Type::artifact_claim_type: return std::pair<int,int>(0,3);
		case DF_Type::histfig_body_state: return std::pair<int,int>(0,6);
		case DF_Type::history_event_hf_act_on_buildingst__T_action: return std::pair<int,int>(0,2);
		case DF_Type::site_dispute_type: return std::pair<int,int>(0,5);
		case DF_Type::insurrection_outcome: return std::pair<int,int>(0,2);
		case DF_Type::history_event_hf_act_on_artifactst__T_action: return std::pair<int,int>(0,1);
		case DF_Type::tactical_situation: return std::pair<int,int>(0,6);
		case DF_Type::history_event_collection_type: return std::pair<int,int>(0,17);
		case DF_Type::era_type: return std::pair<int,int>(0,12);
		case DF_Type::init_display_flags: return std::pair<int,int>(0,14);
		case DF_Type::init_media_flags: return std::pair<int,int>(0,2);
		case DF_Type::init_input_flags: return std::pair<int,int>(0,1);
		case DF_Type::init_window_flags: return std::pair<int,int>(0,3);
		case DF_Type::interaction_flags: return std::pair<int,int>(0,1);
		case DF_Type::interaction_effect_type: return std::pair<int,int>(0,6);
		case DF_Type::interaction_effect_location_hint: return std::pair<int,int>(0,5);
		case DF_Type::interaction_source_type: return std::pair<int,int>(0,7);
		case DF_Type::interaction_source_usage_hint: return std::pair<int,int>(0,12);
		case DF_Type::interaction_target_type: return std::pair<int,int>(0,3);
		case DF_Type::interaction_target_location_type: return std::pair<int,int>(-1,6);
		case DF_Type::breath_attack_type: return std::pair<int,int>(0,21);
		case DF_Type::item_type: return std::pair<int,int>(-1,90);
		case DF_Type::itemdef_flags: return std::pair<int,int>(0,0);
		case DF_Type::ammo_flags: return std::pair<int,int>(0,0);
		case DF_Type::armor_general_flags: return std::pair<int,int>(0,10);
		case DF_Type::armor_flags: return std::pair<int,int>(0,0);
		case DF_Type::gloves_flags: return std::pair<int,int>(0,0);
		case DF_Type::helm_flags: return std::pair<int,int>(0,0);
		case DF_Type::instrument_flags: return std::pair<int,int>(0,8);
		case DF_Type::sound_production_type: return std::pair<int,int>(0,20);
		case DF_Type::pitch_choice_type: return std::pair<int,int>(0,11);
		case DF_Type::tuning_type: return std::pair<int,int>(0,4);
		case DF_Type::timbre_type: return std::pair<int,int>(0,62);
		case DF_Type::pants_flags: return std::pair<int,int>(0,0);
		case DF_Type::shoes_flags: return std::pair<int,int>(0,0);
		case DF_Type::tool_flags: return std::pair<int,int>(0,19);
		case DF_Type::tool_uses: return std::pair<int,int>(-1,25);
		case DF_Type::toy_flags: return std::pair<int,int>(0,0);
		case DF_Type::trapcomp_flags: return std::pair<int,int>(0,4);
		case DF_Type::weapon_flags: return std::pair<int,int>(0,2);
		case DF_Type::items_other_id: return std::pair<int,int>(-1,132);
		case DF_Type::job_item_vector_id: return std::pair<int,int>(0,132);
		case DF_Type::improvement_type: return std::pair<int,int>(0,12);
		case DF_Type::itemimprovement_specific_type: return std::pair<int,int>(0,1);
		case DF_Type::written_content_type: return std::pair<int,int>(0,25);
		case DF_Type::written_content_style: return std::pair<int,int>(0,17);
		case DF_Type::item_magicness_type: return std::pair<int,int>(0,8);
		case DF_Type::item_quality: return std::pair<int,int>(0,6);
		case DF_Type::slab_engraving_type: return std::pair<int,int>(-1,26);
		case DF_Type::corpse_material_type: return std::pair<int,int>(0,11);
		case DF_Type::job_type_class: return std::pair<int,int>(0,15);
		case DF_Type::job_type: return std::pair<int,int>(-1,240);
		case DF_Type::job_subtype_surgery: return std::pair<int,int>(0,3);
		case DF_Type::job_art_specification__T_type: return std::pair<int,int>(-1,3);
		case DF_Type::manager_order_condition_order__T_condition: return std::pair<int,int>(0,1);
		case DF_Type::guild_id: return std::pair<int,int>(-1,5);
		case DF_Type::interface_key: return std::pair<int,int>(0,1614);
		case DF_Type::dfhack_knowledge_scholar_flag: return std::pair<int,int>(0,445);
		case DF_Type::part_of_speech: return std::pair<int,int>(0,8);
		case DF_Type::sphere_type: return std::pair<int,int>(-1,129);
		case DF_Type::language_name_category: return std::pair<int,int>(0,66);
		case DF_Type::nemesis_flags: return std::pair<int,int>(0,2);
		case DF_Type::machine_type: return std::pair<int,int>(0,0);
		case DF_Type::screw_pump_direction: return std::pair<int,int>(0,3);
		case DF_Type::tile_traffic: return std::pair<int,int>(0,3);
		case DF_Type::tile_dig_designation: return std::pair<int,int>(0,6);
		case DF_Type::tile_liquid: return std::pair<int,int>(0,1);
		case DF_Type::tile_building_occ: return std::pair<int,int>(0,7);
		case DF_Type::tile_liquid_flow_dir: return std::pair<int,int>(0,15);
		case DF_Type::block_square_event_type: return std::pair<int,int>(0,7);
		case DF_Type::feature_type: return std::pair<int,int>(0,9);
		case DF_Type::feature_init_flags: return std::pair<int,int>(0,3);
		case DF_Type::layer_type: return std::pair<int,int>(-1,4);
		case DF_Type::feature_alteration_type: return std::pair<int,int>(0,1);
		case DF_Type::world_construction_type: return std::pair<int,int>(0,3);
		case DF_Type::biome_type: return std::pair<int,int>(0,50);
		case DF_Type::flow_type: return std::pair<int,int>(0,13);
		case DF_Type::flow_guide_type: return std::pair<int,int>(0,1);
		case DF_Type::region_block_event_type: return std::pair<int,int>(0,0);
		case DF_Type::craft_material_class: return std::pair<int,int>(-1,11);
		case DF_Type::builtin_mats: return std::pair<int,int>(0,18);
		case DF_Type::material_flags: return std::pair<int,int>(0,74);
		case DF_Type::matter_state: return std::pair<int,int>(-1,5);
		case DF_Type::strain_type: return std::pair<int,int>(0,5);
		case DF_Type::inorganic_flags: return std::pair<int,int>(0,31);
		case DF_Type::environment_type: return std::pair<int,int>(0,7);
		case DF_Type::inclusion_type: return std::pair<int,int>(0,4);
		case DF_Type::organic_mat_category: return std::pair<int,int>(0,36);
		case DF_Type::meeting_topic: return std::pair<int,int>(0,9);
		case DF_Type::meeting_event_type: return std::pair<int,int>(0,5);
		case DF_Type::activity_entry_type: return std::pair<int,int>(0,12);
		case DF_Type::activity_event_type: return std::pair<int,int>(0,27);
		case DF_Type::conversation_menu: return std::pair<int,int>(-1,70);
		case DF_Type::performance_event_type: return std::pair<int,int>(0,3);
		case DF_Type::performance_participant_type: return std::pair<int,int>(0,5);
		case DF_Type::uniform_category: return std::pair<int,int>(0,6);
		case DF_Type::barrack_preference_category: return std::pair<int,int>(0,3);
		case DF_Type::squad_event_type: return std::pair<int,int>(-1,2);
		case DF_Type::squad_order_type: return std::pair<int,int>(0,11);
		case DF_Type::squad_order_cannot_reason: return std::pair<int,int>(0,16);
		case DF_Type::army_flags: return std::pair<int,int>(0,0);
		case DF_Type::unit_path_goal: return std::pair<int,int>(-1,203);
		case DF_Type::unit_station_type: return std::pair<int,int>(-1,41);
		case DF_Type::plant_raw_flags: return std::pair<int,int>(0,87);
		case DF_Type::projectile_type: return std::pair<int,int>(0,2);
		case DF_Type::reaction_flags: return std::pair<int,int>(0,2);
		case DF_Type::reaction_reagent_type: return std::pair<int,int>(0,0);
		case DF_Type::reaction_product_type: return std::pair<int,int>(0,1);
		case DF_Type::reaction_product_item_flags: return std::pair<int,int>(0,5);
		case DF_Type::reaction_product_improvement_flags: return std::pair<int,int>(0,2);
		case DF_Type::general_ref_type: return std::pair<int,int>(0,69);
		case DF_Type::specific_ref_type: return std::pair<int,int>(-1,30);
		case DF_Type::histfig_entity_link_type: return std::pair<int,int>(0,16);
		case DF_Type::histfig_site_link_type: return std::pair<int,int>(0,9);
		case DF_Type::histfig_hf_link_type: return std::pair<int,int>(0,15);
		case DF_Type::entity_entity_link_type: return std::pair<int,int>(0,2);
		case DF_Type::entity_site_link_type: return std::pair<int,int>(-1,4);
		case DF_Type::resource_allotment_specifier_type: return std::pair<int,int>(0,43);
		case DF_Type::profession: return std::pair<int,int>(-1,134);
		case DF_Type::unit_labor_category: return std::pair<int,int>(-13,-1);
		case DF_Type::unit_labor: return std::pair<int,int>(-1,82);
		case DF_Type::job_skill_class: return std::pair<int,int>(0,9);
		case DF_Type::job_skill: return std::pair<int,int>(-1,136);
		case DF_Type::hauler_type: return std::pair<int,int>(0,9);
		case DF_Type::furniture_type: return std::pair<int,int>(0,32);
		case DF_Type::stockpile_category: return std::pair<int,int>(-1,18);
		case DF_Type::stockpile_list: return std::pair<int,int>(0,104);
		case DF_Type::creature_interaction_effect_type: return std::pair<int,int>(0,35);
		case DF_Type::creature_interaction_effect_target_mode: return std::pair<int,int>(0,2);
		case DF_Type::tiletype_shape_basic: return std::pair<int,int>(-1,4);
		case DF_Type::tiletype_shape: return std::pair<int,int>(-1,18);
		case DF_Type::tiletype_material: return std::pair<int,int>(-1,25);
		case DF_Type::tiletype_variant: return std::pair<int,int>(-1,3);
		case DF_Type::tiletype_special: return std::pair<int,int>(-1,11);
		case DF_Type::tiletype: return std::pair<int,int>(0,694);
		case DF_Type::build_req_choice_type: return std::pair<int,int>(0,1);
		case DF_Type::ui_hotkey__T_cmd: return std::pair<int,int>(-1,2);
		case DF_Type::ui_sidebar_mode: return std::pair<int,int>(0,56);
		case DF_Type::kitchen_exc_type: return std::pair<int,int>(1,2);
		case DF_Type::timed_event_type: return std::pair<int,int>(0,8);
		case DF_Type::emotion_type: return std::pair<int,int>(-1,169);
		case DF_Type::unit_thought_type: return std::pair<int,int>(-1,265);
		case DF_Type::value_type: return std::pair<int,int>(-1,32);
		case DF_Type::goal_type: return std::pair<int,int>(0,14);
		case DF_Type::personality_facet_type: return std::pair<int,int>(-1,49);
		case DF_Type::physical_attribute_type: return std::pair<int,int>(0,5);
		case DF_Type::mental_attribute_type: return std::pair<int,int>(0,12);
		case DF_Type::mood_type: return std::pair<int,int>(-1,9);
		case DF_Type::ghost_type: return std::pair<int,int>(-1,10);
		case DF_Type::animal_training_level: return std::pair<int,int>(0,9);
		case DF_Type::unit_report_type: return std::pair<int,int>(0,2);
		case DF_Type::skill_rating: return std::pair<int,int>(0,20);
		case DF_Type::unit_relationship_type: return std::pair<int,int>(-1,47);
		case DF_Type::need_type: return std::pair<int,int>(0,29);
		case DF_Type::ghost_goal: return std::pair<int,int>(-1,7);
		case DF_Type::wound_effect_type: return std::pair<int,int>(0,9);
		case DF_Type::misc_trait_type: return std::pair<int,int>(0,68);
		case DF_Type::unit_action_type: return std::pair<int,int>(-1,19);
		case DF_Type::interface_breakdown_types: return std::pair<int,int>(0,3);
		case DF_Type::embark_finder_option: return std::pair<int,int>(0,22);
		case DF_Type::export_map_type: return std::pair<int,int>(-3,16);
		case DF_Type::viewscreen_image_creator_mode: return std::pair<int,int>(-1,18);
		case DF_Type::viewscreen_kitchenpref_page: return std::pair<int,int>(0,3);
		case DF_Type::adventurer_attribute_level: return std::pair<int,int>(0,6);
		case DF_Type::viewscreen_unitlist_page: return std::pair<int,int>(0,3);
		case DF_Type::world_population_type: return std::pair<int,int>(0,7);
		case DF_Type::world_region_type: return std::pair<int,int>(0,9);
		case DF_Type::geo_layer_type: return std::pair<int,int>(0,8);
		case DF_Type::region_map_entry_flags: return std::pair<int,int>(0,23);
		case DF_Type::front_type: return std::pair<int,int>(0,3);
		case DF_Type::cumulus_type: return std::pair<int,int>(0,3);
		case DF_Type::stratus_type: return std::pair<int,int>(0,3);
		case DF_Type::fog_type: return std::pair<int,int>(0,3);
		case DF_Type::mountain_peak_flags: return std::pair<int,int>(0,0);
		case DF_Type::abstract_building_type: return std::pair<int,int>(0,12);
		case DF_Type::abstract_building_flags: return std::pair<int,int>(0,7);
		case DF_Type::temple_deity_type: return std::pair<int,int>(-1,1);
		case DF_Type::world_site_type: return std::pair<int,int>(0,10);
		case DF_Type::world_site_flags: return std::pair<int,int>(0,9);
		case DF_Type::fortress_type: return std::pair<int,int>(-1,3);
		case DF_Type::monument_type: return std::pair<int,int>(-1,1);
		case DF_Type::lair_type: return std::pair<int,int>(-1,4);
		case DF_Type::site_realization_building_type: return std::pair<int,int>(0,31);
		case DF_Type::site_shop_type: return std::pair<int,int>(0,25);
		case DF_Type::tree_house_type: return std::pair<int,int>(0,5);
		case DF_Type::hillock_house_type: return std::pair<int,int>(0,3);
		case DF_Type::creation_zone_pwg_alteration_type: return std::pair<int,int>(0,3);
		case DF_Type::worldgen_region_type: return std::pair<int,int>(0,9);
		case DF_Type::worldgen_range_type: return std::pair<int,int>(0,23);
		case DF_Type::units_other_id: return std::pair<int,int>(0,1);
		case DF_Type::conflict_level: return std::pair<int,int>(-1,6);
		case DF_Type::combat_report_event_type: return std::pair<int,int>(0,34);
		case DF_Type::conversation__T_state: return std::pair<int,int>(0,3);
		case DF_Type::building_archerytargetst__T_archery_direction: return std::pair<int,int>(0,3);
		case DF_Type::building_bridgest__T_direction: return std::pair<int,int>(-1,3);
		case DF_Type::building_siegeenginest__T_facing: return std::pair<int,int>(0,3);
		case DF_Type::building_siegeenginest__T_action: return std::pair<int,int>(0,2);
		case DF_Type::caste_body_info__T_interactions__T_type: return std::pair<int,int>(0,2);
		case DF_Type::caravan_state__T_trade_state: return std::pair<int,int>(0,4);
		case DF_Type::entity_event__T_data__T_insurrection_end__T_result: return std::pair<int,int>(0,2);
		case DF_Type::history_event_change_hf_statest__T_state: return std::pair<int,int>(0,5);
		case DF_Type::history_event_body_abusedst__T_abuse_data__T_Piled__T_pile_type: return std::pair<int,int>(0,2);
		case DF_Type::history_event_body_abusedst__T_abuse_type: return std::pair<int,int>(0,5);
		case DF_Type::history_event_hist_figure_travelst__T_reason: return std::pair<int,int>(0,2);
		case DF_Type::init_display__T_windowed: return std::pair<int,int>(0,2);
		case DF_Type::init_font__T_use_ttf: return std::pair<int,int>(0,2);
		case DF_Type::job_item_ref__T_role: return std::pair<int,int>(0,8);
		case DF_Type::manager_order__T_frequency: return std::pair<int,int>(0,4);
		case DF_Type::manager_order_condition_item__T_compare_type: return std::pair<int,int>(0,5);
		case DF_Type::mandate__T_mode: return std::pair<int,int>(0,2);
		case DF_Type::unit_demand__T_place: return std::pair<int,int>(0,3);
		case DF_Type::knowledge_scholar_category_flag__T_flag_type: return std::pair<int,int>(0,13);
		case DF_Type::ui_advmode__T_conversation__T_targets__T_type: return std::pair<int,int>(0,4);
		case DF_Type::ui_advmode__T_travel_right_map: return std::pair<int,int>(0,2);
		case DF_Type::ui_advmode__T_show_menu: return std::pair<int,int>(-1,3);
		case DF_Type::history_event_collection_battlest__T_attacker_merc_type: return std::pair<int,int>(0,2);
		case DF_Type::army_controller__T_type: return std::pair<int,int>(0,24);
		case DF_Type::stop_depart_condition__T_direction: return std::pair<int,int>(0,3);
		case DF_Type::stop_depart_condition__T_mode: return std::pair<int,int>(0,2);
		case DF_Type::interface_button_construction_category_selectorst__T_category_id: return std::pair<int,int>(1,7);
		case DF_Type::ui_sidebar_menus__T_designation__T_mine_mode: return std::pair<int,int>(0,3);
		case DF_Type::ui_sidebar_menus__T_zone__T_mode: return std::pair<int,int>(0,2);
		case DF_Type::ui_sidebar_menus__T_unit__T_expel_error: return std::pair<int,int>(-1,10);
		case DF_Type::ui_look_list__T_items__T_type: return std::pair<int,int>(0,12);
		case DF_Type::ui_unit_view_mode__T_value: return std::pair<int,int>(0,6);
		case DF_Type::unit_inventory_item__T_mode: return std::pair<int,int>(0,10);
		case DF_Type::historical_figure_info__T_relationships__T_intrigues__T_plots__T_plot_type: return std::pair<int,int>(-1,15);
		case DF_Type::unit_action_data_attack__T_unk_4__T_wrestle_type: return std::pair<int,int>(0,1);
		case DF_Type::unit_preference__T_type: return std::pair<int,int>(0,11);
		case DF_Type::unit_complaint__T_type: return std::pair<int,int>(25,48);
		case DF_Type::unit_request__T_type: return std::pair<int,int>(0,0);
		case DF_Type::KeybindingScreen__T_mode: return std::pair<int,int>(0,4);
		case DF_Type::viewscreen_adventure_logst__T_mode: return std::pair<int,int>(0,1);
		case DF_Type::viewscreen_adventure_logst__T_info_mode: return std::pair<int,int>(0,6);
		case DF_Type::viewscreen_assign_display_itemst__T_sel_column: return std::pair<int,int>(0,1);
		case DF_Type::viewscreen_choose_start_sitest__T_finder__T_finder_state: return std::pair<int,int>(-1,3);
		case DF_Type::viewscreen_choose_start_sitest__T_page: return std::pair<int,int>(0,8);
		case DF_Type::mission__T_details__T_raid__T_raid_type: return std::pair<int,int>(0,6);
		case DF_Type::mission__T_type: return std::pair<int,int>(2,19);
		case DF_Type::viewscreen_civlistst__T_rumors__T_type: return std::pair<int,int>(0,28);
		case DF_Type::viewscreen_civlistst__T_page: return std::pair<int,int>(0,8);
		case DF_Type::viewscreen_game_cleanerst__T_state: return std::pair<int,int>(0,2);
		case DF_Type::viewscreen_justicest__T_cur_column: return std::pair<int,int>(0,3);
		case DF_Type::assign_trade_status__T_status: return std::pair<int,int>(-2,3);
		case DF_Type::viewscreen_layer_choose_language_namest__T_current_component: return std::pair<int,int>(0,6);
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_mode: return std::pair<int,int>(0,2);
		case DF_Type::viewscreen_layer_militaryst__T_equip__T_edit_mode: return std::pair<int,int>(0,15);
		case DF_Type::viewscreen_layer_militaryst__T_page: return std::pair<int,int>(0,5);
		case DF_Type::viewscreen_layer_noblelistst__T_mode: return std::pair<int,int>(0,2);
		case DF_Type::viewscreen_legendsst__T_cur_page: return std::pair<int,int>(0,11);
		case DF_Type::viewscreen_locationsst__T_in_edit: return std::pair<int,int>(0,4);
		case DF_Type::viewscreen_locationsst__T_menu: return std::pair<int,int>(0,2);
		case DF_Type::viewscreen_loadgamest__T_cur_step: return std::pair<int,int>(0,48);
		case DF_Type::viewscreen_petst__T_mode: return std::pair<int,int>(0,2);
		case DF_Type::setup_character_info__T_status: return std::pair<int,int>(0,2);
		case DF_Type::setup_character_info__T_page: return std::pair<int,int>(5,10);
		case DF_Type::setup_character_info__T_sel_trait_column: return std::pair<int,int>(0,1);
		case DF_Type::viewscreen_setupadventurest__T_page: return std::pair<int,int>(0,9);
		case DF_Type::viewscreen_setupadventurest__T_status: return std::pair<int,int>(0,2);
		case DF_Type::viewscreen_setupdwarfgamest__T_mode: return std::pair<int,int>(0,1);
		case DF_Type::viewscreen_titlest__T_sel_subpage: return std::pair<int,int>(0,4);
		case DF_Type::viewscreen_workquota_conditionst__T_mode: return std::pair<int,int>(-1,2);
		case DF_Type::viewscreen_workshop_profilest__T_tab: return std::pair<int,int>(0,2);
		case DF_Type::unit__T_meeting__T_state: return std::pair<int,int>(0,3);
		case DF_Type::unit__T_counters__T_soldier_mood: return std::pair<int,int>(-1,4);
		case DF_Type::world_underground_region__T_type: return std::pair<int,int>(0,2);
		case DF_Type::world_data__T_flip_latitude: return std::pair<int,int>(-1,2);
		case DF_Type::abstract_building_dungeonst__T_dungeon_type: return std::pair<int,int>(0,2);
		case DF_Type::cultural_identity__T_group_log__T_join_type: return std::pair<int,int>(0,2);
		case DF_Type::world_site_realization__T_areas__T_type: return std::pair<int,int>(0,8);
		case DF_Type::incident__T_type: return std::pair<int,int>(0,10);
		case DF_Type::crime__T_mode: return std::pair<int,int>(0,18);
		case DF_Type::world__T_arena_spawn__T_tame: return std::pair<int,int>(0,1);
		default: break;
	}
	return std::pair<int,int>(-9999,+9999);
}

