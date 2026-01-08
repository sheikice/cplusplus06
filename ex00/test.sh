#!/bin/bash

PROGRAM="./convert"

RED='\033[0;31m'
GREEN='\033[0;32m'
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
    echo ""
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
}

test_output() {
    local test_name="$1"
    local input="$2"

    TOTAL=$((TOTAL + 1))


    if [ "$input" == "NO_ARG" ]; then
        actual=$($PROGRAM 2>&1)
    else
        actual=$($PROGRAM "$input" 2>&1)
    fi
    echo -e "${RED}✗${NC} Test $TOTAL: $test_name"
    echo "  Input: '$input'"
    echo "Got: $actual" | sed 's/^/    /'
}

test_contains() {
    local test_name="$1"
    local input="$2"

    TOTAL=$((TOTAL + 1))

    actual=$($PROGRAM "$input" 2>&1)
 
    echo -e "[$YELLOW Test $TOTAL: $test_name $NC]"
    echo ""
	echo "input: '$input'"
    echo ""
    echo "$actual" | sed 's/^/    /'
	echo "--------------------------------------------------------"
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

print_section "Tests Doubles"

test_contains "Double 42.0" "42.0"
test_contains "Double 42.42" "42.42"
test_contains "Double negativ" "-42.42"

print_section "Tests Non_numbers"

test_contains "nan" "nan"
test_contains "nan - float" "nan"
test_contains "nanf" "nanf"
test_contains "+inf" "+inf"
test_contains "-inf" "-inf"
test_contains "+inff" "+inff"
test_contains "-inff" "-inff"

print_section "Tests Edge cases"

test_contains "Overflow int" "2147483648"
test_contains "Underflow int" "-2147483649"
test_contains "Char hors limites (pos)" "200"
test_contains "Char hors limites (neg)" "-200"
test_contains "String vide" ""
test_contains "Point seul" "."

print_section "Tests Invalid inputs"

test_contains "String invalid" "abc"
test_contains "Multiple points" "42..0"
test_contains "f not last" "f42.0"
test_contains "Double f" "42.0ff"
test_contains "Minus dot " "-."
test_contains "Space" "42.0f 1"

echo ""
echo "Total:  $TOTAL tests"
echo ""
