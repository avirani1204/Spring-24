#include "functions.hpp"

#include <iostream>
#include <stdexcept>

/**
 * TODO: Implement this function
 * @param word word to change to lowercase
 * @return result of changing every character in word to lowercase
 */
std::string StringToLower(const std::string& word) {
  std::string output = word;
  for (size_t i = 0; i < output.size(); i++) {
    output.at(i) = std::tolower(output.at(i));
  }
  return output;
}

/**
 * TODO: Implement this function
 * @param v1 first character in potential vowel group
 * @param v2 second character in potential vowel group
 * @return true if v1 and v2 form a valid vowel group
 */

// make different strings for each vowel group and then check
// i
bool IsVowelGroup(const char& v1, const char& v2) {
  if (v1 == 'a' && v2 == 'i') {
    return true;
  }
  if (v1 == 'a' && v2 == 'e') {
    return true;
  }
  if (v1 == 'a' && v2 == 'o') {
    return true;
  }
  if (v1 == 'a' && v2 == 'u') {
    return true;
  }
  if (v1 == 'e' && v2 == 'i') {
    return true;
  }
  if (v1 == 'e' && v2 == 'u') {
    return true;
  }
  if (v1 == 'i' && v2 == 'u') {
    return true;
  }
  if (v1 == 'o' && v2 == 'i') {
    return true;
  }
  if (v1 == 'o' && v2 == 'u') {
    return true;
  }
  if (v1 == 'u' && v2 == 'i') {
    return true;
  }
  return false;
}

/**
 * TODO: Complete this function
 * @param v potential vowel character
 * @return true if v is a vowel
 */
