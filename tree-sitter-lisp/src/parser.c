#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 10
#define STATE_COUNT 20
#define SYMBOL_COUNT 19
#define ALIAS_COUNT 0
#define TOKEN_COUNT 10
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 4

enum {
  anon_sym_LPAREN = 1,
  anon_sym_RPAREN = 2,
  anon_sym_LBRACK = 3,
  anon_sym_RBRACK = 4,
  sym_identifier = 5,
  sym_number = 6,
  sym_string_escape = 7,
  sym_string_content = 8,
  anon_sym_DQUOTE = 9,
  sym_source_file = 10,
  sym__statement = 11,
  sym_call_definition = 12,
  sym_list_definition = 13,
  sym__string_contents = 14,
  sym_string = 15,
  aux_sym_source_file_repeat1 = 16,
  aux_sym_call_definition_repeat1 = 17,
  aux_sym_string_repeat1 = 18,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_identifier] = "identifier",
  [sym_number] = "number",
  [sym_string_escape] = "string_escape",
  [sym_string_content] = "string_content",
  [anon_sym_DQUOTE] = "\"",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym_call_definition] = "call_definition",
  [sym_list_definition] = "list_definition",
  [sym__string_contents] = "_string_contents",
  [sym_string] = "string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_call_definition_repeat1] = "call_definition_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_string_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_string_content] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_call_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_list_definition] = {
    .visible = true,
    .named = true,
  },
  [sym__string_contents] = {
    .visible = false,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_call_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_fn = 1,
  field_items = 2,
};

static const char *ts_field_names[] = {
  [0] = NULL,
  [field_fn] = "fn",
  [field_items] = "items",
};

static const TSFieldMapSlice ts_field_map_slices[] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_fn, 1},
  [1] =
    {field_fn, 1},
    {field_items, 2},
  [3] =
    {field_items, 1},
};

static TSSymbol ts_alias_sequences[4][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (lookahead == 0) ADVANCE(4);
      if (lookahead == '"') ADVANCE(14);
      if (lookahead == '(') ADVANCE(5);
      if (lookahead == ')') ADVANCE(6);
      if (lookahead == '[') ADVANCE(7);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == ']') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      if (lookahead == '!' ||
          lookahead == '+' ||
          lookahead == '-' ||
          lookahead == '/' ||
          lookahead == '<' ||
          ('>' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(14);
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 2:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == '"' ||
          ('0' <= lookahead && lookahead <= '9') ||
          lookahead == '\\' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '!' ||
          lookahead == '+' ||
          lookahead == '-' ||
          ('/' <= lookahead && lookahead <= '9') ||
          lookahead == '<' ||
          ('>' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '\'') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_string_escape);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_string_content);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(13);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_string_content);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
};

