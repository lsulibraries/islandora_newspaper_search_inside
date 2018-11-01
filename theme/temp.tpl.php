<?php
//comments...
?>

<div class='isandora_solr_search_results'>
    <div class='islandora_solr_search_result_inner'>
      <?php print "You have searched for the string"?> <?php print $variables['search']?> <?php echo "<br>" ?>
      <?php print $variables['n']?> <?php print "results found in OCR Datastream"?>
    </div>
</div>
<?php foreach ($pids as $pid) : ?>
  <div class='isandora_solr_search_results'>
    <div class = 'islandora-solr-search-result clear-block even'>
      <div class='islandora_solr_search_result_inner'>
        <?php $path = $variables[$pid]['path']?>
        <?php $label = $variables[$pid]['label']?>
        <?php $ocr_view = $variables[$pid]['ocr_view']?>
        <?php $tn_link = $variables[$pid]['tn_link']?>
        <?php print "<a href= '$path' > $label</a>" ?> <?php echo "&nbsp&nbsp&nbsp&nbsp" ?>
        <?php print "<a href='$ocr_view'>View OCR</a>" ?> <?php echo "<br>" ?>
        <dl calss = "solr-thumb">
          <dt>
          <?php print "<a href='$path'><img src='$tn_link' alt='$label'></img></a>" ?>
        </dt>
        </dl>
          <dl class = 'solr-fields islandora-inline-metadata'>
            <dt class="solr-label dc-title"><?php $label ?> </dt>
            <dd class="solr-value dc-title">
              <?php print "<a href= '$path'>$label</a>" ?>
          </dd>
        </dl>
      </div>
    </div>
  </div>
<?php endforeach; ?>
