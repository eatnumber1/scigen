// therules.cc: keeping these rules separate, for convenience.
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////

#include "generate.h"
#include "grammar.h"
#include "therules.h"

void load_grammar ()
{
        //
        // literature paper - Book
        //
	// TOPIC = the book
	// LIT_BOOK = </i>TOPIC</i>
	// LASTNAME = author's last name
	// FIRSTNAME = author's first name        

	load_easy ("LIT_BOOK", "<i> TOPIC </i>");

        load_easy ("LITPAPER_SHORT", "<p> LIT_PARAGRAPH_A <p> LIT_PARAGRAPH_MIDDLE <p> LIT_PARAGRAPH_C");
        load_easy ("LITPAPER_LONG", "<p> LIT_PARAGRAPH_A <p> LIT_PARAGRAPH_BODY1 <p> LIT_PARAGRAPH_BODY1 <p> LIT_PARAGRAPH_BODY2 <p> LIT_PARAGRAPH_BODY2 <p> LIT_PARAGRAPH_C");
	
	load_easy ("LIT_PARAGRAPH_BODY1", "LIT_MIDDLE_ONE LIT_PARAGRAPH_B <p> LIT_PARAGRAPH_B <p> LIT_BLOCKQUOTE <p> LIT_PARAGRAPH_B <p> LIT_PARAGRAPH_B <p> "); 


	load_easy ("LIT_PARAGRAPH_BODY2", "LIT_PARAGRAPH_B <p> LIT_PARAGRAPH_B <p> LIT_BLOCKQUOTE <p> LIT_PARAGRAPH_B <p> LIT_MIDDLE_THREE LIT_PARAGRAPH_B <p>"); 

	load_easy ("LIT_BLOCKQUOTE", "<blockquote><blockquote><font size=1 face=verdana> LIT_BLOCKQUOTE_BODY ( LASTNAME HIST_QUOTE_PAGE ) </font></blockquote></blockquote> LIT_BLOCKQUOTE_RESPONSE ");

	load_easy ("LIT_BLOCKQUOTE_RESPONSE", "LIT_QUOTE_COMMENT_UNPUNC ; LIT_QUOTE_TRANS LIT_QUOTE_COMMENT");

	load_easy ("LIT_QUOTE_TRANS", "still, ");
	load_easy ("LIT_QUOTE_TRANS", "");

	load_easy ("LIT_BLOCKQUOTE_BODY", "LIT_QUOTEA . LIT_QUOTEA . LIT_QUOTEA . LIT_QUOTEA . LIT_QUOTEA . LIT_QUOTEA .");

        load_easy ("LITPAPER_TITLE", "<font size=3> TOPIC : LIT_SUBTITLE </font><br><font size=3><i>By USER_NAME </i></font>");
        load_easy ("LIT_PARAGRAPH_A", "LIT_A_ONE LIT_A_TWO LIT_A_THREE");

	load_easy ("LIT_PARAGRAPH_MIDDLE", "LIT_MIDDLE_ONE LIT_PARAGRAPH_B <p> LIT_MIDDLE_TWO LIT_PARAGRAPH_B <p> LIT_MIDDLE_THREE LIT_PARAGRAPH_B");
      
	load_easy ("LIT_PARAGRAPH_B", "LIT_B_ONE LIT_B_TWO LIT_B_CONCLUDE");
        load_easy ("LIT_PARAGRAPH_C", "LIT_C_ONE LIT_C_TWO LIT_C_THREE LIT_C_FOUR");
                
	load_easy ("LIT_SUBTITLE", "LIT_THEMES_A and LIT_THEMES_B");
	load_easy ("LIT_SUBTITLE", "LIT_THEMES_A and LIT_THEMES_C");
	load_easy ("LIT_SUBTITLE", "LIT_THEMES_B and LIT_THEMES_C");
	load_easy ("LIT_SUBTITLE", "a LIT_MOVEMENTA LIT_TITLE_NOUN ");
	load_easy ("LIT_SUBTITLE", "a LIT_MOVEMENTA LIT_TITLE_NOUN ");
	load_easy ("LIT_SUBTITLE", "LIT_THEMES_B , LIT_THEMES_C , and LIT_THEMES_A");
	load_easy ("LIT_SUBTITLE", "LASTNAME and the use of LIT_THEMES");

	load_easy ("LIT_ADJ_50", "LIT_ADJ");
	load_easy ("LIT_ADJ_50", "");

	load_easy ("LIT_TITLE_NOUN", "exploration");
	load_easy ("LIT_TITLE_NOUN", "explanation");
	load_easy ("LIT_TITLE_NOUN", "approach");
	load_easy ("LIT_TITLE_NOUN", "critique");
	load_easy ("LIT_TITLE_NOUN", "exegesis");
	load_easy ("LIT_TITLE_NOUN", "analysis");

	load_easy ("LIT_NOUN_POS", "sanity");
	load_easy ("LIT_NOUN_POS", "spirit");
	load_easy ("LIT_NOUN_POS", "motivation");
	load_easy ("LIT_NOUN_POS", "ability");
	load_easy ("LIT_NOUN_POS", "intelligence");
	load_easy ("LIT_NOUN_POS", "will to live");

	load_easy ("LIT_SUPER_NEG", "most self-indulgent");
	load_easy ("LIT_SUPER_NEG", "most ill-conceived");
	load_easy ("LIT_SUPER_NEG", "worst");
	load_easy ("LIT_SUPER_NEG", "most half-baked");
	load_easy ("LIT_SUPER_NEG", "crassest");
	load_easy ("LIT_SUPER_NEG", "most commercial");

	load_easy ("LIT_SUPER_POS", "most influential");
	load_easy ("LIT_SUPER_POS", "best");
	load_easy ("LIT_SUPER_POS", "most timeless");
	load_easy ("LIT_SUPER_POS", "richest");
	load_easy ("LIT_SUPER_POS", "best-loved");
	load_easy ("LIT_SUPER_POS", "most enduring");

	load_easy ("LIT_ADJ_NEG", "half-baked");
	load_easy ("LIT_ADJ_NEG", "LIT_ADV brainless");
	load_easy ("LIT_ADJ_NEG", "wrong-headed");
	load_easy ("LIT_ADJ_NEG", "witless");
	load_easy ("LIT_ADJ_NEG", "ponderous");
	load_easy ("LIT_ADJ_NEG", "simple");
	load_easy ("LIT_ADJ_NEG", "drug-influenced");
	load_easy ("LIT_ADJ_NEG", "insane");
	load_easy ("LIT_ADJ_NEG", "pandering");

	load_easy ("LIT_ADJ", "LIT_ADJ_POS");
	load_easy ("LIT_ADJ", "LIT_ADJ_NEG");


	load_easy ("LIT_ADJ_POS", "triumphant");
	load_easy ("LIT_ADJ_POS", "notable");
	load_easy ("LIT_ADJ_POS", "famous");
	load_easy ("LIT_ADJ_POS", "reknown");
	load_easy ("LIT_ADJ_POS", "brilliant");
	load_easy ("LIT_ADJ_POS", "monumental");
	load_easy ("LIT_ADJ_POS", "skillful");
	load_easy ("LIT_ADJ_POS", "moving");
	load_easy ("LIT_ADJ_POS", "powerful");

	load_easy ("LIT_DURATION", "often");
	load_easy ("LIT_DURATION", "frequently");
	load_easy ("LIT_DURATION", "habitually");
	load_easy ("LIT_DURATION", "usually");
	load_easy ("LIT_DURATION", "typically");

	load_easy ("LIT_A_ONE", "FIRSTNAME LASTNAME was a LIT_ADJ_POS contributor to the LIT_PERIOD literary tradition.");
	load_easy ("LIT_A_ONE", "Frequent allusions to LIT_THEMES have led many critics to question LASTNAME 's LIT_NOUN_POS .");
	load_easy ("LIT_A_ONE", "There was no author more LIT_ADJ_POS during the LIT_PERIOD than FIRSTNAME LASTNAME ."); 

	load_easy ("LIT_A_ONE", "Writers of the LIT_PERIOD LIT_DURATION ignored the themes of LIT_THEMES_A and LIT_THEMES_C . FIRSTNAME LASTNAME was no exception.");
	load_easy ("LIT_A_ONE", "LIT_THEMES was a favorite theme of FIRSTNAME LASTNAME .");

	load_easy ("LIT_A_TWO", "However, in  LIT_BOOK , LASTNAME demonstrates none of the ill effects that LIT_SCHOOL had on many writers of the period. LIT_THESIS .");
	load_easy ("LIT_A_TWO", "Still, while scholars often feel LIT_BOOK is LIT_ADJ_NEG , it is one of LASTNAME 's LIT_SUPER_POS works. LIT_THESIS .");
	load_easy ("LIT_A_TWO", "Nevertheless, LASTNAME 's use of LIT_THEMES is all too often mistaken for LIT_THEMES in LIT_BOOK . LIT_THESIS .");
	load_easy ("LIT_A_TWO", "To wit, LIT_THEMES was never so present in FIRSTNAME LASTNAME 's work as in the LIT_ADJ_POS novel, LIT_BOOK .  LIT_THESIS .");
	load_easy ("LIT_A_TWO", "Unfortunately, LIT_BOOK is absolutely LIT_ADJ_NEG in terms of LASTNAME 's usual LIT_MOVEMENTA politics . LIT_THESIS .");


	load_easy ("LIT_THESIS", "LIT_THESIS_OPENING , LIT_THESIS_MIDDLE LIT_THESIS_CLOSE");

	load_easy ("LIT_THESIS_OPENING", "In this paper");
	load_easy ("LIT_THESIS_OPENING", "In the following paragraphs");
	load_easy ("LIT_THESIS_OPENING", "Below");


	load_easy ("LIT_THESIS_MIDDLE", "I will show that");
	load_easy ("LIT_THESIS_MIDDLE", "evidence will be presented that clearly demonstrates");
	load_easy ("LIT_THESIS_MIDDLE", "it will be proven that");

	load_easy ("LIT_THESIS_CLOSE", "most LIT_MOVEMENTA critics are wrong about LASTNAME 's use of LIT_THEMES ");
	load_easy ("LIT_THESIS_CLOSE", "LIT_BOOK is the most LIT_ADJ_POS example of LIT_MOVEMENTA writing ever created ");
	load_easy ("LIT_THESIS_CLOSE", "LIT_BOOK 's LIT_MOVEMENTA overtones and views on LIT_BIG_NOUN are <i>not</i> evidence of LASTNAME 's surrender to LIT_BIG_NOUN ");
	load_easy ("LIT_THESIS_CLOSE", "LASTNAME 's LIT_ADJ_POS writing is representative of the strong LIT_MOVEMENTA ideals of the author's time");


	load_easy ("LIT_A_THREE", "Support for this claim is present in the following: (a) LIT_A_THESIS_POINT_A , (b) LIT_A_THESIS_POINT_B , and (c) LIT_A_THESIS_POINT_C .");
	load_easy ("LIT_A_THREE", "This claim is buttressed by three points: (1) LIT_A_THESIS_POINT_B , (2) LIT_A_THESIS_POINT_A , and (3) LIT_A_THESIS_POINT_C .");

	load_easy ("LIT_A_THESIS_POINT_A", " LASTNAME 's LIT_ADJ_POS LIT_ACTION of LIT_THEMES_A in the work");
	load_easy ("LIT_A_THESIS_POINT_A", " LASTNAME 's LIT_ADJ_NEG take on LIT_THEMES_A throughout the book");
	load_easy ("LIT_A_THESIS_POINT_A", " LASTNAME 's adversarial relationship to LIT_SCHOOL while writing the book");
	load_easy ("LIT_A_THESIS_POINT_A", " LASTNAME 's LIT_ADJ_POS role in LIT_SCHOOL"); 

	load_easy ("LIT_A_THESIS_POINT_B", "the LIT_ADJ_POS use of LIT_THEMES_B in LIT_BOOK");
	load_easy ("LIT_A_THESIS_POINT_B", "the LIT_MOVEMENTA theme of LIT_THEMES_B in LIT_BOOK");
	load_easy ("LIT_A_THESIS_POINT_B", "the LIT_MOVEMENTA views of LIT_BOOK 's protagonist, LIT_CHARACTER ");

	load_easy ("LIT_A_THESIS_POINT_C", "the author's LIT_ACTION of LIT_THEMES_C");
	load_easy ("LIT_A_THESIS_POINT_C", "LIT_MOVEMENTA overtones in the work's LIT_CHAPTER");
	load_easy ("LIT_A_THESIS_POINT_C", "the author's LIT_ACTION of LIT_THEMES_C , showing the influence of the LIT_SCHOOL");
	load_easy ("LIT_A_THESIS_POINT_C", "the author's brave LIT_ACTION of LIT_THEMES_C depite the influence of the LIT_MOVEMENTA school ");

	load_easy ("LIT_ACTION", "employment");
	load_easy ("LIT_ACTION", "portrayal");
	load_easy ("LIT_ACTION", "incorporation");
	load_easy ("LIT_ACTION", "exploration");
	load_easy ("LIT_ACTION", "use");

	load_easy ("LIT_MIDDLE_ONE", "");
	load_easy ("LIT_MIDDLE_ONE", "");
        load_easy ("LIT_MIDDLE_ONE", "To start,");
        load_easy ("LIT_MIDDLE_ONE", "How can I put this...");
        load_easy ("LIT_MIDDLE_ONE", "First,");
        load_easy ("LIT_MIDDLE_ONE", "To begin,");
        load_easy ("LIT_MIDDLE_ONE", "First of all,");
        
	load_easy ("LIT_MIDDLE_TWO", "");
	load_easy ("LIT_MIDDLE_TWO", "");
	load_easy ("LIT_MIDDLE_TWO", "");
	load_easy ("LIT_MIDDLE_TWO", "");
        load_easy ("LIT_MIDDLE_TWO", "Second,");
        load_easy ("LIT_MIDDLE_TWO", "Next,");
        load_easy ("LIT_MIDDLE_TWO", "Further,");
        load_easy ("LIT_MIDDLE_TWO", "Furthermore,");
        load_easy ("LIT_MIDDLE_TWO", "Continuing with this rationale,");

	load_easy ("LIT_MIDDLE_THREE", "");
	load_easy ("LIT_MIDDLE_THREE", "");
	load_easy ("LIT_MIDDLE_THREE", "");
	load_easy ("LIT_MIDDLE_THREE", "");
        load_easy ("LIT_MIDDLE_THREE", "Finally,");
        load_easy ("LIT_MIDDLE_THREE", "Third,");
        load_easy ("LIT_MIDDLE_THREE", "Last,");
        load_easy ("LIT_MIDDLE_THREE", "Finally,");


	load_easy ("LIT_PHRASE", "a quest for LIT_BIG_NOUN ");
	load_easy ("LIT_PHRASE", "the most succesful");
	load_easy ("LIT_PHRASE", "a triumph");
	load_easy ("LIT_PHRASE", "a triumph over the LIT_THEMES_B of the human condition");
	load_easy ("LIT_PHRASE", "with few equals in the forest of truth");


	load_easy ("LIT_TRANS", "therefore");
	load_easy ("LIT_TRANS", "hence");
	load_easy ("LIT_TRANS", "ergo");
	load_easy ("LIT_TRANS", "thusly");
	load_easy ("LIT_TRANS", "thus");

        load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "In some circles, this caused revolution; in others, revulsion");
        load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "LASTNAME 's quest for LIT_BIG_NOUN couldn't be more forceful ");
        load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "The LIT_MOVEMENTA implications of this are wide-ranging");
        load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "Truer words have never been uttered, at least not by me");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "Notice how the LIT_THEMES_A shown here almost eclipses the sense of LIT_THEMES_B ");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "This is LIT_ADV the most LIT_ADJ_POS , LIT_ADJ_POS capitulation of LIT_MOVEMENTA ideals LASTNAME would ever make");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "LIT_ADV , LASTNAME 's intentions for LIT_CHARACTER are ambiguous here");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "Though these words have a LIT_MOVEMENTA quality, they also reveal search for LIT_BIG_NOUN ");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "The few words encapsulate nearly the whole of LIT_PERIOD thought");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "One can see that LIT_THEMES_A is right around the corner");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "LIT_THEMES_A and LIT_THEMES_B come to bear here like never before");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "The question is begged: what is <i>really</i> going on here");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "Thus, LIT_SCHOOL was in effect ");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "Many LIT_PEOPLE have looked to these words for guidance");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "Yet again, LIT_BOOK 's discordant amalgam of LIT_THEMES_B and LIT_THEMES_B couldn't be more compelling");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "With these words, LASTNAME devastated his critics");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "In just a few words, the LIT_MOVEMENTA movement was left in shambles");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "Salt in the wounds of LIT_BIG_NOUN ");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "Pregnant words");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "The contemplation of this passage is beyond me");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "I'll address this in greater detail later");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "This passage escaped most critics, but not LIT_SOURCE , who plagarized it years later");
	load_easy ("LIT_QUOTE_COMMENT_UNPUNC", "To conclude from this that my argument is true is... trivial");





        load_easy ("LIT_QUOTE_COMMENT", "in some circles, this caused revolution; in others, revulsion.");
        load_easy ("LIT_QUOTE_COMMENT", "LASTNAME 's quest for LIT_BIG_NOUN couldn't be more forceful .");
        load_easy ("LIT_QUOTE_COMMENT", "the LIT_MOVEMENTA implications of this are wide-ranging.");
        load_easy ("LIT_QUOTE_COMMENT", "truer words have never been uttered, at least not by me.");
	load_easy ("LIT_QUOTE_COMMENT", "notice how the LIT_THEMES_A shown here almost eclipses the sense of LIT_THEMES_B .");
	load_easy ("LIT_QUOTE_COMMENT", "this line is LIT_ADV the most LIT_ADJ_POS , LIT_ADJ_POS capitulation of LIT_MOVEMENTA ideals LASTNAME would ever make.");
	load_easy ("LIT_QUOTE_COMMENT", "LIT_ADV , LASTNAME 's intentions for LIT_CHARACTER are ambiguous here.");
	load_easy ("LIT_QUOTE_COMMENT", "though these words have a LIT_MOVEMENTA quality, they also reveal search for LIT_BIG_NOUN .");
	load_easy ("LIT_QUOTE_COMMENT", "these words encapsulate nearly the whole of LIT_PERIOD thought.");
	load_easy ("LIT_QUOTE_COMMENT", "one can see that LIT_THEMES_A is right around the corner.");
	load_easy ("LIT_QUOTE_COMMENT", "LIT_THEMES_A and LIT_THEMES_B come to bear here like never before.");
	load_easy ("LIT_QUOTE_COMMENT", "the question is begged: what is <i>really</i> going on here?");
	load_easy ("LIT_QUOTE_COMMENT", "LIT_SCHOOL was in effect.");
	load_easy ("LIT_QUOTE_COMMENT", "many LIT_PEOPLE have looked to these words for guidance.");
	load_easy ("LIT_QUOTE_COMMENT", "LIT_BOOK 's discordant amalgam of LIT_THEMES_B and LIT_THEMES_B couldn't be more forceful.");
	load_easy ("LIT_QUOTE_COMMENT", "with these words, LASTNAME devastated his critics.");
	load_easy ("LIT_QUOTE_COMMENT", "in these few words, the LIT_MOVEMENTA movement was left in shambles.");
	load_easy ("LIT_QUOTE_COMMENT", "salt in the wounds of LIT_BIG_NOUN .");
	load_easy ("LIT_QUOTE_COMMENT", "these are pregnant words, indeed.");
	load_easy ("LIT_QUOTE_COMMENT", "the contemplation of this passage is beyond me.");
	load_easy ("LIT_QUOTE_COMMENT", "I'll address this in greater detail later.");
	load_easy ("LIT_QUOTE_COMMENT", "this passage escaped most critics, but not LIT_SOURCE , who plagarized it years later, frankly.");
	load_easy ("LIT_QUOTE_COMMENT", "to conclude from this that my argument is true is... trivial.");

	load_easy ("LIT_CRIT_ADJ", "fecund");
	load_easy ("LIT_CRIT_ADJ", "fertile");
	load_easy ("LIT_CRIT_ADJ", "invaluable");
	load_easy ("LIT_CRIT_ADJ", "fruitful");
	load_easy ("LIT_CRIT_ADJ", "useful");

	load_easy ("LIT_B_ONE", "in the LIT_CHAPTER_EARLY of LIT_BOOK , LASTNAME writes: LIT_QUOTE LIT_QUOTE_COMMENT");
	load_easy ("LIT_B_ONE", "the lingering line of LIT_BOOK is , LIT_QUOTE LIT_QUOTE_COMMENT ");
	load_easy ("LIT_B_ONE", "consider this passage: LIT_QUOTE LIT_QUOTE_COMMENT ");
	load_easy ("LIT_B_ONE", "in LIT_BOOK 's LIT_CHAPTER_EARLY we find LASTNAME at his LIT_SUPER_NEG . But even this section can still prove LIT_CRIT_ADJ to the LIT_GROUP reader . Consider: LIT_QUOTE LIT_QUOTE_COMMENT ");
	load_easy ("LIT_B_ONE", "with words like \" LIT_QUOTEA ,\"  LASTNAME stakes his claim.");
	load_easy ("LIT_B_ONE", "lines like \" LIT_QUOTEA ,\" have made LIT_BOOK required reading for the LIT_MOVEMENTA student. ");
	load_easy ("LIT_B_ONE", "LASTNAME 's LIT_GROUP sympathies are evident in LIT_BOOK . ");
	load_easy ("LIT_B_ONE", "how LIT_ADJ_RHET that LIT_BOOK is LIT_DURATION dismissed as little more than LIT_TYPE !");
	load_easy ("LIT_B_ONE", "LIT_BOOK is LIT_ADV a LIT_ADJ_POS work.");
	load_easy ("LIT_B_ONE", "when LIT_PEOPLE dismiss LIT_BOOK as a simple LIT_TYPE , all I can say is, LIT_FILLER ");
	load_easy ("LIT_B_ONE", "LIT_BOOK is LIT_CRIT_ADJ ground for the LIT_MOVEMENTA LIT_GROUP .");
	load_easy ("LIT_B_ONE", "could the so-called  \" LIT_MOVEMENTA \" critics be more wrong about LIT_BOOK ?");
	load_easy ("LIT_B_ONE", "LASTNAME 's prose is so LIT_DURATION LIT_ADJ_POS that we often take for granted lines like LIT_QUOTE ");
	load_easy ("LIT_B_ONE", "what ignorant moron annointed LASTNAME as the LIT_MOVEMENTA savior?");
        load_easy ("LIT_B_ONE", "these themes are most evident in LIT_CHAPTER_EARLY of LIT_BOOK , for that is when LASTNAME 's often LIT_ADJ_NEG prose shines most brightly.");
        load_easy ("LIT_B_ONE", "LASTNAME 's LIT_ACTION of such imagery is most skillful in LIT_BOOK 's LIT_ADJ_POS LIT_CHAPTER_EARLY .");
        load_easy ("LIT_B_ONE", "the LIT_THEMES_A in LIT_BOOK really hits you like a rock.");
        load_easy ("LIT_B_ONE", "LIT_THEMES_A is not LIT_BOOK 's only theme; there is also pure LIT_BIG_NOUN .");
        load_easy ("LIT_B_ONE", "consider that LIT_BOOK was not so much written by LASTNAME as belched forth in a fit of sublime inspiration .");
        load_easy ("LIT_B_ONE", "realize that LASTNAME had lost his LIT_NOUN_POS just before completing LIT_BOOK .");
        load_easy ("LIT_B_ONE", "LASTNAME 's LIT_NOUN_POS is truly evident in LIT_BOOK .");
        load_easy ("LIT_B_ONE", "critics are dead wrong when they cite LIT_BOOK as an example of LASTNAME 's dwindling LIT_NOUN_POS .");
        load_easy ("LIT_B_ONE", "any examination of LIT_BIG_NOUN is incomplete without addressing the LIT_THEMES_A of LIT_BOOK .");
        load_easy ("LIT_B_ONE", "LIT_BOOK is, like all of LASTNAME 's great works, LIT_PHRASE .");
        load_easy ("LIT_B_ONE", "LIT_BOOK cannot be fully understood without examination of LIT_SCHOOL .");
	load_easy ("LIT_B_ONE", "the LIT_THEMES motif in LIT_BOOK was not original with LASTNAME . Consider this famous quote by LIT_SOURCE : \" LIT_QUOTEA .\" LIT_QUOTE_COMMENT ");
	load_easy ("LIT_B_ONE", "The protagonist's life is dominated by LIT_NOUN , and the character of LIT_CHARACTER is LIT_ADJ as a symbol of LIT_THEMES_A .");

	load_easy ("LIT_B_TWO", "In the LIT_CHAPTER_LATE the reader is presented with a paradox: though the characters seem unable to escape LIT_THEMES , they are simultaneously LIT_ADJ and LIT_ADJ .");
	load_easy ("LIT_B_TWO", "the author uses LIT_THEMES_B to transform LIT_CHARACTER from a LIT_ADJ_NEG bit-player into a LIT_ADJ_POS hero.");
	load_easy ("LIT_B_TWO", "To indicate that LIT_CHARACTER is the work's villain, the author makes his dialogue LIT_ADJ_NEG .");
	load_easy ("LIT_B_TWO", "LIT_BOOK 's LIT_ACTION of LIT_THEMES_C is in keeping with its LIT_MOVEMENTA point-of-view .");
	load_easy ("LIT_B_TWO", "it's quite obvious that LASTNAME 's LIT_NOUN_POS was tenuous at best by the time LIT_BOOK was completed.");
	load_easy ("LIT_B_TWO", "LIT_BOOK is not so much LIT_TYPE <i>per se</i> as it is LASTNAME 's most heart-felt LIT_TITLE_NOUN of LIT_BIG_NOUN .");
	load_easy ("LIT_B_TWO", "for the LIT_GROUP community there can be no other conclusion.");
	load_easy ("LIT_B_TWO", "while this fact allays most of LASTNAME 's LIT_GROUP detractors, it has led a certain LIT_MOVEMENTA critic-- the execrable LIT_SOURCE --to proclaim \" LIT_QUOTE_COMMENT \"");
	load_easy ("LIT_B_TWO", "it should be obvious that LASTNAME was never driven <i>purely</i> by the LIT_BIG_NOUN paradigm.");
	load_easy ("LIT_B_TWO", "of course, like all great works, LIT_BOOK has its flaws!");
	load_easy ("LIT_B_TWO", "still, LIT_BOOK was not originally seen as a <i>tour de force</i> by the intelligensia. LIT_FILLER ");
	load_easy ("LIT_B_TWO", "As such, the words of the character LIT_CHARACTER ring true: \" LIT_QUOTEA .\"");
	load_easy ("LIT_B_TWO", "as you can imagine, LIT_PEOPLE took to the streets after the book's first publication.");
	load_easy ("LIT_B_TWO", "wars have been fought over less.");
	load_easy ("LIT_B_TWO", "many LIT_PEOPLE_MOD see the book's LIT_CHAPTER_LATE as the LIT_SUPER_POS ; I, however, do not.");
	load_easy ("LIT_B_TWO", "LASTNAME 's quest for LIT_BIG_NOUN in his later books supports this conclusion.");
	load_easy ("LIT_B_TWO", "While most other HIST_NATIONALITY authors conceived of their characters as LIT_MOVEMENT symbols, LASTNAME 's lusted for real LIT_BIG_NOUN ! ");
	load_easy ("LIT_B_TWO", "Where many other HIST_NATIONALITY writers failed to convincingly portray LIT_THEMES , LASTNAME succeeds.");

	load_easy ("LIT_B_CONCLUDE", "LIT_B_THREE_UNPUNC ; LIT_B_THREE ");
	load_easy ("LIT_B_CONCLUDE", " LIT_B_THREE ");




	load_easy ("LIT_B_THREE", "critics of LASTNAME 's work often overlook this aspect.");
	load_easy ("LIT_B_THREE", "LIT_CHARACTER 's famously LIT_ADJ_NEG attitude throughout the book is often cited.");
	load_easy ("LIT_B_THREE", "parts of the book's LIT_CHAPTER_LATE are often cited as evidence.");
	load_easy ("LIT_B_THREE", "it is no great feat to realize LASTNAME has written himself into a corner here!");
	load_easy ("LIT_B_THREE", "LIT_ADV , LASTNAME meant this as a critique of LIT_THEMES_C .");
	load_easy ("LIT_B_THREE", "of course, this is the LIT_MOVEMENTA view.");
	load_easy ("LIT_B_THREE", "of course, this is only a guess.");
	load_easy ("LIT_B_THREE", "nonetheless, we must be careful in making assumptions.");
	load_easy ("LIT_B_THREE", "as pure LIT_TYPE , LIT_BOOK was assailed for such statements. LIT_FILLER ");
	load_easy ("LIT_B_THREE", "read as LIT_TYPE , LIT_BOOK supports no other analysis.");
	load_easy ("LIT_B_THREE", "that's the LIT_GROUP assumption, at least.");
	load_easy ("LIT_B_THREE", "at best, this is the LIT_ADJ_NEG critique. LIT_FILLER ");
	load_easy ("LIT_B_THREE", "some of LASTNAME 's LIT_SUPER_POS writing is in LIT_BOOK .");
	load_easy ("LIT_B_THREE", "to see how this supports my previous claim is quite trivial.");
	load_easy ("LIT_B_THREE", "evidence for this conclusion abounds in the LIT_CHAPTER_LATE of the book.");
	load_easy ("LIT_B_THREE", "this all but proves my thesis, especially when LASTNAME 's LIT_ACTION of LIT_THEMES_A in the book is taken into account.");
	load_easy ("LIT_B_THREE", "the casual critic LIT_DURATION misses this point.");
	load_easy ("LIT_B_THREE", "LASTNAME 's point here is clear:  LIT_BIG_NOUN and LIT_BIG_NOUN are LIT_STOCK_PHRASE .");
	load_easy ("LIT_B_THREE", "as an affirmation of LIT_BIG_NOUN , this is LASTNAME 's grandest statement.");
	load_easy ("LIT_B_THREE", "it is also LIT_ADJ_RHET that scholars--by seeing him as an avatar of LASTNAME 's LIT_MOVEMENT views--have misinterpreted the character LIT_CHARACTER 's role in the book.");
	load_easy ("LIT_B_THREE", "this becomes LIT_ADJ_RHET only when one considers the book's famous line, LIT_QUOTE ");
	load_easy ("LIT_B_THREE", "LIT_CHARACTER is a surprisingly LIT_ADJ character.");
	load_easy ("LIT_B_THREE", "this is LIT_ADV why LIT_CHARACTER is such a LIT_ADJ character.");
	load_easy ("LIT_B_THREE", "LIT_CHARACTER is a far from marginal character; in fact, it is through him that many of LASTNAME 's LIT_PERIOD influences show through.");
	load_easy ("LIT_B_THREE", "this reasoning differs radically from traditional theories of LIT_SCHOOL .");

	load_easy ("LIT_B_THREE_UNPUNC", "Critics of LASTNAME 's work often overlook this aspect");
	load_easy ("LIT_B_THREE_UNPUNC", "LIT_CHARACTER 's famously LIT_ADJ_NEG attitude throughout the book is often blamed");
	load_easy ("LIT_B_THREE_UNPUNC", "developments in the LIT_CHAPTER_EARLY are often cited as evidence");
	load_easy ("LIT_B_THREE_UNPUNC", "It is no great feat to realize LASTNAME has written himself into a corner here");
	load_easy ("LIT_B_THREE_UNPUNC", "LIT_ADV , LASTNAME meant this as a critique of LIT_THEMES_C ");
	load_easy ("LIT_B_THREE_UNPUNC", "As pure LIT_TYPE , LIT_BOOK was assailed for such statements ");
	load_easy ("LIT_B_THREE_UNPUNC", "Read as LIT_TYPE , LIT_BOOK supports no other analysis");
	load_easy ("LIT_B_THREE_UNPUNC", "Some of LASTNAME LIT_SUPER_POS writing is in LIT_BOOK ");
	load_easy ("LIT_B_THREE_UNPUNC", "To see how this supports my previous claim is quite trivial");
	load_easy ("LIT_B_THREE_UNPUNC", "Evidence for this conclusion abounds in the LIT_CHAPTER_EARLY of the book");
	load_easy ("LIT_B_THREE_UNPUNC", "This all but proves my thesis, especially when LASTNAME 's LIT_ACTION of LIT_THEMES_A in the book is taken into account");
	load_easy ("LIT_B_THREE_UNPUNC", "The casual critic LIT_DURATION misses this point");
	load_easy ("LIT_B_THREE_UNPUNC", "LASTNAME 's point here is clear:  LIT_BIG_NOUN and LIT_BIG_NOUN are LIT_STOCK_PHRASE ");
	load_easy ("LIT_B_THREE_UNPUNC", "As an affirmation of LIT_BIG_NOUN , this is LASTNAME 's grandest statement");
	load_easy ("LIT_B_THREE_UNPUNC", "It is LIT_ADJ_RHET that scholars--by seeing him as an avatar of LASTNAME 's LIT_MOVEMENTA views--have misinterpreted the character LIT_CHARACTER 's role in the book ");
	load_easy ("LIT_B_THREE_UNPUNC", "This becomes LIT_ADJ_RHET only when one considers the book's famous line, \" LIT_QUOTEA \" ");
	load_easy ("LIT_B_THREE_UNPUNC", "LIT_CHARACTER is a LIT_ADJ character for this very reason");
	load_easy ("LIT_B_THREE_UNPUNC", "This is LIT_ADV why LIT_CHARACTER is such a LIT_ADJ character");
	load_easy ("LIT_B_THREE_UNPUNC", "LIT_CHARACTER is a far from marginal character; in fact, it is through him that many of LASTNAME 's LIT_PERIOD influences show through");
	load_easy ("LIT_B_THREE_UNPUNC", "This reasoning differs radically from traditional theories on LIT_SCHOOL ");





	load_easy ("LIT_ADJ_RHET", "meaningful");
	load_easy ("LIT_ADJ_RHET", "clear");
	load_easy ("LIT_ADJ_RHET", "significant");
	load_easy ("LIT_ADJ_RHET", "germane");
	load_easy ("LIT_ADJ_RHET", "relevant");
	load_easy ("LIT_ADJ_RHET", "apparent");
	load_easy ("LIT_ADJ_RHET", "trivial");
	load_easy ("LIT_ADJ_RHET", "obvious");
	load_easy ("LIT_ADJ_RHET", "predictable");
	load_easy ("LIT_ADJ_RHET", "transparent");


	load_easy ("LIT_FILLER", "how things have changed!");
	load_easy ("LIT_FILLER", "SCI_C_ONE_OPENING this is truly foolish.");
	load_easy ("LIT_FILLER", "what blindness.");
	load_easy ("LIT_FILLER", "give me a goddamn break!");
	load_easy ("LIT_FILLER", "woe is them!");
	load_easy ("LIT_FILLER", "yet again, the curs of ignorance slaver at the heels of reason.");
	load_easy ("LIT_FILLER", "this begs the question: why?");
	load_easy ("LIT_FILLER", "<i>Quelle injuste</i>!");

	load_easy ("LIT_TYPE", "roman a clef");
	load_easy ("LIT_TYPE", "bildungsroman");
	load_easy ("LIT_TYPE", "allegory");
	load_easy ("LIT_TYPE", "satire");
	load_easy ("LIT_TYPE", "non-fiction");
	load_easy ("LIT_TYPE", "journalism");
	load_easy ("LIT_TYPE", "autobiography");

	load_easy ("LIT_BIG_NOUN", "life");
	load_easy ("LIT_BIG_NOUN", "reality");
	load_easy ("LIT_BIG_NOUN", "humanity");
	load_easy ("LIT_BIG_NOUN", "being");
	load_easy ("LIT_BIG_NOUN", "hate");
	load_easy ("LIT_BIG_NOUN", "love");
	load_easy ("LIT_BIG_NOUN", "peer pressure");
	load_easy ("LIT_BIG_NOUN", "truth");
	load_easy ("LIT_BIG_NOUN", "religion");
	load_easy ("LIT_BIG_NOUN", "salvation");
	load_easy ("LIT_BIG_NOUN", "immortality");
	load_easy ("LIT_BIG_NOUN", "reason");

	load_easy ("LIT_C_ONE", "LIT_C_ONE_CLOSING");

	load_easy ("LIT_ADV", "probably");
	load_easy ("LIT_ADV", "totally");
	load_easy ("LIT_ADV", "definitely");
	load_easy ("LIT_ADV", "possibly");
	load_easy ("LIT_ADV", "most likely");
	load_easy ("LIT_ADV", "obviously");
	load_easy ("LIT_ADV", "clearly");

	load_easy ("LIT_STOCK_PHRASE", "part and parcel");
	load_easy ("LIT_STOCK_PHRASE", "one and the same");


	load_easy ("LIT_PEOPLE_MOD", "former LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "wannabe LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "concerned LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "politically-minded LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "contemplative LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "aspiring LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "erstwhile LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "LIT_PEOPLE");
	load_easy ("LIT_PEOPLE_MOD", "LIT_PEOPLE");

	load_easy ("LIT_GROUP", "teen");
	load_easy ("LIT_GROUP", "under-class");
	load_easy ("LIT_GROUP", "German");
	load_easy ("LIT_GROUP", "Italian");
	load_easy ("LIT_GROUP", "immigrant");
	load_easy ("LIT_GROUP", "male");
	load_easy ("LIT_GROUP", "feminist");
	load_easy ("LIT_GROUP", "expatriot");
	load_easy ("LIT_GROUP", "Canadian");


	load_easy ("LIT_PEOPLE", "Germans");
	load_easy ("LIT_PEOPLE", "expatriots");
	load_easy ("LIT_PEOPLE", "Mexicans");
	load_easy ("LIT_PEOPLE", "critics");
	load_easy ("LIT_PEOPLE", "revolutionaries");
	load_easy ("LIT_PEOPLE", "feminists");
	load_easy ("LIT_PEOPLE", "women");
	load_easy ("LIT_PEOPLE", "homophobes");
	load_easy ("LIT_PEOPLE", "parents");
	load_easy ("LIT_PEOPLE", "teens");
	load_easy ("LIT_PEOPLE", "martyrs");
	load_easy ("LIT_PEOPLE", "immigrants");
	load_easy ("LIT_PEOPLE", "students");

	load_easy ("LIT_C_ONE_CLOSING", "LIT_BIG_NOUN is more deftly LIT_ACTION in LIT_BOOK than ever before.");
	load_easy ("LIT_C_ONE_CLOSING", "LIT_BOOK should be required reading for all LIT_PEOPLE_MOD .");
	load_easy ("LIT_C_ONE_CLOSING", "LIT_BOOK is truly LASTNAME 's most enduring contribution to mankind's continuing attempt to understand his own LIT_BIG_NOUN .");
	load_easy ("LIT_C_ONE_CLOSING", "as a testament to LIT_BIG_NOUN and a celebration of LIT_BIG_NOUN , LIT_BOOK will always ring true.");
	load_easy ("LIT_C_ONE_CLOSING", "LASTNAME 's LIT_BOOK will always be with me.");
	load_easy ("LIT_C_ONE_CLOSING", "LIT_BOOK remains the most important LIT_ACTION of LIT_BIG_NOUN ever committed to paper.");
	load_easy ("LIT_C_ONE_CLOSING", "LIT_BOOK might never be fully appreciated.");
	load_easy ("LIT_C_ONE_CLOSING", "the echoes of LIT_BOOK will reverberate through the centuries, for years to come.");
	load_easy ("LIT_C_ONE_CLOSING", "the sun may never set on the empire that is LIT_BOOK 's lasting influence.");
	load_easy ("LIT_C_ONE_CLOSING", "the influence of LIT_BOOK is stronger than ever.");
	load_easy ("LIT_C_ONE_CLOSING", "the influence of LASTNAME 's LIT_BOOK is still strong.");
	load_easy ("LIT_C_ONE_CLOSING", "it's easy to forget that LIT_BOOK was the most HIST_ADJ work of its time.");
	
	load_easy ("LIT_C_TWO", "While other works influenced by LIT_SCHOOL are LIT_DURATION forgotten , LIT_BOOK remains LIT_ADJ_POS .");
	load_easy ("LIT_C_TWO", "Perhaps it's time that scholars reevaluated their estimation of the book .");	

	load_easy ("LIT_C_THREE", "Though contemporaries found LASTNAME 's use of LIT_THEMES LIT_ADJ_NEG , history will vindicate LIT_BOOK .");
	load_easy ("LIT_C_THREE", "Though famous for portrayals of LIT_THEMES_A in other works, LASTNAME will always be loved for his LIT_ADJ_POS LIT_ACTION of LIT_THEMES_B in this book.");

	load_easy ("LIT_C_FOUR", "This work is a fine example of what I like to call LIT_TYPE .");
	load_easy ("LIT_C_FOUR", "The Great Muse certainly smiled on LASTNAME when LIT_BOOK was written.");
	load_easy ("LIT_C_FOUR", "This book is perhaps the greatest LIT_ACTION of LIT_BIG_NOUN mankind has ever seen.");
	load_easy ("LIT_C_FOUR", "Join me in appreciating it .");
	load_easy ("LIT_C_FOUR", "FIRSTNAME LASTNAME , we salute you.");
	load_easy ("LIT_C_FOUR", "God rest ye, FIRSTNAME LASTNAME .");
	load_easy ("LIT_C_FOUR", "All thanks to a person I like to call FIRSTNAME LASTNAME .");
	load_easy ("LIT_C_FOUR", "FIRSTNAME LASTNAME : one soul lost in a LIT_ADJ_NEG whirlwind of LIT_NOUN .");
	load_easy ("LIT_C_FOUR", "This concludes my research.");
	load_easy ("LIT_C_FOUR", "Thus concludes my participation in this class.");
	load_easy ("LIT_C_FOUR", "Thus concludes my paper.");
	load_easy ("LIT_C_FOUR", "This is LIT_ADV why LASTNAME died disgraced and penniless .");
	load_easy ("LIT_C_FOUR", "Q. E. D. -- quite easily done.");

	load_easy ("LIT_THEMES", "LIT_THEMES_A");
	load_easy ("LIT_THEMES", "LIT_THEMES_B");
	load_easy ("LIT_THEMES", "LIT_THEMES_C");

	load_easy ("LIT_THEMES_A", "irony");
	load_easy ("LIT_THEMES_A", "tragedy");
	load_easy ("LIT_THEMES_A", "wilderness");
	load_easy ("LIT_THEMES_A", "pathos");
	load_easy ("LIT_THEMES_A", "bathos");
	load_easy ("LIT_THEMES_A", "allegory");
	load_easy ("LIT_THEMES_A", "juxtapostion");
	load_easy ("LIT_THEMES_A", "satire");
	load_easy ("LIT_THEMES_A", "the tragic hero");
	load_easy ("LIT_THEMES_A", "the patriarch");
	load_easy ("LIT_THEMES_A", "destiny");

	load_easy ("LIT_THEMES_B", "dystopic future-vision");
	load_easy ("LIT_THEMES_B", "revolution");
	load_easy ("LIT_THEMES_B", "iconoclasm");
	load_easy ("LIT_THEMES_B", "loss of innocence");
	load_easy ("LIT_THEMES_B", "coming of age");
	load_easy ("LIT_THEMES_B", "the journey");
	load_easy ("LIT_THEMES_B", "the absurd");
	load_easy ("LIT_THEMES_B", "nature");
	load_easy ("LIT_THEMES_B", "political commentary");
	load_easy ("LIT_THEMES_B", "social commentary");
	load_easy ("LIT_THEMES_B", "subversive undertones");

	load_easy ("LIT_THEMES_C", "incest");
	load_easy ("LIT_THEMES_C", "phallic imagery");
	load_easy ("LIT_THEMES_C", "sexual identity");
	load_easy ("LIT_THEMES_C", "farce");
	load_easy ("LIT_THEMES_C", "sexuality");
	load_easy ("LIT_THEMES_C", "human nature");
	load_easy ("LIT_THEMES_C", "the supernatural");
	load_easy ("LIT_THEMES_C", "the prison");
	load_easy ("LIT_THEMES_C", "sensuality");
	load_easy ("LIT_THEMES_C", "self-indulgence");

	load_easy ("LIT_SOURCE", "Jane Austen");
	load_easy ("LIT_SOURCE", "Mark Twain");
	load_easy ("LIT_SOURCE", "Shakespeare");
	load_easy ("LIT_SOURCE", "T. S. Eliot");
	load_easy ("LIT_SOURCE", "Robert Frost");
	load_easy ("LIT_SOURCE", "James Joyce");
	load_easy ("LIT_SOURCE", "Tom Wolfe");
	load_easy ("LIT_SOURCE", "John Updike");
	load_easy ("LIT_SOURCE", "Ovid");
	load_easy ("LIT_SOURCE", "Lewis Carroll");
	load_easy ("LIT_SOURCE", "Oscar Wilde");
	load_easy ("LIT_SOURCE", "Eugene Ionesco");
	load_easy ("LIT_SOURCE", "Lao Tzu");
	load_easy ("LIT_SOURCE", "Gustave Flaubert");

	load_easy ("LIT_CHARACTER", "LIT_FIRST_NAME LIT_LAST_NAME");
        load_easy ("LIT_FIRST_NAME", "Tom");
	load_easy ("LIT_FIRST_NAME", "Moby");
	load_easy ("LIT_FIRST_NAME", "David");
	load_easy ("LIT_FIRST_NAME", "Captain");
	load_easy ("LIT_FIRST_NAME", "Mr.");
	load_easy ("LIT_FIRST_NAME", "One-Eyed");
	load_easy ("LIT_FIRST_NAME", "William");
	load_easy ("LIT_FIRST_NAME", "Colonel");
	load_easy ("LIT_FIRST_NAME", "Benvolio");
	load_easy ("LIT_FIRST_NAME", "King");	
	load_easy ("LIT_FIRST_NAME", "Master");
	load_easy ("LIT_FIRST_NAME", "Little Timmy");
	load_easy ("LIT_FIRST_NAME", "Nick");
	load_easy ("LIT_FIRST_NAME", "Holden");
	load_easy ("LIT_FIRST_NAME", "Ichabod");
	load_easy ("LIT_FIRST_NAME", "Ishmael");

	load_easy ("LIT_LAST_NAME", "Joad");
	load_easy ("LIT_LAST_NAME", "Daniel");
	load_easy ("LIT_LAST_NAME", "Dick");
	load_easy ("LIT_LAST_NAME", "Lee");
	load_easy ("LIT_LAST_NAME", "Maxwell");
	load_easy ("LIT_LAST_NAME", "Lewis");
	load_easy ("LIT_LAST_NAME", "Crane");
	load_easy ("LIT_LAST_NAME", "Sawyer");
	load_easy ("LIT_LAST_NAME", "Adams");
	load_easy ("LIT_LAST_NAME", "Stephenson");
	load_easy ("LIT_LAST_NAME", "Caulfield");



	load_easy ("LIT_SCHOOL", "the LIT_MOVEMENT school of HIST_NATIONALITY literature");
	load_easy ("LIT_SCHOOL", "the LIT_MOVEMENT school");
        load_easy ("LIT_SCHOOL", "the LIT_MOVEMENT movement");
	load_easy ("LIT_SCHOOL", "the LIT_PERIOD renaissance of HIST_NATIONALITY literature");	
	load_easy ("LIT_SCHOOL", "the LIT_MOVEMENT school");
	load_easy ("LIT_SCHOOL", "the LIT_MOVEMENTA movement");
	load_easy ("LIT_SCHOOL", "the HIST_NATIONALITY LIT_MOVEMENTA school");

	load_easy ("LIT_MOVEMENT", "LIT_MOVEMENTA");
	load_easy ("LIT_MOVEMENT", "post LIT_MOVEMENTA");
	load_easy ("LIT_MOVEMENT", "pre LIT_MOVEMENTA");
	load_easy ("LIT_MOVEMENT", "LIT_PERIOD LIT_MOVEMENTA");

	load_easy ("LIT_MOVEMENTA", "Modernist");
	load_easy ("LIT_MOVEMENTA", "Romantic");
	load_easy ("LIT_MOVEMENTA", "Christian");
	load_easy ("LIT_MOVEMENTA", "Minimalist");
	load_easy ("LIT_MOVEMENTA", "Symbolist");
	load_easy ("LIT_MOVEMENTA", "Surrealist");
	load_easy ("LIT_MOVEMENTA", "Dadaist");
	load_easy ("LIT_MOVEMENTA", "Romantic");
	load_easy ("LIT_MOVEMENTA", "Positivist");
	load_easy ("LIT_MOVEMENTA", "Constructivist");
	load_easy ("LIT_MOVEMENTA", "Colonialist");
	load_easy ("LIT_MOVEMENTA", "reactionary");
	load_easy ("LIT_MOVEMENTA", "conservative");

	load_easy ("LIT_PERIOD", "18th century");
	load_easy ("LIT_PERIOD", "late 17th century");
	load_easy ("LIT_PERIOD", "mid 19th century");
	load_easy ("LIT_PERIOD", "early 20th century");
	load_easy ("LIT_PERIOD", "16th century");
	load_easy ("LIT_PERIOD", "20th century");
	load_easy ("LIT_PERIOD", "late 20th century");

	load_easy ("LIT_QUOTE", "\" LIT_QUOTEA .\" ( LASTNAME HIST_QUOTE_PAGE )");

	load_easy ("LIT_QUOTEA", "He drank the coffee");
	load_easy ("LIT_QUOTEA", "He sat in the chair");
	load_easy ("LIT_QUOTEA", "The woman looked into his eyes");
	load_easy ("LIT_QUOTEA", "Yearning pervaded the camp");
	load_easy ("LIT_QUOTEA", "She looked to the bleak horizon");
	load_easy ("LIT_QUOTEA", "There was hope in her eyes; in his, hope of a different kind");
	load_easy ("LIT_QUOTEA", "All they needed was LIT_BIG_NOUN ");
	load_easy ("LIT_QUOTEA", "The man and the boy talked for hours about absolutely nothing");
	load_easy ("LIT_QUOTEA", "Six of the men were LIT_PEOPLE ; the others were LIT_PEOPLE ");
	load_easy ("LIT_QUOTEA", "His face was bright as he looked at her");
	load_easy ("LIT_QUOTEA", "Her eyes were blue like sapphires");
	load_easy ("LIT_QUOTEA", "His sadness was deep, as if it wouldn't end");
	load_easy ("LIT_QUOTEA", "Four years had passed since the fun county fair");
	load_easy ("LIT_QUOTEA", "The winter winds blew cold, like snow");
	load_easy ("LIT_QUOTEA", "Autumn is the finest, and third, season");
	load_easy ("LIT_QUOTEA", "It was late at night when the old man died");
	load_easy ("LIT_QUOTEA", "Oh! How beautiful a sunrise can be!");
	load_easy ("LIT_QUOTEA", "She sat on the bed");
	load_easy ("LIT_QUOTEA", "It was a terrible week in France");
	load_easy ("LIT_QUOTEA", "Tuesday was a the bleakest day for the Parkers");
	load_easy ("LIT_QUOTEA", "She was not so much fat as unloved");
	load_easy ("LIT_QUOTEA", "Surely, fate was with them");
	load_easy ("LIT_QUOTEA", "There was nothing else to be done");
	load_easy ("LIT_QUOTEA", "I couldn't believe it");
	load_easy ("LIT_QUOTEA", "Down by the river, there was much mud and much water to drink");
	load_easy ("LIT_QUOTEA", "Unheard, I cried");
	load_easy ("LIT_QUOTEA", "The whiskey tasted good to the man");
	load_easy ("LIT_QUOTEA", "The man doffed his nice hat");
	load_easy ("LIT_QUOTEA", "Never give a party if you will be the most interesting person there");
	load_easy ("LIT_QUOTEA", "I subscribed to LIT_MOVEMENTA beliefs");
	load_easy ("LIT_QUOTEA", "My ideology is quite obvious");
	load_easy ("LIT_QUOTEA", "He was ready for any unforeseen event");
	load_easy ("LIT_QUOTEA", "The game was up");
	load_easy ("LIT_QUOTEA", "Life offered nothing but fear itself");
	load_easy ("LIT_QUOTEA", "Love lived in LIT_ADJ bottles of regret");

	load_easy ("LIT_NOUN", "wanderlust");
	load_easy ("LIT_NOUN", "the zeitgiest");
	load_easy ("LIT_NOUN", "soul-searching");
	load_easy ("LIT_NOUN", "angst");
	load_easy ("LIT_NOUN", "hope");


	load_easy ("LIT_CHAPTER", "LIT_CHAPTER_EARLY");
	load_easy ("LIT_CHAPTER", "LIT_CHAPTER_LATE");

	load_easy ("LIT_CHAPTER_EARLY", "opening monologue");
	load_easy ("LIT_CHAPTER_EARLY", "first chapter");
	load_easy ("LIT_CHAPTER_EARLY", "second chapter");
	load_easy ("LIT_CHAPTER_EARLY", "prologue");
	load_easy ("LIT_CHAPTER_EARLY", "first half");

	load_easy ("LIT_CHAPTER_LATE","tenth chapter");
	load_easy ("LIT_CHAPTER_LATE","final paragraph");
	load_easy ("LIT_CHAPTER_LATE","twelfth chapter");
	load_easy ("LIT_CHAPTER_LATE","latter half");
	load_easy ("LIT_CHAPTER_LATE","closing scene");




	//
	// science paper
	//

	load_easy ("SCIPAPER_SHORT", "<p> SCI_PARAGRAPH_A <p> SCI_MIDDLE_SHORT <p> SCI_PARAGRAPH_C");
	load_easy ("SCIPAPER_LONG", "<p> SCI_PARAGRAPH_A <p> SCI_MIDDLE_LONG <p> SCI_PARAGRAPH_C");

	load_easy ("SCI_SCIENTIST", "FIRSTNAME LASTNAME");
	load_easy ("SCIPAPER_TITLE", "SCI_SCIENTIST and TOPIC :<br><i> SCI_SUBTITLE </i>");
	load_easy ("SCIPAPER_TITLE", "TOPIC and SCI_THING");

	load_easy ("SCI_MIDDLE_SHORT", "<p> SCI_PARAGRAPH_B_ONE <p> SCI_PARAGRAPH_B_TWO <p> SCI_PARAGRAPH_B_THREE");
	load_easy ("SCI_MIDDLE_LONG", "<p> SCI_PARAGRAPH_B_ONE <p> SCI_PARAGRAPH_B_TWO <p> SCI_PARAGRAPH_B_THREE");

	load_easy ("SCI_PARAGRAPH_A", "SCI_A_ONE SCI_A_TWO SCI_A_THREE SCI_A_FOUR");
	load_easy ("SCI_PARAGRAPH_B", "SCI_B_ONE SCI_B_TWO SCI_B_THREE");
	load_easy ("SCI_PARAGRAPH_C", "SCI_C_ONE SCI_C_TWO SCI_C_THREE SCI_C_FOUR");


	load_easy ("SCI_SUBTITLE", "SCI_MOVEMENT SCI_ACT or SCI_MOVEMENT SCI_ACT ?");
	load_easy ("SCI_SUBTITLE", "a SCI_ADJ theory");
	load_easy ("SCI_SUBTITLE", "the SCI_ACT as it relates to TOPIC");
	load_easy ("SCI_SUBTITLE", "SCI_COMPLEXNOUN and SCI_COMPLEXNOUN");

	load_easy ("SCI_A_ONE", "Many SCI_PEOPLE would agree that, had it not been for TOPIC , the SCI_ACT might never have occurred.");
	load_easy ("SCI_A_ONE", "Without TOPIC , the SCI_YEAR SCI_ACT would have been merely a SCI_ADJ fantasy.");
	load_easy ("SCI_A_ONE", "The implications of TOPIC technology have been far-reaching and pervasive, touching all aspects of our lives.");
	load_easy ("SCI_A_ONE", "Although the SCI_ACT by SCI_SOURCE and the SCI_ACT by SCI_SOURCE were both SCI_ADJ discoveries, they would have been nothing without TOPIC .");
	load_easy ("SCI_A_ONE", "Our SCI_ADJ_ADV modern lives are influenced by TOPIC everyday.");
	load_easy ("SCI_A_ONE", "TOPIC technology has led to SCI_ADJ advances in SCI_FIELD , discoveries that today we take for granted.");
	load_easy ("SCI_A_ONE", "Unified TOPIC theory has led to many SCI_ADJ advances, including SCI_THING and SCI_THING .");

	load_easy ("SCI_A_TWO", "Few scientists have been as SCI_ADJ as SCI_SCIENTIST in the development of TOPIC .");
	load_easy ("SCI_A_TWO", "No discussion of TOPIC would be complete without mention of SCI_SCIENTIST .");
	load_easy ("SCI_A_TWO", "Although the contributions of SCI_SOURCE and SCI_SOURCE to TOPIC are well documented, few people realize that it was actually SCI_SCIENTIST who played a leading role in its development.");
	load_easy ("SCI_A_TWO", "Few would argue that SCI_SCIENTIST 's discovery of TOPIC was one of the most important scientific advances of our century.");
	load_easy ("SCI_A_TWO", "No one played as pivotal a role in the development of TOPIC as SCI_SCIENTIST .");
	load_easy ("SCI_A_TWO", "Although the contributions of SCI_SCIENTIST to the worldwide advancement of science are SCI_ADJ , TOPIC is perhaps the most SCI_ADJ of all.");
	load_easy ("SCI_A_TWO", "TOPIC , perhaps one of the most SCI_ADJ advances of our time, would never have occurred had it not been for SCI_SCIENTIST .");

	load_easy ("SCI_A_THREE", "Three points support this thesis: SCI_A_FACT , SCI_A_FACT , and most importantly, SCI_A_FACT .");
	load_easy ("SCI_A_THREE", "Three important discoveries led to the discovery of TOPIC : SCI_THING , SCI_THING , and SCI_THING .");
	load_easy ("SCI_A_THREE", "The evidence points to three main factors: SCI_A_FACT , SCI_THING , and SCI_A_FACT .");

	load_easy ("SCI_A_FOUR", "In this paper, the author will demonstrate the important role played by SCI_SCIENTIST in the development of TOPIC .");
	load_easy ("SCI_A_FOUR", "The author hopes to set the record straight concerning SCI_SCIENTIST 's many contributions to TOPIC .");
	load_easy ("SCI_A_FOUR", "This paper will explore SCI_SCIENTIST 's important relationship with TOPIC .");
	
	load_easy ("SCI_A_FACT", "SCI_SOURCE 's SCI_ACT in SCI_YEAR");
	load_easy ("SCI_A_FACT", "LASTNAME 's relationship with the SCI_COUNTRY SCI_PEOPLE");
	load_easy ("SCI_A_FACT", "the SCI_COMPLEXNOUN of SCI_MOVEMENT theory");
	load_easy ("SCI_A_FACT", "the work of SCI_COUNTRY SCI_PERSON SCI_SOURCE");

	load_easy ("SCI_PARAGRAPH_B_ONE", "SCI_B_LEADIN_A SCI_B_ONE SCI_B_SUPP_ONE SCI_B_SUPP_TWO SCI_B_SUPP_THREE");
	load_easy ("SCI_PARAGRAPH_B_TWO", "SCI_B_LEADIN SCI_B_TWO SCI_B_SUPP_ONE SCI_B_SUPP_TWO SCI_B_SUPP_THREE");
	load_easy ("SCI_PARAGRAPH_B_THREE", "SCI_B_LEADIN_C SCI_B_THREE SCI_B_SUPP_ONE  SCI_B_SUPP_TWO SCI_B_SUPP_THREE");

	load_easy ("SCI_B_LEADIN_A", "To begin with, ");
	load_easy ("SCI_B_LEADIN_A", "First, ");
	load_easy ("SCI_B_LEADIN_A", "Primarily, ");
	load_easy ("SCI_B_LEADIN_A", "For starters, ");

	load_easy ("SCI_B_LEADIN", "But, ");
	load_easy ("SCI_B_LEADIN", "In addition, ");
	load_easy ("SCI_B_LEADIN", "SCI_ADJ_ADV enough, ");
	load_easy ("SCI_B_LEADIN", "Without a doubt, ");
	load_easy ("SCI_B_LEADIN", "In the opinion of SCI_SOURCE , ");
	load_easy ("SCI_B_LEADIN", "Predictably, ");
	load_easy ("SCI_B_LEADIN", "On a smilar note, ");
	load_easy ("SCI_B_LEADIN", "Furthermore, ");
	load_easy ("SCI_B_LEADIN", "By comparison, ");
	load_easy ("SCI_B_LEADIN", "In the opinions of many, ");
	load_easy ("SCI_B_LEADIN", "Certainly, ");
	load_easy ("SCI_B_LEADIN", "In SCI_YEAR , ");

	load_easy ("SCI_B_LEADIN_C", "Finally, ");
	load_easy ("SCI_B_LEADIN_C", "Ultimately, ");
	load_easy ("SCI_B_LEADIN_C", "As a result, ");
	load_easy ("SCI_B_LEADIN_C", "In the end, ");

	load_easy ("SCI_B_ONE", "LASTNAME 's SCI_ADJ discovery of SCI_THING prompted SCI_ADJ inquiry into TOPIC .");
	load_easy ("SCI_B_ONE", "LASTNAME 's initial intent was not so much SCI_ACT , but rather SCI_ACT .");
	load_easy ("SCI_B_ONE", "LASTNAME 's SCI_ADJ discovery of TOPIC was no so much SCI_COMPLEXNOUN as it was SCI_COMPLEXNOUN .");
	load_easy ("SCI_B_ONE", "few would have suspected that LASTNAME 's SCI_ADJ experiments with SCI_THING would lead to TOPIC .");
	load_easy ("SCI_B_ONE", "the idea of TOPIC was a SCI_ADJ joke.");
	load_easy ("SCI_B_ONE", "few scientists in SCI_YEAR were willing to risk their SCI_ADJ reputations on controversial TOPIC research.");
	load_easy ("SCI_B_ONE", "LASTNAME 's interest in TOPIC sprung from a personal, SCI_ADJ sense of duty.");
	
	load_easy ("SCI_B_TWO", "public interest was piqued by the SCI_ADJ possibility of using TOPIC warfare against the SCI_COUNTRY enemy.");
	load_easy ("SCI_B_TWO", "facing the SCI_ADJ attitudes of the scientific community, LASTNAME continued reasearch into TOPIC .");
	load_easy ("SCI_B_TWO", "it wasn't until the SCI_ADJ SCI_ACT in SCI_YEAR that TOPIC research became a possibility.");
	load_easy ("SCI_B_TWO", "no one before LASTNAME had considered combining the SCI_YEAR findings of SCI_SOURCE , who had SCI_VERBED SCI_THING before anyone thought it possible, with TOPIC in such a meaningful way.");
	load_easy ("SCI_B_TWO", "LASTNAME made a SCI_ADJ discovery: TOPIC , it would seem, had SCI_MOVEMENT implications.  This realization was on a par with the SCI_ACT .");
	load_easy ("SCI_B_TWO", "SCI_ADJ success came in SCI_YEAR , when lastname SCI_ACH .");
	load_easy ("SCI_B_TWO", "it was a long, SCI_ADJ time for LASTNAME .");
	load_easy ("SCI_B_TWO", "SCI_SOURCE summed up scientific sentiment in saying, SCI_QUOTE ");

	load_easy ("SCI_B_THREE", "LASTNAME contrinued working despite SCI_ADJ obstacles.");
	load_easy ("SCI_B_THREE", "SCI_SOURCE 's SCI_YEAR paper on SCI_THING provided a SCI_ADJ basis for SCI_COMPLEXNOUN .");
	load_easy ("SCI_B_THREE", "LASTNAME 's TOPIC research soon attracted the government, who were interested in military applications, namely the SCI_ACT .");
	load_easy ("SCI_B_THREE", "it wasn't until the SCI_COUNTRY SCI_PEOPLE SCI_ACH that LASTNAME gained insight into the SCI_COMPLEXNOUN of TOPIC .");
	load_easy ("SCI_B_THREE", "the SCI_ADJ importance of TOPIC was not fully grasped until LASTNAME SCI_ACH in SCI_YEAR .");
	load_easy ("SCI_B_THREE", "LASTNAME 's SCI_ADJ efforts had begun to prove SCI_ADJ .");
	load_easy ("SCI_B_THREE", "LASTNAME became increasingly intrigued by the SCI_ADJ SCI_COMPLEXNOUN of SCI_ACH_PRES .");
	load_easy ("SCI_B_THREE", "LASTNAME is rumored to have said, SCI_QUOTE ");

	load_easy ("SCI_B_SUPP_ONE", "SCI_ADJ developments seemed SCI_ADJ in the wake of recent SCI_COUNTRY TOPIC discoveries.");
	load_easy ("SCI_B_SUPP_ONE", "dismay became relief when LASTNAME succeeded in SCI_ACH_PRES .");
	load_easy ("SCI_B_SUPP_ONE", "further investigation into SCI_THING proved SCI_ADJ .  TOPIC was suggested as a SCI_ADJ alternative.");
	load_easy ("SCI_B_SUPP_ONE", "LASTNAME remained SCI_ADJ_ADV undaunted, claiming SCI_QUOTE ");
	load_easy ("SCI_B_SUPP_ONE", "LASTNAME 's SCI_ADJ thesis was supported by SCI_ADJ SCI_COUNTRY research.");
	load_easy ("SCI_B_SUPP_ONE", "the question of TOPIC 's SCI_ADJ SCI_COMPLEXNOUN still remained to be answered, at least until the SCI_ACT .");
	load_easy ("SCI_B_SUPP_ONE", "LASTNAME 's research posed a SCI_ADJ question: what, indeed was the SCI_COMPLEXNOUN of TOPIC ?");

	load_easy ("SCI_B_SUPP_TWO", "Working closely with the SCI_COUNTRY SCI_PERSON SCI_SOURCE , LASTNAME struggled to define a Unified Theory of TOPIC .");
	load_easy ("SCI_B_SUPP_TWO", "SCI_SOURCE 's SCI_ADJ research into SCI_THING provided a SCI_ADJ touchstone for LASTNAME .");
	load_easy ("SCI_B_SUPP_TWO", "TOPIC 's SCI_ADJ possibilities had never been SCI_VERBED until LASTNAME suggested SCI_ACH_PRES .");
	load_easy ("SCI_B_SUPP_TWO", "LASTNAME 's theory of TOPIC was SCI_ADJ_ADV complete, but futher study still seemed SCI_ADJ if the SCI_ACT was to occurr.");
	load_easy ("SCI_B_SUPP_TWO", "LASTNAME was SCI_ADJ_ADV close to a discovery.");
	load_easy ("SCI_B_SUPP_TWO", "LASTNAME had grasped the SCI_COMPLEXNOUN of TOPIC ; but its SCI_COMPLEXNOUN was still SCI_ADJ_ADV out of reach.");
	load_easy ("SCI_B_SUPP_TWO", "LASTNAME hoped that TOPIC technology might become a SCI_ADJ force for good.");

	load_easy ("SCI_B_SUPP_THREE", "As SCI_SOURCE said of the discovery, SCI_QUOTE ");
	load_easy ("SCI_B_SUPP_THREE", "As SCI_SOURCE once quipped, SCI_QUOTE ");
	load_easy ("SCI_B_SUPP_THREE", "This begs the question: is TOPIC SCI_MOVEMENT in nature?  LASTNAME would say SCI_RESPONSE .");
	load_easy ("SCI_B_SUPP_THREE", "LASTNAME 's SCI_ADJ paper was published later that year.");
	load_easy ("SCI_B_SUPP_THREE", "LASTNAME felt the time was ripe for further exploration, possibly even the SCI_ACT_A SCI_THING .");
	load_easy ("SCI_B_SUPP_THREE", "LASTNAME 's colleagues in SCI_FIELD were intrigued.");

	load_easy ("SCI_C_ONE", "SCI_C_ONE_OPENING , SCI_C_ONE_CLOSING");

	load_easy ("SCI_C_ONE_OPENING", "these days");
	load_easy ("SCI_C_ONE_OPENING", "nowadays");
	load_easy ("SCI_C_ONE_OPENING", "today");
	load_easy ("SCI_C_ONE_OPENING", "as such");
        load_easy ("SCI_C_ONE_OPENING", "as we begin the new millennium");
	load_easy ("SCI_C_ONE_OPENING", "in modern times");
	load_easy ("SCI_C_ONE_OPENING", "in the SCI_ADJ world of the 21st century");
        

	load_easy ("SCI_C_ONE_CLOSING", "we take TOPIC for granted.");
	load_easy ("SCI_C_ONE_CLOSING", "we've come a long way since the early experiments in TOPIC .");
	load_easy ("SCI_C_ONE_CLOSING", "our memories of the pre- TOPIC era have become faded.");
	load_easy ("SCI_C_ONE_CLOSING", "the interest in TOPIC has waned.");
	load_easy ("SCI_C_ONE_CLOSING", "the lessons of TOPIC seem outdated and irrelevant.");
	load_easy ("SCI_C_ONE_CLOSING", "the survivors of TOPIC warfare are growing fewer by the day.");

	load_easy ("SCI_C_TWO", "It's easy to forget that, once, TOPIC was a SCI_ADJ mystery that challenged even the greatest SCI_COUNTRY SCI_PEOPLE .");
	load_easy ("SCI_C_TWO", "But, in reality, the lessons of TOPIC are more relevant than ever.");

	load_easy ("SCI_C_THREE", "Even as late as SCI_YEAR , SCI_SOURCE noted , SCI_QUOTE");
	load_easy ("SCI_C_THREE", "As prominent SCI_PEOPLE like SCI_SOURCE have noted, SCI_QUOTE");

	load_easy ("SCI_C_FOUR", "The world is changing; changing with the help of TOPIC .");
	load_easy ("SCI_C_FOUR", "SCI_ADV we are destined to never truly understand how much we owe to TOPIC .");
	load_easy ("SCI_C_FOUR", "SCI_ADV , the name of SCI_SCIENTIST will be destined to go down in History.");

	load_easy ("SCI_ACT", "SCI_ACT_A SCI_THING");
	load_easy ("SCI_ACT", "SCI_ACT_A SCI_THING that SCI_EFFECT");

	load_easy ("SCI_ACT_A", "discovery of");
	load_easy ("SCI_ACT_A", "invention of");
	load_easy ("SCI_ACT_A", "development of");
	load_easy ("SCI_ACT_A", "understanding of");
	load_easy ("SCI_ACT_A", "conception of");
	load_easy ("SCI_ACT_A", "deployment of");
	load_easy ("SCI_ACT_A", "unification of SCI_THING and");
	load_easy ("SCI_ACT_A", "exploration of");

	load_easy ("SCI_ACH", "SCI_VERBED SCI_THING");
	load_easy ("SCI_ACH", "SCI_VERBED SCI_THING (which SCI_EFFECT )");

	load_easy ("SCI_ACH_PRES", "SCI_VERBING SCI_THING");
	load_easy ("SCI_ACH_PRES", "SCI_VERBING SCI_THING (which SCI_EFFECT )");

	load_easy ("SCI_VERBED", "explored");
	load_easy ("SCI_VERBED", "harnessed");
	load_easy ("SCI_VERBED", "squared");
	load_easy ("SCI_VERBED", "invented");
	load_easy ("SCI_VERBED", "developed");
	load_easy ("SCI_VERBED", "discovered");
	load_easy ("SCI_VERBED", "refined");

	load_easy ("SCI_VERBING", "harnessing");
	load_easy ("SCI_VERBING", "exploring");
	load_easy ("SCI_VERBING", "controlling");
	load_easy ("SCI_VERBING", "squaring");
	load_easy ("SCI_VERBING", "inventing");
	load_easy ("SCI_VERBING", "developing");
	load_easy ("SCI_VERBING", "discovering");
	load_easy ("SCI_VERBING", "refining");

	load_easy ("SCI_THING", "aromatherapy");
	load_easy ("SCI_THING", "chaos theory");
	load_easy ("SCI_THING", "cold fusion");
	load_easy ("SCI_THING", "electromagnetic waves");
	load_easy ("SCI_THING", "Euclidean geometry");
	load_easy ("SCI_THING", "fire");
	load_easy ("SCI_THING", "food dehydration");
	load_easy ("SCI_THING", "gamma-ray radiation");
	load_easy ("SCI_THING", "gender-reassignment therapy");
	load_easy ("SCI_THING", "healing crystals");
	load_easy ("SCI_THING", "Jungian archetypes");
	load_easy ("SCI_THING", "krazy glue");
	load_easy ("SCI_THING", "kryptonite");
	load_easy ("SCI_THING", "laser hair removal technology");
	load_easy ("SCI_THING", "nuclear fission");
	load_easy ("SCI_THING", "silicon semiconductors");
	load_easy ("SCI_THING", "so-called new math");
	load_easy ("SCI_THING", "space-age plastics");
	load_easy ("SCI_THING", "telegraph and radio");
	load_easy ("SCI_THING", "television");
	load_easy ("SCI_THING", "the Commodore VIC-20");
	load_easy ("SCI_THING", "the dilithium warp drive");
	load_easy ("SCI_THING", "the atom");
	load_easy ("SCI_THING", "the H-Bomb");
	load_easy ("SCI_THING", "the id");
	load_easy ("SCI_THING", "the Internet");
	load_easy ("SCI_THING", "the superego");
	load_easy ("SCI_THING", "the transistor");
	load_easy ("SCI_THING", "the UNIVAC computer");
	load_easy ("SCI_THING", "the wheel");
	load_easy ("SCI_THING", "the X-ray");
	load_easy ("SCI_THING", "thermodynamic theory");
	load_easy ("SCI_THING", "wormholes in space");

	load_easy ("SCI_RESPONSE", "yes");
	load_easy ("SCI_RESPONSE", "no");
	load_easy ("SCI_RESPONSE", "it is");
	load_easy ("SCI_RESPONSE", "unlikely");	
	load_easy ("SCI_RESPONSE", "exactly so");
	load_easy ("SCI_RESPONSE", "it is not");
	load_easy ("SCI_RESPONSE", "the answer is yes");
	
	load_easy ("SCI_EFFECT", "made SCI_VERBING and possibly SCI_VERBING TOPIC a reality");
	load_easy ("SCI_EFFECT", "would allow for further study into SCI_THING");
	load_easy ("SCI_EFFECT", "paved the way for the SCI_ACT_A SCI_THING");
	load_easy ("SCI_EFFECT", "would make SCI_VERBING SCI_THING a real possibility");

        load_easy ("SCI_PERSON", "chemist");
        load_easy ("SCI_PERSON", "physicist");
	load_easy ("SCI_PERSON", "astrologer");
	load_easy ("SCI_PERSON", "astrophysicist");
	load_easy ("SCI_PERSON", "biogeneticist");
	load_easy ("SCI_PERSON", "biologist");
	load_easy ("SCI_PERSON", "geologist");
	load_easy ("SCI_PERSON", "mad scientist");
	load_easy ("SCI_PERSON", "nutritionist");
	load_easy ("SCI_PERSON", "psychologist");

        load_easy ("SCI_PEOPLE", "physicists");
	load_easy ("SCI_PEOPLE", "academics");
	load_easy ("SCI_PEOPLE", "astrologers");
	load_easy ("SCI_PEOPLE", "astrologers");	
	load_easy ("SCI_PEOPLE", "astrophysicists");
	load_easy ("SCI_PEOPLE", "biogeneticists");
	load_easy ("SCI_PEOPLE", "biologists");
	load_easy ("SCI_PEOPLE", "chemists");
	load_easy ("SCI_PEOPLE", "geologists");
	load_easy ("SCI_PEOPLE", "mad scientists");
	load_easy ("SCI_PEOPLE", "nutritionists");
	load_easy ("SCI_PEOPLE", "physicists");
	load_easy ("SCI_PEOPLE", "psychologists");
	load_easy ("SCI_PEOPLE", "researchers");

	load_easy ("SCI_FIELD", "archaeology");
	load_easy ("SCI_FIELD", "astrology");
	load_easy ("SCI_FIELD", "astrophysics");
	load_easy ("SCI_FIELD", "biology");
	load_easy ("SCI_FIELD", "chemistry");
	load_easy ("SCI_FIELD", "computer technology");
	load_easy ("SCI_FIELD", "library science");
	load_easy ("SCI_FIELD", "linguistics");
	load_easy ("SCI_FIELD", "medical science");
	load_easy ("SCI_FIELD", "mortuary science");
	load_easy ("SCI_FIELD", "national defense");
	load_easy ("SCI_FIELD", "physics");
	load_easy ("SCI_FIELD", "psychiatry");
	load_easy ("SCI_FIELD", "psychology");
	load_easy ("SCI_FIELD", "sexology");
	load_easy ("SCI_FIELD", "sociology");
	
	load_easy ("SCI_COUNTRY", "American");
	load_easy ("SCI_COUNTRY", "British");
	load_easy ("SCI_COUNTRY", "Canadian");
	load_easy ("SCI_COUNTRY", "French");
	load_easy ("SCI_COUNTRY", "German");
	load_easy ("SCI_COUNTRY", "Italian");
	load_easy ("SCI_COUNTRY", "Japanese");
	load_easy ("SCI_COUNTRY", "Swedish");
	load_easy ("SCI_COUNTRY", "Russian");
	load_easy ("SCI_COUNTRY", "Soviet");

	load_easy ("SCI_ADJ", "SCI_ADJ_ADV important");
	load_easy ("SCI_ADJ", "significant");
	load_easy ("SCI_ADJ", "key");
	load_easy ("SCI_ADJ", "SCI_ADJ_ADV unfortunate");
	load_easy ("SCI_ADJ", "fortuitous");
	load_easy ("SCI_ADJ", "trying");
	load_easy ("SCI_ADJ", "daunting");
	load_easy ("SCI_ADJ", "SCI_ADJ_ADV unbearable");
	load_easy ("SCI_ADJ", "foolish");
	load_easy ("SCI_ADJ", "foolhardy");
	load_easy ("SCI_ADJ", "SCI_ADJ_ADV amusing");
	load_easy ("SCI_ADJ", "disturbing");
	load_easy ("SCI_ADJ", "SCI_ADJ_ADV alarming");
	load_easy ("SCI_ADJ", "confusing");
	load_easy ("SCI_ADJ", "SCI_ADJ_ADV enlightening");
	load_easy ("SCI_ADJ", "SCI_ADJ_ADV inspiring"); 
	load_easy ("SCI_ADJ", "laughable");
	load_easy ("SCI_ADJ", "shocking");
	load_easy ("SCI_ADJ", "SCI_ADJ_ADV annoying");
	load_easy ("SCI_ADJ", "SCI_ADJ_ADV invigorating");
	load_easy ("SCI_ADJ", "celebrated");
	
	load_easy ("SCI_ADJ_ADV", "particularly");
	load_easy ("SCI_ADJ_ADV", "dubiously");
	load_easy ("SCI_ADJ_ADV", "daringly");
	load_easy ("SCI_ADJ_ADV", "shockingly"); 
	load_easy ("SCI_ADJ_ADV", "daringly"); 
	load_easy ("SCI_ADJ_ADV", "famously");
	load_easy ("SCI_ADJ_ADV", "predictably");
	load_easy ("SCI_ADJ_ADV", "clearly");
	load_easy ("SCI_ADJ_ADV", "obviously");

	load_easy ("SCI_ADV", "obviously");
	load_easy ("SCI_ADV", "evidently");
	load_easy ("SCI_ADV", "clearly");
	load_easy ("SCI_ADV", "apparently");
	load_easy ("SCI_ADV", "perhaps");

	load_easy ("SCI_COMPLEXNOUN", "complexity");
	load_easy ("SCI_COMPLEXNOUN", "contradiction");
	load_easy ("SCI_COMPLEXNOUN", "uncertainty");
	load_easy ("SCI_COMPLEXNOUN", "chaos");
	load_easy ("SCI_COMPLEXNOUN", "change");
	load_easy ("SCI_COMPLEXNOUN", "mystery");
	load_easy ("SCI_COMPLEXNOUN", "enigma");
	load_easy ("SCI_COMPLEXNOUN", "paradox");
	load_easy ("SCI_COMPLEXNOUN", "incoherence");
	load_easy ("SCI_COMPLEXNOUN", "simplicity");

	load_easy ("SCI_MOVEMENT", "Einstinian");
	load_easy ("SCI_MOVEMENT", "Newtonian");
	load_easy ("SCI_MOVEMENT", "Euclidean");
	load_easy ("SCI_MOVEMENT", "Freudian");
	load_easy ("SCI_MOVEMENT", "Psychoanalytical");


	load_easy ("SCI_QUOTE", "SCI_QUOTEA SCI_QUOTE_SOURCE SCI_QUOTE_COMMENT");

	load_easy ("SCI_QUOTEA", "\"If anybody says he can think about TOPIC without getting giddy, that only shows he has not understood the first thing about it.\"");
	load_easy ("SCI_QUOTEA", "\" TOPIC increases our power in proportion as it lowers our pride.\"");
	load_easy ("SCI_QUOTEA", "\"In TOPIC the credit goes to the man who convinces the world, not to the man to whom the idea first occurred.\"");
	load_easy ("SCI_QUOTEA", "\"Shall I refuse my dinner because I do not fully understand the process of TOPIC ?\"");
	load_easy ("SCI_QUOTEA", "\"We see only what we know, TOPIC included.\"");
	load_easy ("SCI_QUOTEA", "\"I believe there is no philosophical high-road in TOPIC , with epistemological signposts. No, we are in a jungle and find our way by trial and error, building our road behind us as we proceed.\"");
	load_easy ("SCI_QUOTEA", "\" TOPIC is to see what everybody else has seen, and to think what nobody else has thought.\"");
	load_easy ("SCI_QUOTEA", "\" TOPIC is like an axe in the hands of a pathological criminal.\"");
	load_easy ("SCI_QUOTEA", "\"Happy is he who gets to know the reasons for TOPIC .\"");
	load_easy ("SCI_QUOTEA", "\"True TOPIC teaches us to doubt and, in ignorance, to refrain.\"");

	load_easy ("SCI_QUOTE_COMMENT", " --a truly telling remark.");
        load_easy ("SCI_QUOTE_COMMENT", "This opinion is SCI_ADJ not so much in its SCI_COMPLEXNOUN but in its SCI_ADJ use of SCI_COMPLEXNOUN to explain LASTNAME 's thesis.");
        load_easy ("SCI_QUOTE_COMMENT", "This comment truly captures the view of the SCI_PEOPLE when confronted with TOPIC .");
        load_easy ("SCI_QUOTE_COMMENT", "SCI_ADJ in this quote's SCI_COMPLEXNOUN is the SCI_MOVEMENT sentiment that LASTNAME faced in SCI_YEAR .");
        load_easy ("SCI_QUOTE_COMMENT", "The motive for saying this is SCI_ADJ when one considers that LASTNAME was a SCI_PERSON .");
	load_easy ("SCI_QUOTE_COMMENT", "Immortal words from a SCI_ADJ player in the field of TOPIC .");
	load_easy ("SCI_QUOTE_COMMENT", "Though this was written during SCI_YEAR , it's apparent that SCI_MOVEMENT ideas had begun to influence the TOPIC SCI_PEOPLE .");

	load_easy ("SCI_QUOTE_SOURCE", "( SCI_QUOTE_NAME SCI_QUOTE_NUMBER )");

	load_easy ("SCI_QUOTE_NAME", "Spock");
	load_easy ("SCI_QUOTE_NAME", "Coyne");	
	load_easy ("SCI_QUOTE_NAME", "Rudder");
	load_easy ("SCI_QUOTE_NAME", "Kestler");
	load_easy ("SCI_QUOTE_NAME", "Florman");
	load_easy ("SCI_QUOTE_NAME", "Krohn");
	load_easy ("SCI_QUOTE_NAME", "Yagan");
	load_easy ("SCI_QUOTE_NAME", "Ring");
	load_easy ("SCI_QUOTE_NAME", "Starr");
	load_easy ("SCI_QUOTE_NAME", "Sheckler");
	load_easy ("SCI_QUOTE_NAME", "Kinsey");
	load_easy ("SCI_QUOTE_NAME", "Who");
	load_easy ("SCI_QUOTE_NAME", "Westheimer");
	load_easy ("SCI_QUOTE_NAME", "Brothers");
	load_easy ("SCI_QUOTE_NAME", "Spark");

	load_easy ("SCI_QUOTE_NUMBER", "42");
	load_easy ("SCI_QUOTE_NUMBER", "196");	
	load_easy ("SCI_QUOTE_NUMBER", "3054");
	load_easy ("SCI_QUOTE_NUMBER", "54");
	load_easy ("SCI_QUOTE_NUMBER", "250");
	load_easy ("SCI_QUOTE_NUMBER", "666");

	load_easy ("SCI_SOURCE", "Ada Lovelace");
	load_easy ("SCI_SOURCE", "Alan Turing");
	load_easy ("SCI_SOURCE", "Albert Einstein");
	load_easy ("SCI_SOURCE", "Alexander Graham Bell");
	load_easy ("SCI_SOURCE", "Aristotle");
	load_easy ("SCI_SOURCE", "Benjamin Franklin");
	load_easy ("SCI_SOURCE", "Bill Nye");
	load_easy ("SCI_SOURCE", "Blaise Pascal");
	load_easy ("SCI_SOURCE", "Charles Darwin");
	load_easy ("SCI_SOURCE", "Doctor Who");
	load_easy ("SCI_SOURCE", "Dr. Laura Schlessinger");
	load_easy ("SCI_SOURCE", "Dr. Ruth Westheimer");
	load_easy ("SCI_SOURCE", "Erwin Schroedinger");
	load_easy ("SCI_SOURCE", "Galileo");
	load_easy ("SCI_SOURCE", "George Washington Carver");
	load_easy ("SCI_SOURCE", "Isaac Asimov");
	load_easy ("SCI_SOURCE", "Isaac Newton");
	load_easy ("SCI_SOURCE", "Johannes Kepler");
	load_easy ("SCI_SOURCE", "Leonardo Da Vinci");
	load_easy ("SCI_SOURCE", "Louis Pasteur");
	load_easy ("SCI_SOURCE", "Marie Curie");
	load_easy ("SCI_SOURCE", "Max Planck");
	load_easy ("SCI_SOURCE", "Mr. Spock");
	load_easy ("SCI_SOURCE", "Nicola Tesla");
	load_easy ("SCI_SOURCE", "Noam Chomsky");
	load_easy ("SCI_SOURCE", "Sigmund Freud");
	load_easy ("SCI_SOURCE", "Stephen Hawking");
	load_easy ("SCI_SOURCE", "Timothy Leary");

	load_easy ("SCI_YEAR", "1886");
	load_easy ("SCI_YEAR", "1968");
	load_easy ("SCI_YEAR", "1992");
	load_easy ("SCI_YEAR", "1781");
	load_easy ("SCI_YEAR", "1612");
	load_easy ("SCI_YEAR", "1745");
	load_easy ("SCI_YEAR", "1016 AD");
	load_easy ("SCI_YEAR", "1974");
	load_easy ("SCI_YEAR", "1949");
	load_easy ("SCI_YEAR", "784 BC");






	load_easy ("HISTPAPER_SHORT", "<p> HIST_PARAGRAPH_A <p> HIST_PARAGRAPH_B <p> HIST_PARAGRAPH_C");
	load_easy ("HISTPAPER_LONG", "<p> HIST_PARAGRAPH_A <p> HIST_PARAGRAPH_B_LONG <p> HIST_PARAGRAPH_C");
	
	load_easy ("HIST_PARAGRAPH_B_LONG","HIST_PARAGRAPH_B <p> HIST_PARAGRAPH_B <p> HIST_PARAGRAPH_B <p> HIST_PARAGRAPH_B <p> HIST_PARAGRAPH_B <p> HIST_PARAGRAPH_B <p> HIST_PARAGRAPH_B <p> HIST_PARAGRAPH_B");




	load_easy ("HISTPAPER_TITLE", "TOPIC : HIST_SUBTITLE");
	load_easy ("HISTPAPER_TITLE", "TOPIC and HIST_FACT");


	
	load_easy ("HIST_PARAGRAPH_BODY", "INTROA HIST_PARAGRAPH_B <p> INTROB HIST_PARAGRAPH_B <p> INTROC HIST_PARAGRAPH_B"); 
	load_easy ("HIST_PARAGRAPH_BODY_LONG", "HIST_PARAGRAPH_BODY HIST_PARAGRAPH_BODY HIST_PARAGRAPH_BODY");

	load_easy ("HIST_PARAGRAPH_A", "HIST_A1 HIST_A2 HIST_A3");
	load_easy ("HIST_PARAGRAPH_B", "HIST_B1 HIST_B2 HIST_B3");
	load_easy ("HIST_PARAGRAPH_C", "HIST_C1 HIST_C2 HIST_C3 HIST_C4");


	load_easy ("HIST_SUBTITLE", "HIST_MOVEMENT HIST_ACT or HIST_MOVEMENT HIST_ACT ?");
	load_easy ("HIST_SUBTITLE", "HIST_SOURCE and the HIST_ACT of HIST_YEAR");
	load_easy ("HIST_SUBTITLE", "a HIST_ADJ time");
	load_easy ("HIST_SUBTITLE", "the HIST_ACT of the HIST_PEOPLE");
	load_easy ("HIST_SUBTITLE", "COMPLEXNOUN and COMPLEXNOUN");

	load_easy ("HIST_A1", "Many HIST_SCHOLARS agree that TOPIC is HIST_ADV the most HIST_ADJ event in HIST_NATIONALITY history.");
        load_easy ("HIST_A1", "TOPIC was a HIST_ADJ turning-point in HIST_NATIONALITY history.");
	load_easy ("HIST_A1", "TOPIC is perhaps the most misunderstood point in HIST_NATIONALITY history.");
	load_easy ("HIST_A1", "When studying TOPIC , it is HIST_ADJ to consider the HIST_NATIONALITY perspective on this significant event.");
	load_easy ("HIST_A1", "HIST_QUOTE As HIST_SOURCE said in HIST_YEAR , TOPIC was certainly a HIST_ADJ time full of COMPLEXNOUN and COMPLEXNOUN .");
	load_easy ("HIST_A1", "In HIST_YEAR , HIST_SOURCE had this to say about TOPIC :  HIST_QUOTE");
	load_easy ("HIST_A1", "Perhaps HIST_SOURCE best summed up the HIST_NATIONALITY sentiment toward TOPIC when he said, HIST_QUOTE");

	load_easy ("HIST_A2", "HIST_TRANS it is HIST_ADJ to see that TOPIC was in fact a product of the HIST_MOVEMENT movement and its HIST_NATIONALITY followers.");
	load_easy ("HIST_A2", "HIST_TRANS it became obvious that TOPIC was not nearly as HIST_ADJ as HIST_NATIONALITY  HIST_SCHOLARS would have us believe.");
	load_easy ("HIST_A2", "HIST_TRANS we now know that TOPIC was actually a HIST_ADJ conspiracy by the HIST_NATIONALITY  HIST_PEOPLE in their attempt to distract its citizens from the COMPLEXNOUN of the HIST_MOVEMENT movement.");
	load_easy ("HIST_A2", "While HIST_ADJ HIST_SCHOLARS have called this event HIST_ADJ , I would argue that TOPIC was in fact HIST_ADJ .");

	load_easy ("HIST_TRANS", "Although it was not clear in HIST_YEAR , ");
	load_easy ("HIST_TRANS", "While other HIST_ADJ HIST_SCHOLARS may disagree, ");
	load_easy ("HIST_TRANS", "But after examining the HIST_ADJ evidence, ");

	load_easy ("HIST_A3", "HIST_ANALYSIS : HIST_FACT , HIST_FACT , and HIST_FACT .");

	load_easy ("HIST_ANALYSIS", "This claim is supported by three HIST_ADJ facts");
	load_easy ("HIST_ANALYSIS", "This claim is confirmed by three HIST_ADJ points");

	load_easy ("HIST_FACT", "the HIST_NATIONALITY HIST_ACT of HIST_YEAR");
	load_easy ("HIST_FACT", "the HIST_NATIONALITY HIST_ACT of HIST_YEAR that HIST_EFFECT");
	load_easy ("HIST_FACT", "the HIST_SOURCE HIST_ACT of HIST_YEAR");
	load_easy ("HIST_FACT", "the HIST_SOURCE HIST_ACT of HIST_YEAR that HIST_EFFECT");
	load_easy ("HIST_FACT", "the HIST_MOVEMENT manifesto written by HIST_SOURCE");
	load_easy ("HIST_FACT", "the COMPLEXNOUN present in the HIST_ACT of HIST_YEAR");
	load_easy ("HIST_FACT", "the HIST_NATIONALITY literature of the HIST_MOVEMENT period");

	load_easy ("HIST_B1", "it's important to take into account a HIST_ADJ quote by HIST_SOURCE : HIST_QUOTE HIST_QUOTE_COMMENT");
        load_easy ("HIST_B1", "let us not forget HIST_SOURCE 's feelings on the subject: HIST_QUOTE HIST_QUOTE_COMMENT");
	load_easy ("HIST_B1", "any examination of TOPIC would be incomplete without HIST_SOURCE : HIST_QUOTE HIST_QUOTE_COMMENT");
	load_easy ("HIST_B1", "the HIST_NATIONALITY HIST_ACT of HIST_YEAR had a HIST_ADJ role in TOPIC because, as HIST_SOURCE said, HIST_QUOTE HIST_QUOTE_COMMENT");
	load_easy ("HIST_B1", "in HIST_YEAR a member of a HIST_ADJ group of HIST_NATIONALITY HIST_SCHOLARS wrote: HIST_QUOTE HIST_QUOTE_COMMENT");	
	load_easy ("HIST_B1", "HIST_FACT was HIST_ADJ in TOPIC compared to HIST_FACT .");
	load_easy ("HIST_B1", "HIST_FACT was a HIST_ADJ event that almost rivaled TOPIC in terms of its COMPLEXNOUN .");
	load_easy ("HIST_B1", "TOPIC cannot be truly understood without examination of HIST_FACT .");
	
	load_easy ("HIST_B2", "When we examine HIST_FACT , what is most HIST_ADJ is its COMPLEXNOUN and how that relates to TOPIC .");
	load_easy ("HIST_B2", "Even HIST_SOURCE agrees that HIST_FACT was a direct cause of TOPIC . In HIST_YEAR he said HIST_QUOTE");
	load_easy ("HIST_B2", "The HIST_ADJ reality is that HIST_FACT was caused by TOPIC , a fact well documented by HIST_SOURCE .");
        load_easy ("HIST_B2", "HIST_SOURCE , in spite of his HIST_NATIONALITY allegiances, believed that HIST_FACT and TOPIC were in fact symptoms of the same HIST_MOVEMENT unrest among the HIST_PEOPLE .");
	load_easy ("HIST_B2", "This begs the question, was TOPIC HIST_MOVEMENT ? In HIST_YEAR it was thought that HIST_QUOTE");
	load_easy ("HIST_B2", "Without the HIST_MOVEMENT HIST_ACT it is unlikely that TOPIC would ever have come to fruition.");
	load_easy ("HIST_B2", "Without TOPIC it is unlikely that the HIST_MOVEMENT HIST_ACT would ever have occurred.");
	load_easy ("HIST_B2", "Without TOPIC it is unlikely that the HIST_NATIONALITY HIST_ACT of HIST_YEAR would have been successful.");

	load_easy ("HIST_B3", "HIST_ADV HIST_SCHOLARS recognize that the two are intertwined.");
	load_easy ("HIST_B3", "If HIST_FACT was a HIST_MOVEMENT plot, then obviously TOPIC must have been as well.");	
	load_easy ("HIST_B3", "While HIST_SOURCE believed that TOPIC was caused by the HIST_PEOPLE , this HIST_ADJ evidence points instead to the HIST_PEOPLE .");
	load_easy ("HIST_B3", "Though TOPIC may have been HIST_MOVEMENT , this HIST_ADJ fact was never accepted by the HIST_NATIONALITY HIST_PEOPLE .");
	load_easy ("HIST_B3", "In the opinion of HIST_SOURCE , nothing could ever be as HIST_ADJ as TOPIC .");
	load_easy ("HIST_B3", "HIST_ADV the COMPLEXNOUN in HIST_FACT has been grossly misinterpreted by HIST_SCHOLARS .");
	load_easy ("HIST_B3", "HIST_ADV the role of HIST_MOVEMENT HIST_SCHOLARS in TOPIC has been overrated.");
	load_easy ("HIST_B3", "HIST_ADV HIST_SCHOLARS have marginalized the part of HIST_MOVEMENT in TOPIC .");

	load_easy ("INTROA", "LIT_MIDDLE_ONE");
	load_easy ("INTROB", "Aside from HIST_FACT ,");
	load_easy ("INTROB", "LIT_MIDDLE_TWO");
	load_easy ("INTROB", "LIT_MIDDLE_TWO");
	load_easy ("INTROC", "LIT_MIDDLE_THREE");

	load_easy ("COMPLEXNOUN", "democracy");

	load_easy ("HIST_C1", "HIST_OPENING the days of TOPIC are long over.");
	load_easy ("HIST_C1", "HIST_OPENING we've come a long way since TOPIC .");
	load_easy ("HIST_C1", "HIST_OPENING our memories of TOPIC have become faded.");
	load_easy ("HIST_C1", "HIST_OPENING the influence of TOPIC has waned.");
	load_easy ("HIST_C1", "HIST_OPENING the lessons of TOPIC seem outdated and irrelevant.");
	load_easy ("HIST_C1", "HIST_OPENING the survivors of TOPIC are growing fewer by the day.");

	load_easy ("HIST_C2", "It's easy to forget that, once, TOPIC was a HIST_ADJ force that changed the minds and hearts of the HIST_NATIONALITY HIST_PEOPLE .");
	load_easy ("HIST_C2", "But, in reality, the lessons of TOPIC are more relevant than ever.");

	load_easy ("HIST_C3", "Even as late as HIST_YEAR , HIST_SOURCE noted , HIST_QUOTE");
	load_easy ("HIST_C3", "As prominent HIST_SCHOLARS like HIST_SOURCE have noted, HIST_QUOTE");

	load_easy ("HIST_C4", "The world was changing. Changing, with the help of TOPIC .");
	load_easy ("HIST_C4", "HIST_ADV we are destined to never truly understand how much we owe to TOPIC .");
	load_easy ("HIST_C4", "God bless America.");

	load_easy ("HIST_OPENING", "these days");
	load_easy ("HIST_OPENING", "nowadays");
	load_easy ("HIST_OPENING", "today");
        load_easy ("HIST_OPENING", "as we begin the new millennium");
	load_easy ("HIST_OPENING", "in modern times");
	load_easy ("HIST_OPENING", "in the HIST_ADJ world of the 21st century");        

	load_easy ("HIST_ACT", "War");
	load_easy ("HIST_ACT", "Election");
	load_easy ("HIST_ACT", "Rebellion");
	load_easy ("HIST_ACT", "Revolution");
	load_easy ("HIST_ACT", "Tariff");
	load_easy ("HIST_ACT", "Tax");
	load_easy ("HIST_ACT", "Coup");
	load_easy ("HIST_ACT", "Act");
	load_easy ("HIST_ACT", "Measure");
	load_easy ("HIST_ACT", "Law");      
	load_easy ("HIST_ACT", "Doctrine");
	load_easy ("HIST_ACT", "Declaration");
	load_easy ("HIST_ACT", "Adjustment");
	load_easy ("HIST_ACT", "Invasion");
	load_easy ("HIST_ACT", "Depression");
	load_easy ("HIST_ACT", "Recession");

	load_easy ("HIST_EFFECT", "HIST_EFFECT_NEG");
	load_easy ("HIST_EFFECT", "HIST_EFFECT_POS");

	load_easy ("HIST_EFFECT_POS", "cut off relations with HIST_NATION");
	load_easy ("HIST_EFFECT_POS", "paved the way for the HIST_MOVEMENT HIST_ACT");

	load_easy ("HIST_EFFECT_NEG", "threw HIST_NATION into HIST_NOUN_NEG");
	load_easy ("HIST_EFFECT_NEG", "led HIST_NATION to suppress its HIST_PEOPLE");
	load_easy ("HIST_EFFECT_NEG", "improved relations with the HIST_NATIONALITY HIST_PEOPLE");

        load_easy ("HIST_PEOPLE", "elite");
        load_easy ("HIST_PEOPLE", "lower-class");
        load_easy ("HIST_PEOPLE", "upper-class");
        load_easy ("HIST_PEOPLE", "citizenry");
        load_easy ("HIST_PEOPLE", "populace");
        load_easy ("HIST_PEOPLE", "landed gentry");
        load_easy ("HIST_PEOPLE", "middle class");
        load_easy ("HIST_PEOPLE", "governing-class");
	load_easy ("HIST_PEOPLE", "proletariat");
	load_easy ("HIST_PEOPLE", "bourgeoisie");

	load_easy ("HIST_SCHOLARS", "scholars");
	load_easy ("HIST_SCHOLARS", "historians");
	load_easy ("HIST_SCHOLARS", "academics");
	load_easy ("HIST_SCHOLARS", "historical writers");
	load_easy ("HIST_SCHOLARS", "political scientists");
	load_easy ("HIST_SCHOLARS", "anthropologists");
	load_easy ("HIST_SCHOLARS", "sociologists");	



	load_easy ("HIST_NATION", "America");
	load_easy ("HIST_NATION", "Germany");
	load_easy ("HIST_NATION", "the Soviet Union");
	load_easy ("HIST_NATION", "the U.S.S.R.");
	load_easy ("HIST_NATION", "Japan");
	load_easy ("HIST_NATION", "Rome");
	load_easy ("HIST_NATION", "Greece");
	load_easy ("HIST_NATION", "Egypt");
	load_easy ("HIST_NATION", "Britian");
	load_easy ("HIST_NATION", "England");
	load_easy ("HIST_NATION", "France");
	load_easy ("HIST_NATION", "Ireland");
	load_easy ("HIST_NATION", "China");
	load_easy ("HIST_NATION", "Italy");


	load_easy ("HIST_NATIONALITY", "American");
	load_easy ("HIST_NATIONALITY", "French");
	load_easy ("HIST_NATIONALITY", "Italian");
	load_easy ("HIST_NATIONALITY", "Cuban");
	load_easy ("HIST_NATIONALITY", "Canadian");
	load_easy ("HIST_NATIONALITY", "British");
	load_easy ("HIST_NATIONALITY", "Japanese");
	load_easy ("HIST_NATIONALITY", "German");
	load_easy ("HIST_NATIONALITY", "Roman");
	load_easy ("HIST_NATIONALITY", "Ottoman");
	load_easy ("HIST_NATIONALITY", "Greek");

	load_easy ("HIST_ADJ", "LIT_ADJ_POS");


	load_easy ("HIST_ADV", "particularly");
	load_easy ("HIST_ADV", "very");
	load_easy ("HIST_ADV", "dubiously");
	load_easy ("HIST_ADV", "daringly");
	load_easy ("HIST_ADV", "vehemently"); 
	load_easy ("HIST_ADV", "virulently"); 
	load_easy ("HIST_ADV", "daringly"); 
	load_easy ("HIST_ADV", "famously");
	load_easy ("HIST_ADV", "predictably");
	load_easy ("HIST_ADV", "clearly");
	load_easy ("HIST_ADV", "obviously");

	load_easy ("HIST_ADJ_RHET", "obvious");
	load_easy ("HIST_ADJ_RHET", "evident");
	load_easy ("HIST_ADJ_RHET", "clear");
	load_easy ("HIST_ADJ_RHET", "apparent");
	load_easy ("HIST_ADJ_RHET", "supposed");
	load_easy ("HIST_ADJ_RHET", "presumed");

	load_easy ("HIST_NOUN_NEG", "upheaval");
	load_easy ("HIST_NOUN_NEG", "revolution");
	load_easy ("HIST_NOUN_NEG", "disorder");
	load_easy ("HIST_NOUN_NEG", "depression");
	load_easy ("HIST_NOUN_NEG", "dispute");
	load_easy ("HIST_NOUN_NEG", "ruin");
	load_easy ("HIST_NOUN_NEG", "disrepair");
	load_easy ("HIST_NOUN_NEG", "recession");
	load_easy ("HIST_NOUN_NEG", "chaos");

	load_easy ("HIST_MOVEMENT", "Communism");
	load_easy ("HIST_MOVEMENT", "Socialism");
	load_easy ("HIST_MOVEMENT", "Nationalism");
	load_easy ("HIST_MOVEMENT", "Fascism");
	load_easy ("HIST_MOVEMENT", "Marxism");
	load_easy ("HIST_MOVEMENT", "Maoism");
	load_easy ("HIST_MOVEMENT", "Abolitionism");
	load_easy ("HIST_MOVEMENT", "Anarchism");
	load_easy ("HIST_MOVEMENT", "McCarthyism");	
	load_easy ("HIST_MOVEMENT", "Reaganism");	
	load_easy ("HIST_MOVEMENT", "New Historicism");	
	load_easy ("HIST_MOVEMENT", "Colonialism");	
	load_easy ("HIST_MOVEMENT", "Neo-Nazism");
	load_easy ("HIST_MOVEMENT", "Imperialism");


	load_easy ("HIST_QUOTE", "HIST_QUOTEA HIST_QUOTE_CITE");


	load_easy ("HIST_QUOTEA", "\"History hath triumphed over time, which besides it nothing but eternity hath triumphed over.\"");
	load_easy ("HIST_QUOTEA", "\"While we read history we make history.\"");
	load_easy ("HIST_QUOTEA", "\"Every great crisis of human history is a pass of Thermopylae, and there is always a Leonidas and his three hundred to die in it, if they can not conquer.\"");
	load_easy ("HIST_QUOTEA", "\"War makes rattling good history; but Peace is poor reading.\"");
	load_easy ("HIST_QUOTEA", "\"As the HIST_NATIONALITY HIST_PEOPLE say, there are three sexes,—men, women, and clergymen.\"");
	load_easy ("HIST_QUOTEA", "\"It hath been an opinion that the HIST_NATIONALITY HIST_PEOPLE are wiser than they seem, and the HIST_NATIONALITY HIST_PEOPLE seem wiser than they are; but howsoever it be between nations, certainly it is so in TOPIC .\"");
	load_easy ("HIST_QUOTEA", "\"Nothing succeeds like success.\"");
	load_easy ("HIST_QUOTEA", "\"Like the HIST_NATIONALITY Constitution, TOPIC owed its success in practice to its inconsistencies in principle.\"");
	load_easy ("HIST_QUOTEA", "\"Praise undeserved is scandal in disguise.\"");
	load_easy ("HIST_QUOTEA", "\" TOPIC ought to be the only study of a prince.\"");
	load_easy ("HIST_QUOTEA", "\"To the memory of TOPIC , first in war, first in peace, and first in the hearts of HIST_NATIONALITY countrymen.\"");

        load_easy ("HIST_QUOTE_COMMENT", "How true.");
        load_easy ("HIST_QUOTE_COMMENT", "I could not agree more.");
        load_easy ("HIST_QUOTE_COMMENT", "And how could one not agree?");
        load_easy ("HIST_QUOTE_COMMENT", "In some circles, this caused revolution; in others, revulsion.");
        load_easy ("HIST_QUOTE_COMMENT", "His opinion is HIST_ADJ not so much in its COMPLEXNOUN but in its HIST_ADJ use of COMPLEXNOUN to convey the HIST_MOVEMENT perspective on TOPIC .");
        load_easy ("HIST_QUOTE_COMMENT", "His comment truly captures the view of the HIST_PEOPLE when confronted with TOPIC .");
        load_easy ("HIST_QUOTE_COMMENT", "HIST_ADJ in this quote's COMPLEXNOUN is the HIST_MOVEMENT sentiment that swept over the HIST_NATIONALITY HIST_PEOPLE in HIST_YEAR .");
        load_easy ("HIST_QUOTE_COMMENT", "His motive for saying this is HIST_ADJ when you consider that HIST_SOURCE was a HIST_MOVEMENT .");
	load_easy ("HIST_QUOTE_COMMENT", "Immortal words from a HIST_ADJ player in the delicate balance that was TOPIC .");
	load_easy ("HIST_QUOTE_COMMENT", "Though this was written during the HIST_NATIONALITY HIST_ACT of HIST_YEAR , it is already evident that HIST_MOVEMENT ideals had infiltrated the HIST_ADJ thoughts of HIST_SCHOLARS .");


	load_easy ("HIST_QUOTE_CITE", "( HIST_QUOTE_NAME HIST_QUOTE_PAGE )");

	load_easy ("HIST_QUOTE_NAME", "Smith");
	load_easy ("HIST_QUOTE_NAME", "Washington");	
	load_easy ("HIST_QUOTE_NAME", "Pliny");
	load_easy ("HIST_QUOTE_NAME", "Farrakan");
	load_easy ("HIST_QUOTE_NAME", "Boswell");
	load_easy ("HIST_QUOTE_NAME", "Cromwell");
	load_easy ("HIST_QUOTE_NAME", "Churchill");
	load_easy ("HIST_QUOTE_NAME", "Marx");
	load_easy ("HIST_QUOTE_NAME", "King");
	load_easy ("HIST_QUOTE_NAME", "Gould");
	load_easy ("HIST_QUOTE_NAME", "Herotodus");

	load_easy ("HIST_QUOTE_PAGE", "122");
	load_easy ("HIST_QUOTE_PAGE", "121");	
	load_easy ("HIST_QUOTE_PAGE", "120");
	load_easy ("HIST_QUOTE_PAGE", "119");
	load_easy ("HIST_QUOTE_PAGE", "97");
	load_easy ("HIST_QUOTE_PAGE", "93");
	load_easy ("HIST_QUOTE_PAGE", "92");
	load_easy ("HIST_QUOTE_PAGE", "90");
	load_easy ("HIST_QUOTE_PAGE", "89");
	load_easy ("HIST_QUOTE_PAGE", "88");
	load_easy ("HIST_QUOTE_PAGE", "118");
	load_easy ("HIST_QUOTE_PAGE", "87");
	load_easy ("HIST_QUOTE_PAGE", "84");
	load_easy ("HIST_QUOTE_PAGE", "83");

	load_easy ("HIST_SOURCE", "Mark Twain");
	load_easy ("HIST_SOURCE", "Stephen Jay Gould");
	load_easy ("HIST_SOURCE", "Mao Zedong");
	load_easy ("HIST_SOURCE", "Benjamin Franklin");
	load_easy ("HIST_SOURCE", "John Lennon");
	load_easy ("HIST_SOURCE", "Noam Chomsky");
	load_easy ("HIST_SOURCE", "Abraham Lincoln");
	load_easy ("HIST_SOURCE", "Fidel Castro");
	load_easy ("HIST_SOURCE", "Winston Churchill");
	load_easy ("HIST_SOURCE", "James Madison");
	load_easy ("HIST_SOURCE", "John Quincy Adams");
	load_easy ("HIST_SOURCE", "Mikhail Gorbachev");
	load_easy ("HIST_SOURCE", "Thomas More");
	load_easy ("HIST_SOURCE", "Marcus Aurelius");
	load_easy ("HIST_SOURCE", "Aristotle");
	load_easy ("HIST_SOURCE", "Karl Marx");

	load_easy ("HIST_YEAR", "1944");
	load_easy ("HIST_YEAR", "1945");
	load_easy ("HIST_YEAR", "1968");
	load_easy ("HIST_YEAR", "1991");
	load_easy ("HIST_YEAR", "1789");
	load_easy ("HIST_YEAR", "1492");
	load_easy ("HIST_YEAR", "1943");
	load_easy ("HIST_YEAR", "1918");
	load_easy ("HIST_YEAR", "1917");
	load_easy ("HIST_YEAR", "1916");
	load_easy ("HIST_YEAR", "1915");
	load_easy ("HIST_YEAR", "1914");
	load_easy ("HIST_YEAR", "1913");
	load_easy ("HIST_YEAR", "1940");
	load_easy ("HIST_YEAR", "1941");
	load_easy ("HIST_YEAR", "1942");
	load_easy ("HIST_YEAR", "1972");
	load_easy ("HIST_YEAR", "1945");
	load_easy ("HIST_YEAR", "1775");
	load_easy ("HIST_YEAR", "1776");
	load_easy ("HIST_YEAR", "1777");
	load_easy ("HIST_YEAR", "1778");
	load_easy ("HIST_YEAR", "1779");
	load_easy ("HIST_YEAR", "1780");
	load_easy ("HIST_YEAR", "1781");
	load_easy ("HIST_YEAR", "1789");
	load_easy ("HIST_YEAR", "1791");





}

