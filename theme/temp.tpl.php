<?php
//comments...
?>
<div class = "islandora_solr_search_results">
  <?php $row_result = 0; ?>
  <?php print "You have searched for the string "?><?php print $variables['search']?><?php echo ",&nbsp" ?>
  <?php print $variables['n']?><?php print " results found in the OCR Datastream"?><?php echo "<br><br>"?>
  <?php foreach ($issues as $issue) : ?>
    <?php $path = $issue['path']?>
    <?php $label = $issue['label']?>
    <?php $tn_link = $issue['tn_link']?>
    <div class="islandora-solr-search-result clear-block <?php print $row_result % 2 == 0 ? 'odd' : 'even'; ?>">
      <div class = "islandora-solr-search-result-inner">
        <dl class = "solr-thumb">
          <dt>
            <?php print "<a href='$path'><img src='$tn_link' alt='$label'></img></a>"?>
          </dt>
        </dl>
        <dl class = "solr-fields islandora-inline-metadata">
          <dt class="solr-label dc-title">
            <?php print $label;?>
          </dt>
          <dd class="solr-value dc-title">
            <?php print "<a href= '$path'>$label</a>"?><?php print "------>"?>
          </dd>
        </dl>
      </div>
    </div>
    <?php $row_result++; ?>
  <?php endforeach; ?>
</div>
