*** Begin Patch
*** Update File: Client/Ui/TitleScreen/Squad.c
@@
             proto_bug_write_uint8(&encoder2, rr_serverbound_squad_join,
                                   "header");
-            proto_bug_write_uint8(&encoder2, 2, "join type");
+            proto_bug_write_uint8(&encoder2, 2, "join type");
+            /* send chosen biome for the squad */
+            proto_bug_write_uint8(&encoder2, game->selected_biome, "biome");
*** End Patch
