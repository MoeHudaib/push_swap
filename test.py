import random
import subprocess

def run_push_swap(test_numbers):
    """Run push_swap with test_numbers and return number of moves."""
    # Convert list of ints to strings
    args = list(map(str, test_numbers))

    try:
        # Run push_swap and pipe to wc -l equivalent in Python
        process = subprocess.Popen(
            ["./push_swap"] + args,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE
        )
        output, error = process.communicate()

        if process.returncode != 0:
            print("Error running push_swap:", error.decode())
            return None

        # Count lines (moves)
        moves = output.decode().strip().split("\n")
        return len([m for m in moves if m])  # filter empty lines

    except Exception as e:
        print("Execution failed:", e)
        return None


def main():
    max_moves = 0
    best_case = []

    num_tests = 5000  # adjust this for more runs
    for i in range(num_tests):
        # Generate a random permutation of 1..100
        numbers = random.sample(range(1, 501), 500)
        
        moves = run_push_swap(numbers)
        if moves is not None:
            print(f"Test {i+1}: {moves} moves")
            if moves > max_moves:
                max_moves = moves
                best_case = numbers

    print("\nMaximum moves observed:", max_moves)
    print("Case producing max moves:", best_case)


if __name__ == "__main__":
    main()

