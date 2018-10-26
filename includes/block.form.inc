<?php

function islandora_newspaper_search_inside_form($form, &$form_state){
  $path_arr = explode('/', current_path());
  $obj = islandora_object_load($path_arr[2]);
  if (in_array('islandora:newspaperCModel', $obj->models)) {
    $form['newspaper_search'] = array(
      '#title' => t('Search inside this newspaper'),
      '#type' => 'textfield',
    );
      $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Find the string in the newspaper'),
    );
  }

  // if(current_path() == 'islandora/object'){
  //   dpm('form');
  //   }
  //are we on a n object page?
  //is it a newspaper parent?
  //then add this form
  return $form;
}
//search fn
// load all child ORC/HORC datastreams and their content for the search.
// str_pos
//$obj = islandora_object_load($pid);
//find the children RIsearch?
//load all the children
// $obj['OCR']->content || $obj['HOCR']->content
//strpos($hay, $needle)


function islandora_newspaper_search_inside_form_submit($form, &$form_state){
  //some fn to search for string in ocr
  $path_arr = explode('/', current_path());
  $parent = $path_arr[2];
  $pids = islandora_newspaper_search_inside_search($parent);
  foreach($pids as $key => $value) {
    $obj = islandora_object_load($value);
    if (isset($obj['OCR'])) {
      if(strpos($obj['OCR']->content, $form_state['input']['newspaper_search']) != FALSE ){
        dpm('hit');
      }
    }
  }
}
