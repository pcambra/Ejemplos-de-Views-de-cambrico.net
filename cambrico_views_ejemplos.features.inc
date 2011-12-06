<?php
/**
 * @file
 * cambrico_views_ejemplos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cambrico_views_ejemplos_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cambrico_views_ejemplos_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cambrico_views_ejemplos_image_default_styles() {
  $styles = array();

  // Exported image style: article
  $styles['article'] = array(
    'name' => 'article',
    'effects' => array(
      4 => array(
        'label' => 'Escalar y recortar',
        'help' => 'Escalar y recortar mantendrán la relación de proporciones de la imagen original y se desechará lo que sobre por el lado mayor. Esto es especialmente útil para crear miniaturas perfectamente cuadradas sin deformar la imagen.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '600',
          'height' => '200',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cambrico_views_ejemplos_node_info() {
  $items = array(
    'lugar' => array(
      'name' => t('Lugar'),
      'base' => 'node_content',
      'description' => t('Registro de todos los lugares con información relacionada'),
      'has_title' => '1',
      'title_label' => t('Nombre'),
      'help' => '',
    ),
  );
  return $items;
}
