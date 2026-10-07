#include <iostream>   // Include iostream for input/output operations
#include <string>     // Include string for using std::string
using namespace std;  // Use the standard namespace

// Structure representing a task node in the circular linked list
struct Job {
    int jobCode;          // Unique identifier for the job/task
    string jobPhase;      // Current phase/state of the job
    Job* nextJob;         // Pointer to the next job in the circular list
    // Constructor to initialize a job with code and phase
    Job(int c, string p) : jobCode(c), jobPhase(p), nextJob(NULL) {}
};

Job* firstJob = NULL;     // Pointer to the first job (head) of the circular list
Job* lastJob = NULL;      // Pointer to the last job (tail) of the circular list
int jobTotal = 0;         // Counter to track the number of jobs currently in the list

// Function to advance a job's phase to the next stage in the workflow
string movePhaseForward(string phaseNow) {
    if (phaseNow == "pending")     return "waiting";       // pending -> waiting
    if (phaseNow == "waiting")     return "ready";         // waiting -> ready
    if (phaseNow == "ready")       return "in-progress";   // ready -> in-progress
    if (phaseNow == "in-progress") return "completed";     // in-progress -> completed
    return "completed";                                    // default fallback
}

// Function to age (advance phase of) all existing jobs by one step
void ageEveryJob() {
    if (firstJob == NULL) return;        // If list is empty, do nothing
    Job* walker = firstJob;              // Start from the first job
    do {
        walker->jobPhase = movePhaseForward(walker->jobPhase); // Advance this job's phase
        walker = walker->nextJob;        // Move to next job
    } while (walker != firstJob);        // Stop when we loop back to first
}

// Function to add a new job to the circular list
void insertJob(int incomingCode) {
    // STEP 1: Age all existing jobs before adding a new one
    ageEveryJob();

    // STEP 2: If list already has 4 jobs, remove the oldest (first) job
    if (jobTotal >= 4) {
        Job* staleJob = firstJob;        // Save reference to oldest job
        if (firstJob == lastJob) {       // Case: only one job in list
            firstJob = lastJob = NULL;   // Reset both pointers to NULL
        } else {                         // Case: multiple jobs
            firstJob = firstJob->nextJob; // Move first pointer forward
            lastJob->nextJob = firstJob;  // Update last job's link to new first
        }
        cout << "  [Job " << staleJob->jobCode << " removed to make space]\n"; // Notify removal
        delete staleJob;                 // Free memory of removed job
        jobTotal--;                      // Decrement active job count
    }

    // STEP 3: Insert the new job with initial phase "pending"
    Job* brandNewJob = new Job(incomingCode, "pending"); // Allocate new job node
    if (firstJob == NULL) {              // Case: list was empty
        firstJob = lastJob = brandNewJob; // Both first and last point to new job
        brandNewJob->nextJob = firstJob;  // Point to itself (circular)
    } else {                              // Case: list has existing jobs
        lastJob->nextJob = brandNewJob;   // Old last job links to new job
        brandNewJob->nextJob = firstJob;  // New job links back to first
        lastJob = brandNewJob;            // Update last job to new job
    }
    jobTotal++;                           // Increment active job count
    cout << "  [Job " << incomingCode << " inserted with phase: pending]\n"; // Notify insertion
}

// Function to remove a job by name (placeholder - not used in this program)
void deleteJob(string nameArg) {
    // Not used here, but kept for completeness
}

// Function to process one job in round-robin fashion
void processTick(Job*& activePtr) {
    if (activePtr == NULL) return;       // If no active job, return

    cout << "Job " << activePtr->jobCode << " : " << activePtr->jobPhase; // Print current job info

    // If job is already completed, remove it from the list
    if (activePtr->jobPhase == "completed") {
        cout << "  -> removing (completed)\n"; // Notify removal
        Job* trashJob = activePtr;        // Save node to delete

        if (firstJob == lastJob) {        // Case: only one job remains
            firstJob = lastJob = NULL;    // Reset list to empty
            activePtr = NULL;             // Reset active pointer
            delete trashJob;              // Free memory
            jobTotal--;                   // Decrement count
            return;                       // Exit function
        }

        Job* beforeJob = firstJob;        // Start from first job
        while (beforeJob->nextJob != activePtr) beforeJob = beforeJob->nextJob; // Find previous job

        beforeJob->nextJob = activePtr->nextJob; // Bypass active job
        if (activePtr == firstJob) firstJob = activePtr->nextJob; // Update first if needed
        if (activePtr == lastJob) lastJob = beforeJob;            // Update last if needed

        activePtr = activePtr->nextJob;   // Move active pointer to next job
        delete trashJob;                  // Free memory of removed job
        jobTotal--;                       // Decrement count
        return;                           // Exit function
    }

    // If job not completed, advance its phase and move to next job
    activePtr->jobPhase = movePhaseForward(activePtr->jobPhase); // Advance phase
    cout << "  -> " << activePtr->jobPhase << endl;              // Print new phase
    activePtr = activePtr->nextJob;       // Move active pointer to next job
}

// Function to display all jobs in the circular list
void showEveryJob() {
    if (firstJob == NULL) { cout << "  (no jobs)\n"; return; } // Handle empty list
    Job* scanner = firstJob;              // Start from first job
    do {
        cout << "  Job " << scanner->jobCode << " : " << scanner->jobPhase << endl; // Print job info
        scanner = scanner->nextJob;       // Move to next job
    } while (scanner != firstJob);        // Stop when loop completes
}

// Main function - entry point of the program
int main() {
    cout << "=== TICK 1: Insert Job 1 ===\n"; // Print tick header
    insertJob(1);                              // Add job with code 1
    showEveryJob();                            // Show all jobs

    cout << "\n=== TICK 2: Insert Job 2 ===\n"; // Print tick header
    insertJob(2);                                // Add job with code 2
    showEveryJob();                              // Show all jobs

    cout << "\n=== TICK 3: Insert Job 3 ===\n"; // Print tick header
    insertJob(3);                                // Add job with code 3
    showEveryJob();                              // Show all jobs

    cout << "\n=== TICK 4: Insert Job 4 ===\n"; // Print tick header
    insertJob(4);                                // Add job with code 4
    showEveryJob();                              // Show all jobs

    cout << "\n=== TICK 5: Insert Job 5 (oldest removed) ===\n"; // Print tick header
    insertJob(5);                                                // Add job 5, oldest removed
    showEveryJob();                                              // Show all jobs

    cout << "\n=== TICK 6: Round Robin ===\n"; // Print tick header
    Job* runningJob = firstJob;                // Initialize active pointer to first job
    processTick(runningJob);                   // Process one job
    showEveryJob();                            // Show all jobs

    cout << "\n=== TICK 7 ===\n";              // Print tick header
    processTick(runningJob);                   // Process next job
    showEveryJob();                            // Show all jobs

    cout << "\n=== TICK 8 ===\n";              // Print tick header
    processTick(runningJob);                   // Process next job
    showEveryJob();                            // Show all jobs

    cout << "\n=== TICK 9 ===\n";              // Print tick header
    processTick(runningJob);                   // Process next job
    showEveryJob();                            // Show all jobs

    cout << "\n=== TICK 10 ===\n";             // Print tick header
    processTick(runningJob);                   // Process next job
    showEveryJob();                            // Show all jobs

    cout << "\n=== FINAL STATE ===\n";         // Print final header
    showEveryJob();                            // Show final state of all jobs

    return 0;                                  // Return success
}