static uint16_t ts_parse_table[STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_string_escape] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(19),
    [sym_call_definition] = STATE(16),
    [aux_sym_source_file_repeat1] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
  [2] = {
    [sym__statement] = STATE(2),
    [sym_call_definition] = STATE(2),
    [sym_list_definition] = STATE(2),
    [sym_string] = STATE(2),
    [aux_sym_call_definition_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(7),
    [anon_sym_RPAREN] = ACTIONS(10),
    [anon_sym_LBRACK] = ACTIONS(12),
    [anon_sym_RBRACK] = ACTIONS(10),
    [sym_identifier] = ACTIONS(15),
    [sym_number] = ACTIONS(15),
    [anon_sym_DQUOTE] = ACTIONS(18),
  },
  [3] = {
    [sym__statement] = STATE(5),
    [sym_call_definition] = STATE(5),
    [sym_list_definition] = STATE(5),
    [sym_string] = STATE(5),
    [aux_sym_call_definition_repeat1] = STATE(5),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_RPAREN] = ACTIONS(21),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_identifier] = ACTIONS(25),
    [sym_number] = ACTIONS(25),
    [anon_sym_DQUOTE] = ACTIONS(27),
  },
  [4] = {
    [sym__statement] = STATE(6),
    [sym_call_definition] = STATE(6),
    [sym_list_definition] = STATE(6),
    [sym_string] = STATE(6),
    [aux_sym_call_definition_repeat1] = STATE(6),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_LBRACK] = ACTIONS(23),
    [anon_sym_RBRACK] = ACTIONS(29),
    [sym_identifier] = ACTIONS(31),
    [sym_number] = ACTIONS(31),
    [anon_sym_DQUOTE] = ACTIONS(27),
  },
  [5] = {
    [sym__statement] = STATE(2),
    [sym_call_definition] = STATE(2),
    [sym_list_definition] = STATE(2),
    [sym_string] = STATE(2),
    [aux_sym_call_definition_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_RPAREN] = ACTIONS(33),
    [anon_sym_LBRACK] = ACTIONS(23),
    [sym_identifier] = ACTIONS(35),
    [sym_number] = ACTIONS(35),
    [anon_sym_DQUOTE] = ACTIONS(27),
  },
  [6] = {
    [sym__statement] = STATE(2),
    [sym_call_definition] = STATE(2),
    [sym_list_definition] = STATE(2),
    [sym_string] = STATE(2),
    [aux_sym_call_definition_repeat1] = STATE(2),
    [anon_sym_LPAREN] = ACTIONS(5),
    [anon_sym_LBRACK] = ACTIONS(23),
    [anon_sym_RBRACK] = ACTIONS(37),
    [sym_identifier] = ACTIONS(35),
    [sym_number] = ACTIONS(35),
    [anon_sym_DQUOTE] = ACTIONS(27),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [anon_sym_LPAREN] = ACTIONS(39),
    [anon_sym_RPAREN] = ACTIONS(39),
    [anon_sym_LBRACK] = ACTIONS(39),
    [anon_sym_RBRACK] = ACTIONS(39),
    [sym_identifier] = ACTIONS(39),
    [sym_number] = ACTIONS(39),
    [anon_sym_DQUOTE] = ACTIONS(39),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(41),
    [anon_sym_LPAREN] = ACTIONS(41),
    [anon_sym_RPAREN] = ACTIONS(41),
    [anon_sym_LBRACK] = ACTIONS(41),
    [anon_sym_RBRACK] = ACTIONS(41),
    [sym_identifier] = ACTIONS(41),
    [sym_number] = ACTIONS(41),
    [anon_sym_DQUOTE] = ACTIONS(41),
  },
  [9] = {
    [anon_sym_LPAREN] = ACTIONS(43),
    [anon_sym_RPAREN] = ACTIONS(43),
    [anon_sym_LBRACK] = ACTIONS(43),
    [anon_sym_RBRACK] = ACTIONS(43),
    [sym_identifier] = ACTIONS(43),
    [sym_number] = ACTIONS(43),
    [anon_sym_DQUOTE] = ACTIONS(43),
  },
  [10] = {
    [anon_sym_LPAREN] = ACTIONS(45),
    [anon_sym_RPAREN] = ACTIONS(45),
    [anon_sym_LBRACK] = ACTIONS(45),
    [anon_sym_RBRACK] = ACTIONS(45),
    [sym_identifier] = ACTIONS(45),
    [sym_number] = ACTIONS(45),
    [anon_sym_DQUOTE] = ACTIONS(45),
  },
  [11] = {
    [anon_sym_LPAREN] = ACTIONS(47),
    [anon_sym_RPAREN] = ACTIONS(47),
    [anon_sym_LBRACK] = ACTIONS(47),
    [anon_sym_RBRACK] = ACTIONS(47),
    [sym_identifier] = ACTIONS(47),
    [sym_number] = ACTIONS(47),
    [anon_sym_DQUOTE] = ACTIONS(47),
  },
  [12] = {
    [anon_sym_LPAREN] = ACTIONS(49),
    [anon_sym_RPAREN] = ACTIONS(49),
    [anon_sym_LBRACK] = ACTIONS(49),
    [anon_sym_RBRACK] = ACTIONS(49),
    [sym_identifier] = ACTIONS(49),
    [sym_number] = ACTIONS(49),
    [anon_sym_DQUOTE] = ACTIONS(49),
  },
  [13] = {
    [sym__string_contents] = STATE(14),
    [aux_sym_string_repeat1] = STATE(14),
    [sym_string_escape] = ACTIONS(51),
    [sym_string_content] = ACTIONS(53),
    [anon_sym_DQUOTE] = ACTIONS(55),
  },
  [14] = {
    [sym__string_contents] = STATE(15),
    [aux_sym_string_repeat1] = STATE(15),
    [sym_string_escape] = ACTIONS(57),
    [sym_string_content] = ACTIONS(59),
    [anon_sym_DQUOTE] = ACTIONS(61),
  },
  [15] = {
    [sym__string_contents] = STATE(15),
    [aux_sym_string_repeat1] = STATE(15),
    [sym_string_escape] = ACTIONS(63),
    [sym_string_content] = ACTIONS(66),
    [anon_sym_DQUOTE] = ACTIONS(69),
  },
  [16] = {
    [sym_call_definition] = STATE(17),
    [aux_sym_source_file_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(71),
    [anon_sym_LPAREN] = ACTIONS(5),
  },
  [17] = {
    [sym_call_definition] = STATE(17),
    [aux_sym_source_file_repeat1] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(73),
    [anon_sym_LPAREN] = ACTIONS(75),
  },
  [18] = {
    [sym_identifier] = ACTIONS(78),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(80),
  },
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.count = 0, .reusable = false},
  [1] = {.count = 1, .reusable = false}, RECOVER(),
  [3] = {.count = 1, .reusable = true}, REDUCE(sym_source_file, 0),
  [5] = {.count = 1, .reusable = true}, SHIFT(18),
  [7] = {.count = 2, .reusable = true}, REDUCE(aux_sym_call_definition_repeat1, 2), SHIFT_REPEAT(18),
  [10] = {.count = 1, .reusable = true}, REDUCE(aux_sym_call_definition_repeat1, 2),
  [12] = {.count = 2, .reusable = true}, REDUCE(aux_sym_call_definition_repeat1, 2), SHIFT_REPEAT(4),
  [15] = {.count = 2, .reusable = true}, REDUCE(aux_sym_call_definition_repeat1, 2), SHIFT_REPEAT(2),
  [18] = {.count = 2, .reusable = true}, REDUCE(aux_sym_call_definition_repeat1, 2), SHIFT_REPEAT(13),
  [21] = {.count = 1, .reusable = true}, SHIFT(7),
  [23] = {.count = 1, .reusable = true}, SHIFT(4),
  [25] = {.count = 1, .reusable = true}, SHIFT(5),
  [27] = {.count = 1, .reusable = true}, SHIFT(13),
  [29] = {.count = 1, .reusable = true}, SHIFT(9),
  [31] = {.count = 1, .reusable = true}, SHIFT(6),
  [33] = {.count = 1, .reusable = true}, SHIFT(8),
  [35] = {.count = 1, .reusable = true}, SHIFT(2),
  [37] = {.count = 1, .reusable = true}, SHIFT(11),
  [39] = {.count = 1, .reusable = true}, REDUCE(sym_call_definition, 3, .production_id = 1),
  [41] = {.count = 1, .reusable = true}, REDUCE(sym_call_definition, 4, .production_id = 2),
  [43] = {.count = 1, .reusable = true}, REDUCE(sym_list_definition, 2),
  [45] = {.count = 1, .reusable = true}, REDUCE(sym_string, 2),
  [47] = {.count = 1, .reusable = true}, REDUCE(sym_list_definition, 3, .production_id = 3),
  [49] = {.count = 1, .reusable = true}, REDUCE(sym_string, 3),
  [51] = {.count = 1, .reusable = false}, SHIFT(14),
  [53] = {.count = 1, .reusable = true}, SHIFT(14),
  [55] = {.count = 1, .reusable = false}, SHIFT(10),
  [57] = {.count = 1, .reusable = false}, SHIFT(15),
  [59] = {.count = 1, .reusable = true}, SHIFT(15),
  [61] = {.count = 1, .reusable = false}, SHIFT(12),
  [63] = {.count = 2, .reusable = false}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(15),
  [66] = {.count = 2, .reusable = true}, REDUCE(aux_sym_string_repeat1, 2), SHIFT_REPEAT(15),
  [69] = {.count = 1, .reusable = false}, REDUCE(aux_sym_string_repeat1, 2),
  [71] = {.count = 1, .reusable = true}, REDUCE(sym_source_file, 1),
  [73] = {.count = 1, .reusable = true}, REDUCE(aux_sym_source_file_repeat1, 2),
  [75] = {.count = 2, .reusable = true}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(18),
  [78] = {.count = 1, .reusable = true}, SHIFT(3),
  [80] = {.count = 1, .reusable = true},  ACCEPT_INPUT(),
};

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_lisp(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .field_names = ts_field_names,
    .field_map_slices = (const TSFieldMapSlice *)ts_field_map_slices,
    .field_map_entries = (const TSFieldMapEntry *)ts_field_map_entries,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
