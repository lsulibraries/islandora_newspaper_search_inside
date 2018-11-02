<?php
//comments...
?>
<div class = "islandora-solr-content">
  <div class = "islandora_solr_search_results">
    <?php echo "<br>" ?><?php print "You have searched for the string"?> <?php print $variables['search']?><?php echo "<br>" ?>
    <?php print $variables['n']?> <?php print "results found in OCR Datastream"?><?php echo "<br>" ?>
    <?php foreach ($pids as $pid) : ?>
    <?php $path = $variables[$pid]['path']?>
    <?php $label = $variables[$pid]['label']?>
    <?php $ocr_view = $variables[$pid]['ocr_view']?>
    <?php $tn_link = $variables[$pid]['tn_link']?>
    <div class = "islandora-solr-search-result clear-block odd">
      <div class = "islandora-solr-search-result-inner">
        <dl class = "solr-thumb">
          <dt>
            <?php print "<a href='$path'><img src='$tn_link' alt='$label'></img></a>"?>
          </dt>
        </dl>
        <dl class = "solr-fields islandora-inline-metadata">
          <dt class="solr-label dc-title">
            <?php $label?>
          </dt>
          <dd class="solr-value dc-title">
            <?php print "<a href= '$path'>$label</a>"?><?php echo "&nbsp&nbsp&nbsp&nbsp&nbsp"?>
            <?php print "<a href='$ocr_view'>View OCR</a>"?>
          </dd>
        </dl>
      </div>
    </div>
    <?php endforeach; ?>
  </div>
</div>
