<?php
/**
 * @file
 * Displays the search bar for a Newspaper
 * Finds the #pids of the newspaper pages which got hit by the searched string
 */
/**
 * Implements hook_form().
 */
function islandora_newspaper_search_inside_form($form, &$form_state){
    $form['newspaper_search'] = array(
      '#title' => t('Search inside the Newspaper'),
      '#type' => 'textfield',
      '#description' => t('Search only for a single string'),
    );
      $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Find the string in the Newspaper'),
    );
  return $form;
}

/**
 * Implements hook_form_submit().
 */
function islandora_newspaper_search_inside_form_submit($form, &$form_state){
  //some fn to search for string in ocr
  if($form_state['input']['newspaper_search'] != NULL) {
    $path_arr = explode('/', current_path());
    $parent = $path_arr[2];
    $pids = islandora_newspaper_search_inside_search($parent);
    $results = array();
    foreach($pids as $key => $value) {
      $obj = islandora_object_load($value);
      if (isset($obj['OCR'])) {
        if(strpos($obj['OCR']->content, $form_state['input']['newspaper_search']) != FALSE ){
          $results[] = $value;
          }
        }
      }
      if(count($results) > 0) {
        $options = array('query' => array());
        foreach($results as $result) {
          $options['query'][] = $result;
        }
        $options['query'][] = $form_state['input']['newspaper_search'];
      drupal_goto('newspaper/search/results-tpl', $options);
    }
    else {
      drupal_set_message('Sorry, but your search returned no results.');
    }
  }
  else {
    drupal_set_message('Cannot search an empty string', 'error');
  }
}