bool IsVowel(const char& v) {
  return (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u');
}

/**
 * TODO: Complete this function
 * @param c potential consonant character
 * @return true if c is a consonant
 */
// use the valid consonants only
bool IsConsonant(const char& c) {
  return (!IsVowel(c) && ((c == 'p' || c == 'k' || c == 'h' || c == 'l' ||
                           c == 'm' || c == 'n' || c == 'w') &&
                          c != ' '));
}

/**
 * TODO: Implement this function
 * @param c character to check validity of
 * @return true if input c is a valid character in the Hawaiian
 * language, false otherwise
 */

// valid characters : a, e, i, o, u, p, k, h, l, m, n, and w
bool IsValidCharacter(const char& c) {
  std::string valid_chs = "aeioupkhlmnw' ";
  for (size_t i = 0; i < valid_chs.size(); i++) {
    if (c == valid_chs.at(i)) {
      return true;
    }
  }
  return false;
}

/**
* TODO: Implement this function
* @param word word to check validity of
* @return true if every character in word is a valid character
in the
* Hawaiian language, false otherwise
*/
bool IsValidWord(const std::string& word) {
  for (const char& c : word) {
    if (!IsValidCharacter(c)) {
      return false;
    }
  }
  return true;
}

/**
 * TODO: Implement this function
 * @param c consonant to get pronunciation of
 * @param prev character before c, used for determining w translation
 *    set to null character as default if no value is passed in
 * @return pronunciation of the consonant c as a char
 */
char ConsonantPronunciation(const char& c, const char& prev) {
  if (c == 'w') {
    if (prev == 'a' || prev == 'u' || prev == 'o') {
      return 'w';
    }
    if (prev == 'i' || prev == 'e') {
      return 'v';
    }
  }
  return c;
}

/**
 * TODO: Implement this function
 * @param v1 first vowel in a vowel grouping
 * @param v2 second vowel in a vowel grouping
 * @return the pronunciation of the vowel grouping made up of v1 and v2
 * as a string
 */
std::string VowelGroupPronunciation(const char& v1, const char& v2) {
  std::string pronunc;
  if (v1 == 'a' && (v2 == 'i' || v2 == 'e')) {
    pronunc = "eye";
  } else if ((v1 == 'a' && (v2 == 'u' || v2 == 'o')) ||
             (v1 == 'o' && v2 == 'u')) {
    pronunc = "ow";
  } else if (v1 == 'e' && v2 == 'u') {
    pronunc = "eh-oo";
  } else if (v1 == 'e' && v2 == 'i') {
    pronunc = "ay";
  } else if (v1 == 'i' && v2 == 'u') {
    pronunc = "ew";
  } else if (v1 == 'u' && v2 == 'i') {
    pronunc = "ooey";
  } else if (v1 == 'o' && v2 == 'i') {
    pronunc = "oy";
  }
  return pronunc;
}

/**
 * TODO: Implement this function
 * @param v single vowel to get pronunciation of
 * @return the pronunciation of v as a string
 */
std::string SingleVowelPronunciation(const char& v) {
  std::string pronunc;
  if (v == 'a') {
    pronunc = "ah";
  } else if (v == 'e') {
    pronunc = "eh";
  } else if (v == 'i') {
    pronunc = "ee";
  } else if (v == 'o') {
    pronunc = "oh";
  } else if (v == 'u') {
    pronunc = "oo";
  }
  return pronunc;
}

/**
 * TODO: Implement this function
 * @param prev first character in set of three passed to function
 * @param curr second character in set of three passed to function
 * @param next third character in set of three passed to function
 * @return pronunciation of curr using next and prev as needed to determine
 * result
 */
std::string ProcessCharacter(const char& prev,
                             const char& curr,
                             const char& next) {
  std::string pronunc;
  if (IsVowel(curr)) {
    if (IsVowel(next) && IsVowelGroup(curr, next)) {
      pronunc = VowelGroupPronunciation(curr, next);
    } else {
      pronunc = SingleVowelPronunciation(curr);
    }
  } else if (IsConsonant(curr)) {
    pronunc += ConsonantPronunciation(curr, prev);
  } else if (curr == ' ') {
    pronunc = " ";
  } else if (curr == '\'') {
    pronunc = "\'";
  }
  return pronunc;
}

/**
 * TODO: Implement this function
 * @param word string to get pronunciation of
 * @return pronunciation of word
 */
// This function takes in a valid lowercase string (word) and returns the
// pronunciation of the input word in the Hawaiian language as a string,
// including dashes.

std::string Pronunciation(const std::string& word) {
  std::string pronunciation;
  for (size_t i = 0; i < word.size(); i++) {
    char prev = '\0';
    if (i == 0) {
      prev = '\0';
    } else {
      prev = word.at(i - 1);
    }
    char curr = word.at(i);
    char next = '\0';
    if (i == word.size() - 1) {
      next = '\0';
    } else {
      next = word.at(i + 1);
    }
    pronunciation += ProcessCharacter(prev, curr, next);
    if (IsVowelGroup(curr, next)) {
      if (i != word.size() - 2) {
        pronunciation += "-";
      }
      i++;
    } else if (IsVowel(curr)) {
      if (i != word.size() - 1) {
        pronunciation += "-";
      }
    } else if (curr == ' ' || curr == '\'') {
      pronunciation.pop_back();
      if (pronunciation.at(pronunciation.size() - 1) == '-') {
        pronunciation.at(pronunciation.size() - 1) = curr;
      }
    }
  }

  return pronunciation;
}

// if (pronunciation.at(pronunciation.size() - 1) == '-') {
// pronunciation.pop_back();
//}
// if (pronunciation[pronunciation.size() - 1] == '\'') {
// pronunciation.pop_back();
//}

/**
 * TODO: Implement this function
 * @param hawaiian_word word to get pronunciation of
 * @return the pronunciation of hawaiian_word as a string if valid
 *  and throws an invalid_argument error if not valid
 */
std::string GetPronunciation(const std::string& hawaiian_word) {
  // make words to lowercase -- call to Lower Case
  std::string updated_word = StringToLower(hawaiian_word);
  if (!IsValidWord(updated_word)) {
    throw std::invalid_argument("Invalid argument exception");
  }
  return Pronunciation(updated_word);
}