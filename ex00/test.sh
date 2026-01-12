#!/bin/bash

PROGRAM="./convert"

YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

TOTAL=0

if [ ! -f "$PROGRAM" ]; then
    echo -e "${RED}Erreur: $PROGRAM doesn't exist${NC}"
    echo "Compile with make"
    exit 1
fi

if [ ! -x "$PROGRAM" ]; then
    echo -e "${RED}Erreur: $PROGRAM isn't executable${NC}"
    exit 1
fi

print_section() {
    echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
}

test_contains() {
    local test_name="$1"
    local input="$2"

    TOTAL=$((TOTAL + 1))

    actual=$($PROGRAM "$input" 2>&1)
 
    echo -e "[$YELLOW Test $TOTAL: $test_name $NC]\n"
	echo -e "input: '$input'\n"
    echo -e "$actual\n"
	echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
}

print_section "Tests Chars"

test_contains "Char 'a'" "a"
test_contains "Char 'Z'" "Z"
test_contains "Char non displayable" "$(printf '\x01')"

print_section "Tests Ints"

test_contains "Int 0" "0"
test_contains "Int 42" "42"
test_contains "Int negativ" "-42"
test_contains "Int max" "2147483647"
test_contains "Int min" "-2147483648"

print_section "Tests Floats"

test_contains "Float 42.0f" "42.0f"
test_contains "Float 42.42f" "42.42f"
test_contains "Float negativ" "-42.42f"
test_contains "Float 0.0f" "0.0f"
test_contains "Float big nbr" "999999999999999.7f"

print_section "Tests Doubles"

test_contains "Double 42.0" "42.0"
test_contains "Double 42.42" "42.42"
test_contains "Double negativ" "-42.42"
test_contains "double 0.0" "0.0"
test_contains "double big nbr" "999999999999999.7"

print_section "Tests Non_numbers"

test_contains "nan" "nan"
test_contains "nanf" "nanf"
test_contains "+inf" "+inf"
test_contains "-inf" "-inf"
test_contains "+inff" "+inff"
test_contains "-inff" "-inff"

print_section "Tests Edge cases"

test_contains "Overflow int" "2147483648"
test_contains "Overflow int from float" "2147483648.0f"
test_contains "Overflow int from double" "2147483648.0"
test_contains "Overflow float" "350000000000000000000000000000000000000.f"
test_contains "Overflow float from double conversion" "350000000000000000000000000000000000000."
test_contains "Char out of bound (pos)" "200"
test_contains "Char out of boynd (neg)" "-200"
test_contains "Empty string" ""
test_contains "Dot only" "."

print_section "Tests Invalid inputs"

test_contains "String invalid" "abc"
test_contains "Multiple points" "42..0"
test_contains "f not last" "f42.0"
test_contains "Double f" "42.0ff"
test_contains "Minus dot " "-."
test_contains "Space" "42.0f 1"

echo ""
