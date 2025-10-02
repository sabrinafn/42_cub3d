<h1>cub3D</h1>

<p><strong>cub3D</strong> was part of the 42 school curriculum and marked our first real dive into 3D rendering using raycasting, inspired by the classic Wolfenstein 3D. 
The goal was to create a basic game where the player moves through a 2D map and experiences a simulated 3D perspective. This project was developed by <a href="https://github.com/marcelagonzaga" target="_blank">Marcela Gonzaga</a> and me.</p>

<h2>Repository Structure</h2>
<pre>
.
├── Dockerfile
├── docker-compose.yml
├── Makefile
├── README.md
└── app/ # cub3D project
</pre>

<h2>Makefile Commands</h2>
<ul>
    <li><code>make build</code> - build the Docker image.</li>
    <li><code>make run</code> - start the container in the background.</li>
    <li><code>make map MAP=map_filename</code> - run the game with a specific map (maps are in <code>app/assets/maps_valid</code> or <code>app/assets/maps_invalid</code>).</li>
    <li><code>make clean</code> - stop the container and remove images/volumes.</li>
    <li><code>make help</code> - show this help message.</li>
</ul>

<h2>Available Maps</h2>

<h3>Valid Maps</h3>
<ul>
    <li>brick_wall.cub</li>
    <li>cat_wall.cub</li>
    <li>eyes.cub</li>
    <li>horror.cub</li>
    <li>meme_cat.cub</li>
    <li>wood_wall.cub</li>
    <li>wood_wall2.cub</li>
</ul>

<h3>Invalid Maps</h3>
<ul>
    <li>02-wrong_file_ext.cbb</li>
    <li>04a-empty_file.cub</li>
    <li>04b-extra_element.cub</li>
    <li>04c-missing_element.cub</li>
    <li>04d-only_map.cub</li>
    <li>05-incomplete_map.cub</li>
    <li>06a-unidentified_content.cub</li>
    <li>06b-wrong_map_content.cub</li>
    <li>06c-wrong_map_content.cub</li>
    <li>06d-invalid_inner_wall.cub</li>
    <li>07a-element_after_map.cub</li>
    <li>07b-map_after_map.cub</li>
    <li>08a-wrong_texture_content.cub</li>
    <li>08b-not_found_texture.cub</li>
    <li>09-wrong_color_content.cub</li>
    <li>10a-two_players.cub</li>
    <li>10b-missing_player.cub</li>
    <li>10c-double_player.cub</li>
    <li>11a-open_wall_left.cub</li>
    <li>11b-open_wall_right.cub</li>
    <li>11c-open_wall_down.cub</li>
    <li>11d-open_wall.cub</li>
</ul>

<h2>Example Workflow</h2>
<ol>
    <li>Build the Docker image (only once):
        <pre><code>make build</code></pre>
    </li>
    <li>Start the container in the background (only once):
        <pre><code>make run</code></pre>
    </li>
    <li>Run the game with a specific map:
        <pre><code>make map MAP=brick_wall</code></pre>
    </li>
</ol>

<h2>Notes</h2>
<ul>
    <li>You can run any valid map by changing the <code>MAP</code> variable.</li>
    <li>Initial delay may occur on first run due to container startup and MiniLibX initialization.</li>
    <li>Ensure your Docker environment has access to X11 to display the graphical window.</li>
</ul>

</body>
</html>
