<?php

function islandora_newspaper_search_inside_results_form($form, &$form_state) {
  $params = drupal_get_query_parameters();
  foreach ($params as $pid) {
    $obj = islandora_object_load($pid);
    $path = '/islandora/object/' . $obj->id;
    $tn_link = '/islandora/object/' . $obj->id . '/datastream/TN/view';
    $path_link = "<a href='$path'><img src='$tn_link' alt='$obj->label'></img></a>";
    $form[$obj->id] = array(
      '#type' => 'markup',
      '#markup' => "<div class='isandora_solr_search_result'>
                      <div class='islandora_solr_search_result_inner'>
                        <div>$obj->label</div>
                        <div>$path_link</div>
                      </div>
                    </div>",
    );
  }
  return $form;
}
